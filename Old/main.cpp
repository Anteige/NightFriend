/*
FICHIER : ObjetsMessiers.cpp
AUTEUR : Antoine Gaulin
DATE : 30/10/2016 - MAJ 10/12/2016
DESCRIPTION : Ce programme permet de manipuler une liste des objets Messiers
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>


using namespace std;

static const int N_OBJETS_MESSIERS = 110, N_DE_MOIS = 12, N_DE_PERIODE = 3, N_MAX_CHAR_TYPE = 20;

enum Mois { JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC };

enum Moments { SOIR, MINUIT, MATIN };

struct AcensionDroite {
	int heure,
		minute;
};

struct Informations {
	bool			estAffiche = true;
	int				declinaison = 0;
	double			magnitude = 0.0;
	unsigned		nom = 0;
	string			type = "";
	AcensionDroite  acensionDroite = { 0, 0 };
};

struct ListeDesObjetsMessiers {
	int taille = N_OBJETS_MESSIERS;
	Informations element[N_OBJETS_MESSIERS];
};

struct etoiles {
	int				declinaison = 0;
	string			nom = "",
		constellation = "";
	AcensionDroite	acensionDroite = { 0 , 0 };
};

struct Tableau3Variables {

	int taille1 = N_DE_PERIODE,
		taille2 = N_DE_MOIS;

	double element[N_DE_PERIODE][N_DE_MOIS];
};

void lirefichierbinaire(ListeDesObjetsMessiers& objetsMessier) {

	char chaine[N_MAX_CHAR_TYPE];

	ifstream fichierBinaire("Liste des objets", ios::binary);

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

void initialiserTableau3Variables(Tableau3Variables& passagesAuMeridien) {

	for (int i = 0; i < passagesAuMeridien.taille1; ++i) {
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

void initialiserEstAfficher(ListeDesObjetsMessiers& liste) {
	for (int i = 0; i < liste.taille; ++i)
		liste.element[i].estAffiche = true;
}

void afficherMenu() {
	cout << "Veuiller faire un choix parmis les suivants : " << endl;
	cout << "1 - Afficher Tout les objets Messiers actuellement visible" << endl;
	cout << "2 - Afficher Tout les objets Messiers de niveau facile" << endl;
	cout << "3 - Afficher Tout les objets Messiers de niveau facile actuellement visible" << endl;
	cout << "4 - Afficher les informations d'un objet Messier specifique" << endl;
	cout << "5 - Afficher le menu" << endl;
	cout << "0 - Fermer le programme" << endl;
}

void afficherListe(string titre, ListeDesObjetsMessiers& liste) {
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

void afficheretoileGuide(etoiles etoile) {
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

	time_t now = time(0);
   	struct tm * date_time = localtime(&now);

	int mois = date_time->tm_mon;
	int heure = date_time->tm_hour;

	int periode = -1;
	if (20 <= heure <= 22)
		periode = SOIR;
	else if (23 == heure || 0 <= heure <= 1)
		periode = MINUIT;
	else if (2 <= heure <= 4)
		periode = MATIN;

	AcensionDroite acensionsDroiteMin, acensionsDroiteMax;
	acensionsDroiteMin.heure = passagesAuMeridien.element[periode][mois] - 1.5;
	acensionsDroiteMax.heure = passagesAuMeridien.element[periode][mois] + 1.5;

	for (int i = 0; i < liste.taille; i++) {
		bool EstDansLaPlageHoraire = (acensionsDroiteMin.heure <= liste.element[i].acensionDroite.heure) && (liste.element[i].acensionDroite.heure <= acensionsDroiteMax.heure);
		if (!EstDansLaPlageHoraire)
			liste.element[i].estAffiche = false;
	}
}

void trouveretoileGuide(ListeDesObjetsMessiers liste, etoiles& etoileGuide) {
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

	ListeDesObjetsMessiers objetsMessier;
	Tableau3Variables passagesAuMeridien;
	etoiles etoileGuide;

	lirefichierbinaire(objetsMessier);

	initialiserTableau3Variables(passagesAuMeridien);

	cout << "Bienvenue dans le Companion du ciel" << endl << endl;

	testVisible(passagesAuMeridien, objetsMessier);

	afficherMenu();
	
	int choix = 0;
	cin >> choix;

	if (cin.fail())
		choix = -1;

	while (choix != 0) {

		switch (choix) {
			case 1 :
				testVisible(passagesAuMeridien, objetsMessier);
				trouveretoileGuide(objetsMessier, etoileGuide);
				afficherListe("Liste des objets Messiers actuellement visibles", objetsMessier);
				afficheretoileGuide(etoileGuide);
				break;

			case 2 :
				testFacile(objetsMessier);
				afficherListe("Liste des objets Messiers faciles", objetsMessier);
				break;

			case 3 :
				testFacile(objetsMessier);
				testVisible(passagesAuMeridien, objetsMessier);
				trouveretoileGuide(objetsMessier, etoileGuide);
				afficherListe("Liste des objets Messiers faciles et visibles", objetsMessier);
				afficheretoileGuide(etoileGuide);
				break;

			case 4 :
				afficherObjet(objetsMessier);
				break;

			case 5 :
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
		afficherMenu();
	}

	cout << "Bonne Observations!" << endl;
}