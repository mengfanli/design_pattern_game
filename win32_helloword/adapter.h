#pragma once
#include "product_equipment.h"
#include "flyweight.h"
#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
class GetinfoAdapter:public Iequipment,Strange
{
public:
	GetinfoAdapter(std::string type):m_pstrange(StrangeFactory::getStrange(type)){}
	~GetinfoAdapter();
	virtual int get_info(int attribute) {
		switch (attribute) {
		case hp:
			return 0;
		case att:
			return m_pstrange->getatt();
		case def:
			return 0;
		case coins :
			return 2;
		case exper:
			return 2;
		}
	}


private:
	Strange *m_pstrange;//持有需要被适配的接口对象 -小怪
};

GetinfoAdapter::~GetinfoAdapter()
{
}
