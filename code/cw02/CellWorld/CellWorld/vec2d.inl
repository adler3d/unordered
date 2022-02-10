double lerp(double value,double min,double max){return min+value*(max-min);}
double clamp(double value,double min,double max){return std::max(min,std::min(max,value));}
double sign(double v){return v<0?-1:v>0?+1:0;}

typedef double real;
class vec2d{
public:
  real x,y;
public:
  vec2d(){}
  vec2d(const real&x,const real&y):x(x),y(y){}
  vec2d(const vec2d&v):x(v.x),y(v.y){}
  vec2d&operator=(const vec2d&v){x=v.x;y=v.y;return *this;}
  vec2d operator+()const{return *this;}
  vec2d operator-()const{return vec2d(-x,-y);}
  vec2d&operator+=(const vec2d&v){x+=v.x;y +=v.y;return *this;}
  vec2d&operator-=(const vec2d&v){x-=v.x; y-=v.y;return *this;}
  vec2d&operator*=(const real&f){x*=f;y*=f;return *this;}
  vec2d&operator/=(const real&f){x/=f;y/=f;return *this;}
public:
  vec2d Rot(const vec2d&OX)const{real M=OX.Mag();return vec2d(((x*+OX.x)+(y*OX.y))/M,((x*-OX.y)+(y*OX.x))/M);}
  vec2d UnRot(const vec2d&OX)const{real M=OX.Mag();if(M==0.0f){return vec2d(0,0);};return vec2d(((x*OX.x)+(y*-OX.y))/M,((x*OX.y)+(y*+OX.x))/M);}
  vec2d Ort()const{return vec2d(-y,x);}
  vec2d Norm()const{if((x==0)&&(y==0)){return vec2d(0,0);}return vec2d(x/this->Mag(),y/this->Mag());}
  vec2d SetMag(const real&val)const{return this->Norm().Mul(vec2d(val,val));}
  vec2d Mul(const vec2d&v)const{return vec2d(x*v.x,y*v.y);}
  vec2d Div(const vec2d&v)const{return vec2d(v.x!=0?x/v.x:x,v.y!=0?y/v.y:y);}
  real GetAng()const{return atan2(y,x);}
  real Mag()const{return sqrt(x*x+y*y);}
  real SqrMag()const{return x*x+y*y;}
public:
  static vec2d Vec2dEx(const real&ang,const real&mag){return vec2d(cos(ang)*mag,sin(ang)*mag);}
public:
  inline static real dot(const vec2d&a,const vec2d&b){return a.x*b.x+a.y*b.y;}
  inline static real cross(const vec2d&a,const vec2d&b){return a.x*b.y-a.y*b.x;}
};

vec2d operator+(const vec2d&u,const vec2d&v){return vec2d(u.x+v.x,u.y+v.y);}
vec2d operator-(const vec2d&u,const vec2d&v){return vec2d(u.x-v.x,u.y-v.y);}
vec2d operator*(const vec2d&u,const real&v){return vec2d(u.x*v,u.y*v);}
vec2d operator*(const real&u,const vec2d&v){return vec2d(u*v.x,u*v.y);}
bool operator==(const vec2d&u,const vec2d&v){return (u.x==v.x)&&(u.y==v.y);}
bool operator!=(const vec2d&u,const vec2d&v){return (u.x!=v.x)||(u.y!=v.y);}