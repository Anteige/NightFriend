///////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		ObjetCeleste.cpp
/// \date		31/03/17
/// \brief		Implementation de la classe ObjetCelete.
///////////////////////////////////////////////////////////////////////////////

#include "ObjetCeleste.h"

ObjetCeleste::ObjetCeleste(const string& nom, 
						   const string& constellation, 
						   const DonneeDouble& ascensionDroite,
						   const DonneeDouble& declinaison)
	: nom_(nom), constellation_(constellation), 
				 ascensionDroite_(ascensionDroite),
				 declinaison_(declinaison)
{
}

void ObjetCeleste::modifierNom(const string& nom)
{
	nom_ = nom;
}

void ObjetCeleste::modifierConstellation(const string& constellation)
{
	constellation_ = constellation;
}

void ObjetCeleste::modifierAscensionDroite(const DonneeDouble& ascensionDroite)
{
	ascensionDroite_ = ascensionDroite;
}

void ObjetCeleste::modifierDeclinaison(const DonneeDouble& declinaison)
{
	declinaison_ = declinaison;
}