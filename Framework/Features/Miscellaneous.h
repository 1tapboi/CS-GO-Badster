#pragma once

class CMiscellaneous
{
public:
	void GameResources();
	void Initialize();
	void Run();
	void Think();
	void Bunnyhop();
	void LegitStrafe();
	void RageStrafe();
	void Run_LocationSpam();
	void NameSteal();
	void ChangeName( const char* name );
	void ChangeCName();
	void Chatspam();
	void AirStuck();
	void LagExploit();
	void Panic();
private:
	

private:
	bool m_bInitialized = false;
	std::vector<std::string> m_spamlines;
	std::vector<std::string> m_insults;

};