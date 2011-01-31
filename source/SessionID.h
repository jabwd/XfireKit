#include "XfireKit.h"

#define XK_SESSIONID_LEN 16

namespace XfireKit
{
	static const uint8 invalidData[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	class SessionID 
	{
	public:
		SessionID();
		SessionID(const uint8 p_data[XK_SESSIONID_LEN]);
		SessionID(const SessionID &p_other);
		~SessionID();
		
		SessionID &operator=(const SessionID &p_other);
		
		/*
		 * So we can do if( sessionID1 == sessionID2 )
		 */
		bool operator==(const SessionID &p_other);
		
		// checks whether the sessionID contains a valid sessionID
		bool isValid();
		
		/*
		 * Instance variables
		 */
		uint8 m_data[];
	private:
	};
}