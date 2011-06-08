#include "QtTcpSocket.h"
#include <QTcpSocket>
#include <QHostAddress>

namespace XfireKit
{
    QtTcpSocket::QtTcpSocket() :
        QObject(),
        TcpSocket(),
        m_socket(new QTcpSocket(this))
    {
        QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(connected()));
        QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
        QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    }

    bool QtTcpSocket::connect(const std::string &p_host, uint16 p_port)
    {
        if(m_socket->state() != QTcpSocket::UnconnectedState)
            return false;

        m_socket->connectToHost(QString::fromStdString(p_host), p_port);
        return true;
    }

    void QtTcpSocket::disconnect()
    {
        m_socket->close();
    }

    bool QtTcpSocket::isConnected() const
    {
        return (m_socket->state() == QTcpSocket::ConnectedState);
    }

    uint64 QtTcpSocket::send(const ByteStorage &p_data, uint64 p_len)
    {
        if(p_len > p_data.size())
            p_len = 0;

        return m_socket->write(reinterpret_cast<const char*>(p_data.constData()),
                               p_len ? p_len : p_data.size());
    }

    void QtTcpSocket::connected()
    {
        if(delegate())
            delegate()->connected();
    }

    void QtTcpSocket::disconnected()
    {
        if(delegate())
            delegate()->disconnected();
    }

    void QtTcpSocket::readyRead()
    {
        if(!delegate())
            return;

        ByteStorage storage;
        storage.resize(m_socket->bytesAvailable());

        m_socket->read(reinterpret_cast<char*>(storage.data()), storage.size());
        delegate()->dataAvailable(storage, m_socket->peerAddress().toIPv4Address(), m_socket->peerPort());
    }
}
