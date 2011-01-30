#include "XFKit.h"
#include "XFFriend.h"


class XFConnection;

typedef enum
{
	XFSessionStatusOffline		= 0,
	XFSessionStatusLoggingOff = 1,
	XFSessionStatusLoggingOn	= 2,
	XFSessionStatusOnline			= 3
} XFSessionStatus;

class XFSession
{
public:
	XFSession();
	~XFSession();
	
	/*
	 * Connect to xfire.com given a username and password
	 */
	bool connect(XFUInteger32 ip,XFUInteger16 port);
	void disconnect(); // disconnect an opened connection
	
	/*
	 * Instance variables
	 */
	XFFriend				*loginIdentity;
	XFConnection		*tcpConnection;
	XFSessionStatus status;
	
	
private:
};