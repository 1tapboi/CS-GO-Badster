#pragma once

class CLegitBot
{
public:
	void Run();
	bool EntityIsValid( int i );

	int chockedtickz = 0;


private:
	void GoToTarget();
	void FindTarget();
	void DropTarget();
	void Nearest();
	void CheckF();
	void Triggerbot();
	void AutoPistol();
};

