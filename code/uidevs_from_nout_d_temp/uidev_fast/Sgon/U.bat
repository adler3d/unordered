@echo off
@echo %TIME%
@cl /c /Z7 /nologo /W1 /WX- /MP /Od /Oy- /D WIN32 /D _DEBUG /D _WINDOWS /GF- /Gm- /EHsc /RTC1 /MTd /GS /Gy- /fp:precise /Zc:wchar_t /Zc:forScope /Fo"Debug\\" /Fd"Debug\vc120.pdb" /Gd /TP /analyze- /errorReport:queue /bigobj /Zm190 %1
@echo %TIME%