; for function inlining {input smart asm stataments {=>} output smart asm statament}
{
  var int i
  {=>}
  var int sub_i
}

{
  var int j
  {=>}
  var int sub_j
}

{
  ret 10
  {=>}
  call "mov" $ 10
}

{
  ret x
  {=>}
  call "mov" $ x
}