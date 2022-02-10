//описание шаблона генерирующего лексуму:
template{lexem TYPE,lexem SEP}
t_vec_with_sep{
  t_item{TYPE body;SEP sep;{go_auto(sep);go_auto(body);}}
  TYPE first;
  vector<t_item> arr;
  {
    M+=go_auto(first);
    O+=go_auto(arr);
  }
}
//пример использования.
t_func_class_stat=>i_class_stat{
  t_keyword{string keyword;{go_any_str_from_vec(keyword,split("explicit,constexpr,virtual,const,static",","));}}
  typedef t_vec_with_sep{t_keyword,t_sep} t_keywords; //вот тут мы сгенерируем лексему t_keywords. а потом по ней С++ код.
  string keywords;
  {
    O+=go_str<t_keywords>(keywords);
  }
}

template{lexem TYPE,lexem SEP}
t_lexem_with_two_sep{SEP bef;TYPE body;SEP aft;{O+=go_auto(bef);M+=go_auto(body);O+=go_auto(aft);}}
typedef t_lexem_with_two_sep{t_type_expr,t_sep} t_type_expr_with_sep;