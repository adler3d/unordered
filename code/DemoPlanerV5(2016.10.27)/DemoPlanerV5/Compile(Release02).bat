@del Release\Demo.exe
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\vsvars32.bat"
@set "solution=Demo.sln"
MSBuild.exe %solution% /p:configuration=ReleaseO2
pause
cd Release
Demo.exe
pause