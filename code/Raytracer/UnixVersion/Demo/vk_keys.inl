/*#define VK_LBUTTON  1
#define VK_RBUTTON  2
#define VK_CANCEL 3
#define VK_MBUTTON  4

#define VK_XBUTTON1 5
#define VK_XBUTTON2 6

#define VK_BACK 8
#define VK_TAB  9
#define VK_CLEAR  12
#define VK_RETURN 13
#define VK_SHIFT  16
#define VK_CONTROL  17
#define VK_MENU 18
#define VK_PAUSE  19
#define VK_CAPITAL  20
#define VK_KANA 0x15
#define VK_HANGEUL  0x15
#define VK_HANGUL 0x15
#define VK_JUNJA  0x17
#define VK_FINAL  0x18
#define VK_HANJA  0x19
#define VK_KANJI  0x19
#define VK_ESCAPE 0x1B
#define VK_CONVERT  0x1C
#define VK_NONCONVERT 0x1D
#define VK_ACCEPT 0x1E
#define VK_MODECHANGE 0x1F
#define VK_SPACE  32
#define VK_PRIOR  33
#define VK_NEXT 34
#define VK_END  35
#define VK_HOME 36
#define VK_LEFT 37
#define VK_UP 38
#define VK_RIGHT  39
#define VK_DOWN 40
#define VK_SELECT 41
#define VK_PRINT  42
#define VK_EXECUTE  43
#define VK_SNAPSHOT 44
#define VK_INSERT 45
#define VK_DELETE 46
#define VK_HELP 47
#define VK_LWIN 0x5B
#define VK_RWIN 0x5C
#define VK_APPS 0x5D
#define VK_SLEEP  0x5F
#define VK_NUMPAD0  0x60
#define VK_NUMPAD1  0x61
#define VK_NUMPAD2  0x62
#define VK_NUMPAD3  0x63
#define VK_NUMPAD4  0x64
#define VK_NUMPAD5  0x65
#define VK_NUMPAD6  0x66
#define VK_NUMPAD7  0x67
#define VK_NUMPAD8  0x68
#define VK_NUMPAD9  0x69
#define VK_MULTIPLY 0x6A
#define VK_ADD  0x6B
#define VK_SEPARATOR  0x6C
#define VK_SUBTRACT 0x6D
#define VK_DECIMAL  0x6E
#define VK_DIVIDE 0x6F
#define VK_F1 0x70
#define VK_F2 0x71
#define VK_F3 0x72
#define VK_F4 0x73
#define VK_F5 0x74
#define VK_F6 0x75
#define VK_F7 0x76
#define VK_F8 0x77
#define VK_F9 0x78
#define VK_F10  0x79
#define VK_F11  0x7A
#define VK_F12  0x7B
#define VK_F13  0x7C
#define VK_F14  0x7D
#define VK_F15  0x7E
#define VK_F16  0x7F
#define VK_F17  0x80
#define VK_F18  0x81
#define VK_F19  0x82
#define VK_F20  0x83
#define VK_F21  0x84
#define VK_F22  0x85
#define VK_F23  0x86
#define VK_F24  0x87
#define VK_NUMLOCK  0x90
#define VK_SCROLL 0x91
#define VK_LSHIFT 0xA0
#define VK_RSHIFT 0xA1
#define VK_LCONTROL 0xA2
#define VK_RCONTROL 0xA3
#define VK_LMENU  0xA4
#define VK_RMENU  0xA5

#define VK_BROWSER_BACK 0xA6
#define VK_BROWSER_FORWARD  0xA7
#define VK_BROWSER_REFRESH  0xA8
#define VK_BROWSER_STOP 0xA9
#define VK_BROWSER_SEARCH 0xAA
#define VK_BROWSER_FAVORITES  0xAB
#define VK_BROWSER_HOME 0xAC
#define VK_VOLUME_MUTE  0xAD
#define VK_VOLUME_DOWN  0xAE
#define VK_VOLUME_UP  0xAF
#define VK_MEDIA_NEXT_TRACK 0xB0
#define VK_MEDIA_PREV_TRACK 0xB1
#define VK_MEDIA_STOP 0xB2
#define VK_MEDIA_PLAY_PAUSE 0xB3
#define VK_LAUNCH_MAIL  0xB4
#define VK_LAUNCH_MEDIA_SELECT  0xB5
#define VK_LAUNCH_APP1  0xB6
#define VK_LAUNCH_APP2  0xB7

#define VK_OEM_1  0xBA

#define VK_OEM_PLUS 0xBB
#define VK_OEM_COMMA  0xBC
#define VK_OEM_MINUS  0xBD
#define VK_OEM_PERIOD 0xBE

#define VK_OEM_2  0xBF
#define VK_OEM_3  0xC0
#define VK_OEM_4  0xDB
#define VK_OEM_5  0xDC
#define VK_OEM_6  0xDD
#define VK_OEM_7  0xDE
#define VK_OEM_8  0xDF

#define VK_OEM_102  0xE2

#define VK_PROCESSKEY 0xE5

#define VK_PACKET 0xE7

#define VK_ATTN 0xF6
#define VK_CRSEL  0xF7
#define VK_EXSEL  0xF8
#define VK_EREOF  0xF9
#define VK_PLAY 0xFA
#define VK_ZOOM 0xFB
#define VK_NONAME 0xFC
#define VK_PA1  0xFD
#define VK_OEM_CLEAR  0xFE*/
#ifndef WIN32
static const int VK_LBUTTON  =1;
static const int VK_RBUTTON  =2;
static const int VK_CANCEL =3;
static const int VK_MBUTTON  =4;
static const int VK_XBUTTON1 =5;
static const int VK_XBUTTON2 =6;
static const int VK_BACK =8;
static const int VK_TAB  =9;
static const int VK_CLEAR  =12;
static const int VK_RETURN =13;
static const int VK_SHIFT  =16;
static const int VK_CONTROL  =17;
static const int VK_MENU =18;
static const int VK_PAUSE  =19;
static const int VK_CAPITAL  =20;
static const int VK_KANA =0x15;
static const int VK_HANGEUL  =0x15;
static const int VK_HANGUL =0x15;
static const int VK_JUNJA  =0x17;
static const int VK_FINAL  =0x18;
static const int VK_HANJA  =0x19;
static const int VK_KANJI  =0x19;
static const int VK_ESCAPE =0x1B;
static const int VK_CONVERT  =0x1C;
static const int VK_NONCONVERT =0x1D;
static const int VK_ACCEPT =0x1E;
static const int VK_MODECHANGE =0x1F;
static const int VK_SPACE  =32;
static const int VK_PRIOR  =33;
static const int VK_NEXT =34;
static const int VK_END  =35;
static const int VK_HOME =36;
static const int VK_LEFT =37;
static const int VK_UP =38;
static const int VK_RIGHT  =39;
static const int VK_DOWN =40;
static const int VK_SELECT =41;
static const int VK_PRINT  =42;
static const int VK_EXECUTE  =43;
static const int VK_SNAPSHOT =44;
static const int VK_INSERT =45;
static const int VK_DELETE =46;
static const int VK_HELP =47;
static const int VK_LWIN =0x5B;
static const int VK_RWIN =0x5C;
static const int VK_APPS =0x5D;
static const int VK_SLEEP  =0x5F;
static const int VK_NUMPAD0  =0x60;
static const int VK_NUMPAD1  =0x61;
static const int VK_NUMPAD2  =0x62;
static const int VK_NUMPAD3  =0x63;
static const int VK_NUMPAD4  =0x64;
static const int VK_NUMPAD5  =0x65;
static const int VK_NUMPAD6  =0x66;
static const int VK_NUMPAD7  =0x67;
static const int VK_NUMPAD8  =0x68;
static const int VK_NUMPAD9  =0x69;
static const int VK_MULTIPLY =0x6A;
static const int VK_ADD  =0x6B;
static const int VK_SEPARATOR  =0x6C;
static const int VK_SUBTRACT =0x6D;
static const int VK_DECIMAL  =0x6E;
static const int VK_DIVIDE =0x6F;
static const int VK_F1 =0x70;
static const int VK_F2 =0x71;
static const int VK_F3 =0x72;
static const int VK_F4 =0x73;
static const int VK_F5 =0x74;
static const int VK_F6 =0x75;
static const int VK_F7 =0x76;
static const int VK_F8 =0x77;
static const int VK_F9 =0x78;
static const int VK_F10  =0x79;
static const int VK_F11  =0x7A;
static const int VK_F12  =0x7B;
static const int VK_F13  =0x7C;
static const int VK_F14  =0x7D;
static const int VK_F15  =0x7E;
static const int VK_F16  =0x7F;
static const int VK_F17  =0x80;
static const int VK_F18  =0x81;
static const int VK_F19  =0x82;
static const int VK_F20  =0x83;
static const int VK_F21  =0x84;
static const int VK_F22  =0x85;
static const int VK_F23  =0x86;
static const int VK_F24  =0x87;
static const int VK_NUMLOCK  =0x90;
static const int VK_SCROLL =0x91;
static const int VK_LSHIFT =0xA0;
static const int VK_RSHIFT =0xA1;
static const int VK_LCONTROL =0xA2;
static const int VK_RCONTROL =0xA3;
static const int VK_LMENU  =0xA4;
static const int VK_RMENU  =0xA5;
static const int VK_BROWSER_BACK =0xA6;
static const int VK_BROWSER_FORWARD  =0xA7;
static const int VK_BROWSER_REFRESH  =0xA8;
static const int VK_BROWSER_STOP =0xA9;
static const int VK_BROWSER_SEARCH =0xAA;
static const int VK_BROWSER_FAVORITES  =0xAB;
static const int VK_BROWSER_HOME =0xAC;
static const int VK_VOLUME_MUTE  =0xAD;
static const int VK_VOLUME_DOWN  =0xAE;
static const int VK_VOLUME_UP  =0xAF;
static const int VK_MEDIA_NEXT_TRACK =0xB0;
static const int VK_MEDIA_PREV_TRACK =0xB1;
static const int VK_MEDIA_STOP =0xB2;
static const int VK_MEDIA_PLAY_PAUSE =0xB3;
static const int VK_LAUNCH_MAIL  =0xB4;
static const int VK_LAUNCH_MEDIA_SELECT  =0xB5;
static const int VK_LAUNCH_APP1  =0xB6;
static const int VK_LAUNCH_APP2  =0xB7;
static const int VK_OEM_1  =0xBA;
static const int VK_OEM_PLUS =0xBB;
static const int VK_OEM_COMMA  =0xBC;
static const int VK_OEM_MINUS  =0xBD;
static const int VK_OEM_PERIOD =0xBE;
static const int VK_OEM_2  =0xBF;
static const int VK_OEM_3  =0xC0;
static const int VK_OEM_4  =0xDB;
static const int VK_OEM_5  =0xDC;
static const int VK_OEM_6  =0xDD;
static const int VK_OEM_7  =0xDE;
static const int VK_OEM_8  =0xDF;
static const int VK_OEM_102  =0xE2;
static const int VK_PROCESSKEY =0xE5;
static const int VK_PACKET =0xE7;
static const int VK_ATTN =0xF6;
static const int VK_CRSEL  =0xF7;
static const int VK_EXSEL  =0xF8;
static const int VK_EREOF  =0xF9;
static const int VK_PLAY =0xFA;
static const int VK_ZOOM =0xFB;
static const int VK_NONAME =0xFC;
static const int VK_PA1  =0xFD;
static const int VK_OEM_CLEAR  =0xFE;
#endif
/*
  // http://adler3d.github.io/test2013/
  var u=e=>{e[e.length-1]="="+e[e.length-1];return e;};
  var f=e=>u(e.split(" ")).join(" ").split("#define ").join("static const int ");
  return POST.data.split("\n").filter(e=>e.length).map(f).join(";\n");
*/