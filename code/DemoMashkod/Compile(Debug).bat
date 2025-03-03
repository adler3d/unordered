call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\vsvars32.bat"
@set "solution=Demo.sln"
MSBuild.exe %solution% /p:configuration=Debug
@echo errorlevel = %errorlevel%
pause
@if errorlevel 1 goto fail
cd Release
..\Debug\Demo.exe
goto end
pause
:fail
:end
exit /b 2