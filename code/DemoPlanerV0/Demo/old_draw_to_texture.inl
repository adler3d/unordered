    int c=0;int maxv=-1;int minv=-1;static int prevmin=-1;static int prevmax=-1;static real prevsum=0;static real prevn=0;static real prevr=0;static real prevdiffsum=0;
    int divider=abs(prevmax-prevmin);if(divider<=0)divider=2;
    //float invd=255.0/divider;
    int low=prevmin;//+divider/4;
    int top=prevmax;//-divider/4;
    real avr=prevn<=0?128:prevsum/prevn;
    real ggg=prevn<=0?128:4.0*prevdiffsum/prevn;//std::min(abs(top-avr),abs(avr-low));
    low=std::max<int>(1,avr-ggg);
    top=avr+ggg;
    int nd=abs(top-low);if(nd<=0)nd=2;
    float invd=255.0/nd;auto vps=vp;vps.size*=0.125;
    real r=std::min(vp.size.x,vp.size.y)*0.5;real invr=1.0/r;real cr=r*0.25;real invcr=1.0/cr;
    real sum=0;real n=0;real diffsum=0;
    //---
    auto&tex=*qt.Tex;
    D3DLOCKED_RECT rect;
    tex.LockRect(0,&rect,NULL,0);auto*pBits=(QapColor*)rect.pBits;
    for(int y=0;y<map.h;y++)for(int x=0;x<map.w;x++)
    {
      auto coord=vec2d(x,y);//get_block_size;
      auto center=map.map_to_world(coord);
      auto pos=vec2d(qDev.xf*center)+qDev.viewport.pos;
      //if(!point_in_quad(vp,pos))continue;
      int mem_id=x+y*map.w;
      auto&out=pBits[mem_id];
      auto v=map.mem[mem_id];
      int z=-1;
      if(v>=0)
      {
        //if(vp.pos.dist_to_point_less_that_r(pos,r))
        {
          real dist=vp.pos.dist_to(pos);
          real mass=dist<cr?1:((dist-cr)*invcr);
          diffsum+=abs(v-avr)*mass;
          n+=mass;sum+=v*mass;//*vp.pos.dist_to(pos)*invr;
          maxv=maxv<0?v:std::max(maxv,v);
          minv=minv<0?v:std::min(minv,v);
        }
        z=v<low?0:(v>top?0xff:int(float(v-low)*invd));
      }
      if(z<0){
        if(v<low)z=0xff;
        if(v>top)z=0x00;
      }
      out.a=0xFF;
      //if(vp.clamp(pos)!=pos){qDev.color.a=0xff;v-=0x40;};
      out.r=255-z;
      out.g=255-z;
      out.b=255-z;
      //out=0x80AA44AA;
    }
    prevmin=minv;prevmax=maxv;prevr=r;prevn=n;prevsum=sum;prevdiffsum=diffsum;
    tex.UnlockRect(0);