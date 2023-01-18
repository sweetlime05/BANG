#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdarg>

#include "enumCards.h"
#include "cPlayer.h"
#include "cCard.h"

class cBangCore
{
public:
	int m_iNumOfPlayers;
	std::vector<cPlayer>* m_stlvpPlayerVector;
	std::vector<cCard>* m_stlvpDrawPile;
	std::vector<cCard>* m_stlvpDiscardPile;

public:
	void					init();
	int						getNextTurn(int _iTurn);

	template <typename _Ty>
	void					addPlayer(std::vector<cPlayer>* _stlvpPlayerVector, std::vector<eCharacter>* _stlvepCharacter, int _count, _Ty ...);

	std::vector<cPlayer>*	makePlayerVector(int _iMode);

	void					addCard(std::vector<cCard>* _stlvpDrawPile, ePlayingCard _ePlayingCard, eCardSuit _eCardSuit, int _iStart, int _iFinish);

	std::vector<cCard>*		makeDrawPile();

	bool					executePhaseZero(int _iTurn);
	cCard					checkCard();
	inline void				cancelCheckCard(cCard _cCard);
	inline void				discardCard(cCard _cCard);

	std::vector<cCard>		chooseCardFromHand(int _iTurn, ePlayingCard _ePlayingCard, int _iNumber);
	void					deleteCardFromHand(int _iTurn, ePlayingCard _ePlayingCard, std::vector<cCard> _stlvValue);

	void					Damage(int _iPlayer, int _iValue);

	void					checkDynamite(int _iTurn);

	bool					checkJail(int _iTurn);

	void					drawCard(int _iTurn);

public:
	cBangCore(int _iNumOfPlayers, int _iMode);
	~cBangCore();
};

