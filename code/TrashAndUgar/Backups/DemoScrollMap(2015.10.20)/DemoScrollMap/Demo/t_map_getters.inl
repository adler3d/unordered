t_elem&get(const vec2d&p){return get(p.x,p.y);}
const t_elem&get(const vec2d&p)const{return get(p.x,p.y);}
t_elem&get(const vec2i&p){return get(p.x,p.y);}
const t_elem&get(const vec2i&p)const{return get(p.x,p.y);}
t_elem&get_unsafe(int x,int y){return mem[x+y*w];}
const t_elem&get_unsafe(int x,int y)const{return mem[x+y*w];}
t_elem&fail_id(){return sys_fail_id_const(*this);};
template<class T>static t_elem&sys_fail_id_const(T&v){const T&ref=(const T&)v;return (t_elem&)ref.fail_id();};
const t_elem&fail_id()const{static t_elem buff;set_to_def(buff);return buff;};
t_elem&get(int x,int y){if(x<0||y<0)return fail_id();if(x<w&&y<h)return get_unsafe(x,y);return fail_id();}
bool check(const vec2i&p)const{if(p.x<0||p.y<0||p.x+1>w||p.y+1>h)return false;return true;}
const t_elem&get(int x,int y)const{if(x<0||y<0)return fail_id();if(x<w&&y<h)return get_unsafe(x,y);return fail_id();}