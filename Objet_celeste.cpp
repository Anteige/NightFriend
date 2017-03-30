////////////////////////////////////////////////////////////////////////////////
/// \author		Jean-Sebastien Lemaire
/// \file		Objet_celeste.cpp
/// \date		26/03/2017
/// \brief		Implementation de la classe Objet_celeste
////////////////////////////////////////////////////////////////////////////////

#include "Objet_celeste.h"

Objet_celeste::Objet_celeste(const string& nom, const string& type,
                                                const string& constellation) :
	nom_(nom), 
	type_(type), 
	constellation_(constellation), 
	declinaison_(0),
	distance_(0), 
	magnitudeApparente_(0)
{
    ascensionDroite_.heure = 0;
    ascensionDroite_.minute = 0;
}

string Objet_celeste::obtenirNom() const
{
	return nom_;
}

string Objet_celeste::obtenirType() const
{
	return type_;
}

string Objet_celeste::obtenirConstellation() const
{
	return constellation_;
}

Donnee Objet_celeste::obtenirDeclinaison() const
{
	return declinaison_;
}

Donnee Objet_celeste::obtenirDistance() const
{
	return distance_;
}

Donnee Objet_celeste::obtenirMagnitudeApparente() const
{
	return magnitudeApparente_;
}

AscensionDroite Objet_celeste::obtenirAscensionDroite() const
{
	return ascensionDroite_;
}

void Objet_celeste::mettreNom(const string& nom)
{
	nom_ = nom;
}

void Objet_celeste::mettreType(const string& type)
{
	type_ = type;
}

void Objet_celeste::mettreConstellation(const string& constellation)
{
	constellation_ = constellation;
}

void Objet_celeste::mettreDeclinaison(const Donnee& declinaison)
{
	declinaison_ = declinaison;
}

void Objet_celeste::mettreDistance(const Donnee& distance)
{
	distance_ = distance;
}

void Objet_celeste::mettreMagnitudeApparente(const Donnee& magnitudeApparente)
{
    magnitudeApparente_ = magnitudeApparente;
}

void Objet_celeste::mettreAscensionDroite(const AscensionDroite& ascensionDroite)
{
	ascensionDroite_ = ascensionDroite;
}