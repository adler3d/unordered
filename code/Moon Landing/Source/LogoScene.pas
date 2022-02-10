unit LogoScene;
interface

uses
  eXgine,Scene,OpenGL,GameRender;
type
  TLogo=class(TScene)
  private
    FT,FMT:Real;
    FNS:TScene;
    FI:TTexture;
    procedure Run;
  public
    constructor Create(NS:TScene; Logo:TTexture; MT:Real);
    procedure Render; override;
    procedure Update; override;
    property NextScene:TScene read FNS write FNS;
    property MaxTime:Real read FMT write FMT;
    property Image:TTexture read FI write FI;
    property Time:Real read FT write FT;
  end;

implementation
uses
  GameApp,GameRes;

{ TApp }

constructor TLogo.Create(NS:TScene; Logo:TTexture; MT:Real);
begin
  FNS:=NS; FI:=Logo; FT:=0; FMT:=MT;
end;

procedure TLogo.Render;
begin
  ogl.Clear; ogl.Set2D(0,0,wnd.Width,wnd.Height); ogl.Blend(BT_SUB);
  with wnd do
  begin
    if FT>FMT/2 then
    begin
      FNS.Render;
      glColor4d(0,0,0,2-FT*2/FMT); DrawRect(0,0,Width,Height);
    end;
    if FT<FMT/2 then glColor4d(1,1,1,(FT*2/FMT)) else
    begin
      glColor4d(1,1,1,2-FT*2/FMT); ogl.Blend(BT_ADD);
    end;
    tex.Enable(FI); DrawQuads(Width/2,Height/2,512,512); tex.Disable;
  end;
end;

procedure TLogo.Run;
begin
  eX.MainLoop(UPS);
end;

procedure TLogo.Update;
begin
  FT:=FT+1/UPS; if FT>FMT/2 then FNS.Update; if FT>=FMT then ActivScene:=FNS;
  if inp.Down(27) then eX.Quit;
end;

end.

