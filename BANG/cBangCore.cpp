#include "cBangCore.h"
#include "Utility.h"

void cBangCore::init()
{
	for (int i = 0; i < this->m_iNumOfPlayers; ++i)
	{
		for (int j = 0; j < this->m_stlvpPlayerVector->at(i).m_iLife; ++j)
		{
			drawCard(i);
		}
	}
}

template <typename _Ty>
void cBangCore::addPlayer(std::vector<cPlayer>* _stlvpPlayerVector, std::vector<eCharacter>* _stlvepCharacter, int _count, _Ty ...)
{
	va_list list;
	va_list copy;

	va_start(list, _count);
	va_copy(copy, list);

	for (int i = 0; i != _count; ++i)
	{
		_stlvpPlayerVector->push_back(cPlayer(va_arg(copy, _Ty), _stlvepCharacter->at(i)));
	}

	va_end(list);
	va_end(copy);
}

int cBangCore::getNextTurn(int _iTurn)
{
	int iTurn = _iTurn;
	do 
	{
		++iTurn;
		if (iTurn >= this->m_iNumOfPlayers)
		{
			iTurn = 0;
		}
	} while (this->m_stlvOutTurn.size() > 0 && std::count(this->m_stlvOutTurn.begin(), this->m_stlvOutTurn.end(), iTurn));
	return iTurn;
}

std::vector<cPlayer>* cBangCore::makePlayerVector(int _iMode)
{
	std::vector<cPlayer>* stlvpPlayers = new std::vector<cPlayer>;

	std::vector<eCharacter> stlveCharacter = {
												eCharacter::WILLY_THE_KID,
												eCharacter::CALAMITY_JANET,
												eCharacter::KIT_CARLSON,
												eCharacter::BART_CASSIDY,
												eCharacter::SID_KETCHUM,
												eCharacter::LUCKY_DUKE,
												eCharacter::JOURDONNAIS,
												eCharacter::BLACK_JACK,
												eCharacter::VULTURE_SAM,
												eCharacter::JESSE_JONES,
												eCharacter::SUZY_LAFAYETTE,
												eCharacter::PEDRO_RAMIREZ,
												eCharacter::SLAB_THE_KILLER,
												eCharacter::ROSE_DOOLAN,
												eCharacter::PAUL_REGRET,
												eCharacter::EL_GRINGO
	};

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(stlveCharacter.begin(), stlveCharacter.end(), std::default_random_engine((unsigned int)seed));

	switch (this->m_iNumOfPlayers)
	{
	case 3:
		addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::DEPUTY, eRole::RENEGADE, eRole::OUTLAW);
		break;
	case 4:
		switch (_iMode)
		{
		case 1:
			addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::SHERIFF, eRole::OUTLAW, eRole::OUTLAW, eRole::RENEGADE);
			break;
		case 2:
			addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::SHERIFF, eRole::OUTLAW, eRole::DEPUTY, eRole::RENEGADE);
			break;
		case 3:
			addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::SHERIFF, eRole::OUTLAW, eRole::OUTLAW, eRole::DEPUTY);
			break;
		}
	case 5:
		addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::SHERIFF, eRole::DEPUTY, eRole::OUTLAW, eRole::OUTLAW, eRole::RENEGADE);
		break;
	case 6:
		switch (_iMode)
		{
		case 1:
			addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::SHERIFF, eRole::DEPUTY, eRole::OUTLAW, eRole::OUTLAW, eRole::OUTLAW, eRole::RENEGADE);
			break;
		case 2:
			addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::SHERIFF, eRole::DEPUTY, eRole::DEPUTY, eRole::OUTLAW, eRole::OUTLAW, eRole::OUTLAW);
			break;
		case 3:
			addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::SHERIFF, eRole::DEPUTY, eRole::DEPUTY, eRole::OUTLAW, eRole::OUTLAW, eRole::RENEGADE);
			break;
		}
	case 7:
		addPlayer(stlvpPlayers, &stlveCharacter, this->m_iNumOfPlayers, eRole::SHERIFF, eRole::DEPUTY, eRole::DEPUTY, eRole::OUTLAW, eRole::OUTLAW, eRole::OUTLAW, eRole::RENEGADE);
		break;
	}

	for (int i = 0; i < this->m_iNumOfPlayers; ++i)
	{
		if (int((*stlvpPlayers)[i].m_eCharacter) <= 13)
		{
			(*stlvpPlayers)[i].m_iLife = 4;
		}
		else
		{
			(*stlvpPlayers)[i].m_iLife = 3;
		}
	}
	++((*stlvpPlayers)[0].m_iLife);

	return stlvpPlayers;
}

