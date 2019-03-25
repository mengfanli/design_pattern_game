#pragma once
#include "warrior.h"
class EquipmentDedcorator :public Iwarrior
{
protected:
	Iwarrior *m_pWarrior;
	int ATT_gain ;
	int DEF_gain ;
	int HP_gain  ;
public:
	EquipmentDedcorator(Iwarrior *warrior):m_pWarrior(warrior)	{}

	string Name() {
		return m_pWarrior->Name();
	}
	void Attribute() {
		ATT += ATT_gain;
		DEF += DEF_gain;
		HP  += HP_gain;
	}
	
};