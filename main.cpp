///////////////////////////////////////////////////////////////////////////////
// \autors	Antoine Gaulin
// \file	main.cpp
// \date	24/03/2017
// \brief	Ce programme permet de gérer les nombreux objets de Messiers.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <windows.h>

#include "ListeObjetsDeMessier.h"


using namespace std;


enum Mois { JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC };
const int N_DE_MOIS = 12;

enum Periodes { SOIR, MINUIT, MATIN };
const int N_DE_PERIODE = 3;

enum Types
{
	AMAS_OUVERT,
	AMAS_GLOBULAIRE,
	NEBULEUSE_PLANETAIRE,
	STARFORMING_NEBULA,
	GALAXIE_SPIRALE,
	GALAXIE_ELIPTIQUE,
	GALAXIE_IRREGULIERE,
	GALAXIE_LENTILLE,
	RESTANT_DE_SUPERNOVA,
	ASTERISME = 'A',
	PATCH_VOIE_LACTEE = 'B',
	ETOILE_BINAIRE = 'C'
};


///
///\brief	Initialise l'affichage et mets le texte en rouge fonce.
///
void InitialiserAffichage()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
}


///
///\brief	Affiche le menu principal dans la console.
///
void afficherMenuPrincipal() 
{
	system("cls");

	cout << "Veuiller choisir parmis les options suivantes : "			<< endl
		 << "0 - Ajuster les parametres du programme."					<< endl
		 << "1 - Afficher la liste des objets de Messier visibles."		<< endl
		 << "2 - Rechercher un objet de Messier"						<< endl
		 << "3 - Fermer le programme"									<< endl;
}


///
/// \brief Fonction principale.
///
int main()
{
	// Initialisation du GUI.
	InitialiserAffichage();
	// TODO: InitialiserSon();

	// Initialisation de la liste des objets de Messier.
	ListeObjetsDeMessier listeDesObjetsDeMessiers;
	listeDesObjetsDeMessiers.lireFichier();

	// Definition des choix du menu.
	enum Choix { PARAMETRES, LISTE, RECHERCHE, QUITTER };

	// Boucle du menu principale.
	while (true) {

		// Afficher le menu.
		afficherMenuPrincipal();

		// L'utilisateur entre un choix.
		int choix;
		cin >> choix;

		switch (choix) {

			case PARAMETRES:
				// TODO : Implementer l'ajustement des parametres.
					// TODO : Implementer l'ajustement de la difficulte.
					// TODO : Implementer l'ajustement de la periode d'observation.
				break;

			case LISTE:
				// TODO : Implementer l'affichage de la liste ajustee au conditions.
					// TODO : Implementer l'ajustement des criteres d'affichages.
						// TODO : Implementer l'option par types.
						// TODO : Implementer l'option par magnitudes.
						// TODO : Implementer l'option par distance.
						// TODO : Implementer l'option par diametre apparent.
				break;

			case RECHERCHE:
				// TODO : Implementer la recherche d'un objet de Messier en particulier.
				break;

			case QUITTER:
				return(0);

			default:
				// Nettoyer cin.
				cin.clear();
				cin.ignore(80, '\n');
				break;
		}

	}
}

