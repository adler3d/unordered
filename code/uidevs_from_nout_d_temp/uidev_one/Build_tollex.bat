@echo off
rem ������ �����
@cls
rem ������ ������� �����
@cd Sgon\"
rem ������� ������ ���� �����������
@del "trollex.i"
rem ��������� ��������� ���������� ��������� MSVC
@call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\vcvars32.bat"
rem ��������� ���������� ��������� ������ ����������
@set "INCLUDE=%INCLUDE%;"
@set "BuildFile=trollex.cpp"
@set "ScanFile=trollex.i"
@set "MacroGen=..\Macro\Gen.exe"
rem ��������� ���������� � ������ �������������
@call "cl.exe" %BuildFile% /Od /TP /EP /P /C /c /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "DEF_BUILD_MICRO"
rem ������� ���������� ������ ��� ������ �������
@del /q "..\Macro\*.*"
@rmdir "..\Macro"
@mkdir "..\Macro"
rem ��������� ��� ������
@copy "%MACRO_GEN%" %MacroGen% 
@call %MacroGen% %ScanFile% -ln +nc
rem �������� =)
pause
cd ..\Macro
copy ..\ArtStyle.bat ArtStyle.bat
call ArtStyle.bat *.h
pause