#pragma once
#include <iostream>
#include <string>
class Strange
{
public:
	Strange();
	~Strange();
	virtual void assignAttDef(std::int16_t att_v);
	//virtual void mission() = 0;
	virtual void mission(){}
	virtual int getatt();

protected:
	std::string m_task;//�ڲ�״̬
	std::int16_t m_att_v;//�ⲿ״̬
};
