#pragma once
#include <string>

using namespace std;
//���г�����+��Ļ���
class Iwarrior
{
public:
	virtual string Name() = 0;	//���麯��
	virtual void Attribute() = 0;
protected:
	int ATT  ;
	int DEF ;
	int HP  ;
};