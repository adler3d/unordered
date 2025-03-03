//V5
{
  string main(int w,int h)
  {
    string v="begin"+"\n";
    for(int y=0;y<h;y++)
    {
      v+="|"; int next_y=1+y;
      for(int x=0;x<w;x++)
      {
        string n=".";
        if(x==32){if(y<3){n=" ";}else{n="#";}}
        if(y==0){n="-";}
        if(next_y==h){n="-";}
        if(y==8){if(x<8){n=" ";}else{n="#";}}
        v+=n;
      }
      v+="|";
      if(next_y==h){continue;}
      v+="\n";
    }
    return v+"\nend";
  }
  return main(64,16);
}
//V4
{
  string inc(int value){int v=value;for(int t=0;t<1;v++){t=1;}return v;}
  string less(int x,int y){for(int t=0;x<y;t++){return 1;}return 0;}
  string v="begin"+"\n"; int h=16; int w=128;
  for(int y=0;y<h;y++)
  {
    v+="|"; int next_y=inc(y);
    for(int x=0;x<w;x++)
    {
      string n=".";
      if(x==32){if(less(y,3)==1){n=" ";}else{n="#";}}
      if(y==0){n="-";}
      if(next_y==h){n="-";}
      if(y==8){if(less(x,8)==1){n=" ";}else{n="#";}}
      v+=n;
    }
    v+="|";
    if(next_y==h){}else{v+="\n";continue;}
  }
  return v+"\nend";
}
//V3
{
  string inc(string value){string v=value;for(string t="0";t<"1";v++){t="1";}return v;}
  string less(string x,string y){for(string t="0";x<y;t++){return "1";}return "0";}
  string v="begin"+"\n"; string h="16"; string w="128"; //if("0"=="1") {} else {return ":)";}
  for(string y="0";y<h;y++)
  {
    v+="|"; string next_y=inc(y);
    for(string x="0";x<w;x++)
    {
      string n=".";
      if(y=="0"){n="-";} if(next_y==h){n="-";} if(y=="8"){if(less(x,"8")=="1"){n=" ";}else{n="#";}}
      v+=n;
    }
    v+="|";
    if(next_y==h){}else{v+="\n";continue;}
  }
  return v+"\nend";
}
//V2
{
  string tohtml(string code){return "<html>"+code+"</html>";}
  string foo(string s){return "["+s+"]";}
  return tohtml(__cur_date_str())+" => "+foo("other message");
}
//V1
{
  string tohtml(string code){
    string tmp="<html>";
    string out="</html>";
    out=code+out;
    out=tmp+out;
    return out;
  }
  string value="";
  value=tohtml("2013.11.12 11:37");
  value+=" => ";
  string foo(string s){
    string out="[";
    out=out+s;
    out+="]";
    return out;
  }
  string x="";
  x=foo("other message");
  value=value+x;
  return value;
}