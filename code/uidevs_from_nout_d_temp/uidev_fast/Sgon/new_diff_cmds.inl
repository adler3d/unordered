class t_def_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(dev.isSave())
    {
      bool eq=p->BinIO->IsSame(dev.top.bef.pValue,dev.top.aft.pValue);
      if(!eq)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      ref.ok=true;
    }
  }
};

class t_new_cmdfunc:public i_cmdfunc{
public:
  void call(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TType*ptr)
  {
    if(dev.isSave())
    {
      if(!dev.isDebug())
      {
        TSimpleBinarySaver::toIO(IO,dev.top.aft);
        ref.ok=true;
        return;
      }
      ref.data=dev.toBinEx(dev.top.aft);
      ref.info=ref.data;
      IO.write_raw_string(ref.data);
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      auto&aft=dev.top.aft;
      ref.data.clear();
      TQapIOGrabber IOG(IO,ref.data);
      TSimpleBinaryLoader::fromStrEx(dev.isDebug()?IOG:IO,aft);
      ref.ok=true;
    }
  }
};

class t_vector_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeVector*p)
  {
    auto bc=p->VecAPI->GetCount(dev.top.bef.pValue);
    auto ac=p->VecAPI->GetCount(dev.top.aft.pValue);
    auto*pElemType=p->ElementType.get();
    if(dev.isSave())
    {
      if(bc!=ac)return;
      ref.DoReset();
      vector<t_cmd>&buff=ref.arr;
      buff.resize(ac);
      QapPolyScopeIO tmpIO(IO);
      for(int i=0;i<ac;i++)
      {
        auto&ex=buff[i];
        auto*pb=p->VecAPI->GetItem(dev.top.bef.pValue,i);
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        dev.top.set(pElemType,pb,pa);
        {
          QapPolyScopeIO curIO(tmpIO);
          dev.find_best_cmd(ex,curIO);
          weak_dev_save_cmdfunc(dev,tmpIO,ex.cmdfunc);
        }
        dev.pop(i);
      }
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      if(bc!=ac)return;
      vector<t_cmd>&buff=ref.arr;
      buff.resize(ac);
      //vector<TQapIO> IOs; IOs.resize(ac);
      for(int i=0;i<ac;i++)
      {
        auto&cmd=buff[i]; //auto&curIO=IOs[i];
        auto*pb=p->VecAPI->GetItem(dev.top.bef.pValue,i);
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        dev.top.set(pElemType,pb,pa);
        dev.load_cmdfunc(IO,cmd.cmdfunc);
        cmd.cmdfunc->main(dev,IO,cmd);
        dev.pop(i);
      }
      ref.ok=true;
    }
  }
};

class t_vector_resize_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeVector*p)
  {
    auto bc=p->VecAPI->GetCount(dev.top.bef.pValue);
    auto ac=p->VecAPI->GetCount(dev.top.aft.pValue);
    auto*pElemType=p->ElementType.get();
    vector<t_cmd>&buff=ref.arr;
    if(dev.isSave())
    {
      if(bc==ac)return;
      if(!bc)return;
      ref.DoReset();
      buff.resize(ac);
      QapPolyScopeIO tmpIO(IO);
      for(int i=0;i<ac;i++)
      {
        auto&ex=buff[i];
        auto*pb=p->VecAPI->GetItem(dev.top.bef.pValue,std::min<int>(bc-1,i));
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        dev.top.set(pElemType,pb,pa);
        {
          QapPolyScopeIO curIO(tmpIO);
          dev.find_best_cmd(ex,curIO);
          weak_dev_save_cmdfunc(dev,tmpIO,ex.cmdfunc);
        }
        dev.pop(i);
      }
      if(dev.isDebug())ref.info="size = int("+IToS(ac)+") also it is "+string(ac-bc>0?"+":"")+IToS(ac-bc);
      (dev.isDebug()?(QapIO&)TQapIOGrabber(IO,ref.data):IO).save(ac);
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      (dev.isDebug()?(QapIO&)TQapIOGrabber(IO,ref.data):IO).load(ac);
      QapAssert(ac>=0);
      p->VecAPI->SetCount(dev.top.aft.pValue,ac);
      buff.resize(ac);
      //vector<TQapIO> IOs; IOs.resize(ac);
      for(int i=0;i<ac;i++)
      {
        auto&cmd=buff[i]; //auto&curIO=IOs[i];
        auto*pb=p->VecAPI->GetItem(dev.top.bef.pValue,std::min<int>(bc-1,i));
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        qap_simple_clone_unsafe(pElemType,pa,pb);
        dev.top.set(pElemType,pb,pa);
        dev.load_cmdfunc(IO,cmd.cmdfunc);
        cmd.cmdfunc->main(dev,IO,cmd);
        dev.pop(i);
      }
      ref.ok=true;
    }
  }
};

