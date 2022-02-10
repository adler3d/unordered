unit ASDStream;

interface

uses Windows,eXgine;
const
  { TFileStream create mode }
  fmCreate=$FFFF;
  { File open modes }
  fmOpenRead=$0000;
  fmOpenWrite=$0001;
  fmOpenReadWrite=$0002;

  fmShareCompat=$0000 platform;
  fmShareExclusive=$0010;
  fmShareDenyWrite=$0020;
  fmShareDenyRead=$0030 platform;
  fmShareDenyNone=$0040;
type
  { TStream seek origins }
  TSeekOrigin=(soBeginning,soCurrent,soEnd);

  { TStream abstract class }
  TStream=class(TObject)
  private
    function GetPosition:Integer;
    procedure SetPosition(const Pos:Integer);
  protected
    function GetSize:Integer; virtual;
    procedure SetSize(const NewSize:Integer); virtual;
  public
    function Read(var Buffer; Count:Longint):Longint; virtual; abstract;
    function Write(const Buffer; Count:Longint):Longint; virtual; abstract;
    function Seek(const Offset:Integer; Origin:TSeekOrigin=soBeginning):
      Integer; virtual;
    procedure ReadBuffer(var Buffer; Count:Longint);
    procedure WriteBuffer(const Buffer; Count:Longint);
    function CopyFrom(Source:TStream; Count:Integer):Integer;
    function Valid:Boolean;
    property Position:Integer read GetPosition write SetPosition;
    property Size:Integer read GetSize write SetSize;
  end;

  { THandleStream class }

  THandleStream=class(TStream)
  protected
    FHandle:HFile;
    procedure SetSize(const NewSize:Integer); override;
  public
    constructor Create(AHandle:Integer);
    function Read(var Buffer; Count:Longint):Longint; override;
    function Write(const Buffer; Count:Longint):Longint; override;
    function Seek(const Offset:Integer; Origin:TSeekOrigin=soBeginning):
      Integer; override;
    function Handle:HFile;
  end;

  { TFileStream class }

  TFileStream=class(THandleStream)
  private
    FFileName:string;
  public
    constructor Create(const FileName:string; Mode:Word);
    destructor Destroy; override;
    property FileName:string read FFileName;
  end;

  { TCustomMemoryStream abstract class }

  TCustomMemoryStream=class(TStream)
  private
    FMemory:Pointer;
    FSize,FPosition:Integer;
  protected
    procedure SetPointer(Ptr:Pointer; Size:Integer);
  public
    function Read(var Buffer; Count:Longint):Integer; override;
    function Seek(const Offset:Integer; Origin:TSeekOrigin=soBeginning):
      Integer; override;
    procedure SaveToStream(Stream:TStream);
    procedure SaveToFile(const FileName:string);
    function Memory:Pointer;
  end;

  { TMemoryStream }

  TMemoryStream=class(TCustomMemoryStream)
  private
    FCapacity:Integer;
    FNone:Boolean;
    procedure SetCapacity(NewCapacity:Integer);
  protected
    function Realloc(var NewCapacity:Integer):Pointer; virtual;
    property Capacity:Integer read FCapacity write SetCapacity;
  public
    destructor Destroy; override;
    procedure Clear;
    procedure LoadFromStream(Stream:TStream);
    procedure LoadFromFile(const FileName:string);
    procedure SetSize(const NewSize:Integer); override;
    function Write(const Buffer; Count:Integer):Integer; override;
  end;

  //{ TStringStream }

  {TStringStream = class(TStream, IStringStream)
  private
    FDataString: string;
    FPosition: Integer;
    function GetDataString: PChar;
  protected
    procedure SetSize(const NewSize: Integer); override;
  public
    constructor Create(const AString: string);
    function Read(var Buffer; Count: Integer): Integer; override;
    function ReadString(Count: Integer): PChar;
    function Seek(const Offset: Integer; Origin: TSeekOrigin = soBeginning):
      Integer; override;
    function Write(const Buffer; Count: Integer): Integer; override;
    procedure WriteString(const AString: PChar);
    property DataString: PChar read GetDataString;
  end; }

  { TResourceStream }

  TResourceStream=class(TCustomMemoryStream)
  private
    HResInfo:THandle;
    HGlobal:THandle;
    procedure Initialize(Instance:THandle; Name,ResType:PChar);
  public
    constructor Create(Instance:THandle; const ResName:string; ResType:
      PChar);
    constructor CreateFromID(Instance:THandle; ResID:Integer; ResType:PChar);
    destructor Destroy; override;
    function Write(const Buffer; Count:Longint):Longint; override;
  end;

