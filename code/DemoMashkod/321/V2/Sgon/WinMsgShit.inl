string Msg2String(int msg);

#include <Windowsx.h>

class TWinMsgPoint{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWinMsgPoint)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,x,SET,320,$)\
ADDVAR(1,int,y,SET,240,$)\
ADDEND()
//=====+>>>>>TWinMsgPoint
#include "QapGenStruct.inl"
//<<<<<+=====TWinMsgPoint
};

class TWinMsg{
public:
#define DEF_PRO_AUTO_COPY()
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWinMsg)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,int,hwnd,SET,0,$)\
ADDVAR(1,int,message,DEF,$,$)\
ADDVAR(2,int,wParam,SET,0,$)\
ADDVAR(3,int,lParam,SET,0,$)\
ADDVAR(4,int,time,DEF,$,$)\
ADDVAR(5,TWinMsgPoint,pt,DEF,$,$)\
ADDEND()
//=====+>>>>>TWinMsg
#include "QapGenStruct.inl"
//<<<<<+=====TWinMsg
public:
  TWinMsg(const MSG&ref){
    *(MSG*)(void*)this=ref;
  }
  string toStr()
  {
    string wParam_str=IToS(wParam);
    string lParam_str=IToS(lParam);
    if(WM_SYSCOMMAND==message){wParam_str=SysCmd();}
    if(WM_MOVE==message){lParam_str=lParam2xy();}
    if(WM_SIZE==message){wParam_str=toStr_wParam_WM_SIZE();lParam_str=lParam2xy();}
    if(WM_SHOWWINDOW==message){
      lParam_str=toStr_lParam_WM_SHOWWINDOW();
      if(wParam==TRUE)wParam_str="shown";
      if(wParam==FALSE)wParam_str="hidden";
    }
    if(WM_IME_NOTIFY==message){
      wParam_str=toStr_wParam_WM_IME_NOTIFY();
    }
    if(WM_COMMAND==message){
      wParam_str=toStr_wParam_WM_COMMAND();
    }
    if(WM_PARENTNOTIFY==message){wParam_str=toStr_wParam_WM_PARENTNOTIFY();lParam_str=toStr_lParam2point_xy();}
    if(WM_NCHITTEST==message){
      lParam_str=toStr_lParam2point_xy();
    }
    if(WM_MOUSEFIRST==message){
      lParam_str=toStr_lParam2point_xy();
    }
    if(WM_SIZING==message){
      wParam_str=toStr_wParam_WM_SIZING();
    }
    return IToS(hwnd)+";"+Msg2String(message)+";"+wParam_str+";"+lParam_str;//+";"+IToS(time)+";"+IToS(pt.x)+";"+IToS(pt.y);
  }
  string toStr_wParam_WM_SIZING(){
    #define F(CMD)if(CMD==HIWORD(wParam))return #CMD;
    F(WMSZ_LEFT       );
    F(WMSZ_RIGHT      );
    F(WMSZ_TOP        );
    F(WMSZ_TOPLEFT    );
    F(WMSZ_TOPRIGHT   );
    F(WMSZ_BOTTOM     );
    F(WMSZ_BOTTOMLEFT );
    F(WMSZ_BOTTOMRIGHT);
    #undef F
    return IToS(HIWORD(wParam));
  }
  string toStr_wParam_WM_PARENTNOTIFY(){
    return Msg2String(wParam);
  }
  string toStr_lParam2point_xy(){
    auto xPos = GET_X_LPARAM(lParam);
    auto yPos = GET_Y_LPARAM(lParam);
    return "(x:"+IToS(xPos)+";y:"+IToS(yPos)+")";
  }
  string toStr_wParam_HIWORD_WM_COMMAND(){
    const int Menu=0;
    const int Accelerator=1;
    #define F(CMD)if(CMD==HIWORD(wParam))return #CMD;
    F(BN_CLICKED  );
    F(BN_PAINT    );
    F(BN_DISABLE  );
    F(BN_PUSHED   );
    F(BN_UNPUSHED );
    F(BN_DBLCLK   );
    F(BN_SETFOCUS );
    F(BN_KILLFOCUS);
    F(Menu );
    F(Accelerator);
    F(EN_SETFOCUS );
    F(EN_KILLFOCUS);
    F(EN_CHANGE   );
    F(EN_UPDATE   );
    F(EN_ERRSPACE );
    F(EN_MAXTEXT  );
    F(EN_HSCROLL  );
    F(EN_VSCROLL  );
    F(EN_ALIGN_LTR_EC);
    F(EN_ALIGN_RTL_EC);
    F(LBN_ERRSPACE    );
    F(LBN_SELCHANGE   );
    F(LBN_DBLCLK      );
    F(LBN_SELCANCEL   );
    F(LBN_SETFOCUS    );
    F(LBN_KILLFOCUS   );
    F(CBN_ERRSPACE    );
    F(CBN_SELCHANGE   );
    F(CBN_DBLCLK      );
    F(CBN_SETFOCUS    );
    F(CBN_KILLFOCUS   );
    F(CBN_EDITCHANGE  );
    F(CBN_EDITUPDATE  );
    F(CBN_DROPDOWN    );
    F(CBN_CLOSEUP     );
    F(CBN_SELENDOK    );
    F(CBN_SELENDCANCEL);
    #undef F
    return IToS(HIWORD(wParam));
  }
  string toStr_wParam_WM_COMMAND(){
    return "(source:"+toStr_wParam_HIWORD_WM_COMMAND()+";id:"+IToS(LOWORD(wParam))+")";
  }
  string toStr_wParam_WM_IME_NOTIFY(){
    #define F(CMD)if(CMD==wParam)return #CMD;
    F(IMN_CLOSESTATUSWINDOW   );
    F(IMN_OPENSTATUSWINDOW    );
    F(IMN_CHANGECANDIDATE     );
    F(IMN_CLOSECANDIDATE      );
    F(IMN_OPENCANDIDATE       );
    F(IMN_SETCONVERSIONMODE   );
    F(IMN_SETSENTENCEMODE     );
    F(IMN_SETOPENSTATUS       );
    F(IMN_SETCANDIDATEPOS     );
    F(IMN_SETCOMPOSITIONFONT  );
    F(IMN_SETCOMPOSITIONWINDOW);
    F(IMN_SETSTATUSWINDOWPOS  );
    F(IMN_GUIDELINE           );
    F(IMN_PRIVATE             );
    #undef F
    return IToS(wParam);
  }
  string toStr_lParam_WM_SHOWWINDOW(){
    #define F(CMD)if(CMD==lParam)return #CMD;
    F(SW_PARENTCLOSING);
    F(SW_OTHERZOOM    );
    F(SW_PARENTOPENING);
    F(SW_OTHERUNZOOM  );
    #undef F
    return IToS(lParam);
  }
  string lParam2xy(){
    auto xPos = (int)(short) LOWORD(lParam);   // horizontal position 
    auto yPos = (int)(short) HIWORD(lParam);   // vertical position 
    return "(x:"+IToS(xPos)+";y:"+IToS(yPos)+")";
  }
  string toStr_wParam_WM_SIZE(){
    #define F(CMD)if(CMD==wParam)return #CMD;
    F(SIZE_RESTORED );
    F(SIZE_MINIMIZED);
    F(SIZE_MAXIMIZED);
    F(SIZE_MAXSHOW  );
    F(SIZE_MAXHIDE  );
    #undef F
    return IToS(wParam);
  }
  string SysCmd(){
    #define F(CMD)if(CMD==wParam)return #CMD;
    F(SC_SIZE);
    F(SC_MOVE);
    F(SC_MINIMIZE);
    F(SC_MAXIMIZE);
    F(SC_NEXTWINDOW);
    F(SC_PREVWINDOW);
    F(SC_CLOSE);
    F(SC_VSCROLL);
    F(SC_HSCROLL);
    F(SC_MOUSEMENU);
    F(SC_KEYMENU);
    F(SC_ARRANGE);
    F(SC_RESTORE);
    F(SC_TASKLIST);
    F(SC_SCREENSAVE);
    F(SC_HOTKEY);
    F(SC_DEFAULT);
    F(SC_MONITORPOWER);
    F(SC_CONTEXTHELP);
    F(SC_SEPARATOR);
    F(SC_ICON);
    F(SC_ZOOM);
    #undef F
    return IToS(wParam);
  }
};

