#include "Session.h"
#include "AbstractSocketFactory.h"
#include "XfireConnection.h"

namespace XfireKit
{
    Session::Session(AbstractSocketFactory *p_socketFactory) :
        m_socketFactory(p_socketFactory),
        m_connection(0)
    {
    }

    Session::~Session()
    {
        delete m_connection;
        delete m_socketFactory;
    }

    bool Session::start(const std::string &p_username, const std::string &p_password)
    {
        if(m_connection)
            return false;

        m_username = p_username;
        m_password = p_password;

        XFInfo("Starting session for account \"%s\"\n", m_username.c_str());

        m_connection = new XfireConnection(this);
        if(!m_connection->connect())
        {
            delete m_connection;
            m_connection = 0;
            return false;
        }

        return true;
    }
}
