#ifndef XK_HEADER_UDP_SOCKET
#define XK_HEADER_UDP_SOCKET

#include <SocketDelegate.h>
#include <XfireKit.h>

namespace XfireKit
{
    class ByteStorage;

    class XK_EXPORT UdpSocket
    {
    public:
        UdpSocket();
        ~UdpSocket();

        virtual bool bind(uint32 p_ip, uint16 p_port) = 0;
        virtual bool isBound() const = 0;

        virtual uint64 send(uint32 p_ip, uint16 p_port, const ByteStorage &p_data, uint64 p_len = 0) = 0;

        void setDelegate(SocketDelegate *p_delegate);
        SocketDelegate *delegate() const;

    private:
        SocketDelegate *m_delegate;
    };

    inline void UdpSocket::setDelegate(SocketDelegate *p_delegate)
    { delete m_delegate; m_delegate = p_delegate; }

    inline SocketDelegate *UdpSocket::delegate() const
    { return m_delegate; }
}

#endif // XK_HEADER_UDP_SOCKET
