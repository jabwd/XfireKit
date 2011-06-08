#include "UdpSocket.h"

namespace XfireKit
{
    UdpSocket::UdpSocket() :
        m_delegate(0)
    {
    }

    UdpSocket::~UdpSocket()
    {
        delete m_delegate;
    }
}
