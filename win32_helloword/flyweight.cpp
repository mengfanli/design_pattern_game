#include "stdafx.h"
#include "flyweight.h"
void Strange::assignAttDef(std::int16_t att_v) {
	m_att_v = att_v;
}
//virtual void mission() = 0;
int Strange::getatt() { return m_att_v; }

Strange::Strange()
{
}

Strange::~Strange()
{
}