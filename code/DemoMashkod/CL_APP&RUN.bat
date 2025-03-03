@cd Release
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@cd "..\321\V2\Release\"
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
"Sgon(Debug).exe" HIDE
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@copy qapcppout.asm ..\..\..\Demo\asmogovno.inl
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@cd ..\..\..\
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@call CL_ASM_APP.bat
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
ASM_APP.bat
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
exit /b 0
:fail
:end
pause
exit /b 2