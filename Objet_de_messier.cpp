////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		Objet_de_Messier.cpp
/// \date		26/03/17
/// \brief		Implementation de la classe objet de messier
////////////////////////////////////////////////////////////////////////////////

#include "Objet_de_messier.h"

Objet_messier::Objet_messier() : id_(000), diametreApparent_(Donnee())
{
}

void Objet_messier::mettreId(int id)
{
	id_ = id;
}

void Objet_messier::mettreDiametreApparent(const Donnee& diametre)
{
	diametreApparent_ = diametre;
}