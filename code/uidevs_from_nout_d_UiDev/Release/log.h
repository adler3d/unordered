
THardPtr<TType>(Sys$$<t_diff_result>::GetRTTI())
int(21)
t_diff_result
{
  arr = vector<t_diff_fields_info>
  {
    //0
    t_diff_fields_info
    {
      type = string("TGabobClock")
      fields = string("+d")
    }
    ,
    //1
    t_diff_fields_info
    {
      type = string("TGabobUnit")
      fields = string("dddx+ddddddd")
    }
    ,
    //2
    t_diff_fields_info
    {
      type = string("TGabobClock")
      fields = string("1d")
    }
    ,
    //3
    t_diff_fields_info
    {
      type = string("TGabobUnit")
      fields = string("dddx+0ddd+dd")
    }
    ,
    //4
    t_diff_fields_info
    {
      type = string("TGabobBulletRaw")
      fields = string("ddd+")
    }
    ,
    //5
    t_diff_fields_info
    {
      type = string("TGabobTeam")
      fields = string("ddddddddddddddddddd+ddd+dpp")
    }
    ,
    //6
    t_diff_fields_info
    {
      type = string("TGabobTeam")
      fields = string("dddddddddddddddddddddddddpp")
    }
    ,
    //7
    t_diff_fields_info
    {
      type = string("TGabobExplosion")
      fields = string("ddddd+dddddddddddddp")
    }
    ,
    //8
    t_diff_fields_info
    {
      type = string("TGabobReplayFrame")
      fields = string("pp")
    }
  }
  root = t_cmd
  {
    cmd = string("xpatch")
    name = string("root")
    type = string("TGabobReplayFrame")
    data = string("int(8) but saved as int(0) also: pp")
    arr = vector<t_cmd>
    {
      //0
      t_cmd
      {
        cmd = string("patch")
        name = string("teams")
        type = string("vector<TGabobTeam>")
        data = string("")
        arr = vector<t_cmd>
        {
          //0
          t_cmd
          {
            cmd = string("xpatch")
            name = string("0")
            type = string("TGabobTeam")
            data = string("int(5) but saved as int(0) also: ddddddddddddddddddd+ddd+dpp")
            arr = vector<t_cmd>
            {
              //0
              t_cmd
              {
                cmd = string("+1")
                name = string("shots")
                type = string("int")
                data = string("")
                arr = vector<t_cmd>()
              }
              ,
              //1
              t_cmd
              {
                cmd = string("+1")
                name = string("last_bullet_id")
                type = string("int")
                data = string("")
                arr = vector<t_cmd>()
              }
              ,
              //2
              t_cmd
              {
                cmd = string("patch")
                name = string("units")
                type = string("vector<TGabobUnit>")
                data = string("")
                arr = vector<t_cmd>
                {
                  //0
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("0")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //1
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("1")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //2
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("2")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //3
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("3")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //4
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("4")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //5
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("5")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(2) but saved as int(1) also: 1d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //6
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("6")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //7
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("7")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //8
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("8")
                    type = string("TGabobUnit")
                    data = string("int(3) but saved as int(1) also: dddx+0ddd+dd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                      ,
                      //2
                      t_cmd
                      {
                        cmd = string("0")
                        name = string("need_help_tick")
                        type = string("int")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                      ,
                      //3
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("total_shots")
                        type = string("int")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //9
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("9")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //10
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("10")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //11
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("11")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //12
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("12")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //13
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("13")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //14
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("14")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //15
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("15")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                }
              }
              ,
              //3
              t_cmd
              {
                cmd = string("patch")
                name = string("bullets")
                type = string("TGabobBullets")
                data = string("r")
                arr = vector<t_cmd>
                {
                  //0
                  t_cmd
                  {
                    cmd = string("resize")
                    name = string("raws")
                    type = string("vector<TGabobBulletRaw>")
                    data = string("int(14) also it is +1")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("0")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("1")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //2
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("2")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //3
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("3")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //4
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("4")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //5
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("5")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //6
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("6")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //7
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("7")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //8
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("8")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //9
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("9")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //10
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("10")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //11
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("11")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //12
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("12")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //13
                      t_cmd
                      {
                        cmd = string("new")
                        name = string("13")
                        type = string("TGabobBulletRaw")
                        data = string("\0\2\0\0\064\2\0\0\010\x9EíYK\xA1\'sÀ\nùÎ×R\x7Fu@ü~.)0ù\4@\x1BúX\xAFuU÷\xBF")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                }
              }
            }
          }
          ,
          //1
          t_cmd
          {
            cmd = string("xpatch")
            name = string("1")
            type = string("TGabobTeam")
            data = string("int(6) but saved as int(1) also: dddddddddddddddddddddddddpp")
            arr = vector<t_cmd>
            {
              //0
              t_cmd
              {
                cmd = string("patch")
                name = string("units")
                type = string("vector<TGabobUnit>")
                data = string("")
                arr = vector<t_cmd>
                {
                  //0
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("0")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //1
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("1")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //2
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("2")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //3
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("3")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //4
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("4")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //5
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("5")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //6
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("6")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //7
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("7")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //8
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("8")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //9
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("9")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //10
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("10")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //11
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("11")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //12
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("12")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(2) but saved as int(1) also: 1d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //13
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("13")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //14
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("14")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //15
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("15")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //16
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("16")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(2) but saved as int(1) also: 1d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                  ,
                  //17
                  t_cmd
                  {
                    cmd = string("xpatch")
                    name = string("17")
                    type = string("TGabobUnit")
                    data = string("int(1) but saved as int(0) also: dddx+ddddddd")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("clock")
                        type = string("TGabobClock")
                        data = string("int(0) but saved as int(0) also: +d")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("tick")
                            type = string("int")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                      ,
                      //1
                      t_cmd
                      {
                        cmd = string("+1")
                        name = string("phys")
                        type = string("TGabobPhys")
                        data = string("")
                        arr = vector<t_cmd>()
                      }
                    }
                  }
                }
              }
              ,
              //1
              t_cmd
              {
                cmd = string("patch")
                name = string("bullets")
                type = string("TGabobBullets")
                data = string("p")
                arr = vector<t_cmd>
                {
                  //0
                  t_cmd
                  {
                    cmd = string("patch")
                    name = string("raws")
                    type = string("vector<TGabobBulletRaw>")
                    data = string("")
                    arr = vector<t_cmd>
                    {
                      //0
                      t_cmd
                      {
                        cmd = string("xpatch")
                        name = string("0")
                        type = string("TGabobBulletRaw")
                        data = string("int(4) but saved as int(0) also: ddd+")
                        arr = vector<t_cmd>
                        {
                          //0
                          t_cmd
                          {
                            cmd = string("+1")
                            name = string("phys")
                            type = string("TGabobPhys")
                            data = string("")
                            arr = vector<t_cmd>()
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      ,
      //1
      t_cmd
      {
        cmd = string("patch")
        name = string("explosions")
        type = string("vector<TGabobExplosion>")
        data = string("")
        arr = vector<t_cmd>
        {
          //0
          t_cmd
          {
            cmd = string("xpatch")
            name = string("0")
            type = string("TGabobExplosion")
            data = string("int(7) but saved as int(0) also: ddddd+dddddddddddddp")
            arr = vector<t_cmd>
            {
              //0
              t_cmd
              {
                cmd = string("+1")
                name = string("tick")
                type = string("int")
                data = string("")
                arr = vector<t_cmd>()
              }
              ,
              //1
              t_cmd
              {
                cmd = string("patch")
                name = string("arr")
                type = string("vector<TGabobParticle>")
                data = string("")
                arr = vector<t_cmd>
                {
                  //0
                  t_cmd
                  {
                    cmd = string("+1")
                    name = string("0")
                    type = string("TGabobParticle")
                    data = string("")
                    arr = vector<t_cmd>()
                  }
                  ,
                  //1
                  t_cmd
                  {
                    cmd = string("+1")
                    name = string("1")
                    type = string("TGabobParticle")
                    data = string("")
                    arr = vector<t_cmd>()
                  }
                }
              }
            }
          }
          ,
          //1
          t_cmd
          {
            cmd = string("xpatch")
            name = string("1")
            type = string("TGabobExplosion")
            data = string("int(7) but saved as int(0) also: ddddd+dddddddddddddp")
            arr = vector<t_cmd>
            {
              //0
              t_cmd
              {
                cmd = string("+1")
                name = string("tick")
                type = string("int")
                data = string("")
                arr = vector<t_cmd>()
              }
              ,
              //1
              t_cmd
              {
                cmd = string("patch")
                name = string("arr")
                type = string("vector<TGabobParticle>")
                data = string("")
                arr = vector<t_cmd>
                {
                  //0
                  t_cmd
                  {
                    cmd = string("+1")
                    name = string("0")
                    type = string("TGabobParticle")
                    data = string("")
                    arr = vector<t_cmd>()
                  }
                  ,
                  //1
                  t_cmd
                  {
                    cmd = string("+1")
                    name = string("1")
                    type = string("TGabobParticle")
                    data = string("")
                    arr = vector<t_cmd>()
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
