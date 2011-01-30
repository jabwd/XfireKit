#include "XFKit.h"

class XFFriend
{
public:
	XFFriend();
	~XFFriend();
	
	XFUInteger32	userID;
	XFUInteger32	publicIP;
	XFUInteger32	publicPort;
	XFUInteger32	externalIP;
	XFUInteger32	externalPort;
	XFUInteger32  gameID;
	XFUInteger32  gameIP;
	XFUInteger32  gamePort;
	
	// TODO: Add NAT type
	
	XFInteger8    *sessionID;
	XFInteger8    *moniker;
	
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