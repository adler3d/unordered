#define QapCheckId(arr,id)
//#define QapCheckId(arr,id){QapAssert(qap_check_id(arr,id));}
template<class TYPE,size_t block=(1024*1024*4)/sizeof(TYPE)>
struct big_vector{
  #define DEF_PRO_CLASSNAME()big_vector
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<vector<TYPE>>,arr,$)\
  //===
  #include "defprovar.inl"
  //===
  TYPE&operator[](size_t id){
    auto seg=id/block;
    auto off=id%block;
    QapCheckId(arr,seg);
    auto&sub=arr[seg];
    QapCheckId(sub,off);
    return sub[off];
  };
  const TYPE&operator[](size_t id)const{
    auto seg=id/block;
    auto off=id%block;
    QapCheckId(arr,seg);
    auto&sub=arr[seg];
    QapCheckId(sub,off);
    return s[off];
  };
  int add(){
    if(arr.empty())qap_add_back(arr).reserve(block);
    auto*pb=&arr.back();
    int id=-block+arr.size()*block+pb->size();
    if(pb->size()==block){pb=&qap_add_back(arr);pb->reserve(block);}
    qap_add_back(*pb);
    return id;
  }
  void push_back(TYPE&&ref){
    if(arr.empty())qap_add_back(arr).reserve(block);
    auto*pb=&arr.back();
    if(pb->size()==block){pb=&qap_add_back(arr);pb->reserve(block);}
    pb->push_back(std::move(ref));
  }
  void clear(){arr.clear();}
  TYPE&back(){return arr.back().back();}
  const TYPE&back()const{return arr.back().back();}
  size_t size()const{return arr.empty()?0:-block+arr.size()*block+arr.back().size();}
  void resize(size_t new_size){
    QapAssert(new_size<size());
    auto seg=new_size/block;
    auto off=new_size%block;
    arr.resize(seg+1);
    for(int i=0;i+1<seg;i++){
      arr[i].resize(block);
    }
    if(seg||off){auto&b=arr.back();b.reserve(block);b.resize(off);}
  }
  static friend void operator+=(big_vector<TYPE>&arr,vector<TYPE>&&ref)
  {
    //arr.reserve(arr.size()+ref.size());
    for(int i=0;i<ref.size();i++)
    {
      arr.push_back(std::move(ref[i]));
    }
    ref.clear();
  }
};

template<class TYPE>static TYPE&qap_add_back(big_vector<TYPE>&arr){arr.add();return arr.back();}