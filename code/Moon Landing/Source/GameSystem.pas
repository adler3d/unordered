unit GameSystem;
interface
uses
  Windows,Menu,Scene,eXgine,OpenGL,ASDVector,QuickSprites,Tools,
  PhysicSprites,GameRender,ASDClock,InfoScene,ASDStream;

type
  TPlayer=record
    Wheel1,Wheel2:TBot;
    Connect:TConnectBot;
    Tag:Integer;
  end;
  TCamera=record
    P,V:TVector;
    A:Real;
  end;
  TMapHeader=record
    Magic:string[3];
    AppVer:Integer;
    Date,Time:TDateTime;
    MapName:string[32];
    MeshCount:Integer;
    Scale:Real;
    Start,Finish:TVector;
  end;
  TGameSys=class(TScene)
  private
    PE:TPhysicEngine;
    SP:TSpriteEngine;
    Player:TPlayer;
    Camera:TCamera;
    FStart,FFinish:TVector;
    FLife:Integer;
    LevelName:string;
    FWin:Boolean;
    Clock:TClock;
    FInfo:TInfoScene;
    procedure MakeMoped;
    procedure AddPart(P:TVector; MS:Real; Color:TRGB);
    procedure InitEffect;
    procedure WorkCollision(Sender:TBot);
  protected
    procedure Render; override;
    procedure Update; override;
    procedure GoMenu;
    procedure GoGameEnd;
  public
    constructor Create;
    procedure InitBot;
    procedure NewLife;
    procedure NewGame;
    procedure MapWalking;
    procedure LoadMap(FileName:string);
    function LoadMapHeader(FileName:string):TMapHeader;
  end;

  TPart=class(TSprite)
  private
    FP,FV,FCP,FCV:TVector;
    FA,FT,FO,FLT,FMS:Real;
    FC:TRGB;
    FLoop:Boolean;
    FTex:TTexture;
  protected
    procedure DoDraw; override;
    procedure DoMove; override;
  public
    constructor Init(Owner:TSpriteEngine; P,V:TVector; T,MS:Real; C:TRGB;
      Loop:Boolean=False);
  end;

implementation
uses
  GameApp,GameMouse,GameRes;
const
  Gravity:TVector=(X:0; Y:0.020);
  Friction=0.0005;

procedure RNDShar(const ABot:TBot);
const
  pr=1;
  Kof=0.5;
  Rot=100;
  E_Pb=15.0;
var
  aH,aW:Integer;
  cR,cG,cB:Byte;
begin
  aH:=Wnd.Height;
  aW:=Wnd.Width;
  with ABot do
  begin
    if R=0 then
      R:=RndReal(16,16);
    Texture:=Ball;
    V:=MakeVector(RndReal(-pr,pr),RndReal(-pr,pr));
    P:=MakeVector(RndReal(R+Rot,aW-R-Rot),RndReal(R+Rot,aH-R-
      Rot));
    M:=Pi*R*R*Kof;
    E:=E_Pb*M/8;
    W:=RndReal(-Pi,Pi,0.0001)/64;
    I:=(M*R*R)*Kof;
    K:=1;
    A:=RndReal(-Pi,Pi,0.0001);
    C:=RGBA(255,255,255,255);
  end;
end;

{ TGameSys }

constructor TGameSys.Create;
begin
  PE:=TPhysicEngine.Init;
  PE.Bots.Friction:=Friction;
  PE.Bots.Gravity:=Gravity;
  PE.OnCollision:=WorkCollision;
  SP:=TSpriteEngine.Create(PE);
  Clock:=TClock.Create;
end;

procedure TGameSys.GoMenu;
begin
  ActivScene:=GMenu; inp.Reset; GMenu.Select:=0;
end;

procedure TGameSys.InitBot;
const
  C:Integer=0;
var
  I,J,ReSetupCount,Count:integer;
  Bot:TBot;
label
  ReSetup;