void cBangCore::addCard(std::vector<cCard>* _stlvpDrawPile, ePlayingCard _ePlayingCard, eCardSuit _eCardSuit, int _iStart, int _iFinish)
{
	for (int i = _iStart; i < _iFinish + 1; ++i)
	{
		_stlvpDrawPile->push_back(cCard(_ePlayingCard, _eCardSuit, i));
	}
}

std::vector<cCard>* cBangCore::makeDrawPile()
{
	std::vector<cCard>* stlvpDrawPile = new std::vector<cCard>;

	//J:11 Q:12 K:13 A:14
	addCard(stlvpDrawPile, ePlayingCard::BANG, eCardSuit::HEART, 12, 14);
	addCard(stlvpDrawPile, ePlayingCard::BANG, eCardSuit::DIAMOND, 2, 14);
	addCard(stlvpDrawPile, ePlayingCard::BANG, eCardSuit::CLUB, 2, 9);
	addCard(stlvpDrawPile, ePlayingCard::BANG, eCardSuit::SPADE, 14, 14);

	addCard(stlvpDrawPile, ePlayingCard::MISSED, eCardSuit::SPADE, 2, 8);
	addCard(stlvpDrawPile, ePlayingCard::MISSED, eCardSuit::CLUB, 10, 14);

	addCard(stlvpDrawPile, ePlayingCard::BEER, eCardSuit::HEART, 6, 11);

	addCard(stlvpDrawPile, ePlayingCard::DUEL, eCardSuit::DIAMOND, 12, 12);
	addCard(stlvpDrawPile, ePlayingCard::DUEL, eCardSuit::CLUB, 8, 8);
	addCard(stlvpDrawPile, ePlayingCard::DUEL, eCardSuit::SPADE, 11, 11);

	addCard(stlvpDrawPile, ePlayingCard::INDIANS, eCardSuit::DIAMOND, 13, 14);

	addCard(stlvpDrawPile, ePlayingCard::GATLING, eCardSuit::HEART, 10, 10);

	addCard(stlvpDrawPile, ePlayingCard::SALOON, eCardSuit::HEART, 5, 5);

	addCard(stlvpDrawPile, ePlayingCard::PANIC, eCardSuit::DIAMOND, 8, 8);
	addCard(stlvpDrawPile, ePlayingCard::PANIC, eCardSuit::HEART, 11, 12);
	addCard(stlvpDrawPile, ePlayingCard::PANIC, eCardSuit::HEART, 14, 14);

	addCard(stlvpDrawPile, ePlayingCard::CAT_BALOU, eCardSuit::DIAMOND, 9, 11);
	addCard(stlvpDrawPile, ePlayingCard::CAT_BALOU, eCardSuit::HEART, 13, 13);

	addCard(stlvpDrawPile, ePlayingCard::GENERAL_STORE, eCardSuit::CLUB, 9, 9);
	addCard(stlvpDrawPile, ePlayingCard::GENERAL_STORE, eCardSuit::SPADE, 12, 12);

	addCard(stlvpDrawPile, ePlayingCard::STAGECOACH, eCardSuit::SPADE, 9, 9);
	addCard(stlvpDrawPile, ePlayingCard::STAGECOACH, eCardSuit::SPADE, 9, 9);

	addCard(stlvpDrawPile, ePlayingCard::WELLS_FARGO, eCardSuit::HEART, 3, 3);

	addCard(stlvpDrawPile, ePlayingCard::SCHOFIELD, eCardSuit::CLUB, 11, 11);
	addCard(stlvpDrawPile, ePlayingCard::SCHOFIELD, eCardSuit::CLUB, 12, 12);
	addCard(stlvpDrawPile, ePlayingCard::SCHOFIELD, eCardSuit::SPADE, 13, 13);

	addCard(stlvpDrawPile, ePlayingCard::REMINGTON, eCardSuit::CLUB, 13, 13);

	addCard(stlvpDrawPile, ePlayingCard::REV_CARABINE, eCardSuit::CLUB, 14, 14);

	addCard(stlvpDrawPile, ePlayingCard::WINCHESTER, eCardSuit::SPADE, 8, 8);

	addCard(stlvpDrawPile, ePlayingCard::VOLCANIC, eCardSuit::CLUB, 10, 10);
	addCard(stlvpDrawPile, ePlayingCard::VOLCANIC, eCardSuit::SPADE, 10, 10);

	addCard(stlvpDrawPile, ePlayingCard::SCOPE, eCardSuit::SPADE, 14, 14);

	addCard(stlvpDrawPile, ePlayingCard::MUSTANG, eCardSuit::HEART, 8, 8);
	addCard(stlvpDrawPile, ePlayingCard::MUSTANG, eCardSuit::HEART, 9, 9);

	addCard(stlvpDrawPile, ePlayingCard::BARREL, eCardSuit::SPADE, 12, 12);
	addCard(stlvpDrawPile, ePlayingCard::BARREL, eCardSuit::SPADE, 13, 13);

	addCard(stlvpDrawPile, ePlayingCard::JAIL, eCardSuit::HEART, 4, 4);
	addCard(stlvpDrawPile, ePlayingCard::JAIL, eCardSuit::SPADE, 10, 11);

	addCard(stlvpDrawPile, ePlayingCard::DYNAMITE, eCardSuit::HEART, 2, 2);

	//std::cout << stlvpCardStack->size();

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(stlvpDrawPile->begin(), stlvpDrawPile->end(), std::default_random_engine((unsigned int)seed));

	return stlvpDrawPile;
}

