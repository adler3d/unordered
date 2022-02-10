#define DEF_PRO_ENTRY_AS_ADDFIELD(TYPE,NAME,VALUE)TYPE NAME;
#define DEF_PRO_ENTRY_AS_DORESET(TYPE,NAME,VALUE)t_$::set(this->NAME,VALUE);

#define DEF_PRO_FIELDS_AND_DORESET()\
  DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_ADDFIELD)\
  void DoReset(){t_$ $;DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_DORESET)}\
//

#include "packed_beg.inl"
DEF_PRO_FIELDS_AND_DORESET()
#include "packed_end.inl"

#ifdef DEF_PRO_CLASSNAME
  typedef DEF_PRO_CLASSNAME() SelfClass;
  #ifndef DEF_PRO_BACKUP
    #define DEF_PRO_BACKUP_IMPL(ProxySys)
  #else
    #define DEF_PRO_ENTRY_AS_BACKUP_LOAD(TYPE,NAME,VALUE)this->NAME=ref.NAME;
    #define DEF_PRO_ENTRY_AS_BACKUP_SAVE(TYPE,NAME,VALUE)ref.NAME=this->NAME;
    #define DEF_PRO_ENTRY_AS_BACKUP_MOVE_LOAD(TYPE,NAME,VALUE)this->NAME=std::move(ref.NAME);
    #define DEF_PRO_ENTRY_AS_BACKUP_MOVE_SAVE(TYPE,NAME,VALUE)ref.NAME=std::move(this->NAME);
    #define DEF_PRO_BACKUP_IMPL(ProxySys)\
      struct SelfClassBackup{\
        typedef SelfClassBackup SelfClass;\
        typedef DEF_PRO_CLASSNAME() MainClass;\
        DEF_PRO_FIELDS_AND_DORESET()\
        void Load(const MainClass&ref){DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_BACKUP_LOAD);}\
        void Load(const MainClass*ptr){Load(*ptr);}\
        void Save(MainClass&ref)const{DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_BACKUP_SAVE);}\
        void Save(MainClass*ptr)const{Save(*ptr);}\
        void LoadFrom(const MainClass&ref){Load(ref);}\
        void LoadFrom(const MainClass*ptr){Load(*ptr);}\
        void SaveTo(MainClass&ref)const{Save(ref);}\
        void SaveTo(MainClass*ptr)const{Save(*ptr);}\
        void MoveLoad(MainClass&&ref){DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_BACKUP_MOVE_LOAD);}\
        void MoveSave(MainClass& ref){DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_BACKUP_MOVE_SAVE);}\
        ProxySys\
      };\
      typedef SelfClassBackup DEF_PRO_BACKUP();\
    //
  #endif
  #define TOTEXT(A)#A
  #define TOTEXT2(A)TOTEXT(A)
  static const string qap_def_pro_get_class_name(){return TOTEXT2(DEF_PRO_CLASSNAME());}
  #undef TOTEXT2
  #undef TOTEXT
  #define DEF_PRO_ENTRY_AS_MOVE_OPER(TYPE,NAME,VALUE)this->NAME=std::move(ref.NAME);
  #define DEF_PRO_ENTRY_AS_COPY_OPER(TYPE,NAME,VALUE)this->NAME=ref.NAME;
  #define DEF_PRO_ENTRY_AS_EQUAL_OPER(TYPE,NAME,VALUE)if(this->NAME!=ref.NAME){\
    QapDebugMsg(qap_def_pro_get_class_name()+"::"+#NAME+"\ndiff:\n"+qap_def_pro_diff(this->NAME,ref.NAME));ok=false;\
  }
  
  #define DEF_PRO_CTORS_AND_OPERS()\
    void operator=(SelfClass&&ref){oper_set(std::move(ref));}\
    SelfClass(SelfClass&&ref){DoReset();oper_set(std::move(ref));}\
    SelfClass(){DoReset();}\
    SelfClass(const SelfClass&ref)=default;\
    void oper_set(SelfClass&&ref){DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_MOVE_OPER);}\
    void oper_set(const SelfClass&ref){DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_COPY_OPER);}\
    bool oper_eq(const SelfClass&ref)const{bool ok=true;DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_EQUAL_OPER);return ok;}\
    bool oper_neq(const SelfClass&ref)const{return !oper_eq(ref);}\
    bool operator==(const SelfClass&ref)const{return oper_eq(ref);}\
    bool operator!=(const SelfClass&ref)const{return oper_neq(ref);}\
    void operator=(const SelfClass&ref){return oper_set(ref);}\
  //
  
  DEF_PRO_CTORS_AND_OPERS()
  
  #ifdef DEF_PRO_UNSAVEABLE
    DEF_PRO_BACKUP_IMPL(;)
  #else
    #ifdef DEF_PRO_TEMPLATE_DATAIO
      #define DEF_PRO_TEMPLATE_FUNC_PREFIX()template<class QapIO>
    #else
      #define DEF_PRO_TEMPLATE_FUNC_PREFIX()
    #endif
    
    #define DEF_PRO_ENTRY_AS_PROXYSYS_SAVE(TYPE,NAME,VALUE)Sys$$<TYPE>::Save(IO,ref.NAME);
    #define DEF_PRO_ENTRY_AS_PROXYSYS_LOAD(TYPE,NAME,VALUE)Sys$$<TYPE>::Load(IO,ref.NAME);
    #define DEF_PRO_ENTRY_AS_PROXYSYS_POD_(TYPE,NAME,VALUE)&&QapIsPOD<TYPE>()
    #define DEF_PRO_PROXY_SYS()\
      struct ProxySys$${\
        constexpr static bool IsPod(){\
          return (true)DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_PROXYSYS_POD_);\
        }\
        DEF_PRO_TEMPLATE_FUNC_PREFIX()\
        static void Save(QapIO&IO,SelfClass&ref){\
          if constexpr(IsPod()){\
            IO.ForceSaveAsPOD(ref);\
          }else{\
            DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_PROXYSYS_SAVE);\
          }\
        }\
        DEF_PRO_TEMPLATE_FUNC_PREFIX()\
        static void Load(QapIO&IO,SelfClass&ref){\
          if constexpr(IsPod()){\
            IO.ForceLoadAsPOD(ref);\
          }else{\
            DEF_PRO_VARIABLE(DEF_PRO_ENTRY_AS_PROXYSYS_LOAD);\
          }\
        }\
      };\
    //
    
    DEF_PRO_PROXY_SYS()
    DEF_PRO_BACKUP_IMPL(DEF_PRO_PROXY_SYS()DEF_PRO_CTORS_AND_OPERS())
    
    #undef DEF_PRO_ENTRY_AS_PROXYSYS_LOAD
    #undef DEF_PRO_ENTRY_AS_PROXYSYS_SAVE
    #undef DEF_PRO_ENTRY_AS_PROXYSYS_POD_
    
    #ifdef DEF_PRO_TEMPLATE_DATAIO
      #undef DEF_PRO_TEMPLATE_DATAIO
    #endif //DEF_PRO_TEMPLATE_DATAIO
    
    #undef DEF_PRO_PROXY_SYS
    #undef DEF_PRO_TEMPLATE_FUNC_PREFIX
  #endif //DEF_PRO_UNSAVEABLE
  
  #undef DEF_PRO_CTORS_AND_OPERS
  
  #undef DEF_PRO_ENTRY_AS_EQUAL_OPER
  #undef DEF_PRO_ENTRY_AS_COPY_OPER
  #undef DEF_PRO_ENTRY_AS_MOVE_OPER
  
  #ifndef DEF_PRO_BACKUP
    #undef DEF_PRO_BACKUP_IMPL
  #else
    #undef DEF_PRO_BACKUP_IMPL
    
    #undef DEF_PRO_ENTRY_AS_BACKUP_MOVE_SAVE
    #undef DEF_PRO_ENTRY_AS_BACKUP_MOVE_LOAD
    #undef DEF_PRO_ENTRY_AS_BACKUP_SAVE
    #undef DEF_PRO_ENTRY_AS_BACKUP_LOAD
    //#undef DEF_PRO_ENTRY_AS_ADDFIELD
      
    #undef DEF_PRO_BACKUP
  #endif //DEF_PRO_BACKUP
  
  #undef DEF_PRO_CLASSNAME
#endif //DEF_PRO_CLASSNAME

#ifdef DEF_PRO_UNSAVEABLE
  #undef DEF_PRO_UNSAVEABLE
#endif

#undef DEF_PRO_FIELDS_AND_DORESET

#undef DEF_PRO_ENTRY_AS_DORESET
#undef DEF_PRO_ENTRY_AS_ADDFIELD

#undef DEF_PRO_VARIABLE