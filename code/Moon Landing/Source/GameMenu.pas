unit GameMenu;
interface
uses
  eXgine,OpenGL,Tools,Scene,Menu,GameRender,GameSystem,QuickSprites,ASDVector;
type
  TGameMenu=class(TMenu)
  private
    Tick:Integer;
    SP:TSpriteEngine;
    FOption:TMenu;
    FCredits:TMenu;
    FRecord:TMenu;
    FShowFPS:Boolean;
    FActiveMenu:Boolean;
    FUserName:string;
    FCurrentMap:Integer;
  protected
    procedure NoAction(O:TObject);
    procedure DoShowFPS(O:TObject);
    procedure DoActiveMenu(O:TObject);
    procedure DoVSync(O:TObject);
    procedure GoQuit(O:TObject);
    procedure GoOption(O:TObject);
    procedure GoBack(O:TObject);
    procedure GoResume(O:TObject);
    procedure GoNewGame(O:TObject);
    procedure GoRecords(O:TObject);
    procedure InitBack;
    procedure MakeMenu;
  public
    constructor Create;
    destructor Destroy; override;
    procedure GoCredits(O:TObject);
    procedure DrawFPS;
    procedure LoadConfig;
    procedure SaveConfig;
    procedure DrawBack;
    procedure MoveBack;
    procedure Render; override;
    procedure Update; override;
    function NextMap:Boolean;
  end;

  TPart=class(TSprite)
  private
    FP,FV,FCP,FCV:TVector;
    FA,FT,FO,FLT,FMS:Real;
    FC:TRGB;
    FLoop:Boolean;
  protected
    procedure DoDraw; override;
    procedure DoMove; override;
  public
    constructor Init(Owner:TSpriteEngine; P,V:TVector; T,MS:Real; C:TRGB;
      Loop:Boolean=False);
  end;

  TAdditionMenu=class(TMenu)
  public
    procedure Render; override;
    procedure Update; override;
  end;

implementation
uses
  GameApp,GameRes,GameMouse;

const
  FileName='Settings.dat';
  MapPath='Maps\';
  MapName='Level';
  //MapName='J-net';
type
  TSettingsFile=record
    Magic:string[3];
    User:string[32];
    ShowFPS:Boolean;
    ActiveMenu:Boolean;
    RecCount:Integer;
  end;

{ TGameMenu }

constructor TGameMenu.Create;
begin
  inherited Create('Menu');
  Cursor:=GameRes.Cursor; SelTex:=Cell;
  LoadConfig; MakeMenu;
end;

const
  LW=512; LH=128; Q=2/3;
const
  C_BTS:array[Boolean] of string=('Off','On');

procedure TGameMenu.DoShowFPS(O:TObject);
begin
  FShowFPS:=not FShowFPS;
  TMenuItem(O).Name:='Show FPS '+C_BTS[FShowFPS];
end;

procedure TGameMenu.DoActiveMenu(O:TObject);
begin
  FActiveMenu:=not FActiveMenu;
  TMenuItem(O).Name:='Active menu '+C_BTS[FActiveMenu];
end;

procedure TGameMenu.DoVSync(O: TObject);
begin
  ogl.VSync(not ogl.VSync); 
  TMenuItem(O).Name:='VSync '+C_BTS[ogl.VSync];
end;

procedure TGameMenu.DrawFPS;
begin
  if FShowFPS then
  begin
    glColor3d(1,1,1);
    ogl.TextOut(0,10,10,PChar('FPS : '+IntToStr(ogl.FPS)));
  end;
end;

procedure TGameMenu.DrawBack;
  function F(A:Real; B:Real=1):Real;
  begin
    Result:=Abs(Sin(Pi*(Tick/B/UPS/5+A)));
  end;
begin
  if FActiveMenu then
    with wnd do
    begin
      glBegin(GL_QUADS);
      glColor3d(F(0,2)*Q,F(0,16)*Q,0); glVertex2f(0,0);
      glColor3d(F(0,4)*Q,F(0,14)*Q,0); glVertex2f(Width,0);
      glColor3d(F(0,6)*Q,F(0,12)*Q,0); glVertex2f(Width,Height);
      glColor3d(F(0,8)*Q,F(0,10)*Q,0); glVertex2f(0,Height);
      glEnd;
      tex.Enable(Smoke); ogl.Blend(BT_SUB); Sp.Draw;
      tex.Enable(Light); glColor4d(1,1,1,0.8);
      DrawQuads(Width/2,Height/2,300,300,30);
    end else ogl.Clear;
  tex.Enable(Logo); ogl.Blend(BT_SUB); glColor3d(0,1,0);
  with wnd do DrawRect((Width-LW)/2,Height*3/16-LH/2,LW,LH); tex.Disable;
  DrawFPS;
