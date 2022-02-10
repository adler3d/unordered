unit GameApp;
interface

uses
  eXgine,OpenGL,Tools,Scene,GameRes,GameMenu,GameSystem,GameRender,LogoScene;
const
  UPS=100;
  Concurs='None';
  AppName='Moon Landing';
  AppVer='0.9';
  AASamples=4;
  VSync=True;
type
  TApp=class
    Debug:Boolean;
  public
    constructor Create;
    procedure Init;
    procedure Run;
    procedure ShutDown;
  end;
var
  App:TApp;
  GMenu:TGameMenu;
  GSys:TGameSys;
implementation

{ TApp }

constructor TApp.Create;
var
  SM:TScreenMode;
begin
  SM:=GetScreenMode;
  eX.SetProc(PROC_UPDATE,@Scene.Update);
  eX.SetProc(PROC_RENDER,@Scene.Render);
  eX.SetProc(PROC_MESSAGE,@Scene.UseMessage);
  if ParamCount=1 then Debug:=ParamStr(1)='-Debug' else Debug:=False;
  ogl.AntiAliasing(AASamples);
  wnd.Create(AppName,not Debug); wnd.Mode(True,SM.X,SM.Y,SM.BPP,SM.Freg);
  inp.MCapture(True); eX.ActiveUpdate(True); ogl.VSync(VSync);
end;

procedure TApp.Init;
begin
  LoadRes;
  GMenu:=TGameMenu.Create; GSys:=TGameSys.Create;
  ActivScene:=GMenu;//TLogo.Create(GMenu,IGDC,2);
end;

procedure TApp.Run;
begin
  eX.MainLoop(UPS);
end;

procedure TApp.ShutDown;
begin
  GMenu.Free;
  GSys.Free;
end;

end.

