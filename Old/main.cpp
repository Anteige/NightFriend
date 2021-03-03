/*
FICHIER : ObjetsMessiers.cpp
AUTEUR : Antoine Gaulin
DATE : 30/10/2016 - MAJ 10/12/2016
DESCRIPTION : Ce programme permet de manipuler une liste des objets Messiers
*/

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

#pragma region �num�rations

enum Mois { JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC };

enum Moments { SOIR, MINUIT, MATIN };

#pragma endregion

#pragma region Structures

struct AcensionDroite {
	int heure,
		minute;
};

struct Informations {
	bool			estAffiche = true;
	int				d�clinaison = 0;
	double			magnitude = 0.0;
	unsigned		nom = 0;
	string			type = "";
	AcensionDroite  acensionDroite = { 0, 0 };
};

struct ListeDesObjetsMessiers {
	int taille = N_OBJETS_MESSIERS;
	Informations �l�ment[N_OBJETS_MESSIERS];
};

struct �toiles {
	int				d�clinaison = 0;
	string			nom = "",
		constellation = "";
	AcensionDroite	acensionDroite = { 0 , 0 };
};

struct Tableau3Variables {

	int taille1 = N_DE_PERIODE,
		taille2 = N_DE_MOIS;

	double �l�ment[N_DE_PERIODE][N_DE_MOIS];
};

#pragma endregion

void lirefichierbinaire(ListeDesObjetsMessiers& objetsMessier) {

	char chaine[N_MAX_CHAR_TYPE];

	ifstream fichierBinaire("Liste des objets", ios::binary);

	fichierBinaire.seekg(0, ios::beg);

	for (int i = 0; i < N_OBJETS_MESSIERS; i++) {

		fichierBinaire.read((char*)&objetsMessier.�l�ment[i].nom, sizeof(int));

		fichierBinaire.read((char*)&chaine, sizeof(chaine));
		objetsMessier.�l�ment[i].type = chaine;

		fichierBinaire.read((char*)&objetsMessier.�l�ment[i].magnitude, sizeof(double));

		fichierBinaire.read((char*)&objetsMessier.�l�ment[i].d�clinaison, sizeof(int));

		fichierBinaire.read((char*)&objetsMessier.�l�ment[i].acensionDroite.heure, sizeof(int));
		fichierBinaire.read((char*)&objetsMessier.�l�ment[i].acensionDroite.minute, sizeof(int));
	}

}

void initialiserTableau3Variables(Tableau3Variables& passagesAuMeridien) {

	for (int i = 0; i < passagesAuMeridien.taille1; i++) {
		passagesAuMeridien.�l�ment[SOIR + i][NOV] = 1.5 + 3 * (i + 0);
		passagesAuMeridien.�l�ment[SOIR + i][DEC] = 1.5 + 3 * (i + 0);
		passagesAuMeridien.�l�ment[SOIR + i][JAN] = 1.5 + 3 * (i + 1);
		passagesAuMeridien.�l�ment[SOIR + i][FEV] = 1.5 + 3 * (i + 2);
		passagesAuMeridien.�l�ment[SOIR + i][MAR] = 1.5 + 3 * (i + 2);
		passagesAuMeridien.�l�ment[SOIR + i][AVR] = 1.5 + 3 * (i + 3);
		passagesAuMeridien.�l�ment[SOIR + i][MAI] = 1.5 + 3 * (i + 4);
		passagesAuMeridien.�l�ment[SOIR + i][JUN] = 1.5 + 3 * (i + 4);
		passagesAuMeridien.�l�ment[SOIR + i][JUL] = 1.5 + 3 * (i + 5);
		passagesAuMeridien.�l�ment[SOIR + i][AOU] = 1.5 + 3 * (i + 6);
		passagesAuMeridien.�l�ment[SOIR + i][SEP] = 1.5 + 3 * (i + 6);
		passagesAuMeridien.�l�ment[SOIR + i][OCT] = 1.5 + 3 * (i + 7);
	}

}

void initialiserEstAfficher(ListeDesObjetsMessiers& liste) {
	for (int i = 0; i < liste.taille; i++)
		liste.�l�ment[i].estAffiche = true;
}

