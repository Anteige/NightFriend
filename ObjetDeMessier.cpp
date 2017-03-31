////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ObjetDeMessier.cpp
/// \date		26/03/2017
/// \brief		Implementation de la classe Objet de Messier.
////////////////////////////////////////////////////////////////////////////////

#include "ObjetDeMessier.h"
ObjetDeMessier::ObjetDeMessier (
	int id = 000,
	string constellation = "CON",
	string type = "0",
	DonneeDouble ascensionDroite = { Donnee(), Donnee() },
	DonneeDouble declinaison = { Donnee(), Donnee() },
	Donnee magnitudeApparente = Donnee(),
	Donnee distance = Donnee(),
	Donnee diametreApparent = Donnee()
) :
	id_(id),
	constellation_(constellation),
	type_(type),
	ascensionDroite_(ascensionDroite),
	declinaison_(declinaison),
	magnitudeApparente_(magnitudeApparente),
	distance_(distance),
	diametreApparent_(diametreApparent)
{
}

int ObjetDeMessier::obtenirId() const
{
	return id_;
}
