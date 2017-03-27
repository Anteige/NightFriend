////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		Objet_de_Messier.h
/// \date		16/03/17
/// \brief		Definition de la classe objet de messier
////////////////////////////////////////////////////////////////////////////////

#ifndef _OBJET_MESSIER_H_
#define _OBJET_MESSIER_H_

#include "Objet_celeste.h"
#include "donnee.h"

using namespace std;

class Objet_messier : Objet_celeste
{

public:

	///
	///\brief	constructeur par default
	///
	Objet_messier();



	///
	///\brief	Mutator de id_
	///\param	int	Le nouveau id de l'objet.
	///
	void mettreId(int id);

	///
	///\brief	Mutator de diametreApparent_
	///\param	int	Le nouveau id de l'objet.
	///
	void mettreDiametreApparent(const Donnee& diametre);

private:

	int id_;
	Donnee diametreApparent_;

};

#endif // _OBJET_MESSIER_H_