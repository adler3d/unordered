#define DEF_PRO_HEAD
#include "StdAfx.h"
#undef DEF_PRO_HEAD
#define DEF_PRO_FULL

#include "t_error_tool.inl"
#include "QapLexer.inl"
#include "t_config.inl"
#include "t_poly_tool.inl"
#include "raw_cpp_lexem.inl"
#include "t_line_lexer.inl"

#include "t_branch_lexem.inl"

static int find_member_id(TTypeStruct*pS,const string&field)
{
  auto arr=qap_find(pS->Members,[&](TTypeStruct::Member&ex){return ex.Name==field;});
  if(arr.empty())return -1;
  if(arr.size()>1){QapDebugMsg("found "+IToS(arr.size())+" member with name:\n"+field);return -1;}
  return arr[0];
}

struct t_exec_optimization_stat_info{
  int total=0;
  int prod_type=0;
  int elem_type=0;
  int find_type=0;
  int find_type_ok=0;
  static t_exec_optimization_stat_info&get()
  {
    static t_exec_optimization_stat_info info;
    return info;
  }
};

static t_booksys_exec_result booksys_branch_exec_impl
(
  IEnvRTTI&Env,TSuperOutDevice&dev,
  TRawPtr&raw_ptr,
  t_branch_lexem::t_var_expr&branch,
  vector<TAutoPtr<TOutDev::DevCmd>>&way
)
{
  t_booksys_exec_result fail={false};
  auto&arr=branch.arr;
  QapAssert(!arr[0].ext);
  auto root_item=arr[0].name;
  if(!raw_ptr.pValue){return fail;}
  for(int i=1;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if(t_branch_lexem::t_hard::UberCast(ex.ext.get())||!ex.ext)
    {
      auto*ptr=TTypeStruct::UberCast(raw_ptr.pType);
      QapAssert(ptr);
      if(!ptr)return fail;
      auto*pfield=ptr->find_member_full(ex.name);
      if(!pfield)return fail;
      auto&field=*pfield;
      raw_ptr.pType=field.Type.get();
      raw_ptr.pValue=field.getValue(raw_ptr.pValue);
      {
        auto member_id=find_member_id(ptr,ex.name);
        QapAssert(member_id>=0);
        qap_add_back(way).build<TOutDev::TMemberID>(Env)->id=member_id;
      }
      if(!ex.ext)continue;
      auto*pext=t_branch_lexem::t_hard::UberCast(ex.ext.get());
      QapAssert(pext);QapAssert(pext->arr.size()==1);
      auto v=SToI(pext->arr[0].value);
      //ex.name1
      auto*ptv=TTypeVector::UberCast(raw_ptr.pType);
      raw_ptr.pType=ptv->ElementType.get();
      auto count=ptv->VecAPI->GetCount(raw_ptr.pValue);
      if(v>=count)return fail;
      raw_ptr.pValue=ptv->VecAPI->GetItem(raw_ptr.pValue,v);
      qap_add_back(way).build<TOutDev::TVecID>(Env)->id=v;
    }
    if(t_branch_lexem::t_soft::UberCast(ex.ext.get()))
    {
      auto*pext=t_branch_lexem::t_soft::UberCast(ex.ext.get());
      QapAssert(pext);
      if(ex.name=="get")
      {
        auto*pta=TTypeAutoPtr::UberCast(raw_ptr.pType);
        QapAssert(pta);
        if(!pext->templ)
        {
          QapDebugMsg("no way");return fail;
          //auto&raw_ap=*(TAutoPtr<void>*)raw_ptr.pValue;
          //raw_ptr.pType=pta->ElementType.get();
          //raw_ptr.pValue=raw_ap.get();
          //continue;
        }
        auto tn=pext->templ->name;
        {
          auto&raw_ap=*(TAutoPtr<void>*)raw_ptr.pValue;
          if(!raw_ap)return fail;
          static auto&stat_info=t_exec_optimization_stat_info::get();
          stat_info.total++;
          auto pProductType=raw_ap.Product.pType.get();
          auto pProductType_fn=pProductType->GetFullName();
          TType*p=nullptr;
          if(pProductType_fn==tn)
          {
            p=pProductType;
            stat_info.prod_type++;
          }
          auto pta_et=pta->ElementType.get();
          if(!p)if(pta_et->GetFullName()==tn)
          {
            p=pta_et;
            stat_info.elem_type++;
          }
          if(!p)
          {
            stat_info.find_type++;
            auto*pt=Env.FindTypeByName_is_ug_but_work(tn);
            if(!pt)return fail;
            auto*pProductType=raw_ap.Product.pType.get();
            bool ok=pProductType->IsBasedOn(p);
            if(!ok)return fail;
            p=pt;
            stat_info.find_type_ok++;
          }
          if(!p)return fail;
          raw_ptr.pType=p;
          raw_ptr.pValue=raw_ap.get();
          qap_add_back(way).build<TOutDev::TChunk>(Env);
        }
        continue;
      }
      QapDebugMsg("WTF?\n"+ex.name);return fail;
    }
    int gg=1;
  }
  t_booksys_exec_result ok={true};
  ok.ptr=raw_ptr;
  return ok;
}

t_booksys_exec_result booksys_branch_exec_v00
(
  IEnvRTTI&Env,TSuperOutDevice&dev,
  TRawPtr&raw_ptr,
  const string&branch_str,
  vector<TAutoPtr<TOutDev::DevCmd>>&way
){
  t_booksys_exec_result fail={false};
  t_branch_lexem::t_var_expr branch;
  auto res=load_obj_full(Env,branch,branch_str);
  if(!res.ok)return fail;
  auto a=booksys_branch_exec_impl(Env,dev,raw_ptr,branch,way);
  if(!a.ok)return fail;
  if(!a.ptr.IsValid())return fail;
  return a;
}

struct t_exec_result{
  bool ok;
  TRawPtr ptr;
};

