  mov i 0
  mov c inp[0]
cond:
  less b i c
  jnz b body
  jmp end
body:
  add a i i
  mov out[i] a
next:
  inc i
  jmp cond
end:
  mov out[0] s
  ret