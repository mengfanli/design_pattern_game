#pragma once
#include "warrior.h"

class Soldier : public Iwarrior
{
private:
	int ATT_gain = 300;
	int DEF_gain = 300;
	int HP_gain = 1000;
public:
	string Name() {
		return "Soldier";
	}
	void Attribute() {
		ATT = ATT_gain;
		DEF = DEF_gain;
		HP = HP_gain;
	}
};

class Assassin : public Iwarrior
{
private:
	int ATT_gain = 300;
	int DEF_gain = 300;
	int HP_gain = 1000;
public:
	string Name() {
		return "Assassin";
	}
	void Attribute() {
		ATT = ATT_gain;
		DEF = DEF_gain;
		HP = HP_gain;
	}
};

class Tank : public Iwarrior
{
private:
	int ATT_gain = 300;
	int DEF_gain = 300;
	int HP_gain = 1000;
public:
	string Name() {
		return "Tank";
	}
	void Attribute() {
		ATT = ATT_gain;
		DEF = DEF_gain;
		HP = HP_gain;
	}
};