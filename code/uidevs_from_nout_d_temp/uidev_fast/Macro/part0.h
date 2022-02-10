//part0
namespace detail {};
//===>>===IVisitorRTTI
class IEnvRTTI;
class TType;
class TTypeSys;
class TTypeStruct;
class TTypeSys;
class TTypeFactory;
class TTypeVector;
class TTypeArray;
class TTypeSelfPtr;
class TTypeAutoPtr;
class TTypeWeakPtr;
class TTypeHardPtr;
class TTypeVoidPtr;
class TTypeFieldPtr;
class IVisitorRTTI
{
public:
  //#define ADD(TYPE)virtual void Do(TYPE*p)=0;
  //  LIST(DEF_PRO_BLANK,ADD,DEF_PRO_BLANK)
  //#undef ADD
  virtual void Do(TTypeStruct*p)=0;
  virtual void Do(TTypeSys*p)=0;
  virtual void Do(TTypeFactory*p) {}
  virtual void Do(TTypeVector*p)=0;
  virtual void Do(TTypeArray*p)=0;
  virtual void Do(TTypeSelfPtr*p)=0;
  virtual void Do(TTypeAutoPtr*p)=0;
  virtual void Do(TTypeWeakPtr*p)=0;
  virtual void Do(TTypeHardPtr*p)=0;
  virtual void Do(TTypeVoidPtr*p)=0;
  virtual void Do(TTypeFieldPtr*p)=0;
public:
  template<class TYPE,class Visitor>
  struct Is:public Visitor
  {
    TYPE*ptr;
    Is():ptr(nullptr) {}
public:
    template<class U>static TYPE*get(U*p)
    {
      return nullptr;
    }
    template<>static TYPE*get<TYPE>(TYPE*p)
    {
      return p;
    }
public:
    void Do(TTypeStruct*p)
    {
      ptr=get(p);
    }void Do(TTypeSys*p)
    {
      ptr=get(p);
    }void Do(TTypeFactory*p)
    {
      ptr=get(p);
    }void Do(TTypeVector*p)
    {
      ptr=get(p);
    }void Do(TTypeArray*p)
    {
      ptr=get(p);
    }void Do(TTypeSelfPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeAutoPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeWeakPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeHardPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeVoidPtr*p)
    {
      ptr=get(p);
    }void Do(TTypeFieldPtr*p)
    {
      ptr=get(p);
    }
  };
  template<class TYPE>
  static TYPE*UberCast(TType*p)
  {
    if (!p)return nullptr;
    Is<TYPE,IVisitorRTTI> IS;
    p->Use(IS);
    return IS.ptr;
  }
};
//===<<===IVisitorRTTI
template<class SYS_TYPE>class Sys$$;