static t_exec_result branch_exec_ext(const t_branch_lexem::t_item&ex,TRawPtr&raw_ptr)
{
  t_exec_result fail={false};
  auto*pext=t_branch_lexem::t_hard::UberCast(ex.ext.get());
  QapAssert(pext);QapAssert(pext->arr.size()==1);
  auto v=SToI(pext->arr[0].value);
  auto*ptv=TTypeVector::UberCast(raw_ptr.pType);
  if(!ptv)return fail;
  raw_ptr.pType=ptv->ElementType.get();
  auto count=ptv->VecAPI->GetCount(raw_ptr.pValue);
  if(v<0||v>=count)return fail;
  raw_ptr.pValue=ptv->VecAPI->GetItem(raw_ptr.pValue,v);
  return {true,raw_ptr};
}

static t_exec_result branch_exec(IEnvRTTI&Env,vector<t_branch_head_ptr>&ptrs,const t_branch_lexem::t_var_expr&branch,bool readonly,int&temp_int)
{
  t_exec_result fail={false};
  auto&arr=branch.arr;
  auto root_item=arr[0].name;
  TRawPtr raw_ptr;
  auto list=qap_find(ptrs,[&](t_branch_head_ptr&ex){return ex.name==root_item;});
  if(list.size()!=1){
    QapDebugMsg("found "+IToS(list.size())+" root_item`s with name:\n"+root_item);
    return fail;
  }
  raw_ptr=ptrs[list[0]].raw_ptr;
  if(!raw_ptr.pValue){return fail;}
  if(arr[0].ext)
  {
    auto subres=branch_exec_ext(arr[0],raw_ptr);
    if(!subres.ok)return fail;
  }
  for(int i=1;i<arr.size();i++)
  {
    auto&ex=arr[i];
    if(t_branch_lexem::t_hard::UberCast(ex.ext.get())||!ex.ext)
    {
      auto*ptr=TTypeStruct::UberCast(raw_ptr.pType);
      QapAssert(ptr);
      if(!ptr)return fail;
      auto*pfield=ptr->find_member_full(ex.name);
      if(!pfield)return fail;
      auto&field=*pfield;
      raw_ptr.pType=field.Type.get();
      raw_ptr.pValue=field.getValue(raw_ptr.pValue);
      if(!ex.ext)continue;
      auto subres=branch_exec_ext(ex,raw_ptr);
      if(!subres.ok)return fail;
    }
    if(t_branch_lexem::t_soft::UberCast(ex.ext.get()))
    {
      auto*pext=t_branch_lexem::t_soft::UberCast(ex.ext.get());
      QapAssert(pext);
      if(ex.name=="get")
      {
        auto*pta=TTypeAutoPtr::UberCast(raw_ptr.pType);
        QapAssert(pta);
        if(!pext->templ){
          auto&raw_ap=*(TAutoPtr<void>*)raw_ptr.pValue;
          raw_ptr.pType=pta->ElementType.get();
          raw_ptr.pValue=raw_ap.get();
          continue;
        }
        auto tn=pext->templ->name;
        {
          auto&raw_ap=*(TAutoPtr<void>*)raw_ptr.pValue;
          if(!raw_ap)return fail;
          static auto&stat_info=t_exec_optimization_stat_info::get();
          stat_info.total++;
          auto pProductType=raw_ap.Product.pType.get();
          auto pProductType_fn=pProductType->GetFullName();
          TType*p=nullptr;
          if(pProductType_fn==tn)
          {
            p=pProductType;
            stat_info.prod_type++;
          }
          auto pta_et=pta->ElementType.get();
          if(!p)if(pta_et->GetFullName()==tn)
          {
            p=pta_et;
            stat_info.elem_type++;
          }
          if(!p)
          {
            stat_info.find_type++;
            auto*pt=Env.FindTypeByName_is_ug_but_work(tn);
            if(!pt)return fail;
            auto*pProductType=raw_ap.Product.pType.get();
            bool ok=pProductType->IsBasedOn(p);
            if(!ok)return fail;
            p=pt;
            stat_info.find_type_ok++;
          }
          if(!p)return fail;
          raw_ptr.pType=p;
          raw_ptr.pValue=raw_ap.get();
        }
        continue;
      }
      if(ex.name=="build")if(!readonly)
      {
        QapAssert(pext->templ);
        auto*pta=TTypeAutoPtr::UberCast(raw_ptr.pType);
        QapAssert(pta);
        auto&types=Env.GetArr();
        auto tn=pext->templ->name;
        {
          auto&arr=qap_find(types,[&](EnvType&ex){return ex.Type->GetFullName()==tn;});
          if(!arr.empty())
          {
            int id=arr[0];
            auto&t=types[id].Type;
            auto*p=TTypeStruct::UberCast(t.get());
            QapAssert(p);
            QapAssert(p->IsBasedOn(pta->ElementType.get()));
            auto&raw_ap=*(TAutoPtr<void>*)raw_ptr.pValue;
            raw_ap.unsafe_build(p);
            raw_ptr.pType=p;
            raw_ptr.pValue=raw_ap.get();
          }
        }
        continue;
      }
      if(ex.name=="clear")if(!readonly)
      {
        QapAssert(!pext->templ);
        auto*ptv=TTypeVector::UberCast(raw_ptr.pType);
        QapAssert(ptv);
        ptv->VecAPI->SetCount(raw_ptr.pValue,0);
        QapAssert(i+1==arr.size());break;
        /*
        raw_ptr.pType=ptv->ElementType.get();
        raw_ptr.pValue=*/
      }
      if(ex.name=="size")//if(readonly)
      {
        QapAssert(!pext->templ);
        auto*ptv=TTypeVector::UberCast(raw_ptr.pType);
        QapAssert(ptv);
        temp_int=ptv->VecAPI->GetCount(raw_ptr.pValue);
        raw_ptr.pType=ptv->SizeType.get();
        raw_ptr.pValue=&temp_int;
        continue;
      }
      if(ex.name=="emplace_back")if(!readonly)
      {
        QapAssert(!pext->templ);
        auto*ptv=TTypeVector::UberCast(raw_ptr.pType);
        QapAssert(ptv);
        auto count=ptv->VecAPI->GetCount(raw_ptr.pValue);
        ptv->VecAPI->SetCount(raw_ptr.pValue,count+1);
        QapAssert(i+1==arr.size());break;
        /*
        raw_ptr.pType=ptv->ElementType.get();
        raw_ptr.pValue=*/
      }
      if(ex.name=="pop_back")if(!readonly)
      {
        QapAssert(!pext->templ);
        auto*ptv=TTypeVector::UberCast(raw_ptr.pType);
        if(!ptv)
        {
          QapAssert(ptv);
          break;
        }
        auto count=ptv->VecAPI->GetCount(raw_ptr.pValue);
        if(!count)
        {
          QapDebugMsg("no way.\nvector<"+ptv->GetFullName()+"> is empty.");
          QapAssert(i+1==arr.size());
          break;
        }
        ptv->VecAPI->SetCount(raw_ptr.pValue,count-1);
        QapAssert(i+1==arr.size());break;
        /*
        raw_ptr.pType=ptv->ElementType.get();
        raw_ptr.pValue=*/
      }
      if(ex.name=="back")
      {
        QapAssert(!pext->templ);
        auto*ptv=TTypeVector::UberCast(raw_ptr.pType);
        QapAssert(ptv);
        auto count=ptv->VecAPI->GetCount(raw_ptr.pValue);
        if(!count)
        {
          QapAssert(count);
          break;
        }
        raw_ptr.pType=ptv->ElementType.get();
        raw_ptr.pValue=ptv->VecAPI->GetItem(raw_ptr.pValue,count-1);
        continue;
      }
      if(ex.name=="front")
      {
        QapAssert(!pext->templ);
        auto*ptv=TTypeVector::UberCast(raw_ptr.pType);
        QapAssert(ptv);
        auto count=ptv->VecAPI->GetCount(raw_ptr.pValue);
        if(!count)
        {
          QapAssert(count);
          break;
        }
        raw_ptr.pType=ptv->ElementType.get();
        raw_ptr.pValue=ptv->VecAPI->GetItem(raw_ptr.pValue,0);
        continue;
      }
      QapDebugMsg("WTF?\n"+ex.name);
    }
    int gg=1;
  }
  t_exec_result ok={true};
  ok.ptr=raw_ptr;
  return ok;
}

