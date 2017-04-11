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
	///\brief  Constructeur par default.
	///
	ObjetCeleste();

    ///
	///\brief  Constructeur par parametres.
	///\param  nom					Le nom de l'objet.
	///\param  constellation		Le nom de la constellation repere.
	///\param  ascensionDroite		Les coordonnees de l'ascension droite.
	///\param  declinaison			Les coordonnees de la declinaison.
	///
	ObjetCeleste(const string& nom, const string& constellation, 
									const DonneeDouble& ascensionDroite,
									const DonneeDouble& declinaison);

	///
	///\brief  Mutator de nom_.
	///\return string	le nom de l'objet celeste.
	///
	string obtenirNom() const;

	///
	///\brief  Mutator de constellation_.
	///\return string	la constellation de l'objet celeste.
	///
	string obtenirConstellation() const;

	///
	///\brief  Mutator de AscensionDroite_.
	///\return string	l'ascension droite de l'objet celeste.
	///
	DonneeDouble obtenirAscensionDroite() const;

	///
	///\brief  Mutator de Declinaison_.
	///\return string	la declinaison de l'objet celeste.
	///
	DonneeDouble obtenirDeclinaison() const;

private:

	string nom_;
	string constellation_;
    DonneeDouble ascensionDroite_;
	DonneeDouble declinaison_;

};

#endif // _OBJET_CELESTE_H_
