#ifndef XK_HEADER_TCP_SOCKET
#define XK_HEADER_TCP_SOCKET

#include <SocketDelegate.h>
#include <string>
#include <XfireKit.h>

namespace XfireKit
{
    class ByteStorage;

    class XK_EXPORT TcpSocket
    {
    public:
        TcpSocket();
        ~TcpSocket();

        virtual bool connect(const std::string &p_host, uint16 p_port) = 0;
        virtual void disconnect() = 0;

        virtual bool isConnected() const = 0;

        virtual uint64 send(const ByteStorage &p_data, uint64 p_len = 0) = 0;

        void setDelegate(SocketDelegate *p_delegate);
        SocketDelegate *delegate() const;

    private:
        SocketDelegate *m_delegate;
    };

    inline void TcpSocket::setDelegate(SocketDelegate *p_delegate)
    { delete m_delegate; m_delegate = p_delegate; }

    inline SocketDelegate *TcpSocket::delegate() const
    { return m_delegate; }
}

#endif // XK_HEADER_TCP_SOCKET