static bool unsafe_QapClone(IEnvRTTI&Env,const TRawPtr&dest,const TRawPtr&source){
  bool ok=QapPublicUberFullCloneBinMem(Env,TQapRawObject(dest),TQapRawObject(source));
  return ok;
}

class t_branch_lex_v3_menu_tool{
public:
  typedef IBookPage::t_context t_context;
public:
  static string str_add_space_to_end(const string&s,int max_v){
    string out=s;
    size_t size=std::max<int>(0,max_v-s.size());
    return s+string(size,' ');
  }
  static bool add_members_to_buff_arr(IEnvRTTI&Env,TType*pType,void*pValue,vector<string>&buff_arr)
  {
    auto*ps=TTypeStruct::UberCast(pType);
    auto*pv=TTypeVector::UberCast(pType);
    auto*pa=TTypeAutoPtr::UberCast(pType);
    auto*py=TTypeSys::UberCast(pType);
    if(ps)return add_members_to_buff_arr(Env,ps,pValue,buff_arr);
    if(pv)return add_members_to_buff_arr(Env,pv,pValue,buff_arr);
    if(pa)return add_members_to_buff_arr(Env,pa,pValue,buff_arr);
    if(py)return add_members_to_buff_arr(Env,py,pValue,buff_arr);
    return false;
    //if(!pt){buff_arr.push_back("["+pStruct->GetFullName()+"] - this is not struct");return false;}
  }
  static string to128(const string&text){
    int n=128;
    if(text.size()<=n)return text;
    return text.substr(0,n)+"...";
  }
  static bool add_members_to_buff_arr(IEnvRTTI&Env,TTypeSys*pType,void*pValue,vector<string>&buff_arr)
  {
    string text;
    pType->TxtIO->Save(text,pValue);
    string s=to128(text);
    buff_arr.push_back(pType->GetFullName()+"("+s+")");
    return true;
  }
  static bool add_members_to_buff_arr(IEnvRTTI&Env,TTypeVector*pType,void*pValue,vector<string>&buff_arr)
  {
    auto*pElemType=pType->ElementType.get();
    auto et=pElemType->GetFullName();
    auto max_v=std::max<int>(et.size(),4)+4;
    int count=pType->VecAPI->GetCount(pValue);
    string fv="...";
    string bv="...";
    if(count)if(TTypeSys::UberCast(pElemType))
    {
      auto*pes=TTypeSys::UberCast(pElemType);
      auto*pfvalue=pType->VecAPI->GetItem(pValue,0);
      auto*pbvalue=pType->VecAPI->GetItem(pValue,count-1);
      fv.clear();bv.clear();
      pes->TxtIO->Save(fv,pfvalue);
      pes->TxtIO->Save(bv,pbvalue);
    }
    if(!count){fv="...empty...";bv=fv;}
    buff_arr.push_back("emplace_back() = procedure");
    buff_arr.push_back("pop_back()     = procedure");
    buff_arr.push_back("front()        = "+et+"("+fv+")");
    buff_arr.push_back("back()         = "+et+"("+bv+")");
    buff_arr.push_back("size()         = int("+IToS(count)+")");
    buff_arr.push_back("clear()        = procedure");
    return true;
  }
  static bool add_members_to_buff_arr(IEnvRTTI&Env,TTypeAutoPtr*pType,void*pValue,vector<string>&buff_arr)
  {
    auto*pElemType=pType->ElementType.get();
    auto&ap=*(TAutoPtr<void>*)pValue;
    string method="get";
    if(!ap)method="build";
    if(ap)
    {
      auto aptfn=ap.Product.pType->GetFullName();
      buff_arr.push_back(method+"{"+aptfn+"}()");
    }
    buff_arr.push_back(method+"()");
    buff_arr.push_back(method+"{"+pElemType->GetFullName()+"}()");
    qap_foreach
    (
      Env.GetArr(),
      [&](EnvType&ex)
      {
        auto*pt=ex.Type.get();
        if(!pt)return;
        if(!pt->IsBasedOn(pElemType))return;
        buff_arr.push_back(method+"{"+pt->GetFullName()+"}()");
      }
    );
    return true;
  }
  static bool add_members_to_buff_arr(IEnvRTTI&Env,TTypeStruct*p,void*pValue,vector<string>&buff_arr)
  {
    if(p->SubType)
    {
      auto*psub=p->SubType.get();
      if(!add_members_to_buff_arr(Env,psub,pValue,buff_arr))return false;
    }
    auto&arr=p->Members;
    int max_v=-1;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      max_v=std::max(max_v,int(ex.Type->GetFullName().size()));
    }
    max_v+=4;
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pft=ex.Type.get();
      auto tfn=pft->GetFullName();
      string s=str_add_space_to_end(tfn,max_v);
      string value="...";
      if(TTypeSys::UberCast(pft)){value.clear();TTypeSys::UberCast(pft)->TxtIO->Save(value,ex.getValue(pValue));}
      value=to128(value);
      buff_arr.push_back(ex.Name+" = "+tfn+"("+value+")");
    }
    return true;
  }
  static bool MakeMenuForLineEx(t_context&con,const string&line,vector<t_branch_head_ptr>&ptrs,vector<string>&buff_arr,TTextSelector&menu)
  {
    typedef t_branch_lexem::t_var_expr t_branch;
    if(line.empty())return false;
    if(line.back()!='?')return false;
    buff_arr.clear();menu.Lines.clear();
    t_branch branch;
    auto s=line;
    if(!s.empty()&&s.back()=='?')s.pop_back();
    if(!s.empty()&&s.back()=='.')s.pop_back();
    auto res_a=load_obj_full(con.Env,branch,s);
    if(!res_a.ok)return false;
    int temp_int;
    t_exec_result a;
    a=branch_exec(con.Env,ptrs,branch,true,temp_int);
    if(!a.ok)return false;
    if(!a.ptr.IsValid())return true;
    bool result=add_members_to_buff_arr(con.Env,a.ptr.pType,a.ptr.pValue,buff_arr);
    if(result)
    {
      vector<string> out;
      int n=-1;
      auto&arr=buff_arr;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto a=split(ex," = ");
        if(a.empty())continue;
        auto name=a.front();
        n=std::max<int>(n,name.size());
      }
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto a=split(ex," = ");
        if(a.size()==1)continue;
        a[0]=str_add_space_to_end(a[0],n);
        ex=join(a," = ");
      }
      menu.Lines=buff_arr;
    }
    return result;
  }
};

