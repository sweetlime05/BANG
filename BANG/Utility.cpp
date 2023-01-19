#include "Utility.h"

const char* getCharacterName(eCharacter _eCharacter)
{
	switch (_eCharacter)
	{
	case eCharacter::WILLY_THE_KID:
		return "WILLY_THE_KID  ";
	case eCharacter::CALAMITY_JANET:
		return "CALAMITY_JANET ";
	case eCharacter::KIT_CARLSON:
		return "KIT_CARLSON    ";
	case eCharacter::BART_CASSIDY:
		return "BART_CASSIDY   ";
	case eCharacter::SID_KETCHUM:
		return "SID_KETCHUM    ";
	case eCharacter::LUCKY_DUKE:
		return "LUCKY_DUKE     ";
	case eCharacter::JOURDONNAIS:
		return "JOURDONNAIS    ";
	case eCharacter::BLACK_JACK:
		return "BLACK_JACK     ";
	case eCharacter::VULTURE_SAM:
		return "VULTURE_SAM    ";
	case eCharacter::JESSE_JONES:
		return "JESSE_JONES    ";
	case eCharacter::SUZY_LAFAYETTE:
		return "SUZY_LAFAYETTE ";
	case eCharacter::PEDRO_RAMIREZ:
		return "PEDRO_RAMIREZ  ";
	case eCharacter::SLAB_THE_KILLER:
		return "SLAB_THE_KILLER";
	case eCharacter::ROSE_DOOLAN:
		return "ROSE_DOOLAN    ";
	case eCharacter::PAUL_REGRET:
		return "PAUL_REGRET    ";
	case eCharacter::EL_GRINGO:
		return "EL_GRINGO      ";
	default:
		return "Name Not Found";
	}
}

const char* getCardName(ePlayingCard _ePlayingCard)
{
	switch (_ePlayingCard)
	{
	case ePlayingCard::BANG:
		return "BANG";
	case ePlayingCard::MISSED:
		return "MISSED";
	case ePlayingCard::BEER:
		return "BEER";
	case ePlayingCard::DUEL:
		return "DUEL";
	case ePlayingCard::INDIANS:
		return "INDIANS";
	case ePlayingCard::GATLING:
		return "GATLING";
	case ePlayingCard::SALOON:
		return "SALOON";
	case ePlayingCard::PANIC:
		return "PANIC";
	case ePlayingCard::CAT_BALOU:
		return "CAT_BALOU";
	case ePlayingCard::GENERAL_STORE:
		return "GENERAL_STORE";
	case ePlayingCard::STAGECOACH:
		return "STAGECOACH";
	case ePlayingCard::WELLS_FARGO:
		return "WELLS_FARGO";
	case ePlayingCard::SCHOFIELD:
		return "SCHOFIELD";
	case ePlayingCard::REMINGTON:
		return "REMINGTON";
	case ePlayingCard::REV_CARABINE:
		return "REV_CARABINE";
	case ePlayingCard::WINCHESTER:
		return "WINCHESTER";
	case ePlayingCard::VOLCANIC:
		return "VOLCANIC";
	case ePlayingCard::SCOPE:
		return "SCOPE";
	case ePlayingCard::MUSTANG:
		return "MUSTANG";
	case ePlayingCard::BARREL:
		return "BARREL";
	case ePlayingCard::JAIL:
		return "JAIL";
	case ePlayingCard::DYNAMITE:
		return "DYNAMITE";
	case ePlayingCard::COLT45:
		return "COLT45";
	default:
		return "Name Not Found";
	}
}

const char* getSuit(eCardSuit _eCardSuit)
{
	switch (_eCardSuit)
	{
	case eCardSuit::CLUB:
		return "CLUB ";
	case eCardSuit::DIAMOND:
		return "DIAMOND ";
	case eCardSuit::HEART:
		return "HEART ";
	case eCardSuit::SPADE:
		return "SPADE ";
	default:
		return "Suit Not Found";
	}
}

