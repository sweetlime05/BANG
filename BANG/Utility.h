#pragma once
#include "enumCards.h"
#include "cBangCore.h"
#include <iostream>

const char* getCharacterName(eCharacter _eCharacter);
const char* getCardName(ePlayingCard _ePlayingCard);
const char* getSuit(eCardSuit _eCardSuit);
const char* getRole(eRole _eRole);

void dataDump(cBangCore* _Game);