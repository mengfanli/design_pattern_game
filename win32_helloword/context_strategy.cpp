#include "stdafx.h"
#include "context_strategy.h"
Context::Context(Istrategy *strategy) {
	m_pstrategy = strategy;
}
void Context::do_attack() {
	m_pstrategy->do_attack();
}
void Context::show_info() {
	m_pstrategy->show_info();
}
void Context::set_strategy(Istrategy *strategy) {
	m_pstrategy = strategy;
}