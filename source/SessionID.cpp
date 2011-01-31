#include "SessionID.h"

namespace XfireKit
{
	SessionID::SessionID()
	{
	}
	
	
	SessionID::SessionID(const uint8 *p_data)
	{
		memcpy(m_data, p_data, XK_SESSIONID_LEN);
	}
	
	SessionID::SessionID(const SessionID &p_other)
	{
		memcpy(m_data, p_other.m_data, XK_SESSIONID_LEN);
	}
	
	SessionID::~SessionID()
	{
		delete[] m_data;

	}
	
	/*
	 * For easier copying
	 */
	SessionID &SessionID::operator=(const SessionID &p_other)
	{
		memcpy(m_data, p_other.m_data, XK_SESSIONID_LEN);
		return *this;
	}
	
	/*
	 * So we can do if( sessionID1 == sessionID2 )
	 */
	bool SessionID::operator==(const SessionID &p_other)
	{
		return (memcmp(m_data, m_data, XK_SESSIONID_LEN) != 0);
	}
	
	/*
	 * Make sure this sessionID is valid
	 */
	bool SessionID::isValid()
	{
		return (memcmp(m_data, invalidData, XK_SESSIONID_LEN) != 0);
	}
}