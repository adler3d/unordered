void foo(bit a,bit b)asm
{
  or result a b
  
}

��� ������ �����.
��� ������ ���� � ����� ���������� �����?

����.
�������.

struct "vec2i"{
  "int" "x"
  "int" "y"
}

int "sum"(int x,int y)asm{
  "int"var r;
  ---
  "int"add r x y
  ret r
}

int "mag"(int x,int y)asm{
  "int"var xx;
  "int"var yy;
  "int"var rr;
  "int"var r;
  ---
  "int"mul xx x x
  "int"mul yy y y
  "int"add rr x y
  "int"sqrt r rr
  ret r
}

int "vec2i::mag(vec2i)"(vec2i v)asm{
  "int" x;
  "int" y;
  "int" xx;
  "int" yy;
  "int" rr;
  "int" r;
  ---
  "int"mov x v."x"
  "int"mov y v."y"
  "int"mul xx x x
  "int"mul yy y y
  "int"mul yy y y
  call "sum" rr x y
  "int"sqrt r rr
  ret r
}
struct "t_buff"{
  array{char,1024} arr;
}
t_buff ""(t_heap heap,int ptr,int size)asm{
  ;for(int i=0;i<size;i++){
  ;  result.arr[i]=heap.arr[ptr+i];
  ;}
  ;return result;
  ---
  
}

t_heap "string copy_string(t_heap,t_string)"(t_heap heap,t_string s)asm{
  "t_buff" buff;
  "int" ptr;
  "int" size;
  ---
  "int"mov ptr s.ptr
  "int"mov size s.size
  call "copy_from_heap" buff heap ptr size
}

����. ����� �� ���������.
��� ���� ����������

����. ����� ���-�� � ��� ���������� ���������� - �� �������� ������ � ��� �������.
�� ������������� ���-�� ���������� - ��� ������.
� ���� ������ ���� � ��� ����� �������� �� �������� � � ��������� ��������.
��� ����� ����������� ��������� �������.
��������, ��� ������ ��������� �� �������.
������ � ��������� �������� ��� ����, ��� � �� ���� ������� �� ������� ������ ������������ ������.
������ � ��������� ���������� ������ ������������� �������.
����. ��� � ��������� ������.
������ ������ ��� ������� � �������� ������������ ���-�� ���������� ������������� �������.

������ � ���� �������� � ������� ������.

"hi.\0"


����. ��� �� �����.
������ � ��� ���� ��� ������.
������ ��� ����� ���������� ���������� �� ����� ������� ������.

������ � ��� ������ ������� ������� ��� �������� ������� ������.
� ����� ���������� ������.
� ����� ����. ����������� ����.


���� �� ������ ����� ���� �� � ������ ������ ����� � ������, �� ������� ��� ������� ����� ��� ������� �����������.

������ ����� �����.
� ���� ������� ����.
� ���� ������� ������� ����.

������ � ���� ������� ������� ����.
� ���� ������� ���� ����� ...


� �� �������. � ����� ����������� � �����, ��� �� ��������� ����������� ����� ����.
� ��� ���� ����� ������������ ��� ���� �� ���������� ����� ���� �����.



���������� ��������� ����� ����
{
  ��� ������� � ��������� �����.
  ��������� �����, ��� ����� ���������� ���� ������ ��� ���� ����������.
  ����� ����������� �������� ���� ����������.
  � ������ �������� ����� �������� ����� ������.
  � �������� ����� ���������� ����.
  �� ���� � ����������� �������� ���������� ����, �� ����� ��������� �� ���������� � ����� ���������. ��� ����?
  ����� ��������� ��������� ����� ������.
  ������ ��� ������� ��������� ����. �� ������ ������� ��������� ���� ������� �������.
  ������ ��������� ������� ������ ���� �������� ������� ��������� ����, �� � ����� ���� ���, ������� ���������� �������� ������ � ����������.
}
���������� ��������� ���������.
{
  ��������� � ��������� �����.
  � �����. ��� ���� � ���, ��� � ��� ���� ������.
  � ������ ��� ����� �����, ������� ������ �������� ����� ��������, �.� � ������ ������ �� ��������.
}

