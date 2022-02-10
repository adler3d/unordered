program Lektor;
uses
  Forms,
  OneForm in 'OneForm.pas' {eXForm},
  GameRender in 'GameRender.pas',
  MeshUnit in 'MeshUnit.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TeXForm, eXForm);
  Application.Run;
end.
