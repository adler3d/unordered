@del Release\Sgon.exe
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\vsvars32.bat"
@set "solution=Sgon.sln"
MSBuild.exe %solution% /p:configuration=Release
pause
cd Release
Sgon.exe
pause