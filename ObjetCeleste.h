///////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ObjetCeleste.h
/// \date		31/03/17
/// \brief		Cette classe permet de cree un objet celeste.
///////////////////////////////////////////////////////////////////////////////

#include "Donnee.h"
#include "utilitaire.h"

#ifndef _OBJET_CELESTE_H_
#define _OBJET_CELESTE_H_

using namespace std;

class ObjetCeleste
{

public:

    ///
	///\brief  Constructeur par parametres.
	///\param  nom					Le nom de l'objet.
	///\param  constellation		Le nom de la constellation repere.
	///\param  ascensionDroite		Les coordonnees de l'ascension droite.
	///\param  declinaison			Les coordonnees de la declinaison.
	///
	ObjetCeleste(const string& nom = "Objet sans nom", 
				 const string& constellation = "BTW",
				 const DonneeDouble& ascensionDroite = { Donnee(), Donnee() },
				 const DonneeDouble& declinaison = { Donnee(), Donnee() } );

private:

	string nom_;
	string constellation_;
    DonneeDouble ascensionDroite_;
	DonneeDouble declinaison_;

};

#endif // _OBJET_CELESTE_H_
