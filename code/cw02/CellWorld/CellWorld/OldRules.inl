
    void AddRuleV0()
    {
      unsigned R=CellWorld::CharToCellType('R');
      unsigned G=CellWorld::CharToCellType('G');
      unsigned B=CellWorld::CharToCellType('B');
      unsigned X=CellWorld::CharToCellType('X');
      auto&tools=add_new_tools();
      tools.add(R,X,0,0);
      tools.add(G,R,1,0);
      tools.add(X,G,2,0);
      tools.calc_usefullmodes();
      add_rules_from_tools(tools);
      //CellWorld::tools_print(tools);
    }
    void AddRuleV1()
    {
      string inp=(
        "RGBX\n"
      );
      string out=(
        "XRGB\n"
      );
      add_rule_from_str(inp,out);
    }
    void AddRuleV2()
    {
      string inp=(
        "..O\n"
        "RGB\n"
        "..X\n"
      );
      string out=(
        "..O\n"
        "XRG\n"
        "..B\n"
      );
      add_rule_from_str(inp,out);
    }
    void AddRuleV3()
    {
      string inp=(
        "RG\n"
        ".B\n"
        ".X\n"
      );
      string out=(
      "XR\n"
      ".G\n"
      ".B\n"
      );
      add_rule_from_str(inp,out);
    }
    void AddRuleV4()
    {
      string inp=(
        "RGBYX\n"
      );
      string out=(
        "XRGBY\n"
      );
      add_rule_from_str(inp,out);
    }
    void AddRuleV5()
    {
      string inp=(
        "...O\n"
        "RGBY\n"
        "...X\n"
      );
      string out=(
        "...O\n"
        "XRGB\n"
        "...Y\n"
      );
      add_rule_from_str(inp,out);
    }
    void AddRuleV6()
    {
      string inp=(
        "...O\n"
        "RGBE\n"
        "...X\n"
      );
      string out=(
        "...O\n"
        "XRGB\n"
        "...E\n"
      );
      add_rule_from_str(inp,out);
    }
    void AddRuleV7()
    {
      string inp=(
        "RGBEX\n"
      );
      string out=(
        "XRGBE\n"
      );
      add_rule_from_str(inp,out);
    }