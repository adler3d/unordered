t_file_with_lex{
  t_sep{string body;{go_any(body," \n");}}
  t_class=>i_elem{
    t_with_parent=>i_def{
      string name;
      string parent;
      {
        go_str<t_name>(name);
        go_const(":public ");
        go_str<t_name>(parent);
        go_const("{\n");
      }
    }
    t_without_parent=>i_def{
      string name;
      {
        go_str<t_name>(name);
        go_const("{\n");
      }
    }
    t_head{
      t_impl{
        t_noway=>i_way{TAutoPtr<i_def> body;{go_auto(body);}}
        t_okway=>i_way{{go_const("#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\\\n");}}
        string body;
        t_okway okway;
        {
          go_str_without<TAutoPtr<i_way>>(body);
          go_auto(okway);
        }
      }
      string body;
      {
        go_str<t_impl>(body);
      }
    }
    t_vars{
      t_item{
        string sep;
        string num;
        string type;
        string name;
        string mode;
        string value;
        {
          O+=go_str<t_sep>(sep);
          M+=go_const("ADDVAR(");
          M+=go_end(num,",");
          M+=go_end(type,",");
          M+=go_end(name,",");
          M+=go_end(mode,",");
          M+=go_end(value,",");
          M+=go_const("$)\\\n");
        }
      }
      string sep0;
      vector<t_item> arr;
      string sep1;
      {
        O+=go_str<t_sep>(sep0);
        M+=go_const("ADDBEG()\\\n");
        O+=go_auto(arr);
        O+=go_str<t_sep>(sep1);
        M+=go_const("ADDEND()\n");
      }
    }
    t_include{
      string sep0;
      string name_bef;
      string sep1;
      string sep2;
      string name_aft;
      string sep3;
      {
        O+=go_str<t_sep>(sep0);
        M+=go_const("//=====+>>>>>");
        M+=go_str<t_name>(name_bef);
        O+=go_str<t_sep>(sep1);
        M+=go_const("#include \"QapGenStruct.inl\"");
        O+=go_str<t_sep>(sep2);
        M+=go_const("//<<<<<+=====");
        M+=go_str<t_name>(name_aft);
        O+=go_str<t_sep>(sep3);
      }
    }
    t_lex_base=>i_lex{
      t_okway=>i_way{{go_const("virtual bool go(i_dev&dev)");}}
      t_noway=>i_way{{go_const("bool go(i_dev&dev){\n");}}
      string body;
      t_okway okway;
      {
        M+=go_str_without<TAutoPtr<i_way>>(body);
        M+=go_auto(okway);
      }
    }
    t_lex_impl=>i_lex{
      t_line{
        string sep0;
        char mode;
        string line;
        string sep1;
        {
          O+=go_str<t_sep>(sep0);
          M+=go_any_char(mode,"DOM");
          M+=go_const("+=dev.");
          M+=go_end(line,"\n");
          O+=go_str<t_sep>(sep1);
          M+=go_const("if(!ok)return ok;\n");
        }
      }
      t_unused{
        t_noway=>i_way{{go_const("virtual bool go(i_dev&dev)");}}
        t_okway=>i_way{{go_const("bool go(i_dev&dev){\n");}}
        string body;
        t_okway okway;
        string sep0;
        string sep1;
        string sep2;
        string sep3;
        string sep4;
        {
          M+=go_str_without<TAutoPtr<i_way>>(body);
          M+=go_auto(okway);
          O+=go_str<t_sep>(sep0);
          M+=go_const("t_fallback scope(dev,__FUNCTION__);");
          O+=go_str<t_sep>(sep1);
          M+=go_const("auto&ok=scope.ok;");
          O+=go_str<t_sep>(sep2);
          M+=go_const("auto&D=scope.mandatory;");
          O+=go_str<t_sep>(sep3);
          M+=go_const("auto&M=scope.mandatory;");
          O+=go_str<t_sep>(sep4);
          M+=go_const("auto&O=scope.optional;");
        }
      }
      string unused;
      vector<t_line> arr;
      string sep0;
      string sep1;
      {
        M+=go_str<t_unused>(unused);
        M+=go_auto(arr);
        O+=go_str<t_sep>(sep0);
        M+=go_const("return ok;\n");
        O+=go_str<t_sep>(sep1);
        M+=go_const("}\n");
      }
    }
    t_body{TAutoPtr<i_lex> body;{go_auto(body);}}
    t_end{
      t_code=>i_code{string body;{go_any(body,dip_inv("{}"));}}
      t_scope=>i_code{
        vector<t_end> arr;
        {
          M+=go_const("{");
          O+=go_auto(arr);
          M+=go_const("}");
        }
      }
      vector<TAutoPtr<i_code>> body;
      {
        go_auto(body);
      }
    }
    t_sep_stat=>i_stat{string sep;{go_any(sep," \n");}}
    t_public_stat=>i_stat{{go_const("public:");}}
    t_class_stat=>i_stat{TAutoPtr<t_class> body;{go_auto(body);}}
    t_forward_decl_stat=>i_stat{string name;{go_const("class ");go_str<t_name>(name);go_const(";");}}
    string sep;
    TAutoPtr<i_def> def;
    vector<TAutoPtr<i_stat>> stats;
    t_head head;
    t_vars vars;
    t_include incl;
    t_body body;
    string end;
    {
      O+=go_str<t_sep>(sep);
      M+=go_const("class ");
      M+=go_auto(def);
      O+=go_auto(stats);
      M+=go_auto(head);
      O+=go_auto(vars);
      M+=go_auto(incl);
      M+=go_auto(body);
      O+=go_str<t_end>(end);
      M+=go_const("};\n");
    }
  }
  t_other=>i_elem{
    string body;
    {
      go_str_without<t_class>(body);
    }
  }
  vector<TAutoPtr<i_elem>> arr;
  {
    go_auto(arr);
  }
}