bool qap_public_MakeMenuForLineEx(IBookPage::t_context&con,const string&line,vector<t_branch_head_ptr>&ptrs,vector<string>&buff_arr,TTextSelector&menu)
{
  return t_branch_lex_v3_menu_tool::MakeMenuForLineEx(con,line,ptrs,buff_arr,menu);
}

class TPageWithBranchLexV03:public IBookPage{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TPageWithBranchLexV03)PARENT(IBookPage)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(bool,run,DEF,$,$)\
ADDVAR(bool,auto_run,DEF,$,$)\
ADDVAR(bool,wait_mbLeftUp,DEF,$,$)\
ADDVAR(vector<string>,buff_arr,DEF,$,$)\
ADDVAR(TTextEditor,editor,DEF,$,$)\
ADDVAR(TRawRectAndMenuItems,menu,DEF,$,$)\
ADDEND()
//=====+>>>>>TPageWithBranchLexV03
#include "QapGenStruct.inl"
//<<<<<+=====TPageWithBranchLexV03
public:
  void Render(t_context&con)
  {
    editor.Render(con);
    menu.Render(con);
  }
  bool SysKeyHandler(t_context&con)
  {
    if(!con.is_hovered())return false;
    auto&kb=con.kb;
    auto ctrl_down=kb.Down[VK_CONTROL];
    if(ctrl_down&&kb.OnDown(VK_RETURN))
    {
      run=true;
      return true;
    }
    if(menu.Enabled)if(kb.OnDown(mbLeft))
    {
      int gg=1;
      if(con.make_sub_context(menu.rect).is_hovered())
      {
        int gg=1;wait_mbLeftUp=true;
        return true;
      }
    }
    if(ctrl_down&&kb.OnDown(VK_BACK))
    {
      auto dpos=editor.text.rfind('.',editor.caret_pos);
      if(!dpos)return true;
      if(string::npos==dpos)return true;
      //dpos--:
      auto&text=editor.text; auto&p=editor.caret_pos;auto&s=editor.sel_caret_pos;
      text=text.substr(0,dpos)+text.substr(p);
      p=dpos;s=dpos;
      return true;
    }
    return false;
  }
  static string unsafe_get_curBranchAsStr(t_context&con,int start_id=0)
  {
    return con.GetCurBranchAsStr(con.context.dev.branch.top.pValue,start_id);
  }
  typedef t_branch_lexem::t_alias_from_func_call t_alias_func_call;
  static TRawPtr make_raw_ptr_for_cbrft(t_context&con,const t_alias_func_call&afc,vector<TAutoPtr<void>>&vars)
  {
    TRawPtr fail;
    if(afc.func!="cbrft")return fail; //current_branch_reverse_find_type = cbrft
    auto&context=con.context;
    t_str_item::t_impl impl;
    auto res=load_obj_full(con.Env,impl,afc.str_param);
    QapAssert(res.ok);
    auto type=impl.get_value();
    if(type.empty())return fail;
    bool without_ug=con.Env.GetArr().size()>context.dev.branch.size();
    if(!without_ug){QapDebugMsg("ORLY?\nok. ignore it.");}
    if(without_ug)
    {
      auto&arr=context.dev.branch;
      if(arr.empty()){QapNoWay();return fail;}
      for(int i=int(arr.size())-1;i>=0;i--)
      {
        auto&ax=arr[i];
        auto ax_fn=ax.pType->GetFullName();
        if(ax_fn!=type)continue;
        return TRawPtr(ax.pType,ax.pValue);
      }
    }else{
      auto*pType=con.Env.FindTypeByName_is_ug_but_work(type);
      auto&arr=context.dev.branch;
      if(arr.empty()){QapNoWay();return fail;}
      for(int i=int(arr.size())-1;i>=0;i--)
      {
        auto&ax=arr[i];
        if(ax.pType!=pType)continue;
        return TRawPtr(ax.pType,ax.pValue);
      }
    }
    string msg="cbrft not found this type on current branch.\nbranch:\n"+unsafe_get_curBranchAsStr(con)+"\n\ntype:\n"+afc.str_param;
    QapDebugMsg(msg);
    return fail;
  }
  static TRawPtr make_raw_ptr_for_toBlob(t_context&con,const t_alias_func_call&afc,vector<TAutoPtr<void>>&vars)
  {
    TRawPtr fail;
    if(afc.func!="toBlob")return fail;
    auto&context=con.context;
    t_str_item::t_impl impl;
    auto res=load_obj_full(con.Env,impl,afc.str_param);
    QapAssert(res.ok);
    auto param=impl.get_value();
    auto&a=qap_add_back(vars);
    a.unsafe_build(Sys$$<string>::GetRTTI(con.Env));
    string&s=*(string*)a.get();
    TDataIO IO;
    IO.save(param);
    s=IO.IO.mem;
    return TRawPtr(a);
  }
  static TRawPtr make_raw_ptr(t_context&con,const t_alias_func_call&afc,vector<TAutoPtr<void>>&vars)
  {
    TRawPtr fail;
    #define LIST(F)F(cbrft)F(toBlob)
    #define F(FUNC){if(afc.func==#FUNC)return make_raw_ptr_for_##FUNC(con,afc,vars);}
    LIST(F)
    #undef F
    vector<string> funcs;
    #define F(FUNC){qap_add_back(funcs)=#FUNC;}
    LIST(F)
    #undef F
    #undef LIST
    auto msg="function not found:\n  "+afc.func+"\n\nlist of supported functions:\n  "+join(funcs,"\n  ");
    QapDebugMsg(msg);
    return fail;
  }
  class t_alias_visitor:public t_branch_lexem::i_alias_visitor{
  public:
    class t_dev{
    public:
      t_context&con;
      //const string&line;
      vector<t_branch_head_ptr>&ptrs;
      vector<TAutoPtr<void>>&vars;
      bool ok;
    };
    t_dev&dev;
    t_alias_visitor(t_dev&dev):dev(dev){}
  public:
    void Do(t_alias_from_func_call*p)
    {
      dev.ok=false;
      TRawPtr raw_ptr=make_raw_ptr(dev.con,*p,dev.vars);
      if(!raw_ptr.IsValid()){QapNoWay();return;}
      auto&back=qap_add_back(dev.ptrs);
      back.name=p->alias;
      back.raw_ptr=raw_ptr;
      dev.ok=true;
    }
    void Do(t_alias_from_var_expr*p)
    {
      dev.ok=false;
      t_exec_result a; int temp_int;
      a=branch_exec(dev.con.Env,dev.ptrs,p->var_expr,true,temp_int);
      if(!a.ok)return;
      if(!a.ptr.IsValid()){QapNoWay();return;}
      auto&back=qap_add_back(dev.ptrs);
      back.name=p->alias;
      back.raw_ptr=a.ptr;
      dev.ok=true;
    }
  };
  static bool add_alias_form_ast(t_context&con,TAutoPtr<t_branch_lexem::i_alias>&alias,vector<t_branch_head_ptr>&ptrs,vector<TAutoPtr<void>>&vars)
  {
    QapAssert(alias);
    //string line;auto ok=save_obj(con.Env,alias,line);QapAssert(ok);
    t_alias_visitor::t_dev dev={
      con,ptrs,vars,false
    };
    t_alias_visitor av(dev);
    auto*pas=alias.get();
    pas->Use(av);
    QapAssert(dev.ok);
    return dev.ok;
  }
  static bool add_alias_from_line(t_context&con,const string&line,vector<t_branch_head_ptr>&ptrs,vector<TAutoPtr<void>>&vars)
  {
    TAutoPtr<t_branch_lexem::i_alias> alias;
    auto res=load_obj_full(con.Env,alias,line);
    if(!res.ok){QapDebugMsg(res.msg);return false;}
    return add_alias_form_ast(con,alias,ptrs,vars);
  }
  vector<t_branch_head_ptr> get_ptrs(t_context&con)
  {
    auto&path=con.path;
    auto*pprev_book=&con.book;
    auto ps=path.size();
    if(!ps)pprev_book=nullptr;
    if(ps)
    {
      if(path.back()!=&con.book)pprev_book=path.back();
      if(path.back()==&con.book)pprev_book=ps>1?path[ps-2]:nullptr;
    }
    vector<t_branch_head_ptr> ptrs;
    #define F(NAME,VAR){auto&back=qap_add_back(ptrs);back.name=NAME;back.raw_ptr.set(con.Env,VAR);}
    F("root",con.root);
    if(pprev_book)F("prevbook",*pprev_book);
    F("book",con.book);
    F("self",*this);
    #undef F
    return ptrs;
  }
  void UpdateMenu(t_context&con)
  {
    if(!menu.Enabled)return;
    if(!con.is_hovered())return;
    auto&kb=con.kb;
    auto ctrl_down=kb.Down[VK_CONTROL];
    if(kb.OnDown(VK_OEM_PERIOD)||(ctrl_down&&kb.OnDown(mbRight)))
    {
      auto&text=editor.text; auto caret_pos=editor.caret_pos;
      if(caret_pos<=0)return;
      auto sol=text.rfind('\n',caret_pos-1);
      if(string::npos==sol){sol=0;}else{sol++;}
      auto line=text.substr(sol,caret_pos-sol);
      if(line.find("\"")!=line.find("="))return;
      line+="?";
      vector<TAutoPtr<void>> vars;
      auto ptrs=get_ptrs(con);
      auto lines=split(text,"\n");
      int car_pos_y=editor.car_pos.y;
      car_pos_y=std::max<int>(0,std::min<int>(car_pos_y,lines.size()));
      for(int i=0;i<car_pos_y;i++)
      {
        auto&ex=lines[i];
        bool flag=is_first_part_of(ex,"auto ");
        if(!flag)continue;
        bool ok=add_alias_from_line(con,ex,ptrs,vars);
        if(!ok){QapDebugMsg("error when attempt to create alias:\n"+ex);return;}
      }
      bool ok=t_branch_lex_v3_menu_tool::MakeMenuForLineEx(con,line,ptrs,buff_arr,menu.selector);
      QapAssert(ok);
      return;
    }
  }
  bool CheckMenuSelector(t_context&con)
  {
    if(!menu.selector.OnDown)return false;
    wait_mbLeftUp=true;
    if(!editor.caret_pos)return true;
    menu.selector.OnDown=false;
    auto selected=menu.selector.Lines[menu.selector.SelectId];
    auto arr=split(selected," = ");
    if(arr.empty())return true;
    auto name=split(arr[0]," ").front();
    editor.insert_string(con,name);
    return true;
  }
  void Update(t_context&con)
  {
    if(Caption.empty()){Caption="BranchLexTest";editor.text="node.arr.emplace_back()";editor.border=8;}
    menu.Update(con);
    bool in_menu=CheckMenuSelector(con);
    bool skh=SysKeyHandler(con);
    if(wait_mbLeftUp)wait_mbLeftUp=con.kb.Down[mbLeft];
    if(!skh&&!in_menu&&!wait_mbLeftUp)
    {
      editor.Update(con);
    }
    UpdateMenu(con);
    if(run||auto_run)Run(con);
  }
  void Run(t_context&con)
  {
    vector<TAutoPtr<void>> vars;
    auto ptrs=get_ptrs(con);
    run=false;
    auto lines=split(editor.text,"\n");
    for(int i=0;i<lines.size();i++)
    {
      auto&line=lines[i];
      bool flag=is_first_part_of(line,"auto ");
      if(flag)
      {
        auto ok=add_alias_from_line(con,line,ptrs,vars);
        if(!ok)return;
        continue;
      }
      auto ok=ExecLineEx(con,line,ptrs);
      if(!ok)return;
    }
  }
  static bool ExecLineEx(t_context&con,const string&line,vector<t_branch_head_ptr>&ptrs)
  {
    typedef t_branch_lexem::t_var_expr t_branch;
    if(line.empty())return false;
    t_branch branch_a;
    t_branch branch_b;
    auto arr=split(line,"=");
    if(arr.empty())return false;
    auto res_a=load_obj_full(con.Env,branch_a,arr[0]);
    if(!res_a.ok)return false;
    int temp_int_a;int temp_int_b;
    t_exec_result a;
    t_exec_result b;
    a=branch_exec(con.Env,ptrs,branch_a,false,temp_int_a);
    if(arr.size()==1)
    {
      return a.ok;
    }
    QapPopFront(arr);
    string arr1=join(arr,"=");
    auto res_b=load_obj_full(con.Env,branch_b,arr1);
    if(!res_b.ok&&a.ok&&a.ptr.pValue&&a.ptr.pType->GetFullName()=="bool"){
      #define F(CONST)if(#CONST==arr1){*(bool*)a.ptr.pValue=CONST;return true;}
      F(false)F(true)F(0)F(1)
      #undef F
      QapDebugMsg("WTF?\n"+arr1);
      return false;
    }
    if(!res_b.ok&&a.ok&&a.ptr.pValue&&a.ptr.pType->GetFullName()=="int"){
      bool have_sign=is_first_part_of(arr1,"-")||is_first_part_of(arr1,"+");
      int sign=+1;
      if(have_sign)
      {
        if(arr1[0]=='-')sign=-1;
        if(arr1[0]=='+')sign=+1;
        arr1=arr1.substr(1);
      }
      const static CharMask mask("0123456789");
      bool ok=mask.check(arr1);
      if(ok)
      {
        *(int*)a.ptr.pValue=sign*SToI(arr1);
        return true;
      }
      return false;
    }
    if(!res_b.ok&&a.ok&&a.ptr.pValue&&a.ptr.pType->GetFullName()=="real"){
      bool have_sign=is_first_part_of(arr1,"-")||is_first_part_of(arr1,"+");
      int sign=+1;
      if(have_sign)
      {
        if(arr1[0]=='-')sign=-1;
        if(arr1[0]=='+')sign=+1;
        arr1=arr1.substr(1);
      }
      const static CharMask mask("0123456789");
      bool ok=mask.check(arr1);
      if(ok)
      {
        *(real*)a.ptr.pValue=sign*SToI(arr1);
        return true;
      }
      return false;
    }
    if(!res_b.ok&&a.ok&&a.ptr.pValue&&a.ptr.pType->GetFullName()=="char"){
      const static CharMask mask("0123456789");
      bool ok=mask.check(arr1);
      if(ok)
      {
        *(char*)a.ptr.pValue=SToI(arr1);
        return true;
      }
    }
    if(!res_b.ok&&a.ok&&a.ptr.pValue&&a.ptr.pType->GetFullName()=="uchar"){
      const static CharMask mask("0123456789");
      bool ok=mask.check(arr1);
      if(ok)
      {
        *(uchar*)a.ptr.pValue=SToI(arr1);
        return true;
      }
    }
    if(!res_b.ok&&a.ok&&a.ptr.pValue&&a.ptr.pType->GetFullName()=="string"){
      t_str_item::t_impl str_impl;
      auto res_b=load_obj_full(con.Env,str_impl,arr1);
      if(res_b.ok)
      {
        auto&value=*(string*)a.ptr.pValue;
        value=str_impl.get_value();
        return true;
      }
    }
    if(!res_b.ok&&a.ok&&a.ptr.pValue&&a.ptr.pType->GetFullName()=="QapColor")if(is_first_part_of(arr1,"0x")){
      auto v=without_first_part(arr1,"0x");
      static const CharMask mask("0123456789abcdefABCDEF");
      bool ok=mask.check(v);
      if(ok)
      {
        *(QapColor*)a.ptr.pValue=HToI_raw(v);
        return true;
      }
    }
    if(!res_b.ok)return false;
    b=branch_exec(con.Env,ptrs,branch_b,true,temp_int_b);
    QapAssert(a.ok&&b.ok);
    if(!a.ok||!b.ok)return false;
    auto the_same_types=a.ptr.pType==b.ptr.pType;
    if(!the_same_types)
    {
      string msg=(
        "end types of expression not equal:\n"
        "bef.type:\n  "
        +a.ptr.pType->GetFullName()+"\n\n"
        "aft.type:\n  "
        +b.ptr.pType->GetFullName()+"\n\n"
        "in this code line:\n  "+
        line
      );
      QapDebugMsg(msg);
      return false;
    }
    if(the_same_types)
    {
      auto a_type=a.ptr.pType->GetFullName();
      #define F(TYPE)if(a_type==#TYPE){*(TYPE*)a.ptr.pValue=*(TYPE*)b.ptr.pValue;return true;}
      F(int)F(string)F(bool)F(real)F(char)F(uchar)F(QapColor)
      #undef F
    }
    auto ok=unsafe_QapClone(con.Env,a.ptr,b.ptr);
    QapAssert(ok);
    int gg=1;
    return true;
  }
};

