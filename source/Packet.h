#ifndef XK_HEADER_PACKET
#define XK_HEADER_PACKET

#include <XfireKit.h>
#include <ByteStorage.h>

namespace XfireKit
{
	class BasePacket
	{
	public:
		BasePacket(PacketType p_type);

		PacketType type() const;
		uint8 attributeCount() const;

	protected:
		void baseToByteStorage(ByteStorage &p_storage, uint32 p_offset) const;

		static bool parseBasePacket(BasePacket &p_packet, const ByteStorage &p_data, uint32 p_offset);

		PacketType m_type;
		uint8 m_numAttributes;
	};

	inline PacketType BasePacket::type() const
	{ return m_type; }

	inline uint8 BasePacket::attributeCount() const
	{ return m_numAttributes; }

	template<typename T>
	class Packet : public BasePacket
	{
	public:
		Packet(PacketType p_type) :
			BasePacket(p_type) {}

		ByteStorage toByteStorage() const;

		static Packet<T> parsePacket(const ByteStorage &p_data);
		static uint8 headerSize();

	private:
		static bool parseHeader(Packet<T> &p_packet, const ByteStorage &p_data);
	};

	template<typename T>
	ByteStorage Packet<T>::toByteStorage() const
	{
		if(m_type == InvalidPacket)
			return ByteStorage();

		ByteStorage storage;
		storage.resize(sizeof(T));
		storage.appendInt16(static_cast<uint16>(m_type));
		storage.appendByte(m_numAttributes);

		baseToByteStorage(storage);

		T size = storage.size();
		storage.replace(0, reinterpret_cast<const uint8*>(&size), sizeof(T));
		return storage;
	}

	template<typename T>
	Packet<T> Packet<T>::parsePacket(const ByteStorage &p_data)
	{
		Packet<T> packet(InvalidPacket);
		if(!parseHeader(packet, p_data))
			return Packet<T>(InvalidPacket);
		if(!parseBasePacket(packet, p_data, headerSize()))
			return Packet<T>(InvalidPacket);
		return packet;
	}

	template<typename T>
	uint8 Packet<T>::headerSize()
	{ return sizeof(T) + 3; }

	template<typename T>
	bool Packet<T>::parseHeader(Packet<T> &p_packet, const ByteStorage &p_data)
	{
		if(p_data.size() < headerSize())
			return false;

		T length = *reinterpret_cast<const T*>(p_data.constData());
		T offset = sizeof(T);

		if(p_data.size() != length)
			return false;

		p_packet.m_type = static_cast<PacketType>(*reinterpret_cast<const uint16*>(p_data.constData() + offset));
		offset += 2;

		p_packet.m_numAttributes = *(p_data.constData() + offset);
		return true;
	}

	typedef Packet<uint16> TcpPacket;
	typedef Packet<uint32> UdpPacket;
}

#endif // XK_HEADER_PACKET
