#include <iostream>
#include <stdlib.h>

#include <windows.h>

#include "cBangCore.h"
#include "Utility.h"

#define NUMBEROFPLAYERS 7

int finishTurn(cBangCore* _Game, int _iTurn)
{
	std::cout << "��" << _iTurn << " ����: " << getCharacterName(_Game->m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << std::endl;

	std::cout << std::endl;
	dataDump(_Game);

	system("pause");
	std::cout << std::endl;

	return _Game->getNextTurn(_iTurn);
}

int main()
{
	system("mode con cols=200 lines=50");

	// Setup
	cBangCore Game(NUMBEROFPLAYERS, NULL);
	Game.init();

	Game.m_stlvpPlayerVector->at(0).m_iLife = 1;
	Game.m_stlvpPlayerVector->at(1).m_iLife = 1;
	Game.m_stlvpPlayerVector->at(2).m_iLife = 1;
	Game.m_stlvpPlayerVector->at(3).m_iLife = 1;
	Game.m_stlvpPlayerVector->at(4).m_iLife = 1;
	Game.m_stlvpPlayerVector->at(5).m_iLife = 1;
	Game.m_stlvpPlayerVector->at(6).m_iLife = 1;

	Game.m_stlvpPlayerVector->at(0).m_chDynamite = 1;

	dataDump(&Game);

	int iTurn = 0;

	while (Game.m_iGameOver == 0)
	{
		std::cout << "��" << iTurn << " ����: " << getCharacterName(Game.m_stlvpPlayerVector->at(iTurn).m_eCharacter) << std::endl;

		std::cout << getCharacterName(Game.m_stlvpPlayerVector->at(iTurn).m_eCharacter) << ": ������ 0" << std::endl;
		if (Game.executePhase_0(iTurn))
		{
			// ���� �ɸ� or ���
			iTurn = finishTurn(&Game, iTurn);
			continue;
		}

		std::cout << getCharacterName(Game.m_stlvpPlayerVector->at(iTurn).m_eCharacter) << ": ������ 1" << std::endl;
		if (Game.executePhase_1(iTurn))
		{
			iTurn = finishTurn(&Game, iTurn);
			continue;
		}

		iTurn = finishTurn(&Game, iTurn);
	}

	return 0;
}

