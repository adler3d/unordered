unit MeshUnit;

interface
uses
  Windows,Classes,TypVectors,Graphics;

type
  TSliceList=class;
  TRGBA=record
    R,G,B,A:Byte;
  end;
  TTrigon=record
    A,B,C:TVector;
  end;
  TTrigonEx=record
    A,B,C:Word;
  end;

  TMesh=class(TList)
  private
    FC:TRGBA;
    FTex:string;
    FSliceList:TSliceList;
    function GetVertex(Index:Integer):TVector;
    procedure SetVertex(Index:Integer; const Value:TVector);
    function GetFirst:TVector;
    function GetLast:TVector;
    function GetSliced:Boolean;
  public
    constructor Create; overload;
    constructor Create(Color:TRGBA); overload;
    constructor Copy(Source:TMesh);
    procedure LoadFromStream(Stream:TStream);
    procedure AddVertex(V:TVector); overload;
    procedure AddVertex(X,Y:Real); overload;
    procedure Delete(Index:Integer);
    procedure Slice;
    procedure SaveToStream(Stream:TStream);
    property Last:TVector read GetLast;
    property First:TVector read GetFirst;
    property Color:TRGBA read FC write FC;
    property Texture:string read FTex write FTex;
    property Vertex[Index:Integer]:TVector read GetVertex write SetVertex;
    default;
    property SliceList:TSliceList read FSliceList;
    property Sliced:Boolean read GetSliced;
  end;

  TSliceList=class(TList)
  private
    FOwner: TMesh;
    function GetTrigon(Index:Integer):TTrigon;
    procedure AddTrigon(A,B,C:Word); overload;
    procedure AddTrigon(T:TTrigonEx); overload;
  public
    constructor Create(Owner:TMesh);
    procedure SaveToStream(Stream:TStream);
    procedure LoadFromStream(Stream:TStream);
    property Trigon[Index:Integer]:TTrigon read GetTrigon; default;
    property Mesh:TMesh read FOwner;
  end;
function RGBA(R,G,B,A:Byte):TRGBA;
function RGBAToColor(C:TRGBA):TColor;
implementation

uses SysUtils;

{ TMesh }
type
  PLink=^TLink;
  TLink=record
    ID:Word;
    V:TVector;
    P,N:PLink;
  end;
  PArrayLink=^TArrayLink;
  TArrayLink=array[0..0] of TLink;

function RGBA(R,G,B,A:Byte):TRGBA;
begin
  Result.R:=R; Result.G:=G; Result.B:=B; Result.A:=A;
end;

function RGBAToColor(C:TRGBA):TColor;
begin
  Result:=RGB(C.R,C.G,C.B);
end;

procedure TMesh.AddVertex(V:TVector);
var
  P:PVector;
begin
  New(P); P^:=V; Add(P);
end;

procedure TMesh.AddVertex(X,Y:Real);
var
  P:PVector;
begin
  New(P); P.X:=X; P.Y:=Y; Add(P);
end;

constructor TMesh.Copy(Source:TMesh);
var
  I:Integer;
begin
  inherited Create;
  FC:=Source.FC; FTex:=Source.FTex;
  for I:=0 to Source.Count-1 do
  begin
    AddVertex(Source[I]);
  end;
end;

constructor TMesh.Create;
begin
  inherited;
end;

constructor TMesh.Create(Color: TRGBA);
begin
  inherited Create; FC:=Color;
end;

procedure TMesh.Delete(Index:Integer);
begin
  FreeMem(Items[Index],SizeOf(TVector));
  inherited Delete(Index);
end;

function TMesh.GetFirst:TVector;
begin
  Result:=Vertex[0];
end;

function TMesh.GetLast:TVector;
begin
  Result:=Vertex[Count-1];
end;

function TMesh.GetSliced:Boolean;
begin
  Result:=SliceList<>nil;
end;

function TMesh.GetVertex(Index:Integer):TVector;
begin
  Result:=PVector(Items[Index])^;
end;

procedure TMesh.LoadFromStream(Stream:TStream);
type
  TWrapVector = array[0..0] of TVector;
  TMeshHeader=record
    VC:Integer;
    C:TRGBA;
    S:Boolean;
    Tex:string[32];
  end;
var
  I:Integer;
  MH:TMeshHeader;
  P:^TWrapVector;
begin
  Stream.ReadBuffer(MH,SizeOf(MH));
  FC:=MH.C; FTex:=MH.Tex;
  GetMem(P,SizeOf(TVector)*MH.VC);
  Stream.ReadBuffer(P^,SizeOf(TVector)*MH.VC);
  for I:=0 to MH.VC-1 do AddVertex(P^[I]);
  FreeMem(P,SizeOf(TVector)*MH.VC);
  if MH.S then
  begin
    FSliceList:=TSliceList.Create(Self);
    FSliceList.LoadFromStream(Stream);
  end;
end;

procedure TMesh.SaveToStream(Stream: TStream);
type
  TWrapVector = array[0..0] of TVector;
  TMeshHeader=record
    VC:Integer;
    C:TRGBA;
    S:Boolean;
    Tex:string[32];
  end;
var
  I:Integer;
  MH:TMeshHeader;
  P:^TWrapVector;
begin
  MH.VC:=Count; MH.C:=FC; MH.Tex:=FTex; MH.S:=Sliced;
  Stream.WriteBuffer(MH,SizeOf(MH));
  GetMem(P,SizeOf(TVector)*Count);
  for I:=0 to Count-1 do P^[I]:=Vertex[I];
  Stream.WriteBuffer(P^,SizeOf(TVector)*Count);
  FreeMem(P,SizeOf(TVector)*Count);
  if Sliced then FSliceList.SaveToStream(Stream);
