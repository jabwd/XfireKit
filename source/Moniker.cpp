#include <iostream>
#include "Moniker.h"

namespace XfireKit
{
	Moniker::Moniker()
	{
		// TODO: Figure out the length of an Xfire moniker
		m_data = new uint8[16];
	}
	
	Moniker::Moniker(const uint8 *p_data)
	{
		memcpy(m_data, p_data, sizeof(p_data));
	}
	
	Moniker::Moniker(const Moniker &p_other)
	{
		memcpy(m_data, p_other.m_data, sizeof(p_other.m_data));
	}
	
	Moniker::~Moniker()
	{
		delete[] m_data;
	}
	
	Moniker &Moniker::operator=(const Moniker &p_other)
	{
		memcpy(m_data, p_other.m_data, sizeof(p_other.m_data));
		return *this;
	}
	
	bool Moniker::operator==(const Moniker &p_other)
	{
		return false;
	}
	
	bool Moniker::isValid()
	{
		return false;
	}
}