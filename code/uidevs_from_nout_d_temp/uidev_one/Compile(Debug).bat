@set conf=Debug
@goto :start
:start
@set /a f=0
@for %%i in (*.sln) do @(
  @set solution=%%i
  @set /a f=f+1
)
@if not %f%==1 goto :unambiguous
@echo %solution%
@goto :menu_1
@goto :eof
:unambiguous
@echo %f% solutions founds:
@for %%? in (*.sln) do @(@echo   %%?)
@echo.
@echo menu:
@echo 1)continue with %solution%
@echo 2)exit
@echo.
@set /p id="enter id: "
@if %id%==1 goto :menu_1
@if %id%==2 goto :eof
echo no way.
@goto :eof
:menu_1
@for /f %%i IN ("%solution%") DO @(@set exe_name=%%~ni.exe)
@del Debug\%exe_name%
@call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
@MSBuild.exe %solution% /p:configuration=%conf%
@pause
rem @cd %conf%
rem @call %exe_name%
rem @cd ..
@goto :eof
:eof
@echo Done.
@exit /B