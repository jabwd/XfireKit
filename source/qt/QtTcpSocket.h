#ifndef XK_HEADER_QT_TCP_SOCKET
#define XK_HEADER_QT_TCP_SOCKET

#include <QObject>
#include <TcpSocket.h>

class QTcpSocket;

namespace XfireKit
{
    class QtTcpSocket : public QObject, public TcpSocket
    {
        Q_OBJECT
    public:
        QtTcpSocket();

        bool connect(const std::string &p_host, uint16 p_port);
        void disconnect();

        bool isConnected() const;

        uint64 send(const ByteStorage &p_data, uint64 p_len = 0);

    private:
        QTcpSocket *m_socket;

    private slots:
        void connected();
        void disconnected();
        void readyRead();
    };
}

#endif // XK_HEADER_QT_TCP_SOCKET
