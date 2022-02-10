#ifdef DEF_PRO_FEATURE_BEFORE
  struct t_trigon_vec3f{
    #define DEF_PRO_CLASSNAME()t_trigon_vec3f
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec3f,a,$)\
    ADD(vec3f,b,$)\
    ADD(vec3f,c,$)\
    //===
    #include "defprovar.inl"
    //===
  };
  struct t_trigon_vec2f{
    #define DEF_PRO_CLASSNAME()t_trigon_vec2f
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec2f,a,$)\
    ADD(vec2f,b,$)\
    ADD(vec2f,c,$)\
    //===
    #include "defprovar.inl"
    //===
    t_trigon_vec2f(vec2f a,vec2f b,vec2f c):a(a),b(b),c(c){}
  };
  struct t_trigon_vec2f_with_circle:t_trigon_vec2f{
    vec2d p;real r;
  };
  struct t_axis{
    #define DEF_PRO_CLASSNAME()t_axis
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(vec3f,dir,$)\
    ADD(vec3f,ox,$)\
    ADD(vec3f,oy,$)\
    //===
    #include "defprovar.inl"
    //===
    vec2d get_vec2d(const vec3f&v)const{return vec2d(dot(v,ox),dot(v,oy));}
    vec3f get_vec3f(const vec3f&v)const{return vec3f(dot(v,ox),dot(v,oy),dot(v,dir));}
  };
  static vec3f get_updir(const vec3f&dir){auto up=vec3f(0,1,0);return dir==up?vec3f(0,0,+1):up;}
  static t_axis make_axis_from_dir(const vec3f&dir){
    t_axis out;
    out.dir=dir.Norm();
    out.ox=cross(dir,get_updir(dir)).Norm();
    out.oy=cross(dir,out.ox).Norm();
    return out;
  }
  struct t_dir_quad{
    #define DEF_PRO_CLASSNAME()t_dir_quad
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_axis,axis,$)\
    ADD(t_quad,q,$)\
    //===
    #include "defprovar.inl"
    //===
    t_dir_quad get_subquad(const vec2i&wh,const vec2i&xy)const{t_dir_quad out=*this;out.q=q.get_subquad(wh,xy);return out;}
    bool cd_test_vs(const t_trigon_vec2f&t){return CD_TrigonVsQuad(t,q);}
  };
  struct t_cell_quad{
    #define DEF_PRO_CLASSNAME()t_cell_quad
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,n,0)\
    ADD(int,ptr,-1)\
    //===
    #include "defprovar.inl"
    //===
    t_cell_quad&set_id(int id){this->ptr=id;return *this;}
  };
  struct t_dir_info{
    #define DEF_PRO_CLASSNAME()t_dir_info
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(t_dir_quad,dq,$)\
    ADD(vec2i,dq_wh,$)\
    ADD(vector<t_cell_quad>,pos2info,$)\
    ADD(vector<int>,mem,$)\
    //===
    #include "defprovar.inl"
    //===
    void init(const t_dir_quad&quad,const vec2i&wh){
      dq=quad;dq_wh=wh;
      pos2info.clear();
      pos2info.resize(wh.x*wh.y);
      mem.clear();
    }
    template<class FUNC>
    void map(FUNC func){
      auto w=dq_wh.x;auto h=dq_wh.y;
      for(int y=0;y<h;y++)for(int x=0;x<w;x++)func(pos2info[x+y*w],x,y);
    }
    t_cell_quad&get(int x,int y){
      QapAssert(x<dq_wh.x&&x>=0);
      QapAssert(y<dq_wh.y&&y>=0);
      return pos2info[x+y*dq_wh.x];
    }
    const vector_view<int> get_view(const t_cell_quad&cell)const{
      return make_view(mem,cell.ptr,cell.n);
    }
    /* */ t_cell_quad&unsafe_get(const vec2i&p)/* */{return pos2info[p.x+p.y*dq_wh.x];}
    const t_cell_quad&unsafe_get(const vec2i&p)const{return pos2info[p.x+p.y*dq_wh.x];}
    const vector_view<int> unsafe_get_arr(const vec2i&p)const{
      static const vector_view<int> empty;
      auto&cell=pos2info[p.x+p.y*dq_wh.x];
      return get_view(cell);
    }
    const vector_view<int> safe_get(const vec3f&pos/*,const vector_view<int>&def=vector_view<int>()*/)const{
      auto p=dq.axis.get_vec2d(pos);
      if(!point_in_quad_v_half_interval(dq.q,p))return vector_view<int>();
      auto xy=dq.q.get_xy(dq_wh,p);
      return unsafe_get_arr(xy);
    }
    static int find_end_id(const vector<int>&mem,const vector<int>&arr){
      auto it=std::find_end(mem.begin(),mem.end(),arr.begin(),arr.end());
      if(it==mem.end())return -1;
      return it-mem.begin();
    }
    void set(int x,int y,vector<int>&&arr)
    {
      if(!arr.size()){unsafe_get(vec2i(x,y)).set_id(-1).n=0;return;}
      int id=find_end_id(mem,arr);
      if(!qap_check_id(mem,id))
      {
        id=mem.size();
        QAP_FOREACH(arr,qap_add_back(mem)=ex);
      }
      unsafe_get(vec2i(x,y)).set_id(id).n=arr.size();
    }
  };
  #undef DEF_PRO_FEATURE_BEFORE