bool cBangCore::executePhase_0(int _iTurn)
{
	if (checkDynamite(_iTurn))
	{
		return true;
	}

	if (checkJail(_iTurn))
	{
		return true;
	}
	return false;
}

cCard cBangCore::checkCard()
{
	cCard tmpCard = this->m_stlvpDrawPile->back();
	this->m_stlvpDrawPile->pop_back();
	return tmpCard;
}

inline void cBangCore::cancelCheckCard(cCard _cCard)
{
	this->m_stlvpDrawPile->push_back(_cCard);
}


inline void cBangCore::discardCard(cCard _cCard)
{
	this->m_stlvpDiscardPile->push_back(_cCard);
}

std::vector<cCard> cBangCore::chooseCardFromHand(int _iTurn, ePlayingCard _ePlayingCard, int _iNumber)
{
	std::vector<cCard> tempVector = {};
	std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(chooseCardFromHand)ī�� " << _iNumber << " ���� �����ϼ���" << std::endl;
	if (this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).size() == 0)
	{
		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(chooseCardFromHand)" << getCardName(_ePlayingCard) << " ī�尡 �����ϴ�" << std::endl;
		return tempVector;
	}
	else
	{
		for (auto cardIter = this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).begin(); cardIter != this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).end(); ++cardIter)
		{
			std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(chooseCardFromHand) " << getCardName(cardIter->m_eCardName) << "(" << getSuit(cardIter->m_eCardSuit) << cardIter->m_iCardNumber << ") ";
		}

		int iSeq = 1;
		int iInput;
		while (iSeq < _iNumber)
		{
			std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(chooseCardFromHand)" << iSeq << "��° ī�� ����: ";
			std::cin >> iInput;
			cCard ctempCard(_ePlayingCard, this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).at(iInput).m_eCardSuit, this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).at(iInput).m_iCardNumber);
			if (std::count(tempVector.begin(), tempVector.end(), ctempCard))
			{
				std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(chooseCardFromHand)�̹� �����߽��ϴ�" << std::endl;
				continue;
			}
			else
			{
				tempVector.push_back(ctempCard);
				++iSeq;
			}
		}

		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << std::endl << "(chooseCardFromHand)���� �Ϸ�";
	}
}

