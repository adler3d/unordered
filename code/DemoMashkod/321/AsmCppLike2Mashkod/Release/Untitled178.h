
итак. векторов нет.
но есть строки.
можно попробовать хранить всё внутри строк, но в бинарном виде спецально для того, чтобы не связываться с 
текстовым представлением.



struct vec2i{int i;int y;}
struct t_input{
  int tick;
  vec2i mouse_pos;
  string userdata;
  string net;
  string sound_recorder;
  string camera;
  string keyboard;
}

struct t_display{
  struct t_mode{
    bool fill;
  }
  struct t_set_mode_cmd{
    int id;
  }
  struct t_circle_cmd{
    
  }
  struct t_line_cmd{
    
  }
  vector<t_mode> modes;
  vector<t_color> colors;
  vector<t_circle> circles;
  vector<t_line> lines;
  vector<t_cmd> cmds;
}

struct t_output{
  string display;
  string userdata;
  string net;
  string sound;
}

очень охота выводить линии.