@echo off
@echo %TIME%
@cl /c /Z7 /nologo /W1 /WX- /MP /O2 /Oy- /D WIN32 /D _WINDOWS /GF- /Gm- /EHsc /MT /GS /Gy- /fp:precise /Zc:wchar_t /Zc:forScope /Fo"Debug\\" /Fd"Debug\vc120.pdb" /Gd /TP /analyze- /errorReport:queue /bigobj /Zm190 %1
@echo %TIME%