void afficherMenu() {
	cout << "Veuiller faire un choix parmis les suivants : " << endl;
	cout << "1 - Afficher Tout les objets Messiers" << endl;
	cout << "2 - Afficher Tout les objets Messiers actuellement visible" << endl;
	cout << "3 - Afficher Tout les objets Messiers de niveau facile" << endl;
	cout << "4 - Afficher Tout les objets Messiers de niveau facile actuellement visible" << endl;
	cout << "5 - Afficher les informations d'un objet Messier specifique" << endl;
	cout << "6 - Afficher le menu" << endl;
	cout << "0 - Fermer le programme" << endl;
}

void afficherListe(string titre, ListeDesObjetsMessiers& liste) {

	system("cls");

	unsigned compteur = 0;

	cout << "~ "<< titre << " ~" << endl;
	cout << "________________________________________________________________________"  << endl;

	for (int i = 0; i < liste.taille; i++) {
		if (liste.�l�ment[i].estAffiche) {
			cout << ' ' << 'M' << liste.�l�ment[i].nom << '\t'
				<< "Type: " << left << setw(17) << setfill(' ') << liste.�l�ment[i].type << '\t'
				<< "Magnitude: " << liste.�l�ment[i].magnitude << '\t'
				<< "AD: " << right << setw(2) << setfill('0') << liste.�l�ment[i].acensionDroite.heure << ':' << right << setw(2) << setfill('0') << liste.�l�ment[i].acensionDroite.minute << '\t'
				<< "Dec: " << setw(3) << setfill(' ') << liste.�l�ment[i].d�clinaison << endl;
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
			<< 'M' << liste.�l�ment[objet].nom << endl
			<< "Type: " << left << setw(17) << setfill(' ') << liste.�l�ment[objet].type << endl
			<< "Magnitude: " << liste.�l�ment[objet].magnitude << endl
			<< "AD: " << right << setw(2) << setfill('0') << liste.�l�ment[objet].acensionDroite.heure << ':' << right << setw(2) << setfill('0') << liste.�l�ment[objet].acensionDroite.minute << endl
			<< "Dec: " << setw(3) << setfill(' ') << liste.�l�ment[objet].d�clinaison << endl
			<< "--------------------" << endl;
	}
	else
		cout << "Cet objet Messier n'existe pas." << endl;

}

void afficher�toileGuide(�toiles �toile) {
	if (�toile.nom != "") {
		cout << endl << "L'etoile de reperage est " << �toile.nom << " situee dans la constellation " << �toile.constellation << "." << endl
		 	 << "Les coordonees pour cette etoile sont :" << endl
			 << "AD: " << right << setw(2) << setfill('0') << �toile.acensionDroite.heure << ':' << right << setw(2) << setfill('0') << �toile.acensionDroite.minute << endl
			 << "Dec: " << �toile.d�clinaison << endl;
	}
}

void testFacile(ListeDesObjetsMessiers& liste) {
	for (int i = 0; i < liste.taille; i++) {
		if (liste.�l�ment[i].magnitude >= 8)
			liste.�l�ment[i].estAffiche = false;
	}
}

void testVisible(const Tableau3Variables& passagesAuMeridien, ListeDesObjetsMessiers& liste) {
	bool			estValide = 0;
	int				periode = -1,
					heure = 0,
					mois = 0;
	AcensionDroite	acensionsDroiteMin,
					acensionsDroiteMax;
	�toiles			�toileGuide;

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

	acensionsDroiteMin.heure = passagesAuMeridien.�l�ment[periode][mois] - 1.5;
	acensionsDroiteMax.heure = passagesAuMeridien.�l�ment[periode][mois] + 1.5;

	for (int i = 0; i < liste.taille; i++) {
		bool EstDansLaPlageHoraire = (acensionsDroiteMin.heure <= liste.�l�ment[i].acensionDroite.heure) && (liste.�l�ment[i].acensionDroite.heure <= acensionsDroiteMax.heure);
		if (!EstDansLaPlageHoraire)
			liste.�l�ment[i].estAffiche = false;
	}
}

void trouver�toileGuide(ListeDesObjetsMessiers liste, �toiles& �toileGuide) {
	bool estTrouve = false;
	for (int i = 0; i < liste.taille; i++) {
		if (liste.�l�ment[i].estAffiche == true && !estTrouve) {
			if (0 <= liste.�l�ment[i].acensionDroite.heure && liste.�l�ment[i].acensionDroite.heure < 3) {
				�toileGuide.nom = "Mirach";
				�toileGuide.constellation = "Andromeda";
				�toileGuide.d�clinaison = 35;
				�toileGuide.acensionDroite.heure = 1;
				�toileGuide.acensionDroite.minute = 9;
				estTrouve = true;
			}
			else if (3 <= liste.�l�ment[i].acensionDroite.heure && liste.�l�ment[i].acensionDroite.heure < 6) {
				�toileGuide.nom = "Aldebaran";
				�toileGuide.constellation = "Taurus";
				�toileGuide.d�clinaison = 16;
				�toileGuide.acensionDroite.heure = 4;
				�toileGuide.acensionDroite.minute = 35;
				estTrouve = true;
			}
			else if (6 <= liste.�l�ment[i].acensionDroite.heure && liste.�l�ment[i].acensionDroite.heure < 9) {
				�toileGuide.nom = "Pollux";
				�toileGuide.constellation = "Gemini";
				�toileGuide.d�clinaison = 28;
				�toileGuide.acensionDroite.heure = 7;
				�toileGuide.acensionDroite.minute = 45;
				estTrouve = true;
			}
			else if (9 <= liste.�l�ment[i].acensionDroite.heure && liste.�l�ment[i].acensionDroite.heure < 12) {
				�toileGuide.nom = "Algieba";
				�toileGuide.constellation = "Leo";
				�toileGuide.d�clinaison = 19;
				�toileGuide.acensionDroite.heure = 10;
				�toileGuide.acensionDroite.minute = 19;
				estTrouve = true;
			}
			else if (12 <= liste.�l�ment[i].acensionDroite.heure && liste.�l�ment[i].acensionDroite.heure < 15) {
				�toileGuide.nom = "Alkaid";
				�toileGuide.constellation = "Ursa Major";
				�toileGuide.d�clinaison = 49;
				�toileGuide.acensionDroite.heure = 13;
				�toileGuide.acensionDroite.minute = 47;
				estTrouve = true;
			}
			else if (15 <= liste.�l�ment[i].acensionDroite.heure && liste.�l�ment[i].acensionDroite.heure < 18) {
				�toileGuide.nom = "Kornephoros";
				�toileGuide.constellation = "Hercules";
				�toileGuide.d�clinaison = 21;
				�toileGuide.acensionDroite.heure = 16;
				�toileGuide.acensionDroite.minute = 30;
				estTrouve = true;
			}
			else if (18 <= liste.�l�ment[i].acensionDroite.heure && liste.�l�ment[i].acensionDroite.heure < 21) {
				�toileGuide.nom = "Albireo";
				�toileGuide.constellation = "Cygnus";
				�toileGuide.d�clinaison = 27;
				�toileGuide.acensionDroite.heure = 19;
				�toileGuide.acensionDroite.minute = 30;
				estTrouve = true;
			}
			else if (21 <= liste.�l�ment[i].acensionDroite.heure && liste.�l�ment[i].acensionDroite.heure < 24) {
				�toileGuide.nom = "Matar";
				�toileGuide.constellation = "Pegasus";
				�toileGuide.d�clinaison = 30;
				�toileGuide.acensionDroite.heure = 22;
				�toileGuide.acensionDroite.minute = 43;
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
	�toiles �toileGuide;

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
				trouver�toileGuide(objetsMessier, �toileGuide);
				afficherListe("Liste des objets Messiers actuellement visibles", objetsMessier);
				afficher�toileGuide(�toileGuide);
				break;

			case 3 :
				testFacile(objetsMessier);
				afficherListe("Liste des objets Messiers faciles", objetsMessier);
				break;

			case 4 :
				testFacile(objetsMessier);
				testVisible(passagesAuMeridien, objetsMessier);
				trouver�toileGuide(objetsMessier, �toileGuide);
				afficherListe("Liste des objets Messiers faciles et visibles", objetsMessier);
				afficher�toileGuide(�toileGuide);
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