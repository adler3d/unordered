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

t_out "main"(t_inp inp)asm
{
  var t_out out
  call "main_test" out inp
  ret out
}


t_out "main_test"(t_inp inp)asm
{
  var t_out out
  {var int x{}call "mov" x 20}
  {var int x{}call "mov" x 20}
  call "circle" out out inp.x inp.y 18
  ret out
}