implementation

procedure AddLog(S:string);
begin
  log.Print(PChar(S));
end;

function FileRead(Handle:Integer; var Buffer; Count:LongWord):Integer;
begin
  if not ReadFile(THandle(Handle),Buffer,Count,LongWord(Result),nil) then
    Result:=-1;
end;

function FileWrite(Handle:Integer; const Buffer; Count:LongWord):Integer;
begin
  if not WriteFile(THandle(Handle),Buffer,Count,LongWord(Result),nil) then
    Result:=-1;
end;

function FileCreate(const FileName:string):Integer;
begin
  Result:=Integer(CreateFile(PChar(FileName),GENERIC_READ or GENERIC_WRITE,
    0,nil,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0));
end;

function FileOpen(const FileName:string; Mode:LongWord):Integer;
const
  AccessMode:array[0..2] of LongWord=(
    GENERIC_READ,
    GENERIC_WRITE,
    GENERIC_READ or GENERIC_WRITE);
  ShareMode:array[0..4] of LongWord=(
    0,
    0,
    FILE_SHARE_READ,
    FILE_SHARE_WRITE,
    FILE_SHARE_READ or FILE_SHARE_WRITE);
begin
  Result:=-1;
  if ((Mode and 3)<=fmOpenReadWrite)and
    ((Mode and $F0)<=fmShareDenyNone) then
    Result:=Integer(CreateFile(PChar(FileName),AccessMode[Mode and 3],
      ShareMode[(Mode and $F0)shr 4],nil,OPEN_EXISTING,
      FILE_ATTRIBUTE_NORMAL,0));
end;

procedure FileClose(Handle: Integer);
begin
  CloseHandle(THandle(Handle));
end;

{ TStream }

function TStream.GetPosition:Integer;
begin
  Result:=Seek(0,soCurrent);
end;

procedure TStream.SetPosition(const Pos:Integer);
begin
  Seek(Pos,soBeginning);
end;

function TStream.GetSize:Integer;
var
  Pos:Integer;
begin
  Pos:=Seek(0,soCurrent);
  Result:=Seek(0,soEnd);
  Seek(Pos,soBeginning);
end;

function TStream.Seek(const Offset:Integer; Origin:TSeekOrigin):Integer;
type
  TSeek64=function(const Offset:Integer; Origin:TSeekOrigin):Integer of
    object;
var
  Impl:TSeek64;
  Base:TSeek64;
  ClassTStream:TClass;
begin
  Impl:=Seek;
  ClassTStream:=Self.ClassType;
  while (ClassTStream<>nil)and(ClassTStream<>TStream) do
    ClassTStream:=ClassTStream.ClassParent;
  if ClassTStream=nil then
  begin
    AddLog('Error: TStream.Seek'); Exit;
  end;
  Base:=TStream(@ClassTStream).Seek;
  if TMethod(Impl).Code=TMethod(Base).Code then
  begin
    AddLog('Error: TStream.Seek'); Exit;
  end;
  Result:=Seek(Integer(Offset),TSeekOrigin(Origin));
end;

procedure TStream.ReadBuffer(var Buffer; Count:Longint);
begin
  if (Count<>0)and(Read(Buffer,Count)<>Count) then
  begin
    AddLog('Error: TStream.ReadBuffer'); Exit;
  end;
end;

procedure TStream.WriteBuffer(const Buffer; Count:Longint);
begin
  if (Count<>0)and(Write(Buffer,Count)<>Count) then
  begin
    AddLog('Error: TStream.WriteBuffer'); Exit;
  end;
end;

function TStream.CopyFrom(Source:TStream; Count:Integer):Integer;
const
  MaxBufSize=$F000;
var
  BufSize,N:Integer;
  Buffer:PChar;
begin
  if Count=0 then
  begin
    Source.Position:=0;
    Count:=Source.Size;
  end;
  Result:=Count;
  if Count>MaxBufSize then
    BufSize:=MaxBufSize
  else
    BufSize:=Count;
  GetMem(Buffer,BufSize);
  try
    while Count<>0 do
    begin
      if Count>BufSize then
        N:=BufSize
      else
        N:=Count;
      Source.ReadBuffer(Buffer^,N);
      WriteBuffer(Buffer^,N);
      Dec(Count,N);
    end;
  finally
    FreeMem(Buffer,BufSize);
  end;
end;

procedure TStream.SetSize(const NewSize:Integer);
begin

end;

function TStream.Valid:Boolean;
begin

