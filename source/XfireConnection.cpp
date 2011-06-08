#include "XfireConnection.h"
#include "AbstractSocketFactory.h"
#include "Session.h"
#include "TcpSocket.h"
#include "Packet.h"

namespace XfireKit
{
	XfireConnection::XfireConnection(Session *p_session) :
		m_session(p_session),
		m_socket(0)
	{
	}

	XfireConnection::~XfireConnection()
	{
		delete m_socket;
	}

	bool XfireConnection::connect()
	{
		if(m_socket)
			return false;

		m_socket = m_session->socketFactory()->createTcpSocket();
		m_socket->setDelegate(new Delegate(this));

		if(!m_socket->connect(XFIRE_HOST, XFIRE_PORT))
		{
			delete m_socket;
			m_socket = 0;
			return false;
		}

		return true;
	}

	XfireConnection::Delegate::Delegate(XfireConnection *p_con) :
		m_con(p_con)
	{
	}

	void XfireConnection::Delegate::connected()
	{
		XFInfo("Connected\n");
		m_con->m_socket->send("UA01");
	}

	void XfireConnection::Delegate::disconnected()
	{
		XFInfo("Disconnected\n");
	}

	void XfireConnection::Delegate::dataAvailable(ByteStorage p_data, uint32 p_ip, uint16 p_port)
	{
		(void)p_ip; (void)p_port;
		static ByteStorage buffer;
		uint offset = 0;

		XFInfo("Got data!\n");

		while(offset != p_data.size())
		{
			// Get the packet length
			if(buffer.size() < 2)
			{
				buffer.append(p_data.constData() + offset, min(2 - buffer.size(), p_data.size() - offset));
				offset += min(2 - buffer.size(), p_data.size() - offset);
			}

			// Wait for more if we still have no length
			if(buffer.size() != 2)
				return;

			// Read the rest of the received data
			uint16 length = *reinterpret_cast<const uint16*>(buffer.constData());
			if(length < TcpPacket::headerSize())
			{
				XFError("Got invalid packet (no header)!\n");
				return;
			}

			buffer.append(p_data.constData() + offset, min(length - buffer.size(), p_data.size() - offset));
			offset += min(length - buffer.size(), p_data.size() - offset);

			// Handle complete packet
			if(buffer.size() == length)
			{
				TcpPacket packet = TcpPacket::parsePacket(p_data);
				if(packet.type() == InvalidPacket)
					XFError("Got invalid packet!\n");
				else
					XFInfo("Got valid packet!\n");

				buffer.clear();
			}
		}
	}
}
