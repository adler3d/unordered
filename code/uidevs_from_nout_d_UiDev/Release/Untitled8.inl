окно дл€ входа в игру{
  string login;
  string password;
  button ok;
  button exit;
}

login,[select_unit],realm.

login,select_unit,game.

login,game.

invite_board,enter your login and remember your password,login


t_server{
  ingame_logics;//realms
  outgame_logics;//login,logout,register
}
vector<t_realm> realms;


t_realm{
  vector<t_actor> actors;...
}


2014.11.12
struct foo{
  int a;
  int b;
  сгенерировать инфу дл€ всех полей. но использовать из соседени еденицы компил€ци. вот так.
}