end;

procedure TGameMenu.GoBack(O:TObject);
begin
  ActivScene:=Self;
end;

procedure TGameMenu.GoCredits(O:TObject);
begin
  ActivScene:=FCredits;
end;

procedure TGameMenu.GoOption(O:TObject);
begin
  ActivScene:=FOption;
end;


procedure TGameMenu.GoRecords(O: TObject);
begin
  ActivScene:=FRecord;
end;

procedure TGameMenu.GoQuit(O:TObject);
begin
  eX.Quit;
end;

procedure TGameMenu.GoNewGame(O:TObject);
begin
  ActivScene:=GSys;
  FCurrentMap:=0;
  //GSys.LoadMap(MapPath+'Test_Level.ASD');
  GSys.LoadMap(MapPath+MapName+IntToStr(FCurrentMap)+'.ASD');
end;

procedure TGameMenu.InitBack;
const
  Count=360;
  CountL=75;
  procedure AddPart(X,Y,MS:Real);
  begin
    TPart.Init(SP,MakeVector(X,Y),RndVector(0.4),UPS,MS,RGB(255,255,255),True);
  end;
var
  I:Integer;
  V:TVector;
begin
  SP:=TSpriteEngine.Create(nil);
  V:=MakeVector(150,0);
  for I:=1 to Count do
  begin
    V:=VectorSetAlfa(V,2*I*Pi/Count);
    AddPart(wnd.Width/2+V.X,wnd.Height/2+V.Y,75);
  end;
  for I:=1 to CountL do
  begin
    AddPart(I*wnd.Width/CountL,0,80);
    AddPart(I*wnd.Width/CountL,wnd.Height,80);
    AddPart(0,I*wnd.Height/CountL,80);
    AddPart(wnd.Width,I*wnd.Height/CountL,80);
  end;
end;

procedure TGameMenu.MakeMenu;
var
  SM:TScreenMode;
  S:string;
begin
  InitBack;
  {---GameMenu---}
  Add('Resume game',GoResume,False);
  Add('New game',GoNewGame);
  Add('Options',GoOption);
  Add('Records',GoRecords);
  Add('Credits',GoCredits);
  Add('Quit',GoQuit);
  {---Option---}
  FOption:=TAdditionMenu.Create('Option',Self);
  SM:=GetScreenMode; S:=IntToStr(SM.X)+'x'+IntToStr(SM.Y);
  FOption.Add('Profile : '+FUserName,nil,False);
  FOption.Add('Mode '+S,nil,False);
  FOption.Add('Bits pixel '+IntToStr(SM.BPP),nil,False);
  FOption.Add('Freg '+IntToStr(SM.Freg)+'Hz',nil,False);
  FOption.Add('VSync '+C_BTS[ogl.VSync],DoVSync);
  FOption.Add('Show FPS '+C_BTS[FShowFPS],DoShowFPS);
  FOption.Add('Active menu '+C_BTS[FActiveMenu],DoActiveMenu);
  FOption.Add('Back',GoBack);
  {---Record---}
  FRecord:=TAdditionMenu.Create('Record',Self);
  FRecord.Add('This menu engine not support record',NoAction,False);
  FRecord.Add('Back',GoBack);
  {---Credits---}            
  FCredits:=TAdditionMenu.Create('Credits',Self);
  FCredits.Add('Code : Adler3D',nil,False).DisColor:=RGBA(255,0,0,230);
  FCredits.Add('Graphics : Adler3D',nil,False).DisColor:=RGBA(255,0,0,230);
  FCredits.Add('eXgine(by XProger)',nil,False).DisColor:=RGBA(0,128,255,230);
  FCredits.Add('Site : Adler3D.narod.ru',nil,False).DisColor:=RGBA(192,96,192,230);
  FCredits.Add('18.03.08 - 8.06.08',nil,False).DisColor:=RGBA(64,255,64,230);
  FCredits.Add('Back',GoBack);
