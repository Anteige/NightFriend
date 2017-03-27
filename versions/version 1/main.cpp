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

#pragma region Énumérations

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
	int				déclinaison = 0;
	double			magnitude = 0.0;
	unsigned		nom = 0;
	string			type = "";
	AcensionDroite  acensionDroite = { 0, 0 };
};

struct ListeDesObjetsMessiers {
	int taille = N_OBJETS_MESSIERS;
	Informations élément[N_OBJETS_MESSIERS];
};

struct Étoiles {
	int				déclinaison = 0;
	string			nom = "",
		constellation = "";
	AcensionDroite	acensionDroite = { 0 , 0 };
};

struct Tableau3Variables {

	int taille1 = N_DE_PERIODE,
		taille2 = N_DE_MOIS;

	double élément[N_DE_PERIODE][N_DE_MOIS];
};

#pragma endregion

void lirefichierbinaire(ListeDesObjetsMessiers& objetsMessier) {

	char chaine[N_MAX_CHAR_TYPE];

	ifstream fichierBinaire("Liste des objets", ios::binary);

	fichierBinaire.seekg(0, ios::beg);

	for (int i = 0; i < N_OBJETS_MESSIERS; i++) {

		fichierBinaire.read((char*)&objetsMessier.élément[i].nom, sizeof(int));

		fichierBinaire.read((char*)&chaine, sizeof(chaine));
		objetsMessier.élément[i].type = chaine;

		fichierBinaire.read((char*)&objetsMessier.élément[i].magnitude, sizeof(double));

		fichierBinaire.read((char*)&objetsMessier.élément[i].déclinaison, sizeof(int));

		fichierBinaire.read((char*)&objetsMessier.élément[i].acensionDroite.heure, sizeof(int));
		fichierBinaire.read((char*)&objetsMessier.élément[i].acensionDroite.minute, sizeof(int));
	}

}

void initialiserTableau3Variables(Tableau3Variables& passagesAuMeridien) {

	for (int i = 0; i < passagesAuMeridien.taille1; i++) {
		passagesAuMeridien.élément[SOIR + i][NOV] = 1.5 + 3 * (i + 0);
		passagesAuMeridien.élément[SOIR + i][DEC] = 1.5 + 3 * (i + 0);
		passagesAuMeridien.élément[SOIR + i][JAN] = 1.5 + 3 * (i + 1);
		passagesAuMeridien.élément[SOIR + i][FEV] = 1.5 + 3 * (i + 2);
		passagesAuMeridien.élément[SOIR + i][MAR] = 1.5 + 3 * (i + 2);
		passagesAuMeridien.élément[SOIR + i][AVR] = 1.5 + 3 * (i + 3);
		passagesAuMeridien.élément[SOIR + i][MAI] = 1.5 + 3 * (i + 4);
		passagesAuMeridien.élément[SOIR + i][JUN] = 1.5 + 3 * (i + 4);
		passagesAuMeridien.élément[SOIR + i][JUL] = 1.5 + 3 * (i + 5);
		passagesAuMeridien.élément[SOIR + i][AOU] = 1.5 + 3 * (i + 6);
		passagesAuMeridien.élément[SOIR + i][SEP] = 1.5 + 3 * (i + 6);
		passagesAuMeridien.élément[SOIR + i][OCT] = 1.5 + 3 * (i + 7);
	}

}

void initialiserEstAfficher(ListeDesObjetsMessiers& liste) {
	for (int i = 0; i < liste.taille; i++)
		liste.élément[i].estAffiche = true;
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
		if (liste.élément[i].estAffiche) {
			cout << ' ' << 'M' << liste.élément[i].nom << '\t'
				<< "Type: " << left << setw(17) << setfill(' ') << liste.élément[i].type << '\t'
				<< "Magnitude: " << liste.élément[i].magnitude << '\t'
				<< "AD: " << right << setw(2) << setfill('0') << liste.élément[i].acensionDroite.heure << ':' << right << setw(2) << setfill('0') << liste.élément[i].acensionDroite.minute << '\t'
				<< "Dec: " << setw(3) << setfill(' ') << liste.élément[i].déclinaison << endl;
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
			<< 'M' << liste.élément[objet].nom << endl
			<< "Type: " << left << setw(17) << setfill(' ') << liste.élément[objet].type << endl
			<< "Magnitude: " << liste.élément[objet].magnitude << endl
			<< "AD: " << right << setw(2) << setfill('0') << liste.élément[objet].acensionDroite.heure << ':' << right << setw(2) << setfill('0') << liste.élément[objet].acensionDroite.minute << endl
			<< "Dec: " << setw(3) << setfill(' ') << liste.élément[objet].déclinaison << endl
			<< "--------------------" << endl;
	}
	else
		cout << "Cet objet Messier n'existe pas." << endl;

}

void afficherÉtoileGuide(Étoiles étoile) {
	if (étoile.nom != "") {
		cout << endl << "L'etoile de reperage est " << étoile.nom << " situee dans la constellation " << étoile.constellation << "." << endl
		 	 << "Les coordonees pour cette etoile sont :" << endl
			 << "AD: " << right << setw(2) << setfill('0') << étoile.acensionDroite.heure << ':' << right << setw(2) << setfill('0') << étoile.acensionDroite.minute << endl
			 << "Dec: " << étoile.déclinaison << endl;
	}
}

