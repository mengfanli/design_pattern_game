#pragma once
#include "Istrategy.h"
class Context
{
public:
	Context();
	Context(Istrategy *strategy);
	void set_strategy(Istrategy *strategy);
	void do_attack();
	void show_info();

private:
	Istrategy *m_pstrategy;
};
