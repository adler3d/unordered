;���, ����
struct t_out{
  t_buff arr;
  int pos;
}

t_out push_char(t_out inp,int value){
  auto out=inp;
  if(!(pos%4))out.arr[pos/4]=0;
  out.arr[pos/4][pos%4]=value;
  out.pos++;
  return out;
}

;8mb out,8b inp
asm main,8388608,64
{
  call "t_out::init" out_buff
  mov r inp[0]
  mov color inp[1]
  mul w r 2
  div d 256 w
  mul c w w
  loop:
  {
    mov i 0
    cond:
    {
      less falg i c
      jnz body
      jmp end
    }
    body:
    {
      mod x i w
      div y i w
      call "f" flag x y r
      jnz flag background
      jmp calccolor
      nop
      calccolor:
      {
        mul R x d
        mul G y d
        mov B 0
        call "t_out::push_rgb" out_buff R G B
        jmp next
      }
      background:
      {
        mov R 0
        mov G 0
        mov B 0
        movc R 0 m 0
        movc G 0 m 1
        movc B 0 m 2
        call "t_out::push_rgb" out_buff R G B
        jmp next
      }
      nop
    }
    next:
    {
      inc i
      jmp cond
    }
    nop
  }
  end:
  {
    
  }
}
asm,"f",8,8*4*3
{
  mov x inp[0]
  mov y inp[1]
  mov r inp[2]
  nop
  sub a x r
  sub b y r
  mul aa a a
  mul bbb b b
  add aabb aa bb
  mul rr r r
  more flag aabb rr
  nop
  ret flag
}
asm,"t_out::push_rgb",?,?
{
  mov R inp[0]
  mov G inp[1]
  mov B inp[2]
  nop
  call "push_char" out R
  call "push_char" out G
  call "push_char" out B
  ret out
}

struct t_out{
  t_buff arr;
  int pos;
}

asm,"push_char"(t_out out,int value)
{
  call "mod" tmp out.pos 4
  if(tmp)
  {
    ������ ���� push_char - ����� �����. ������ � ������ ������ �������� ��������� ��-�� ����?
    � ���� �������� ������ � �������� ��� � �� � �����-�� ���������� ������.
    ������� ������� ��������� �������� ������� �������� � ������, � �� � ������.
    ����� ����� � ���� ��� ����� ��������� ��������? � ��� ��� �� �����-�� �����.
    ��� �������� ��������� ��� �� ������� ������. ��� �������� �� �� �� �! � ������������ �����������. ��� ���.
    ����� �����-����� ��� �����.
  }
  call "div" tmp out.pos 4
  if(!(pos%4))out.arr[pos/4]=0;
  out.arr[pos/4][pos%4]=value;
  out.pos++;
  ret out
}

��� �����... ���� � ��� ����������� ����� ������ ��� �����, �� ����� ������� ������ � ��� out.
���� � �� ��������� out, �� � ��� inp ����� ������.
�� ���� � �� ���� ������ ��� �����, �� ����� ��� �������� ������ ��� ����.
����� ���������� ������ �� ����� ��� �� ������������� ��� ������� ��������� �� inp ������� ����������.
����� � ������� �������������� ���. �� ���� ��� ������������� ���, ����� � ���� ��������?
���������������������������������������������������������������������������������������������������!
���������������������������������������������������������������������������������������������������!
���������������������������������������������������������������������������������������������������!
���� ����������� ����� call, �� ����� ��������� ����������� ���� � �� ����������� inp/out ������.
���� ����������� inp/out, �� ��������� �� ����������� ���� � ����� call, ������, ������� �� ������ ������ ���������.
���������������������������������������������������������������������������������������������������!
���������������������������������������������������������������������������������������������������!
���������������������������������������������������������������������������������������������������!
���. ���������� � ������ �� ���� �������� � inp/out � ������ ������.
� ���� ����� call ������� �� ������ ���������� ���������� ��� ��������?
������ ���� ���  ���� ������ call, ���� ��� �� �������� �� ����� �������, � ������� ��� ����� ��������� ��� ������� �������.
������� �� ��� ������.
asm,"push_char",?,?
{
  mov t 4
  div J C t
  mod F C t
  jnz F skip
  mov T 0
skip:
  movc T F N 0
  mov t 2
  add J J t
  mov out[J] T
  inc C
  ret
}

beg:
  mov C 0
  mov r inp[0]
  mov m inp[1]
  mov t 2
  mul w r t
  mov t 256
  div d t w
loop:
  mov i 0
  mul c w w
cond:
  less b i c
  jnz b body
  jmp end
body:
  mod x i w
  div y i w
  sub a x r
  sub b y r
  mul a a a
  mul b b b
  add t a b
  mul q r r
  more b t q
  jnz b bg
cc:
  mul R x d
  mul G y d
  mov B 0
  call set_color
  jmp next
bg:
  mov R 0
  mov G 0
  mov B 0
  movc R 0 m 0
  movc G 0 m 1
  movc B 0 m 2
  call set_color
next:
  inc i
  jmp cond
end:
  mov t 3
  mul s c t
  mov t 4
  add s s t
  mov out[0] s
  mov out[1] c
  ret
finish:
set_color:
  mov N R
  call push_char
  mov N G
  call push_char
  mov N B
  call push_char
  ret
push_char:
  mov t 4
  div J C t
  mod F C t
  jnz F skip
  mov T 0
skip:
  movc T F N 0
  mov t 2
  add J J t
  mov out[J] T
  inc C
  ret
push_char_end: