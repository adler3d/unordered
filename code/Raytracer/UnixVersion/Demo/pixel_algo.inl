auto heds=env.dirs.size()/2;

struct t_info_at{
  int tris_id;
  real t;
  vec3f dir;
};

t_info_at info_at_by_def={-2,0};
vector<t_info_at> cell2tris_id;cell2tris_id.resize(cx*cy,info_at_by_def);

auto info_at=[&](int i,int j)->t_info_at
{
  int x=j;int y=i;
  //if(x<0||x>=cx||y<0||y>=cy)QapDebugMsg("look like point in mask[mask_id] go out of bounds");
  bool wrong_addr=false;
  if(x<0||x>=cx||y<0||y>=cy)wrong_addr=true;
  if(!wrong_addr){
    auto&cell=cell2tris_id[x+y*cx];
    if(cell.tris_id!=-2)return cell;
  }
  auto offset=vec2d(x-cx/2,y-cy/2).Mul(pwh)*2+pwh;
  auto quad_center=center+ox*offset.x+oy*offset.y;
  t_photon inp;inp.pos=log.pos;inp.dir=(quad_center-log.pos).Norm();
  t_info_at out={-1,0};
  out.t=do_raycast_fixed(inp,&out.tris_id).t;
  out.dir=inp.dir;
  if(!wrong_addr)cell2tris_id[x+y*cx]=out;
  return out;
};

auto get_vec3d_color=[&](const vec3f&quad_center,int x,int y,t_pix_info*pinfo)->vec3d
{
  t_photon inp;inp.pos=log.pos;inp.dir=(quad_center-log.pos).Norm();
  t_lights_rays_color frag;
  t_lights_rays_color only_details;
  t_lights_rays_color simple_frag;
  int raw_wins=0;
  QapClock clock;
  for(;;)
  {
    int tris_id=-1;
    auto out=do_raycast_fixed(inp,&tris_id);
    if(tris_id<0)break;
    /*if(bool frag_as_tris_id=true){
      frag.n=1;
      frag.c=vec3d(1,1,1)*(out.t+(tris_id%3)*5.0);
      break;
    }*/
    if(is_light(tris_id)){
      int gg=1;
      frag.n=1;
      frag.c=to_vec3d(env.tris_colors[tris_id])*(two_bounce?sqr(heds):heds);
      if(need_writeln)simple_frag.add(frag);
      break;
    }
    if(bool trigon_as_light_source=true)if(out.t>=0)
    {
      auto&td=two_bounce||0?env.tris[tris_id].dirs:env.tris[tris_id].light_dirs;
      int td_size=env.tris[tris_id].dirs.size();
      {for(int k=0;k<td.size();k++){
        auto dir_id=td[k];
        #define FAST_MODE
        #ifndef FAST_MODE
        auto&ex=dirs[td[k]];
        if(dot(ex,-out.n)<0)QapNoWay();
        t_photon inp;inp.pos=out.pos;inp.dir=ex;
        auto out=do_raycast_fixed(inp);
        if(out.t>0)if(out.c==light_color)win++;
        #else
        if(two_bounce)
        {
          int tris_id=-1;vec3f end_pos;
          auto LRC=fast_do_raycast_v4(out.pos,dir_id,tris_id,end_pos);
          LRC.c*=heds;
          frag.add(LRC);
          if(need_writeln)simple_frag.add(LRC);
          if(tris_id>=0)
          {
            //QapAssert(!is_light(tris_id));
            t_lights_rays_color tris_frag;
            auto&td=env.tris[tris_id].light_dirs;
            {for(int k=0;k<td.size();k++){
              auto dir_id=td[k];
              auto LRC=get_lights_rays_color_in(end_pos,dir_id,tris_id);
              tris_frag.add(LRC);
              if(LRC.n)raw_wins++;//QapDebugMsg("Work!");
            }}
            tris_frag.n=1;
            tris_frag.c=(to_vec3d(env.tris_colors[tris_id])).Mul(tris_frag.c);
            only_details.add(tris_frag);
            frag.add(tris_frag);
          }
        }else{
          auto LRC=get_lights_rays_color_in(out.pos,dir_id,tris_id);
          frag.add(LRC);
        }
        #endif
      }}
      auto tc=(to_vec3d(env.tris_colors[tris_id]));
      frag.c=tc.Mul(frag.c);
      if(need_writeln)simple_frag.c=tc.Mul(simple_frag.c);
    }
    break;
  }
  if(pinfo)
  {
    auto ms=clock.MS();
    auto&info=*pinfo;int size=sizeof(info);int version='v1';
    #define F(VAR)info.VAR=VAR;
    F(version)F(size)F(x)F(y)F(frag)F(only_details)F(simple_frag)F(raw_wins)F(ms)
    #undef F
  }
  return frag.c;
};

