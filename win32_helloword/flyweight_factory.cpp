#include "stdafx.h"
#include "flyweight_factory.h"

// ��� T/CT ������ڣ���ֱ�Ӵ���Ԫ�ػ�ȡ�����򣬴���һ���¶�����ӵ���Ԫ���У�Ȼ�󷵻ء�
Strange* StrangeFactory::getStrange(std::string type)
{
	Strange *p = NULL;
	if (m_map.find(type) != m_map.end()) {
		p = m_map[type];
	}
	else {
		// ���� T/CT ����
		if (type == "M") {
			std::cout << "Monster Created" << std::endl;
			p = new Monster();
		}
		else if (type == "H") {
			std::cout << "Senior Created" << std::endl;
			p = new Senior();
		}
		else {
			std::cout << "Unreachable code!" << std::endl;
		}
		// һ��������������뵽 map ��
		m_map.insert(std::make_pair(type, p));
	}
	return p;
}
