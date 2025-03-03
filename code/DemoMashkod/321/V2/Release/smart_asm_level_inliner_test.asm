int "foo"(int x)asm
{
  var int result{call "mov" result 0}
  call "add" result x 50
  ret result
}
int "main"()asm
{
  var int x
  var int z
  call "mov" x 10
  call "mov" z 20
  call "foo" z x
  ret z
}

int "main"()asm
{
  var int v1__x
  var int v2__z
  call "mov" v1__x 10
  call "mov" v2__z 20
  loop:func_body
  {
    ;var int v5__x{call "mov" v5__x v1__x}
    {
      var int v5_1__result
      {
        call "mov" v5_1__result 0
      }
      call "add" v5_1__result v1__x 50
      call "mov" v2__z v5_1__result{break:func_body}
    }
  }
  ret v2__z
}


t_var_stat

how to detect a this case where t_var_stat 

we need find all places where we read or write some value into a var. and in this place we increase coresponding counter.


struct t_var_info{
  int id;
  string name;
  string type;
  int read_counter;
  int write_counter;
};

foreach_vars if var[i].write_counter=1 then mark var as proxy.


something in code interpretation
auto*p=t_var_stat::UberCast(ex.get());
if(!p)continue;

the place where some var are used we need insert other variable

need write new convertor

