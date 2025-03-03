{
  string v="begin"+"\n"; int h=16; int w=64;
  for(int y=0;y<h;y++)
  {
    v+="|";
    for(int x=0;x<w;x++)
    {
      string n=".";
      if(x==32){if(y<3){n=" ";}else{n="#";}}
      if(y==0||y+1==h){n="-";}
      if(y==8){if(x<8){n=" ";}else{n="#";}}
      v+=n;
    }
    v+="|";
    if(1+y==h){continue;}
    v+="\n";
  }
  return v+"\nend";
}