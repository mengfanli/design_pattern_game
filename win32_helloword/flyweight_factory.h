#pragma once
#include "concrete_flyweight.h"
#include <map>

// ���ڻ�ȡİ���ˣ��������ͷ��
class StrangeFactory
{
public:
	// ��� T/CT ������ڣ���ֱ�Ӵ���Ԫ�ػ�ȡ�����򣬴���һ���¶�����ӵ���Ԫ���У�Ȼ�󷵻ء�
	static Strange* getStrange(std::string type);
	

private:
	// �洢 T/CT ������Ԫ�أ�
	static std::map<std::string, Strange*> m_map;
};
