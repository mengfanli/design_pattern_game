#include "stdafx.h"
#include "product_equipment.h"
extern enum attribute_type{ hp, att, def, coins, exper, NUM_ATTRI };
int Iequipment::get_info(int attribute) {
		switch (attribute) {
		case hp:
			return HP_GAIN;
		case att:
			return ATT_GAIN;
		case def:
			return DEF_GAIN;
		case coins:
			return COIN_COST;
		case exper:
			return EXPERIENCE;
		}
};

Iequipment::Iequipment(int HP_GAIN, int DEF_GAIN, int ATT_GAIN, int COIN_COST, int EXPERIENCE)
{
	this->HP_GAIN = HP_GAIN;
	this->ATT_GAIN = ATT_GAIN;
	this->DEF_GAIN = DEF_GAIN;
	this->COIN_COST = COIN_COST;
	this->EXPERIENCE = EXPERIENCE;
};