begin
  PE.Bots.Friction:=Friction;
  PE.Bots.Gravity:=Gravity;
  ReSetupCount:=C*55;
  for J:=1 to 3 do
    for I:=1 to C do
    begin
      Bot:=TBot.Init(PE);
      ReSetup:
      RNDShar(Bot);
      Bot.P:=MakeVector(I*30,300+50*J);
      {for J:=0 to PE.Bots.Count-2 do
      begin
        if TestCollisionBot(Bot,PE.Bots[J]) then
        begin
          Dec(ReSetupCount);
          if ReSetupCount<=0 then
            Exit;
          goto ReSetup;
        end;
      end;}
    end;
end;

procedure TGameSys.AddPart(P:TVector; MS:Real; Color:TRGB);
begin
  TPart.Init(SP,P,RndVector(0.2),UPS,MS,Color,True).FTex:=Flame;
end;

procedure TGameSys.NewGame;
begin
  GMenu.Items[0].Enabled:=True; Player.Wheel1:=nil; Player.Wheel2:=nil;
  Camera.P:=FStart; Camera.V:=MakeVector(0,0); Camera.A:=0; InitEffect;
  FLife:=3; NewLife; FWin:=False; Clock.Stop;
end;

procedure TGameSys.Render;
begin
  if FInfo<>nil then Exit;
  with wnd,ogl do
  begin
    glClearColor(0,0,0,0); Clear; Set2D(0,0,Width,Height);
    with Camera do
    begin
      glTranslated(-P.X+Width/2,-P.Y+Height/2,0);
      glRotated(A,0,0,1);
    end;
    Blend(BT_SUB);
    PE.Draw;
    Set2D(0,0,Width,Height);
    if ((Player.Connect=nil)and(Player.Wheel1<>nil))or(Player.Tag<0)or(FWin) then
    begin
      if Player.Tag>0 then glColor4d(0,0,0,1-Player.Tag/(UPS*2)) else
        glColor4d(0,0,0,Abs(Player.Tag/(UPS*2)));
      OGL.Blend(BT_SUB);
      glBegin(GL_QUADS);
      glVertex2f(-Width,-Height);
      glVertex2f(+Width,-Height);
      glVertex2f(+Width,+Height);
      glVertex2f(-Width,+Height);
      glEnd;
    end;
    RenderMouse(Cursor);
    GMenu.DrawFPS;
    TextOut(0,Width-200,16,PChar('Life : '+IntToStr(FLife)));
    TextOut(0,Width-200,32,PChar('MapName : '+LevelName));
    if Clock.Activ then
      TextOut(0,10,26,PChar('Time : '+FloatToStr(Clock.Sec,-1,2)+' s')) else
      TextOut(0,10,26,PChar('Time : 0.00 s'));
  end;
end;

procedure TGameSys.Update;
const
  CMove:Real=5;
var
  T:TVector;
  Bot:TBot;
