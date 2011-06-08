#include "QtSocketFactory.h"
#include "QtTcpSocket.h"
#include "QtUdpSocket.h"

namespace XfireKit
{
    QtSocketFactory::QtSocketFactory() :
        AbstractSocketFactory()
    {
    }

    TcpSocket *QtSocketFactory::createTcpSocket()
    {
        return new QtTcpSocket();
    }

    UdpSocket *QtSocketFactory::createUdpSocket()
    {
        return new QtUdpSocket();
    }
}
