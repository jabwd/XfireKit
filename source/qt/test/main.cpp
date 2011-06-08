#include <QCoreApplication>
#include <QtSession.h>

int main(int p_argc, char *p_argv[])
{
    if(p_argc < 3)
        return 1;

    QCoreApplication app(p_argc, p_argv);

    XfireKit::QtSession session;
    if(!session.start(p_argv[1], p_argv[2]))
        return 1;

    return app.exec();
}
