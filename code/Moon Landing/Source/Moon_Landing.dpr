program Moon_Landing;
uses
  GameApp in 'GameApp.pas',
  GameMenu in 'GameMenu.pas',
  GameSystem in 'GameSystem.pas',
  LogoScene in 'LogoScene.pas',
  GameRes in 'GameRes.pas',
  ASDClock in 'ASDClock.pas',
  InfoScene in 'InfoScene.pas',
  ASDStream in 'ASDStream.pas';

begin
  Randomize; App:=TApp.Create; App.Init; App.Run; App.ShutDown;
end.