class TWinMsgRec{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TWinMsgRec)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(0,real,time,SET,0,$)\
ADDVAR(1,TWinMsg,msg,DEF,$,$)\
ADDEND()
//=====+>>>>>TWinMsgRec
#include "QapGenStruct.inl"
//<<<<<+=====TWinMsgRec
public:
};


string Msg2String(int msg)
{
  #define F(MSG)if(msg==MSG)return #MSG;
F(WM_NULL);
F(WM_CREATE);
F(WM_DESTROY);
F(WM_MOVE);
F(WM_SIZE);
F(WM_ACTIVATE);
F(WM_SETFOCUS);
F(WM_KILLFOCUS);
F(WM_ENABLE);
F(WM_SETREDRAW);
F(WM_SETTEXT);
F(WM_GETTEXT);
F(WM_GETTEXTLENGTH);
F(WM_PAINT);
F(WM_CLOSE);
F(WM_QUERYENDSESSION);
F(WM_QUERYOPEN);
F(WM_ENDSESSION);
F(WM_QUIT);
F(WM_ERASEBKGND);
F(WM_SYSCOLORCHANGE);
F(WM_SHOWWINDOW);
F(WM_WININICHANGE);
F(WM_SETTINGCHANGE);
F(WM_DEVMODECHANGE);
F(WM_ACTIVATEAPP);
F(WM_FONTCHANGE);
F(WM_TIMECHANGE);
F(WM_CANCELMODE);
F(WM_SETCURSOR);
F(WM_MOUSEACTIVATE);
F(WM_CHILDACTIVATE);
F(WM_QUEUESYNC);
F(WM_GETMINMAXINFO);
F(WM_PAINTICON);
F(WM_ICONERASEBKGND);
F(WM_NEXTDLGCTL);
F(WM_SPOOLERSTATUS);
F(WM_DRAWITEM);
F(WM_MEASUREITEM);
F(WM_DELETEITEM);
F(WM_VKEYTOITEM);
F(WM_CHARTOITEM);
F(WM_SETFONT);
F(WM_GETFONT);
F(WM_SETHOTKEY);
F(WM_GETHOTKEY);
F(WM_QUERYDRAGICON);
F(WM_COMPAREITEM);
F(WM_GETOBJECT);
F(WM_COMPACTING);
F(WM_COMMNOTIFY);
F(WM_WINDOWPOSCHANGING);
F(WM_WINDOWPOSCHANGED);
F(WM_POWER);
F(WM_COPYDATA);
F(WM_CANCELJOURNAL);
F(WM_NOTIFY);
F(WM_INPUTLANGCHANGEREQUEST);
F(WM_INPUTLANGCHANGE);
F(WM_TCARD);
F(WM_HELP);
F(WM_USERCHANGED);
F(WM_NOTIFYFORMAT);
F(WM_CONTEXTMENU);
F(WM_STYLECHANGING);
F(WM_STYLECHANGED);
F(WM_DISPLAYCHANGE);
F(WM_GETICON);
F(WM_SETICON);
F(WM_NCCREATE);
F(WM_NCDESTROY);
F(WM_NCCALCSIZE);
F(WM_NCHITTEST);
F(WM_NCPAINT);
F(WM_NCACTIVATE);
F(WM_GETDLGCODE);
F(WM_SYNCPAINT);
F(WM_NCMOUSEMOVE);
F(WM_NCLBUTTONDOWN);
F(WM_NCLBUTTONUP);
F(WM_NCLBUTTONDBLCLK);
F(WM_NCRBUTTONDOWN);
F(WM_NCRBUTTONUP);
F(WM_NCRBUTTONDBLCLK);
F(WM_NCMBUTTONDOWN);
F(WM_NCMBUTTONUP);
F(WM_NCMBUTTONDBLCLK);
F(WM_NCXBUTTONDOWN);
F(WM_NCXBUTTONUP);
F(WM_NCXBUTTONDBLCLK);
F(WM_INPUT_DEVICE_CHANGE);
F(WM_INPUT);
F(WM_KEYFIRST);
F(WM_KEYDOWN);
F(WM_KEYUP);
F(WM_CHAR);
F(WM_DEADCHAR);
F(WM_SYSKEYDOWN);
F(WM_SYSKEYUP);
F(WM_SYSCHAR);
F(WM_SYSDEADCHAR);
F(WM_UNICHAR);
F(WM_KEYLAST);
F(WM_IME_STARTCOMPOSITION);
F(WM_IME_ENDCOMPOSITION);
F(WM_IME_COMPOSITION);
F(WM_IME_KEYLAST);
F(WM_INITDIALOG);
F(WM_COMMAND);
F(WM_SYSCOMMAND);
F(WM_TIMER);
F(WM_HSCROLL);
F(WM_VSCROLL);
F(WM_INITMENU);
F(WM_INITMENUPOPUP);
F(WM_GESTURE);
F(WM_GESTURENOTIFY);
F(WM_MENUSELECT);
F(WM_MENUCHAR);
F(WM_ENTERIDLE);
F(WM_MENURBUTTONUP);
F(WM_MENUDRAG);
F(WM_MENUGETOBJECT);
F(WM_UNINITMENUPOPUP);
F(WM_MENUCOMMAND);
F(WM_CHANGEUISTATE);
F(WM_UPDATEUISTATE);
F(WM_QUERYUISTATE);
F(WM_CTLCOLORMSGBOX);
F(WM_CTLCOLOREDIT);
F(WM_CTLCOLORLISTBOX);
F(WM_CTLCOLORBTN);
F(WM_CTLCOLORDLG);
F(WM_CTLCOLORSCROLLBAR);
F(WM_CTLCOLORSTATIC);
F(WM_MOUSEFIRST);
F(WM_MOUSEMOVE);
F(WM_LBUTTONDOWN);
F(WM_LBUTTONUP);
F(WM_LBUTTONDBLCLK);
F(WM_RBUTTONDOWN);
F(WM_RBUTTONUP);
F(WM_RBUTTONDBLCLK);
F(WM_MBUTTONDOWN);
F(WM_MBUTTONUP);
F(WM_MBUTTONDBLCLK);
F(WM_MOUSEWHEEL);
F(WM_XBUTTONDOWN);
F(WM_XBUTTONUP);
F(WM_XBUTTONDBLCLK);
F(WM_MOUSEHWHEEL);
F(WM_MOUSELAST);
F(WM_PARENTNOTIFY);
F(WM_ENTERMENULOOP);
F(WM_EXITMENULOOP);
F(WM_NEXTMENU);
F(WM_SIZING);
F(WM_CAPTURECHANGED);
F(WM_MOVING);
F(WM_POWERBROADCAST);
F(WM_DEVICECHANGE);
F(WM_MDICREATE);
F(WM_MDIDESTROY);
F(WM_MDIACTIVATE);
F(WM_MDIRESTORE);
F(WM_MDINEXT);
F(WM_MDIMAXIMIZE);
F(WM_MDITILE);
F(WM_MDICASCADE);
F(WM_MDIICONARRANGE);
F(WM_MDIGETACTIVE);
F(WM_MDISETMENU);
F(WM_ENTERSIZEMOVE);
F(WM_EXITSIZEMOVE);
F(WM_DROPFILES);
F(WM_MDIREFRESHMENU);
F(WM_TOUCH);
F(WM_IME_SETCONTEXT);
F(WM_IME_NOTIFY);
F(WM_IME_CONTROL);
F(WM_IME_COMPOSITIONFULL);
F(WM_IME_SELECT);
F(WM_IME_CHAR);
F(WM_IME_REQUEST);
F(WM_IME_KEYDOWN);
F(WM_IME_KEYUP);
F(WM_MOUSEHOVER);
F(WM_MOUSELEAVE);
F(WM_NCMOUSEHOVER);
F(WM_NCMOUSELEAVE);
F(WM_WTSSESSION_CHANGE);
F(WM_TABLET_FIRST);
F(WM_TABLET_LAST);
F(WM_CUT);
F(WM_COPY);
F(WM_PASTE);
F(WM_CLEAR);
F(WM_UNDO);
F(WM_RENDERFORMAT);
F(WM_RENDERALLFORMATS);
F(WM_DESTROYCLIPBOARD);
F(WM_DRAWCLIPBOARD);
F(WM_PAINTCLIPBOARD);
F(WM_VSCROLLCLIPBOARD);
F(WM_SIZECLIPBOARD);
F(WM_ASKCBFORMATNAME);
F(WM_CHANGECBCHAIN);
F(WM_HSCROLLCLIPBOARD);
F(WM_QUERYNEWPALETTE);
F(WM_PALETTEISCHANGING);
F(WM_PALETTECHANGED);
F(WM_HOTKEY);
F(WM_PRINT);
F(WM_PRINTCLIENT);
F(WM_APPCOMMAND);
F(WM_THEMECHANGED);
F(WM_CLIPBOARDUPDATE);
F(WM_DWMCOMPOSITIONCHANGED);
F(WM_DWMNCRENDERINGCHANGED);
F(WM_DWMCOLORIZATIONCOLORCHANGED);
F(WM_DWMWINDOWMAXIMIZEDCHANGE);
F(WM_DWMSENDICONICTHUMBNAIL);
F(WM_DWMSENDICONICLIVEPREVIEWBITMAP);
F(WM_GETTITLEBARINFOEX);
F(WM_HANDHELDFIRST);
F(WM_HANDHELDLAST);
F(WM_AFXFIRST);
F(WM_AFXLAST);
F(WM_PENWINFIRST);
F(WM_PENWINLAST);
F(WM_APP);
F(WM_USER);

static const int WM_SETVISIBLE       = 0x00000009;
static const int WM_ALTTABACTIVE     = 0x00000029;
static const int WM_ISACTIVEICON     = 0x00000035;
static const int WM_QUERYPARKICON    = 0x00000036;
static const int WM_CLIENTSHUTDOWN   = 0x0000003B;
static const int WM_COPYGLOBALDATA   = 0x00000049;
static const int WM_LOGONNOTIFY      = 0x0000004C;
static const int WM_KEYF1            = 0x0000004D;
static const int WM_NCUAHDRAWCAPTION = 0x000000AE;
static const int WM_NCUAHDRAWFRAME   = 0x000000AF;
static const int WM_SYSTIMER         = 0x00000118;
static const int WM_LBTRACKPOINT     = 0x00000131;
static const int LB_CARETON          = 0x000001a3;
static const int LB_CARETOFF         = 0x000001a4;
static const int WM_DROPOBJECT       = 0x0000022A;
static const int WM_QUERYDROPOBJECT  = 0x0000022B;
static const int WM_BEGINDRAG        = 0x0000022C;
static const int WM_DRAGLOOP         = 0x0000022D;
static const int WM_DRAGSELECT       = 0x0000022E;
static const int WM_DRAGMOVE         = 0x0000022F;
static const int WM_POPUPSYSTEMMENU  = 0x00000313;
static const int WM_UAHINIT          = 0x0000031b;
static const int WM_MAXIMUM          = 0x0001FFFF;

F(WM_SETVISIBLE      );
F(WM_ALTTABACTIVE    );
F(WM_ISACTIVEICON    );
F(WM_QUERYPARKICON   );
F(WM_CLIENTSHUTDOWN  );
F(WM_COPYGLOBALDATA  );
F(WM_LOGONNOTIFY     );
F(WM_KEYF1           );
F(WM_NCUAHDRAWCAPTION);
F(WM_NCUAHDRAWFRAME  );
F(WM_SYSTIMER        );
F(WM_LBTRACKPOINT    );
F(LB_CARETON         );
F(LB_CARETOFF        );
F(WM_DROPOBJECT      );
F(WM_QUERYDROPOBJECT );
F(WM_BEGINDRAG       );
F(WM_DRAGLOOP        );
F(WM_DRAGSELECT      );
F(WM_DRAGMOVE        );
F(WM_POPUPSYSTEMMENU );
F(WM_UAHINIT         );
F(WM_MAXIMUM         );

F(WM_MOUSELEAVE);
F(WM_MOUSEHOVER);
F(WM_NCMOUSEHOVER);
F(WM_NCMOUSELEAVE);
F(WM_IME_SETCONTEXT);
F(WM_IME_NOTIFY);
  #undef F
  char buffer[1024*8]={0};
  GetClipboardFormatName(msg,buffer,1024*8);
  return IToS(msg)+"\""+string(buffer)+"\"";
}