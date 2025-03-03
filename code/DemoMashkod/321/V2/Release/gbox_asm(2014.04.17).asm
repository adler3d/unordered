struct vec2i{
  int x;
  int y;
}
struct vec3c{
  char r;
  char g;
  char b;
}
struct t_circle{
  vec2i pos;
  int r;
}
struct t_line{
  vec2i a;
  vec2i b;
}
struct t_trigon{
  vec2i a;
  vec2i b;
  vec2i c;
}
struct t_rect{
  vec2i a;
  vec2i b;
}
struct t_pixel{
  vec2i p;
  vec3c color;
}
struct t_image{
  vec2i pos;
  int w;
  int h;
  array{vec3c,4096} arr;
}
struct t_pen{
  int w;
  vec3c color;
  t_out_dev dev;
}
struct t_brush{
  vec3c color;
  t_out_dev dev;
}
struct t_out_dev{
  t_out_dev_pack pack;
  array{int,256} arr;
}
struct t_out_dev_pack{
  array{t_circle,32} circles;
  array{t_line,32} lines;
  array{t_trigon,32} trigons;
  array{t_rect,32} rects;
  array{t_pixel,32} pixels;
  array{t_image,1} images;
  array{t_pen,32} pens;
  array{t_brush,32} brushs;
}
struct t_out{
  int count;
  array{t_circle,128} circles;
}
struct t_inp{
  int tick;
  int x;
  int y;
}
t_circle "circle"(int x,int y,int r)asm
{
  var t_circle tmp
  var vec2i p
  call "mov" p.x x
  call "mov" p.y y
  call "mov" tmp.pos p
  call "mov" tmp.r r
  ret tmp
}

t_out "circle"(t_out out,int x,int y,int r)asm
{
  var int id
  call "mov" id out.count
  var array{t_circle,128} arr
  call "mov" arr out.circles
  var t_circle tmp
  call "circle" tmp x y r
  call "mov" arr[id] tmp
  call "inc" out.count out.count
  call "mov" out.circles arr
  ret out
}

int "X"()asm{var int v{call "mov" v 0}ret v}
int "Y"()asm{var int z{} z=1 {auto x=z}ret 0}

t_out "main"(t_inp inp)asm
{
  var t_out out
  loop{break}
  loop:core{
    call "main_fast" out inp
    break:core
  }
  var bool flag{call "mov" flag true}
  var int iter
  call "mov" iter 0
  for:hehe
  {
    cond{ret flag}
    body{
      for{
        body{
          call "inc" iter iter
          continue:hehe{call "fail_0" flag}
        }
      }
      {call "fail_1" flag}
    }
    next{call "mov" flag false}
  }
  loop{
    break
    if{cond{ret flag}then{ call "flag=true" flag }else{ call "flag=false" flag }}
  }
  ret out
}

t_out "main_test"(t_inp inp)asm
{
  var t_out out
  call "circle" out out inp.x inp.y 18
  {
    var t_out top_out{call "mov" top_out out}
    var int top_x{call "mov" top_x inp.x}
    var int top_y{call "mov" top_y inp.y}
    var int top_r{call "mov" top_r 16}
    var t_out $
    {
      var t_out sub_out{call "mov" sub_out top_out}
      var int sub_x{call "mov" sub_x top_x}
      var int sub_y{call "mov" sub_y top_y}
      var int sub_r{call "mov" sub_r top_r}
      var int sub_id
      call "mov" sub_id sub_out.count
      var array{t_circle,128} sub_arr
      call "mov" sub_arr sub_out.circles
      var t_circle sub_tmp
      call "circle" sub_tmp sub_x sub_y sub_r
      call "mov" sub_arr[sub_id] sub_tmp
      call "inc" sub_out.count sub_out.count
      call "mov" sub_out.circles sub_arr
      nop
      call "mov" $ sub_out
    }
    call "mov" out $
  }
  ret out
}

t_out "main_fast"(t_inp inp)asm
{
  var t_out out
  var array{t_circle,128} arr
  for{
    var int i
    init{
      call "mov" i 0
    }
    cond{
      var bool flag
      call "less" flag i 127
      ret flag
    }
    body{
      var int x
      var int y
      var int id
      var int x_offset
      call "mod" x_offset inp.tick 16
      call "mod" id i 16
      call "mul" x id 40
      call "add" x x 80
      if{
        cond{
          var bool flag
          call "less" flag x_offset 8
          ret flag
        }
        then{
          call "add" x x x_offset
        }
        else{
          call "sub" x_offset x_offset 8
          call "add" x x 8
          call "sub" x x x_offset
        }
      }
      call "div" y i 16
      call "mul" y y 40
      call "sub" y 500 y
      var t_circle tmp
      call "circle" tmp x y 8
      call "mov" arr[i] tmp
    }
    next{
      call "inc" i i
    }
  }
  call "mov" out.count 127
  call "mov" out.circles arr
  call "circle" out out inp.x inp.y 16
  ret out
}

t_out "main_slow"(t_inp inp)asm
{
  var t_out out
  for{
    var int i
    init{
      call "mov" i 0
    }
    cond{
      var bool flag
      call "less" flag i 127
      ret flag
    }
    body{
      var int x
      var int y
      var int id
      var int x_offset
      call "mod" x_offset inp.tick 16
      call "mod" id i 16
      call "mul" x id 40
      call "add" x x 80
      if{
        cond{
          var bool flag
          call "less" flag x_offset 8
          ret flag
        }
        then{
          call "add" x x x_offset
        }
        else{
          call "sub" x_offset x_offset 8
          call "add" x x 8
          call "sub" x x x_offset
        }
      }
      call "div" y i 16
      call "mul" y y 40
      call "sub" y 500 y
      call "circle" out out x y 8
    }
    next{
      call "inc" i i
    }
  }
  call "circle" out out inp.x inp.y 16
  ret out
}



















