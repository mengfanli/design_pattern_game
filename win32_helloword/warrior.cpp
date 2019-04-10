#include "stdafx.h"
#include "warrior.h"
extern enum attribute_type{ hp, att, def, coins, exper, NUM_ATTRI };
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
