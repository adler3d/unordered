struct Genome{
public:
  #define DEF_PRO_CLASSNAME()Genome
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(float,fitness,0)\
  ADD(vector<char>,arr,$)\
  //===
  #include "defprovar.inl"
  //===
public:
  static inline char RandomGen(){return (rand()>>2)%3;}
  static inline float RandomFloatOne(){return float(rand())/float(RAND_MAX+1.0f);}
  static inline float RandomFloat(){return RandomFloatOne()+RandomFloatOne()/float(RAND_MAX+1.0f);}
  static inline float RandomClamped(){return RandomFloat()-RandomFloat();}
  bool operator<(const Genome&ref){return fitness<ref.fitness;}
  Genome mutate(float rate=0.15)const
  {
    Genome out=*this;auto&arr=out.arr;
    for(int i=0;i<arr.size();i++)
    {
      if(RandomFloat()>=rate)continue;
      arr[i]=RandomGen();
    }
    return out;
  }
  Genome mutateOne()const
  {
    Genome out=*this;
    int id=rand()%arr.size();
    out.arr[id]=RandomGen();
    return out;
  }
  Genome mutateTwo()const
  {
    Genome out=*this;
    int aid=rand()%arr.size();
    int bid=rand()%arr.size();
    int v=(rand()>>2)%2;
    out.arr[aid]=1+v;
    out.arr[bid]=2-v;
    return out;
  }
  Genome mutateSoft()const
  {
    Genome out=*this;
    int as=int(arr.size())-1;
    int n=rand()%as;
    if(n+1>arr.size()||n<2)return out;
    int id=rand()%(arr.size()-n);
    int m[3]={0,0,0};
    for(int i=0;i<n;i++){
      auto&c=out.arr[i+id];
      if(c=='N')c=0;
      if(c=='A')c=1;
      if(c=='S')c=2;
      if(c>2)return out;
      m[c]++;
      c=0;
    }
    int mt=std::max(m[1],m[2]);
    int md=std::min(m[1],m[2]);
    int rot_n=mt-md;
    for(int i=0;i<rot_n;i++){
      auto&c=out.arr[i+id];
      c=m[1]>m[2]?1:2;
    };
    return out;
  }
  void init(int numOfInputs)
  {
    arr.resize(numOfInputs);
    for(int i=0;i<arr.size();i++)
    {
      arr[i]=RandomGen();
    }
  }
  Genome&set_arr(const vector<char>&value){arr=value;return *this;};
};
struct GeneticAlgorithm{
public:
  #define DEF_PRO_CLASSNAME()GeneticAlgorithm
  #define DEF_PRO_VARIABLE(ADD)\
  ADD(vector<Genome>,arr,$)\
  //===
  #include "defprovar.inl"
  //===
public:
  void add_random_genome(){
    qap_add_back(arr).init(arr[0].arr.size());
  }
  void sort(){
    qap_sort(arr);reverse(arr);
  }
  void deadline(int n){
    qap_sort(arr);
    qap_subarr(arr,-n);
    reverse(arr);
  }
  void breed(int limit=20)
  {
    auto&out=arr;
    vector<Genome> arr=std::move(out);
    for(int i=0;i<arr.size()/2;i++){
      auto&ex=arr[i];
      for(int j=i+1;j<arr.size();j++){
        auto&ey=arr[j];
        cross(ex,ey);
      }
    }
    qap_add_back(out)=arr[0].mutate();
    qap_add_back(out)=arr[0].mutateOne();
    qap_add_back(out)=arr[0].mutateOne().mutateOne();
    qap_add_back(out)=arr[0].mutateTwo();
    qap_add_back(out)=arr[0].mutateTwo();
    qap_add_back(out)=arr[0].mutateSoft();
  }
  void cross(const Genome&a,const Genome&b)
  {
    int n=std::min(a.arr.size(),b.arr.size());
    int crossover=rand()%n;
    auto baby1=a;
    auto baby2=b;
    for(unsigned int i=crossover;i<n;i++)
    {
      baby1.arr[i]=b.arr[i];
      baby2.arr[i]=a.arr[i];
    }
    qap_add_back(arr)=baby1.mutate();
    qap_add_back(arr)=baby2.mutate();
  }
};