@echo off
rem Чистим экран
@cls
rem Меняем рабочую папку
@cd Sgon\"
rem Удаляем старый файл препроцесса
@del "main.i"
rem Запускаем настройку переменных окружения MSVC
@call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\vcvars32.bat"
rem Дополняем переменных окружения своими катологами
@set "INCLUDE=%INCLUDE%;"
@set "BuildFile=main_2013_12_20.cpp"
@set "ScanFile=main_2013_12_20.i"
@set "MacroGen=..\Macro\Gen.exe"
rem Запускаем компилятор в режиме препроцессора
@call "cl.exe" %BuildFile% /Od /TP /EP /P /C /c /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "DEF_BUILD_MICRO"
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
pause