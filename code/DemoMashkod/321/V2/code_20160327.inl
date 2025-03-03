C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Packages\Debugger\Visualizers

bool go_any_char(char&body,const CharMask&any){
  if(mem.empty())return false;
  if(pos>=mem.size())return false;
  auto ok=any[mem[pos]];
  if(!ok)return false;
  body=mem[pos];
  pos++;
  return true;
}

bool go_any_char(t_load_dev&dev,char&body,const CharMask&any){
  if(vector{char}::empty(dev.mem))return false;
  if(dev.pos>=vector{char}::size(dev.mem))return false;
  bool ok=CharMask::at(any,vector{char}::at(dev.mem,dev.pos));
  if(!ok)return false;
  body=vector{char}::at(dev.mem,dev.pos);
  dev.pos++;
  return true;
}

{proc("bool go_any_char(t_load_dev&,char&,const CharMask&)")
{
  RETTYPE(bool);
  PARAM(t_load_dev&,dev);
  PARAM(char&,body);
  PARAM(CharMask&,any);
  {
    ESP_SCOPE();
    PUSH(vector{char}&,dev.mem);
    call("bool vector{char}::empty(vector{char}&)")
  }
  {IF(eax){
    mov(eax,0);
    ret();
  }}
  VAR(int,N);
  PUSH(vector{char}&,dev.mem);// как получить адрес поля? тупо смещение. да. ссылка. значит адрес ссылки нужно запушить на стек. или лучше в eax уложить?
  call("int vector{char}::size(vector{char}&)");
  mov(N,eax);
  notless(eax,dev.pos,n);
  
  {IF(eax){
    mov(eax,0);
    ret();
  }}
  bool ok=CharMask::at(any,vector{char}::at(dev.mem,dev.pos));
  if(!ok)return false;
  body=vector{char}::at(dev.mem,dev.pos);
  dev.pos++;
  return true;
}}