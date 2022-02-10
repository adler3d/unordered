unit Scene;
interface
uses
  Windows,Messages,eXgine,OpenGL,Tools;
type
  TScene=class(TObject)
  public
    procedure Render; virtual;
    procedure Update; virtual;
  end;

procedure Update;
procedure Render;
procedure UseMessage(Msg:LongWord; wP,lP:Integer);

var
  ActivScene:TScene;
implementation

uses GameApp;

procedure DefRender;
var
  X,Y:Integer;
  procedure AddText(S:string; AX:Word=0; AY:Word=0);
  begin
    if AX<>0 then X:=AX; if AY<>0 then Y:=AY;
    ogl.TextOut(0,X,Y,PChar(S)); Inc(Y,15);
  end;
begin
  ogl.Clear; ogl.Set2D(0,0,wnd.Width,wnd.Height);
  glColor3f(1,0,0);
  AddText('Default scene',10,10); glColor3f(1,1,1);
  AddText('Concurs : '+Concurs);
  AddText('AppName : '+AppName);
  AddText('AppVer : '+AppVer);
  glColor3f(0,1,0);
  AddText('Time : '+TimeToStr(GetTime),Wnd.Width-200,10);
  AddText('Date : '+DateToStr(GetDate));
end;

procedure DefUpdate;
begin
  if inp.Down(27) then
  eX.Quit;
end;

procedure Update;
begin
  if ActivScene=nil then DefUpdate else ActivScene.Update;
end;

procedure Render;
begin
  if ActivScene=nil then DefRender else ActivScene.Render;
end;

procedure UseMessage(Msg:LongWord; wP,lP:Integer);
const
  Path='..\ScreenShots\';
var
  TS,DS:Char;
begin
  if (msg=WM_KEYUP)and(wp=VK_SNAPSHOT) then
  begin
    if not DirExists(Path) then MkDir(Path);
    TS:=TimeSeparator; DS:=DateSeparator; TimeSeparator:='-';
    DateSeparator:='-';
    ogl.ScreenShot(PChar(Path+AppName+DateToStr(GetDate)+'-'+TimeToStr(GetTime)+'.bmp'));
    TimeSeparator:=TS; DateSeparator:=DS;
    inp.Reset;
  end;
  if (msg=WM_SYSKEYDOWN)and(wp=VK_F10) then
  begin
    ActivScene:=nil;
  end;
end;

{ TScene }

procedure TScene.Render;
begin
  DefRender;
end;

procedure TScene.Update;
begin
  DefUpdate;
end;

initialization
end.

