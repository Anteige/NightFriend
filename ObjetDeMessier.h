///////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ObjetDeMessier.h
/// \date		16/03/17
/// \brief		Cette classe permet de cree un objet de Messier.
///////////////////////////////////////////////////////////////////////////////

#include "Donnee.h"
#include "utilitaire.h"

#ifndef _OBJET_DE_MESSIER_H_
#define _OBJET_DE_MESSIER_H_

using namespace std;

class ObjetDeMessier
{

public:

    ///
	///\brief  Constructeur de la classe.
	///\param  id					L'id de l'objet de Messier.
	///\param  constellation		Le nom de la constellation repere.
	///\param  type					Le type de l'objet Messier.
	///\param  ascensionDroite		Les coordonnees de l'ascension droite.
	///\param  declinaison			Les coordonnees de la declinaison.
	///\param  magnitudeApparente	La magnitude apparente de l'objet.
	///\param  distance				La distance de l'objet.
	///\param  diametreApparent		Le diametre apparent de l'objet.
	///
	ObjetDeMessier( int id = 000,
					string constellation = "CON",
					string type_ = "0",
					DonneeDouble ascensionDroite = { Donnee(), Donnee() },
					DonneeDouble declinaison = { Donnee(), Donnee() },
					Donnee magnitudeApparente = Donnee(),
					Donnee distance = Donnee(),
					Donnee diametreApparent = Donnee()
				  );

	///
	///\brief  Accessor de id_.
	///\return L'id de l'objet de Messier.
	///
	int obtenirId() const;

private:

	int	id_;
	string constellation_;
	string type_;
    DonneeDouble ascensionDroite_;
	DonneeDouble declinaison_;
	Donnee magnitudeApparente_;
	Donnee distance_;
	Donnee diametreApparent_;

};

#endif // _OBJET_DE_MESSIER_H_
