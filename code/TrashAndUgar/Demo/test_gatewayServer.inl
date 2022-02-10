void test_gatewayServer()
{
  class TServerCallback:public ServerCallback{
    vector<int> a;
    vector<int> d;
    vector<int> r;
  public:
    void OnRecvPack(Socket&client,std::string&data){
      qap_add_back(r)=client.sock;
      int gg=1;
    }
    void OnAddClient(Socket&client){
      qap_add_back(a)=client.sock;
      int gg=1;
    }
    void OnDeleteClient(Socket&client){
      qap_add_back(d)=client.sock;
      int gg=1;
    }
  };
  GatewayServer gs;
  gs.port=7030;
  gs.start_tcp();
  TServerCallback cb;
  vector<DownLoader> dls;
  //dls.resize(70);
  //for(int i=0;i<dls.size();i++){dls[i].start_ex("localhost/"+IToS(i));}
  vector<string> t;
  bool add_dls=false;
  for(int iter=0;;iter++)
  {
    if(add_dls)for(int i=0;i<16;i++){
      if(dls.size()<2048)qap_add_back(dls).start_ex("localhost/"+IToS(dls.size()));
    }
    QapClock c;c.Start();
    gs.update_tcp(cb);
    auto a0=c.MS();
    int n=0;
    if(add_dls)for(int i=0;i<dls.size();i++)
    {
      if(!dls[i].active)continue;
      dls[i].update();n++;
    }
    auto ms=c.MS()-a0;
    Sleep(0);
    qap_add_back(t)=FToS(a0)+" ms    "+FToS(ms)+" ms";
    if(iter==128+16){
      string tmp=join(t,"\n");
      int readit=1;
    }
    int gg=1;
  }
}