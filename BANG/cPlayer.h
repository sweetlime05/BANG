#pragma once
#include <list>
#include <vector>

#include "enumCards.h"
#include "cCard.h"

class cPlayer
{
public:
	eRole							m_eRole;
	eCharacter						m_eCharacter;

	std::vector<std::vector<cCard>>	m_stllePlayingCardUse;

	ePlayingCard					m_ePlayingCardInstallGUN;

	int								m_iLife;
	int								m_iRange;

	bool							m_bScope;
	bool							m_bMustang;
	bool							m_bBarrel;
	bool							m_bJail;
	char							m_chDynamite;

public:
	void dump();
public:
	cPlayer(eRole _eRole, eCharacter _eCharacter);
};

