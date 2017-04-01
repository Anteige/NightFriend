///////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ObjetDeMessier.cpp
/// \date		26/03/2017
/// \brief		Implementation de la classe Objet de Messier.
///////////////////////////////////////////////////////////////////////////////

#include "ObjetDeMessier.h"

ObjetDeMessier::ObjetDeMessier(const string& nom, 
							   const string& constellation,
						       const DonneeDouble& ascensionDroite,
							   const DonneeDouble& declinaison,
							   int id,
							   const string& type,
							   const Donnee& magnitudeApparente, 
							   const Donnee& distance, 
							   const Donnee& diametreApparent):
	id_(id), 
	type_(type),
	magnitudeApparente_(magnitudeApparente), 
	distance_(distance),
	diametreApparent_(diametreApparent)
{	
	//TODO : Remplacer par les mutators d'objet celeste.
	nom_ = nom;
	constellation_ = constellation;
	ascensionDroite_ = ascensionDroite;
	declinaison_ = declinaison;
}


int ObjetDeMessier::obtenirId() const
{
	return id_;
}
