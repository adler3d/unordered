@del Release\Sgon(WithAsserts).exe
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
@set "solution=Sgon.sln"
MSBuild.exe %solution% /p:configuration=ReleaseWithAsserts
pause
copy ReleaseWithAsserts\Sgon.exe Release\SgonWithAsserts.exe
cd Release