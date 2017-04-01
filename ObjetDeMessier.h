///////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ObjetDeMessier.h
/// \date		16/03/17
/// \brief		Cette classe permet de cree un objet de Messier.
///////////////////////////////////////////////////////////////////////////////

#include "ObjetCeleste.h"

#ifndef _OBJET_DE_MESSIER_H_
#define _OBJET_DE_MESSIER_H_

using namespace std;

class ObjetDeMessier : ObjetCeleste
{

public:

    ///
	///\brief  Constructeur de la classe.
	///\param  id					L'id de l'objet de Messier.
	///\param  nom					Le nom de l'objet en NGC.
	///\param  constellation		Le nom de la constellation repere.
	///\param  type					Le type de l'objet Messier.
	///\param  ascensionDroite		Les coordonnees de l'ascension droite.
	///\param  declinaison			Les coordonnees de la declinaison.
	///\param  magnitudeApparente	La magnitude apparente de l'objet.
	///\param  distance				La distance de l'objet.
	///\param  diametreApparent		Le diametre apparent de l'objet.
	///
	ObjetDeMessier(const string& nom,
				   const string& constellation,
				   const DonneeDouble& ascensionDroite,
				   const DonneeDouble& declinaison,
				   int id = 000,
				   const string& type = "0",
				   const Donnee& magnitudeApparente = Donnee(),
				   const Donnee& distance = Donnee(),
				   const Donnee& diametreApparent = Donnee());

	///
	///\brief  Accessor de id_.
	///\return L'id de l'objet de Messier.
	///
	int obtenirId() const;

private:

	int	id_;
	string type_;
	Donnee magnitudeApparente_;
	Donnee distance_;
	Donnee diametreApparent_;

};

#endif // _OBJET_DE_MESSIER_H_
