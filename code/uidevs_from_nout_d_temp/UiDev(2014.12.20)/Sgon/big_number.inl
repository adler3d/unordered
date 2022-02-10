#pragma once

template<class TYPE>
TYPE reverse(const TYPE&a)
{
  TYPE tmp;
  int c=a.size();
  tmp.resize(c);
  for(int i=0;i<c;i++)tmp[c-i-1]=a[i];
  return std::move(tmp);
}

struct big_number
{
  typedef unsigned short int elem_type;
  typedef unsigned int long_type;
  static_assert(sizeof(long_type)==sizeof(elem_type)<<1,"bad long_type or elem_type");
  static_assert(std::is_unsigned<long_type>::value,"bad long_type");
  static_assert(std::is_unsigned<elem_type>::value,"bad elem_type");
public:
  vector<elem_type> data;
public:
  big_number(){}
public:
  big_number(const string&a){oper_set(a);}
  big_number(long_type a){oper_set(a);}
  big_number(const big_number&ref){oper_set(ref);}
  big_number(big_number&&ref){oper_set(std::move(ref));}
public:
  void operator=(const string&a){oper_set(a);}
  void operator=(long_type a){oper_set(a);}
  void operator=(const big_number&ref){oper_set(ref);}
  void operator=(big_number&&ref){oper_set(std::move(ref));}
public:
  void oper_set(const big_number&ref)
  {
    data=ref.data;
  }
  void oper_set(big_number&&ref)
  {
    data=std::move(ref.data);
  }
  void oper_set(long_type a)
  {
    union{long_type v;elem_type a[2];} tmp={a};
    //tmp.v=a;
    data.resize(2);
    data[0]=tmp.a[0];
    data[1]=tmp.a[1];
    repack();
  }
  bool load_code(const string&a)
  {
    const Extractor::Gripper tag("{","}");
    const Extractor::Gripper tag2("(",")");
    const Extractor::Gripper next("",",");
    Extractor big_extractor(a);
    auto tmp=big_extractor.extract(tag);
    if(!big_extractor)return false;
    Extractor big_extractor2(tmp);
    auto tmp2=big_extractor2.extract(tag2);
    if(big_extractor2)tmp=tmp2;
    data.clear();
    tmp+=",";
    Extractor e(tmp);
    for(;;)
    {
      string str_num=e.extract(next);
      if(!e)break;
      long_type num=SToI(str_num);
      data.push_back(num);
      QapAssert(num==data.back());
    }
    return true;
  }
  void oper_set(const string&a)
  {
    if(load_code(a))return;
    data.clear();
    big_number base=1;
    big_number bn10=10;
    for(int i=a.size();i>0;i--)
    {
      int t=a[i-1]-'0';
      big_number v=t;
      v*=base;
      *this+=v;
      base*=bn10;
    }
  }
  static int64&get_mul_count(){static int64 tmp=0; return tmp;}
  static big_number mul_slow(const big_number&a,const big_number&b)
  {
    get_mul_count()++;
    static bool flag_skip_all=true;
    vector<big_number>*pArr=0;
    if(!flag_skip_all)
    {
    vector<big_number> arr;
      pArr=&arr;
    }
    big_number tmp;
    tmp.data.reserve(a.data.size()+b.data.size());
    //const long_type base=1<<sizeof(elem_type)*8;
    big_number v;
    v.data.reserve(a.data.size()+b.data.size());
    for(int i=0;i<a.data.size();i++)
    {
      long_type ai=a.data[i];
      for(int j=0;j<b.data.size();j++)
      {
        long_type bj=b.data[j];
        long_type val=ai*bj;
        v.data.clear();
        v.data.resize(i+j+2);
        union{elem_type&h;long_type&v;} x={v.data[i+j]};
        x.v=val;
        //v.repack();
        tmp+=v;
        if(!flag_skip_all)pArr->push_back(v);
      }
    }
    if(!flag_skip_all)
    {
      flag_skip_all=true;
      string out_debug_string;
      for(int i=0;i<pArr->size();i++)out_debug_string+=(*pArr)[i].toString()+"\n";
      flag_skip_all=false;
    }
    tmp.repack();
    //string str_a=a.toString();
    //string str_b=b.toString();
    //string str_t=tmp.toString();
    return std::move(tmp);
  }
  static big_number mul(const big_number&a,const big_number&b)
  {
    return std::move(mul_slow(a,b));
    big_number tmp;
    tmp.data.resize(a.data.size()+b.data.size());
    const long_type max_out=1<<sizeof(elem_type)*8;
    for(int i=0;i<a.data.size();i++)
    {
      long_type ai=a.data[i];
      for(int j=0;j<b.data.size();j++)
      {
        long_type bj=b.data[j];
        long_type val=ai*bj;
        QapAssert(i+j!=tmp.data.size());
        auto&out=tmp.data[i+j];
        auto old=out;
        if(val>=max_out)
        {
          continue;
        }
        out+=val;
        if(out<old)
        {
          //overflow
          
          continue;
        }
      }
    }
    tmp.repack();
    //string str_a=a.toString();
    //string str_b=b.toString();
    //string str_t=tmp.toString();
    return std::move(tmp);
  }
  static big_number div(const big_number&Numerator,elem_type Denominator)
  {
    auto&a=Numerator.data;
    auto b=Denominator;
    long_type m=0;
    big_number r;
    long_type base=1<<sizeof(a[0])*8;
    for(int i=a.size();i>0;i--)
    {
      int index=i-1;
      m*=base;
      m+=a[index];
      if(m<Denominator)
      {
        if(!r.data.empty())r.data.push_back(0);
        continue;
      }
      r.data.push_back(m/Denominator);
      m=m%Denominator;
    }
    r.data=std::move(reverse(r.data));
    r.repack();
    return std::move(r);
  }
  static elem_type mod(const big_number&Numerator,elem_type Denominator)
  {
    auto&a=Numerator.data;
    auto b=Denominator;
    long_type m=0;
    long_type base=1<<sizeof(elem_type)*8;
    for(int i=a.size();i>0;i--)
    {
      int index=i-1;
      m*=base;
      m+=a[index];
      m=m%Denominator;
    }
    return m;
  }
  static long_type get_dword(const big_number&number,int id)
  {
    QapAssert(id+1<number.data.size());
    union{const elem_type&h;const long_type&v;} tmp={number.data[id]};
    return tmp.v;
  }
  static int get_index_first_nozero_symbol(const big_number&number)
  {
    auto&arr=number.data;
    QapAssert(!arr.empty());
    for(int i=arr.size();i>0;i--)
    {
      int index=i-1;
      if(arr[index]){
        return index;
      }
    }
    return -1;
  }
  static bool has_first_nozero_symbol(const big_number&number)
  {
    return 
      !number.data.empty()
      &&
      (number.data.size()==(1+get_index_first_nozero_symbol(number)));
  }
  static big_number div(const big_number&Numerator,const big_number&Denominator)
  {
    QapAssert(has_first_nozero_symbol(Denominator));
    QapAssert(has_first_nozero_symbol(Numerator));
    auto&a=Numerator.data;
    auto&b=Denominator.data;
    big_number tmp;
    if(a.size()<b.size())
    {
      tmp.data.push_back(0);
      return std::move(tmp);
    }
    big_number m;
    big_number r;
    big_number base=1<<sizeof(elem_type)*8;
    const long_type elem_max_value=(1<<sizeof(elem_type)*8)-1;
    for(int i=a.size();i>0;i--)
    {
      int index=i-1;
      m*=base;
      m+=a[index];
      if(m<Denominator)
      {
        if(!r.data.empty())r.data.push_back(0);
        continue;
      }
      long_type v=0;
      long_type d=0;
      if(true)do
      {
        if(m.data.size()>Denominator.data.size())
        {
          int md_one=m.data.size()-Denominator.data.size();
          QapAssert(md_one==1);
          QapAssert(m.data.size()>1);
          int id=m.data.size()-2;
          v=get_dword(m,id);
          int Denominator_back_id=Denominator.data.size()-1;
          QapAssert(Denominator_back_id==id);
          d=b.back();
          break;
        }
        if(m.data.size()==Denominator.data.size())
        {
          int mid=get_index_first_nozero_symbol(m);
          int did=get_index_first_nozero_symbol(Denominator);
          int id=min(mid,did);
          QapAssert(did<=mid);
          QapAssert(did==mid);
          if(!id){
            v=m.data[id];
            d=Denominator.data[id];
          }else{
            id--;  
            v=get_dword(m,id);
            d=get_dword(Denominator,id);
          }
          break;
        }
        QapAssert(false);
      }while(false);
      long_type c=v/d;
      QapAssert(c>0);
      if(c>elem_max_value)c=elem_max_value;
      big_number C=Denominator*c;
      for(int loop_count=0;;loop_count++)
      {
        if(C<=m)
        {
          if(loop_count>2)printf("dec_count = %i\n",loop_count);
          break;
        }
        auto diff=C-m;
        auto dC=diff/Denominator;
        QapAssert(dC.data.size()<=1);
        auto dc=dC.empty()?0:dC.data.back();
        if(!dc)dc++;
        QapAssert(c>dc);
        c-=dc;
        C=Denominator*c;
      }
      QapAssert(C<=m);
      QapAssert(C==Denominator*c);
      big_number M=m-C;
      //string str_m=m.toString();
      //string str_C=C.toString();
      //string str_M=M.toString();
      //string str_D=Denominator.toString();
      //string str_Diff=(Denominator-M).toString();
      QapAssert(M<Denominator);
      r.data.push_back(c);
      QapAssert(c<=elem_max_value);
      m=std::move(M);
    }
    tmp.data=std::move(reverse(r.data));
    tmp.repack();
    return std::move(tmp);
  }
  bool operator<(const big_number&ref)const
  {
    int max_size=max(ref.data.size(),data.size());
    const auto SafeGet=[](const big_number&a,int index)->elem_type{
      return index<a.data.size()?a.data[index]:0;
    };
    for(int i=max_size;i>0;i--)
    {
      int index=i-1;
      auto a=SafeGet(*this,index);
      auto b=SafeGet(ref,index);
      if(a!=b)return a<b;
    }
    return false;
  }
  bool operator<=(const big_number&ref)const
  {
    int max_size=max(ref.data.size(),data.size());
    const auto SafeGet=[](const big_number&a,int index)->elem_type{
      return index<a.data.size()?a.data[index]:0;
    };
    for(int i=max_size;i>0;i--)
    {
      int index=i-1;
      auto a=SafeGet(*this,index);
      auto b=SafeGet(ref,index);
      if(a!=b)return a<=b;
    }
    return true;
  }
  bool operator>(const big_number&ref)const
  {
    return ref<*this;
  }
  bool operator==(const big_number&ref)const
  {
    int max_size=max(ref.data.size(),data.size());
    const auto SafeGet=[](const big_number&a,int index)->elem_type{
      return index<a.data.size()?a.data[index]:0;
    };
    for(int i=max_size;i>0;i--)
    {
      int index=i-1;
      auto a=SafeGet(*this,index);
      auto b=SafeGet(ref,index);
      if(a!=b)return false;
    }
    return true;
  }
  static int64&get_shl_count(){static int64 tmp=0; return tmp;}
  void operator<<=(long_type count)
  {
    get_shl_count()++;
    int limit=(sizeof(elem_type)*8);
    int add_count=count/limit;
    int shr=count%limit;
    int shl=limit-count%limit;
    elem_type n=0;
    for(int i=0;i<data.size();i++)
    {
      elem_type d=data[i];
      data[i]=elem_type(d<<shr)+n;
      n=d>>shl;
    }
    if(n)data.push_back(n);
    if(!add_count)return;
    auto old=std::move(data);
    data.resize(add_count+old.size());
    for(int i=0;i<add_count;i++)data[i]=0;
    for(int i=0;i<old.size();i++)data[add_count+i]=old[i];
    //repack();
  }
  static int64&get_shr_count(){static int64 tmp=0; return tmp;}
  void operator>>=(long_type count)
  {
    get_shr_count()++;
    int limit=(sizeof(elem_type)*8);
    int del_count=count/limit;
    int shl=count%limit;
    int shr=limit-count%limit;
    if(del_count)
    {
      for(int i=del_count;i<data.size();i++)
      {
        data[i-del_count]=data[i];
      }
      int new_size=std::max<int>(0,int(data.size())-del_count);
      data.resize(new_size);
    }
    elem_type n=0;
    for(int i=data.size();i>0;i--)
    {
      int index=i-1;
      elem_type d=data[index];
      data[index]=elem_type(d>>shl)+n;
      n=d<<shr;
    }
    //if(n){};//nothing();
    repack();
  }
  big_number operator<<(long_type count)const
  {
    big_number tmp;
    tmp=*this;
    tmp<<=count;
    return std::move(tmp);
  }
  big_number operator>>(long_type count)const
  {
    big_number tmp;
    tmp=*this;
    tmp>>=count;
    return std::move(tmp);
  }
  static int64&get_add_count(){static int64 tmp=0; return tmp;}
  void operator+=(const big_number&ref)
  {
    get_add_count()++;
    data.resize(1+max(ref.data.size(),data.size()));
    bool overflow=false;
    int max_size=data.size();
    const long_type base=1<<sizeof(elem_type)*8;
    int a_size=ref.data.size();
    auto*a_data=a_size?&ref.data.front():nullptr;
    auto*b_data=!data.empty()?&data.front():nullptr;
    for(int i=0;i<max_size;i++)
    {
      auto a=i<a_size?a_data[i]:0;
      auto b=b_data[i];
      long_type c=overflow?1:0;
      c+=a+b;
      b_data[i]=c%base;
      overflow=c>=base;
    }
    repack();
  }
  void operator-=(const big_number&a)
  {
    QapAssert(a<=*this);
    int max_size=max(a.data.size(),data.size());
    int min_size=min(a.data.size(),data.size());
    bool inc=false;
    for(int i=0;i<data.size();i++)
    {
      elem_type di=data[i];
      elem_type ai=i<a.data.size()?a.data[i]:0;
      bool flag=inc;
      if(di==ai)
      {
        elem_type diff=inc?-1:0;
        data[i]=diff;
        continue;
      }
      if(inc)
      {
        ai++;
        if(!ai)continue;
      }
      inc=di<ai;
      elem_type diff=di-ai;
      data[i]=diff;
    }
    QapAssert(!inc);
    repack();
  }
  big_number operator+(const big_number&a)const
  {
    big_number tmp;
    tmp=*this;
    tmp+=a;
    return std::move(tmp);
  }
  big_number operator-(const big_number&a)const
  {
    big_number tmp;
    tmp=*this;
    tmp-=a;
    return std::move(tmp);
  }
  big_number operator*(const big_number&a)const
  {
    big_number tmp;
    tmp=*this;
    tmp*=a;
    return std::move(tmp);
  }
  big_number operator/(const big_number&a)const
  {
    big_number tmp;
    tmp=*this;
    tmp/=a;
    return std::move(tmp);
  }
  big_number operator%(const big_number&a)const
  {
    big_number tmp;
    tmp=*this;
    tmp/=a;
    tmp=*this-tmp*a;
    return std::move(tmp);
  }
  elem_type operator%(elem_type a)const
  {
    return mod(*this,a);
  }
  big_number operator/(elem_type a)const
  {
    big_number tmp;
    tmp=*this;
    tmp/=a;
    return std::move(tmp);
  }
  void repack()
  {
    //while(!data.empty()&&!data.back())data.pop_back();
    int old_size=data.size();
    int new_size=old_size;
    for(int i=int(old_size)-1;i>=0;i--)
    {
      if(data[i])break;
      new_size--;
    }
    if(new_size!=old_size)data.resize(new_size);
  }
  void operator*=(const big_number&a)
  {
    *this=std::move(mul(*this,a));
  }
  void operator/=(const big_number&a)
  {
    *this=std::move(div(*this,a));
  }
  void operator/=(elem_type a)
  {
    *this=std::move(div(*this,a));
  }
  bool empty()const
  {
    auto is_empty=[this]()->bool
    {
      for(int i=0;i<this->data.size();i++)if(this->data[i])return false;
      return true;
    };
    return data.empty()||is_empty();
  }
public:
  string toString()const
  {
    if(empty())return "0";
    string result;
    big_number tmp=*this;
    elem_type base=10;
    while(!tmp.empty())
    {
      auto r=tmp%base;
      result.push_back(r+'0');
      tmp/=base;
    }
    return std::move(reverse(result));
  }
  string toCode()const
  {
    string result;
    for(int i=0;i<data.size();i++)
    {
      if(i)result+=",";
      result+=IToS(data[i]);
    }
    return std::move("{"+result+"}");
  };
  byte toByte()const
  {
    if(data.empty())return 0;
    QapAssert(data.size()==1);
    auto back=data.back();
    QapAssert(back<=255);
    return back;
  };
  template<int size>
  void init(elem_type(&arr)[size])
  {
    big_number tmp;
    data.resize(size);
    for(int i=0;i<size;i++)data[i]=arr[i];
  }
};