#ifndef XK_HEADER_MONIKER
#define XK_HEADER_MONIKER

#include <ByteStorage.h>

namespace XfireKit
{
	class Moniker
	{
    public:
		Moniker();
        Moniker(const ByteStorage &p_data);
		Moniker(const Moniker &p_other);
		
		Moniker &operator=(const Moniker &p_other);
		bool operator==(const Moniker &p_other);
		
		bool isValid();

    private:
        ByteStorage m_data;
	};
}

#endif // XK_HEADER_MONIKER
