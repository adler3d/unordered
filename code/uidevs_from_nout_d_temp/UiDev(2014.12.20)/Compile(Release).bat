@del Release\Sgon.exe
rem call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars64.bat"
@set "solution=Sgon.sln"
MSBuild.exe %solution% /p:configuration=Release /p:platform=Win32
pause
cd Release
Sgon.exe
pause