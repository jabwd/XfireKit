#ifndef XK_HEADER_SOCKET_DELEGATE
#define XK_HEADER_SOCKET_DELEGATE

#include <ByteStorage.h>

namespace XfireKit
{
    class SocketDelegate
    {
    public:
        SocketDelegate() {}

        virtual void dataAvailable(ByteStorage p_data, uint32 p_ip, uint16 p_port)
            {(void)p_data;(void)p_ip;(void)p_port;}

        virtual void connected() {}
        virtual void disconnected() {}
    };
}

#endif // XK_HEADER_SOCKET_DELEGATE
