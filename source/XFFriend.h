#include "XFKit.h"

namespace XfireKit
{
	class XFFriend
	{
	public:
		XFFriend();
		~XFFriend();
		
		uint32	userID;
		uint32	publicIP;
		uint32	publicPort;
		uint32	externalIP;
		uint32	externalPort;
		uint32  gameID;
		uint32  gameIP;
		uint32  gamePort;
		
		// TODO: Add NAT type
		
		uint8    *sessionID;
		uint8    *moniker;
		
		string userName;
		string nickName;
		string firstName;
		string lastName;
		
		bool online;
		bool friendOfFriend;
		
		/*
		 * Returns a description of the XFFriend which we can use
		 * for debug logging!
		 * TODO: Add more details
		 */
		void description();
	private:
		
	};
}