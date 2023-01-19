#include <iostream>
#include "cPlayer.h"

cPlayer::cPlayer(eRole _eRole, eCharacter _eCharacter)
	:
	m_eRole{_eRole},
	m_eCharacter{_eCharacter},
	m_stllePlayingCardUse{22},
	m_ePlayingCardInstallGUN{ePlayingCard::COLT45},
	m_iLife{0},
	m_iRange{1},
	m_bScope{false},
	m_bMustang{false},
	m_bBarrel{false},
	m_bJail{false},
	m_chDynamite{0}
{
}
