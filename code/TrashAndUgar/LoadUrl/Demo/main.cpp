#define _ITERATOR_DEBUG_LEVEL 0
#define _HAS_ITERATOR_DEBUGGING 0
#define _SECURE_SCL 0
#include "QapLite.h"
#include <random>

#include "qap_sys.inl"

#include "InetDownloader.hpp"
#include "network.inl"

#include "http_tool.inl"

#include "TQapGameV2.inl"

void acc_main()
{
  auto s=http_get_content("ya.ru");
  auto head=get_first_part(s,"\"\n");
  auto code=get_second_part(head,"//\"");
  int gg=1;
}

string url_menu="localhost/levels/";

class TGame:public TQapGameV2{
public: 
  class t_menu{
  public:
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(bool,enabled,false)\
    ADD(bool,wait_next_tick,false)\
    ADD(vec2d,pos,$)\
    ADD(string,target,$)\
    ADD(vector<string>,lines,$)\
    ADD(string,caption,$)\
    //===
    #include "defprovar.inl"
    //===
    void fill(string caption)
    {
      this->caption=caption;
      lines=split("lock,invite,trade,ignore",",");
    }
    t_menu(){DoReset();}
    void load_from(string s){caption=get_first_part(s,"```");lines=split(get_second_part(s,"```"),",");};
  };
  t_menu menu;
  t_menu nav_menu;
  vector<string> info;
  #include "menu.inl"
  void soUpdate()
  {
    if(kb.OnDown(VK_ESCAPE))win.Close();
    auto rv=soMenu(*this,menu,16);
    if(movepass)
    {
      if(rv.is_select())
      {
        auto&item=rv.menu.lines[rv.id];
        auto&content=info[rv.id];
        if(content=="empty:")
        {
          content="data:"+wget(url_menu+HttpTool::urlencode(item));
        }
        nav_menu.enabled=true;
        nav_menu.caption=item;
        auto c=get_second_part(content,":");
        c="size = "+IToS(c.size());
        nav_menu.lines=split(c,"\n");
      }else{
        //nav_menu.enabled=false;
      }
    }
    soMenu(*this,nav_menu);
    //menu.caption=IToS(rv);
    static bool first=1;
    if(movepass&&kb("CTRL+O"))
    {
      first=0;
      //auto s=http_get_content("adler3d.github.io/qap_menu");
      //menu.load_from(s);
      nav_menu.pos.x=viewport.size.x*0.5-200;
      nav_menu.load_from("navigation```next,prev,exit");
      nav_menu.enabled=false;
      menu.caption="список_карт(кликнешь - откроется в новой вкладке)";
      menu.enabled=true;
      //menu.lines=split("select nick,play as guest,login,register,exit",",");
      auto list=wget(url_menu);
      //auto list="play(connect to nexus),level editor";
      menu.lines=split(list,"\n");
      info.resize(menu.lines.size(),"empty:");
    }
  }
  string without_crlf(string s){return StrReplace(s,"\r","");}
  string wget(string url){
    return without_crlf(http_get_content(url));
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TGame builder;
  builder.DoNice();
  return 0;
}