class t_vector_resize_as_empty_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeVector*p)
  {
    auto bc=p->VecAPI->GetCount(dev.top.bef.pValue);
    auto ac=p->VecAPI->GetCount(dev.top.aft.pValue);
    auto*pElemType=p->ElementType.get();
    vector<t_cmd>&buff=ref.arr;
    if(dev.isSave())
    {
      if(bc>=ac)return;
      if(!bc)return;
      ref.DoReset();
      buff.resize(ac);
      QapPolyScopeIO tmpIO(IO);
      TAutoPtr<void> apv;auto*pempty=apv.unsafe_build(pElemType);
      for(int i=0;i<ac;i++)
      {
        auto&ex=buff[i];
        auto*pb=i<bc?p->VecAPI->GetItem(dev.top.bef.pValue,i):pempty;
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        dev.top.set(pElemType,pb,pa);
        {
          QapPolyScopeIO curIO(tmpIO);
          dev.find_best_cmd(ex,curIO);
          weak_dev_save_cmdfunc(dev,tmpIO,ex.cmdfunc);
        }
        dev.pop(i);
      }
      if(dev.isDebug())ref.info="size = int("+IToS(ac)+") also it is "+string(ac-bc>0?"+":"")+IToS(ac-bc);
      (dev.isDebug()?(QapIO&)TQapIOGrabber(IO,ref.data):IO).save(ac);
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      (dev.isDebug()?(QapIO&)TQapIOGrabber(IO,ref.data):IO).load(ac);
      QapAssert(ac>=0);
      p->VecAPI->SetCount(dev.top.aft.pValue,ac);
      buff.resize(ac);
      TAutoPtr<void> apv;auto*pempty=apv.unsafe_build(pElemType);
      for(int i=0;i<ac;i++)
      {
        auto&cmd=buff[i];
        auto*pb=i<bc?p->VecAPI->GetItem(dev.top.bef.pValue,i):pempty;
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        qap_simple_clone_unsafe(pElemType,pa,pb);
        dev.top.set(pElemType,pb,pa);
        dev.load_cmdfunc(IO,cmd.cmdfunc);
        cmd.cmdfunc->main(dev,IO,cmd);
        dev.pop(i);
      }
      ref.ok=true;
    }
  }
};

class t_vector_init_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeVector*p)
  {
    auto bc=p->VecAPI->GetCount(dev.top.bef.pValue);
    auto ac=p->VecAPI->GetCount(dev.top.aft.pValue);
    auto*pElemType=p->ElementType.get();
    vector<t_cmd>&buff=ref.arr;
    if(dev.isSave())
    {
      //if(bc)return;
      if(!ac)return;
      ref.DoReset();
      buff.resize(ac);
      QapPolyScopeIO tmpIO(IO);
      TAutoPtr<void> apv;auto*pempty=apv.unsafe_build(pElemType);
      for(int i=0;i<ac;i++)
      {
        auto&ex=buff[i];
        auto*pb=!i?pempty:p->VecAPI->GetItem(dev.top.aft.pValue,i-1);
        auto*pa=/*......*/p->VecAPI->GetItem(dev.top.aft.pValue,i-0);
        dev.push(i);
        dev.top.set(pElemType,pb,pa);
        {
          QapPolyScopeIO curIO(tmpIO);
          dev.find_best_cmd(ex,curIO);
          weak_dev_save_cmdfunc(dev,tmpIO,ex.cmdfunc);
        }
        dev.pop(i);
      }
      if(dev.isDebug())ref.info="size = "+IToS(ac);
      (dev.isDebug()?(QapIO&)TQapIOGrabber(IO,ref.data):IO).save(ac);
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      (dev.isDebug()?(QapIO&)TQapIOGrabber(IO,ref.data):IO).load(ac);
      QapAssert(ac>=0);
      p->VecAPI->SetCount(dev.top.aft.pValue,ac);
      buff.resize(ac);
      TAutoPtr<void> apv;auto*pempty=apv.unsafe_build(pElemType);
      for(int i=0;i<ac;i++)
      {
        auto&cmd=buff[i];
        auto*pb=!i?pempty:p->VecAPI->GetItem(dev.top.aft.pValue,i-1);
        auto*pa=/*......*/p->VecAPI->GetItem(dev.top.aft.pValue,i-0);
        dev.push(i);
        qap_simple_clone_unsafe(pElemType,pa,pb);
        dev.top.set(pElemType,pb,pa);
        dev.load_cmdfunc(IO,cmd.cmdfunc);
        cmd.cmdfunc->main(dev,IO,cmd);
        dev.pop(i);
      }
      ref.ok=true;
    }
  }
};

