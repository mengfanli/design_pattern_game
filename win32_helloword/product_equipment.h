#pragma once
#include <string>
class Iequipment
{
public:
	Iequipment(){}
	Iequipment(int HP_GAIN,int DEF_GAIN,int ATT_GAIN, int COIN_COST, int EXPERIENCE);
	~Iequipment(){}
	virtual std::string Name() = 0;
	//virtual void set_info(int h, int a, int d) = 0;
	virtual int get_info(int attribute);
protected:
	int HP_GAIN;
	int DEF_GAIN;
	int ATT_GAIN;
	int COIN_COST;
	int EXPERIENCE;//对装备为0
};