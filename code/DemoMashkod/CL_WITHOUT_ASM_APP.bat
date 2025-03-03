@echo CL_WITHOUT_ASM_APP
@call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\vsvars32.bat"
@if errorlevel 1 goto fail
@cd Release
@if errorlevel 1 goto fail
@cl /c /Zi /nologo /W1 /WX- /O2 /Oy- /GL /D QAP_DEBUG /D CL_WITHOUT_ASM_APP /D WIN32 /D NDEBUG /D _WINDOWS /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope /Gd /TP /analyze- /errorReport:queue ..\Demo\main.cpp
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@link /nologo /LTCG /SUBSYSTEM:WINDOWS main.obj
@echo errorlevel = %errorlevel%
@if errorlevel 1 goto fail
@echo done
@move main.exe ASM_APP.exe
@if errorlevel 1 goto fail
@del vc100.idb
@del vc100.pdb
@del main.obj
@del main.pdb
exit /b 0
:fail
:end
pause
exit /b 2