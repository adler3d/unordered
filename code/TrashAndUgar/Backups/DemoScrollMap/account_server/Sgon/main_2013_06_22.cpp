class IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()\
//=====+>>>>>IStatement
#include "QapGenStruct.inl"
//<<<<<+=====IStatement
public:
};
class IExpression{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IExpression)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()\
//=====+>>>>>IExpression
#include "QapGenStruct.inl"
//<<<<<+=====IExpression
public:
};
class BlockStatement:public IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BlockStatement)PARENT(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<IStatement>>,arr,DEF,$,$)\
ADDEND()\
//=====+>>>>>BlockStatement
#include "QapGenStruct.inl"
//<<<<<+=====BlockStatement
public:
};
class VariableDeclarator:public IExpression{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(VariableDeclarator)PARENT(IExpression)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,id,DEF,$,$)\
ADDVAR(TAutoPtr<IExpression>,init,DEF,$,$)\
ADDEND()\
//=====+>>>>>VariableDeclarator
#include "QapGenStruct.inl"
//<<<<<+=====VariableDeclarator
public:
};
class t_program{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(t_program)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<TAutoPtr<IStatement>>,nodes,DEF,$,$)\
ADDEND()\
//=====+>>>>>t_program
#include "QapGenStruct.inl"
//<<<<<+=====t_program
public:
};
class FunctionDeclaration:public IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(FunctionDeclaration)PARENT(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,id,DEF,$,$)\
ADDVAR(vector<string>,params,DEF,$,$)\
ADDVAR(BlockStatement,body,DEF,$,$)\
ADDEND()\
//=====+>>>>>FunctionDeclaration
#include "QapGenStruct.inl"
//<<<<<+=====FunctionDeclaration
public:
};
class ExpressionStatement:public IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ExpressionStatement)PARENT(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<IExpression>,expression,DEF,$,$)\
ADDEND()\
//=====+>>>>>ExpressionStatement
#include "QapGenStruct.inl"
//<<<<<+=====ExpressionStatement
public:
};
class VariableStatement:public IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(VariableStatement)PARENT(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(vector<VariableDeclarator>,declarations,DEF,$,$)\
ADDEND()\
//=====+>>>>>VariableStatement
#include "QapGenStruct.inl"
//<<<<<+=====VariableStatement
public:
};
class CallExpression:public IExpression{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(CallExpression)PARENT(IExpression)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<IExpression>,callee,DEF,$,$)\
ADDVAR(vector<TAutoPtr<IExpression>>,arguments,DEF,$,$)\
ADDEND()\
//=====+>>>>>CallExpression
#include "QapGenStruct.inl"
//<<<<<+=====CallExpression
public:
};
class LiteralExpression:public IExpression{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(LiteralExpression)PARENT(IExpression)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,kind,DEF,$,$)\
ADDVAR(string,value,DEF,$,$)\
ADDEND()\
//=====+>>>>>LiteralExpression
#include "QapGenStruct.inl"
//<<<<<+=====LiteralExpression
public:
};
class IdentifierExpression:public IExpression{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IdentifierExpression)PARENT(IExpression)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,name,DEF,$,$)\
ADDEND()\
//=====+>>>>>IdentifierExpression
#include "QapGenStruct.inl"
//<<<<<+=====IdentifierExpression
public:
};
class IfStatement:public IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(IfStatement)PARENT(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<IExpression>,test,DEF,$,$)\
ADDVAR(TAutoPtr<IStatement>,consequent,DEF,$,$)\
ADDVAR(TAutoPtr<IStatement>,alternate,DEF,$,$)\
ADDEND()\
//=====+>>>>>IfStatement
#include "QapGenStruct.inl"
//<<<<<+=====IfStatement
public:
};
class ForStatement:public IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ForStatement)PARENT(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(TAutoPtr<IExpression>,init,DEF,$,$)\
ADDVAR(TAutoPtr<IExpression>,test,DEF,$,$)\
ADDVAR(TAutoPtr<IExpression>,update,DEF,$,$)\
ADDVAR(TAutoPtr<IStatement>,body,DEF,$,$)\
ADDEND()\
//=====+>>>>>ForStatement
#include "QapGenStruct.inl"
//<<<<<+=====ForStatement
public:
};
class BinaryExpression:public IExpression{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BinaryExpression)PARENT(IExpression)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,oper,DEF,$,$)\
ADDVAR(TAutoPtr<IExpression>,left,DEF,$,$)\
ADDVAR(TAutoPtr<IExpression>,right,DEF,$,$)\
ADDEND()\
//=====+>>>>>BinaryExpression
#include "QapGenStruct.inl"
//<<<<<+=====BinaryExpression
public:
};
class UpdateExpression:public IExpression{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(UpdateExpression)PARENT(IExpression)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDVAR(string,oper,DEF,$,$)\
ADDVAR(bool,prefix,DEF,$,$)\
ADDVAR(string,argument,DEF,$,$)\
ADDEND()\
//=====+>>>>>UpdateExpression
#include "QapGenStruct.inl"
//<<<<<+=====UpdateExpression
public:
};
class BreakStatement:public IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(BreakStatement)PARENT(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()\
//=====+>>>>>BreakStatement
#include "QapGenStruct.inl"
//<<<<<+=====BreakStatement
public:
};
class ContinueStatement:public IStatement{
public:
#define DEF_PRO_STRUCT_INFO(NAME,PARENT,OWNER)NAME(ContinueStatement)PARENT(IStatement)
#define DEF_PRO_VARIABLE(ADDBEG,ADDVAR,ADDEND)\
ADDBEG()\
ADDEND()\
//=====+>>>>>ContinueStatement
#include "QapGenStruct.inl"
//<<<<<+=====ContinueStatement
public:
};
