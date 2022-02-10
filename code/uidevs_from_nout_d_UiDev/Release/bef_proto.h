int(7)
vector<EnvDefTypeStr>
{
  //0
  EnvDefTypeStr
  {
    Decl = EnvDefTypeSymbol
    {
      Decl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Def$$<DeclareTypeSys>::GetRTTI())
      }
      Name = string("DeclareTypeSys")
    }
    Impl = EnvDefEntryPoint
    {
      Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<DeclareTypeSys>::GetRTTI())
    }
  }
  ,
  //1
  EnvDefTypeStr
  {
    Decl = EnvDefTypeSymbol
    {
      Decl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Def$$<DeclareTypeVector>::GetRTTI())
      }
      Name = string("DeclareTypeVector")
    }
    Impl = EnvDefEntryPoint
    {
      Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<DeclareTypeVector>::GetRTTI())
    }
  }
  ,
  //2
  EnvDefTypeStr
  {
    Decl = EnvDefTypeSymbol
    {
      Decl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Def$$<DeclareTypeStruct>::GetRTTI())
      }
      Name = string("DeclareTypeStruct")
    }
    Impl = EnvDefEntryPoint
    {
      Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<DeclareTypeStruct>::GetRTTI())
    }
  }
}
int(49)
FullDeclareEnvRTTI
{
  DeclEnv = DeclareEnvRTTI
  {
    Arr = vector<TAutoPtr<DeclareType>>
    {
      //0
      TAutoPtr<DeclareType>
      {
        DeclareTypeSys
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<string>::GetRTTI())
          }
          FullName = string("string")
        }
      }
      ,
      //1
      TAutoPtr<DeclareType>
      {
        DeclareTypeSys
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<int>::GetRTTI())
          }
          FullName = string("int")
        }
      }
      ,
      //2
      TAutoPtr<DeclareType>
      {
        DeclareTypeSys
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<bool>::GetRTTI())
          }
          FullName = string("bool")
        }
      }
      ,
      //3
      TAutoPtr<DeclareType>
      {
        DeclareTypeSys
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<real>::GetRTTI())
          }
          FullName = string("real")
        }
      }
      ,
      //4
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobClock>::GetRTTI())
          }
          Name = string("TGabobClock")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("tick")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("interval")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("16")
            }
          }
        }
      }
      ,
      //5
      TAutoPtr<DeclareType>
      {
        DeclareTypeVector
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<vector<TGabobTeam>>::GetRTTI())
          }
          ElementType = TWeakPtr<DeclareType>(Def$$<TGabobTeam>::GetRTTI())
        }
      }
      ,
      //6
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobTeam>::GetRTTI())
          }
          Name = string("TGabobTeam")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("name")
              Type = TWeakPtr<DeclareType>(Def$$<string>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("spamteam")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //2
            DeclareMember
            {
              Name = string("always_spam")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //3
            DeclareMember
            {
              Name = string("dummy")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //4
            DeclareMember
            {
              Name = string("smart")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //5
            DeclareMember
            {
              Name = string("workinteam")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //6
            DeclareMember
            {
              Name = string("select_best_teammate")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //7
            DeclareMember
            {
              Name = string("select_near_target")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //8
            DeclareMember
            {
              Name = string("bullet_time_control")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //9
            DeclareMember
            {
              Name = string("withoutrules")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //10
            DeclareMember
            {
              Name = string("fire_when_target_is_empty")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //11
            DeclareMember
            {
              Name = string("ai_withoutrules_use_trace_depth")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //12
            DeclareMember
            {
              Name = string("ai_withoutrules_trace_depth")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("768")
            }
            ,
            //13
            DeclareMember
            {
              Name = string("number_of_dirs_for_trace")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("720")
            }
            ,
            //14
            DeclareMember
            {
              Name = string("max_help_tick")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("8")
            }
            ,
            //15
            DeclareMember
            {
              Name = string("help_dist")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("150")
            }
            ,
            //16
            DeclareMember
            {
              Name = string("frags_eat")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //17
            DeclareMember
            {
              Name = string("unfrags")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //18
            DeclareMember
            {
              Name = string("frags")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //19
            DeclareMember
            {
              Name = string("shots")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //20
            DeclareMember
            {
              Name = string("hits")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //21
            DeclareMember
            {
              Name = string("unhits")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //22
            DeclareMember
            {
              Name = string("last_unit_id")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //23
            DeclareMember
            {
              Name = string("last_bullet_id")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //24
            DeclareMember
            {
              Name = string("color")
              Type = TWeakPtr<DeclareType>(Def$$<QapColor>::GetRTTI())
              Mode = string("SET")
              Value = string("0xffffffff")
            }
            ,
            //25
            DeclareMember
            {
              Name = string("units")
              Type = TWeakPtr<DeclareType>(Def$$<vector<TGabobUnit>>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //26
            DeclareMember
            {
              Name = string("bullets")
              Type = TWeakPtr<DeclareType>(Def$$<TGabobBullets>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
      ,
      //7
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<QapColor>::GetRTTI())
          }
          Name = string("QapColor")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("b")
              Type = TWeakPtr<DeclareType>(Def$$<uchar>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("g")
              Type = TWeakPtr<DeclareType>(Def$$<uchar>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //2
            DeclareMember
            {
              Name = string("r")
              Type = TWeakPtr<DeclareType>(Def$$<uchar>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //3
            DeclareMember
            {
              Name = string("a")
              Type = TWeakPtr<DeclareType>(Def$$<uchar>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
      ,
      //8
      TAutoPtr<DeclareType>
      {
        DeclareTypeSys
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<uchar>::GetRTTI())
          }
          FullName = string("uchar")
        }
      }
      ,
      //9
      TAutoPtr<DeclareType>
      {
        DeclareTypeVector
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<vector<TGabobUnit>>::GetRTTI())
          }
          ElementType = TWeakPtr<DeclareType>(Def$$<TGabobUnit>::GetRTTI())
        }
      }
      ,
      //10
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobUnit>::GetRTTI())
          }
          Name = string("TGabobUnit")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("need_remove")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("name")
              Type = TWeakPtr<DeclareType>(Def$$<string>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //2
            DeclareMember
            {
              Name = string("target")
              Type = TWeakPtr<DeclareType>(Def$$<string>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //3
            DeclareMember
            {
              Name = string("clock")
              Type = TWeakPtr<DeclareType>(Def$$<TGabobClock>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //4
            DeclareMember
            {
              Name = string("phys")
              Type = TWeakPtr<DeclareType>(Def$$<TGabobPhys>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //5
            DeclareMember
            {
              Name = string("need_help_tick")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //6
            DeclareMember
            {
              Name = string("life")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("10")
            }
            ,
            //7
            DeclareMember
            {
              Name = string("frags")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //8
            DeclareMember
            {
              Name = string("total_hits")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //9
            DeclareMember
            {
              Name = string("total_shots")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //10
            DeclareMember
            {
              Name = string("frags_eat")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //11
            DeclareMember
            {
              Name = string("wait_new_target")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
      ,
      //11
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobPhys>::GetRTTI())
          }
          Name = string("TGabobPhys")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("pos")
              Type = TWeakPtr<DeclareType>(Def$$<vec2d>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("v")
              Type = TWeakPtr<DeclareType>(Def$$<vec2d>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
      ,
      //12
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<vec2d>::GetRTTI())
          }
          Name = string("vec2d")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("x")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("SET")
              Value = string("0.0")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("y")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("SET")
              Value = string("0.0")
            }
          }
        }
      }
      ,
      //13
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobBullets>::GetRTTI())
          }
          Name = string("TGabobBullets")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("raws")
              Type = TWeakPtr<DeclareType>(Def$$<vector<TGabobBulletRaw>>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
      ,
      //14
      TAutoPtr<DeclareType>
      {
        DeclareTypeVector
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<vector<TGabobBulletRaw>>::GetRTTI())
          }
          ElementType = TWeakPtr<DeclareType>(Def$$<TGabobBulletRaw>::GetRTTI())
        }
      }
      ,
      //15
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobBulletRaw>::GetRTTI())
          }
          Name = string("TGabobBulletRaw")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("need_remove")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("name")
              Type = TWeakPtr<DeclareType>(Def$$<string>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //2
            DeclareMember
            {
              Name = string("owner")
              Type = TWeakPtr<DeclareType>(Def$$<string>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //3
            DeclareMember
            {
              Name = string("phys")
              Type = TWeakPtr<DeclareType>(Def$$<TGabobPhys>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
      ,
      //16
      TAutoPtr<DeclareType>
      {
        DeclareTypeVector
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<vector<TGabobExplosion>>::GetRTTI())
          }
          ElementType = TWeakPtr<DeclareType>(Def$$<TGabobExplosion>::GetRTTI())
        }
      }
      ,
      //17
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobExplosion>::GetRTTI())
          }
          Name = string("TGabobExplosion")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("name")
              Type = TWeakPtr<DeclareType>(Def$$<string>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("auto_move")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("SET")
              Value = string("true")
            }
            ,
            //2
            DeclareMember
            {
              Name = string("auto_draw")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("SET")
              Value = string("true")
            }
            ,
            //3
            DeclareMember
            {
              Name = string("blend_add")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("SET")
              Value = string("true")
            }
            ,
            //4
            DeclareMember
            {
              Name = string("pos")
              Type = TWeakPtr<DeclareType>(Def$$<vec2d>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //5
            DeclareMember
            {
              Name = string("tick")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //6
            DeclareMember
            {
              Name = string("max_tick")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("64")
            }
            ,
            //7
            DeclareMember
            {
              Name = string("particle_beg_size")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("SET")
              Value = string("2")
            }
            ,
            //8
            DeclareMember
            {
              Name = string("particle_end_size")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("SET")
              Value = string("8")
            }
            ,
            //9
            DeclareMember
            {
              Name = string("particle_beg_color")
              Type = TWeakPtr<DeclareType>(Def$$<QapColor>::GetRTTI())
              Mode = string("SET")
              Value = string("0xff000000")
            }
            ,
            //10
            DeclareMember
            {
              Name = string("particle_end_color")
              Type = TWeakPtr<DeclareType>(Def$$<QapColor>::GetRTTI())
              Mode = string("SET")
              Value = string("0x00000000")
            }
            ,
            //11
            DeclareMember
            {
              Name = string("particle_life_time")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("32")
            }
            ,
            //12
            DeclareMember
            {
              Name = string("particle_per_tick")
              Type = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
              Mode = string("SET")
              Value = string("4")
            }
            ,
            //13
            DeclareMember
            {
              Name = string("particle_min_speed")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("SET")
              Value = string("100.0/64.0")
            }
            ,
            //14
            DeclareMember
            {
              Name = string("particle_max_speed")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("SET")
              Value = string("400.0/64.0")
            }
            ,
            //15
            DeclareMember
            {
              Name = string("particle_pos_dist")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("SET")
              Value = string("32")
            }
            ,
            //16
            DeclareMember
            {
              Name = string("particle_pos_dist_var")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("SET")
              Value = string("16")
            }
            ,
            //17
            DeclareMember
            {
              Name = string("particle_grav")
              Type = TWeakPtr<DeclareType>(Def$$<vec2d>::GetRTTI())
              Mode = string("SET")
              Value = string("vec2d_zero")
            }
            ,
            //18
            DeclareMember
            {
              Name = string("undeadable")
              Type = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //19
            DeclareMember
            {
              Name = string("arr")
              Type = TWeakPtr<DeclareType>(Def$$<vector<TGabobParticle>>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
      ,
      //18
      TAutoPtr<DeclareType>
      {
        DeclareTypeVector
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<vector<TGabobParticle>>::GetRTTI())
          }
          ElementType = TWeakPtr<DeclareType>(Def$$<TGabobParticle>::GetRTTI())
        }
      }
      ,
      //19
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobParticle>::GetRTTI())
          }
          Name = string("TGabobParticle")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("pos")
              Type = TWeakPtr<DeclareType>(Def$$<vec2d>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("v")
              Type = TWeakPtr<DeclareType>(Def$$<vec2d>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //2
            DeclareMember
            {
              Name = string("t")
              Type = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
      ,
      //20
      TAutoPtr<DeclareType>
      {
        DeclareTypeStruct
        {
          DeclareType
          {
            Self = TSelfPtr<DeclareType>(Def$$<TGabobReplayFrame>::GetRTTI())
          }
          Name = string("TGabobReplayFrame")
          SubType = TWeakPtr<DeclareType>(nullptr)
          OwnType = TWeakPtr<DeclareType>(nullptr)
          Members = vector<DeclareMember>
          {
            //0
            DeclareMember
            {
              Name = string("teams")
              Type = TWeakPtr<DeclareType>(Def$$<vector<TGabobTeam>>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
            ,
            //1
            DeclareMember
            {
              Name = string("explosions")
              Type = TWeakPtr<DeclareType>(Def$$<vector<TGabobExplosion>>::GetRTTI())
              Mode = string("DEF")
              Value = string("$")
            }
          }
        }
      }
    }
  }
  ImplPtrs = vector<EnvDefTypePtr>
  {
    //0
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<string>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<string>::GetRTTI())
      }
    }
    ,
    //1
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<int>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<int>::GetRTTI())
      }
    }
    ,
    //2
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<bool>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<bool>::GetRTTI())
      }
    }
    ,
    //3
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<real>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<real>::GetRTTI())
      }
    }
    ,
    //4
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobClock>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobClock>::GetRTTI())
      }
    }
    ,
    //5
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<vector<TGabobTeam>>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<vector<TGabobTeam>>::GetRTTI())
      }
    }
    ,
    //6
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobTeam>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobTeam>::GetRTTI())
      }
    }
    ,
    //7
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<QapColor>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<QapColor>::GetRTTI())
      }
    }
    ,
    //8
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<uchar>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<uchar>::GetRTTI())
      }
    }
    ,
    //9
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<vector<TGabobUnit>>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<vector<TGabobUnit>>::GetRTTI())
      }
    }
    ,
    //10
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobUnit>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobUnit>::GetRTTI())
      }
    }
    ,
    //11
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobPhys>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobPhys>::GetRTTI())
      }
    }
    ,
    //12
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<vec2d>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<vec2d>::GetRTTI())
      }
    }
    ,
    //13
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobBullets>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobBullets>::GetRTTI())
      }
    }
    ,
    //14
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<vector<TGabobBulletRaw>>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<vector<TGabobBulletRaw>>::GetRTTI())
      }
    }
    ,
    //15
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobBulletRaw>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobBulletRaw>::GetRTTI())
      }
    }
    ,
    //16
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<vector<TGabobExplosion>>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<vector<TGabobExplosion>>::GetRTTI())
      }
    }
    ,
    //17
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobExplosion>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobExplosion>::GetRTTI())
      }
    }
    ,
    //18
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<vector<TGabobParticle>>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<vector<TGabobParticle>>::GetRTTI())
      }
    }
    ,
    //19
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobParticle>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobParticle>::GetRTTI())
      }
    }
    ,
    //20
    EnvDefTypePtr
    {
      Decl = TWeakPtr<DeclareType>(Def$$<TGabobReplayFrame>::GetRTTI())
      Impl = EnvDefEntryPoint
      {
        Self = TSelfPtr<EnvDefEntryPoint>(Sys$$<TGabobReplayFrame>::GetRTTI())
      }
    }
  }
}
int(49)
THardPtr<TType>(Sys$$<TGabobReplayFrame>::GetRTTI())
int(49)
TGabobReplayFrame
{
  teams = vector<TGabobTeam>
  {
    //0
    TGabobTeam
    {
      name = string("orange")
      spamteam = bool(false)
      always_spam = bool(false)
      dummy = bool(false)
      smart = bool(true)
      workinteam = bool(true)
      select_best_teammate = bool(false)
      select_near_target = bool(true)
      bullet_time_control = bool(false)
      withoutrules = bool(false)
      fire_when_target_is_empty = bool(false)
      ai_withoutrules_use_trace_depth = bool(true)
      ai_withoutrules_trace_depth = int(200)
      number_of_dirs_for_trace = int(720)
      max_help_tick = int(8)
      help_dist = int(150)
      frags_eat = int(0)
      unfrags = int(0)
      frags = int(1)
      shots = int(64)
      hits = int(44)
      unhits = int(6)
      last_unit_id = int(19)
      last_bullet_id = int(64)
      color = QapColor
      {
        b = uchar(64)
        g = uchar(192)
        r = uchar(255)
        a = uchar(255)
      }
      units = vector<TGabobUnit>
      {
        //0
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("0")
          target = string("green.10")
          clock = TGabobClock
          {
            tick = int(11)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-166.31)
              y = real(345.53)
            }
            v = vec2d
            {
              x = real(0.03)
              y = real(0.08)
            }
          }
          need_help_tick = int(0)
          life = int(9)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(6)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //1
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("2")
          target = string("")
          clock = TGabobClock
          {
            tick = int(5)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-109.98)
              y = real(-264.71)
            }
            v = vec2d
            {
              x = real(-0.15)
              y = real(-0.60)
            }
          }
          need_help_tick = int(0)
          life = int(8)
          frags = int(0)
          total_hits = int(1)
          total_shots = int(4)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //2
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("4")
          target = string("")
          clock = TGabobClock
          {
            tick = int(8)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-36.83)
              y = real(-19.19)
            }
            v = vec2d
            {
              x = real(0.04)
              y = real(0.22)
            }
          }
          need_help_tick = int(0)
          life = int(9)
          frags = int(0)
          total_hits = int(1)
          total_shots = int(1)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //3
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("5")
          target = string("")
          clock = TGabobClock
          {
            tick = int(1)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(182.53)
              y = real(-59.96)
            }
            v = vec2d
            {
              x = real(0.60)
              y = real(0.31)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //4
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("6")
          target = string("")
          clock = TGabobClock
          {
            tick = int(2)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-458.23)
              y = real(-53.50)
            }
            v = vec2d
            {
              x = real(-0.39)
              y = real(0.21)
            }
          }
          need_help_tick = int(0)
          life = int(9)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //5
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("7")
          target = string("")
          clock = TGabobClock
          {
            tick = int(16)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(585.96)
              y = real(16.70)
            }
            v = vec2d
            {
              x = real(0.79)
              y = real(0.37)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //6
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("8")
          target = string("")
          clock = TGabobClock
          {
            tick = int(11)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(466.90)
              y = real(344.55)
            }
            v = vec2d
            {
              x = real(-0.17)
              y = real(0.11)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //7
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("9")
          target = string("")
          clock = TGabobClock
          {
            tick = int(3)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-498.22)
              y = real(204.73)
            }
            v = vec2d
            {
              x = real(0.25)
              y = real(-0.30)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //8
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("10")
          target = string("green.10")
          clock = TGabobClock
          {
            tick = int(15)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-305.97)
              y = real(343.62)
            }
            v = vec2d
            {
              x = real(-0.51)
              y = real(0.34)
            }
          }
          need_help_tick = int(1)
          life = int(6)
          frags = int(0)
          total_hits = int(6)
          total_shots = int(15)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //9
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("11")
          target = string("")
          clock = TGabobClock
          {
            tick = int(13)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(124.79)
              y = real(-143.48)
            }
            v = vec2d
            {
              x = real(0.14)
              y = real(-0.65)
            }
          }
          need_help_tick = int(0)
          life = int(4)
          frags = int(1)
          total_hits = int(7)
          total_shots = int(9)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //10
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("12")
          target = string("")
          clock = TGabobClock
          {
            tick = int(11)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(80.78)
              y = real(-136.44)
            }
            v = vec2d
            {
              x = real(0.19)
              y = real(0.23)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //11
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("13")
          target = string("")
          clock = TGabobClock
          {
            tick = int(14)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-70.68)
              y = real(122.99)
            }
            v = vec2d
            {
              x = real(0.15)
              y = real(-0.18)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //12
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("15")
          target = string("")
          clock = TGabobClock
          {
            tick = int(4)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(628.38)
              y = real(-126.21)
            }
            v = vec2d
            {
              x = real(-0.53)
              y = real(-0.64)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //13
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("16")
          target = string("")
          clock = TGabobClock
          {
            tick = int(4)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-424.91)
              y = real(48.34)
            }
            v = vec2d
            {
              x = real(-0.25)
              y = real(0.47)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //14
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("17")
          target = string("")
          clock = TGabobClock
          {
            tick = int(7)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(615.59)
              y = real(164.24)
            }
            v = vec2d
            {
              x = real(0.16)
              y = real(0.37)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //15
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("18")
          target = string("")
          clock = TGabobClock
          {
            tick = int(13)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(439.68)
              y = real(-372.01)
            }
            v = vec2d
            {
              x = real(0.93)
              y = real(-0.00)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
      }
      bullets = TGabobBullets
      {
        raws = vector<TGabobBulletRaw>
        {
          //0
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("51")
            owner = string("10")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(38.61)
                y = real(138.84)
              }
              v = vec2d
              {
                x = real(2.60)
                y = real(-1.50)
              }
            }
          }
          ,
          //1
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("52")
            owner = string("10")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-10.69)
                y = real(168.99)
              }
              v = vec2d
              {
                x = real(2.60)
                y = real(-1.50)
              }
            }
          }
          ,
          //2
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("53")
            owner = string("0")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(49.30)
                y = real(174.34)
              }
              v = vec2d
              {
                x = real(2.40)
                y = real(-1.80)
              }
            }
          }
          ,
          //3
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("54")
            owner = string("10")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-60.15)
                y = real(198.88)
              }
              v = vec2d
              {
                x = real(2.60)
                y = real(-1.49)
              }
            }
          }
          ,
          //4
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("55")
            owner = string("0")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(11.22)
                y = real(204.21)
              }
              v = vec2d
              {
                x = real(2.40)
                y = real(-1.80)
              }
            }
          }
          ,
          //5
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("56")
            owner = string("10")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-109.71)
                y = real(228.58)
              }
              v = vec2d
              {
                x = real(2.61)
                y = real(-1.48)
              }
            }
          }
          ,
          //6
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("57")
            owner = string("0")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-26.79)
                y = real(234.17)
              }
              v = vec2d
              {
                x = real(2.40)
                y = real(-1.81)
              }
            }
          }
          ,
          //7
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("58")
            owner = string("10")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-159.37)
                y = real(258.12)
              }
              v = vec2d
              {
                x = real(2.61)
                y = real(-1.48)
              }
            }
          }
          ,
          //8
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("59")
            owner = string("0")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-64.74)
                y = real(264.23)
              }
              v = vec2d
              {
                x = real(2.39)
                y = real(-1.81)
              }
            }
          }
          ,
          //9
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("60")
            owner = string("10")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-209.17)
                y = real(287.42)
              }
              v = vec2d
              {
                x = real(2.61)
                y = real(-1.47)
              }
            }
          }
          ,
          //10
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("61")
            owner = string("0")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-102.61)
                y = real(294.39)
              }
              v = vec2d
              {
                x = real(2.39)
                y = real(-1.81)
              }
            }
          }
          ,
          //11
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("62")
            owner = string("10")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-259.08)
                y = real(316.52)
              }
              v = vec2d
              {
                x = real(2.62)
                y = real(-1.47)
              }
            }
          }
          ,
          //12
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("63")
            owner = string("0")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-140.39)
                y = real(324.66)
              }
              v = vec2d
              {
                x = real(2.39)
                y = real(-1.82)
              }
            }
          }
        }
      }
    }
    ,
    //1
    TGabobTeam
    {
      name = string("green")
      spamteam = bool(false)
      always_spam = bool(false)
      dummy = bool(false)
      smart = bool(true)
      workinteam = bool(true)
      select_best_teammate = bool(false)
      select_near_target = bool(true)
      bullet_time_control = bool(false)
      withoutrules = bool(false)
      fire_when_target_is_empty = bool(false)
      ai_withoutrules_use_trace_depth = bool(true)
      ai_withoutrules_trace_depth = int(200)
      number_of_dirs_for_trace = int(450)
      max_help_tick = int(8)
      help_dist = int(150)
      frags_eat = int(0)
      unfrags = int(0)
      frags = int(3)
      shots = int(62)
      hits = int(44)
      unhits = int(5)
      last_unit_id = int(19)
      last_bullet_id = int(62)
      color = QapColor
      {
        b = uchar(64)
        g = uchar(255)
        r = uchar(64)
        a = uchar(255)
      }
      units = vector<TGabobUnit>
      {
        //0
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("0")
          target = string("")
          clock = TGabobClock
          {
            tick = int(10)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-269.56)
              y = real(11.35)
            }
            v = vec2d
            {
              x = real(-0.08)
              y = real(-0.02)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //1
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("1")
          target = string("")
          clock = TGabobClock
          {
            tick = int(15)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(670.31)
              y = real(168.71)
            }
            v = vec2d
            {
              x = real(-0.08)
              y = real(-0.31)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //2
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("2")
          target = string("")
          clock = TGabobClock
          {
            tick = int(11)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-342.80)
              y = real(-169.81)
            }
            v = vec2d
            {
              x = real(0.01)
              y = real(-0.09)
            }
          }
          need_help_tick = int(0)
          life = int(9)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(4)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //3
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("4")
          target = string("")
          clock = TGabobClock
          {
            tick = int(8)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-60.79)
              y = real(-334.19)
            }
            v = vec2d
            {
              x = real(0.57)
              y = real(-0.14)
            }
          }
          need_help_tick = int(0)
          life = int(3)
          frags = int(1)
          total_hits = int(7)
          total_shots = int(11)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //4
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("5")
          target = string("")
          clock = TGabobClock
          {
            tick = int(7)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-171.64)
              y = real(-331.08)
            }
            v = vec2d
            {
              x = real(-0.09)
              y = real(-0.24)
            }
          }
          need_help_tick = int(0)
          life = int(2)
          frags = int(1)
          total_hits = int(9)
          total_shots = int(11)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //5
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("6")
          target = string("")
          clock = TGabobClock
          {
            tick = int(13)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(556.55)
              y = real(-136.44)
            }
            v = vec2d
            {
              x = real(-0.22)
              y = real(0.10)
            }
          }
          need_help_tick = int(0)
          life = int(7)
          frags = int(0)
          total_hits = int(4)
          total_shots = int(6)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //6
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("7")
          target = string("")
          clock = TGabobClock
          {
            tick = int(3)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(651.69)
              y = real(162.64)
            }
            v = vec2d
            {
              x = real(-0.18)
              y = real(-0.34)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //7
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("8")
          target = string("")
          clock = TGabobClock
          {
            tick = int(10)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-317.28)
              y = real(261.21)
            }
            v = vec2d
            {
              x = real(0.13)
              y = real(0.07)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //8
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("9")
          target = string("")
          clock = TGabobClock
          {
            tick = int(14)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-374.97)
              y = real(301.85)
            }
            v = vec2d
            {
              x = real(0.09)
              y = real(1.13)
            }
          }
          need_help_tick = int(0)
          life = int(3)
          frags = int(0)
          total_hits = int(7)
          total_shots = int(9)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //9
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("10")
          target = string("")
          clock = TGabobClock
          {
            tick = int(5)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(349.11)
              y = real(-56.22)
            }
            v = vec2d
            {
              x = real(-0.60)
              y = real(0.51)
            }
          }
          need_help_tick = int(0)
          life = int(8)
          frags = int(0)
          total_hits = int(3)
          total_shots = int(4)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //10
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("11")
          target = string("")
          clock = TGabobClock
          {
            tick = int(7)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(433.79)
              y = real(91.55)
            }
            v = vec2d
            {
              x = real(0.02)
              y = real(-0.04)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //11
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("12")
          target = string("")
          clock = TGabobClock
          {
            tick = int(4)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(553.45)
              y = real(-13.59)
            }
            v = vec2d
            {
              x = real(-0.36)
              y = real(0.16)
            }
          }
          need_help_tick = int(0)
          life = int(5)
          frags = int(1)
          total_hits = int(6)
          total_shots = int(9)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //12
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("13")
          target = string("")
          clock = TGabobClock
          {
            tick = int(16)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(644.55)
              y = real(96.65)
            }
            v = vec2d
            {
              x = real(0.14)
              y = real(0.04)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //13
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("14")
          target = string("")
          clock = TGabobClock
          {
            tick = int(11)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-414.73)
              y = real(155.22)
            }
            v = vec2d
            {
              x = real(-0.06)
              y = real(-0.00)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //14
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("15")
          target = string("")
          clock = TGabobClock
          {
            tick = int(6)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(632.60)
              y = real(215.54)
            }
            v = vec2d
            {
              x = real(0.61)
              y = real(0.45)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //15
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("16")
          target = string("")
          clock = TGabobClock
          {
            tick = int(4)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-86.34)
              y = real(-71.95)
            }
            v = vec2d
            {
              x = real(-0.67)
              y = real(-0.01)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //16
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("17")
          target = string("")
          clock = TGabobClock
          {
            tick = int(16)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(193.10)
              y = real(3.57)
            }
            v = vec2d
            {
              x = real(0.01)
              y = real(-0.01)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
        ,
        //17
        TGabobUnit
        {
          need_remove = bool(false)
          name = string("18")
          target = string("")
          clock = TGabobClock
          {
            tick = int(8)
            interval = int(16)
          }
          phys = TGabobPhys
          {
            pos = vec2d
            {
              x = real(-72.94)
              y = real(293.94)
            }
            v = vec2d
            {
              x = real(-0.25)
              y = real(0.37)
            }
          }
          need_help_tick = int(0)
          life = int(10)
          frags = int(0)
          total_hits = int(0)
          total_shots = int(0)
          frags_eat = int(0)
          wait_new_target = bool(false)
        }
      }
      bullets = TGabobBullets
      {
        raws = vector<TGabobBulletRaw>
        {
          //0
          TGabobBulletRaw
          {
            need_remove = bool(false)
            name = string("30")
            owner = string("10")
            phys = TGabobPhys
            {
              pos = vec2d
              {
                x = real(-620.64)
                y = real(347.42)
              }
              v = vec2d
              {
                x = real(-2.67)
                y = real(1.37)
              }
            }
          }
        }
      }
    }
  }
  explosions = vector<TGabobExplosion>
  {
    //0
    TGabobExplosion
    {
      name = string("bullet_die")
      auto_move = bool(true)
      auto_draw = bool(true)
      blend_add = bool(true)
      pos = vec2d
      {
        x = real(-540.42)
        y = real(383.69)
      }
      tick = int(49)
      max_tick = int(2)
      particle_beg_size = real(6.00)
      particle_end_size = real(4.00)
      particle_beg_color = QapColor
      {
        b = uchar(64)
        g = uchar(255)
        r = uchar(64)
        a = uchar(255)
      }
      particle_end_color = QapColor
      {
        b = uchar(128)
        g = uchar(128)
        r = uchar(128)
        a = uchar(0)
      }
      particle_life_time = int(64)
      particle_per_tick = int(2)
      particle_min_speed = real(1.00)
      particle_max_speed = real(1.00)
      particle_pos_dist = real(0.00)
      particle_pos_dist_var = real(0.00)
      particle_grav = vec2d
      {
        x = real(0.00)
        y = real(0.00)
      }
      undeadable = bool(false)
      arr = vector<TGabobParticle>
      {
        //0
        TGabobParticle
        {
          pos = vec2d
          {
            x = real(-496.20)
            y = real(402.35)
          }
          v = vec2d
          {
            x = real(0.92)
            y = real(0.39)
          }
          t = real(16.00)
        }
        ,
        //1
        TGabobParticle
        {
          pos = vec2d
          {
            x = real(-563.68)
            y = real(425.68)
          }
          v = vec2d
          {
            x = real(-0.48)
            y = real(0.87)
          }
          t = real(16.00)
        }
      }
    }
    ,
    //1
    TGabobExplosion
    {
      name = string("bullet_die")
      auto_move = bool(true)
      auto_draw = bool(true)
      blend_add = bool(true)
      pos = vec2d
      {
        x = real(-680.44)
        y = real(382.90)
      }
      tick = int(8)
      max_tick = int(2)
      particle_beg_size = real(6.00)
      particle_end_size = real(4.00)
      particle_beg_color = QapColor
      {
        b = uchar(64)
        g = uchar(255)
        r = uchar(64)
        a = uchar(255)
      }
      particle_end_color = QapColor
      {
        b = uchar(128)
        g = uchar(128)
        r = uchar(128)
        a = uchar(0)
      }
      particle_life_time = int(64)
      particle_per_tick = int(2)
      particle_min_speed = real(1.00)
      particle_max_speed = real(1.00)
      particle_pos_dist = real(0.00)
      particle_pos_dist_var = real(0.00)
      particle_grav = vec2d
      {
        x = real(0.00)
        y = real(0.00)
      }
      undeadable = bool(false)
      arr = vector<TGabobParticle>
      {
        //0
        TGabobParticle
        {
          pos = vec2d
          {
            x = real(-678.53)
            y = real(376.16)
          }
          v = vec2d
          {
            x = real(0.27)
            y = real(-0.96)
          }
          t = real(57.00)
        }
        ,
        //1
        TGabobParticle
        {
          pos = vec2d
          {
            x = real(-683.03)
            y = real(376.40)
          }
          v = vec2d
          {
            x = real(-0.37)
            y = real(-0.93)
          }
          t = real(57.00)
        }
      }
    }
  }
}
