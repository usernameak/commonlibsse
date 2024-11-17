#include "RE/B/BSXAudio2GameSound.h"

namespace RE
{
	BSXAudio2Audio* BSXAudio2GameSound::GetAudioImplementation()
	{
		static REL::Relocation<BSXAudio2Audio**> audioImplementation{ RELOCATION_ID(523613, 410149) };
		return *audioImplementation;
	}

	void BSXAudio2GameSound::SetAudioImplementation(BSXAudio2Audio* a_impl)
	{
		static REL::Relocation<BSXAudio2Audio**> audioImplementation{ RELOCATION_ID(523613, 410149) };
		*audioImplementation = a_impl;
	}
}
