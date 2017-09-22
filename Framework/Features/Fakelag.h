#pragma once

class CFakeLag
{
public:
	void Run();
private:
	int ticks = 0;
	int ticksMax = 16;
};