@del Release\Sgon.exe
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
@set "solution=Sgon.sln"
MSBuild.exe %solution% /p:configuration=Debug
pause