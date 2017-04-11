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
							   const Donnee& diametreApparent)
	: ObjetCeleste(nom, constellation, ascensionDroite, declinaison), 
	  id_(id), 
	  type_(type),
	  magnitudeApparente_(magnitudeApparente), 
	  distance_(distance),
      diametreApparent_(diametreApparent)
{	
}

int ObjetDeMessier::obtenirId() const
{
	return id_;
}