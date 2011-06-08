#include "ByteStorage.h"
#include <cstdlib>

namespace XfireKit
{
	ByteStorage::StorageData ByteStorage::emptyData = { 1, 0 , 0, { 0 } };

	ByteStorage::ByteStorage() :
		m_data(&emptyData)
	{
		m_data->ref++;
	}

	ByteStorage::ByteStorage(const ByteStorage &p_other)
	{
		m_data = p_other.m_data;
		m_data->ref++;
	}

	ByteStorage::ByteStorage(const char *p_str, int p_len)
	{
		uint size = (p_len < 0) ? strlen(p_str) : p_len;
		if(size == 0)
		{
			m_data = &emptyData;
			m_data->ref++;
			return;
		}

		m_data = (StorageData*)malloc(sizeof(StorageData) + size + XK_BYTE_STORAGE_RESERVE);
		m_data->ref = 1;
		m_data->size = size;
		m_data->reserved = XK_BYTE_STORAGE_RESERVE;
		memcpy(m_data->data, p_str, size + 1);
	}

	ByteStorage::ByteStorage(const uint8 *p_data, uint p_len)
	{
		m_data = (StorageData*)malloc(sizeof(StorageData) + p_len + XK_BYTE_STORAGE_RESERVE);
		m_data->ref = 1;
		m_data->size = p_len;
		m_data->reserved = XK_BYTE_STORAGE_RESERVE;
		memcpy(m_data->data, p_data, m_data->size);
		m_data->data[m_data->size] = 0;
	}

	ByteStorage::~ByteStorage()
	{
		m_data->ref--;
		if(!m_data->ref)
			free(m_data);
	}

	void ByteStorage::detach()
	{
		if(m_data->ref == 1)
			return;

		// Copy data
		StorageData *newData = (StorageData*)malloc(sizeof(StorageData) + m_data->size + m_data->reserved);
		newData->ref = 1;
		newData->size = m_data->size;
		newData->reserved = m_data->reserved;
		memcpy(newData->data, m_data->data, m_data->size + 1);

		// Replace our reference
		m_data->ref--;
		m_data = newData;
	}

	void ByteStorage::resize(uint p_size)
	{
		if(m_data->size == p_size)
			return;

		if(p_size == 0)
		{
			clear();
			return;
		}

		detach();

		// Increase size: We have too little space allocated -> reallocate more
		// Decrease size: Always reallocate if we get above the default reserved space
		if(((p_size > m_data->size) && (m_data->size + m_data->reserved <= p_size)) ||
				((p_size < m_data->size) && (m_data->reserved + (m_data->size - p_size) > XK_BYTE_STORAGE_RESERVE)))
		{
			m_data = (StorageData*)realloc(m_data, sizeof(StorageData) + p_size + XK_BYTE_STORAGE_RESERVE);
			m_data->size = p_size;
			m_data->reserved = XK_BYTE_STORAGE_RESERVE;
		}
		else
		{
            uint diff = p_size - m_data->size;
			m_data->size += diff;
			m_data->reserved -= diff;
		}
		m_data->data[m_data->size] = 0;
	}

	void ByteStorage::clear()
	{
		m_data->ref--;
		if(!m_data->ref)
			free(m_data);
		m_data = &emptyData;
		m_data->ref++;
	}

	ByteStorage &ByteStorage::insert(uint p_pos, const uint8 *p_data, uint p_len)
	{
		if(!p_len)
            return *this;

		detach();

		uint oldSize = m_data->size;
		resize(m_data->size + p_len);

		memmove(m_data->data + p_pos + p_len, m_data->data + p_pos, oldSize - p_pos + 1);
		memcpy(m_data + p_pos, p_data, p_len);

		return *this;
	}

	ByteStorage &ByteStorage::operator=(const ByteStorage &p_other)
	{
		if(m_data != p_other.m_data)
		{
			m_data->ref--;
			if(!m_data->ref)
				free(m_data);
			m_data = p_other.m_data;
			m_data->ref++;
		}
		return *this;
	}

    bool ByteStorage::operator==(const ByteStorage &p_other) const
    {
        if(m_data == p_other.m_data)
            return true;

        if(m_data->size != p_other.m_data->size)
            return false;

        return (memcmp(m_data->data, p_other.m_data->data, m_data->size) == 0);
    }
}
