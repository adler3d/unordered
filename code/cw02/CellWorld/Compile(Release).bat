@call "set_env.bat"
@set "solution=CellWorld.sln"
MSBuild.exe %solution% /p:configuration=Release  /p:Platform=Win32
pause