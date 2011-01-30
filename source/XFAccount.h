#include "XFKit.h"

class XFSession;
class XFFriend;

namespace XfireKit
{
	class XFAccount
	{
	public:
		XFAccount();
		~XFAccount();
		
		/*
		 * Instance variables
		 */
		XFSession *session;
		XFFriend  *identity;
		
	private:
	};
}