void testFacile(ListeDesObjetsMessiers& liste) {
	for (int i = 0; i < liste.taille; i++) {
		if (liste.élément[i].magnitude >= 8)
			liste.élément[i].estAffiche = false;
	}
}

void testVisible(const Tableau3Variables& passagesAuMeridien, ListeDesObjetsMessiers& liste) {
	bool			estValide = 0;
	int				periode = -1,
					heure = 0,
					mois = 0;
	AcensionDroite	acensionsDroiteMin,
					acensionsDroiteMax;
	Étoiles			étoileGuide;

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

	acensionsDroiteMin.heure = passagesAuMeridien.élément[periode][mois] - 1.5;
	acensionsDroiteMax.heure = passagesAuMeridien.élément[periode][mois] + 1.5;

	for (int i = 0; i < liste.taille; i++) {
		bool EstDansLaPlageHoraire = (acensionsDroiteMin.heure <= liste.élément[i].acensionDroite.heure) && (liste.élément[i].acensionDroite.heure <= acensionsDroiteMax.heure);
		if (!EstDansLaPlageHoraire)
			liste.élément[i].estAffiche = false;
	}
}

void trouverÉtoileGuide(ListeDesObjetsMessiers liste, Étoiles& étoileGuide) {
	bool estTrouve = false;
	for (int i = 0; i < liste.taille; i++) {
		if (liste.élément[i].estAffiche == true && !estTrouve) {
			if (0 <= liste.élément[i].acensionDroite.heure && liste.élément[i].acensionDroite.heure < 3) {
				étoileGuide.nom = "Mirach";
				étoileGuide.constellation = "Andromeda";
				étoileGuide.déclinaison = 35;
				étoileGuide.acensionDroite.heure = 1;
				étoileGuide.acensionDroite.minute = 9;
				estTrouve = true;
			}
			else if (3 <= liste.élément[i].acensionDroite.heure && liste.élément[i].acensionDroite.heure < 6) {
				étoileGuide.nom = "Aldebaran";
				étoileGuide.constellation = "Taurus";
				étoileGuide.déclinaison = 16;
				étoileGuide.acensionDroite.heure = 4;
				étoileGuide.acensionDroite.minute = 35;
				estTrouve = true;
			}
			else if (6 <= liste.élément[i].acensionDroite.heure && liste.élément[i].acensionDroite.heure < 9) {
				étoileGuide.nom = "Pollux";
				étoileGuide.constellation = "Gemini";
				étoileGuide.déclinaison = 28;
				étoileGuide.acensionDroite.heure = 7;
				étoileGuide.acensionDroite.minute = 45;
				estTrouve = true;
			}
			else if (9 <= liste.élément[i].acensionDroite.heure && liste.élément[i].acensionDroite.heure < 12) {
				étoileGuide.nom = "Algieba";
				étoileGuide.constellation = "Leo";
				étoileGuide.déclinaison = 19;
				étoileGuide.acensionDroite.heure = 10;
				étoileGuide.acensionDroite.minute = 19;
				estTrouve = true;
			}
			else if (12 <= liste.élément[i].acensionDroite.heure && liste.élément[i].acensionDroite.heure < 15) {
				étoileGuide.nom = "Alkaid";
				étoileGuide.constellation = "Ursa Major";
				étoileGuide.déclinaison = 49;
				étoileGuide.acensionDroite.heure = 13;
				étoileGuide.acensionDroite.minute = 47;
				estTrouve = true;
			}
			else if (15 <= liste.élément[i].acensionDroite.heure && liste.élément[i].acensionDroite.heure < 18) {
				étoileGuide.nom = "Kornephoros";
				étoileGuide.constellation = "Hercules";
				étoileGuide.déclinaison = 21;
				étoileGuide.acensionDroite.heure = 16;
				étoileGuide.acensionDroite.minute = 30;
				estTrouve = true;
			}
			else if (18 <= liste.élément[i].acensionDroite.heure && liste.élément[i].acensionDroite.heure < 21) {
				étoileGuide.nom = "Albireo";
				étoileGuide.constellation = "Cygnus";
				étoileGuide.déclinaison = 27;
				étoileGuide.acensionDroite.heure = 19;
				étoileGuide.acensionDroite.minute = 30;
				estTrouve = true;
			}
			else if (21 <= liste.élément[i].acensionDroite.heure && liste.élément[i].acensionDroite.heure < 24) {
				étoileGuide.nom = "Matar";
				étoileGuide.constellation = "Pegasus";
				étoileGuide.déclinaison = 30;
				étoileGuide.acensionDroite.heure = 22;
				étoileGuide.acensionDroite.minute = 43;
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
	Étoiles étoileGuide;

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
				trouverÉtoileGuide(objetsMessier, étoileGuide);
				afficherListe("Liste des objets Messiers actuellement visibles", objetsMessier);
				afficherÉtoileGuide(étoileGuide);
				break;

			case 3 :
				testFacile(objetsMessier);
				afficherListe("Liste des objets Messiers faciles", objetsMessier);
				break;

			case 4 :
				testFacile(objetsMessier);
				testVisible(passagesAuMeridien, objetsMessier);
				trouverÉtoileGuide(objetsMessier, étoileGuide);
				afficherListe("Liste des objets Messiers faciles et visibles", objetsMessier);
				afficherÉtoileGuide(étoileGuide);
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