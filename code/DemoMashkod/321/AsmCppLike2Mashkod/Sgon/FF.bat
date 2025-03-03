@call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
@cd ..
@echo %TIME%
@del /q debug\*.*
@echo %TIME%
@set "solution=Sgon.sln"
MSBuild.exe %solution% /p:configuration=Debug /nologo
@cd Sgon
@echo %TIME%