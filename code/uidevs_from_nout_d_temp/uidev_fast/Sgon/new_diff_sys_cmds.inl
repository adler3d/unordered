class t_int_add_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef+1)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=bef+1;
      ref.ok=true;
    }
  }
};

class t_int_dec_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef-1)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=bef-1;
      ref.ok=true;
    }
  }
};

class t_int_zero_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=0)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=0;
      ref.ok=true;
    }
  }
};

class t_int_one_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=1)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=1;
      ref.ok=true;
    }
  }
};

class t_int_as_byte_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_int(p))return;
    auto&bef=get_int(dev.top.bef);
    auto&aft=get_int(dev.top.aft);
    if(dev.isSave())
    {
      if(int(char(aft))!=aft)return;
      char c=aft;
      if(dev.isDebug()){ref.data=CToS(c);ref.info=IToS(c);}
      IO.save(c);
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      char c;
      IO.load(c);
      if(dev.isDebug()){ref.data=CToS(c);ref.info=IToS(c);}
      aft=c;
      ref.ok=true;
    }
  }
};

class t_real_dec_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef-1.0)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=bef-1.0;
      ref.ok=true;
    }
  }
};

class t_real_add_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=bef+1.0)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=bef+1.0;
      ref.ok=true;
    }
  }
};

class t_real_zero_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=0.0)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=0;
      ref.ok=true;
    }
  }
};

class t_real_one_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(aft!=1.0)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=1.0;
      ref.ok=true;
    }
  }
};

class t_real_as_byte_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(real(char(aft))!=aft)return;
      char c=aft;
      if(dev.isDebug()){ref.data=CToS(c);ref.info=IToS(c);}
      IO.save(c);
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      char c;
      IO.load(c);
      if(dev.isDebug()){ref.data=CToS(c);ref.info=IToS(c);}
      aft=c;
      ref.ok=true;
    }
  }
};

class t_real_inv_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_real(p))return;
    auto&bef=get_real(dev.top.bef);
    auto&aft=get_real(dev.top.aft);
    if(dev.isSave())
    {
      if(bef!=-aft)return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft=-bef;
      ref.ok=true;
    }
  }
};

class t_string_empty_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_string(p))return;
    auto&bef=get_string(dev.top.bef);
    auto&aft=get_string(dev.top.aft);
    if(dev.isSave())
    {
      if(!aft.empty())return;
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      aft.clear();
      ref.ok=true;
    }
  }
};

class t_string_short_cmdfunc:public i_cmdfunc{
public:
  void go(i_diff_dev&dev,QapIO&IO,t_cmd&ref,TTypeSys*p)
  {
    if(!is_string(p))return;
    auto&bef=get_string(dev.top.bef);
    auto&aft=get_string(dev.top.aft);
    if(dev.isSave())
    {
      if(aft.size()>255)return;
      if(aft==bef)return;
      unsigned char c=aft.size();
      IO.save(c);
      IO.write_raw_string(aft);
      if(dev.isDebug()){ref.data=CToS(c)+aft;ref.info="size = int("+IToS(c)+") s = "+aft;}
      ref.ok=true;
    }
    if(dev.isLoad())
    {
      unsigned char c=0;
      IO.load(c);
      aft.resize(c);
      if(c)IO.LoadPOD(&aft[0],c);
      if(dev.isDebug()){ref.data=CToS(c)+aft;ref.info="size = int("+IToS(c)+") s = "+aft;}
      ref.ok=true;
    }
  }
};