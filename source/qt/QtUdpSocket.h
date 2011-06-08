#ifndef XK_HEADER_QT_UDP_SOCKET
#define XK_HEADER_QT_UDP_SOCKET

#include <QObject>
#include <UdpSocket.h>

class QUdpSocket;

namespace XfireKit
{
    class QtUdpSocket : public QObject, public UdpSocket
    {
        Q_OBJECT
    public:
        QtUdpSocket();

        bool bind(uint32 p_ip, uint16 p_port);
        bool isBound() const;

        virtual uint64 send(uint32 p_ip, uint16 p_port, const ByteStorage &p_data, uint64 p_len = 0);

    private:
        QUdpSocket *m_socket;

    private slots:
        void readyRead();
    };
}

#endif // XK_HEADER_QT_UDP_SOCKET
