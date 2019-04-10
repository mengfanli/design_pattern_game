#pragma once
#include "concrete_flyweight.h"
#include <map>

// 用于获取陌生人（怪物或老头）
class StrangeFactory
{
public:
	// 如果 T/CT 对象存在，则直接从享元池获取；否则，创建一个新对象并添加到享元池中，然后返回。
	static Strange* getStrange(std::string type);
	

private:
	// 存储 T/CT 对象（享元池）
	static std::map<std::string, Strange*> m_map;
};
