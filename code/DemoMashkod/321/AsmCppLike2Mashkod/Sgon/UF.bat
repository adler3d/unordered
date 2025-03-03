@echo %TIME%
@call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
@echo %TIME%
@echo begin
@call U %1
@echo end
@cd ..
@echo %TIME%
del /q debug\*.*
@echo %TIME%
@set "solution=Sgon.sln"
MSBuild.exe %solution% /p:configuration=Debug /nologo
@cd Sgon
@echo %TIME%