end;

{ THandleStream }

constructor THandleStream.Create(AHandle:Integer);
begin
  FHandle:=AHandle;
end;

function THandleStream.Read(var Buffer; Count:Longint):Longint;
begin
  Result:=FileRead(FHandle,Buffer,Count); if Result=-1 then Result:=0;
end;

function THandleStream.Write(const Buffer; Count:Longint):Longint;
begin
  Result:=FileWrite(FHandle,Buffer,Count); if Result=-1 then Result:=0;
end;

function THandleStream.Seek(const Offset:Integer; Origin:TSeekOrigin):
  Integer;
begin
  Result:=SetFilePointer(THandle(Handle),Offset,nil,Ord(Origin));
end;

procedure THandleStream.SetSize(const NewSize:Integer);
begin
  Seek(NewSize,soBeginning);
end;

function THandleStream.Handle:HFile;
begin
  Result:=FHandle;
end;

{ TFileStream }

constructor TFileStream.Create(const FileName:string; Mode:Word);
const
  SFCreateErrorEx='Cannot create file "';
  SFOpenErrorEx='Cannot open file "';
begin
  FFileName:=FileName;
  if Mode=fmCreate then
  begin
    inherited Create(FileCreate(FileName));
    if FHandle<0 then
    begin
      AddLog('Error: TFileStream.Create'); Exit;
    end;
  end
  else
  begin
    inherited Create(FileOpen(FileName,Mode));
    if FHandle<0 then
    begin
      AddLog('Error: TFileStream.Create'); Exit;
    end;
  end;
end;

destructor TFileStream.Destroy;
begin
  if FHandle>=0 then FileClose(FHandle);
  inherited Destroy;
end;

{ TCustomMemoryStream }

procedure TCustomMemoryStream.SetPointer(Ptr:Pointer; Size:Longint);
begin
  FMemory:=Ptr;
  FSize:=Size;
end;

function TCustomMemoryStream.Read(var Buffer; Count:Longint):Longint;
begin
  if (FPosition>=0)and(Count>=0) then
  begin
    Result:=FSize-FPosition;
    if Result>0 then
    begin
      if Result>Count then
        Result:=Count;
      Move(Pointer(Longint(FMemory)+FPosition)^,Buffer,Result);
      Inc(FPosition,Result);
      Exit;
    end;
  end;
  Result:=0;
end;

function TCustomMemoryStream.Seek(const Offset:Integer; Origin:TSeekOrigin):
  Integer;
begin
  case Origin of
    soBeginning:FPosition:=Offset;
    soCurrent:Inc(FPosition,Offset);
    soEnd:FPosition:=FSize+Offset;
  end;
  Result:=FPosition;
end;

procedure TCustomMemoryStream.SaveToStream(Stream:TStream);
begin
  if FSize<>0 then
    Stream.WriteBuffer(FMemory^,FSize);
end;

procedure TCustomMemoryStream.SaveToFile(const FileName:string);
var
  Stream:TStream;
begin
  Stream:=TFileStream.Create(FileName,fmCreate);
  try
    SaveToStream(Stream);
  finally
    Stream.Free;
  end;
end;

function TCustomMemoryStream.Memory:Pointer;
begin
  Result:=FMemory;
end;

{ TMemoryStream }

const
  MemoryDelta=$2000; { Must be a power of 2 }

destructor TMemoryStream.Destroy;
begin
  if not FNone then
    Clear;
  inherited Destroy;
end;

procedure TMemoryStream.Clear;
begin
  SetCapacity(0);
  FSize:=0;
  FPosition:=0;
end;

procedure TMemoryStream.LoadFromStream(Stream:TStream);
var
  Count:Longint;
begin
  Stream.Position:=0;
  Count:=Stream.Size;
  SetSize(Count);
  if Count<>0 then
    Stream.ReadBuffer(FMemory^,Count);
end;

procedure TMemoryStream.LoadFromFile(const FileName:string);
var
  Stream:TStream;
begin
  Stream:=TFileStream.Create(FileName,fmOpenRead or fmShareDenyWrite);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TMemoryStream.SetCapacity(NewCapacity:Longint);
begin
  SetPointer(Realloc(NewCapacity),FSize);
  FCapacity:=NewCapacity;
end;

procedure TMemoryStream.SetSize(const NewSize:Integer);
var
  OldPosition:Longint;
begin
  OldPosition:=FPosition;
  SetCapacity(NewSize);
  FSize:=NewSize;
  if OldPosition>NewSize then
    Seek(0,soEnd);
