#include "QapLite.h"
#include "PhysSystem.h"
float random(float min, float max)
{
  return min + (max - min) * (float(rand()) / float(RAND_MAX));
}

class TGame:public TD3DGameBoxBuilder{
public:
  bool need_init;
  PhysSystem physSystem;
  bool paused;
public:
  TGame()
  {
    need_init=true;
    paused=false;
  }
  void addgb(const vec2d&pos,const vec2d&size)
  {
    RigidBody *groundBody = physSystem.AddBody(
      Coords2f(Vector2f(pos.x,pos.y), 0.0f), Vector2f(size.x,size.y)
    );
    groundBody->invInertia = 0.0f;
    groundBody->invMass = 0.0f;
  }
  void Init()
  {
    need_init=false;
    auto wcs=vec2d(win.GetClientSize())*0.5;
    Vector2f windowSize(wcs.x,wcs.y);
    addgb(vec2d(wcs.x*0.5,-wcs.y*0.95),vec2d(wcs.x*2.0,10));
    windowSize.x*=0.5;
    windowSize.y*=0.5;
    float physicsTime = 0.0f;
    {
      RigidBody *draggedBody = physSystem.AddBody(
        Coords2f(Vector2f(windowSize.x * 0.1f, windowSize.y * 0.7f), 0.0f), Vector2f(30.0f, 30.0f));
    }
    addgb(vec2d(+wcs.x*0.95,0),vec2d(10,wcs.y*2.0));
    addgb(vec2d(-wcs.x*0.95,0),vec2d(10,wcs.y*2.0));
    addgb(vec2d(wcs.x*0.5,+wcs.y*0.95),vec2d(wcs.x*2.0,10));
    for(int i=0;i<40;i++)for(int bodyIndex = 0;bodyIndex < 40;bodyIndex++)
    {
      RigidBody *testBody = physSystem.AddBody(
        Coords2f(
          Vector2f(-600+i*20,-300+bodyIndex*10),0.0f), 
        Vector2f(1,1)*4.0
      );
      //testBody->invInertia = 0;
      testBody->velocity = Vector2f(00.0f, 0.0f);
    }
    if(0)for (int bodyIndex = 0; bodyIndex < 300; bodyIndex++)
    {
      RigidBody *testBody = physSystem.AddBody(
        Coords2f(Vector2f(windowSize.x * 0.0f, windowSize.y * 0.0f) + 
        Vector2f(random(-wcs.x,+wcs.x)*0.49, random(-wcs.y,+wcs.y)*0.49), 0.0f), 
        Vector2f(1.0f*(rand()%3+1), 1.0f)*4.0
      );
      //testBody->invInertia = 0;
      testBody->velocity = Vector2f(00.0f, 0.0f);
    }
  }
public:
  void RenderBoxOld(const Coords2f&coords,const Vector2f&size,const QapColor&color,int bs=4)
  {
    if(bs)
    {
      qDev.SetColor(0xFF000000);
      qDev.DrawQuad(vec2d(coords.pos.x,coords.pos.y),size.x*2,size.y*2,atan2(coords.xVector.y,coords.xVector.x));
    }
    qDev.SetColor(color);
    qDev.DrawQuad(vec2d(coords.pos.x,coords.pos.y),size.x*2-bs,size.y*2-bs,atan2(coords.xVector.y,coords.xVector.x));
  }
  void FastQuad(const Vector2f&pos,const Vector2f&size,const Vector2f&xv,const Vector2f&yv)
  {
    auto x=pos.x;auto y=pos.y;
    vec2d OZ=vec2d(xv.x,xv.y);auto w=size.x;auto h=size.y;
    vec2d O(x,y);
    int n=qDev.VPos;
    #define F(X,Y){auto p=pos+(X##w)*xv+(Y##h)*yv;auto&v=qDev.AddVertexRaw();v.color=qDev.color;v.get_pos()=vec2f(p.x,p.y);}
    F(-,-)F(+,-)F(+,+)F(-,+)
    #undef F
    qDev.AddTris(n+1,n+0,n+3);
    qDev.AddTris(n+3,n+2,n+1);
  }
  void RenderBox(const Coords2f&coords,const Vector2f&size,const QapColor&color,int bs=4)
  {
    if(bs)
    {
      qDev.SetColor(0xFF000000);
      FastQuad(coords.pos,size,coords.xVector,coords.yVector);
    }
    qDev.SetColor(color);
    FastQuad(coords.pos,size-Vector2f(1,1)*(bs>>1),coords.xVector,coords.yVector);
  }
  void DoMove()
  {
    if(win.Keyboard.Down[VK_ESCAPE])win.Close();
    if(need_init)Init();
    bool paused = 0;
    Vector2f mousePos = Vector2f(win.mpos.x,win.mpos.y);
    if(win.Keyboard.Down[VK_LSHIFT])
    {
      paused = true;
    }else{paused=false;}
    const float gravity = -200.0f;
    const float integrationTime = 2e-2f*0.25;
    if(!paused)
    {
      RigidBody *draggedBody = physSystem.GetBody(1);
      int n=1;
      for(int i=0;i<n;i++)
      {
        real k=1.0*real(n);
        for(size_t bodyIndex = 0; bodyIndex < physSystem.GetBodiesCount(); bodyIndex++)
        {
          physSystem.GetBody(bodyIndex)->acceleration = Vector2f(0.0f, 0.0f);
          physSystem.GetBody(bodyIndex)->angularAcceleration = 0.0f;
        }
        for(size_t bodyIndex = 0; bodyIndex < physSystem.GetBodiesCount(); bodyIndex++)
        {
          RigidBody *body = physSystem.GetBody(bodyIndex);
          if (body->invMass > 0.0f)
          {
            physSystem.GetBody(bodyIndex)->acceleration += Vector2f(0.0f, gravity*k);
          }
        }
        Vector2f dstVelocity = (mousePos - draggedBody->coords.pos) * 5e1f;
        if(win.Keyboard.Down[mbLeft])draggedBody->acceleration += (dstVelocity - draggedBody->velocity) * (1.0e1*k);
        physSystem.Update(integrationTime*1.0/double(n));
      }
    }

    bool pickingCollision = 0;
  }
  void DoDraw()
  {
    qDev.BindTex(0,nullptr);
    QapDev::BatchScope Scope(qDev);
    //qDev.SetColor(QapColor(255,50,50,50));qDev.DrawQuad(vec2d_zero,win.GetClientSize());
    for (size_t bodyIndex = 0; bodyIndex < physSystem.GetBodiesCount(); bodyIndex++)
    {
      RigidBody *body = physSystem.GetBody(bodyIndex);
      Coords2f bodyCoords = body->coords;
      Vector2f size = body->geom.size;
      QapColor color = QapColor(128, 128, 128);
      if (bodyIndex == 1) //dragged body
      {
        color = QapColor(242, 236, 164);
      }
      RenderBox(bodyCoords, size, color);
    }
    if(win.Keyboard.Down['C'])
    {
      for (Collider::ManifoldMap::iterator man = physSystem.GetCollider()->manifolds.begin(); man != physSystem.GetCollider()->manifolds.end(); man++)
      {
        for (int collisionNumber = 0; collisionNumber < man->second.collisionsCount; collisionNumber++)
        {
          Coords2f coords = Coords2f(Vector2f(0.0f, 0.0f), 3.1415f / 4.0f);
          coords.pos = man->second.body1->coords.pos + man->second.collisions[collisionNumber].delta1;
          coords.pos += man->second.body2->coords.pos + man->second.collisions[collisionNumber].delta2;
          coords.pos*=0.5;
          QapColor color2(255,255,255,255);
          RenderBox(coords, Vector2f(2.0f, 2.0f), QapColor(255,0,255,0),0);
        }
      }
    }
  }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  GlobalEnv global_env(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
  TGame builder;
  builder.DoNice();
}