/*
struct Tableau3Variables {

int taille1 = N_DE_PERIODE,
taille2 = N_DE_MOIS;

double element[N_DE_PERIODE][N_DE_MOIS];
};

void initialiserTableau3Variables(Tableau3Variables& passagesAuMeridien) {
	for (int i = 0; i < passagesAuMeridien.taille1; i++) {
	passagesAuMeridien.element[SOIR + i][NOV] = 1.5 + 3 * (i + 0);
	passagesAuMeridien.element[SOIR + i][DEC] = 1.5 + 3 * (i + 0);
	passagesAuMeridien.element[SOIR + i][JAN] = 1.5 + 3 * (i + 1);
	passagesAuMeridien.element[SOIR + i][FEV] = 1.5 + 3 * (i + 2);
	passagesAuMeridien.element[SOIR + i][MAR] = 1.5 + 3 * (i + 2);
	passagesAuMeridien.element[SOIR + i][AVR] = 1.5 + 3 * (i + 3);
	passagesAuMeridien.element[SOIR + i][MAI] = 1.5 + 3 * (i + 4);
	passagesAuMeridien.element[SOIR + i][JUN] = 1.5 + 3 * (i + 4);
	passagesAuMeridien.element[SOIR + i][JUL] = 1.5 + 3 * (i + 5);
	passagesAuMeridien.element[SOIR + i][AOU] = 1.5 + 3 * (i + 6);
	passagesAuMeridien.element[SOIR + i][SEP] = 1.5 + 3 * (i + 6);
	passagesAuMeridien.element[SOIR + i][OCT] = 1.5 + 3 * (i + 7);
}

void afficherListe(string titre, ListeDesObjetsMessiers& liste) {

	system("cls");

	unsigned compteur = 0;

	cout << "~ "<< titre << " ~" << endl;
	cout << "________________________________________________________________________"  << endl;

	for (int i = 0; i < liste.taille; i++) {
		if (liste.element[i].estAffiche) {
			cout << ' ' << 'M' << liste.element[i].nom << '\t'
				<< "Type: " << left << setw(17) << setfill(' ') << liste.element[i].type << '\t'
				<< "Magnitude: " << liste.element[i].magnitude << '\t'
				<< "AD: " << right << setw(2) << setfill('0') << liste.element[i].acensionDroite.heure << ':' << right << setw(2) << setfill('0') << liste.element[i].acensionDroite.minute << '\t'
				<< "Dec: " << setw(3) << setfill(' ') << liste.element[i].declinaison << endl;
			compteur++;
		}
	}

		if (compteur != 0)
			cout << endl << "total: " << compteur << endl;
		else
			cout << endl << "Aucun objet Messier n'est visible :(" << endl;
		cout << "________________________________________________________________________" << endl;
}

void afficherObjet(ListeDesObjetsMessiers liste) {

	system("cls");

	int objet = 0;

	cout << "Entrez l'objet Messier :" << endl << 'M';
	cin >> objet;

	if (objet >= 0 && objet <= 110) {
		cout << "Voici les informations trouves sur " << 'M' << objet-- << " : " << endl
			<< "--------------------" << endl
			<< 'M' << liste.element[objet].nom << endl
			<< "Type: " << left << setw(17) << setfill(' ') << liste.element[objet].type << endl
			<< "Magnitude: " << liste.element[objet].magnitude << endl
			<< "AD: " << right << setw(2) << setfill('0') << liste.element[objet].acensionDroite.heure << ':' << right << setw(2) << setfill('0') << liste.element[objet].acensionDroite.minute << endl
			<< "Dec: " << setw(3) << setfill(' ') << liste.element[objet].declinaison << endl
			<< "--------------------" << endl;
	}
	else
		cout << "Cet objet Messier n'existe pas." << endl;

}

void afficherEtoileGuide(Etoiles etoile) {
	if (etoile.nom != "") {
		cout << endl << "L'etoile de reperage est " << etoile.nom << " situee dans la constellation " << etoile.constellation << "." << endl
		 	 << "Les coordonees pour cette etoile sont :" << endl
			 << "AD: " << right << setw(2) << setfill('0') << etoile.acensionDroite.heure << ':' << right << setw(2) << setfill('0') << etoile.acensionDroite.minute << endl
			 << "Dec: " << etoile.declinaison << endl;
	}
}

void testFacile(ListeDesObjetsMessiers& liste) {
	for (int i = 0; i < liste.taille; i++) {
		if (liste.element[i].magnitude >= 8)
			liste.element[i].estAffiche = false;
	}
}

void testVisible(const Tableau3Variables& passagesAuMeridien, ListeDesObjetsMessiers& liste) {
	bool			estValide = 0;
	int				periode = -1,
					heure = 0,
					mois = 0;
	AcensionDroite	acensionsDroiteMin,
					acensionsDroiteMax;
	Etoiles			etoileGuide;

	system("cls");

	cout << "Veuillez entrer le mois actuel en format numerique MM :" << endl;
	do {
		cin >> mois;
		if (cin.fail()) {
			cin.clear(); cin.ignore(80, '\n');
		}
		else {
			mois -= 1;
			if ((mois <= 11) && (mois >= 0))
				estValide = true;
			else
				cout << "Veuillez entrer un mois valide" << endl;
		}
	} while (!estValide);

	system("cls");

	cout << "Veuillez entrer l'heure actuel en format numerique HH :" << endl;
	do {
		cin >> heure;
		if (cin.fail()) {
			cin.clear(); cin.ignore(80, '\n');
		}
		else {
		if ((20 <= heure) && (heure <= 22))
			periode = SOIR;
		else if ((23 == heure) || (0 == heure) || (heure == 1))
			periode = MINUIT;
		else if ((2 <= heure) && (heure <= 4))
			periode = MATIN;
		else
			cout << "Choisissez une heure entre 20 et 04" << endl;
		}
	} while (periode != SOIR && periode != MINUIT && periode != MATIN);

	acensionsDroiteMin.heure = passagesAuMeridien.element[periode][mois] - 1.5;
	acensionsDroiteMax.heure = passagesAuMeridien.element[periode][mois] + 1.5;

	for (int i = 0; i < liste.taille; i++) {
		bool EstDansLaPlageHoraire = (acensionsDroiteMin.heure <= liste.element[i].acensionDroite.heure) && (liste.element[i].acensionDroite.heure <= acensionsDroiteMax.heure);
		if (!EstDansLaPlageHoraire)
			liste.element[i].estAffiche = false;
	}
}

void trouverEtoileGuide(ListeDesObjetsMessiers liste, Etoiles& etoileGuide) {
	bool estTrouve = false;
	for (int i = 0; i < liste.taille; i++) {
		if (liste.element[i].estAffiche == true && !estTrouve) {
			if (0 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 3) {
				etoileGuide.nom = "Mirach";
				etoileGuide.constellation = "Andromeda";
				etoileGuide.declinaison = 35;
				etoileGuide.acensionDroite.heure = 1;
				etoileGuide.acensionDroite.minute = 9;
				estTrouve = true;
			}
			else if (3 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 6) {
				etoileGuide.nom = "Aldebaran";
				etoileGuide.constellation = "Taurus";
				etoileGuide.declinaison = 16;
				etoileGuide.acensionDroite.heure = 4;
				etoileGuide.acensionDroite.minute = 35;
				estTrouve = true;
			}
			else if (6 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 9) {
				etoileGuide.nom = "Pollux";
				etoileGuide.constellation = "Gemini";
				etoileGuide.declinaison = 28;
				etoileGuide.acensionDroite.heure = 7;
				etoileGuide.acensionDroite.minute = 45;
				estTrouve = true;
			}
			else if (9 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 12) {
				etoileGuide.nom = "Algieba";
				etoileGuide.constellation = "Leo";
				etoileGuide.declinaison = 19;
				etoileGuide.acensionDroite.heure = 10;
				etoileGuide.acensionDroite.minute = 19;
				estTrouve = true;
			}
			else if (12 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 15) {
				etoileGuide.nom = "Alkaid";
				etoileGuide.constellation = "Ursa Major";
				etoileGuide.declinaison = 49;
				etoileGuide.acensionDroite.heure = 13;
				etoileGuide.acensionDroite.minute = 47;
				estTrouve = true;
			}
			else if (15 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 18) {
				etoileGuide.nom = "Kornephoros";
				etoileGuide.constellation = "Hercules";
				etoileGuide.declinaison = 21;
				etoileGuide.acensionDroite.heure = 16;
				etoileGuide.acensionDroite.minute = 30;
				estTrouve = true;
			}
			else if (18 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 21) {
				etoileGuide.nom = "Albireo";
				etoileGuide.constellation = "Cygnus";
				etoileGuide.declinaison = 27;
				etoileGuide.acensionDroite.heure = 19;
				etoileGuide.acensionDroite.minute = 30;
				estTrouve = true;
			}
			else if (21 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 24) {
				etoileGuide.nom = "Matar";
				etoileGuide.constellation = "Pegasus";
				etoileGuide.declinaison = 30;
				etoileGuide.acensionDroite.heure = 22;
				etoileGuide.acensionDroite.minute = 43;
				estTrouve = true;
			}
		}
	}
}
*/