#include "XfireKit.h"

namespace XfireKit
{
	class Moniker
	{
		Moniker();
		Moniker(const uint8 *p_data);
		Moniker(const Moniker &p_other);
		~Moniker();
		
		Moniker &operator=(const Moniker &p_other);
		bool operator==(const Moniker &p_other);
		
		bool isValid();
		
		uint8 *m_data;
	};
}