static real g_diff_time=0;
static int g_diff_n=0;

class t_vector_skip_n_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeVector*p)
  {
    auto bc=p->VecAPI->GetCount(dev.top.bef.pValue);
    auto ac=p->VecAPI->GetCount(dev.top.aft.pValue);
    auto*pElemType=p->ElementType.get();
    vector<t_cmd>&buff=ref.arr;
    vector<int> skip;
    if(dev.isSave())
    {
      if(!ac)return;
      if(ac>=bc)return;
      ref.DoReset();
      int need=bc-ac;
      int found=0; int offset=0;
      auto get_diff_size=[&](int id_a,int id_b)
      {
        TSizeIO SIO;
        TRawPtr b(pElemType,nullptr);
        TRawPtr a(pElemType,nullptr);
        b.pValue=p->VecAPI->GetItem(dev.top.bef.pValue,id_a);
        a.pValue=p->VecAPI->GetItem(dev.top.aft.pValue,id_b);
        QapClock clock;clock.Start();
        compute_diff_ex(dev.Env,SIO,b,a,false,dev.depth+1);
        clock.Stop();
        g_diff_time+=clock.MS();
        g_diff_n++;
        return SIO.GetSize();
      };
      for(int i=0;i<ac;i++)
      {
        auto a=get_diff_size(i+0+offset,i);
        auto b=get_diff_size(i+1+offset,i);
        if(a<b)continue;
        offset++;
        skip.push_back(i);
        need--;
        if(!need)break;
      }
      if(need>0)if(!skip.empty())
      {
        for(int i=0;i<need;i++)skip.push_back(ac+i);
        need=0;
      }
      buff.resize(ac);
      QapPolyScopeIO tmpIO(IO);
      TAutoPtr<void> apv;auto*pempty=apv.unsafe_build(pElemType);
      for(int i=0;i<ac;i++)
      {
        auto&ex=buff[i];
        for(int j=i;offset!=skip.size()&&skip[offset]==j;j++)offset++;
        auto*pb=p->VecAPI->GetItem(dev.top.bef.pValue,i+offset);
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        dev.top.set(pElemType,pb,pa);
        {
          QapPolyScopeIO curIO(tmpIO);
          dev.find_best_cmd(ex,curIO);
          weak_dev_save_cmdfunc(dev,tmpIO,ex.cmdfunc);
        }
        dev.pop(i);
      }
      if(dev.isDebug())
      {
        string&prefix=ref.info;
        {vector<string> a;a.resize(skip.size());for(int i=0;i<skip.size();i++)a[i]=IToS(skip[i]);prefix=join(a,",");}
      }
      (dev.isDebug()?(QapIO&)TQapIOGrabber(IO,ref.data):IO).save(skip);
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      (dev.isDebug()?(QapIO&)TQapIOGrabber(IO,ref.data):IO).load(skip);
      ac=bc-skip.size();
      QapAssert(ac>=0);
      p->VecAPI->SetCount(dev.top.aft.pValue,ac);
      buff.resize(ac);
      int offset=0;
      for(int i=0;i<ac;i++)
      {
        auto&cmd=buff[i];
        for(int j=i;offset!=skip.size()&&skip[offset]==j;j++)offset++;
        auto*pb=p->VecAPI->GetItem(dev.top.bef.pValue,i+offset);
        auto*pa=p->VecAPI->GetItem(dev.top.aft.pValue,i);
        dev.push(i);
        qap_simple_clone_unsafe(pElemType,pa,pb);
        dev.top.set(pElemType,pb,pa);
        dev.load_cmdfunc(IO,cmd.cmdfunc);
        cmd.cmdfunc->main(dev,IO,cmd);
        dev.pop(i);
      }
      ref.ok=true;
    }
  }
};

