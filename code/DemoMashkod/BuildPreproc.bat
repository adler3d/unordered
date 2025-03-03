@echo off
rem Чистим экран
@cls
rem Меняем рабочую папку
@cd "Demo\"
rem Запускаем настройку переменных окружения MSVC
@call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\vcvars32.bat"
rem Дополняем переменных окружения своими катологами
@set "INCLUDE=%INCLUDE%;"
@set "BuildFile=main.cpp"
@set "ScanFile=main.i"
@set "MacroGen=..\Macro\Gen.exe"
rem Удаляем старый файл препроцесса
@del %ScanFile%
rem Запускаем компилятор в режиме препроцессора
@call "cl.exe" %BuildFile% /Od /TP /EP /P /C /c /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "DEF_BUILD_MICRO"
@if errorlevel 2 goto fail
rem Создаем дирикторию вывода для нашего парсера
@del /q "..\Macro\*.*"
@rmdir "..\Macro"
@mkdir "..\Macro"
rem Запускаем наш парсер
@copy "%MACRO_GEN%" %MacroGen%
@call %MacroGen% %ScanFile%
rem радуемся =)
pause
cd ..\Macro
copy ..\ArtStyle.bat ArtStyle.bat
call ArtStyle.bat *.h
@call %MacroGen% main.h +all +nc +cf
pause
cd ..
:fail
exit /b 2