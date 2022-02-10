

void EntryPoint_v02(IEnvRTTI&Env)
{
  eWindowList::RegAll(Env);
  ISubProgram::IEnv env={Env,nullptr};
  TAutoPtr<ISubProgram> Root;
  auto*root=Root.build<QapStarter>(Env);
  root->Update(env);
}