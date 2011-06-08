#include "TcpSocket.h"

namespace XfireKit
{
    TcpSocket::TcpSocket() :
        m_delegate(0)
    {
    }

    TcpSocket::~TcpSocket()
    {
        delete m_delegate;
    }
}
