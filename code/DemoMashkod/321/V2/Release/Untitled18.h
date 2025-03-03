    struct t_caller_scope{
      typedef t_mash_code_provider t_prov;
      int&pos_var;
      t_prov*prov;
      int old_pos;
      t_caller_scope(t_prov*prov,int&pos_var):prov(prov),pos_var(pos_var){start();}
      ~t_caller_scope(){finish();}
      void start(){
        old_pos=pos_var;
        esp_info.caller_scope_bef();
      }
      static bool mode(){return file_get_content("caller_scope_mode.txt");}
      void finish(){
        #include "asm_header.inl"
        esp_info.caller_scope_aft();
        prov->sub(esp,pos_var-old_pos+esp_info.offset);
      }
    };
    #define CALLER_SCOPE(NAME)t_caller_scope caller_scope(this,pos_var);
struct t_result_scope_shit{
  auto unused_var;
  void init(){
    VAR(int,unused_var);
  }
  void free(){
    lea(esp,unused_var);
  }

                                                            VAR("t_abc",var_abc);
                                                            {
                                                              VAR("vec2i",tmp104);
                                                              VAR("vec2i",tmp105);
                                                              VAR("vec2i",tmp108);
                                                              {
                                                                CALLER_SCOPE();
                                                                pushlea(tmp104);
                                                                push(10);
                                                                push(10);
                                                                call("func_vec2i(int,int)");
                                                              }
                                                                
                                                              push(0);
                                                              push(tmp104);
                                                              call("func_f(int,vec2i)");
                                                              lea(esp,tmp105);
                                                              
                                                              push(0);
                                                              push(1);
                                                              call("func_vec2i(int,int)");
                                                              lea(esp,tmp108);
                                                              
                                                              VAR("t_abc",tmp109);
                                                              push(var_q);
                                                              push(tmp105);
                                                              push(tmp108);
                                                              call("func_foo(t_quad,vec2i,vec2i)");
                                                              lea(esp,tmp109);
                                                              
                                                              copy(var_abc,tmp109);
                                                            }