QT = core network
TEMPLATE = lib

INCLUDEPATH += . ..
LIBS += -L../.. -lXfireKit

SOURCES = \
	QtSocketFactory.cpp \
	QtTcpSocket.cpp \
	QtUdpSocket.cpp \
    QtSession.cpp
	
HEADERS = \
	QtSocketFactory.h \
	QtTcpSocket.h \
	QtUdpSocket.h \
    QtSession.h
