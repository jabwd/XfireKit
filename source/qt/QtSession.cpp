#include "QtSession.h"
#include "QtSocketFactory.h"

namespace XfireKit
{
    QtSession::QtSession() :
        Session(new QtSocketFactory())
    {
    }
}