void cBangCore::deleteCardFromHand(int _iTurn, ePlayingCard _ePlayingCard, std::vector<cCard> _stlvValue)
{
	for (int i = 0; i < _stlvValue.size(); ++i)
	{
		this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).erase(std::remove_if(this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).begin(), this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).end(), [&](cCard _cCArd) {return (_stlvValue.at(i).m_eCardSuit == _cCArd.m_eCardSuit) && (_stlvValue.at(i).m_iCardNumber == _cCArd.m_iCardNumber); }), this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse.at((int)_ePlayingCard).end());
		this->m_stlvpDiscardPile->push_back(_stlvValue.at(i));
	}
}

bool cBangCore::Damage(int _iPlayer, int _iValue)
{
	if (this->m_stlvpPlayerVector->at(_iPlayer).m_iLife <= _iValue)
	{
		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iPlayer).m_eCharacter) << "(Damage)����º��� ���� ���� " << _iValue << "��(��) �Ծ����ϴ�" << std::endl;
		if (_iValue - this->m_stlvpPlayerVector->at(_iPlayer).m_iLife < this->m_stlvpPlayerVector->at(_iPlayer).m_stllePlayingCardUse[(int)ePlayingCard::BEER].size())
		{
			std::cout << getCharacterName(m_stlvpPlayerVector->at(_iPlayer).m_eCharacter) << "(Damage)���ָ� ����Ͽ� ��Ƴ��� �� �ֽ��ϴ� ����Ͻðڽ��ϱ�? ��:1, �ƴϿ�:0" << std::endl;
			int iInput;
			std::cin >> iInput;
			if (iInput == 1)
			{
				std::cout << getCharacterName(m_stlvpPlayerVector->at(_iPlayer).m_eCharacter) << "(Damage)���� " << _iValue - this->m_stlvpPlayerVector->at(_iPlayer).m_iLife + 1 << "�� �����";
				deleteCardFromHand(_iPlayer, ePlayingCard::BEER, chooseCardFromHand(_iPlayer, ePlayingCard::BEER, _iValue - this->m_stlvpPlayerVector->at(_iPlayer).m_iLife + 1));
			}
			else
			{
				std::cout << getCharacterName(m_stlvpPlayerVector->at(_iPlayer).m_eCharacter) << "(Damage)���� ����� �ź��Ͽ����Ƿ� ����Ͽ����ϴ�" << std::endl;

				this->m_stlvOutTurn.push_back(_iPlayer);
				return true;
			}
		}
		else
		{
			std::cout << getCharacterName(m_stlvpPlayerVector->at(_iPlayer).m_eCharacter) << "(Damage)����Ͽ����ϴ�" << std::endl;
			this->m_stlvOutTurn.push_back(_iPlayer);
			return true;
		}
	}
	else
	{
		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iPlayer).m_eCharacter) << "(Damage)" << _iValue << "�� ���ظ� �Ծ����ϴ�" << std::endl;
		this->m_stlvpPlayerVector->at(_iPlayer).m_iLife -= _iValue;
	}

	if (this->m_stlvpPlayerVector->at(_iPlayer).m_eCharacter == eCharacter::BART_CASSIDY)
	{
		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iPlayer).m_eCharacter) << "(Damage)BART CASSIDY�� �ɷ��� �̿��� ī�带 �����ɴϴ�" << std::endl;
		for (int i = 0; i < _iValue; ++i)
		{
			drawCard(_iPlayer);
		}
	}
	return false;
}

