///////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin & JS Lemaire
/// \file		Objet_celeste.h
/// \date		16/03/17
/// \brief		Definition de la classe objet celeste
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Donnee.h"
#include "utilitaire.h"

#ifndef _OBJET_CELESTE_H_
#define _OBJET_CELESTE_H_

using namespace std;

class Objet_celeste
{

public:

    ///
	/// \brief	Constructeur par parametres
	/// \param	nom					Le nom de l'objet
	/// \param	type				Le type de l'objet
	/// \param	constellation 		La constellation ou est situee l'objet
	///
    Objet_celeste(const string& nom = "objet celeste sans nom", 
				  const string& type = "type inconnu",
                  const string& constellation = "constellation inconnue"
				 );

    ///
	/// \brief	accessor de ascensionDroite_
	/// \return	Donnee				L'ascensionDroite de l'objet
	///
    AscensionDroite obtenirAscensionDroite() const;

    ///
	/// \brief	accessor de declinaison_
	/// \return	Donnee				La declinaison de l'objet
	///
	Donnee obtenirDeclinaison() const;

	///
	/// \brief	accessor de distance_
	/// \return	Donnee				La distance de l'objet
	///
	Donnee obtenirDistance() const;

	///
	/// \brief	accessor de magnitudeApparente_
	/// \return	Donnee				La magnitude apparente de l'objet
	///
	Donnee obtenirMagnitudeApparente() const;

	///
	/// \brief	accessor de nom_
	/// \return	Donnee				Le nom de l'objet
	///
	string obtenirNom() const;

	///
	/// \brief	accessor de type_
	/// \return	Donnee				Le type de l'objet
	///
	string obtenirType() const;

	///
	/// \brief	accessor de constellation_
	/// \return	Donnee				La constellation ou est situe l'objet
	///
	string obtenirConstellation() const;

	///
	/// \brief	Mutator de nom_
	/// \param	nom					Le nouveau nom de l'objet
	///
	void mettreNom(const string& nom);

	///
	/// \brief	Mutator de type_
	/// \param	type				Le nouveau type de l'objet
	///
	void mettreType(const string& type);

	///
	/// \brief	Mutator de constellation_
	/// \param	constellation		La nouvelle constellation de l'objet
	///
	void mettreConstellation(const string& constellation);

	///
	/// \brief	Mutator de declinaison_
	/// \param	declinaison			La nouvelle declinaison de l'objet
	///
	void mettreDeclinaison(const Donnee& declinaison);

	///
	/// \brief	Mutator de distance_
	/// \param	distance			La nouvelle distance de l'objet
	///
	void mettreDistance(const Donnee& distance);

	///
	/// \brief	Mutator de magnitudeApparente_
	/// \param	magnitudeApparente	La nouvelle magnitude apparente de l'objet
	///
	void mettreMagnitudeApparente(const Donnee& magnitudeApparente);

	///
	/// \brief	Mutator de acensionDroite_
	/// \param	AscensionDroite		La nouvelle ascension droite de l'objet
	///
	void mettreAscensionDroite(const AscensionDroite& ascensionDroite);

	void LireFichier() const {

		char chaine[N_MAX_CHAR_TYPE];

		ifstream fichierBinaire("database,txt");

		fichierBinaire.seekg(0, ios::beg);

		for (int i = 0; i < N_OBJETS_MESSIERS; i++) {

			fichierBinaire.read((char*)&objetsMessier.element[i].nom, sizeof(int));

			fichierBinaire.read((char*)&chaine, sizeof(chaine));
			objetsMessier.element[i].type = chaine;

			fichierBinaire.read((char*)&objetsMessier.element[i].magnitude, sizeof(double));

			fichierBinaire.read((char*)&objetsMessier.element[i].declinaison, sizeof(int));

			fichierBinaire.read((char*)&objetsMessier.element[i].acensionDroite.heure, sizeof(int));
			fichierBinaire.read((char*)&objetsMessier.element[i].acensionDroite.minute, sizeof(int));
		}

	}

private:

    AscensionDroite ascensionDroite_;
	Donnee declinaison_;
	Donnee distance_;
	Donnee magnitudeApparente_;
	string nom_;
    string type_;
	string constellation_;

};

#endif // _OBJET_CELESTE_H_
