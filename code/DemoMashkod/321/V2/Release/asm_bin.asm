  nop
  mov t 0
  jz t start
start:
  jmp beg
nop:
  mov a 4
  mov b 2
  mov k 4
  mul c b k
  add a a c
  mov out[0] a
  mov out[1] b
  mov t 255
  mov out[2] t
  mov out[3] t
  ret
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