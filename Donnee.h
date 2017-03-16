///////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		Donnee.h
/// \date		31/01/2017
/// \brief		Definition de la classe Donnee
///////////////////////////////////////////////////////////////////////////////

#ifndef _DONNEE_H_
#define _DONNEE_H_

#include <string>

using namespace std;

class Donnee 
{

public:

	///
	/// \brief	Constructeur par parametres
	/// \param	nom		Le nom de la donnee								   [in]
	/// \param	valeur	La valeur de la donnee							   [in]
	/// \param	unite 	L'unite de la donnee							   [in]
	///
	Donnee(string nom = "Donnee sans nom", double valeur = 0.0,
										   string unite = "unites");

	///
	/// \brief	Accessor de nom_
	/// \return	string	Le nom de la donnee
	///
	string obtenirNom() const;

	///
	/// \brief	Accessor de valeur_
	/// \return	double	La valeur de la donnee
	///
	double obtenirValeur() const;

	///
	/// \brief	Accessor de unite_
	/// \return	string	L'unite de la donnee
	///
	string obtenirUnite() const;

	///
	/// \brief	Mutator de nom_
	/// \param	nom		Le nouveau nom de la donnee						   [in]
	///
	void mettreNom(const string& nom);

	///
	/// \brief	Mutator de valeur_
	/// \param	valeur	La nouvelle valeur de la donnee					   [in]
	///
	void mettreValeur(const double& valeur);

	///
	/// \brief	Mutator de unite_
	/// \param	unite	La nouvelle unite de la donnee					   [in]
	///
	void mettreUnite(const string& unite);

	///
	/// \brief	Permet l'addition d'une donnee avec une autre donnee
	/// \param	donnee	La donnee a additionner							   [in]
	/// \return	Donnee	La donnee resultante
	///
	Donnee operator+(const Donnee& donnee) const;

	///
	/// \brief	Permet l'addition d'une donnee avec un nombre reel
	/// \param	donnee	Le nombre reel a additionner					   [in]
	/// \return	Donnee	La donnee resultante
	///
	Donnee operator+(const double& nombre) const;

	///
	/// \brief	Permet la commutativite de l'addition avec un reel
	/// \param	nombre	Le reel a additionner							   [in]
	/// \param	donnee	La donnee a additionner							   [in]
	/// \return	Donnee	La donnee resultante
	///
	friend Donnee operator+(const double&, const Donnee&);

	///
	/// \brief	Permet la soustraction d'une donnee avec une autre donnee
	/// \param	donnee	La donnee a soustraire							   [in]
	/// \return	Donnee	La donnee resultante
	///
	Donnee operator-(const Donnee& donnee) const;

	///
	/// \brief	Permet la soustraction d'une donnee avec un nombre reel
	/// \param	donnee	Le nombre reel a soustraire						   [in]
	/// \return	Donnee	La donnee resultante
	///
	Donnee operator-(const double& nombre) const;

	///
	/// \brief	Permet la commutativite de la soustraction avec un reel
	/// \param	nombre	Le reel a soustraire							   [in]
	/// \param	donnee	La donnee a soustraire							   [in]
	/// \return	Donnee	La donnee resultante
	///
	friend Donnee operator-(const double&, const Donnee&);

	///
	/// \brief	Permet la multiplication d'une donnee avec une autre donnee
	/// \param	donnee	La donnee a multiplier							   [in]
	/// \return	Donnee	La donnee resultante
	///
	Donnee operator*(const Donnee& donnee) const;

	///
	/// \brief	Permet la multiplication d'une donnee avec un nombre reel
	/// \param	donnee	Le nombre reel a multiplier						   [in]
	/// \return	Donnee	La donnee resultante
	///
	Donnee operator*(const double& donnee) const;

	///
	/// \brief	Permet la commutativite de la multiplication avec un reel
	/// \param	nombre	Le reel a multiplier							   [in]
	/// \param	donnee	La donnee a multiplier							   [in]
	/// \return	Donnee	La donnee resultante
	///
	friend Donnee operator*(const double&, const Donnee&);

	///
	/// \brief	Permet la division d'une donnee avec une autre donnee
	/// \param	donnee	La donnee a diviser								   [in]
	/// \return	Donnee	La donnee resultante
	///
	Donnee operator/(const Donnee& donnee) const;

	///
	/// \brief	Permet la division d'une donnee avec un nombre reel
	/// \param	donnee	La donnee a diviser								   [in]
	/// \return	Donnee	La donnee resultante
	///
	Donnee operator/(const double& nombre) const;

	///
	/// \brief	Permet la commutativite de la division avec un reel
	/// \param	nombre	Le reel a diviser								   [in]
	/// \param	donnee	La donnee a diviser								   [in]
	/// \return	Donnee	La donnee resultante
	///
	friend Donnee operator/(const double&, const Donnee&);

	///
	/// \brief	Permet de mettre une donnee a un exposant
	/// \param	nombre	Le nombre de l'exposant							   [in]
	/// \param	donnee	La donnee a mettre en exposant					   [in]
	///
	Donnee operator^(const double& nombre) const;

	///
	/// \brief	Permet l'affichage d'une donnee
	/// \param	donnee	La donnee a afficher						   [in/out]
	/// \param	out		Le flux de sortie							   [in/out]
	/// \return	ostream	Permet l'appel en cascade
	///
	friend ostream& operator<<(ostream& out, const Donnee& donnee);

private:

	string	nom_;
	double	valeur_;
	string	unite_;

};

#endif // _DONNEE_H_