class t_struct_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeStruct*p)
  {
    if(p->SubType)return;
    auto&arr=p->Members;
    if(dev.isSave())
    {
      ref.DoReset();
      vector<t_cmd>&buff=ref.arr;
      buff.resize(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];auto&cmd=buff[i];
        dev.push(ex);
        {
          QapPolyScopeIO curIO(IO);
          dev.find_best_cmd(cmd,curIO);
          weak_dev_save_cmdfunc(dev,IO,cmd.cmdfunc);
        }
        dev.pop(ex);
      }
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      vector<t_cmd>&buff=ref.arr;
      buff.resize(arr.size());
      //vector<TQapIO> IOs; IOs.resize(arr.size());
      for(int i=0;i<arr.size();i++)
      {
        auto&ex=arr[i];
        auto&cmd=buff[i];
        dev.push(ex);
        dev.load_cmdfunc(IO,cmd.cmdfunc);
        cmd.cmdfunc->main(dev,IO,cmd);
        dev.pop(ex);
      }
      ref.ok=true;
    }
  }
};

class t_struct_short_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeStruct*p)
  {
    return;
    //if(p->SubType)return;
    //auto&arr=p->Members;
    //if(dev.isSave())
    //{
    //  ref.DoReset();
    //  vector<t_cmd>&buff=ref.arr;
    //  buff.resize(arr.size()); TQapIO tmpIO; string fi;
    //  for(int i=0;i<arr.size();i++)
    //  {
    //    auto&ex=arr[i];
    //    auto&out=buff[i];
    //    dev.push(ex);
    //    dev.find_best_cmd(out,tmpIO);
    //    auto c=dev.get_cmdfunc_id(out.cmdfunc);
    //    fi.push_back(c);
    //    dev.pop(ex);
    //  }
    //  char struct_patch_id=dev.get_struct_patch_id(p,fi);
    //  IO.save(struct_patch_id);
    //  save_string_without_size(IO,tmpIO.IO.mem);
    //  ref.ok=true;
    //}
    //if(dev.isLoad())
    //{
    //  vector<t_cmd>&buff=ref.arr;
    //  buff.resize(arr.size());
    //  //vector<TQapIO> IOs; IOs.resize(arr.size());
    //  for(int i=0;i<arr.size();i++)
    //  {
    //    auto&ex=arr[i];
    //    auto&cmd=buff[i];
    //    dev.push(ex);
    //    dev.load_cmdfunc(IO,cmd.cmdfunc);
    //    cmd.cmdfunc->main(dev,IO,cmd);
    //    dev.pop(ex);
    //  }
    //  ref.ok=true;
    //}
  }
  //void save(i_diff_dev&dev,QapIO&IO,t_cmd&ref)
  //{
  //  //dev.get_struct_patches
  //  save_string_without_size(IO,ref.data);
  //  string fi;ref.info="";
  //  for(int i=0;i<ref.arr.size();i++)
  //  {
  //    auto&ex=ref.arr[i];
  //    auto cfid=dev.get_cmdfunc_id(ex.cmdfunc);
  //    fi.push_back(cfid);ref.info+=(i?",":"")+IToS(cfid);
  //  }
  //  auto patch_id=dev.get_struct_patch_id(TTypeStruct::UberCast(ref.p),fi);
  //  ref.info="int("+IToS(patch_id)+") also fi = {"+ref.info+"}";
  //  IO.save(patch_id);
  //  for(int i=0;i<ref.arr.size();i++)
  //  {
  //    auto&ex=ref.arr[i];
  //    ex.cmdfunc->save(dev,IO,ex);
  //  }
  //  int gg=1;
  //}
};

template<class TYPE>
bool qap_bin_equal(TYPE&a,TYPE&b)
{
  int c=sizeof(TYPE);
  auto*pa=(char*)(void*)&a;
  auto*pb=(char*)(void*)&b;
  for(int i=0;i<c;i++)if(pa[i]!=pb[i])return false;
  return true;
}

class t_phys_move_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeStruct*p)
  {
    if(p->SubType)return;
    auto&arr=p->Members;
    if(dev.isSave())
    {
      ref.DoReset();
      if(arr.size()!=2)return;
      if(!is_same_type(arr[0],arr[1]))return;
      if(!is_vec2d(arr[0]))return;
      auto&bef=*(TGabobPhys*)dev.top.bef.pValue;
      auto&aft=*(TGabobPhys*)dev.top.aft.pValue;
      auto np=bef.pos+bef.v;
      bool ca=qap_bin_equal(np,aft.pos);
      bool cb=aft.v==bef.v;
      if(!ca||!cb)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      if(arr.size()!=2)return;
      if(!is_same_type(arr[0],arr[1]))return;
      if(!is_vec2d(arr[0]))return;
      auto&bef=*(TGabobPhys*)dev.top.bef.pValue;
      auto&aft=*(TGabobPhys*)dev.top.aft.pValue;
      aft.pos=bef.pos+bef.v;
      ref.ok=true;
    }
  }
};

