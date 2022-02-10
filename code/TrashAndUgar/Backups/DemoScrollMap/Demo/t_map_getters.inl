t_elem&get(const vec2d&p){return get(p.x,p.y);}
const t_elem&get(const vec2d&p)const{return get(p.x,p.y);}
t_elem&get(const vec2i&p){return get(p.x,p.y);}
const t_elem&get(const vec2i&p)const{return get(p.x,p.y);}
t_elem&get_unsafe(int x,int y){return mem[x+y*w];}
const t_elem&get_unsafe(int x,int y)const{return mem[x+y*w];}
t_elem&get_unsafe(const vec2i&p){return mem[p.x+p.y*w];}
const t_elem&get_unsafe(const vec2i&p)const{return mem[p.x+p.y*w];}
t_elem&fail_id(){return sys_fail_id_const(*this);};
template<class T>static t_elem&sys_fail_id_const(T&v){const T&ref=(const T&)v;return (t_elem&)ref.fail_id();};
const t_elem&fail_id()const{static t_elem buff;set_to_def(buff);return buff;};
t_elem&get(int x,int y){if(x<0||y<0)return fail_id();if(x<w&&y<h)return get_unsafe(x,y);return fail_id();}
bool check(const vec2i&p)const{if(p.x<0||p.y<0||p.x+1>w||p.y+1>h)return false;return true;}
const t_elem&get(int x,int y)const{if(x<0||y<0)return fail_id();if(x<w&&y<h)return get_unsafe(x,y);return fail_id();}
int conv_vec_to_id(const vec2i&v)const{return v.x+v.y*w;}
vec2d world_to_map(const vec2d&pos)const{return map_offset+pos*inv_block_size;}
static vec2i tovec2i(const vec2d&p){return vec2i(p.x,p.y);}
vec2d world_to_cell(const vec2d&pos)const{return world_to_map(pos)+vec2d(0.5,0.5);}
vec2d map_to_world(const vec2d&pos)const
{
  return (pos-map_offset)*block_size;
};
void update_block_size(int newscale)
{
  scale=newscale;
  block_size=TGame::get_block_size()*scale;
  inv_block_size=1.0/real(block_size);
  w=map_max_size/scale;
  h=map_max_size/scale;
  map_offset=vec2d(w-1,h-1)*0.5;
  mem.resize(w*h);
}
void init(int newscale=1){update_block_size(newscale);}
vec2d map_offset;
int scale;
real inv_block_size;
real block_size;