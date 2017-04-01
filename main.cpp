///////////////////////////////////////////////////////////////////////////////
// \autors	Antoine Gaulin
// \file	main.cpp
// \date	24/03/2017
// \brief	Ce programme permet de gérer les nombreux objets de Messiers.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

static const int	N_OBJETS_MESSIERS = 110,
					N_DE_MOIS = 12,
					N_DE_PERIODE = 3,
					N_MAX_CHAR_TYPE = 20;

#pragma region Enumerations

enum Moments { SOIR, MINUIT, MATIN };

enum Mois { JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC };

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

#pragma endregion

#pragma region Structures

struct Tableau3Variables {

	int taille1 = N_DE_PERIODE,
		taille2 = N_DE_MOIS;

	double element[N_DE_PERIODE][N_DE_MOIS];
};

#pragma endregion

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

}

void afficherMenu() {
	cout << "Veuiller faire un choix parmis les suivants : "			<< endl
		 << "1 - Ajuster les parametres"								<< endl
		 << "2  Afficher Tout les objets Messiers actuellement visible" << endl
		 << "3  Afficher les informations d'un objet de Messier"		<< endl
		 << "0  Fermer le programme"									<< endl;
}

/*
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

int main() {
	int choix = 0;
	int mois = -1;
	ListeDesObjetsMessiers objetsMessier;
	Tableau3Variables passagesAuMeridien;
	Etoiles etoileGuide;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	lirefichierbinaire(objetsMessier);

	initialiserTableau3Variables(passagesAuMeridien);

	cout << "Bienvenue dans le Companion du ciel 2.6" << endl << endl;

	afficherMenu();

	cout << "							par Antoine Gaulin" << endl << endl;
	cin >> choix;

	if (cin.fail())
		choix = -1;

	while (choix != 0) {

		switch (choix) {
			case 1 :
				afficherListe("Liste exaustive des objets Messiers", objetsMessier);
				break;

			case 2 :
				testVisible(passagesAuMeridien, objetsMessier);
				trouverEtoileGuide(objetsMessier, etoileGuide);
				afficherListe("Liste des objets Messiers actuellement visibles", objetsMessier);
				afficherEtoileGuide(etoileGuide);
				break;

			case 3 :
				testFacile(objetsMessier);
				afficherListe("Liste des objets Messiers faciles", objetsMessier);
				break;

			case 4 :
				testFacile(objetsMessier);
				testVisible(passagesAuMeridien, objetsMessier);
				trouverEtoileGuide(objetsMessier, etoileGuide);
				afficherListe("Liste des objets Messiers faciles et visibles", objetsMessier);
				afficherEtoileGuide(etoileGuide);
				break;

			case 5 :
				afficherObjet(objetsMessier);
				break;

			case 6 :
				break;

			default :
				cout << "Cette action est invalide" << endl;
				cin.clear();
				cin.ignore(80, '\n');
		}

		initialiserEstAfficher(objetsMessier);
		if (cin.fail())
			choix = -1;
		else
			cin >> choix;
		system("cls");
		afficherMenu();
	}

	cout << "Bonne Observations!" << endl;
}
*/