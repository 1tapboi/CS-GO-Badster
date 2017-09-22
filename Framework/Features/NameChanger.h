#pragma once

class CNameChanger
{
public:
	void BeginFrame();
	
	char* nickname;
	char* separator;
	
private:
	int changes = -1;
};