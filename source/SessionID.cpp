#include "SessionID.h"

namespace XfireKit
{
	SessionID::SessionID()
	{
        m_data.resize(XK_SESSIONID_LEN);
	}
	
	
    SessionID::SessionID(const ByteStorage &p_data)
	{
        m_data = p_data;
	}
	
	SessionID::SessionID(const SessionID &p_other)
	{
        m_data = p_other.m_data;
	}
	
	/*
	 * For easier copying
	 */
	SessionID &SessionID::operator=(const SessionID &p_other)
	{
        m_data = p_other.m_data;
		return *this;
	}
	
	/*
	 * So we can do if( sessionID1 == sessionID2 )
	 */
	bool SessionID::operator==(const SessionID &p_other)
	{
        return (m_data == p_other.m_data);
	}
	
	/*
	 * Make sure this sessionID is valid
	 */
	bool SessionID::isValid()
	{
        return false;
	}
}