end;

procedure TMesh.SetVertex(Index:Integer; const Value:TVector);
begin
  PVector(Items[Index])^:=Value;
end;

function IsLeft(O,A,B:TVector):Boolean;
begin
  Result:=(A.X-O.X)*(B.Y-O.Y)>(A.Y-O.Y)*(B.X-O.X);
end;

function DoTri(SL:TSliceList; const O,A,B:TLink):PLink;
  function Condemned(C:TLink):PLink;
  begin
    C.P.N:=C.N; C.N.P:=C.P; Result:=C.N;
  end;
  function IsTri(A,B,C,D:TVector):Boolean;
    function F(O,A,B:TVector):Real;
    begin
      Result:=(A.X-O.X)*(B.Y-O.Y)-(A.Y-O.Y)*(B.X-O.X);
    end;
  var
    X,Y,Z:Real;
  begin
    X:=F(D,B,C); Y:=F(D,A,B); Z:=F(D,C,A);
    Result:=(X>=0)and(Y>=0)and(Z>=0);
  end;
var
  C:TLink;
begin
  C:=A;
  repeat
    C:=C.N^;
    if (C.ID=O.ID)or(C.ID=B.ID)or(C.ID=A.ID) then Continue;
    if IsTri(O.V,A.V,B.V,C.V) then
    begin
      //DoTri(L,O,C,B);
      if IsLeft(O.V,A.V,C.V) then Result:=DoTri(SL,O,A,C);
      Exit;
    end;
  until C.ID=A.ID; Result:=nil;
  if (@O=A.P)and(@O=B.N) then Result:=Condemned(O);
  if (@A=B.P)and(@A=O.N) then Result:=Condemned(A);
  if (@B=A.N)and(@B=O.P) then Result:=Condemned(B);
  if Result=nil then Result:=O.N else SL.AddTrigon(O.ID,A.ID,B.ID);
end;

procedure TMesh.Slice;
var
  I,J:Integer;
  A,B,O,Tick:Integer;
  First,Last,Cur:PLink;
  Mem:PArrayLink;
begin
  {+Подготовка+}
  if Count<=3 then Exit;
  if FSliceList=nil then FSliceList:=TSliceList.Create(Self) else FSliceList.Clear;
  {-Подготовка-}
  {+Создание связанного списка+}
  GetMem(Mem,SizeOf(TLink)*Count);
  First:=@Mem^[0]; First.V:=Vertex[0]; First.ID:=0; Last:=First;
  for I:=1 to Count-1 do
  begin
    Cur:=@Mem^[I]; Cur.V:=Vertex[I]; Cur.ID:=I;
    Last.N:=Cur; Cur.P:=Last; Last:=Cur;
  end;
  Last.N:=First; First.P:=Last; Cur:=First;
  {-Создание связанного списка-}
  {+Мясо+}
  Tick:=0;
  while Cur.N.N<>Cur do
  begin
    Inc(Tick);
    if Tick>2500 then
    begin
      Exception.Create('Не понятно =('); Break;
    end;
    if IsLeft(Cur.V,Cur.N.V,Cur.P.V) then
      Cur:=DoTri(FSliceList,Cur^,Cur.N^,Cur.P^) else Cur:=Cur.N;
  end;
  {-Мясо-}
  FreeMem(Mem,SizeOf(TLink)*Count);
end;

{ TSliceList }
Type
  PTrigonEx=^TTrigonEx;
  
procedure TSliceList.AddTrigon(A,B,C:Word);
var
  P:PTrigonEx;
begin
  New(P); P.A:=A; P.B:=B; P.C:=C;
  inherited Add(P);
end;

procedure TSliceList.AddTrigon(T: TTrigonEx);
var
  P:PTrigonEx;
begin
  New(P); P^:=T;
  inherited Add(P);
end;

constructor TSliceList.Create(Owner: TMesh);
begin
  FOwner:=Owner;
end;

function TSliceList.GetTrigon(Index:Integer):TTrigon;
Var
  P:PTrigonEx;
begin
  P:=Items[Index];
  Result.A:=Mesh[P.A]; Result.B:=Mesh[P.B]; Result.C:=Mesh[P.C];
end;

procedure TSliceList.LoadFromStream(Stream: TStream);
type
  TWrapTrigon = array[0..0] of TTrigonEx;
var
  I,C:Integer;
  P:^TWrapTrigon;
begin
  Stream.ReadBuffer(C,SizeOf(C));
  GetMem(P,SizeOf(TVector)*C);
  Stream.ReadBuffer(P^,SizeOf(TVector)*C);
  for I:=0 to C-1 do AddTrigon(P^[I]);
  FreeMem(P,SizeOf(TVector)*C);
end;

procedure TSliceList.SaveToStream(Stream: TStream);
type
  TWrapTrigon = array[0..0] of TTrigonEx;
var
  I:Integer;
  P:^TWrapTrigon;
begin
  Stream.Write(Count,SizeOf(Count));
  GetMem(P,SizeOf(TVector)*Count);
  for I:=0 to Count-1 do P^[I]:=PTrigonEx(Items[I])^;
  Stream.WriteBuffer(P^,SizeOf(TVector)*Count);
  FreeMem(P,SizeOf(TVector)*Count);
end;

end.

