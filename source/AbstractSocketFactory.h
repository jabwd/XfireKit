#ifndef XK_HEADER_ABSTRACT_SOCKET_FACTORY
#define XK_HEADER_ABSTRACT_SOCKET_FACTORY

namespace XfireKit
{
    class TcpSocket;
    class UdpSocket;

    class AbstractSocketFactory
    {
    public:
        AbstractSocketFactory() {}

        virtual TcpSocket *createTcpSocket() = 0;
        virtual UdpSocket *createUdpSocket() = 0;
    };
}

#endif // XK_HEADER_ABSTRACT_SOCKET_FACTORY
