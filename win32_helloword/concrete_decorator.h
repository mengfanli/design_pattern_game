#pragma once
#include "decorator.h"
class Armour :public EquipmentDedcorator
{
private:
	int ATT_equip = 0;
	int DEF_equip = 100;
	int HP_equip = 0;
public:
	Armour(Iwarrior *warrior) :EquipmentDedcorator(warrior){}
	string Name() {
		return m_pWarrior->Name() + "Armour";
	}
	void Attribute() {
		ATT_gain = ATT_equip;
		DEF_gain = DEF_equip;
		HP_gain  = HP_equip;
	}
};