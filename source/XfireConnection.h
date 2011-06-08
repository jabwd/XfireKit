#ifndef XK_HEADER_XFIRE_CONNECTION
#define XK_HEADER_XFIRE_CONNECTION

#include <SocketDelegate.h>

namespace XfireKit
{
    class Session;
    class TcpSocket;

    class XfireConnection
    {
    public:
        XfireConnection(Session *p_session);
        ~XfireConnection();

        bool connect();

    private:
        class Delegate : public SocketDelegate
        {
        public:
            Delegate(XfireConnection *p_con);

            void connected();
            void disconnected();

            void dataAvailable(ByteStorage p_data, uint32 p_ip, uint16 p_port);

        private:
            XfireConnection *m_con;
        };

        Session *m_session;
        TcpSocket *m_socket;

    friend class Delegate;
    };
}

#endif // XK_HEADER_XFIRE_CONNECTION
