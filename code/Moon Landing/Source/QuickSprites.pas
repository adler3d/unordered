unit QuickSprites;
{<|Автор Adler3D|>}
{<|e-mail : Adler3D@Mail.ru|>}
{<|site : Adler3D.narod.ru|>}
interface
uses
  Windows,ASDVector,QuickList,Tools,eXgine;
{$D-}
type
  TString32=string[32];

  TSprite=class;

  TSpriteEngine=class;

  TSpriteClass=class of TSprite;

  TSprite=class(TAccessObject)
  private
    FEngine:TSpriteEngine;
    FParent:TSprite;
    FList:TQuickList;
    FVisible:Boolean;
    FMoved:Boolean;
    FAllCount:Integer;
    FTag:Integer;
    FDeaded:boolean;
    FCaption:TString32;
    function GetCount:integer;
    function GetItems(Index:Integer):TSprite;
    procedure Add(Sprite:TSprite); virtual;
  protected
    procedure DoMove; virtual;
    procedure DoDraw; virtual;
  public
    constructor Create(AParent:TSprite); virtual;
    procedure Free; override;
    procedure Draw; virtual;
    procedure Move; virtual;
    procedure Dead; virtual;
    procedure Clear; virtual;
    property Engine:TSpriteEngine read FEngine;
    property Visible:Boolean read FVisible write FVisible;
    property Moved:Boolean read FMoved write FMoved;
    property Tag:Integer read FTag write FTag;
    property Count:integer read GetCount;
    property Deaded:boolean read FDeaded;
    property Caption:TString32 read FCaption;
    property AllCount:Integer read FAllCount;
    property Parent:TSprite read FParent;
    property Items[Index:Integer]:TSprite read GetItems; default;
  end;

  TSpriteEngine=class(TSprite)
  private
    FDeadList:TQuickList;
  public
    constructor Create(AParent:TSprite); override;
    destructor Destroy; override;
    procedure Clear; override;
    procedure Dead; override;
  end;

function TestColision(const P1,P2:TVector; const R1,R2:Real):Boolean;

implementation

function TestColision(const P1,P2:TVector; const R1,R2:Real):Boolean;
begin
  Result:=((P1.X-P2.X)*(P1.X-P2.X)+(P1.Y-P2.Y)*(P1.Y-P2.Y))
    <=((R1+R2)*(R1+R2));
end;

{ TSprite }

procedure TSprite.Add(Sprite:TSprite);
begin
  if FList=nil then
  begin
    FList:=TQuickList.Create;
  end;
  FList.Add(Sprite);
end;

constructor TSprite.Create(AParent:TSprite);
begin
  inherited Create;
  FParent:=AParent;
  if FParent<>nil then
  begin
    FParent.Add(Self);
    if FParent is TSpriteEngine then
      FEngine:=TSpriteEngine(FParent)
    else
      FEngine:=FParent.Engine;
    Inc(FEngine.FAllCount);
    FCaption:=ClassName+' #'+IntToStr(FEngine.AllCount);
  end
  else
    FCaption:=ClassName+' Boss';
  FMoved:=True;
  FVisible:=True;
  Lock;
end;

procedure TSprite.Dead;
begin
  if (FEngine<>nil)and not FDeaded then
    FEngine.FDeadList.Add(Self);
  FDeaded:=True;
end;

procedure TSprite.Clear;
begin
  while Count>0 do
    Items[Count-1].Free;
  if FList<>nil then
  begin
    FList.Free;
    FList:=nil;
  end;
end;

procedure TSprite.Free;
begin
  Clear;
  UnLock;
end;

function TSprite.GetCount:integer;
begin
  if FList<>nil then
    Result:=FList.Count
  else
    Result:=0;
end;

function TSprite.GetItems(Index:Integer):TSprite;
begin
  Result:=FList[Index];
end;

procedure TSprite.Move;
var
  i:integer;
begin
  if FMoved then
  begin
    DoMove;
    for i:=0 to Count-1 do
      Items[i].Move;
  end;
end;

procedure TSprite.DoDraw;
begin
end;

procedure TSprite.DoMove;
begin
end;

procedure TSprite.Draw;
var
  i:integer;
begin
  if FVisible then
  begin
    DoDraw;
    for I:=0 to Count-1 do
      Items[I].Draw;
  end;
end;

{ TSpriteEngine }

procedure TSpriteEngine.Clear;
var
  I:Integer;
begin
  for I:=0 to Count-1 do
  begin
    if Items[I] is TSpriteEngine then Items[I].Clear else Items[I].Dead;
  end;
  Dead;
end;

constructor TSpriteEngine.Create(AParent:TSprite);
begin
  inherited;
  FDeadList:=TQuickList.Create;
end;

procedure TSpriteEngine.Dead;
var
  I,J:Integer;
  S:TSprite;
begin
  for I:=FDeadList.Count-1 downto 0 do
  begin
    S:=TSprite(FDeadList[I]);
    for J:=FList.Count-1 downto 0 do if FList[J]=S then FList.Delete(J);
    FDeadList.Delete(I); S.Free;
  end;
end;

destructor TSpriteEngine.Destroy;
begin
  FDeadList.Free;
  inherited;
end;

end.

