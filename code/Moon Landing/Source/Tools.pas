unit Tools;
interface
uses
  Windows,eXgine,OpenGL;
type
  TScreenMode=record
    X,Y,BPP,Freg:Integer;
  end;
  TTime=record
    wHour:Word;
    wMinute:Word;
    wSecond:Word;
    wMilliseconds:Word;
  end;
  TDate=record
    wYear:Word;
    wMonth:Word;
    wDay:Word;
  end;

function FloatToStr(Value:Extended; Width:Integer=-1; Decimal:Integer=0):string;
function TimeToStr(Time:TTime):string;
function DateToStr(Date:TDate):string;
function GetTime:TTime;
function GetDate:TDate;
function DirExists(const DirName:string):Boolean;
function FileExists(const FileName:string):Boolean;
function UserName:string;
function CursorPos:TPoint;
function GetScreenMode:TScreenMode;
function IntPower(const Base:Extended; const Exponent:Integer):Extended;

var
  DateSeparator:Char='.';
  TimeSeparator:Char=':';
implementation

function FloatToStr(Value:Extended; Width,Decimal:Integer):string;
begin
  Str(Value:Width:Decimal,Result);
end;

function TimeToStr(Time:TTime):string;
var
  TS:Char absolute TimeSeparator;
begin
  Result:=
    IntToStr(Time.wHour)+TS+
    IntToStr(Time.wMinute)+TS+
    IntToStr(Time.wSecond)+TS+
    IntToStr(Time.wMilliseconds);
end;

function DateToStr(Date:TDate):string;
var
  DS:Char absolute DateSeparator;
begin
  Result:=
    IntToStr(Date.wDay)+DS+
    IntToStr(Date.wMonth)+DS+
    IntToStr(Date.wYear);
end;

function GetTime:TTime;
var
  ST:TSystemTime;
begin
  GetLocalTime(ST);
  with Result do
  begin
    wHour:=ST.wHour; wMinute:=ST.wMinute;
    wSecond:=ST.wSecond; wMilliseconds:=ST.wMilliseconds;
  end;
end;

function GetDate:TDate;
var
  ST:TSystemTime;
begin
  GetLocalTime(ST);
  with Result do
  begin
    wYear:=ST.wYear; wMonth:=ST.wMonth; wDay:=ST.wDay;
  end;
end;

function DirExists(const DirName:string):Boolean;
var
  Code:Integer;
begin
  Code:=GetFileAttributes(PChar(DirName));
  Result:=(Code<>-1)and(FILE_ATTRIBUTE_DIRECTORY and Code<>0);
end;

function FileExists(const FileName:string):Boolean;
var
  //Code:Integer;
  F:TextFile;
begin
  //Code:=GetFileAttributes(PChar(FileName));
  //Result:=(Code<>-1)and(FILE_ATTRIBUTE_NORMAL and Code<>0);
  AssignFile(F,FileName); {$I-}Reset(F); {$I+}Result:=IOResult=0;
  if Result then CloseFile(F);
end;

function UserName:string;
var
  P:array[1..255] of Char;
  T:Cardinal;
begin
  FillChar(P,SizeOf(P),0); T:=SizeOf(P);
  GetUserName(@P,T); Result:=P;
end;

function Point(AX,AY:Integer):TPoint;
begin
  Result.X:=AX; Result.Y:=AY;
end;

function CursorPos:TPoint;
begin
  GetCursorPos(Result);
end;

function GetScreenMode:TScreenMode;
var
  DC:HDC;
begin
  DC:=GetDC(Wnd.Handle);
  Result.X:=GetDeviceCaps(DC,HORZRES); Result.Y:=GetDeviceCaps(DC,VERTRES);
  Result.BPP:=GetDeviceCaps(DC,BITSPIXEL);
  Result.Freg:=GetDeviceCaps(DC,VREFRESH);
end;

function IntPower(const Base:Extended; const Exponent:Integer):Extended;
asm
        mov     ecx, eax
        cdq
        fld1                      { Result := 1 }
        xor     eax, edx
        sub     eax, edx          { eax := Abs(Exponent) }
        jz      @@3
        fld     Base
        jmp     @@2
@@1:    fmul    ST, ST            { X := Base * Base }
@@2:    shr     eax,1
        jnc     @@1
        fmul    ST(1),ST          { Result := Result * X }
        jnz     @@1
        fstp    st                { pop X from FPU stack }
        cmp     ecx, 0
        jge     @@3
        fld1
        fdivrp                    { Result := 1 / Result }
@@3:
        fwait
end;

end.

