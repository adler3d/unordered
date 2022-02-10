#define DEF_PRO_SORT_BY_FIELD(sort_by_field,TYPE,FIELD)\
  struct t_help_struct_for_sort_vec_of_##TYPE##_by_##FIELD{\
    static int __cdecl cmp_func(const void*a,const void*b){return cmp(*(TYPE*)a,*(TYPE*)b);}\
    static int cmp(const TYPE&a,const TYPE&b){return a.FIELD-b.FIELD;}\
  };\
  void sort_by_field(vector<TYPE>&arr){\
    if(arr.empty())return;\
    std::qsort(&arr[0],arr.size(),sizeof(t_id_with_dist),t_help_struct_for_sort_vec_of_##TYPE##_by_##FIELD::cmp_func);\
  }
#define PRO_FUNCGEN_GETP_BY_FIELD(rettype,getp,arr,field_type,field)\
  rettype*getp(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    return p;\
  }

#define PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD(rettype,adduni,arr,field_type,field)\
  rettype*adduni(field_type value)\
  {\
    rettype*p=nullptr;\
    for(int i=0;i<arr.size();i++){\
      auto&ex=arr[i];\
      if(ex.field!=value)continue;\
      QapAssert(!p);\
      p=&ex;\
    }\
    if(!p)p=&qap_add_back(arr);\
    return p;\
  }

struct WinApiTool{
  static void shell_url(const string&url)
  {
    static bool runonce=true;if(runonce){runonce=false;CoInitializeEx(NULL,COINIT_APARTMENTTHREADED|COINIT_DISABLE_OLE1DDE);}
    SHELLEXECUTEINFO ShExecInfo={0};
    ShExecInfo.cbSize=sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask=SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd=NULL;
    ShExecInfo.lpVerb=NULL;
    ShExecInfo.lpFile=url.c_str();        
    ShExecInfo.lpParameters="";   
    ShExecInfo.lpDirectory=NULL;
    ShExecInfo.nShow=SW_SHOW;
    ShExecInfo.hInstApp=NULL; 
    ShellExecuteEx(&ShExecInfo);
    WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
  }
  static void exec(const string&command,const string&arg)
  {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si,sizeof(si));
    si.cb=sizeof(si);
    ZeroMemory(&pi,sizeof(pi));
    string tmp_arg=arg;
    if(CreateProcess(command.c_str(),&tmp_arg[0],NULL,NULL,FALSE,NULL,NULL,NULL,&si,&pi))
    {
      int gg=1;
      WaitForSingleObject(pi.hProcess,INFINITE);
      CloseHandle(pi.hProcess);
      CloseHandle(pi.hThread);
    }
  }
};

#include "qap_sys.inl"

class TQapGameV2:public TQapGame{
public:
  struct t_hook{
    #define DEF_PRO_CLASSNAME()t_hook
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(string,name,$)\
    ADD(string,value,$)\
    ADD(int,tick,-1)\
    //===
    #include "defprovar.inl"
    //===
  };
  static vector<int> find_hook(vector<t_hook>&arr,const string&name){
    vector<int> out;for(int i=0;i<arr.size();i++)if(arr[i].name==name)out.push_back(i);return out;
  };
  static t_hook*get_hook(vector<t_hook>&arr,const string&name){
    auto r=find_hook(arr,name);if(r.empty())return nullptr;QapAssert(r.size()==1);return &arr[r[0]];
  };
  static t_hook&add_hook(vector<t_hook>&hooks,char*name,int tick){
    auto*p=get_hook(hooks,name);if(!p){p=&qap_add_back(hooks);p->name=name;}p->tick=tick;return *p;
  }
  struct t_input{
    #define DEF_PRO_CLASSNAME()t_input
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,server_id,-1)\
    ADD(int,actor_id,-1)\
    ADD(QapKeyboard,kb,$)\
    ADD(vec2d,mpos,$)\
    ADD(vec2d,consize,$)\
    ADD(int,zDelta,0)\
    ADD(int,game_tick,-1)\
    ADD(vector<t_hook>,hooks,$)\
    //===
    #include "defprovar.inl"
    //===
  public:
    //t_input(){DoReset();}
    operator bool()const{return point_in_quad(t_quad().add_size(consize),mpos);}
  };
  template<class TYPE>
  class t_looped_buffer{
  public:
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<TYPE>,frames,$)\
  ADD(int,n,1)\
  ADD(int,ptr,0)\
  //===
  #include "defprovar.inl"
  //===
  public:
    //vector<t_input>&back(){return frames[ptr%n];}
    TYPE&add()
    {
      QapAssert(n>0);
      if(frames.size()!=n)frames.resize(n);
      ptr=ptr%n;
      auto&cur=frames[ptr];
      ptr++;
      ptr=ptr%n;
      return cur;
    }
    TYPE add(TYPE&&value)
    {
      QapAssert(n>0);
      if(frames.size()!=n)frames.resize(n);
      ptr=ptr%n;
      auto&cur=frames[ptr];
      auto old=std::move(cur);
      std::move(cur)=value;
      ptr++;
      ptr=ptr%n;
      return old;
    }
    t_looped_buffer(){DoReset();}
  };
public:
#define DEF_PRO_VARIABLE(ADD)\
ADD(bool,drawpass,false)\
ADD(bool,movepass,false)\
ADD(bool,srvpass,false)\
ADD(bool,cntpass,false)\
ADD(t_quad&,viewport,qDev.viewport)\
ADD(vec2d&,consize,viewport.size)\
//===
#include "defprovar.inl"
//===
public:
  TQapGameV2():viewport(qDev.viewport),consize(viewport.size){DoReset();}
public:
  void DoDraw(){qDev.auto_clamp=true;consize=win.GetClientSize();drawpass=true;soUpdate();drawpass=false;}
  void DoMove(){qDev.auto_clamp=true;consize=win.GetClientSize();movepass=true;soUpdate();movepass=false;}
  virtual void soUpdate(){}
public:
  static void DrawQuadWithBorder(QapDev&qDev,t_quad q)
  {
    qDev.DrawQuad(q.pos,q.size);
    DrawQuadBorder(qDev,q);
  }
  static void DrawQuadBorder(QapDev&qDev,t_quad q){qDev.color=QapColor::HalfMix(0xff000000,qDev.color);qDev.DrawRectAsQuad(q.pos,q.size,2);}
  void DrawQuadWithBorder(t_quad q){DrawQuadWithBorder(qDev,q);}
  void DrawQuadBorder(t_quad q){DrawQuadBorder(qDev,q);}
  static void DrawQuad(QapDev&qDev,t_quad q){qDev.DrawQuad(q.pos,q.size);}
};