struct t_buff{
  array{bit,1024}
}

bit or(bit a,bit b){
  return a||b;
}

"bit","or",("bit" a,"bit" b),asm{
  "bit" r
  ---
  "bit"or r a b
  ret r
}

array{bit,1} "bit,or,bit,bit"(array{bit,2} inp)asm{
  r 0
  ---
  a 0
  b 1
  ---
  "bit"mov mem[a] inp[a]
  "bit"mov mem[b] inp[b]
  "bit"or mem[r] mem[a] mem[b]
  mov out[r]
  ret
}

bit[1] "bit,or,bit,bit"(bit[2] inp)asm{...} - ����� �������.

asm"bit,or,bit,bit"1,2{
  r 0
  ---
  a 0
  b 1
  ---
  mov a [a]
  mov b [b]
  or c a b
  mov [r] c
  ret
}

asm"bit,or,bit,bit"1,2{
  mem[3]
  [---]
  mov a [0]
  mov b [1]
  or c a b
  mov [0] c
  ret
}

asm"bit,or,bit,bit"1,2{
  mem[3]???
  [---]
  mov mem[0] inp[0]
  mov mem[1] inp[1]
  or mem[2] mem[0] mem[1]
  mov out[0] mem[2]
  ret
}

struct byte{
  bits[8] arr;
}

byte or(byte a,byte b){
  byte c;
  for(int i=0;i<8;i++)c.arr[0]=a.arr[i]||b.arr[i];
  return c;
}

byte or(byte a,byte b){
  byte c;
  for(int i=0;i<8;i++){
    c.arr[0]=or(a.arr[i],b.arr[i]);
  }
  return c;
}

byte or(byte a,byte b){
  byte c;
  for(int i=0;i<8;i++){
    byte ai=a.arr[i];
    byte bi=b.arr[i];
    byte ci=c.arr[i];
    ci=or(ai,bi);
    c.arr[i]=ci;
  }
  return c;
}

"byte","or",("byte" a,"byte" b),asm{
  "byte" c;
  "bit" ai;
  "bit" bi;
  "bit" ci;
  "array{bit,8}" a_arr;
  "array{bit,8}" b_arr;
  "array{bit,8}" c_arr;
  ---
  "array{bit,8}"mov a_arr a.arr
  "array{bit,8}"mov b_arr b.arr
  "bit"mov ai a_arr[0]
  "bit"mov bi b_arr[0]
  "bit"or ci ai bi
  "bit"mov c_arr[0] ci
  nop
  "bit"mov ai a_arr[1]
  "bit"mov bi b_arr[1]
  "bit"or ci ai bi
  "bit"mov c_arr[1] ci
  nop
  ...
  nop
  "bit"mov ai a_arr[7]
  "bit"mov bi b_arr[7]
  "bit"or ci ai bi
  "bit"mov c_arr[7] ci
  "array{bit,8}"mov c.arr c_arr
  ret c
}

"byte","or",("byte" a,"byte" b),asm{
  "byte" c;
  "bit" ai;
  "bit" bi;
  "bit" ci;
  "array{bit,8}" a_arr;
  "array{bit,8}" b_arr;
  "array{bit,8}" c_arr;
  ---
  "array{bit,8}"mov a_arr a.arr
  "array{bit,8}"mov b_arr b.arr
  "int"mov i 0
  nop
  "bit"mov ai a_arr[0]
  "bit"mov bi b_arr[0]
  "bit"or ci ai bi
  "bit"mov c_arr[0] ci
  nop
  "array{bit,8}"mov c.arr c_arr
  ret c
}

���������������������������������������������������������������������������������������!!!!!!!!!



