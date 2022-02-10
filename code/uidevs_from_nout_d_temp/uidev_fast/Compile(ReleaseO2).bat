@del Release\Sgon(O2).exe
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
@set "solution=Sgon.sln"
MSBuild.exe %solution% /p:configuration=ReleaseO2
pause
copy ReleaseO2\Sgon.exe Release\Sgon(O2).exe
cd Release