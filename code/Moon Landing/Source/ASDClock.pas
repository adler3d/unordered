unit ASDClock;

interface
Uses
  Windows,eXgine;
Type
  TClock = class(TObject)
  private
    FActiv: Boolean;
    FEndTime: Int64;
    FStartTime: Int64;
    FFreq: Int64;
  public
    function Time: Real;
    function Sec: Real;
    function Tick: Int64;
    function Activ: Boolean;
    function Freq: Int64;
  public
    constructor Create;
    procedure Start; virtual;
    procedure Stop; virtual;
  end;

  TCalcNPS = class(TClock)
  private
    FCountTick: Integer;
    FWaitTime: Integer;
    FLastCount: Integer;
    FLastTime: Real;
    FAllTick: Integer;
    FAllTime: Real;
    function GetWaitTime: Integer;
    procedure SetWaitTime(WaitTime: Integer = 500);
  public
    constructor Create(WaitTime: Integer = 500);
    function NPS: Real;
    function MeanNPS: Real;
    function AllDateTime: TDateTime;
    function CountTick: Integer;
    function AllTick: Integer;
    function AllTime: Real;
    procedure Reset;
    procedure Next;
    property WaitTime: Integer read GetWaitTime write SetWaitTime;
  end;

implementation

{ TTimer }

function TClock.Activ: Boolean;
begin
  Result := FActiv;
end;

constructor TClock.Create;
begin
  FActiv := False;
  QueryPerformanceFrequency(FFreq);
end;

function TClock.Freq: Int64;
begin
  Result := FFreq;
end;

function TClock.Sec: Real;
begin
  if FActiv then
    QueryPerformanceCounter(FEndTime);
  Result := (FEndTime - FStartTime) / Freq;
end;

function TClock.Tick: Int64;
begin
  if FActiv then
    QueryPerformanceCounter(FEndTime);
  Result := (FEndTime - FStartTime);
end;

function TClock.Time: Real;
begin
  if FActiv then
    QueryPerformanceCounter(FEndTime);
  Result := (FEndTime - FStartTime) * 1000 / Freq;
end;

procedure TClock.Start;
begin
  FActiv := True;
  QueryPerformanceCounter(FStartTime);
end;

procedure TClock.Stop;
begin
  FActiv := False;
  QueryPerformanceCounter(FEndTime);
end;

{ TCalcFPS }

function TCalcNPS.AllDateTime: TDateTime;
const
  mSecInDay: Real = 24 * 60 * 60 * 1000;
begin
  Result := FAllTime / mSecInDay;
end;

function TCalcNPS.AllTick: Integer;
begin
  Result := FAllTick;
end;

function TCalcNPS.AllTime: Real;
begin
  Result := FAllTime;
end;

function TCalcNPS.CountTick: Integer;
begin
  Result := FCountTick;
end;

constructor TCalcNPS.Create(WaitTime: Integer);
begin
  inherited Create;
  FWaitTime := WaitTime;
  FAllTick := 0;
  FAllTime := 0;
end;

function TCalcNPS.NPS: Real;
begin
  if FLastCount = 0 then
  begin
    if FCountTick > 0 then
    begin
      Result := (FCountTick * 1000) / Self.Time;
      Exit;
    end;
    if not Activ then
      Reset;
    Result := 0;
    Exit;
  end;
  Result := (FLastCount * 1000) / FLastTime;
end;

function TCalcNPS.MeanNPS: Real;
begin
  if FAllTime = 0 then
  begin
    Result := 0;
    Exit;
  end;
  Result := (FAllTick * 1000) / FAllTime;
end;

procedure TCalcNPS.Next;
begin
  Inc(FCountTick);
  Inc(FAllTick);
  if (Self.Time > FWaitTime) or not Activ then
    Reset;
end;

procedure TCalcNPS.Reset;
begin
  if FActiv then
    Stop;
  FLastTime := Time;
  FAllTime := FAllTime + FLastTime;
  FLastCount := FCountTick;
  FCountTick := 0;
  Start;
end;

procedure TCalcNPS.SetWaitTime(WaitTime: Integer);
begin
  FWaitTime := WaitTime;
  Reset;
end;

function TCalcNPS.GetWaitTime: Integer;
begin
  Result := FWaitTime;
end;

end.
