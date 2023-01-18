#include <iostream>

#include "cBangCore.h"
#include "Utility.h"

#define NUMBEROFPLAYERS 7



int main()
{
	// Setup
	cBangCore Game(NUMBEROFPLAYERS, NULL);
	Game.init();

	int iTurn = 0;

	while (iTurn >= 0)
	{
		std::cout << "턴 시작: " << getCharacterName(Game.m_stlvpPlayerVector->at(iTurn).m_eCharacter) << std::endl;
		std::cout << getCharacterName(Game.m_stlvpPlayerVector->at(iTurn).m_eCharacter) << ": 페이즈 0" << std::endl;
		if (Game.executePhaseZero(iTurn))
		{
			continue;
		}

 		++iTurn;
		if (iTurn >= NUMBEROFPLAYERS)
		{
			iTurn = 0;
		}
	}

	return 0;
}

