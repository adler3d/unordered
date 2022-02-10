можно всех наследников i_page загнать в посетитель.

но тогда когда мне захочеться создать какие-то новые страницы что я буду делать?

t_page_with_book=>i_page{
  vector<TAutoPtr<i_page>> arr;
}

t_page_with_node=>i_page{
  t_node node;
}

t_rect_with_offset=>i_rect{
  vec2d offset;
  vec2d size;
  t_rect rect;
  TAutoPtr<i_rect> content;
}

t_rect_with_node=>i_rect{
  t_node node;
}

t_node{
  vector<TAutoPtr<i_rect>> arr;
}

// какие-то не очевидные для разработчика книжной системы компоненты будут размещены тут.
// потом особенно удачные будет внедренны.
t_page_with_content=i_page{
  TAutoPtr<i_content> content;
}



t_book{
  vector<i_page> arr;
  t_render_context{
    vector<t_book*>&stack;
    vec2d owner_apos;
    vec2d owner_size;
  };
  void render_internal(vec2d offset)
  {
    
  }
  void update_internal(vec2d offset)
  {
    
  }
}

t_book_app{
  vec2d pos;
  vec2d sizel
  t_book book;
  void render()
  {
    book.render_internal(pos,size);
  }
}


t_page_with_book=>i_page{
  t_rect rect;
  t_book book;
  void render()
  {
    book.render_internal(rect.pos,rect.size);
  }
}

-----------------------------
страница{
  t_item{
    t_content_book=>i_content{}
    t_embed=>i_content{}
    t_single=>i_layout{
      
    }
    t_absolute=>i_layout{
      vec2d pos;
      vec2d size;
    }
    TAutoPtr<i_layout> layout;
    TAutoPtr<i_content> content;
  }
  vector<t_item>  items;
  квадратик=>элемент_страницы{
    t_content_book=>i_content{}
    t_embed=>i_content{}
    TRawRect rect;
    TAutoPtr<i_content> content;
  }
  другая_книга_во_всю_страницу=>элемент_страницы{
    
  }
  квадратики=>{
    vector<t_elem>
  }
}