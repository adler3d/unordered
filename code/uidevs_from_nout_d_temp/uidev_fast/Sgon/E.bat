call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
echo %TIME%
cl /c /Z7 /nologo /W1 /WX- /MP /Od /Oy- /D WIN32 /D _DEBUG /D _WINDOWS /GF- /Gm- /EHsc /RTC1 /MTd /GS /Gy- /fp:precise /Zc:wchar_t /Zc:forScope /Fo"Debug\\" /Fd"Debug\vc120.pdb" /Gd /TP /analyze- /errorReport:queue /bigobj /Zm190 branch_lex_v3.cpp
echo %TIME%
pause
echo %TIME%
cl /c /Z7 /nologo /W1 /WX- /MP /Od /Oy- /D WIN32 /D _DEBUG /D _WINDOWS /GF- /Gm- /EHsc /RTC1 /MTd /GS /Gy- /fp:precise /Zc:wchar_t /Zc:forScope /Fo"Debug\\" /Fd"Debug\vc120.pdb" /Gd /TP /analyze- /errorReport:queue /bigobj /Zm190 t_components.cpp
echo %TIME%
cl /c /Z7 /nologo /W1 /WX- /MP /Od /Oy- /D WIN32 /D _DEBUG /D _WINDOWS /GF- /Gm- /EHsc /RTC1 /MTd /GS /Gy- /fp:precise /Zc:wchar_t /Zc:forScope /Fo"Debug\\" /Fd"Debug\vc120.pdb" /Gd /TP /analyze- /errorReport:queue /bigobj /Zm190 gabob.cpp
echo %TIME%