end;

procedure TGameMenu.MoveBack;
begin
  Inc(Tick);
  if not FActiveMenu then Exit;
  SP.Move; SP.Dead;
end;

procedure TGameMenu.NoAction(O:TObject);
begin

end;

procedure TGameMenu.Render;
begin
  ogl.Clear; ogl.Set2D(0,0,wnd.Width,wnd.Height);
  DrawBack; ogl.Blend(BT_SUB);
  inherited Render;
end;

procedure TGameMenu.Update;
begin
  inherited Update;
  MoveBack;
end;

procedure TGameMenu.LoadConfig;
var
  F:file;
  Temp:TSettingsFile;
begin
  FUserName:=UserName; FShowFPS:=True; FActiveMenu:=True;
  if not FileExists(FileName) then Exit;
  AssignFile(F,FileName);
  Reset(F,1);
  BlockRead(F,Temp,SizeOf(Temp));
  FActiveMenu:=Temp.ActiveMenu; FShowFPS:=Temp.ShowFPS; FUserName:=Temp.User;
  CloseFile(F);
end;

procedure TGameMenu.SaveConfig;
var
  F:file;
  Temp:TSettingsFile;
begin
  AssignFile(F,FileName);
  Rewrite(F,1);
  Temp.ActiveMenu:=FActiveMenu; Temp.ShowFPS:=FShowFPS; Temp.User:=FUserName;
  BlockWrite(F,Temp,SizeOf(Temp));
  CloseFile(F);
end;

destructor TGameMenu.Destroy;
begin
  SaveConfig;
  inherited;
end;

procedure TGameMenu.GoResume(O:TObject);
begin
  ActivScene:=GSys;
end;

//{$O-}
function TGameMenu.NextMap:Boolean;
var
  S:String;
  P:Integer;
begin
  Inc(FCurrentMap);
  //S:=ParamStr(0);
  //for P:=Length(S)-1 downto 0 do
  //  if S[P]='\' then Break;
  S:='';//Copy(S,1,P);
  S:=S+MapPath+MapName+IntToStr(FCurrentMap)+'.ASD';
  Result:=FileExists(S);
  if not Result then Exit;
  GSys.LoadMap(S);
end;
//{$O+}

{ TPart }

procedure TPart.DoDraw;
begin
  glColor4ub(FC.R,FC.G,FC.B,Round(FLT*255/FT));
  DrawQuads(FP.X,FP.Y,(FLT-FT)/FT*FMS,(FLT-FT)/FT*FMS,FA);
end;

constructor TPart.Init(Owner:TSpriteEngine; P,V:TVector; T,MS:Real; C:TRGB;
  Loop:Boolean);
begin
  inherited Create(Owner);
  FP:=P; FV:=V; FT:=T; FC:=C; FA:=RndReal(0,360); FO:=RndReal(-1,1,0.001);
  FCP:=FP; FCV:=FV; FLoop:=Loop; FMS:=MS;
  if FLoop then FLT:=RndReal(1,FT) else FLT:=FT;
end;

procedure TPart.DoMove;
const
  G:TVector=(X:0; Y:-0.003);
begin
  FP:=VectorAdd(FP,FV); FV:=VectorAdd(FV,G);
  FLT:=FLT-1; FA:=FA+FO;
  with Wnd do
  begin
    if FP.X<0 then FP.X:=0; if FP.Y<=0 then FP.Y:=0;
    if FP.X>Width then FP.X:=Width; if FP.Y>Height then FP.Y:=Height;
  end;
  if FLT<0 then
    if FLoop then
    begin
      FLT:=FT; FV:=FCV; FP:=FCP;
    end else Dead;
end;

{ TAdditionMenu }

procedure TAdditionMenu.Render;
begin
  ogl.Clear(False,True); ogl.Set2D(0,0,wnd.Width,wnd.Height);
  if Owner is TGameMenu then TGameMenu(Owner).DrawBack;
  inherited;
end;

procedure TAdditionMenu.Update;
begin
  inherited Update;
  if Owner is TGameMenu then TGameMenu(Owner).MoveBack;
end;

end.

