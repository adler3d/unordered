static vec2i tovec2i(vec2d p){return vec2i(p.x,p.y);}
struct t_rec_with_id_and_s_and_t{int id;int s;int t;};
void draw_map()
{
  USE_NBF();auto&obj=world.actor;
  //draw map
  //auto&map=qap_check_id(id2vec,layer_id-1)?():nbf.map;
  auto block_size=get_block_size();
  qDev.color=0x80008000;
  qDev.DrawQuad(target_point,block_size*0.99*vec2d(1,1));
  auto base=target_point;
  vec2d dir=s2w(mpos)-target_point;dir=dir.SqrMag()?dir.SetMag(max_speed):vec2d(0,max_speed);
  {
    //auto&map=nbf.get_pnodemaps(dir);
    auto cc=map.world_to_cell(target_point);
    int map_zn=map_n*map_z;int layers_n=id2vec.size();
    typedef t_rec_with_id_and_s_and_t t_rec;
    auto step=[&](int L,int id,t_rec&rec)->void
    {
      auto ex_id=L*map_zn+id;
      auto t=maps[ex_id].get(cc);
      if(t<0)return;
      const t_rec cur={ex_id,id2vec[L].size(),t};
      if(rec.id>=0)
      {
        bool skip=rec.s<cur.s;
        if(rec.s==cur.s)skip=rec.t<cur.t;
        if(skip)return;
      }
      rec=cur;
    };
    auto get_minid_for_any_dir=[&]()->int{
      t_rec rec={-1,0,0};
      for(int L=0;L<layers_n;L++)for(int id=0;id<map_zn;id++)step(L,id,rec);
      return rec.id;
    };
    auto minid=get_minid_for_any_dir();
    auto&full_genome2linelist=t_node::full_genome2linelist;
    auto node2linelist=[&](t_small_node_ptr&pnode)->vector<vec2d>{
      auto n=1;//steps_per_pranch;
      auto fg=nbf.full_genome(pnode,n);
      return full_genome2linelist(&nbf,fg);
    };
    if(minid>=0)if(auto&pnode=pnodemaps[minid].get(cc))
    {
      auto tmp=node2linelist(pnode);
      qDev.color=0x80FF0000;qDev.DrawLineList(tmp,4);
    }
    QapAssert(!show_dir_way);
    if(show_dir_way)
    {
      //auto&maps=nbf.maps;
      t_rec rec={-1,0,0};
      auto clone=world;clone.actor.v=dir.SetMag(max_speed);
      int id=nbf.get_map_id(clone)%map_n;
      for(int L=0;L<layers_n;L++)
      {
        step(L,id,rec);
      }
      if(rec.id>=0)if(auto&pnode=pnodemaps[rec.id].get(cc))
      {
        auto tmp=node2linelist(pnode);
        qDev.color=0x80004000;qDev.DrawLineList(tmp,4);
      }
      //int id=nbf.get_map_id(dir.SetMag(max_speed))%map_n;vector<int> dir2mapid;
      //for(int i=0;i<map_z;i++)qap_add_back(dir2mapid)=i*map_n+id;
      //auto minid=QAP_MINVAL_ID_OF_VEC(dir2mapid,pnodemaps[ex].get(cc)?pnodemaps[ex].get(cc)->t:1e6);
      //if(minid>=0)if(auto*pnode=pnodemaps[dir2mapid[minid]].get(cc))
      //{
      //  qDev.color=0x80004000;qDev.DrawLineList(pnode->full_path(),4);
      //}
    }
  }
  qDev.color=0xff000000;
  QapAssert(!show_dir_way);
  if(show_dir_way)
  {
    int rays=256;
    auto clone_dir=world;clone_dir.actor.v=dir.SetMag(max_speed);
    int id=nbf.get_map_id(clone_dir)%map_n;
    for(int i=0;i<rays;i++){
      auto clone=world;clone.actor.v=Vec2dEx(i*Pi2/real(rays),max_speed);
      if((nbf.get_map_id(clone)%map_n)!=(nbf.get_map_id(clone_dir)%map_n))continue;
      qDev.DrawLine(base,base+clone.actor.v.SetMag(100),1);
    }
  }
  if(!show_map)return;
  //auto&map=get_map(dir);
  vec2d offset=vec2d(map.w,map.h)*block_size*0.5;
  auto vp=viewport;
  vp.size/=scale;
  vp=vp.add_size(vec2d(1,1)*block_size*sqrt(2.0));
  vec2i imin;vec2i imax;
  {
    //vp=vp.add_size(-vec2d(1,1)*s*sqrt(2.0)*4);
    vec2d minp;vec2d maxp;
    vec2d dir=vec2d(1,1);
    for(int i=0;i<4;i++)
    {
      dir=dir.Ort();
      vec2d qvp=vec2d(vp.get_vertex_by_dir(dir)-vp.pos-vec2d(qDev.xf.p)*(1.0/scale)).Rot(qDev.xf.r.col1);
      vec2d mqc=(qvp+offset-dir*0.5*block_size)*(1.0/block_size);
      vec2i ic=vec2d_round(mqc,dir);
      //if(x==ic.x&&y==ic.y)qDev.color=0xffff0000;
      if(!i)
      {
        maxp=ic;
        minp=ic;
        continue;
      }
      vec2d::comax(maxp,ic);
      vec2d::comin(minp,ic);
    }
    imin=tovec2i(vec2d::max(vec2d_zero,minp));
    imax=tovec2i(vec2d::min(vec2d(map.w,map.h),maxp+vec2d(1,1)));
    //if(scale>1){imax+=vec2i(2,2);imin-=vec2i(2,2);}
  }
  int c=0;
  for(int y=imin.y;y<imax.y;y++)for(int x=imin.x;x<imax.x;x++)
  {        
    //auto pos=vec2d(qDev.xf*(vec2d(x,y)*block_size-offset))+qDev.viewport.pos;
    auto coord=vec2d(x,y);//get_block_size;
    auto center=map.map_to_world(coord);
    auto pos=vec2d(qDev.xf*center)+qDev.viewport.pos;
    if(vp.clamp(pos)!=pos)continue;
    int mem_id=x+y*map.w;
    //auto minid=QAP_MINVAL_ID_OF_VEC(maps,ex.mem[mem_id]<0?100500:ex.mem[mem_id]);
    auto v=map.mem[mem_id]/2;//maps[minid].mem[x+y*map.w]/2;
    qDev.color.a=0x20;
    //if(vp.clamp(pos)!=pos){qDev.color.a=0xff;v-=0x40;};
    qDev.color.r=v;
    qDev.color.g=v;
    qDev.color.b=v;
    qDev.DrawQuad(center,block_size,block_size);c++;
    if(v==0x50){qDev.color=0xffFF0000;qDev.DrawQuad(center,vec2d(4,4));}
    if(v==0x5F){qDev.color=0xffFFFF00;qDev.DrawQuad(center,vec2d(4,4));}
  }
}