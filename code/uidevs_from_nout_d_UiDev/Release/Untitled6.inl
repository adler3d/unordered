//check
struct t_check_request{
  string name;
  int key;
}
struct t_user_info{
  string nick;
  int key;
  string data;
}
vector{t_user_info} users=server.users;
t_check_request cr; cr.fromBlob(POST['data']);
for(int i=0;i<users.size();i++)
{
  auto ex=users[i];
  if(ex.name!=cr.name)continue;
  if(ex.key!=cr.key)return "wrong_key;";
  return "ok;"
}
return "not_found;";
