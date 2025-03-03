#pragma once
//-------------------------------------------//
//   {<| author : Adler3D(Kashin Ivan) |>}   //
//   {<| e-mail : Adler3D@gmail.com    |>}   //
//   {<| site   : Adler3d.narod.ru     |>}   //
//-------------------------------------------//
#define SAY(MSG)//MACRO_ADD_LOG(MSG,lml_EVENT);
//-------------------------------------------//
class CrutchIO{
public:
  static bool FileExist(const string&FN)
  {
    std::fstream f;
    f.open(FN.c_str(),std::ios::in|std::ios::binary);
    return f.is_open();
  }
private:
  static int FileLength(iostream&f)
  {
    using namespace std;
    f.seekg(0,ios::end);
    auto L=f.tellg();
    f.seekg(0,ios::beg);
    return int(L);
  };
public:
  int pos;
  string mem;
  CrutchIO():mem(""),pos(0){};
  bool LoadFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::in|ios::binary);
    if(!f)return false;
    int L=FileLength(f);
    mem.resize(L);
    if(L)f.read(&mem[0],L);
    //printf("f->size=%i\n",L);
    //printf("f->Chcount=%i\n",f._Chcount);
    f.close(); pos=0;
    SAY("'"+FN+"' : "+"["+IToS(L)+"]");
    return true;
  };
  bool SaveFile(const string&FN)
  {
    using namespace std;
    fstream f;
    f.open(FN.c_str(),ios::out|ios::binary);
    if(!f)return false;
    if(!mem.empty())f.write(&mem[0],mem.size());
    f.close(); pos=0; int L=mem.size();
    SAY("'"+FN+"' : "+"["+IToS(L)+"]");
    return true;
  };
  void read(char*c,int count)
  {
    for(int i=0;i<count;i++)c[i]=mem[pos++];//FIXME: ��� ����� ����� memcpy
  };
  void write(char*c,int count)
  {
    //mem.reserve(max(mem.capacity(),mem.size()+count));
    int n=mem.size();
    mem.resize(n+count);//Hint: resize ������������� �������� ����������.
    for(int i=0;i<count;i++)mem[n+i]=c[i];//FIXME: ��� ����� ����� memcpy
    pos+=count;
  };
};
//-------------------------------------------//
inline string file_get_contents(const string&fn){CrutchIO IO;IO.LoadFile(fn);return IO.mem;}
inline void file_put_contents(const string&fn,const string&data){CrutchIO IO;IO.mem=data;IO.SaveFile(fn);}
//-------------------------------------------//
#undef SAY
//-------------------------------------------//
//   {<|          03.06.2011           |>}   //
//-------------------------------------------//