#include <string>
using std::string;

#include "ImgLoader.h"
#include "Dynamic.h"
using std::vector;
struct png_function
{
  double m_w,m_h;
  vector<double> arr;
  void load(const string&fn)
  {
    TLoaderEnv Env;
    {
      ImgLoader::TextureMemory mem;
      Env.LoadTextureFromFile(mem,fn);
      struct rgba{unsigned char r,g,b,a;};
      rgba*ptr=(rgba*)mem.ptr;
      m_w=mem.W;
      m_h=mem.H;
      for(int x=0;x<mem.W;x++)
      {
        double h=mem.H;
        for(int y=0;y<mem.H;y++)
        {
          auto&c=ptr[x+y*mem.W];
          bool f=(c.r!=255)||(c.g!=255)||(c.b!=255);
          if(f)
          {
            h=y;
            break;
          }
          continue;
        }
        double H=mem.H;
        double result=1.0-h/H;
        arr.push_back(H-h);
      }
      Env.FreeMemory(mem);
    }
  }
  double eval_norm(double x_norm)
  {
    assert(x_norm>=0);
    assert(x_norm<=1.0);
    double x=x_norm*m_w;
    int a=x+0;
    int b=x+1;
    double v_a=arr[a];
    double v_b=arr[b];
    double dx=x-double(int(x));
    return lerp(dx,v_a,v_b)/m_h;
  }
};