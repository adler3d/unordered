#ifdef DEF_BUILD_MACRO
  #include "../Macro/part2.h"
#else
//=====>>>>>part2

class TTypeInfo{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeInfo)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Name,SET,"unnamed",$)\
ADDVAR(int,Size,SET,0,$)\
ADDVAR(int,Align,SET,0,$)\
ADDEND()
//=====+>>>>>TTypeInfo
#include "QapGenStruct.inl"
//<<<<<+=====TTypeInfo
public:
};

//не конкретный описатель метатипов.
class TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TSelfPtr<SelfClass>,Self,DEF,$,$)\
ADDVAR(THardPtr<IEnvRTTI>,Env,DEF,$,$)\
ADDVAR(THardPtr<IFactory>,Factory,DEF,$,$)\
ADDVAR(TTypeInfo,Info,DEF,$,$)\
ADDEND()
//=====+>>>>>TType
#include "QapGenStruct.inl"
//<<<<<+=====TType
public:
  static void SysHasSelf();
public:
  virtual void Use(IVisitorRTTI&);
  virtual string GetFullName();
  virtual TType*GetMetaType(IEnvRTTI&Env);
  virtual TType*GetSubType()const;
  bool ready()const;
  IAllocator*GetAlloc();
  bool CanDestroy()const;
public:
  bool IsBasedOn(TType*A)const;
};
//ќписатель системных метатипов.
class TTypeSys:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeSys)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<IBinIO>,BinIO,DEF,$,$)\
ADDVAR(THardPtr<ITxtIO>,TxtIO,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeSys
#include "QapGenStruct.inl"
//<<<<<+=====TTypeSys
public:
  void Use(IVisitorRTTI&A);
  ~TTypeSys();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
};

//ќписатель метатипов описывающих вектор.
class TTypeVector:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeVector)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,SizeType,DEF,$,$)\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(THardPtr<IVectorAPI>,VecAPI,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeVector
#include "QapGenStruct.inl"
//<<<<<+=====TTypeVector
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
};

//ќписатель метатипов описывающих массив.
class TTypeArray:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeArray)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(int,Size,SET,0,$)\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeArray
#include "QapGenStruct.inl"
//<<<<<+=====TTypeArray
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
};

//ќписатель метатипов описывающих виртуальный коструктор.
class TTypeFactory:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeFactory)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(THardPtr<TType>,SubType,DEF,$,$)\
ADDVAR(THardPtr<TType>,SmartType,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeFactory
#include "QapGenStruct.inl"
//<<<<<+=====TTypeFactory
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
  TType*GetSubType()const{return SubType?SubType.get():nullptr;}
};

class IEsoteric;

class QapSysMember{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(QapSysMember)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,Name,SET,"unnamed",$)\
ADDVAR(THardPtr<TType>,Type,DEF,$,$)\
ADDEND()
//=====+>>>>>QapSysMember
#include "QapGenStruct.inl"
//<<<<<+=====QapSysMember
public:
  void set(const string&Name,TType*Type);
};

//ќписатель метатипов описывающих умный указатель "точка входа".
class TTypeSelfPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeSelfPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(QapSysMember,mSaveID,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeSelfPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeSelfPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env);
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
public:
  typedef TDynSelfPtrFactory TDynamicFactory;
};
//ќписатель метатипов описывающих "владеющий умный указатель".
class TTypeAutoPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeAutoPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(QapSysMember,mType,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeAutoPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeAutoPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env);
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
};

//ќписатель метатипов описывающих "слабый след€щий умный указатель".
class TTypeWeakPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeWeakPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(QapSysMember,mSaveID,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeWeakPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeWeakPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env);
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
};
//ќписатель метатипов описывающих "сильный след€щий умный указатель".
class TTypeHardPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeHardPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,ElementType,DEF,$,$)\
ADDVAR(QapSysMember,mSaveID,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeHardPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeHardPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env);
public:
  void Use(IVisitorRTTI&A);
  string GetElementName();
  string GetFullName();
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
};

//SmartType - это TWeakPtr<TType> спецально дл€ внутреностей.
class TTypeVoidPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeVoidPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapSysMember,mType,DEF,$,$)\
ADDVAR(QapSysMember,mPtr,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeVoidPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeVoidPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env);
public:
  void Use(IVisitorRTTI&A);
  string GetFullName(){return Info.Name;}
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
};

