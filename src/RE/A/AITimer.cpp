#include "RE/A/AITimer.h"

namespace RE
{
	float AITimer::GetTimer()
	{
		using func_t = decltype(&AITimer::GetTimer);
		static REL::Relocation<func_t> func{ RELOCATION_ID(47089, 48253) };
		return func();
	}
}