end;

function TMemoryStream.Realloc(var NewCapacity:Longint):Pointer;
begin
  if (NewCapacity>0)and(NewCapacity<>FSize) then
    NewCapacity:=(NewCapacity+(MemoryDelta-1))and not(MemoryDelta-1);
  Result:=Memory;
  if NewCapacity<>FCapacity then
  begin
    if NewCapacity=0 then
    begin
      GlobalFreePtr(Memory);
      Result:=nil;
    end
    else
    begin
      if Capacity=0 then
        Result:=GlobalAllocPtr(HeapAllocFlags,NewCapacity)
      else
        Result:=GlobalReallocPtr(Memory,NewCapacity,HeapAllocFlags);
      if Result=nil then
      begin
        AddLog('Error: TMemoryStream.Realloc'); Exit;
        Exit;
      end;
    end;
  end;
end;

function TMemoryStream.Write(const Buffer; Count:Longint):Longint;
var
  Pos:Longint;
begin
  if (FPosition>=0)and(Count>=0) then
  begin
    Pos:=FPosition+Count;
    if Pos>0 then
    begin
      if Pos>FSize then
      begin
        if Pos>FCapacity then
          SetCapacity(Pos);
        FSize:=Pos;
      end;
      System.Move(Buffer,Pointer(Longint(FMemory)+FPosition)^,Count);
      FPosition:=Pos;
      Result:=Count;
      Exit;
    end;
  end;
  Result:=0;
end;

//{ TStringStream }

{constructor TStringStream.Create(const AString: string);
begin
  inherited Create;
  FDataString := AString;
end;

function TStringStream.Read(var Buffer; Count: Longint): Longint;
begin
  Result := Length(FDataString) - FPosition;
  if Result > Count then
    Result := Count;
  Move(PChar(@FDataString[FPosition + 1])^, Buffer, Result);
  Inc(FPosition, Result);
end;

function TStringStream.Write(const Buffer; Count: Longint): Longint;
begin
  Result := Count;
  SetLength(FDataString, (FPosition + Result));
  Move(Buffer, PChar(@FDataString[FPosition + 1])^, Result);
  Inc(FPosition, Result);
end;

function TStringStream.Seek(const Offset: Integer; Origin: TSeekOrigin):
  Integer;
begin
  case Origin of
    soBeginning: FPosition := Offset;
    soCurrent: FPosition := FPosition + Offset;
    soEnd: FPosition := Length(FDataString) - Offset;
  end;
  if FPosition > Length(FDataString) then
    FPosition := Length(FDataString)
  else if FPosition < 0 then
    FPosition := 0;
  Result := FPosition;
end;

function TStringStream.ReadString(Count: Longint): PChar;
var
  Len: Integer;
begin
  Len := Length(FDataString) - FPosition;
  if Len > Count then
    Len := Count;
  Result := PChar(@FDataString[FPosition + 1]);
  Inc(FPosition, Len);
end;

procedure TStringStream.WriteString(const AString: PChar);
begin
  Write(PChar(AString)^, Length(AString));
end;

procedure TStringStream.SetSize(const NewSize: Integer);
begin
  SetLength(FDataString, NewSize);
  if FPosition > NewSize then
    FPosition := NewSize;
end;}

{ TResourceStream }

constructor TResourceStream.Create(Instance:THandle; const ResName:string;
  ResType:PChar);
begin
  inherited Create;
  Initialize(Instance,PChar(ResName),ResType);
end;

constructor TResourceStream.CreateFromID(Instance:THandle; ResID:Integer;
  ResType:PChar);
begin
  inherited Create;
  Initialize(Instance,PChar(ResID),ResType);
end;

procedure TResourceStream.Initialize(Instance:THandle; Name,ResType:PChar);
begin
  HResInfo:=FindResource(Instance,Name,ResType);
  if HResInfo=0 then
  begin
    AddLog('Error: TResourceStream.Initialize'); Exit;
  end;
  HGlobal:=LoadResource(Instance,HResInfo);
  if HGlobal=0 then
  begin
    AddLog('Error: TResourceStream.Initialize'); Exit;
  end;
  SetPointer(LockResource(HGlobal),SizeOfResource(Instance,HResInfo));
end;

destructor TResourceStream.Destroy;
begin
  UnlockResource(HGlobal);
  FreeResource(HGlobal);
  inherited Destroy;
end;

function TResourceStream.Write(const Buffer; Count:Longint):Longint;
begin
  AddLog('Error: TResourceStream.Write'); Exit;
end;

end.

