@cd Release
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@cd "..\321\V2\Release\"
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@if exist qapcppout.asm del qapcppout.asm
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
"Sgon(Debug).exe" HIDE
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@copy /Y qapcppout.asm ..\..\AsmCppLike2Mashkod\Release\asm2mashkod2016.h
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@cd "..\..\AsmCppLike2Mashkod\Release\"
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@if exist mashkod.asm del mashkod.asm 
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
"Sgon(Debug).exe" HIDE
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@copy /Y mashkod.asm ..\..\..\Release\mashkod.txt
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@cd "..\..\..\"
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