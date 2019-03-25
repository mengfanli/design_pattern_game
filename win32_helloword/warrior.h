#pragma once
#include <string>

using namespace std;
//所有出场人+物的基类
class Iwarrior
{
public:
	virtual string Name() = 0;	//纯虚函数
	virtual void Attribute() = 0;
protected:
	int ATT  ;
	int DEF ;
	int HP  ;
};