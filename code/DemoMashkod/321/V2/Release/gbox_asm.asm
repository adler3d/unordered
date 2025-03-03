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
  array{t_circle,1024} circles;
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
  var array{t_circle,1024} arr
  call "mov" arr out.circles
  var t_circle tmp
  call "circle" tmp x y r
  call "mov" arr[id] tmp
  call "inc" out.count out.count
  call "mov" out.circles arr
  ret out
}

int "X"()asm{var int v{call "mov" v 0}ret v}
int "Y"()asm{var int z{}ret z}

t_out "main"(t_inp inp)asm
{
  var t_out out
  loop{break}
  loop:core{
    call "main_new" out inp
    break:core
  }
  var bool flag{call "less" flag 0 1}
  var int iter
  call "mov" iter 0
  for:hehe
  {
    cond{ret flag}
    body{
      for{
        body{
          call "inc" iter iter
          continue:hehe{nop}
        }
      }
      {nop}
    }
    next{call "less" flag 1 0}
  }
  loop{
    break
    if{cond{ret flag}then{ nop }else{ nop }}
  }
  ret out
}

int "calc_sqr_dist"(int x,int y)asm{
  var int xx
  var int yy
  call "mul" xx x x
  call "mul" yy y y
  var int v{call "add" v xx yy}
  ret v
}

bool "check_dist"(int x,int y,int r)asm
{
  var bool result
  call "sub" x x r
  call "sub" y y r
  var int sqr_dist
  call "calc_sqr_dist" sqr_dist x y
  var int rr
  call "mul" rr r r
  call "less" result sqr_dist rr
  if{cond{ret result}then{
    var int v
    call "sub" v r 2
    call "mul" v v v
    call "more" result sqr_dist v
    ret result
  }}
  ret result
}

int "sqrt"(int v)asm
{
  var int result
  for{
    var int i
    init{
      call "mov" i 0
    }
    cond{
      var bool flag
      var int s
      call "mul" s i i
      call "less" flag s v
      ret flag
    }
    body{
      call "mov" result i
    }
    next{
      call "inc" i i
    }
  }
  ret result
}

int "zoom"(int a,int d,int i,int count)asm{
  var int p
  call "mul" p d i
  call "div" p p count
  call "add" p p a
  ret p
}

t_out "add_line"(t_out out,int ax,int ay,int bx,int by)asm
{
  var int count
  var int x
  var int y
  call "sub" x bx ax
  call "sub" y by ay
  var int m
  call "calc_sqr_dist" m x y
  call "sqrt" m m
  call "mov" count 10
  call "div" count m 10
  for{
    var int i
    init{
      call "mov" i 0
    }
    cond{
      var bool flag
      call "less" flag i count
      ret flag
    }
    body{
      var int px
      var int py
      call "zoom" px ax x i count
      call "zoom" py ay y i count
      call "circle" out out px py 4
      nop
    }
    next{
      call "inc" i i
    }
  }
  ret out
}

t_out "add_circle"(t_out out,int px,int py)asm
{
  for{
    var int i
    init{
      call "mov" i 0
    }
    cond{
      var bool flag
      call "less" flag i 256
      ret flag
    }
    body{
      var int x
      var int y
      call "mod" x i 16
      call "div" y i 16
      if{
        cond{
          var bool flag
          call "check_dist" flag x y 8
          ret flag
        }
        then{
          call "mul" x x 10
          call "mul" y y 10
          call "add" x x px
          call "sub" y py y
          call "circle" out out x y 4
        }else{}
      }
      nop
    }
    next{
      call "inc" i i
    }
  }
  ret out
}

t_out "main_new"(t_inp inp)asm
{
  var t_out out
  call "add_circle" out out 100 500
  call "add_circle" out out 300 300
  call "add_circle" out out 100 200
  call "add_line" out out 600 500 500 50
  call "add_line" out out 80 580 780 350
  call "circle" out out inp.x inp.y 16
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
      var array{t_circle,1024} sub_arr
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
  var array{t_circle,1024} arr
  for{
    var int i
    init{
      call "mov" i 0
    }
    cond{
      var bool flag
      call "less" flag i 255
      ret flag
    }
    body{
      var int x
      var int y
      var int id
      var int x_offset
      call "mod" x_offset inp.tick 16
      call "mod" id i 20
      call "mul" x id 35
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
      call "div" y i 20
      call "mul" y y 35
      call "sub" y 500 y
      var t_circle tmp
      call "circle" tmp x y 8
      call "mov" arr[i] tmp
    }
    next{
      call "inc" i i
    }
  }
  call "mov" out.count 255
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



















