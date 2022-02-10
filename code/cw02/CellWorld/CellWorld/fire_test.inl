void AddRuleV4()
{
  unsigned E=CellWorld::CharToCellType('E');
  unsigned Y=CellWorld::CharToCellType('Y');
  unsigned X=CellWorld::CharToCellType('X');
  auto&tools=add_new_tools();
  /*
  .X.
  XYX
  .X.

  .Y.
  YEY
  .Y.
  */
  tools.add(X,Y,1,0);
  tools.add(X,Y,0,1);
  tools.add(Y,E,1,1);
  tools.add(X,Y,2,1);
  tools.add(X,Y,1,2);
  tools.calc_usefullmodes();
  add_rules_from_tools(tools);
}
void AddRuleV5()
{
  unsigned E=CellWorld::CharToCellType('E');
  unsigned Y=CellWorld::CharToCellType('Y');
  unsigned X=CellWorld::CharToCellType('X');
  auto&tools=add_new_tools();
  /*
  EYX
  EYY
  */
  tools.add(E,E,0,0);
  tools.add(Y,Y,1,0);
  tools.add(X,Y,2,0);
  tools.calc_usefullmodes();
  add_rules_from_tools(tools);
}
void AddRuleV6()
{
  unsigned E=CellWorld::CharToCellType('E');
  unsigned Y=CellWorld::CharToCellType('Y');
  unsigned X=CellWorld::CharToCellType('X');
  auto&tools=add_new_tools();
  /*
  EYY

  EEY
  */
  tools.add(E,E,0,0);
  tools.add(Y,E,1,0);
  tools.add(Y,Y,2,0);
  tools.calc_usefullmodes();
  add_rules_from_tools(tools);
}
void AddRuleV7()
{
  unsigned E=CellWorld::CharToCellType('E');
  unsigned Y=CellWorld::CharToCellType('Y');
  unsigned X=CellWorld::CharToCellType('X');
  auto&tools=add_new_tools();
  /*
  XE
  EE

  YE
  EE
  */
  tools.add(X,Y,0,0);
  tools.add(E,E,1,0);
  tools.add(E,E,0,1);
  tools.add(E,E,1,1);
  tools.calc_usefullmodes();
  add_rules_from_tools(tools);
}
void AddRuleV8()
{
  unsigned E=CellWorld::CharToCellType('E');
  unsigned Y=CellWorld::CharToCellType('Y');
  unsigned X=CellWorld::CharToCellType('X');
  auto&tools=add_new_tools();
  /*
  XY
  YY

  YY
  YE
  */
  tools.add(X,Y,0,0);
  tools.add(Y,Y,1,0);
  tools.add(Y,Y,0,1);
  tools.add(Y,E,1,1);
  tools.calc_usefullmodes();
  add_rules_from_tools(tools);
}