t_reg reg(ctti); t_mem mem(ctti); t_raw_pro raw(ctti);t_ptr ptr(ctti);
#define F(NAME)auto&NAME=reg[::NAME];
DEF_PRO_REGISTERS(F)
#undef F