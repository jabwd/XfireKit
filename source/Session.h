#ifndef XK_HEADER_SESSION
#define XK_HEADER_SESSION

#include <XfireKit.h>
#include <string>

namespace XfireKit
{
    class AbstractSocketFactory;
    class XfireConnection;

    class XK_EXPORT Session
    {
    public:
        Session(AbstractSocketFactory *p_socketFactory);
        ~Session();

        bool start(const std::string &p_username, const std::string &p_password);

        AbstractSocketFactory *socketFactory() const;

    private:
        AbstractSocketFactory *m_socketFactory;
        XfireConnection *m_connection;

        std::string m_username;
        std::string m_password;
    };

    inline AbstractSocketFactory *Session::socketFactory() const
    { return m_socketFactory; }
}

#endif // XK_HEADER_SESSION
