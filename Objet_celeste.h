////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin & JS Lemaire
/// \file		Objet_celeste.h
/// \date		16/03/17
/// \brief		Definition de la classe objet celeste
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Donnee.h"

#ifndef _OBJET_CELESTE_H_
#define _OBJET_CELESTE_H_

using namespace std;

class Objet_celeste
{

public:

    ///
	/// \brief	Constructeur par parametres
	/// \param	nom		Le nom de la donnee
	/// \param	valeur	La valeur de la donnee
	/// \param	unite 	L'unite de la donnee
	///
    Objet_celeste(string nom = "objet celeste sans nom", string type = "type inconnu",
                  string constellation = "constellation inconnue");

    ///
	/// \brief	accessor de ascensionDroite_.heure
	/// \return	Donnee	l'ascension droite heure
	///
    Donnee obtenirAscensionDroiteHeure() const;

    ///
	/// \brief	accessor de ascensionDroite_.minute
	/// \return	Donnee	l'ascension droite minute
	///
    Donnee obtenirAscensionDroiteMinute() const;

    ///
	/// \brief	accessor de declinaison_
	/// \return	Donnee	la declinaison
	///
	Donnee obtenirDeclinaison() const;

	///
	/// \brief	accessor de distance_
	/// \return	Donnee	la distance
	///
	Donnee obtenirDistance() const;

	///
	/// \brief	accessor de magnitudeApparente_
	/// \return	Donnee	la magnitude apparente
	///
	Donnee obtenirMagnitudeApparente() const;

	///
	/// \brief	accessor de nom_
	/// \return	Donnee	le nom
	///
	string obtenirNom() const;

	///
	/// \brief	accessor de type_
	/// \return	Donnee	le type
	///
	string obtenirType() const;

	///
	/// \brief	accessor de constellation_
	/// \return	Donnee	la constellation
	///
	string obtenirConstellation() const;

	///
	/// \brief	Mutator de nom_
	/// \param	nom		Le nouveau nom de la donnee
	///
	void mettreNom(const string& nom);

	///
	/// \brief	Mutator de type_
	/// \param	type		Le nouveau type de la donnee
	///
	void mettreType(const string& type);

	///
	/// \brief	Mutator de constellation_
	/// \param	constellation		La nouvelle constellation de la donnee
	///
	void mettreConstellation(const Donnee& constellation);

	///
	/// \brief	Mutator de declinaison_
	/// \param	declinaison		La nouvelle declinaison de la donnee
	///
	void mettreDeclinaison(const Donnee& declinaison);

	///
	/// \brief	Mutator de distance_
	/// \param	distance		La nouvelle distance de la donnee
	///
	void mettreDistance(const Donnee& distance);

	///
	/// \brief	Mutator de magnitudeApparente_
	/// \param	magnitudeApparente		La nouvelle magnitude apparente de la donnee
	///
	void mettreMagnitudeApparente(const Donnee& magnitudeApparente);

private:

	struct AscensionDroite {
        int heure,
            minute;
    };

	Donnee declinaison_;
	Donnee distance_;
	Donnee magnitudeApparente_;
	string nom_;
    string type_;
	string constellation_;
};

#endif // _OBJET_CELESTE_H_
