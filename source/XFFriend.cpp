#include "XFFriend.h"

XFFriend::XFFriend()
{
}

XFFriend::~XFFriend()
{
	
	if( this->sessionID )
		free(this->sessionID);
	
	if( this->moniker )
		free(this->moniker);
	
}

/*
 * A method that returns the description of the
 * current XFFriend instance.
 * TODO: add more details
 */
void XFFriend::description()
{	
	xfPrintf("XFFriend\nUserID = %u\nUsername = \"%s\"",this->userID,this->userName.data());
}