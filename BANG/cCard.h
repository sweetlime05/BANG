#pragma once

#include "enumCards.h"

class cCard
{
public:
	ePlayingCard	m_eCardName;
	eCardSuit		m_eCardSuit;
	int				m_iCardNumber;

public:
	void dump();
	bool operator==(const cCard& _cCard);

public:
	cCard(ePlayingCard _eCardName, eCardSuit _eCardSuit, int _iCardNumber);
};