begin
  if FInfo<>nil then
  begin
    FInfo.Free;
    FInfo:=nil;
    if not GMenu.NextMap then
    begin
      GMenu.GoCredits(nil); GMenu.Items[0].Enabled:=False; GMenu.Select:=1;
    end;
    Exit;
  end;
  PE.Move; PE.Collision; //PE.CollisionMap;
  with Camera,Player do
  begin
    if Player.Wheel1<>nil then
    begin
      T:=VectorDiv(VectorAdd(Wheel2.P,Wheel1.P),2);
      V:=VectorSub(V,VectorDiv(V,100));
      V:=VectorAdd(V,VectorDiv(VectorSub(VectorSub(T,P),V),1000));
    end;
    P:=VectorAdd(P,V);
  end;
  UpdateMouse;
  if inp.Down(27) then GoMenu;
  {if inp.Down(Ord('A')) then
  begin
    inp.Reset;
    Bot:=TBot.Init(PE);
    RNDShar(Bot);
    Bot.P:=FStart;
  end;}
  if Player.Tag<=0 then
  begin
    Inc(Player.Tag);
    if Player.Tag=0 then MakeMoped;
  end;
  if not FWin then
  begin
    with Player,Camera,inp do
      if Connect=nil then
      begin
        {if Down(VK_LEFT) then P:=VectorAdd(P,MakeVector(-CMove,0));
        if Down(VK_RIGHT) then P:=VectorAdd(P,MakeVector(+CMove,0));
        if Down(VK_UP) then P:=VectorAdd(P,MakeVector(0,-CMove));
        if Down(VK_DOWN) then P:=VectorAdd(P,MakeVector(0,+CMove));}
        if Wheel1<>nil then
        begin
          Dec(Tag);
          if (Tag mod 2)=0 then
          begin
            //TPart.Init(SP,Wheel1.P,RndVector(0.3),UPS,UPS/4,RGB(255,255,255)).FTex:=Smoke;
            //TPart.Init(SP,Wheel2.P,RndVector(0.3),UPS,UPS/4,RGB(255,255,255)).FTex:=Smoke;
          end;
          if Tag<=0 then GoGameEnd;
        end;
      end else
      begin
        if (Connect.Deaded)or Down(Ord('D')) then
        begin
          Tag:=UPS*2; Connect:=nil;
        end else Inc(Tag);
        if TestCollisionVertex(Wheel1,FFinish)or
          TestCollisionVertex(Wheel2,FFinish) then
        begin
          FWin:=True; Tag:=UPS*2;
        end;
        if (Tag mod 2)=0 then
        begin
          TPart.Init(SP,VectorAdd(Wheel1.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=flame;
          TPart.Init(SP,VectorAdd(Wheel2.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=Smoke;
          {TPart.Init(SP,VectorAdd(Wheel1.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=flame;
          TPart.Init(SP,VectorAdd(Wheel2.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=Smoke;
          TPart.Init(SP,VectorAdd(Wheel1.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=flame;
          TPart.Init(SP,VectorAdd(Wheel2.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=Smoke;
          TPart.Init(SP,VectorAdd(Wheel1.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=flame;
          TPart.Init(SP,VectorAdd(Wheel2.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=Smoke;
          TPart.Init(SP,VectorAdd(Wheel1.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=flame;
          TPart.Init(SP,VectorAdd(Wheel2.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=Smoke;
          TPart.Init(SP,VectorAdd(Wheel1.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=flame;
          TPart.Init(SP,VectorAdd(Wheel2.P,RndVector(40)),RndVector(0.3),UPS,UPS/4,RGB(255,255,255),False).FTex:=Smoke;}
        end;
        if Down(VK_LEFT) then Wheel1.AddW(-0.007);
        if Down(VK_RIGHT) then Wheel1.AddW(+0.007);
        if Down(VK_SPACE) then Wheel2.ClearAccum;
      end;
  end else
  begin
    Dec(Player.Tag);
    if Player.Tag=0 then MapWalking;
  end;
  PE.Dead;
end;

procedure TGameSys.MakeMoped;
var
  Pos:TVector;
begin
  Pos:=FStart;
  with Player do
  begin
    Wheel1:=TBot.Init(PE);
    //DefBot:=Wheel1;
    with Wheel1 do
    begin
      R:=40; RNDShar(Wheel1);
      P:=MakeVector(0,100); P:=VectorAdd(P,Pos);
      V:=MakeVector(0.2,0);
      C:=RGBA(255,255,0,255); I:=(M*R*R)/10;
    end;
    Wheel2:=TBot.Init(PE);
    with Wheel2 do
    begin
      R:=40; RNDShar(Wheel2);
      P:=MakeVector(0,-100); P:=VectorAdd(P,Pos);
      V:=MakeVector(0.2,0);
      C:=RGBA(255,255,0,255); I:=(M*R*R)/10;
    end;
    Player.Connect:=TConnectBot.Init(PE,Wheel1,Wheel2);
    Player.Connect.MaxF:=Player.Connect.MaxF*4;
    Camera.P:=Pos; Camera.V:=NulVector;
  end;
  Clock.Start;
end;

procedure TGameSys.LoadMap(FileName:string);
procedure AddLog(S:String);
begin
  log.Print(PChar(S));
end;
var
  F:TFileStream;
  H:record
    Magic:string[3];
    AppVer:Integer;
    Date,Time:TDateTime;
    MapName:string[32];
    MeshCount:Integer;
    Scale:Real;
    Start,Finish:TVector;
  end;
  I:Integer;
  M:TMeshObject;
begin
  if not FileExists(FileName) then
  begin
    AddLog('Error LoadMap : File "'+FileName+'" not found'); Exit;
  end;
  F:=TFileStream.Create(FileName,fmOpenRead or fmShareDenyRead);
  PE.Clear;
  F.ReadBuffer(H,SizeOf(H));
    if H.Magic<>'Map' then
    begin
      AddLog('Error LoadMap : File "'+FileName+'" not identify'); Exit;
    end;
    {EditScale.Text:=FloatToStr(Scale);} LevelName:=H.MapName;
    if H.AppVer<>7 then
    begin
      AddLog('Error LoadMap : not compatible version'); Exit;
    end;
    FStart:=H.Start; FFinish:=H.Finish;
    for I:=1 to H.MeshCount do
    begin
      M:=TMeshObject.Init(PE); M.LoadFromStream(F);
    end;
  F.Free; NewGame;
end;

function TGameSys.LoadMapHeader(FileName:string):TMapHeader;
var
  F:file;
begin
{$I-}
  AssignFile(F,FileName); Reset(F,1);
{$I+}
  if IOResult<>0 then
  begin
    log.Print(PChar('Error : File "'+FileName+'" not found')); Exit;
  end;
  BlockRead(F,Result,SizeOf(Result)); CloseFile(F);
end;

procedure TGameSys.InitEffect;
var
  I:Integer;
begin
  //for I:=0 to 10 do AddPart(FStart,80,RGB(255,64,16));
  for I:=0 to 250 do AddPart(FFinish,100,RGB(64,128,255));
  for I:=0 to 250 do AddPart(FStart,100,RGB(255,128,64));
end;

procedure TGameSys.GoGameEnd;
begin
  Dec(FLife);
  if FLife>=0 then
  begin
    NewLife; Exit;
  end;
  GoMenu; GMenu.Items[0].Enabled:=False; GMenu.Select:=1;
end;

procedure TGameSys.NewLife;
begin
  Player.Wheel1:=nil; Player.Wheel2:=nil; Player.Connect:=nil;
  Player.Tag:=-2*UPS; Camera.P:=FStart; Camera.V:=NulVector; Clock.Stop;
end;

procedure TGameSys.WorkCollision(Sender:TBot);
begin

    //if (Player.Tag mod 5=0){and((Player.Wheel1=Sender)or(Player.Wheel2=Sender))} then
    //begin
    //  TPart.Init(SP,Sender.P,RndVector(0.3),UPS,UPS/4,RGB(255,255,255)).FTex:=Smoke;
    //end;
end;

procedure TGameSys.MapWalking;
begin
  FInfo:=TInfoScene.Create(Self,7);
  FInfo.Text:='Map : '+LevelName+'   [Time : '+FloatToStr(Clock.Sec,-1,2)+' s]';
  ActivScene:=FInfo;
end;

{ TPart }

procedure TPart.DoDraw;
begin
  glPushMatrix;
  ogl.Blend(BT_ADD);
  tex.Enable(FTex);
  glColor4ub(FC.R,FC.G,FC.B,Round(FLT*255/FT));
  DrawQuads(FP.X,FP.Y,(FLT-FT)/FT*FMS,(FLT-FT)/FT*FMS,FA);
  tex.Disable;
  glPopMatrix;
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
  if FLT<0 then
    if FLoop then
    begin
      FLT:=FT; FV:=FCV; FP:=FCP;
    end else Dead;
end;

end.