const char* getRole(eRole _eRole)
{
	switch (_eRole)
	{
	case eRole::SHERIFF:
		return "SHERIFF ";
	case eRole::DEPUTY:
		return "DEPUTY  ";
	case eRole::OUTLAW:
		return "OUTLAW  ";
	case eRole::RENEGADE:
		return "RENEGADE";
	default:
		return "Role Not Found";
	}
}

void dataDump(cBangCore* _Game)
{
	for (int iDump = 0; iDump < _Game->m_iNumOfPlayers; ++iDump)
	{
		std::cout << "[";
		if (_Game->m_stlvOutTurn.size() > 0 && std::count(_Game->m_stlvOutTurn.begin(), _Game->m_stlvOutTurn.end(), iDump))
		{
			std::cout << "x";
		}
		else
		{
			std::cout << iDump;
		}
		std::cout << "]";
		std::cout << getCharacterName(_Game->m_stlvpPlayerVector->at(iDump).m_eCharacter) << "/" << getRole(_Game->m_stlvpPlayerVector->at(iDump).m_eRole) << ": Life:" << _Game->m_stlvpPlayerVector->at(iDump).m_iLife << " Gun:" << getCardName(_Game->m_stlvpPlayerVector->at(iDump).m_ePlayingCardInstallGUN) << " // ";
		std::cout << (_Game->m_stlvpPlayerVector->at(iDump).m_chDynamite ? (_Game->m_stlvpPlayerVector->at(iDump).m_chDynamite == 1 ? "NEXTDYNAMITE " : "DYNAMITE ") : "- ");
		std::cout << (_Game->m_stlvpPlayerVector->at(iDump).m_bJail ? "JAIL " : "- ");
		std::cout << (_Game->m_stlvpPlayerVector->at(iDump).m_bBarrel ? "BARREL " : "- ");
		std::cout << (_Game->m_stlvpPlayerVector->at(iDump).m_bMustang ? "MUSTANG " : "- ");
		std::cout << (_Game->m_stlvpPlayerVector->at(iDump).m_bScope ? "SCOPE " : "- ");
		std::cout << "// ";

		int iNumber = 0;
		for (int i = 0; i < 22; ++i)
		{
			int iSize = _Game->m_stlvpPlayerVector->at(iDump).m_stllePlayingCardUse.at(i).size();
			if (iSize)
			{
				for (int j = 0; j < iSize; ++j)
				{
					std::cout << getCardName(_Game->m_stlvpPlayerVector->at(iDump).m_stllePlayingCardUse.at(i).at(j).m_eCardName) << "(" << getSuit(_Game->m_stlvpPlayerVector->at(iDump).m_stllePlayingCardUse.at(i).at(j).m_eCardSuit) << _Game->m_stlvpPlayerVector->at(iDump).m_stllePlayingCardUse.at(i).at(j).m_iCardNumber << ")   ";
					++iNumber;
				}
			}
		}

		std::cout << ": " << iNumber;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	if (_Game->m_stlvpDrawPile->size())
	{
		std::cout << "DrawPile(" << _Game->m_stlvpDrawPile->size() << ") / Top: " << getCardName(_Game->m_stlvpDrawPile->back().m_eCardName) << "(" << getSuit(_Game->m_stlvpDrawPile->back().m_eCardSuit) << _Game->m_stlvpDrawPile->back().m_iCardNumber << ")" << std::endl;
	}
	else
	{
		std::cout << "DrawPile(0)" << std::endl;
	}

	if (_Game->m_stlvpDiscardPile->size())
	{
		std::cout << "DiscardPile(" << _Game->m_stlvpDiscardPile->size() << ") / Top: " << getCardName(_Game->m_stlvpDiscardPile->back().m_eCardName) << "(" << getSuit(_Game->m_stlvpDiscardPile->back().m_eCardSuit) << _Game->m_stlvpDiscardPile->back().m_iCardNumber << ")" << std::endl;
	}
	else
	{
		std::cout << "DiscardPile(0)" << std::endl;
	}

	std::cout << std::endl;
}