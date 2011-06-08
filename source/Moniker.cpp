#include "Moniker.h"

namespace XfireKit
{
	Moniker::Moniker()
	{
        m_data.resize(16);
	}
	
    Moniker::Moniker(const ByteStorage &p_data)
	{
        m_data = p_data;
	}
	
	Moniker::Moniker(const Moniker &p_other)
	{
        m_data = p_other.m_data;
	}
	
	Moniker &Moniker::operator=(const Moniker &p_other)
	{
        m_data = p_other.m_data;
		return *this;
	}
	
	bool Moniker::operator==(const Moniker &p_other)
	{
        return m_data == p_other.m_data;
	}
	
	bool Moniker::isValid()
	{
		return false;
	}
}
