////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin & JS Lemaire
/// \file		Objet_celestre.h
/// \date		16/03/17
/// \brief		Definition de la classe objet celestre
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Donnee.h"

#ifndef _OBJET_CELESTRE_H_
#define _OBJET_CELESTRE_H_

using namespace std;

class Objet_celestre
{

public:

	enum AscensionDroite{ HEURE, MINUTE, NB_DONNES };

    ///
	/// \brief	accessor de ascensionDroite_
	/// \return	Donnee	l'ascension droite
	///
    Donnee obtenirAscensionDroite() const;

    ///
	/// \brief	accessor de declinaison_
	/// \return	Donnee	la declinaison
	///
	Donnee obtenirDeclinaison() const;

	///
	/// \brief	accessor de declinaison_
	/// \return	Donnee	la declinaison
	///
	Donnee obtenirDeclinaison() const;

	///
	/// \brief	accessor de declinaison_
	/// \return	Donnee	la declinaison
	///
	Donnee obtenirDeclinaison() const;

private:
	Donnee ascensionDroite_[NB_DONNES];
	Donnee declinaison_;
	Donnee distance_;
	Donnee magnitudeApparente_;
	string nom_;
    string type_;
	string constellation_;
};

#endif // _OBJET_CELESTRE_H_
