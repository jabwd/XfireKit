#include <ByteStorage.h>
#include <Session.h>

#define AVATAR_IMAGE_DEFAULT "http://media.xfire.com/xfire/xf/images/avatars/gallery/default/xfire100.jpg"
#define AVATAR_IMAGE_GALLERY "http://media.xfire.com/xfire/xf/images/avatars/gallery/default/%u.gif"
#define AVATAR_IMAGE_CUSTOM  "http://screenshot.xfire.com/avatar/160/%s.jpg?%u"


namespace XfireKit
{
	class Friend 
	{
	public:
		Friend(uint32 p_userID);
		~Friend();
        
        uint32 userID();
        std::string username();
        std::string nickname();
        std::string firstName();
        std::string lastName();
        Session     *session();
        uint32      gameID();
        uint32      gameIP();
        uint16      gamePort();
        uint32      publicIP();
        uint16      publicPort();
        uint64      sendSequence();
        
        // this method checks the xfire prefs whether the user wants to show
        // nicknames, or usernames in the friends list
        std::string displayName();
        
        // operators
        bool    operator==(const Friend &p_other);
        Friend  &operator=(const Friend &p_other);
        
    private:
        
        // basic user information
        uint32      m_userID;
        std::string m_username;
        std::string m_nickname;
        std::string m_firstName;
        std::string m_lastName;
        
        // assigned value, no need to release this
        Session     *m_session;
        
        // games
        uint32 m_gameID;
        uint32 m_gameIP;
        uint16 m_gamePort;
        
        // peer to peer
        uint32 m_publicIP;
        uint16 m_publicPort;
        
        // chatting
        uint64 m_sendSequence;
        
        ///---------------------------
        //std::string m_clanNickname;
	};
    
    inline uint32 Friend::userID()
    { return m_userID; }
    
    inline std::string Friend::username()
    { return m_username; }
    
    inline std::string Friend::nickname()
    { return m_nickname; }
    
    inline std::string Friend::firstName()
    { return m_firstName; }
    
    inline std::string Friend::lastName()
    { return m_lastName; }
    
    inline Session * Friend::session()
    { return m_session; }
    
    inline uint32 Friend::gameID()
    { return m_gameID; }
    
    inline uint32 Friend::gameIP()
    { return m_gameIP; }
    
    inline uint16 Friend::gamePort()
    { return m_gamePort; }
    
    inline uint32 Friend::publicIP()
    { return m_publicIP; }
    
    inline uint16 Friend::publicPort()
    { return m_publicPort; }
    
    inline uint64 Friend::sendSequence()
    { return m_sendSequence; }
}
