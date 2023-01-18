#include "Utility.h"

const char* getCharacterName(eCharacter _eCharacter)
{
	switch (_eCharacter)
	{
	case eCharacter::WILLY_THE_KID:
		return "WILLY_THE_KID";
	case eCharacter::CALAMITY_JANET:
		return "CALAMITY_JANET";
	case eCharacter::KIT_CARLSON:
		return "KIT_CARLSON";
	case eCharacter::BART_CASSIDY:
		return "BART_CASSIDY";
	case eCharacter::SID_KETCHUM:
		return "SID_KETCHUM";
	case eCharacter::LUCKY_DUKE:
		return "LUCKY_DUKE";
	case eCharacter::JOURDONNAIS:
		return "JOURDONNAIS";
	case eCharacter::BLACK_JACK:
		return "BLACK_JACK";
	case eCharacter::VULTURE_SAM:
		return "VULTURE_SAM";
	case eCharacter::JESSE_JONES:
		return "JESSE_JONES";
	case eCharacter::SUZY_LAFAYETTE:
		return "SUZY_LAFAYETTE";
	case eCharacter::PEDRO_RAMIREZ:
		return "PEDRO_RAMIREZ";
	case eCharacter::SLAB_THE_KILLER:
		return "SLAB_THE_KILLER";
	case eCharacter::ROSE_DOOLAN:
		return "ROSE_DOOLAN";
	case eCharacter::PAUL_REGRET:
		return "PAUL_REGRET";
	case eCharacter::EL_GRINGO:
		return "EL_GRINGO";
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
	default:
		return "Name Not Found";
	}
}

const char* getSuit(eCardSuit _eCardSuit)
{
	switch (_eCardSuit)
	{
	case eCardSuit::CLUB:
		return "♣";
	case eCardSuit::DIAMOND:
		return "♦";
	case eCardSuit::HEART:
		return "♥";
	case eCardSuit::SPADE:
		return "♠";
	default:
		return "Suit Not Found";
	}
}
