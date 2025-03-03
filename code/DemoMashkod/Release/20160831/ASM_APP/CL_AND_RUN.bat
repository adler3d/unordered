@if exist qapcppout.asm del qapcppout.asm
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
"V2.exe" HIDE
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@copy /Y qapcppout.asm asm2mashkod2016.h
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@if exist mashkod.asm del mashkod.asm 
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
"Asm2Mashkod.exe" HIDE
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@copy /Y mashkod.asm mashkod.txt
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
ASM_APP.exe
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
exit /b 0
:fail
:end
pause
exit /b 2