@del Release\Demo.exe
rem call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\vsvars32.bat"
rem call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars32.bat"
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars64.bat"
@set "solution=Demo.sln"
MSBuild.exe %solution% /p:configuration=Release /p:Platform=Win32
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
cd Release
Demo.exe
goto end
pause
:fail
pause
:end
@exit /b 2