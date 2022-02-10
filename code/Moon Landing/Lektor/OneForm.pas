unit OneForm;
interface

uses
  eXgine,Windows,Messages,Graphics,Controls,Forms,SysUtils,Classes,ExtCtrls,
  ASDVector,StdCtrls,Buttons,Dialogs,Menus,MeshUnit;

type
  THackPopupList=class(TPopupList)
  protected
    procedure WndProc(var Message:TMessage); override;
  end;

  PQUADS=^TQUADS;
  TQUADS=record
    A,B,C,D:TVector;
  end;
  TMode=(mNone,mADD);

  TeXForm=class(TForm)
    Timer_eX:TTimer;
    TimerRender:TTimer;
    XBox:TPanel;
    sd:TSaveDialog;
    UserBox:TPanel;
    lbTex:TLabel;
    BoxTex:TComboBox;
    BoxInfo:TPanel;
    lbZoom:TLabel;
    lbPosition:TLabel;
    od:TOpenDialog;
    sbClear:TSpeedButton;
    sbOpen:TSpeedButton;
    sbSave:TSpeedButton;
    lbMap:TLabel;
    edMapName:TEdit;
    PopupMenu:TPopupMenu;
    NTex:TMenuItem;
    NInvNormal:TMenuItem;
    NNul3:TMenuItem;
    NAddBot:TMenuItem;
    NNul:TMenuItem;
    NStart:TMenuItem;
    NFinish:TMenuItem;
    NNul2:TMenuItem;
    NDel:TMenuItem;
    NNUL_Con:TMenuItem;
    NBringF:TMenuItem;
    NBringB:TMenuItem;
    lbMPos: TLabel;
    lbNumMesh: TLabel;
    procedure Timer_eXTimer(Sender:TObject);
    procedure FormCreate(Sender:TObject);
    procedure TimerRenderTimer(Sender:TObject);
    procedure FormKeyDown(Sender:TObject; var Key:Word;
      Shift:TShiftState);
    procedure XBoxMouseDown(Sender:TObject; Button:TMouseButton;
      Shift:TShiftState; X,Y:Integer);
    procedure BoxTexEnter(Sender:TObject);
    procedure PopupMenuPopup(Sender:TObject);
    procedure NStartClick(Sender:TObject);
    procedure NFinishClick(Sender:TObject);
    procedure NInvNormalClick(Sender:TObject);
    procedure NTexClick(Sender:TObject);
    procedure NDelClick(Sender:TObject);
    procedure sbOpenClick(Sender:TObject);
    procedure sbSaveClick(Sender:TObject);
    procedure sbClearClick(Sender:TObject);
    procedure NBringFClick(Sender:TObject);
    procedure NBringBClick(Sender:TObject);
    procedure XBoxMouseUp(Sender:TObject; Button:TMouseButton;
      Shift:TShiftState; X,Y:Integer);
    procedure fdShow(Sender: TObject);
    procedure fdClose(Sender: TObject);
    procedure FormMouseWheel(Sender: TObject; Shift: TShiftState;
      WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
  private
    Mode:TMode;
    Zoom:Real;
    FCP,FMP:TVector;
    FMeshList:TList;
    FSelect,FEdit:TMesh;
    FStart,FFinish:TVector;
    FMouseCap:Boolean;
    function BoxToMap(P:TVector):TVector;
    function MapToBox(P:TVector):TVector;
    procedure DrawGrid;
    procedure UpLabel;
    function GetIsXBoxActiv:Boolean;
    function GetSelected:Boolean;
    function GetMPos:TVector;
    procedure DoMouse;
    function GetMesh(Pos:TVector):TMesh;
    procedure DrawEdit;
    procedure DrawSelect;
    procedure DrawSF;
    function GetMouseCap: Boolean;
  public
    procedure Init_eX;
    procedure Render;
    procedure DrawMeshList;
    procedure Clear;
    procedure ZoomIn;
    procedure ZoomOut;
    procedure LoadFromFile(FileName:string);
    procedure SaveToFile(FileName:string);
    property IsXBoxActiv:Boolean read GetIsXBoxActiv;
    property Selected:Boolean read GetSelected;
    property MPos:TVector read GetMPos;
    property MouseCap:Boolean read GetMouseCap;
  end;
const
  //MapDir='..\GFX\Background\';
  TexDir='..\GFX\Maps\';
var
  eXForm:TeXForm;
  Ang:Real;
  AppPath:string;
implementation

uses OpenGL,GameRender,Math;
//{$DEFINE DrawRoad}
{$R *.dfm}

procedure Rib(const A,B:TVector);
var
  C,D:TVector;
  L:Real;
begin
  L:=10/eXForm.Zoom;
  C.X:=(A.X+B.X)/2;
  C.Y:=(A.Y+B.Y)/2;
  D:=VectorAdd(C,MakeVectorEx(Pi/2+VectorGetAlfa(VectorSub(A,B)),L));
  glBegin(GL_LINES);
  glVertex2dv(@A); glVertex2dv(@B);
  glVertex2dv(@C); glVertex2dv(@D);
  glEnd;
end;

function CollisionMesh(M:TMesh; const C:TVector):Boolean;
var
  I:Integer;
  L,C_R:Real;
  LV,AB,A,B,AC,R:TVector;
begin
  C_R:=5/eXForm.Zoom;
  Result:=False;
  A:=M.Last;
  for I:=0 to M.Count-1 do
  begin
    B:=M[I]; AB:=VectorSub(B,A); AC:=VectorSub(C,A);
    R:=VectorRot(AC,AB); L:=VectorMagnitude(AB);
    if (R.X>=0)and(R.X<=L)and(R.Y>=-C_R)and(R.Y<=C_R) then
    begin
      Result:=True; Exit;
    end; A:=B;
  end;
end;

function FtStr(V:Real; E:Integer):string;
begin
  Str(V:0:E,Result);
end;

procedure JaRender;
begin
  eXForm.Render;
end;

{ THackPopupList }

procedure THackPopupList.WndProc(var Message:TMessage);
var
  I:Integer;
  Menu:TPopupMenu;
begin
  if (Message.Msg=WM_EXITMENULOOP) then
  begin
    eXForm.FMouseCap:=True;
  end; inherited;
end;

{ TFormEdit }

procedure DrawTwo(A,B:TVector);
const
  W:Real=10;
var
  N,AB,T:TVector;
  function FA(V:TVector):PGLdouble;
  begin
    T.X:=V.X+N.X; T.Y:=V.Y+N.Y; Result:=@T;
  end;
  function FS(V:TVector):PGLdouble;
  begin
    T.X:=V.X-N.X; T.Y:=V.Y-N.Y; Result:=@T;
  end;
begin
  AB:=VectorSub(B,A);
  N:=MakeVectorEx(VectorGetAlfa(AB)+Pi/2,W);
  glBegin(GL_LINE_LOOP);
  glVertex2dv(FA(A)); glVertex2dv(FS(A));
  glVertex2dv(FS(B)); glVertex2dv(FA(B));
  glEnd;
end;

procedure DrawBox(F,A,B,L:TVector);
const
  W:Real=100;
var
  NA,NB,T:TVector;
  function Norm(X,Y,Z:TVector):TVector;
  var
    V1,V2:TVector;
  begin
    if VectorEquel(X,Y) then
    begin
      Result:=MakeVectorEx(VectorGetAlfa(VectorSub(Y,Z))+Pi/2,W); Exit;
    end;
    if VectorEquel(Y,Z) then
    begin
      Result:=MakeVectorEx(VectorGetAlfa(VectorSub(X,Y))+Pi/2,W); Exit;
    end;
    V1:=VectorNormal(VectorSub(Y,X));
    V2:=VectorNormal(VectorSub(Z,Y));
    Result:=VectorSetDlina(VectorMul(VectorSub(V1,V2),VectorCross(V1,V2)),W);
  end;
  function FA(V,N:TVector):PGLdouble;
  begin
    T.X:=V.X+N.X; T.Y:=V.Y+N.Y; Result:=@T;
  end;
  function FS(V,N:TVector):PGLdouble;
  begin
    T.X:=V.X-N.X; T.Y:=V.Y-N.Y; Result:=@T;
  end;
begin
  NA:=Norm(F,A,B); NB:=Norm(A,B,L);
  glBegin(GL_LINE_LOOP);
  glTexCoord2dv(FA(A,NA)); glVertex2dv(FA(A,NA));
  glTexCoord2dv(FS(A,NA)); glVertex2dv(FS(A,NA));
  glTexCoord2dv(FS(B,NB)); glVertex2dv(FS(B,NB));
  glTexCoord2dv(FA(B,NB)); glVertex2dv(FA(B,NB));
  glEnd;
end;

procedure DrawLine(A,B:TVector);
begin
  glBegin(GL_LINES);
  glVertex2dv(@A); glVertex2dv(@B);
  glEnd;
end;

procedure DrawLineEx(A,B:TPoint);
begin
  glBegin(GL_LINES);
  glVertex2iv(@A); glVertex2iv(@B);
  glEnd;
end;

procedure DrawPoint(P:TVector);
var
  PS:Real;
begin
  PS:=2/eXForm.Zoom;
  glBegin(GL_QUADS);
  glVertex2d(P.X-PS,P.Y-PS);
  glVertex2d(P.X+PS,P.Y-PS);
  glVertex2d(P.X+PS,P.Y+PS);
  glVertex2d(P.X-PS,P.Y+PS);
  glEnd;
end;

procedure DrawPointEx(P:TPoint);
const
  PS=2;
begin
  glBegin(GL_QUADS);
  glVertex2i(P.X-PS,P.Y-PS);
  glVertex2i(P.X+PS,P.Y-PS);
  glVertex2i(P.X+PS,P.Y+PS);
  glVertex2i(P.X-PS,P.Y+PS);
  glEnd;
end;

procedure TeXForm.LoadFromFile(FileName:string);
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
  M:TMesh;
begin
  if not FileExists(FileName) then
  begin
    ShowMessage('Error : File "'+FileName+'" not found'); Exit;
  end;
  F:=TFileStream.Create(FileName,fmOpenRead or fmShareDenyRead);
  Clear;
  F.ReadBuffer(H,SizeOf(H));
  with H do
  begin
    if Magic<>'Map' then
    begin
      ShowMessage('Error : File "'+FileName+'" not identify'); Exit;
    end;
    edMapName.Text:=MapName;
    if AppVer<>7 then
    begin
      ShowMessage('Error : not compatible version'); Exit;
    end;
    FStart:=Start; FFinish:=Finish; Zoom:=Scale; FCP:=Start;
    for I:=1 to MeshCount do
    begin
      FMeshList.Add(TMesh.Create);
      TMesh(FMeshList.Last).LoadFromStream(F);
    end;
  end;
  F.Free; FEdit:=nil; FSelect:=nil;
end;

procedure TeXForm.SaveToFile(FileName:string);
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
  Temp:Pointer;
begin
  F:=TFileStream.Create(FileName,fmCreate);
  H.Magic:='Map'; H.MapName:=edMapName.Text;
  H.MeshCount:=FMeshList.Count; H.Date:=Date; H.Time:=Time;
  H.AppVer:=7; H.Scale:=Zoom;
  H.Start:=FStart; H.Finish:=FFinish;
  F.WriteBuffer(H,SizeOf(H));
  for I:=0 to FMeshList.Count-1 do TMesh(FMeshList[I]).SaveToStream(F);
  F.Free;
end;

procedure TeXForm.Init_eX;
begin
  wnd.Create(XBox.Handle); eX.SetProc(PROC_RENDER,@JaRender);
  inp.MCapture(False);
end;

procedure TeXForm.Render;
begin
  glViewport(0,0,wnd.Width,wnd.Height);
  ogl.Set2D(0,0,wnd.Width,wnd.Height);
  glClearColor(0,0,0,1); ogl.Clear;
  glTranslated(wnd.Width/2,wnd.Height/2,0);
  glScaled(Zoom,Zoom,1); glTranslated(-FCP.X,-FCP.Y,0);
  DrawGrid;
  DrawMeshList;
end;

procedure TeXForm.Timer_eXTimer(Sender:TObject);
begin
  if BorderStyle=bsNone then
  begin
    Init_eX; Timer_eX.Enabled:=False;
    FCP:=MakeVector(wnd.Width/2,wnd.Height/2);
  end else
  begin
    BorderStyle:=bsNone; WindowState:=wsMaximized;
  end;
end;

procedure TeXForm.FormCreate(Sender:TObject);
begin
  Ang:=0; Zoom:=1; FMouseCap:=True;
  AppPath:=ExtractFilePath(ParamStr(0));
  BoxTexEnter(nil); FMeshList:=TList.Create;
  od.InitialDir:=ExtractFileDir(ParamStr(0))+'\Maps';
  sd.InitialDir:=ExtractFileDir(ParamStr(0))+'\Maps';
  TClass(pointer(PopupList)^):=THackPopupList;
end;

procedure TeXForm.TimerRenderTimer(Sender:TObject);
  function IsDown(Key:Word):Boolean;
  begin
    Result:=GetKeyState(Key)<0;
  end;
const
  CSpeed:Real=4;
begin
  if IsXBoxActiv then
  begin
    if IsDown(VK_UP) then FCP:=VectorAdd(FCP,MakeVector(0,-CSpeed/Zoom));
    if IsDown(VK_DOWN) then FCP:=VectorAdd(FCP,MakeVector(0,+CSpeed/Zoom));
    if IsDown(VK_LEFT) then FCP:=VectorAdd(FCP,MakeVector(-CSpeed/Zoom,0));
    if IsDown(VK_RIGHT) then FCP:=VectorAdd(FCP,MakeVector(+CSpeed/Zoom,0));
    if IsDown(VK_SUBTRACT) then ZoomOut;
    if IsDown(VK_ADD) then ZoomIn;
    if MouseCap then DoMouse;
  end;
  Ang:=Ang+1; eX.Render;
  UpLabel;
end;

procedure TeXForm.UpLabel;
begin
  if Zoom<1 then
    lbZoom.Caption:='Zoom [1 : '+FtStr(1/Zoom,0)+']' else
    lbZoom.Caption:='Zoom ['+FtStr(Zoom,0)+' : 1]';
  lbPosition.Caption:='Position [X:'+FtStr(FCP.X,2)+' | '+FtStr(FCP.Y,2)+']';
  lbMPos.Caption:='Mouse Position [X:'+FtStr(FMP.X,2)+' | '+FtStr(FMP.Y,2)+']';
  lbNumMesh.Caption:='Number Mesh['+IntToStr(FMeshList.IndexOf(FEdit))+']';
end;

procedure TeXForm.FormKeyDown(Sender:TObject; var Key:Word;
  Shift:TShiftState);
begin
  if Key=VK_ESCAPE then Close;
  if Key=VK_MULTIPLY then Zoom:=1;
end;

procedure TeXForm.Clear;
var
  I:Integer;
begin
  for I:=0 to FMeshList.Count-1 do TMesh(FMeshList[I]).Free;
  FMeshList.Clear;
end;

function TeXForm.BoxToMap(P:TVector):TVector;
begin
  Result:=VectorAdd(FCP,VectorDiv(VectorSub(P,MakeVector(wnd.Width/2,wnd.Height/2)),Zoom));
end;

function TeXForm.MapToBox(P:TVector):TVector;
begin
  //Result:=VectorMul(P,Zoom);
end;

procedure TeXForm.DrawGrid;
  function Dis(V,D:Real):Real;
  begin
    if D=0 then Exit;
    Result:=Round(V/D)*D;
  end;
const
  CGS:Integer=10;
var
  I:Integer;
  A,B:TVector;
  W,H,Col,C:Real;
  GS:Real;
begin
  W:=XBox.Width; H:=XBox.Height;
  GS:=Power(CGS,Trunc(LogN(CGS,W/Zoom)-1));
  C:=W/Zoom/GS;
  Col:=0.2;
  glColor3d(Col,Col,Col);
  for I:=0 to Round(C) do
  begin
    A:=MakeVector(I*GS+Dis(FCP.X-W/2/Zoom,GS),FCP.Y-H/2/Zoom);
    B:=MakeVector(I*GS+Dis(FCP.X-W/2/Zoom,GS),FCP.Y+H/2/Zoom);
    DrawLine(A,B);
  end;
  C:=H/Zoom/GS;
  for I:=0 to Round(C) do
  begin
    A:=MakeVector(FCP.X-W/2/Zoom,I*GS+Dis(FCP.Y-H/2/Zoom,GS));
    B:=MakeVector(FCP.X+W/2/Zoom,I*GS+Dis(FCP.Y-H/2/Zoom,GS));
    DrawLine(A,B);
  end;
  GS:=Power(CGS,Trunc(LogN(CGS,W/Zoom)));
  C:=W/Zoom/GS;
  glColor3d(0.5,0.5,0.5);
  for I:=0 to Round(C) do
  begin
    A:=MakeVector(I*GS+Dis(FCP.X-W/2/Zoom,GS),FCP.Y-H/2/Zoom);
    B:=MakeVector(I*GS+Dis(FCP.X-W/2/Zoom,GS),FCP.Y+H/2/Zoom);
    DrawLine(A,B);
  end;
  C:=H/Zoom/GS;
  for I:=0 to Round(C) do
  begin
    A:=MakeVector(FCP.X-W/2/Zoom,I*GS+Dis(FCP.Y-H/2/Zoom,GS));
    B:=MakeVector(FCP.X+W/2/Zoom,I*GS+Dis(FCP.Y-H/2/Zoom,GS));
    DrawLine(A,B);
  end;
end;

procedure TeXForm.ZoomIn;
begin
  if Zoom<1E1 then Zoom:=Zoom*100/99; // else Zoom:=10E3;
end;

procedure TeXForm.ZoomOut;
begin
  if Zoom>1E-2 then Zoom:=Zoom*99/100; // else Zoom:=10E-3;
end;

procedure TeXForm.XBoxMouseUp(Sender:TObject; Button:TMouseButton;
  Shift:TShiftState; X,Y:Integer);
begin
  if Button=mbMiddle then
  begin
    XBox.Cursor:=crCross;
  end;
end;

procedure TeXForm.XBoxMouseDown(Sender:TObject; Button:TMouseButton;
  Shift:TShiftState; X,Y:Integer);
begin
  if Button=mbLeft then
  begin
    if not Selected then
    begin
      FSelect:=TMesh.Create; FMeshList.Add(FSelect);
      FSelect.AddVertex(MPos);
    end;
    FSelect.AddVertex(MPos);
  end;
  if Button=mbRight then
  begin
    if FSelect<>nil then
    begin
      FSelect.Delete(FSelect.Count-1);
      if FSelect.Count<3 then
      begin
        FMeshList.Extract(FSelect); FSelect.Free;
      end else FSelect.Slice;
    end else PopupMenu.Popup(X,Y);
    FSelect:=nil;
  end;
  if (Button=mbMiddle)and(FSelect=FEdit) then
  begin
    XBox.Cursor:=crSizeAll; FMP:=MPos;
  end;
end; {Just One Primitive Action(J.O.P.A)}

function PointInRect(P:TPoint; R:TRect):Boolean;
begin
  Result:=(R.Left<P.X)and(R.Top<P.Y)and(R.Right>P.X)and(R.Bottom>P.Y);
end;

function TeXForm.GetIsXBoxActiv:Boolean;
var
  I:Integer;
  P:TPoint;
  C:TControl;
begin
  Result:=False;
  if PopupMenu.OwnerDraw then Exit;
  P:=Mouse.CursorPos;
  if not PointInRect(XBox.ScreenToClient(P),XBox.ClientRect) then Exit;
  Result:=True; FocusControl(XBox);
end;

procedure TeXForm.BoxTexEnter(Sender:TObject);
var
  SR:TSearchRec;
begin
  if FindFirst(AppPath+TexDir+'*.*',faArchive,SR)=0 then
    repeat
      BoxTex.Items.Add(SR.Name);
    until FindNext(SR)<>0;
  BoxTex.ItemIndex:=BoxTex.Items.Count-1;
end;

function TeXForm.GetSelected:Boolean;
begin
  Result:=FSelect<>nil;
end;

procedure TeXForm.DrawSelect;
var
  I,J:Integer;
  M:TMesh;
begin
  M:=FSelect; if M=nil then Exit;
  glColor3d(0,1,0);
  for I:=1 to M.Count-2 do Rib(M[I-1],M[I]);
  glColor3d(0,0.5,1); Rib(M[M.Count-2],M[M.Count-1]);
  glColor3d(1,1,1);
  for I:=0 to M.Count-1 do DrawPoint(M[I]);
end;

procedure TeXForm.DrawEdit;
var
  I,J:Integer;
  M:TMesh;
begin
  M:=FEdit; if M=nil then Exit;
  glColor3d(1,0.5,0);
  for I:=1 to M.Count-1 do Rib(M[I-1],M[I]); Rib(M[M.Count-1],M[0]);
  glColor3d(1,1,1);
  for I:=0 to M.Count-1 do DrawPoint(M[I]);
end;

procedure TeXForm.DrawSF;
var
  Size:Real;
begin
  Size:=10/Zoom;
  glColor3d(1,1,0);
  DrawQuads(FStart.X,FStart.Y,Size,Size,45);
  glColor3d(0,1,1);
  DrawQuads(FFinish.X,FFinish.Y,Size,Size,45);
end;

procedure TeXForm.DrawMeshList;
var
  I,J:Integer;
  M:TMesh;
begin
  for J:=0 to FMeshList.Count-1 do
  begin
    M:=TMesh(FMeshList[J]);
    if (M=FSelect)or(M=FEdit) then Continue;
    glColor3d(0,1,0);
    for I:=1 to M.Count-1 do Rib(M[I-1],M[I]); Rib(M[M.Count-1],M[0]);
    glColor3d(1,1,1);
    for I:=0 to M.Count-1 do DrawPoint(M[I]);
  end;
  DrawEdit; DrawSelect; DrawSF;
end;

function TeXForm.GetMPos:TVector;
begin
  Result:=BoxToMap(PointToVector(XBox.ScreenToClient(Mouse.CursorPos)));
end;

function TeXForm.GetMesh(Pos:TVector):TMesh;
var
  I:Integer;
begin
  for I:=0 to FMeshList.Count-1 do
    if CollisionMesh(TMesh(FMeshList[I]),Pos) then
    begin
      Result:=TMesh(FMeshList[I]); Exit;
    end; Result:=nil;
end;

procedure TeXForm.DoMouse;
begin
  if (FSelect<>nil){and(FSelect.Count>1)} then
  begin
    FSelect.Last:=MPos;
  end else
  begin
    FEdit:=GetMesh(MPos);
  end;
  if XBox.Cursor=crSizeAll then
  begin
    FCP:=VectorAdd(FCP,VectorSub(FMP,MPos));
  end else FMP:=MPos;
end;

procedure TeXForm.PopupMenuPopup(Sender:TObject);
begin
  FMouseCap:=False;
  NTex.Enabled:=FEdit<>nil;
  NInvNormal.Enabled:=FEdit<>nil;
  NDel.Enabled:=FEdit<>nil;
end;

procedure TeXForm.NStartClick(Sender:TObject);
begin
  FStart:=BoxToMap(PointToVector(PopupMenu.PopupPoint));
end;

procedure TeXForm.NFinishClick(Sender:TObject);
begin
  FFinish:=BoxToMap(PointToVector(PopupMenu.PopupPoint));
end;

procedure TeXForm.NInvNormalClick(Sender:TObject);
begin
  FEdit.InvNormal;
end;

procedure TeXForm.NTexClick(Sender:TObject);
begin
  FEdit.Texture:=BoxTex.Text;
end;

procedure TeXForm.NDelClick(Sender:TObject);
begin
  FMeshList.Extract(FEdit); FEdit.Free; FEdit:=nil;
end;

procedure TeXForm.sbOpenClick(Sender:TObject);
begin
  if not od.Execute then Exit; LoadFromFile(od.FileName);
end;

procedure TeXForm.sbSaveClick(Sender:TObject);
begin
  if not sd.Execute then Exit; SaveToFile(sd.FileName);
end;

procedure TeXForm.sbClearClick(Sender:TObject);
begin
  Clear;
end;

procedure TeXForm.NBringFClick(Sender:TObject);
begin
  FMeshList.Extract(FEdit); FMeshList.Add(FEdit);
end;

procedure TeXForm.NBringBClick(Sender:TObject);
begin
  FMeshList.Extract(FEdit); FMeshList.Insert(0,FEdit);
end;

procedure TeXForm.fdShow(Sender: TObject);
begin
  FMouseCap:=False;
end;

procedure TeXForm.fdClose(Sender: TObject);
begin
  FMouseCap:=True;
end;

function TeXForm.GetMouseCap: Boolean;
begin
  Result:=FMouseCap and (Screen.ActiveForm=Self);
end;

procedure TeXForm.FormMouseWheel(Sender: TObject; Shift: TShiftState;
  WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
function Sign(const AValue: Integer): Integer;
begin
  Result := 0;
  if AValue < 0 then  Result := -1
  else if AValue > 0 then Result := 1;
end;
begin
  if PointInRect(XBox.ScreenToClient(ClientToScreen(MousePos)),XBox.ClientRect) then
  begin
    WheelDelta:=Sign(WheelDelta)*5;
    while WheelDelta<>0 do
    begin
      if WheelDelta>0 then ZoomIn else ZoomOut;
      WheelDelta:=Sign(WheelDelta)*(Abs(WheelDelta)-1);
    end;
  end;
end;

end.

