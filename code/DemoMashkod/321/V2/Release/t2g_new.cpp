t_game_t2d{
  Tank{
    vec2d p;
    real w;
    real h;
    vec2d v;
    vec2d ta;
    vec2d dir;
    int BanTick;
    bool deaded;
    bool bot;
    bool IsMotor;
    bool IsTower;
    bool IsEvil;
    bool Crafty;
    vec2d bas;
    vec2d btar;
    real bspe;
    int EvilTick;
  }
  Bullet{
    vec2d p;
    vec2d v;
    real r;
    bool deaded;
    int dcount;
  }
  Brick{
    vec2d p;
    bool IsHome;
    bool deaded;
    bool undead;
  }
  Effect{
    array<vec2d,16> p;
    array<vec2d,16> v;
    int count;
    int tc;
    int t;
    bool deaded;
    bool isAdd;
    QapColor Color;
  }
  TankGen{vec2d p;int count;int type;}
  World{
    vector<Tank> tanks;
    vector<Tank> dtanks;
    vector<Bullet> bullets;
    vector<Bullet> dbullets;
    vector<Brick> bricks;
    vector<TankGen> TGL;
    vector<Effect> effects;
  }
}