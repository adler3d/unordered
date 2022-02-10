t_fv_stat{
  t_func_fv_part=>i_fv_part{
    TAutoPtr<t_func_params> params;
    TAutoPtr<t_const_with_sep> cv1;
    t_sep sep1;
    TAutoPtr<i_fv_body> body;
    {
      M+=go_auto(params);
      O+=go_auto(cv1);
      O+=go_auto(sep1);
      M+=go_auto(body);
    }
  }
  t_var_fv_part=>i_fv_part{
    t_body{
      string body;
      t_sep sep;
      {
        M+=go_const("[");
        M+=go_any(body,gen_dips("09"));
        M+=go_const("]");
        O+=go_auto(sep);
      }
    }
    t_sep sep0;
    TAutoPtr<t_body> body;
    TAutoPtr<t_func_param_value> value;
    t_sep sep1;
    {
      O+=go_auto(sep0);
      O+=go_auto(body);
      O+=go_auto(value);
    }
  }
  t_var_part{
    TAutoPtr<i_fv_part> part;
    t_sep sep1;
    {
      M+=go_auto(part);
      O+=go_auto(sep1);
    }
  }
  vector<t_keyword> keywords;
  TAutoPtr<t_type_expr> type;
  TAutoPtr<t_const_with_sep> cv0;
  t_sep sep;
  string name;
  vector<t_var_part> arr;
  {
    O+=go_auto(keywords);
    M+=go_auto(type);
    O+=go_auto(cv0);
    
    O+=go_auto(sep);
    M+=go_str<t_name>(name);
    

    
    M+=go_auto(arr);
    M+=go_const(";");
  }
}
---

вначале провер€ем что дальше. если просто переменна€, то ищем ещЄ переменные.
если фунци€ без тела и 

int z,foo2(),bar2(),x,u();

t_fv_stat{
  t_var_ext=>i_ext{
    t_arr_num{
      string num;
      t_sep sep;
      {
        M+=go_const("[");
        M+=go_any(body,gen_dips("09"));
        M+=go_const("]");
        O+=go_auto(sep);
      }
    }
    TAutoPtr<t_arr_num> num;
    {
      O+=go_diff<t_func_ext_impl>(num);
    }
  }
  t_func_ext_impl{
    {
      O+=sep;
      M+=go_auto(params);
    }
  }
  t_func_ext=>i_ext{t_func_ext_impl impl;{go_auto(impl);}}
  
              ,asd=1000;
              ,asd[1000];
              ,asd[1000]={0};
              ,asd;
              ,asd();
              ,asd(),u
              ,asd,cde
  
  t_item{
    t_sep sep0;
    string name;
    t_sep sep1;
    TAutoPtr<i_ext> ext;
    t_sep sep2;
    {
      O+=go_auto(sep0);
      M+=go_str<t_name>(name);
      O+=go_auto(sep1);
      M+=go_auto(ext);
      O+=go_auto(sep2);
    }
  }
  
    int gg
          =10;
          [10];
          [1]={0};
          ;
          (),
          ();
          ;
          ,x
          (){}
          ()=0;
          ()=delete;
  
  t_vars_stat=>i_stat{
    t_type type;
    t_name sep0;
    vector<t_item> arr;
    {
      M+=go_auto(type);
      O+=go_auto(sep);
      O+=go_auto(arr);
      sep;
      M+=go_const(";");
    }
  }
  t_func_with_impl_stat=>i_stat{
    t_type type;
    t_name sep0;
    string name;
    t_name sep1;
    TAutoPtr<t_func_params> params;
    TAutoPtr<t_const_with_sep> cv;
    t_sep sep1;
    vector<t_item> arr;
    {
      M+=go_auto(type);
      O+=go_auto(sep);
      M+=go_str<t_name>(name);
      O+=go_auto(sep);
      M+=go_auto(params);
      O+=go_auto(cv);
      O+=go_auto(sep1);
      M+=go_auto(body);
    }
  }
  t_type type;
  t_name sep0;
  string name;
  t_name sep1;
  TAutoPtr<i_impl> body;
  {
    M+=go_auto(type);
    O+=go_auto(sep0);
    M+=go_str<t_name>(name);
    O+=go_auto(sep1);
    M+=go_auto(end);
  }
}

int gg
      =10;
      [10];
      [1]={0};
      ;
      (),
      ();
      ;
      ,x
        =10;
        [10];
        [1]={0};
        ;
        ()
          ,abc
              =1000;
              [1000];
              [1000]={0};
              ;
              ();
              (),u
              ,cde
                  [10];
                  [1]={0};
                  ;
                  ()
                  ,end;
          ;
      (){}
      ()=0;
      ()=delete;

    int var;
    int var=0;
    int foo();
    int bar()=0;
    int bar()const=0;
    int bar()const=0,abc;// fail!
    int bar()const=0;abc;// fail!
    int var,foo,bar;
    int var=0,foo,bar;
    int var=0,foo(),bar=1;





















t_type_expr * t_name * ;
t_type_expr * t_name * t_value{ * = * t_number } * ;
t_type_expr * t_name * t_func_params{ * ( * ) * } * ;
t_type_expr * t_name * t_func_params{null} ;


можно пр€м поле компил€ции показать какой процент компил€тора использован. надо только спецальную опцию указать.
ещЄ можно сгенерировать минимальный компил€тор который будет компилировать этот код и похожий на него.
тоесть использующий тот же самый набор возможностей компил€тора.
короче надо в компил€тор встроить такую вишку котора€ позволит ему создавать урезаную версию себ€.
тоесть такую версию котора€ забудет про те возможности которые твой код не использует.
компил€тор может показывать какими возможност€ми ты воспользовалс€ а какими ещЄ нет.
и например ты изменил код и заюзал ещЄ какую-то особенность. запускаешь компил€тор и он тебе показывает достижение, мол использована така€-то возможность.