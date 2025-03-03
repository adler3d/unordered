@echo CL_ASM_APP
@call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\vsvars32.bat"
@if errorlevel 1 goto fail
@if not exist Debug mkdir Debug
@cd Debug
@if errorlevel 1 goto fail
@cl /Gm- /ZI /nologo /W1 /WX- /Od /Oy- /D CL_ASM_APP /D WIN32 /D _DEBUG /D _WINDOWS /EHsc /RTC1 /MTd /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd /TP /analyze- /errorReport:queue ..\Demo\main.cpp
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@link /nologo /SUBSYSTEM:WINDOWS main.obj
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
rem @del mashkod.txt
@echo running...
@main.exe
@if errorlevel 1 goto fail
@echo done
@copy /Y mashkod.txt ..\Release
@del asm.txt.inl
@del asm_app.txt.inl
@del vc100.idb
@del vc100.pdb
@del main.obj
@del main.pdb
cd ..
exit /b 0
:fail
:end
pause
exit /b 2