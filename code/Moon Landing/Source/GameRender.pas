unit GameRender;

interface
uses
  eXgine,OpenGL;
procedure DrawRect(X,Y,W,H:Real; Mode:GLenum=GL_QUADS);
procedure DrawRectEx(X,Y,W,H:Real; ScaledX:Real=0; ScaledY:Real=0);
procedure DrawQuads(X,Y,W,H:Real; A:Real=0);

const
  clRed:TRGBA=(R:255; G:0; B:0; A:255);
  clLime:TRGBA=(R:0; G:255; B:0; A:255);
  clBlue:TRGBA=(R:0; G:0; B:255; A:255);
  clWhite:TRGBA=(R:255; G:255; B:255; A:255);
  clBlack:TRGBA=(R:0; G:0; B:0; A:255);
implementation

procedure DrawRect(X,Y,W,H:Real; Mode:GLenum);
begin
  glPushMatrix;
  glTranslated(X,Y,0);
  glBegin(Mode);
  glTexCoord2d(0,0); glVertex2f(0,0);
  glTexCoord2d(1,0); glVertex2f(W,0);
  glTexCoord2d(1,1); glVertex2f(W,H);
  glTexCoord2d(0,1); glVertex2f(0,H);
  glEnd;
  glPopMatrix;
end;

procedure DrawRectEx(X,Y,W,H:Real; ScaledX:Real=0; ScaledY:Real=0);
begin
  if ScaledX=0 then ScaledX:=1 else ScaledX:=W/ScaledX;
  if ScaledY=0 then ScaledY:=1 else ScaledY:=H/ScaledY;
  glPushMatrix;
  glTranslated(X,Y,0);
  glBegin(GL_QUADS);
  glTexCoord2d(0,ScaledY); glVertex2f(0,0);
  glTexCoord2d(ScaledX,ScaledY); glVertex2f(W,0);
  glTexCoord2d(ScaledX,0); glVertex2f(W,H);
  glTexCoord2d(0,0); glVertex2f(0,H);
  glEnd;
  glPopMatrix;
end;

procedure DrawQuads(X,Y,W,H:Real; A:Real=0);
begin
  W:=W/2;
  H:=H/2;
  glPushMatrix;
  glTranslated(X,Y,0);
  glRotated(A,0,0,1);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0); glVertex2f(-W,-H);
  glTexCoord2d(1,0); glVertex2f(W,-H);
  glTexCoord2d(1,1); glVertex2f(W,H);
  glTexCoord2d(0,1); glVertex2f(-W,H);
  glEnd;
  glPopMatrix;
end;

end.
