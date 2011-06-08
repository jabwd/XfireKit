#include "QtUdpSocket.h"
#include <QUdpSocket>
#include <QHostAddress>

namespace XfireKit
{
    QtUdpSocket::QtUdpSocket() :
        QObject(),
        UdpSocket(),
        m_socket(new QUdpSocket(this))
    {
        connect(m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    }

    bool QtUdpSocket::bind(uint32 p_ip, uint16 p_port)
    {
        return m_socket->bind(QHostAddress(p_ip), p_port);
    }

    bool QtUdpSocket::isBound() const
    {
        return (m_socket->state() == QUdpSocket::BoundState);
    }

    uint64 QtUdpSocket::send(uint32 p_ip, uint16 p_port, const ByteStorage &p_data, uint64 p_len)
    {
        if(p_len > p_data.size())
            p_len = 0;
        return m_socket->writeDatagram(reinterpret_cast<const char*>(p_data.constData()),
                                       p_len ? p_len : p_data.size(),
                                       QHostAddress(p_ip), p_port);
    }

    void QtUdpSocket::readyRead()
    {
        if(!delegate())
            return;

        ByteStorage storage;
        QHostAddress ip;
        quint16 port;

        while(m_socket->hasPendingDatagrams())
        {
            storage.resize(m_socket->pendingDatagramSize());
            m_socket->readDatagram(reinterpret_cast<char*>(storage.data()), storage.size(), &ip, &port);
            delegate()->dataAvailable(storage, ip.toIPv4Address(), port);
        }
    }
}