class TVoidPtr;
//костыль
class TTypeFieldPtr:public TType{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeFieldPtr)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(QapSysMember,mObject,DEF,$,$)\
ADDVAR(QapSysMember,mType,DEF,$,$)\
ADDVAR(QapSysMember,mOffset,DEF,$,$)\
ADDVAR(QapSysMember,mIndex,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeFieldPtr
#include "QapGenStruct.inl"
//<<<<<+=====TTypeFieldPtr
public:
  template<class QAPRTTI>
  void InitFields(QAPRTTI&Env);
  void Use(IVisitorRTTI&A);
  string GetFullName(){return Info.Name;}
  TType*GetMetaType(IEnvRTTI&Env);
public:
  static SelfClass*UberCast(TType*ptr);
};

//ќписатель метатипов описывающих конкретные структуры.
class TTypeStruct:public TType{
public:
  class Member{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(Member)OWNER(TTypeStruct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(string,Name,SET,"unnamed",$)\
    ADDVAR(int,Offset,SET,0,$)\
    ADDVAR(THardPtr<TType>,Type,DEF,$,$)\
    ADDVAR(string,Mode,DEF,$,$)\
    ADDVAR(string,Value,DEF,$,$)\
    ADDEND()
    //=====+>>>>>Member
    #include "QapGenStruct.inl"
    //<<<<<+=====Member
  public:
    void*getValue(void*pValue);
  };
  class TExtInfo{
  public:
    #define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TExtInfo)OWNER(TTypeStruct)
    #define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
    ADDBEG()\
    ADDVAR(int,SelfId,SET,-1,$)\
    ADDVAR(string,SpecInfo,DEF,$,$)\
    ADDVAR(bool,Polymorph,SET,false,$)\
    ADDVAR(bool,Abstract,SET,false,$)\
    ADDVAR(bool,PoorDesign,SET,false,$)\
    ADDEND()
    //=====+>>>>>TExtInfo
    #include "QapGenStruct.inl"
    //<<<<<+=====TExtInfo
  public:
  };
public:
#define DEF_PRO_NESTED(F)F(Member)F(TExtInfo)
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(TTypeStruct)PARENT(TType)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(THardPtr<TType>,SubType,DEF,$,$)\
ADDVAR(THardPtr<TType>,OwnType,DEF,$,$)\
ADDVAR(vector<Member>,Members,DEF,$,$)\
ADDVAR(vector<THardPtr<TType>>,Nesteds,DEF,$,$)\
ADDVAR(TExtInfo,extInfo,DEF,$,$)\
ADDEND()
//=====+>>>>>TTypeStruct
#include "QapGenStruct.inl"
//<<<<<+=====TTypeStruct
public:
  void Use(IVisitorRTTI&A);
  static string GetElementName(THardPtr<TType>&ElementType);
  string GetFullName();
public:
  string GetDebugInfo();
public:
  bool TestField(const Member&it,int depth=0);
public:
  static SelfClass*UberCast(TType*ptr);
public:
  template<class TYPE>
  static TYPE*AddOffset(TYPE*pValue,int offset);
  struct IsStruct
  {
    static Member*GetNearSelf(THardPtr<TType>&pType);
    static Member*GetNearSelf(TType*type);
    struct MemberIndexByOffset
    {
      struct FieldInfo{
        TTypeStruct*base;
        int index;
        Member*get();
      };
      struct Input{
        TType*type;
        int offset;
        TType*fieldtype;
      };
      struct Output{
        int index;
        FieldInfo info;
      };
      static bool get(Input&in,Output&out);
    };
  };
  Member*GetNearSelf();
public:
  void AddField(Member&&field);
  void AddMemberSET(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value);
  void AddMemberDEF(TType*MemType,const string&MemName,int Offset,const string&Mode,const string&Value);
  void AddMemberSYS(...);
  void AddMemberSYD(...);
  void AddNested(TType*NestedType);
public:
  static vector<string>&get_white_list();
  static bool find_in_white_list(const string&type_fullname);
  void SelfTesting();
public:
  void Calc();
  static int getAligned(int offset,int align);
  void ReCalcMembersOffset();
  TType*GetMetaType(IEnvRTTI&Env);
  TType*GetSubType()const;
  bool IsEqual(TTypeStruct*type);
  bool hasMember(const string&name);
  Member&unsafe_find_member(const string&name);
  Member*find_member(const string&name);
  Member*find_member_full(const string&name);
public:
  typedef TDynStructFactory TDynamicFactory;
};

//<<<<<=====part2
#endif //DEF_BUILD_MICRO//