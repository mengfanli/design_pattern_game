#pragma once
#include "flyweight.h"
class Monster : public Strange
{
public:
	Monster();
	//virtual void assignAttDef(std::int16_t att_v)override {	}
	virtual void mission()override;
};
class Senior : public Strange
{
public:
	Senior();
	//virtual void assignAttDef(std::int16_t att_v)override {}
	virtual void mission()override;
};