#include "cCard.h"

void cCard::dump()
{

}

bool cCard::operator==(const cCard& _cCard)
{
	if (this->m_eCardName == _cCard.m_eCardName && this->m_eCardSuit == _cCard.m_eCardSuit && this->m_iCardNumber == _cCard.m_iCardNumber)
	{
		return true;
	}
	return false;
}

cCard::cCard(ePlayingCard _eCardName, eCardSuit _eCardSuit, int _iCardNumber)
	:m_eCardName	{ _eCardName },
	 m_eCardSuit	{ _eCardSuit },
	 m_iCardNumber	{ _iCardNumber }
{

}
