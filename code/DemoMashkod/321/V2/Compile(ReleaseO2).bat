if exist "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\vsvars32.bat" (
  call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\vsvars32.bat"
) else (
  call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\VsDevCmd.bat"
)
@set "solution=Sgon.sln"
MSBuild.exe %solution% /p:configuration=ReleaseO2
pause
copy ReleaseO2\Sgon.exe Release\Sgon(O2).exe
cd Release