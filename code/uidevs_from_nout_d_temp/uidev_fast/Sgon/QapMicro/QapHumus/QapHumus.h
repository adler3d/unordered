#define NO_HDR
//#define NO_PNG
#define NO_JPEG
#define NO_PCX
//#pragma warning(disable:4217) //libjpeg.lib(jerror.o) : warning LNK4217: локально определенный символ __iob импортирован в функцию _output_message

#ifdef DEF_BUILD_MICRO
  #define _WINDOWS_
  #define _D3D9_H_
#else
  #include "platform.cpp"
  #include "Image.cpp"
#endif //DEF_BUILD_MICRO//