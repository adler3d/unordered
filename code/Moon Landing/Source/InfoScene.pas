unit InfoScene;

interface
uses
  eXgine,OpenGL,Windows,Scene,ASDClock,GameRes,GameRender,GameMouse;
type
  TInfoScene=class(TScene)
  private
    FTime:Real;
    FTarget:TScene;
    FText: String;
  protected
  public
    constructor Create(Target:TScene; Time:Real);
    property Time:Real read FTime write FTime;
    property Target:TScene read FTarget write FTarget;
    property Text:String read FText write FText;
    procedure Update; override;
    procedure Render; override;
  end;

implementation
uses
  GameApp;

{ TInfoScene }

constructor TInfoScene.Create(Target:TScene; Time:Real);
begin
  FTime:=Time;
  FTarget:=Target;
end;

procedure TInfoScene.Render;
begin
  with wnd,ogl,GMenu do
  begin
    glClearColor(0,0,0,0); ogl.Clear; Set2D(0,0,Width,Height);
    Blend(BT_SUB);
    glColor3d(1,0.5,0);
    TextOut(Font,(Width-TextLen(Font,PChar(Text)))/2,(Height+128)/2,PChar(Text));
    tex.Enable(LevelWalk); DrawQuads(Width/2,Height/2,512,128,0); tex.Disable;
    RenderMouse(Cursor);
  end;
end;

procedure TInfoScene.Update;
begin
  UpdateMouse;
  Time:=Time-1/UPS;
  if inp.Down(27) then ActivScene:=GMenu;
  if (Time<0) or inp.Down(32) then ActivScene:=Target;
  inp.Reset;
end;

end.

