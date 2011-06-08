#include "Friend.h"

namespace XfireKit
{
    Friend::Friend(uint32 p_userID)
    {
        m_userID = p_userID;
    }
    
    Friend::~Friend()
    {
    }
    
    
    
    std::string Friend::displayName()
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
        
        m_session   = p_other.m_session;
        
        m_gameID    = p_other.m_gameID;
        m_gameIP    = p_other.m_gameIP;
        m_gamePort  = p_other.m_gamePort;
        
        m_publicIP      = p_other.m_publicIP;
        m_publicPort    = p_other.m_publicPort;
        
        m_sendSequence = p_other.m_sendSequence;
        
        
        
        return *this;
    }
    
    bool Friend::operator==(const Friend &p_other)
    {
        return (m_userID == p_other.m_userID);
    }
}
