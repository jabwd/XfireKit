#ifndef XK_HEADER_BYTE_STORAGE
#define XK_HEADER_BYTE_STORAGE

#include "XfireKit.h"
#include <cstring>

#define XK_BYTE_STORAGE_RESERVE	20

namespace XfireKit
{
	class XK_EXPORT ByteStorage
	{
	public:
		// Constructors
		ByteStorage();
		ByteStorage(const ByteStorage &p_other);
		ByteStorage(const char *p_str, int p_len = -1);
		ByteStorage(const uint8 *p_data, uint p_len);
        ~ByteStorage();

		// State
		uint size() const;
		bool isEmpty() const;

		// Modifying
		void detach();

		void resize(uint p_size);
		void clear();

		ByteStorage &insert(uint p_pos, const uint8 *p_data, uint p_len);
		ByteStorage &insert(uint p_pos, const char *p_str, int p_len = -1);
		ByteStorage &insert(uint p_pos, const ByteStorage &p_storage);
		ByteStorage &insertByte(uint p_pos, uint8 p_byte);
        ByteStorage &insertInt32(uint p_pos, uint32 p_int32);
        ByteStorage &insertInt64(uint p_pos, uint64 p_int64);

		ByteStorage &prepend(const uint8 *p_data, uint p_len);
		ByteStorage &prepend(const char *p_str, int p_len = -1);
		ByteStorage &prepend(const ByteStorage &p_storage);
		ByteStorage &prependByte(uint8 p_byte);
		ByteStorage &prependInt32(uint32 p_int32);
		ByteStorage &prependInt64(uint64 p_int64);

		ByteStorage &append(const uint8 *p_data, uint p_len);
		ByteStorage &append(const char *p_str, int p_len = -1);
		ByteStorage &append(const ByteStorage &p_storage);
		ByteStorage &appendByte(uint8 p_byte);
		ByteStorage &appendInt32(uint32 p_int32);
		ByteStorage &appendInt64(uint64 p_int64);

		// Accessing
		uint8 *data();
		const uint8 *constData() const;

		uint8 at(uint p_index) const;
		uint8 operator[](uint p_index) const;
		uint8 &operator[](uint p_index);

		// Operators
		ByteStorage &operator=(const ByteStorage &p_other);
        bool operator==(const ByteStorage &p_other) const;

	private:
		struct StorageData
		{
			uint ref;
			uint size;
			uint reserved;
			uint8 data[1];
		};
		static StorageData emptyData;

		StorageData *m_data;
	};

	// Inline implementations

	inline uint ByteStorage::size() const
	{ return m_data->size; }

	inline bool ByteStorage::isEmpty() const
	{ return (m_data->size == 0); }

	inline ByteStorage &ByteStorage::insert(uint p_pos, const char *p_str, int p_len)
	{ return insert(p_pos, (const uint8*)p_str, (p_len < 0) ? strlen(p_str) : p_len); }

	inline ByteStorage &ByteStorage::insert(uint p_pos, const ByteStorage &p_storage)
	{ return insert(p_pos, p_storage.m_data->data, p_storage.m_data->size); }

	inline ByteStorage &ByteStorage::insertByte(uint p_pos, uint8 p_byte)
	{ return insert(p_pos, &p_byte, 1); }

    inline ByteStorage &ByteStorage::insertInt32(uint p_pos, uint32 p_int32)
	{ return insert(p_pos, (uint8*)&p_int32, 4); }

    inline ByteStorage &ByteStorage::insertInt64(uint p_pos, uint64 p_int64)
	{ return insert(p_pos, (uint8*)&p_int64, 8); }

	inline ByteStorage &ByteStorage::prepend(const uint8 *p_data, uint p_len)
	{ return insert(0, p_data, p_len); }

	inline ByteStorage &ByteStorage::prepend(const char *p_str, int p_len)
	{ return insert(0, p_str, p_len); }

	inline ByteStorage &ByteStorage::prepend(const ByteStorage &p_storage)
	{ return insert(0, p_storage); }

	inline ByteStorage &ByteStorage::prependByte(uint8 p_byte)
	{ return insertByte(0, p_byte); }

	inline ByteStorage &ByteStorage::prependInt32(uint32 p_int32)
	{ return insertInt32(0, p_int32); }

	inline ByteStorage &ByteStorage::prependInt64(uint64 p_int64)
	{ return insertInt64(0, p_int64); }

	inline ByteStorage &ByteStorage::append(const uint8 *p_data, uint p_len)
	{ return insert(m_data->size, p_data, p_len); }

	inline ByteStorage &ByteStorage::append(const char *p_str, int p_len)
	{ return insert(m_data->size, p_str, p_len); }

	inline ByteStorage &ByteStorage::append(const ByteStorage &p_storage)
	{ return insert(m_data->size, p_storage); }

	inline ByteStorage &ByteStorage::appendByte(uint8 p_byte)
	{ return insertByte(m_data->size, p_byte); }

	inline ByteStorage &ByteStorage::appendInt32(uint32 p_int32)
	{ return insertInt32(m_data->size, p_int32); }

	inline ByteStorage &ByteStorage::appendInt64(uint64 p_int64)
	{ return insertInt64(m_data->size, p_int64); }

	inline uint8 *ByteStorage::data()
	{ detach(); return m_data->data; }

	inline const uint8 *ByteStorage::constData() const
	{ return m_data->data; }

	inline uint8 ByteStorage::at(uint p_index) const
	{ return m_data->data[p_index]; }

	inline uint8 ByteStorage::operator[](uint p_index) const
	{ return m_data->data[p_index]; }

	inline uint8 &ByteStorage::operator[](uint p_index)
	{ detach(); return m_data->data[p_index]; }
}

#endif // XK_HEADER_BYTE_STORAGE
