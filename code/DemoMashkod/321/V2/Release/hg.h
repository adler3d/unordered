t_opt_test_machine=>t_opt_test_lex_scope{
  t_version{
    string var;
    int id;
  }
  t_var{
    string name;
    string type;
    vector<vector<t_version>> arr;
  }
  t_program scope;
  vector<t_var> vars;
}