auto get_msaa_mass=[&](const vec2i&coords)->int{
  //if(coords!=vec2i(1130,437))return 1; // ok need fix esp to 1e-5
  int fuf[9]={-1};vector_view<int> fmp=make_view(fuf);fmp.n=0;
  vec3f buf[9]={};vector_view<vec3f> tmp=make_view(buf);tmp.n=0;
  t_info_at ptr2info[9];{for(int i=0;i<9;i++)ptr2info[i]=info_at_by_def;}
  int ptr=-1;
  for(int dy=-1;dy<=+1;dy++)for(int dx=-1;dx<=+1;dx++){
    auto c=vec2i(dx,dy)+coords;ptr++;
    if(c.x<0||c.x>=cx||c.y<0||c.y>=cy)continue;
    auto info=info_at(c.y,c.x);ptr2info[ptr]=info;
    {auto v=info.tris_id;if(!qap_includes(fmp,v))fuf[fmp.n++]=v;}
    if(bool use_oy=true)
    {
      auto id=info.tris_id;auto v=id<0?vec3f(0,0,0):env.tris[id].oy;
      bool found=false;QAP_FOREACH(tmp,if((ex-v).SqrMag()<1e-9)found=true;);
      if(found)continue;
      buf[tmp.n++]=v;
    }
  }
  const int cx=3;const real esp=1e-5;
  if(fmp.size()>1)for(int i=0;i<3;i++)
  {
    #define U(a,b){auto h=dot(-a.dir*a.t,an);auto v=dot(-b.dir,an);QapAssert(v);auto bt=h/v;QapAssert(bt>=0);if(fabs(b.t-bt)>esp)return 2;}
    #define F(a,dz)ptr=dz+cx*i;auto&a=ptr2info[ptr];if(a.tris_id<0)continue;auto&a##n=env.tris[a.tris_id].oy;
    {
      F(a,0)F(b,1)F(c,2);
      U(b,a);
      U(b,c);
    }
    #undef F
    #define F(a,dz)ptr=i+cx*dz;auto&a=ptr2info[ptr];if(a.tris_id<0)continue;auto&a##n=env.tris[a.tris_id].oy;;
    {
      F(a,0)F(b,1)F(c,2);
      U(b,a);
      U(b,c);
    }
    #undef F
    #undef U
  }
  //return 1;
  return std::min<int>(2,tmp.size());
  //return tmp.size();
};

auto f=[&](int i,int j){
  t_pix_info info;bool subpixel=msaa_q;
  int x=j;int y=i;
  if(x<0||x>=cx||y<0||y>=cy)QapDebugMsg("look like point in mask[mask_id] go out of bounds");
  
  auto def_color=[&]()->vec3d{
    auto offset=vec2d(x-cx/2,y-cy/2).Mul(pwh)*2+pwh;
    auto quad_center=center+ox*offset.x+oy*offset.y;
    auto out=get_vec3d_color(quad_center,x,y,&info);
    if(need_writeln)writeln(string((char*)(void*)&info,sizeof(info)));
    return out;
  };
  
  if(!msaa_q&&!only_edges)
  {
    frags[x+y*cx]=def_color();
    return;
  }
  
  auto coords=vec2i(x,y);
  auto mm=get_msaa_mass(coords);
  
  if(only_colorless_edges)
  {
    frags[x+y*cx]=vec3d(1,1,1)*mm;
    return;//(std::min<int>(2,tmp.size()));
  }
  if(only_edges&&!msaa_q)
  {
    if(mm>1)frags[x+y*cx]=def_color();
    return;
  }
  if(mm<=1)
  {
    frags[x+y*cx]=def_color();
    return;
  }
  QapClock clock;
  vec3d accum;int n=0;int q=msaa_q/2;const real inv=1.0/(q+q);
  for(int dy=-q+1;dy<=+q;dy++)for(int dx=-q+1;dx<=+q;dx++){
    auto offset=vec2d(x+dx*inv-cx/2,y+dy*inv-cy/2).Mul(pwh)*2+pwh;
    auto quad_center=center+ox*offset.x+oy*offset.y;
    accum+=get_vec3d_color(quad_center,x,y,nullptr);n++;
  }
  frags[x+y*cx]=accum*(1.0/n);

  if(need_writeln)
  {
    auto ms=clock.MS();
    int raw_wins=0;
    t_lights_rays_color frag;frag.c=accum*(1.0/n);
    t_lights_rays_color only_details;
    t_lights_rays_color simple_frag;
    t_pix_info info;int size=sizeof(info);int version='v1';
    #define F(VAR)info.VAR=VAR;
    F(version)F(size)F(x)F(y)F(frag)F(only_details)F(simple_frag)F(raw_wins)F(ms)
    #undef F
    writeln(string((char*)(void*)&info,sizeof(info)));
  }
};





































