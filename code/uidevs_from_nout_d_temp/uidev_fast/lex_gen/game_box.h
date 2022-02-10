{
  //__UserMsg(__NetDownload("adler.hol.es","/"));
  auto fn="branch.h";//9:07 16:20
  fn="t_type_expr.inl";
  fn="t_inl_parser.inl";
  auto code=__file_get_contents(fn);
  real bef_time=__microtime();
  string msg=__gen_lexem_v01(code);
  real aft_time=__microtime();
  __UserMsg("//time = "+__FToS(0.001*(aft_time-bef_time))+" ms.\n\n"+msg);
  return "";
}