bool qap_public_add_alias_from_line(IBookPage::t_context&con,const string&line,vector<t_branch_head_ptr>&ptrs,vector<TAutoPtr<void>>&vars)
{
  return TPageWithBranchLexV03::add_alias_from_line(con,line,ptrs,vars);
}

bool ExecBranchScript(IBookPage::t_context&con,const string&code,vector<t_branch_head_ptr>&ptrs,vector<TAutoPtr<void>>&vars)
{
  auto lines=split(code,"\n");
  for(int i=0;i<lines.size();i++)
  {
    auto&line=lines[i];
    bool flag=is_first_part_of(line,"auto ");
    if(flag)
    {
      auto ok=TPageWithBranchLexV03::add_alias_from_line(con,line,ptrs,vars);
      if(!ok)return false;
      continue;
    }
    auto ok=TPageWithBranchLexV03::ExecLineEx(con,line,ptrs);
    if(!ok)return false;
  }
  return true;
}

template<class RET_TYPE,class TYPE>
RET_TYPE*UberGet(TAutoPtr<TYPE>&ref)
{
  auto*ptr=ref.get();
  if(!ptr)return nullptr;
  return RET_TYPE::UberCast(ptr);
}

#include "IScriptAST.inl"

class TScriptAST:public IScriptAST{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TScriptAST)PARENT(IScriptAST)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,source,DEF,$,$)\
ADDVAR(t_branch_lexem,body,DEF,$,$)\
ADDEND()
//=====+>>>>>TScriptAST
#include "QapGenStruct.inl"
//<<<<<+=====TScriptAST
public:
  #define F(TYPE)typedef t_branch_lexem::TYPE TYPE;
  F(i_case);
  F(i_expr);
  F(i_alias);
  F(i_oper);
  F(i_line);
  F(t_hex_number);
  F(t_bool);
  F(t_number);
  F(t_hard_barckets);
  F(t_hard);
  F(t_template);
  F(t_soft);
  F(t_item);
  F(t_var_expr);
  F(t_string_expr);
  F(t_num_expr);
  F(t_hexnum_expr);
  F(t_bool_expr);
  F(t_alias_from_func_call);
  F(t_alias_from_var_expr);
  F(t_set_oper);
  F(t_inc_oper);
  F(t_dec_oper);
  F(t_oper);
  F(t_alias);
  F(t_line);
  F(i_line_visitor);
  F(i_oper_visitor);
  F(i_expr_visitor);
  #undef F
