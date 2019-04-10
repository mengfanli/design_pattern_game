#pragma once
#include "Istrategy.h"
class ConcreteStrategy1:public Istrategy
{
public:
	virtual void do_attack()override;
	virtual void show_info()override;
};

class ConcreteStrategy2:public Istrategy
{
public:
	virtual void do_attack()override;
	virtual void show_info()override;
};

class ConcreteStrategy3:public Istrategy
{
public:
	virtual void do_attack()override;
	virtual void show_info()override;
};

