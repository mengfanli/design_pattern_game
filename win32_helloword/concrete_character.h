#pragma once
#include "warrior.h"

class Soldier : public Iwarrior
{
public:
	//string Name();
	std::string Name();
	Soldier();
};

class Assassin : public Iwarrior
{
public:
	std::string Name();
	Assassin();
};

class Tank : public Iwarrior
{
public:
	std::string Name();
	Tank();
};