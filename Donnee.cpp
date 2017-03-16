////////////////////////////////////////////////////////////////////////////////
/// \author		Antoine Gaulin
/// \file		Donnee.cpp
/// \date		31/01/2017
/// \brief		Implementation de la classe Donnee
////////////////////////////////////////////////////////////////////////////////

#include "iostream"
#include "Donnee.h"

Donnee::Donnee(string nom, double valeur, string unite) :
	nom_(nom), valeur_(valeur), unite_(unite)
{
}

string Donnee::obtenirNom() const
{
	return nom_;
}

double Donnee::obtenirValeur() const
{
	return valeur_;
}

string Donnee::obtenirUnite() const
{
	return unite_;
}

void Donnee::mettreNom(const string& nom)
{
	nom_ = nom;
}

void Donnee::mettreValeur(const double& valeur)
{
	valeur_ = valeur;
}

void Donnee::mettreUnite(const string& unite)
{
	unite_ = unite;
}

Donnee Donnee::operator+(const Donnee& donnee) const
{
	Donnee resultat(nom_, valeur_, unite_);

	if (donnee.nom_ != nom_ || donnee.unite_ != unite_) {
		cout << "/!\\ ERREUR lors de la soustraction de donnees : "
			 << "Il n'est pas possible d'additionner ";
		if (donnee.nom_ != nom_)
			cout << "deux donnees de nom differents." << endl;
		else
			cout << "deux donnees d'unites differentes." << endl;
	}
	else
		resultat.valeur_ += donnee.valeur_;

	return resultat;
}

Donnee Donnee::operator+(const double& nombre) const
{
	Donnee resultat(nom_, valeur_, unite_);
	resultat.valeur_ += nombre;
	return resultat;
}

Donnee operator+(const double& nombre, const Donnee& donnee)
{
	return nombre + donnee;
}

Donnee Donnee::operator-(const Donnee& donnee) const
{
	Donnee resultat(nom_, valeur_, unite_);

	if (donnee.nom_ != nom_ || donnee.unite_ != unite_) {
		cout << "/!\\ ERREUR lors de la soustraction de donnees : "
			 << "Il n'est pas possible de soustraire ";
		if (donnee.nom_ != nom_)
			cout << "deux donnees de nom differents." << endl;
		else
			cout << "deux donnees d'unites differentes." << endl;
	}
	else
		resultat.valeur_ -= donnee.valeur_;

	return resultat;
}

Donnee Donnee::operator-(const double& nombre) const
{
	Donnee resultat(nom_, valeur_, unite_);
	resultat.valeur_ -= nombre;
	return resultat;
}

Donnee operator-(const double& nombre, const Donnee& donnee)
{
	return nombre - donnee;
}

Donnee Donnee::operator*(const Donnee& donnee) const
{
	Donnee resultat(nom_, valeur_, unite_);

	if (donnee.nom_ != nom_ || donnee.unite_ != unite_) {
		cout << "/!\\ ERREUR lors de la soustraction de donnees : "
			 << "Il n'est pas possible de multiplier ";
		if (donnee.nom_ != nom_)
			cout << "deux donnees de nom differents." << endl;
		else
			cout << "deux donnees d'unites differentes." << endl;
	}
	else
		resultat.valeur_ *= donnee.valeur_;

	return resultat;
}

Donnee Donnee::operator*(const double& nombre) const
{
	Donnee resultat(nom_, valeur_, unite_);
	resultat.valeur_ *= nombre;
	return resultat;
}

Donnee operator*(const double& nombre, const Donnee& donnee)
{
	return nombre * donnee;
}

Donnee Donnee::operator/(const Donnee& donnee) const
{
	Donnee resultat(nom_, valeur_, unite_);

	if (donnee.nom_ != nom_ || donnee.unite_ != unite_) {
		cout << "/!\\ ERREUR lors de la division de donnees : "
			 << "Il n'est pas possible de diviser ";
		if (donnee.nom_ != nom_)
			cout << "deux donnees de nom differents." << endl;
		else
			cout << "deux donnees d'unites differentes." << endl;
	}
	else
		resultat.valeur_ /= donnee.valeur_;

	return resultat;
}

Donnee Donnee::operator/(const double& nombre) const
{
	Donnee resultat(nom_, valeur_, unite_);
	resultat.valeur_ /= nombre;
	return resultat;
}

Donnee operator/(const double& nombre, const Donnee& donnee)
{
	return nombre / donnee;
}

Donnee Donnee::operator^(const double& nombre) const
{
	Donnee resultat(nom_, pow(valeur_, nombre), unite_);
	return resultat;
}

ostream& operator<<(ostream& out, const Donnee& donnee)
{
	out << donnee.nom_		<< ' ' 
		<< donnee.valeur_	<< ' '
		<< donnee.unite_	<< ' '
		<< endl;
	return out;
}