@echo off

IF (%1)==() GOTO error
dir /b /ad %1 >nul 2>nul && GOTO indentDir
IF NOT EXIST %1 GOTO error
goto indentFile

:indentDir
set searchdir=%1

IF (%2)==() GOTO assignDefaultSuffix
set filesuffix=%2

GOTO run

:assignDefaultSuffix
::echo !!!!DEFAULT SUFFIX!!!
set filesuffix=*

:run
FOR /F "tokens=*" %%G IN ('DIR /B /S %searchdir%\*.%filesuffix%') DO (
echo Indenting file "%%G"
"D:/Adler/My Doc/Programs/UniversalIndentGUI_win32/indenters/astyle.exe" "%%G" --options="D:/Adler/My Doc/Programs/UniversalIndentGUI_win32/indenters/.astylerc"

)
GOTO ende

:indentFile
echo Indenting one file %1
"D:/Adler/My Doc/Programs/UniversalIndentGUI_win32/indenters/astyle.exe" "%1" --options="D:/Adler/My Doc/Programs/UniversalIndentGUI_win32/indenters/.astylerc"


GOTO ende

:error
echo .
echo ERROR: As parameter given directory or file does not exist!
echo Syntax is: 1.bat dirname filesuffix
echo Syntax is: 1.bat filename
echo Example: 1.bat temp cpp
echo .

:ende
