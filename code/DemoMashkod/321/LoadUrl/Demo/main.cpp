#define _ITERATOR_DEBUG_LEVEL 0
#define _HAS_ITERATOR_DEBUGGING 0
#define _SECURE_SCL 0
#include "QapLite.h"
#include <random>

#include "qap_sys.inl"

#include "InetDownloader.hpp"
#include "network.inl"

//#include "proc_list.inl"
#include "http_tool.inl"
//#include "account_server.inl"
string http_get_content(const string&s){return DownLoader::LoadUrl("get",s,"").get_body();}
void acc_main()
{
  auto s=http_get_content("ya.ru");
  auto head=get_first_part(s,"\"\n");
  auto code=get_second_part(head,"//\"");
  int gg=1;
}
static vector<string> vIToS(const vector<int>&arr){vector<string> out;for(int i=0;i<arr.size();i++)out.push_back(IToS(arr[i]));return out;}
void test()
{
  vector<int> out;
  auto top=25;
  out.push_back(0);
  out.push_back(top-1);
  for(int n=1;n<top;n*=2)
  for(int i=0;i<n;i++)
  {
    auto k=top/n;
    auto v=k/2+i*k;
    if(v!=top-1)out.push_back(v);
  }
  string s=join(vIToS(out),",");
  int gg=1;
}

struct t_diff{
  int id;
  int old_v;
  int new_v;
  void set(int i,int o,int n){id=i;old_v=o;new_v=n;}
};

vector<t_diff> make_diff(const vector<int>&bef,const vector<int>&aft){
  vector<t_diff> out;
  for(int i=0;i<bef.size();i++){auto&b=bef[i];auto&a=aft[i];if(b!=a)qap_add_back(out).set(i,b,a);}
  return out;
}
/*
make_diff(bef.mem,aft.mem);
make_diff(bef.reg,aft.reg);*/

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  test();
  acc_main();
  return 0;
}