class t_particle_move_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeStruct*p)
  {
    if(p->SubType)return;
    auto&arr=p->Members;
    if(dev.isSave())
    {
      ref.DoReset();
      if(arr.size()!=3)return;
      if(!is_same_type(arr[0],arr[1]))return;
      if(!is_vec2d(arr[0]))return;
      if(!is_real(arr[2]))return;
      auto&bef=*(TGabobParticle*)dev.top.bef.pValue;
      auto&aft=*(TGabobParticle*)dev.top.aft.pValue;
      auto np=bef.pos+bef.v;
      bool ca=qap_bin_equal(np,aft.pos);
      bool cb=aft.v==bef.v;
      bool cd=bef.t-1.0==aft.t;
      if(!ca||!cb||!cd)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      if(arr.size()!=3)return;
      if(!is_same_type(arr[0],arr[1]))return;
      if(!is_vec2d(arr[0]))return;
      if(!is_real(arr[2]))return;
      auto&bef=*(TGabobParticle*)dev.top.bef.pValue;
      auto&aft=*(TGabobParticle*)dev.top.aft.pValue;
      aft.pos=bef.pos+bef.v;
      aft.t=bef.t-1.0;
      ref.ok=true;
    }
  }
};

class t_particle_get_pos_from_parent_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeStruct*p)
  {
    if(p->SubType)return;
    if(dev.isSave())
    {
      ref.DoReset();
      if(!is_vec2d(p))return;
      auto back_id=int(dev.stack.size())-1;
      if(back_id<0)return;
      auto*pGabobParticle=TTypeStruct::UberCast(dev.stack[back_id].bef.pType);
      if(!pGabobParticle)return;
      auto&arr=pGabobParticle->Members;
      if(arr.size()!=3)return;
      if(!is_same_type(arr[0],arr[1]))return;
      if(!is_vec2d(arr[0]))return;
      if(!is_real(arr[2]))return;
      auto&bef=*(TGabobParticle*)dev.top.bef.pValue;
      auto&aft=*(TGabobParticle*)dev.top.aft.pValue;
      if(bef.pos==aft.pos)return;
      {
        auto id=int(dev.stack.size())-2;
        if(id<0)return;
        auto*pV=TTypeVector::UberCast(dev.stack[id].bef.pType);
        if(!pV)return;
      }
      {
        auto id=int(dev.stack.size())-3;
        if(id<0)return;
        auto*pS=TTypeStruct::UberCast(dev.stack[id].aft.pType);
        if(!pS)return;
        auto*mpos=pS->find_member("pos");
        if(!mpos)return;
        if(!is_vec2d(*mpos))return;
        auto&pb=*(vec2d*)mpos->getValue(dev.stack[id].bef.pValue);
        auto&pa=*(vec2d*)mpos->getValue(dev.stack[id].aft.pValue);
        if(pb==pa)return;
        if(pa!=aft.pos)return;
      }
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      if(!is_vec2d(p))return;
      auto back_id=int(dev.stack.size())-1;
      if(back_id<0)return;
      auto*pGabobParticle=TTypeStruct::UberCast(dev.stack[back_id].bef.pType);
      if(!pGabobParticle)return;
      auto&arr=pGabobParticle->Members;
      if(arr.size()!=3)return;
      if(!is_same_type(arr[0],arr[1]))return;
      if(!is_vec2d(arr[0]))return;
      if(!is_real(arr[2]))return;
      auto&bef=*(TGabobParticle*)dev.top.bef.pValue;
      auto&aft=*(TGabobParticle*)dev.top.aft.pValue;
      if(bef.pos!=aft.pos)return;
      {
        auto id=int(dev.stack.size())-2;
        if(id<0)return;
        auto*pV=TTypeVector::UberCast(dev.stack[id].bef.pType);
        if(!pV)return;
      }
      {
        auto id=int(dev.stack.size())-3;
        if(id<0)return;
        auto*pS=TTypeStruct::UberCast(dev.stack[id].aft.pType);
        if(!pS)return;
        auto*mpos=pS->find_member("pos");
        if(!mpos)return;
        if(!is_vec2d(*mpos))return;
        auto&pb=*(vec2d*)mpos->getValue(dev.stack[id].bef.pValue);
        auto&pa=*(vec2d*)mpos->getValue(dev.stack[id].aft.pValue);
        QapAssert(pb!=pa);
        aft.pos=pa;
      }
      ref.ok=true;
    }
  }
};