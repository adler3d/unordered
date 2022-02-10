unit QuickList;
{<|Автор Adler3D|>}
{<|e-mail : Adler3D@Mail.ru|>}
{<|site : Adler3D.narod.ru|>}
interface
uses
  Windows,ASDVector,eXgine;
{$D-}
const
  MaxListSize=Maxint div 16;
type

  PPointerList=^TPointerList;
  TPointerList=array[0..MaxListSize-1] of Pointer;

  TList=class(TObject)
  private
    FList:PPointerList;
    FCount:Integer;
    FCapacity:Integer;
  protected
    function Get(Index:Integer):Pointer;
    procedure Grow; virtual;
    procedure Put(Index:Integer; Item:Pointer);
    procedure SetCapacity(NewCapacity:Integer);
    function GetCapacity:Integer;
    function GetCount:Integer;
  public
    destructor Destroy; override;
    function Add(Item:Pointer):Integer;
    procedure Clear; virtual;
    procedure Delete(Index:Integer); virtual;
    function First:Pointer;
    function Last:Pointer;
    property Capacity:Integer read FCapacity write SetCapacity;
    property Count:Integer read FCount;
    property Items[Index:Integer]:Pointer read Get write Put; default;
    property List:PPointerList read FList;
  end;

  TQuickList=class(TList)
  public
    procedure Delete(Index:Integer); override;
  end;

  TAccessObject=class(TObject)
  private
    FLockCount:Integer;
  public
    constructor Create;
    property LockCount:Integer read FLockCount;
    procedure Lock;
    procedure UnLock;
    procedure Free; virtual;
  end;

implementation

function TestColision(const P1,P2:TVector; const R1,R2:Real):Boolean;
begin
  Result:=((P1.X-P2.X)*(P1.X-P2.X)+(P1.Y-P2.Y)*(P1.Y-P2.Y))
    <=((R1+R2)*(R1+R2));
end;

procedure RaiseError(Msg:string);
begin
  Log.Print(PChar(Msg));
end;

{ TQuickList }

destructor TList.Destroy;
begin
  Clear;
end;

function TList.Add(Item:Pointer):Integer;
begin
  Result:=FCount;
  if Result=FCapacity then
    Grow;
  FList^[Result]:=Item;
  Inc(FCount);
end;

procedure TList.Clear;
begin
  FreeMem(FList); FList:=nil;
  FCount:=0; FCapacity:=0;
end;

procedure TList.Delete(Index:Integer);
var
  Temp:Pointer;
begin
  if (Index<0)or(Index>=FCount) then
    RaiseError('List index out of bounds ('+IntToStr(Index)+')');
  Temp:=Items[Index]; Dec(FCount);
  if Index<FCount then
    System.Move(FList^[Index+1],FList^[Index],(FCount-Index)*SizeOf(Pointer));
end;

function TList.First:Pointer;
begin
  Result:=Get(0);
end;

function TList.Get(Index:Integer):Pointer;
begin
  if (Index<0)or(Index>=FCount) then
  begin
    RaiseError('List index out of bounds ('+IntToStr(Index)+')');
    Exit;
  end;
  Result:=FList^[Index];
end;

procedure TList.Grow;
var
  Delta:Integer;
begin
  if FCapacity>64 then
    Delta:=FCapacity div 4
  else if FCapacity>8 then
    Delta:=16
  else
    Delta:=4;
  SetCapacity(FCapacity+Delta);
end;

function TList.Last:Pointer;
begin
  Result:=Get(FCount-1);
end;

procedure TList.Put(Index:Integer; Item:Pointer);
var
  Temp:Pointer;
begin
  if (Index<0)or(Index>=FCount) then
  begin
    RaiseError('List index out of bounds ('+IntToStr(Index)+')');
    Exit;
  end;
  if Item<>FList^[Index] then
  begin
    Temp:=FList^[Index];
    FList^[Index]:=Item;
  end;
end;

procedure TList.SetCapacity(NewCapacity:Integer);
begin
  if (NewCapacity<FCount)or(NewCapacity>MaxListSize) then
  begin
    RaiseError('List capacity out of bounds ('+IntToStr(NewCapacity)+
      ')');
    Exit;
  end;
  if NewCapacity<>FCapacity then
  begin
    ReallocMem(FList,NewCapacity*SizeOf(Pointer));
    FCapacity:=NewCapacity;
  end;
end;

function TList.GetCapacity:Integer;
begin
  Result:=FCapacity;
end;

function TList.GetCount:Integer;
begin
  Result:=FCount;
end;

{ TQuickList }

procedure TQuickList.Delete(Index:Integer);
var
  Temp:Pointer;
begin
  if (Index<0)or(Index>=FCount) then
  begin
    RaiseError('List index out of bounds ('+IntToStr(Index)+')');
    Exit;
  end;
  Temp:=Items[Index];
  FList^[Index]:=FList^[FCount-1];
  Dec(FCount);
end;

{ TAccessObject }

constructor TAccessObject.Create;
begin
  FLockCount:=0;
end;

procedure TAccessObject.Free;
begin
  // No Action
end;

procedure TAccessObject.Lock;
begin
  Inc(FLockCount);
end;

procedure TAccessObject.UnLock;
begin
  Dec(FLockCount);
  if FLockCount=0 then
    inherited Free;
end;

end.

