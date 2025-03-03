void foo(){};
typedef decltype(foo) t_foo;
template<class>struct a{};
template<class>struct b{};
struct ttt{
  constexpr t_foo operator>>=(const ttt&)const{return foo;};
  constexpr t_foo operator>>=(int)const{return foo;};
  constexpr ttt(int){}
  constexpr ttt(){}
};
static const ttt c=0;
static const ttt d=0;

void func(a<b<c>>=d>>=8);
int main(){
  return 0;
}