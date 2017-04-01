////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ListeObjetsDeMessier.cpp
/// \date		30/03/2017
/// \brief		Implementation de la classe Objet de Messier.
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include "ListeObjetsDeMessier.h"

ListeObjetsDeMessier::ListeObjetsDeMessier()
{
}

ListeObjetsDeMessier::~ListeObjetsDeMessier()
{
	for_each( liste_.begin(), 
			  liste_.end(), 
			  [](ObjetDeMessier* objet){delete objet;}
			);

	liste_.clear();
}

void ListeObjetsDeMessier::inserer( 
	int id,
	string constellation,
	string type,
	DonneeDouble ascensionDroite,
	DonneeDouble declinaison,
	Donnee magnitudeApparente,
	Donnee distance,
	Donnee diametreApparent
)

{
	ObjetDeMessier* nouvelObjet = new ObjetDeMessier(id, 
													 constellation, 
													 type, 
													 ascensionDroite,
													 declinaison, 
													 magnitudeApparente,
													 distance,
													 diametreApparent
													);
	liste_.push_back(nouvelObjet);
}

ObjetDeMessier* ListeObjetsDeMessier::trouver(int id) const
{
	auto it = find_if(liste_.begin(), 
					  liste_.end(), 
					  [](int id, const ObjetDeMessier* objet)
					  { return objet -> obtenirId() == id; }
					 );

	if (it != liste_.end())
		return *it;
	else
		return nullptr;
}

void ListeObjetsDeMessier::lireFichier()
{
	// TODO: Completer l'implementation
}

ostream& ListeObjetsDeMessier::afficher(ostream & out)
{
	// TODO: Completer l'implementation
	return out;
}
