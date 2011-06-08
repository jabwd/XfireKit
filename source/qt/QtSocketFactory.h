#ifndef XK_HEADER_QT_SOCKET_FACTORY
#define XK_HEADER_QT_SOCKET_FACTORY

#include <AbstractSocketFactory.h>

namespace XfireKit
{
    class QtSocketFactory : public AbstractSocketFactory
    {
    public:
        QtSocketFactory();

        TcpSocket *createTcpSocket();
        UdpSocket *createUdpSocket();
    };
}

#endif // XK_HEADER_QT_SOCKET_FACTORY
