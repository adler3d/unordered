unit GameRes;

interface
uses eXgine;

procedure LoadRes;

const
  TexPath:string='..\GFX\';
var
  Back,Cursor,Logo,Smoke,Cell,Light,Ball,flame,IGDC,LevelWalk:TTexture;

procedure Load(out Img:TTexture; FileName:string);

implementation

uses GenImage;

procedure Load(out Img:TTexture; FileName:string);
begin
  Img:=Tex.Load(PChar(TexPath+FileName));
end;

procedure LoadRes;
begin
  Load(Smoke,'Effects\Smoke.tga');
  Load(flame,'Effects\flame.tga');
  Load(Cursor,'GUI\Cursor.tga');
  Load(Logo,'GUI\Logo.tga');
  Load(Cell,'GUI\Cell.bmp');
  Load(Light,'GUI\Light.tga');
  Load(LevelWalk,'GUI\Level Walking.tga');
  //Load(IGDC,'IGDC.tga');
  Ball:=Gen(BallPathImage(256));
end;

end.

