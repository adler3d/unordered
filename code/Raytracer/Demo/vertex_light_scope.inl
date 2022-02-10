struct t_vertex_light_scope{
  int ipos;
  int beg;
  vec3f pos;
  QapDev&qDev;
  bool enabled;
  bool drop_color;
  t_vertex_light_scope(QapDev&qDev,vec3f pos,bool enabled=true,bool drop_color=false):qDev(qDev),pos(pos),enabled(enabled),drop_color(drop_color){ipos=qDev.IPos;beg=qDev.VPos;}
  ~t_vertex_light_scope()
  {
    if(!enabled)return;
    vec3f lightpos(0,0,3);
    //auto c=0.05;
    vector<vec3f> NA;NA.resize(qDev.VPos-beg);
    //vector<int> CA;CA.resize(qDev.VPos-beg);
    auto iter_n=(int(qDev.IPos-ipos)/3)-1;
    //#pragma omp parallel for schedule(dynamic,32)
    //for(int i=ipos;i+2<qDev.IPos;i+=3){
    for(int iter=0;iter<iter_n;iter++){
      int i=ipos+iter*3;
      #define F(A,a,id)auto&A=qDev.IBA[i+id];auto&a=qDev.VBA[A].get_vec3f();
      F(A,a,0)F(B,b,1)F(C,c,2)
      #undef F
      auto n=-cross(b-a,c-a).Norm();
      #define F(A,a,id)NA[A-beg]+=n;//CA[A-beg]++; // TODO: omp racing detected here!
      F(A,a,0)F(B,b,1)F(C,c,2)
      #undef F
    }
    //QAP_FOREACH(NA,ex*=(1.0/CA[i]));
    //#pragma omp parallel for schedule(dynamic,128)
    for(int i=beg;i<qDev.VPos;i++)
    {
      auto&v=qDev.VBA[i];
      auto&p=v.get_vec3f();
      QapColor c0,c1;
      {
        auto dir=p-pos;
        auto n=NA[i-beg];
        auto k=dot(-dir.Norm(),n);if(k<0)k=0;if(k>1)k=1;
        c0=QapColor::Mix(0xffa8a8a8*0+0xff000000,0xffffffff,k);
      }
      {
        auto dir=p-lightpos;
        auto n=NA[i-beg];
        auto k=dot(-dir.Norm(),n);if(k<0)k=0;if(k>1)k=1;
        c1=QapColor::Mix(0xffa8a8a8,0xffffffff,k);
      }
      auto out=QapColor::HalfMix(c0,c1);
      v.color=drop_color?out:QapColor::HalfMix(out,v.color);
    }
  }
};