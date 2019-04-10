#include "stdafx.h"
#include "equip_factory.h"
//extern enum attribute_type{ hp, att, def, coins, exper, NUM_ATTRI };
bool Afactory::is_coins_enough(int need) {
	return (Singleton_player::GetInstance().get_info(coins) >= need);
}