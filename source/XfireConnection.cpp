#include "XfireConnection.h"
#include "AbstractSocketFactory.h"
#include "Session.h"
#include "TcpSocket.h"

namespace XfireKit
{
    XfireConnection::XfireConnection(Session *p_session) :
        m_session(p_session),
        m_socket(0)
    {
    }

    XfireConnection::~XfireConnection()
    {
        delete m_socket;
    }

    bool XfireConnection::connect()
    {
        if(m_socket)
            return false;

        m_socket = m_session->socketFactory()->createTcpSocket();
        m_socket->setDelegate(new Delegate(this));

        if(!m_socket->connect(XFIRE_HOST, XFIRE_PORT))
        {
            delete m_socket;
            m_socket = 0;
            return false;
        }

        return true;
    }

    XfireConnection::Delegate::Delegate(XfireConnection *p_con) :
        m_con(p_con)
    {
    }

    void XfireConnection::Delegate::connected()
    {
        XFInfo("Connected\n");

        //m_con->m_socket->send("UA01");
        m_con->m_socket->send("test");
    }

    void XfireConnection::Delegate::disconnected()
    {
        XFInfo("Disconnected\n");
    }

    void XfireConnection::Delegate::dataAvailable(ByteStorage p_data, uint32 p_ip, uint16 p_port)
    {
        XFInfo("Got data: %s!\n", (const char*)p_data.constData());
    }
}
