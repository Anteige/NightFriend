///////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ObjetCeleste.cpp
/// \date		31/03/17
/// \brief		Implementation de la classe ObjetCelete.
///////////////////////////////////////////////////////////////////////////////

#include "ObjetCeleste.h"

ObjetCeleste::ObjetCeleste() :
	nom_("Objet sans nom"), 
	constellation_("BTW"), 
	ascensionDroite_({Donnee(), Donnee()}),
	declinaison_({ Donnee(), Donnee() })
{
}

ObjetCeleste::ObjetCeleste(const string& nom,
						   const string& constellation, 
						   const DonneeDouble& ascensionDroite, 
						   const DonneeDouble& declinaison)
{
	nom_ = nom;
	constellation_ = constellation;
	ascensionDroite_ = ascensionDroite;
	declinaison_ = declinaison;
}