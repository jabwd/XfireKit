#include "Friend.h"

namespace XfireKit
{
    Friend::Friend(uint32 p_userID, Session *p_session)
    {
        m_userID    = p_userID;
        m_session   = p_session;
    }
    
    Friend::~Friend()
    {
    }
    
    
    
    const std::string &Friend::displayName() const
    {
        // TODO: Add support for xfire preferences
        if( m_nickname.length() > 0 )
        {
            return m_nickname;
        }
        return m_username;
    }
    
    Friend &Friend::operator=(const Friend &p_other)
    {
        m_userID    = p_other.m_userID;
        m_username  = p_other.m_username;
        m_nickname  = p_other.m_nickname;
        m_firstName = p_other.m_firstName;
        m_lastName  = p_other.m_lastName;
        m_isOnline  = p_other.m_isOnline;
        
        m_session   = p_other.m_session;
        m_sessionID = p_other.m_sessionID;
        
        m_gameID    = p_other.m_gameID;
        m_gameIP    = p_other.m_gameIP;
        m_gamePort  = p_other.m_gamePort;
        
        m_publicIP      = p_other.m_publicIP;
        m_publicPort    = p_other.m_publicPort;
        
        m_sendSequence = p_other.m_sendSequence;
        
        
        
        return *this;
    }
    
    bool Friend::operator==(const Friend &p_other) const
    {
        return (m_userID == p_other.m_userID);
    }
}
