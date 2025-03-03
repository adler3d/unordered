struct vec2i{
  int x;
  int y;
}

int "get_x"(int v,int b)asm
{
  ret v
}

int "get_x"(int v)asm
{
  ret v
}

int "get_x"(vec2i v)asm
{
  ret v.x
}

vec2i "vec2i"(int x,int y)asm
{
  var vec2i result
  call "mov" result.x x
  call "mov" result.y y
  ret result
}

int "func_name"()asm
{
  var int result
  call "mov" result 10
  ret result
}

int "func_name"(int x,int y)asm
{
  var int s
  {
    call "sub" s x y
    call "inc" s s
    call "add" s s 10
    call "add" s 194 s
    {
      var vec2i v
      call "vec2i" v x y
    }
  }
  ret s
}

int "main"()asm
{
  var int result
  call "func_name" result 100 200
  var vec2i tmp
  call "vec2i" tmp 10 20
  call "inc" tmp.x tmp.x
  call "add" tmp.x tmp.x 4
  call "mov" tmp.y tmp.x
  var int buff
  call "get_x" buff tmp.y
  call "add" result buff result
  var int counter
  for{
    var int i
    init{
      call "mov" i 0
      call "mov" counter 0
    }
    cond{
      var bool flag
      call "less" flag i 10
      ret flag
    }
    body{
      call "inc" counter counter
      if{
        cond{
          var bool flag
          call "less" flag counter 2
          ret flag
        }then{continue}else{break}
      }
    }
    next{
      call "inc" i i
    }
  }
  call "add" result counter result
  for{body{break}}
  {
    var int i
    var int counter
    call "mov" i 5
    call "mov" counter 10
    if{
      cond{
        var bool flag
        call "less" flag i 10
        ret flag
      }
      then{
        call "mov" counter 0
      }
      else{
        call "mov" counter 1
      }
    }
  }
  ret result
}

int "some_shit"()asm{
  var bool flag
  call "less" flag 1 0
  if
  {
    cond{ret flag}
    then
    {
      var int counter
      call "mov" counter 0
      start:
      var int i
      call "mov" i 0
      loop:{
        var bool flag
        call "less" flag i 10
        jnz flag body
        jmp end
      }
      body:{
        call "inc" counter counter
      }
      end:{
        call "add" result counter result
      }
    }else{}
  }
  var int retval
  call "mov" retval 1000
  ret retval
}

