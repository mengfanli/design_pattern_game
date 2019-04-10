#include "stdafx.h"
#include "flyweight_factory.h"

// 如果 T/CT 对象存在，则直接从享元池获取；否则，创建一个新对象并添加到享元池中，然后返回。
Strange* StrangeFactory::getStrange(std::string type)
{
	Strange *p = NULL;
	if (m_map.find(type) != m_map.end()) {
		p = m_map[type];
	}
	else {
		// 创建 T/CT 对象
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
		// 一旦创建，将其插入到 map 中
		m_map.insert(std::make_pair(type, p));
	}
	return p;
}
