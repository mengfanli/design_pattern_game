#include "stdafx.h"
#include "warrior.h"
extern enum attribute_type{ hp, att, def, coins, exper, NUM_ATTRI };
Iwarrior::Iwarrior(const Iwarrior& obj) {
	NAME = obj.NAME;
	HP = obj.HP;
	ATT = obj.ATT;
	DEF = obj.DEF;
	COINS = obj.COINS;
	EXPERIENCE = obj.EXPERIENCE;
}
Iwarrior & Iwarrior::operator =(const Iwarrior & war) {
	if (this != &war) {
		this->ATT = war.ATT;
		this->COINS = war.COINS;
		this->DEF = war.DEF;
		this->EXPERIENCE = war.EXPERIENCE;
		this->HP = war.HP;
		this->NAME = war.NAME;
	}
	return *this;
}

int Iwarrior::get_info(int attribute) {
	switch (attribute) {
	case hp:
		return HP;
	case att:
		return ATT;
	case def:
		return DEF;
	case coins:
		return COINS;
	case exper:
		return EXPERIENCE;
	}
}
void Iwarrior::update_info(int attribute,int value) {
	switch (attribute) {
	case hp:
		HP += value;
		break;
	case att:
		ATT += value;
		break;
	case def:
		DEF += value;
		break;
	case coins:
		COINS += value;
		break;
	case exper:
		EXPERIENCE += value;
		break;
	}
}
