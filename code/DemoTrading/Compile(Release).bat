@del Release\Demo.exe
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\vsvars32.bat"
@set "solution=Demo.sln"
MSBuild.exe %solution% /p:configuration=Release
pause
cd Release
Demo.exe
pause