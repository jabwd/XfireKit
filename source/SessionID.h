#include <ByteStorage.h>

#define XK_SESSIONID_LEN 16

namespace XfireKit
{
	static const uint8 invalidData[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	class SessionID 
	{
	public:
		SessionID();
        SessionID(const ByteStorage &p_data);
		SessionID(const SessionID &p_other);
		
		SessionID &operator=(const SessionID &p_other);
		
		/*
		 * So we can do if( sessionID1 == sessionID2 )
		 */
		bool operator==(const SessionID &p_other);
		
		// checks whether the sessionID contains a valid sessionID
		bool isValid();

    private:
		/*
		 * Instance variables
		 */
        ByteStorage m_data;
	};
}
