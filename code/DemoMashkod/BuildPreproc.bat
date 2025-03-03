@echo off
rem ������ �����
@cls
rem ������ ������� �����
@cd "Demo\"
rem ��������� ��������� ���������� ��������� MSVC
@call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\vcvars32.bat"
rem ��������� ���������� ��������� ������ ����������
@set "INCLUDE=%INCLUDE%;"
@set "BuildFile=main.cpp"
@set "ScanFile=main.i"
@set "MacroGen=..\Macro\Gen.exe"
rem ������� ������ ���� �����������
@del %ScanFile%
rem ��������� ���������� � ������ �������������
@call "cl.exe" %BuildFile% /Od /TP /EP /P /C /c /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "DEF_BUILD_MICRO"
@if errorlevel 2 goto fail
rem ������� ���������� ������ ��� ������ �������
@del /q "..\Macro\*.*"
@rmdir "..\Macro"
@mkdir "..\Macro"
rem ��������� ��� ������
@copy "%MACRO_GEN%" %MacroGen%
@call %MacroGen% %ScanFile%
rem �������� =)
pause
cd ..\Macro
copy ..\ArtStyle.bat ArtStyle.bat
call ArtStyle.bat *.h
@call %MacroGen% main.h +all +nc +cf
pause
cd ..
:fail
exit /b 2