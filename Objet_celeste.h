////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		Objet_celeste.h
/// \date		16/03/17
/// \brief		Definition de la classe objet celeste
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Donnee.h"

#ifndef _OBJET_CELESTE_H_
#define _OBJET_CELESTE_H_

using namespace std;

class Objet_celeste
{

public:

	enum AscensionDroite{ HEURE, MINUTE, NB_DONNES };

	///
	/// 
	///
	Objet_celeste();

private:
	Donnee ascensionDroite_[NB_DONNES];
	Donnee declinaison_;
	Donnee distance_;
	Donnee magnitudeApparente_;
	string nom_;
};

#endif // _OBJET_CELESTE_H_