#endif //DEF_PRO_FEATURE_BEFORE

#ifdef DEF_PRO_FEATURE_INSIDE
  //vector<t_trigon_vec3f> trigons;
  //vector<t_dir_info> dir2info;
  t_dir_quad make_dir_quad(int dir_id,const string&geom)
  {
    QapAssert(geom.size()<=2);
    auto dir=dirs[dir_id];
    t_dir_quad out;
    out.axis=make_axis_from_dir(dir);
    vec2d low,top;
    #define F(a){auto tmp=out.axis.get_vec2d(trigons[ex].a);low.comin(tmp);top.comax(tmp);}
    for(int i=0;i<geom.size();i++)
    {
      QapAssert(geom[i]=='L'||geom[i]=='D');
      auto&tris=(geom[i]=='D'?dir_id_to_Dtris_list:dir_id_to_Ltris_list)[dir_id];
      QAP_FOREACH(tris,F(a)F(b)F(c));
    }
    #undef F
    out.q.size=top-low;
    out.q.pos=0.5*(top+low);
    return out;
  }
  #undef DEF_PRO_FEATURE_INSIDE
#endif //DEF_PRO_FEATURE_INSIDE

#ifdef DEF_PRO_FEATURE_AFTER
  t_trigon_vec2f make_2d_tris(const t_trigon_vec3f&t,const t_axis&axis){
    t_trigon_vec2f out;
    #define F(a)out.a=axis.get_vec2d(t.a);
    F(a);F(b);F(c);
    #undef F 
    return out;
  }
  t_trigon_vec2f_with_circle make_2d_tris_ex(const t_trigon_vec3f&t,const t_axis&axis){
    t_trigon_vec2f_with_circle out;
    #define F(a)out.a=axis.get_vec2d(t.a);
    F(a);F(b);F(c);
    #undef F
    auto tmp=t_circle_from_points(out);
    out.p=tmp.pos;out.r=tmp.r;
    return out;
  }
  static vector<real> do_clamp_bottom_bound(const vector<real>&arr,real portion=0.1)
  {
    real low=1e20;real top=-low;
    int id=QAP_MINVAL_ID_OF_VEC(arr,+ex);auto v=id<0?top:arr[id];
    QAP_FOREACH(arr,if(ex>v)low=std::min<real>(ex,low));
    auto out=arr;
    QAP_FOREACH(out,if(ex<=v)ex=low);
    return out;
  }
  static vector<real> do_clamp_upper_bound(const vector<real>&arr,real portion=0.1)
  {
    real low=1e20;real top=-low;
    int id=QAP_MINVAL_ID_OF_VEC(arr,-ex);auto v=id<0?low:arr[id];
    QAP_FOREACH(arr,if(ex<v)top=std::max<real>(ex,top));
    auto out=arr;
    QAP_FOREACH(out,if(ex>=v)ex=top);
    return out;
  }
  static real vec3d_max(const vec3d&v){return std::max(std::max(v.x,v.y),v.z);}
  static real vec3d_min(const vec3d&v){return std::min(std::min(v.x,v.y),v.z);}
  static vec3d vec3d_max(const vec3d&a,const vec3d&b){return vec3d_max(a)<vec3d_max(b)?b:a;}
  static vec3d vec3d_min(const vec3d&a,const vec3d&b){return vec3d_min(a)>vec3d_min(b)?b:a;}
  static vector<vec3d> do_clamp_bottom_bound(const vector<vec3d>&arr)
  {
    auto out=arr;
    real low=1e20;real top=-low;bool fail=true;
    int id=QAP_MINVAL_ID_OF_VEC(arr,+vec3d_min(ex));auto v=id<0?top:vec3d_min(arr[id]);
    QAP_FOREACH(arr,auto m=vec3d_min(ex);if(m>v){low=std::min<real>(m,low);fail=false;});
    if(fail)return out;
    #define F(x)if(ex.x<=v)ex.x=low;
    QAP_FOREACH(out,F(x)F(y)F(z));
    #undef F
    return out;
  }
  static vector<vec3d> do_clamp_upper_bound(const vector<vec3d>&arr)
  {
    auto out=arr;
    real low=1e20;real top=-low;bool fail=true;
    int id=QAP_MINVAL_ID_OF_VEC(arr,-vec3d_max(ex));auto v=id<0?low:vec3d_max(arr[id]);
    QAP_FOREACH(arr,auto m=vec3d_max(ex);if(m<v){top=std::max<real>(m,top);fail=false;});
    if(fail)return out;
    #define F(x)if(ex.x>=v)ex.x=top;
    QAP_FOREACH(out,F(x)F(y)F(z));
    #undef F
    return out;
  }
  /*static vector<vec3d> do_clamp_upper_bound(const vector<vec3d>&arr)
  {
    QapNoWay();
    auto out=arr;
    auto low=vec3d(1,1,1)*1e20;auto top=-low;vec3d v;
    #define F(x){int id=QAP_MINVAL_ID_OF_VEC(arr,-ex.x);v.x=id<0?low.x:arr[id].x;}QAP_FOREACH(arr,if(ex.x<v.x)top.x=std::max<real>(ex.x,top.x));
    F(x)F(y)F(z)
    #undef F
    real vm=vec3d_max(v);
    #define F(x)if(v.x==vm)QAP_FOREACH(out,if(ex.x>=v.x)ex.x=top.x);
    F(x)F(y)F(z)
    #undef F
    return out;
  }*/
  static vector<vec3d> hdr_pixmap(const vector<vec3d>&pix,real min=0x00,real max=0xff)
  {
    real low=1e20;real top=-low;
    QAP_FOREACH(pix,top=std::max<real>(vec3d_max(ex),top);low=std::min<real>(vec3d_min(ex),low));
    real dip=max-min;
    real koef=(dip/(top-low));
    auto dno=vec3d(1,1,1)*low;auto min3d=vec3d(min,min,min);
    auto out=pix;
    QAP_FOREACH(out,ex=min3d+(ex-dno)*koef);
    return out;
  }
  static vector<real> hdr_pixmap(const vector<real>&pix,real min=0x00,real max=0xff/*,bool use_some_hack_with_limits=false*/)
  {
    real low=1e20;real top=-low;
    //int topid=QAP_MINVAL_ID_OF_VEC(pix,-ex);auto topv=topid<0?low:pix[topid];
    //int lowid=QAP_MINVAL_ID_OF_VEC(pix,+ex);auto lowv=lowid<0?top:pix[lowid];
    //QAP_FOREACH(pix,if(ex<topv)top=std::max<real>(ex,top);if(ex>lowv)low=std::min<real>(ex,low));
    QAP_FOREACH(pix,top=std::max<real>(ex,top);low=std::min<real>(ex,low));
    real dip=max-min;
    real koef=(dip/(top-low));
    auto out=pix;
    QAP_FOREACH(out,ex=min+(ex-low)*koef);
    return out;
  }
  static vector<QapColor> hdr_pixmap(const vector<QapColor>&pix)
  {
    int low=256;int top=-1;
    QAP_FOREACH(pix,if(ex.r!=255)top=std::max<int>(ex.r,top);if(ex.r)low=std::min<int>(ex.r,low));
    //low--;
    real koef=low>255?1:(253.0/(top-low));
    auto f=[low,top,koef](const QapColor&c){
      auto out=c;
      #define F(r)out.r=c.r==255?255:(!c.r?0:1+std::min<int>(253,(c.r-low)*koef));
      F(r)F(g)F(b)
      #undef F
      return out;
    };
    auto out=pix;
    QAP_FOREACH(out,ex=f(ex));
    return out;
  }
  bool is_light(int tris_id)const{return env.is_light[tris_id];}
  void make(vector<t_dir_info>&out,const std::string&dm_geom,const string&order,const string&geom,int limit)
  {
    out.clear();out.resize(env.dirs.size());
    #pragma omp parallel for schedule(guided,8)
    for(int i=0;i<env.dirs.size();i++)
    {
      QapClock clock;
      auto&dir_id=i;
      auto&dir=env.dirs[i];
      auto dq=env.make_dir_quad(dir_id,dm_geom);
      auto dq_wh=vec2i(1,1)*2;//dq_wh=vec2i(1920,1200);
      //auto dq_wh=vec2i(dq.q.size.x,dq.q.size.y)*4;
      auto&b=out[i];//qap_add_back(out);
      
      vector<t_trigon_vec2f_with_circle> arr;arr.reserve(env.trigons.size());
      vector<int> id2id;
      real order_k=order=="main"?+1:-1;bool inc_ld_counter=order=="back";
      bool need_light=geom=="light"||geom=="all";
      bool need_dark=geom=="dark"||geom=="all";
      {QAP_FOREACH(env.trigons,{
        auto LT=is_light(i);
        if(!need_light&&LT)return;
        if(!need_dark&&!LT)return;
        if(dot(env.tris[i].normal(),dir)*order_k<0)return;
        id2id.push_back(i);
        qap_add_back(arr)=make_2d_tris_ex(ex,dq.axis);
      });}
      
      //#define SaveOnce(FN,VAR){static bool once=false;if(!once){QapSaveToFile(FN,VAR);once=true;}}
      //SaveOnce("some_arr_at_frame_0.bin",arr);
      
      if(bool first_iter=1)
      {
        b.init(dq,dq_wh);
        auto qr=t_circle_from_points(dq.get_subquad(dq_wh,vec2i(0,0)).q).r;
        b.map([&](t_cell_quad&e,int x,int y){
          auto sq=dq.get_subquad(dq_wh,vec2i(x,y));
          vector<int> out;
          QAP_FOREACH(arr,if(CD_TrigonVsQuad(ex,sq.q,qr))qap_add_back(out)=i);
          b.set(x,y,std::move(out));
        });
      }
      auto top=b;
      for(;dq_wh.x*2<=limit;)
      {
        dq_wh*=2;
        b.init(dq,dq_wh);
        auto qr=t_circle_from_points(dq.get_subquad(dq_wh,vec2i(0,0)).q).r;
        b.map([&](t_cell_quad&e,int x,int y){
          auto sq=dq.get_subquad(dq_wh,vec2i(x,y));
          vector<int> out;
          auto tmp=top.unsafe_get_arr(vec2i(x/2,y/2));
          QAP_FOREACH(tmp,if(CD_TrigonVsQuad(arr[ex],sq.q,qr))qap_add_back(out)=ex);
          b.set(x,y,std::move(out));
        });
        top=b;
      }
      b=top;
      QAP_FOREACH(b.mem,ex=id2id[ex]);
      if(inc_ld_counter)
      {
        auto atomic_inc=[](int&ref){
          #pragma omp atomic
          ref++;
        };
        QAP_FOREACH(b.pos2info,{
          auto arr=b.get_view(ex);
          bool light_found=false;QAP_FOREACH(arr,if(is_light(ex))light_found=true);
          if(!light_found)return;
          QAP_FOREACH(arr,{
            if(is_light(ex))return;
            auto&t=env.tris[ex];
            atomic_inc(t.light_dirs_counter[dir_id]);
            //QapDebugMsg("t.light_dirs_counter[dir_id]++;");
          });
        });
      }

      if(bool need_imgs_debug=false&&order=="main")
      {
        vector<QapColor> out;
        QAP_FOREACH(b.pos2info,auto k=Clamp<int>(ex.n,0,0xff);qap_add_back(out)=QapColor(0xFF,k,k,k););
        out=hdr_pixmap(out);
        QAP_FOREACH(out,ex=ex.inv_rgb().swap_rg());
        //ImgLoader::TextureMemory mem;
        //Env.InitMemory(mem,dq_wh.x,dq_wh.y);
        //QAP_FOREACH(out,((QapColor*)mem.ptr)[i]=ex.inv_rgb().swap_rg());
        foo(dq_wh.x,dq_wh.y,out,("raymaps/"+IToS(i)+".png").c_str());
        //Env.SaveTextureToFile(mem,"raymaps/"+IToS(i)+".png");QapDebugMsg("done\n"+FToS(clock.MS())+"ms");
        int gg=1;
      }
    }
  }
  void toplevel_algo(int limit)
  {
    QAP_FOREACH(env.tris,auto&c=ex.light_dirs_counter;c.clear();c.resize(env.dirs.size()));
    make(env.dir2info,"D","main","dark",limit); // for dark tris. v3 and v4
    make(env.dir2back,"D","back","all",limit); // for dark tris.light_dirs
    env.dir2back.clear();
    make(env.dir2light,"L","main","light",std::max(8,limit/2)); // for light tris. v3
  }
  void make_raymaps()
  {
    //return;
    int limit=get_raymaps_limit();
    string fn=get_rayenv_fn(limit);//"rayenv_L"+IToS(limit)+"_scene_v30.bin";//fn="rayenv_L64_just_cube.bin";
    if(access(fn.c_str(),0)!=0){
      QapUserInfo(fn+" - not found, but ok let's generate it!");
    }else{
      t_ray_env tmp;t_ray_env tmp2;
      QapLoadFromFile(fn,tmp);
      //QapLoadFromFile("rayenv_L2_scene_v22(old).bin",tmp2);
      //QapAssert(tmp==tmp2);
      env=std::move(tmp);
      return;
    }
    //return;
    QapClock clock;
    
    toplevel_algo(limit);
    
    QAP_FOREACH(env.tris,{
      auto&t=ex;
      if(is_light(i))return;
      QAP_FOREACH(t.dirs,{
        if(t.light_dirs_counter[ex]>0){
          qap_add_back(t.light_dirs)=ex;
        }
      });
    });
    QapSaveToFile(fn,env);
  }
  #undef DEF_PRO_FEATURE_AFTER
#endif //DEF_PRO_FEATURE_AFTER