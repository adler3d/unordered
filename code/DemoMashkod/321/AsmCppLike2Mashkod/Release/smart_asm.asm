struct vec2i{
  int x;
  int y;
}

bool "f"(int x,int y,int r)asm{
  var int xx
  var int yy
  var int rr
  call "mul" xx x x
  call "mul" yy y y
  call "mul" rr r r
  var int xx_yy
  call "add" xx_yy xx yy
  var bool flag
  call "more" flag xx_yy rr
  ret flag
}

struct vec3c{
  char r;
  char g;
  char b;
}

vec3c "mov"(vec3c inp)asm{ret inp}

array{vec3c,65536} "mov"(array{vec3c,65536} inp)asm{ret inp}

struct t_mem{
  int count;
  array{vec3c,65536} arr;
}

struct vec3i{
  int r;
  int g;
  int b;
}

t_mem "gen_img"(int r)asm{
  var int w
  call "mul" w r 2
  var int c
  call "mul" c w w
  var int dc
  call "div" dc 256 w
  var t_mem mem
  var array{vec3c,65536} arr
  call "mov" arr mem.arr
  var int mem_pos
  call "mov" mem_pos 0
  call "mov" mem.count c
  for{
    var int i
    init{
      call "mov" i 0
    }
    cond{
      var bool flag
      call "less" flag i c
      ret flag
    }
    body{
      var int x
      var int y
      call "mod" x i w
      call "div" y i w
      if{
        cond{
          var bool flag
          var int xr
          var int yr
          call "sub" xr x r
          call "sub" yr y r
          call "f" flag xr yr r
          ret flag
        }
        then{
          var vec3c bgcolor
          var char x
          call "char" x 225
          call "mov" bgcolor.r x
          call "mov" bgcolor.g x
          call "mov" bgcolor.b x
          call "mov" arr[mem_pos] bgcolor
          call "inc" mem_pos mem_pos
          continue
        }
      }
      nop
      var vec3c out
      var vec3i tmp
      call "mul" tmp.r x dc
      call "mul" tmp.g y dc
      call "char" out.r tmp.r
      call "char" out.g tmp.g
      nop
      call "mov" arr[mem_pos] out
      call "inc" mem_pos mem_pos
    }
    next{
      call "inc" i i
    }
  }
  call "mov" mem.arr arr
  ret mem
}

struct t_inp{
  int r;
  vec3c color;
  char unused;
}

t_mem "main"(int r)asm
{
  var t_mem mem
  call "gen_img" mem r
  ret mem
}