bool cBangCore::checkDynamite(int _iTurn)
{
	if (1 == this->m_stlvpPlayerVector->at(_iTurn).m_chDynamite)
	{
		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkDynamite)���� �Ϻ��� ���̳ʸ���Ʈ�� ���۵˴ϴ�" << std::endl;
		this->m_stlvpPlayerVector->at(_iTurn).m_chDynamite = 2;
	}
	else if (2 == this->m_stlvpPlayerVector->at(_iTurn).m_chDynamite)
	{
		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkDynamite)���̳ʸ���Ʈ�� �����Ǿ����ϴ�. ī�带 Ȯ���մϴ�" << std::endl;
		cCard cTempCard(checkCard());
		discardCard(cTempCard);
		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkDynamite)" << getCardName(cTempCard.m_eCardName) << "(" << getSuit(cTempCard.m_eCardSuit) << cTempCard.m_iCardNumber << ") ����" << std::endl;
		if (cTempCard.m_eCardSuit == eCardSuit::SPADE && cTempCard.m_iCardNumber >= 2 && cTempCard.m_iCardNumber <= 9)
		{
			std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkDynamite)���̳ʸ���Ʈ�� �����߽��ϴ�" << std::endl;
			this->m_stlvpPlayerVector->at(_iTurn).m_chDynamite = 0;
			discardCard(cCard(ePlayingCard::DYNAMITE, eCardSuit::HEART, 2));
			if (Damage(_iTurn, 3))
			{
				return true;
			}
		}
		else
		{
			std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkDynamite)���̳ʸ���Ʈ�� �������� �ʾҽ��ϴ�. ���̳ʸ���Ʈ�� ���� ������� ���޵˴ϴ�" << std::endl;
			this->m_stlvpPlayerVector->at(_iTurn).m_chDynamite = 0;
			this->m_stlvpPlayerVector->at(getNextTurn(_iTurn)).m_chDynamite = 2;
		}
	}
	return false;
}

bool cBangCore::checkJail(int _iTurn)
{
	if (this->m_stlvpPlayerVector->at(_iTurn).m_bJail)
	{
		this->m_stlvpPlayerVector->at(_iTurn).m_bJail = false;

		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkJail)������ �����Ǿ����ϴ�. ī�带 Ȯ���մϴ�" << std::endl;
		discardCard(cCard(ePlayingCard::JAIL, eCardSuit::HEART, 4));

		cCard cTempCard(checkCard());

		std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkJail)" << getCardName(cTempCard.m_eCardName) << "(" << getSuit(cTempCard.m_eCardSuit) << cTempCard.m_iCardNumber << ") ����" << std::endl;

		discardCard(cTempCard);
		if (cTempCard.m_eCardSuit == eCardSuit::HEART)
		{
			std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkJail)��Ʈ ������ �̾����Ƿ� �������� Ż���մϴ�" << std::endl;
			return false;
		}
		else
		{
			std::cout << getCharacterName(m_stlvpPlayerVector->at(_iTurn).m_eCharacter) << "(checkJail)��Ʈ ������ ���� �������Ƿ� ���� �ѱ�ϴ�" << std::endl;
			return true;
		}
	}
	return false;
}

bool cBangCore::executePhase_1(int _iTurn)
{
	return false;
}

void cBangCore::drawCard(int _iTurn)
{
	cCard tmpCard = checkCard();
	(this->m_stlvpPlayerVector->at(_iTurn).m_stllePlayingCardUse)[(int)tmpCard.m_eCardName].push_back(tmpCard);
}


cBangCore::~cBangCore()
{
	delete m_stlvpPlayerVector;
	delete m_stlvpDrawPile;
	delete m_stlvpDiscardPile;
}

cBangCore::cBangCore(int _iNumOfPlayers, int _iMode)
	:
	m_iNumOfPlayers(_iNumOfPlayers),
	m_stlvOutTurn(),
	m_stlvpPlayerVector(),
	m_stlvpDrawPile(nullptr),
	m_stlvpDiscardPile(nullptr),
	m_iGameOver(0)
{
	m_stlvpPlayerVector = makePlayerVector(_iMode);
	m_stlvpDrawPile = makeDrawPile();
	m_stlvpDiscardPile = new std::vector<cCard>;
}