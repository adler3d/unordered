
class t_new_cmdfunc:public i_cmdfunc{
public:
  void call(i_diff_dev&dev,TType*ptr)
  {
    if(dev.isSave())
    {
      dev.out.data=dev.toBinEx(dev.top.aft);
      dev.out.info=dev.out.data;
      dev.ret();
    }
    if(dev.isLoad())
    {
      auto&aft=dev.top.aft;
      TSimpleBinaryLoader::fromStrEx(dev.out.data,aft.pType,aft.pValue);
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_def_cmdfunc:public i_cmdfunc{
public:
  void call(i_diff_dev&dev,TType*ptr)
  {
    if(dev.isSave())
    {
      if(dev.toBinEx(dev.top.bef)!=dev.toBinEx(dev.top.aft))return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_int_add_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef+1)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=bef+1;
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_int_dec_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef-1)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=bef-1;
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_real_dec_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef-1.0)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=bef-1.0;
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_real_add_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef+1.0)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=bef+1.0;
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_int_zero_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=0)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=0;
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_int_one_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=1)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=1;
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_real_zero_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=0.0)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=0;
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_real_one_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=1.0)return;
      dev.ret();
    }
    if(dev.isLoad())
    {
      aft=1.0;
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_struct_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeStruct*p)
  {
    if(p->SubType)return;
    auto&arr=p->Members;
    if(dev.isSave())
    {
      vector<t_cmd> buff;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        dev.push(ex);
        dev.find_best_cmd();
        dev.pop(ex);
        qap_add_back(buff)=std::move(dev.out);
      }
      dev.out.DoReset();
      dev.out.arr=std::move(buff);
      dev.ret();
    }
    if(dev.isLoad())
    {
      QapNoWay();
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        dev.push(ex);
        //dev.apply_cmd();
        dev.pop(ex);
      }
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

class t_struct_short_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeStruct*p)
  {
    if(p->SubType)return;
    auto&arr=p->Members;
    if(dev.isSave())
    {
      vector<t_cmd> buff;
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        dev.push(ex);
        dev.find_best_cmd();
        dev.pop(ex);
        qap_add_back(buff)=std::move(dev.out);
      }
      dev.out.DoReset();
      dev.out.arr=std::move(buff);
      dev.ret();
    }
    if(dev.isLoad())
    {
      QapNoWay();
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        dev.push(ex);
        //dev.apply_cmd();
        dev.pop(ex);
      }
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref)
  {
    //dev.get_struct_patches
    save_string_without_size(IO,ref.data);
    string fi;ref.info="";
    for(int i=0;i<ref.arr.size();i++)
    {
      auto&ex=ref.arr[i];
      auto cfid=dev.get_cmdfunc_id(ex.cmdfunc);
      fi.push_back(cfid);ref.info+=(i?",":"")+IToS(cfid);
    }
    auto patch_id=dev.get_struct_patch_id(TTypeStruct::UberCast(ref.p),fi);
    ref.info="int("+IToS(patch_id)+") also fi = {"+ref.info+"}";
    IO.save(patch_id);
    for(int i=0;i<ref.arr.size();i++)
    {
      auto&ex=ref.arr[i];
      ex.cmdfunc->save(dev,IO,ex);
    }
    int gg=1;
  }
};

class t_vector_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,TTypeVector*p)
  {
    auto bc=p->VecAPI->GetCount(dev.top.bef.pValue);
    auto ac=p->VecAPI->GetCount(dev.top.aft.pValue);
    auto*pElemType=p->ElementType.get();
    if(dev.isSave())
    {
      if(bc!=ac)return;
      vector<t_cmd> buff;
      for(int i=0;i<bc;i++)
      {
        auto*pb=p->VecAPI->GetItem(dev.top.bef.pValue,i);
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        dev.top.bef.pType=pElemType;
        dev.top.aft.pType=pElemType;
        dev.top.bef.pValue=pb;
        dev.top.aft.pValue=pa;
        dev.find_best_cmd();
        dev.pop(i);
        qap_add_back(buff)=std::move(dev.out);
      }
      dev.out.DoReset();
      dev.out.arr=std::move(buff);
      dev.ret();
    }
    if(dev.isLoad())
    {
      for(int i=0;i<ac;i++)
      {
        auto*pb=p->VecAPI->GetItem(dev.top.bef.pValue,i);
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        dev.top.bef.pType=pElemType;
        dev.top.aft.pType=pElemType;
        dev.top.bef.pValue=pb;
        dev.top.aft.pValue=pa;
        dev.load_from_top();
        dev.pop(i);
      }
      dev.ret();
    }
  }
  void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref){def_save(dev,IO,ref);}
};

//     go  ->    save  -> load   ->  go
// obj -> t_cmd   ->   IO  ->  t_cmd -> obj