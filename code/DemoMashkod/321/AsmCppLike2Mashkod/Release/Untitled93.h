  struct vec2i{    int x=0; int y=0;  };
  
  struct t_quad{    vec2i a;    vec2i b;  };
  struct t_abc{int a;int b;int c;};
  t_abc foo(t_quad q,vec2i offset,vec2i unused){   return tmp;  }
  vec2i f(int x,vec2i p){return p;}
  int new_main(){
    t_quad q;
    t_abc abc=foo(q,f(0,vec2i(10,10)),vec2i(0,1));
  }
void push(t_ptr_offset&ref,int&pos_var){sub(esp,size(ref));copy(esp,ref,size(ref);pos_var+=size(ref);}
#define PUSHVAR(TYPE,retval)sub(esp,size(TYPE));pos_var+=size(TYPE);VAR(TYPE,retval);
#define push(var)push(var,pos_var);
#define lea(esp,retval)QapAssert(string("esp")==string(#esp));pos_var=retval.offset+size(retval);
      VAR("t_qaud",q);
      VAR("t_abc",abc);
      {
        VAR("t_abc",tmp1000);
          push(q);
          VAR("vec2i",tmp1001);
            push(0);
            VAR("vec2i",tmp1005);
              push(10);
              push(10);
            call("vec2i(int,int)");lea(esp,tmp1005);
          call("f(int,vec2i)");lea(esp,tmp1001);
          VAR("vec2i",tmp1002);
            push(0);
            push(1);
          call("vec2i(int,int)");lea(esp,tmp1002);
        call("foo(int,vec2i,vec2i");lea(esp,tmp1000);
        copy(abc,tmp1000);
        {
          
          {
            PUSHVAR("vec2i",retval);
            {
              push(0);
              push(1);
              call("vec2i(int,int)");
            }
            lea(esp,retval);
            copy_back(retval);//copy(esp+size(retval),esp,size(retval));
          }
          {
            PUSHVAR("vec2i",retval);
            {
              push(0);
              push(1);
              call("vec2i(int,int)");
            }
            lea(esp,retval);
            copy_back(retval);//copy(esp+size(retval),retval,size(retval));
          }
          call("foo(int,vec2i,vec2i");
        }
        lea(esp,retval);
        copy(abc,retval);
        dtor(
      }