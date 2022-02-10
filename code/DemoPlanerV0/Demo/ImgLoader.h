// Interface. App_Side <=> DLL_Side

struct ImgLoader{
  struct string
  {
    const char*ptr;
    int size;
  };
  struct TextureMemory
  {
    void*ptr;
    int W;
    int H;
    TextureMemory(){ptr=0;W=0;H=0;}
  };
  struct IEnv
  {
    virtual void InitMemory(TextureMemory&out,int W,int H)=0;
    virtual void FreeMemory(TextureMemory&in)=0;
  };
  virtual void LoadTextureFromFile(IEnv&Env,TextureMemory&Mem,string FileName)=0;
  virtual void SaveTextureToFile(IEnv&Env,TextureMemory&Mem,string FileName)=0;
  virtual bool KeepExt(string ext)=0;
};
// Dynamic.h
struct DynamicContext
{
  DynamicContext(){DoReset();}
  typedef ImgLoader*(WINAPI *PGIL)();
  //...
  string path;
  HMODULE Module;
  PGIL pProc;
  //...
  ImgLoader*GetImgLoader(){return pProc();}
  //...
  void DoReset()
  {
    path="pngloader.dll";
    Module=0;
    pProc=0;
  }
  //...
  void init()
  {
    const string ProcName="GetImgLoader";
    Module=LoadLibrary(path.c_str());
    if(!Module){QapDebugMsg("\""+path+"\" - dll not found");return;}
    pProc=(PGIL)GetProcAddress(Module,ProcName.c_str());
    if(!pProc){QapDebugMsg("\""+ProcName+"\" - proc not found in \""+path+"\"");return;}
  }
  void free()
  {
    FreeLibrary(Module);
    pProc=nullptr;
  }
};

struct TLoaderEnv:ImgLoader::IEnv
{
  static ImgLoader::string SToS(const std::string&in)
  {
    ImgLoader::string tmp;
    if(in.empty()){tmp.ptr=0;tmp.size=0;return tmp;}
    tmp.ptr=&in[0];
    tmp.size=in.size();
    return tmp;
  }
  typedef ImgLoader::TextureMemory TextureMemory;
  //using ImgLoader::TextureMemory;
  void InitMemory(TextureMemory&out,int W,int H)
  {
    if(W*H<=0)return;
    QapAssert(!out.ptr);
    QapAssert(!out.W);
    QapAssert(!out.H);
    out.ptr=new int[W*H];
    out.W=W;
    out.H=H;
    int*p=(int*)out.ptr;
    for(int i=0;i<W*H;i++)p[i]=0;
  }
  void FreeMemory(TextureMemory&in)
  {
    int*ptr=(int*)in.ptr;
    delete[] ptr;
    in.ptr=0;
    in.W=0;
    in.H=0;
  }
  DynamicContext DC;
  ImgLoader*pLoader;
  TLoaderEnv()
  {
    DC.init();
    pLoader=DC.GetImgLoader();
  }
  TLoaderEnv(string&path)
  {
    DC.path=path;
    DC.init();
    pLoader=DC.GetImgLoader();
  }
  ~TLoaderEnv()
  {
    pLoader=nullptr;
    DC.free();
  }
  static string GetFileExt(const std::string&fn)
  {
    //std::string fn=FileName;
    auto x=fn.rfind('.');
    if(x==std::string::npos)return "";
    return fn.substr(x+1);
  }
  void LoadTextureFromFile(TextureMemory&Mem,const std::string&FileName)
  {
    if(!pLoader)return;
    std::string fn=FileName;
    pLoader->LoadTextureFromFile(*this,Mem,SToS(fn));
  }
  void SaveTextureToFile(TextureMemory&Mem,const std::string&FileName)
  {
    if(!pLoader)return;
    if(!KeepExt(GetFileExt(FileName)))return;
    pLoader->SaveTextureToFile(*this,Mem,SToS(FileName));
  }
  bool KeepExt(const std::string&ext)
  {
    return pLoader->KeepExt(SToS(ext));
  }
};