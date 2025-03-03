t_templ_sys_v03{
  t_head{
    string name;
    {
      go_const("----------------------------------------------------------------\n");
      go_const("#####-");
      go_any(name,gen_dips("azAZ09")+"_$@");
      go_const("-#####\n");
      go_const("----------------------------------------------------------------\n");
    }
  }
  t_scope{
    t_head head;
    string body;
    {
      M+=go_auto(head);
      O+=go_str_without<t_head>(body);
    }
  }
  vector<t_scope> arr;
  {
    go_auto(arr);
  }
}

t_scope{
  t_raw=>i_seq{string body;{go_any(body,dip_inv("-"));}}
  t_step=>i_seq{t_impl{{go_const("-");}}t_impl body;{go_minor<t_head>(body);}}
  t_impl{vector<TAutoPtr<i_seq>> arr;{go_auto(arr);}}
  t_head head;
  string body;
  {
    go_auto(head);
    go_str<t_impl>(body);
  }
}



t_templ_sys_v02{
  t_data=>i_item{
    t_impl{vector<TAutoPtr<i_seq>> arr;{go_auto(arr);}}
    string body;
    {
      go_str<t_impl>(body);
    }
  }
  t_var=>i_item{
    string name;
    {
      go_const("^^^");
      go_any(name,gen_dips("azAZ09")+"_$@");
      go_const("^^^");
    }
  }
  t_raw=>i_seq{string body;{go_any(body,dip_inv("^"));}}
  t_caret=>i_seq{
    t_impl{{go_const("^");}}
    t_impl body;
    {
      go_minor<t_var>(body);
    }
  }
  vector<TAutoPtr<i_item>> arr;
  {
    go_auto(arr);
  }
}