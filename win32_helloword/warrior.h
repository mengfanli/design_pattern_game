#pragma once
#include <string>
//���г�����+��Ļ���
class Iwarrior
{
public:
	//virtual std::string Name() = 0;	//���麯��
	//virtual void Attribute() = 0;
	//get()
	int get_info(int attribute);
	void update_info(int attribute, int value);
	Iwarrior(){}
	Iwarrior(const Iwarrior &obj);
	Iwarrior & operator =(const Iwarrior & war);
protected:
	int HP  ;
	std::string NAME;
	int ATT ;
	int DEF ;
	int COINS = 20;
	int EXPERIENCE = 100;
};