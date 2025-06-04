      #define QapKbOnDownDoInvFlag(FLAG,KEY,VALUE)(add_kb_flag(FLAG)->update(KEY,VALUE))
      struct t_kb_flag{
        #define DEF_PRO_CLASSNAME()t_kb_flag
        #define DEF_PRO_VARIABLE(ADD)\
        ADD(string,name,"")\
        ADD(int,key,0)\
        ADD(bool,flag,false)\
        ADD(bool,need_init,true)\
        //===
        //#include "defprovar.inl"
        #define ADD(TYPE,NAME,VALUE)TYPE NAME=VALUE;
        DEF_PRO_VARIABLE(ADD)
        #undef ADD
        #undef DEF_PRO_VARIABLE    
        #undef DEF_PRO_CLASSNAME
        //===
        bool update(int key,bool def_value){this->key=key;if(need_init){flag=def_value;need_init=false;}return flag;}
      };
      vector<t_kb_flag> kb_flags;
      PRO_FUNCGEN_ADD_UNIQUE_OBJ_BY_FIELD_V2(t_kb_flag,add_kb_flag,kb_flags,string,name);