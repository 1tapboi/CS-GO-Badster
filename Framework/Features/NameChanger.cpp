#include "../Cheat.h"

CNameChanger* NameChanger;

void CNameChanger::BeginFrame()
{
	static bool flip = false;

	if (!Vars.Misc.NameChangerenabled)
		return;

	if (!I::Engine->IsInGame())
		return;

	if (changes >= 5)
	{
		changes = -1;
		flip = false;
		Vars.Misc.NameChangerenabled = false;
		return;
	}

	long currentTime_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	static long timeStamp = currentTime_ms;

	if (currentTime_ms - timeStamp < 100)
		return;

	timeStamp = currentTime_ms;

	changes++;
	
	if (changes < 5)
	{
		std::string ctWithEscapesProcessed1 = std::string(nickname);
		std::string ctWithEscapesProcessed2 = std::string(separator);

		U::StdReplaceStr(ctWithEscapesProcessed1, "\\n", "\n");
		U::StdReplaceStr(ctWithEscapesProcessed2, "\\n", "\n");

		char buf[128];

		if (Vars.Misc.NameChangerseparator_animation == 0)
		{
			if (!flip)
			{
				sprintf(buf, "%s%s", ctWithEscapesProcessed2.c_str(), ctWithEscapesProcessed1.c_str());
			}
			else
			{
				sprintf(buf, "%s", ctWithEscapesProcessed1.c_str());
			}
		}
		else if (Vars.Misc.NameChangerseparator_animation == 1)
		{
			if (!flip)
			{
				sprintf(buf, "%s%s", ctWithEscapesProcessed1.c_str(), ctWithEscapesProcessed2.c_str());
			}
			else
			{
				sprintf(buf, "%s", ctWithEscapesProcessed1.c_str());
			}
		}
		else
		{
			if (!flip)
			{
				sprintf(buf, "%s%s", ctWithEscapesProcessed1.c_str(), ctWithEscapesProcessed2.c_str());
			}
			else
			{
				sprintf(buf, "%s%s", ctWithEscapesProcessed2.c_str(), ctWithEscapesProcessed1.c_str());
			}
		}

		E::Misc->ChangeName( buf );
		flip = !flip;
	}
}
