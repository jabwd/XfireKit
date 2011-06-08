#include "Packet.h"

namespace XfireKit
{
	BasePacket::BasePacket(PacketType p_type) :
		m_type(p_type),
		m_numAttributes(0)
	{
	}

	void BasePacket::baseToByteStorage(ByteStorage &p_storage, uint32 p_offset) const
	{
	}

	bool BasePacket::parseBasePacket(BasePacket &p_packet, const ByteStorage &p_data, uint32 p_offset)
	{
		return true;
	}
}