public:
  class t_line_visitor:public i_line_visitor,public i_oper_visitor,public i_expr_visitor{
  public:
    t_context&con;
    vector<t_branch_head_ptr>&ptrs;
    t_line*pline;
    bool ok;
    vector<TAutoPtr<void>> vars;
    t_line_visitor(t_context&con,vector<t_branch_head_ptr>&ptrs):con(con),ptrs(ptrs),pline(nullptr),ok(false){}
  public:
    //t_line_visitor
  public:
    void Do(t_alias*p)
    {
      ok=TPageWithBranchLexV03::add_alias_form_ast(con,p->body,ptrs,vars);
    }
    void Do(t_line*p)
    {
      if(!p->opt)
      {
        int temp_int_a=0;int temp_int_b=0;
        auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
        if(!a.ok)return;
      }
      if(!p->opt){ok=true;return;}
      pline=p;
      auto*popt=p->opt.get();
      popt->value->Use(*this);
    }
  public:
    //t_oper_visitor
  public:
    void Do(t_set_oper*p)
    {
      p->value->Use(*this);
    }
    void Do(t_inc_oper*p)
    {
      DoIncDec(pline,+1);
    }
    void Do(t_dec_oper*p)
    {
      DoIncDec(pline,-1);
    }
    void DoIncDec(t_line*p,int dv)
    {
      int temp_int_a=0;int temp_int_b=0;
      auto a=branch_exec(con.Env,ptrs,p->bef,false,temp_int_a);
      if(!a.ok)return;
      //check
      {
        auto*a_type_factory=a.ptr.pType->Factory.get();
        #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){auto&v=*(TYPE*)a.ptr.pValue;v+=dv;ok=true;return;}
        F(int)F(real)F(char)F(uchar)
        #undef F
      }
      ok=false;
    }
  public:
    //t_expr_visitor
  public:
    void Do(t_hexnum_expr*p)
    {
      int temp_int_a=0;int temp_int_b=0;
      auto a=branch_exec(con.Env,ptrs,pline->bef,false,temp_int_a);
      if(!a.ok)return;
      auto v=HToI(p->value);
      auto*a_type_factory=a.ptr.pType->Factory.get();
      #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){*(TYPE*)a.ptr.pValue=TYPE(v);ok=true;return;}
      F(uint)F(int)F(bool)F(real)F(char)F(uchar)F(QapColor)
      #undef F
      // fail
      {
        string line;
        bool ok=save_obj(con.Env,*p,line);
        QapAssert(ok);
        string msg=(
          "attempt to set 'uint' into '"+a.ptr.pType->GetFullName()+"' failed:\n"
          "in this line of code:\n  "+
          line
        );
        QapDebugMsg(msg);
      }
      ok=false;
    }
    void Do(t_bool_expr*p)
    {
      int temp_int_a=0;int temp_int_b=0;
      auto a=branch_exec(con.Env,ptrs,pline->bef,false,temp_int_a);
      if(!a.ok)return;
      auto v=SToB(p->value);
      auto*a_type_factory=a.ptr.pType->Factory.get();
      #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){*(TYPE*)a.ptr.pValue=TYPE(v);ok=true;return;}
      F(bool)
      #undef F
      // fail
      {
        string line;
        bool ok=save_obj(con.Env,*p,line);
        QapAssert(ok);
        string msg=(
          "attempt to set 'bool' into '"+a.ptr.pType->GetFullName()+"' failed:\n"
          "in this line of code:\n  "+
          line
        );
        QapDebugMsg(msg);
      }
      ok=false;
    }
    void Do(t_num_expr*p)
    {
      int temp_int_a=0;int temp_int_b=0;
      auto a=branch_exec(con.Env,ptrs,pline->bef,false,temp_int_a);
      if(!a.ok)return;
      auto v=SToI(p->value);
      auto*a_type_factory=a.ptr.pType->Factory.get();
      #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){*(TYPE*)a.ptr.pValue=TYPE(v);ok=true;return;}
      F(uint)F(int)F(bool)F(real)F(char)F(uchar)F(QapColor)
      #undef F
      // fail
      {
        string line;
        bool ok=save_obj(con.Env,*p,line);
        QapAssert(ok);
        string msg=(
          "attempt to set 'int' into '"+a.ptr.pType->GetFullName()+"' failed:\n"
          "in this line of code:\n  "+
          line
        );
        QapDebugMsg(msg);
      }
      ok=false;
    }
    void Do(t_var_expr*p)
    {
      int temp_int_a=0;int temp_int_b=0;
      auto a=branch_exec(con.Env,ptrs,pline->bef,false,temp_int_a);
      if(!a.ok)return;
      auto b=branch_exec(con.Env,ptrs,*p,false,temp_int_b);
      if(!b.ok)return;
      QapAssert(a.ok&&b.ok);
      if(!a.ok||!b.ok)return;
      auto the_same_types=a.ptr.pType==b.ptr.pType;
      if(!the_same_types)
      {
        string line;
        bool ok=save_obj(con.Env,*pline,line);
        QapAssert(ok);
        string msg=(
          "end types of expression not equal:\n"
          "bef.type:\n  "
          +a.ptr.pType->GetFullName()+"\n\n"
          "aft.type:\n  "
          +b.ptr.pType->GetFullName()+"\n\n"
          "in this line of code:\n  "+
          line
        );
        QapDebugMsg(msg);
        return;
      }
      if(the_same_types)
      {
        auto*a_type_factory=a.ptr.pType->Factory.get();
        #define F(TYPE)if(a_type_factory==TFactory<TYPE>::Get()){*(TYPE*)a.ptr.pValue=*(TYPE*)b.ptr.pValue;ok=true;return;}
        F(int)F(string)F(bool)F(real)F(char)F(uchar)F(QapColor)
        #undef F
      }
      auto ok=unsafe_QapClone(con.Env,a.ptr,b.ptr);
      QapAssert(ok);
      int gg=1;
      ok=true;
    }
    void Do(t_string_expr*p)
    {
      int temp_int_a=0;int temp_int_b=0;
      auto a=branch_exec(con.Env,ptrs,pline->bef,false,temp_int_a);
      if(!a.ok)return;
      t_str_item::t_impl str_impl;
      auto res_b=load_obj_full(con.Env,str_impl,p->value);
      if(res_b.ok)
      {
        auto&value=*(string*)a.ptr.pValue;
        value=str_impl.get_value();
        ok=true;
        return;
      }
      // fail
      {
        string line;
        bool ok=save_obj(con.Env,*p,line);
        QapAssert(ok);
        string msg=(
          "attempt to set 'string' into '"+a.ptr.pType->GetFullName()+"' failed:\n"
          "in this line of code:\n  "+
          line
        );
        QapDebugMsg(msg);
      }
      ok=false;
    }
  };
  bool check_source(const string&ref){return ref==this->source;}
  t_exec_result exec(t_context&con,vector<t_branch_head_ptr>&ptrs)
  {
    t_exec_result tmp;
    auto&arr=body.lines;
    t_line_visitor V{con,ptrs};
    for(int i=0;i<arr.size();i++)
    {
      auto&ex=arr[i];
      auto*pline=ex.get();
      pline->Use(V);
      if(V.ok)continue;
      tmp.msg="exec fail on line id:\n"+IToS(i);
      break;
    }
    tmp.ok=V.ok;
    return tmp;
  }
};

void build_branch_script_ast(IEnvRTTI&Env,TAutoPtr<IScriptAST>&out,const string&code)
{
  TScriptAST ast;
  ast.source=code;
  auto res=load_obj_full(Env,ast.body,code);
  if(!res.ok)return;
  auto*pout=out.build<TScriptAST>(Env);
  *pout=std::move(ast);
}

namespace
{
  struct ThisCompileUnit:public ICompileUnit
  {
    const char*get_filename()const
    {
      return __FILE__;
    }
    virtual void RegAll(IEnvRTTI&Env)
    {
      #define F(CLASS){Sys$$<CLASS>::GetRTTI(Env);};;
      #define LIST(F)\
        F(TType)F(TPageWithBranchLexV03)F(TScriptAST)
      //===+>>>LIST
      LIST(F);
      //<<<+===LIST
      #undef LIST
      #undef F
    }
    void Run(IEnvRTTI&Env)
    {
    }
    ThisCompileUnit()
    {
    }
  };
  ThisCompileUnit ThisCompileUnitInstance;
}