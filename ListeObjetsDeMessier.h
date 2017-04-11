////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ListeObjetsDeMessier.h
/// \date		30/03/2017
/// \brief		Cette classe permet de contenir des objets de Messier.
////////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_OBJETS_DE_MESSIER_INCLUDED
#define LISTE_OBJETS_DE_MESSIER_INCLUDED

#include <iostream>
#include <list>
#include "ObjetDeMessier.h"

using namespace std;

class ListeObjetsDeMessier
{

public:

	///
	///\brief Constructeur par default.
	///
	ListeObjetsDeMessier();

	///
	///\brief Destructeur.
	///
    ~ListeObjetsDeMessier();

	///
	///\brief  Insere un objet de Messier dans la liste.
	///\param  id					L'id de l'objet de Messier.
	///\param  constellation		Le nom de la constellation repere.
	///\param  type					Le type de l'objet Messier.
	///\param  ascensionDroite		Les coordonnees de l'ascension droite.
	///\param  declinaison			Les coordonnees de la declinaison.
	///\param  magnitudeApparente	La magnitude apparente de l'objet.
	///\param  distance				La distance de l'objet.
	///\param  diametreApparent		Le diametre apparent de l'objet.
	///
	void inserer(const string& nom,
				 const string& constellation,
				 const string& type,
				 const DonneeDouble& ascensionDroite,
				 const DonneeDouble& declinaison,
				 int id,
				 const Donnee& magnitudeApparente,
				 const Donnee& distance,
				 const Donnee& diametreApparent);

	///
	///\brief  Trouve un objet ayant l'id demande.
	///\param  id	L'id de l'objet a trouver.
	///\return Un pointeur vers l'objet, nullptr si l'objet n'existe pas.
	///
	ObjetDeMessier* trouver(int id) const;

	///
	///\brief  Permet d'obtenir les objets de Messier a partir d'un fichier.
	///
	void lireFichier();

	///
	///\brief Affiche tous les objets en ordre numerique des ids.
	///\param out	Le stream de sortie.
	///\return Le stream initial.
	///
	ostream& afficher(ostream& out);

private:

	list<ObjetDeMessier*> liste_;

};

#endif // LISTE_OBJETS_DE_MESSIER_INCLUDED
