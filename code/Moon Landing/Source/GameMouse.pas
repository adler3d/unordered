unit GameMouse;
{<|Вспомогательный модуль|>}
{<|Дата создания 18.03.08|>}
{<|Автор Adler3D|>}
{<|e-mail : Adler3D@Mail.ru|>}
{<|Дата последнего изменения 31.03.08|>}
interface
uses
  Windows,eXgine,OpenGL,ASDVector,Tools;

procedure InitMouse(X,Y:Real);
procedure RenderMouse(Img:TTexture);
procedure UpdateMouse;
function GetMousePos:TVector;
function MouseMoved:Boolean;

implementation
var
  MX,MY:Real;
  Moved:Boolean;

procedure InitMouse(X,Y:Real);
begin
  MX:=X; MY:=Y;
end;

procedure RenderMouse(Img:TTexture);
const
  Size:Real=32;
begin
  ogl.Blend(BT_SUB);
  tex.Enable(Img); glColor3d(1,1,1);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0); glVertex2f(MX,MY);
  glTexCoord2d(1,0); glVertex2f(MX+Size,MY);
  glTexCoord2d(1,1); glVertex2f(MX+Size,MY+Size);
  glTexCoord2d(0,1); glVertex2f(MX,MY+Size);
  glEnd;
  tex.Disable;
end;

procedure UpdateMouse;
begin
  with wnd,inp.MDelta do
  begin
    Moved:=(X<>Y)or(X<>0);
    MX:=MX+X;
    MY:=MY+Y;
    if MX<0 then MX:=0; if MY<=0 then MY:=0;
    if MX>Width then MX:=Width; if MY>Height then MY:=Height;
  end;
end;

function GetMousePos:TVector;
begin
  Result:=MakeVector(MX,MY);
end;

function MouseMoved:Boolean;
begin
  Result:=Moved;
end;

end.

 