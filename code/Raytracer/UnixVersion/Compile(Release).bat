@del Release\Demo.exe
rem call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\vsvars32.bat"
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86_amd64
@set "solution=Demo.sln"
MSBuild.exe %solution% /p:configuration=Release
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
cd Release
copy ..\x64\Release\Demo.exe Demo.exe
rmdir /s/q ..\x64
Demo.exe
goto end
pause
:fail
pause
:end
@exit /b 2