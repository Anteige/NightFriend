#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

enum Months { JAN, FEV, MAR, AVR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
enum NightTime { DUSK, NIGHT, MORM };

struct AcensionDroite {
	int heure, minute;
};

struct Informations {
	bool estAffiche = true;
	int declinaison = 0;
	double magnitude = 0.0;
	unsigned nom = 0;
	string type = "";
	AcensionDroite acensionDroite = { 0, 0 };
};

struct ListeDesObjetsMessiers {
	int taille = 110;
	Informations element[110];
};

struct etoiles {
	int				declinaison = 0;
	string			nom = "", constellation = "";
	AcensionDroite	acensionDroite = { 0 , 0 };
};

struct Tableau3Variables {
	int taille1 = 3, taille2 = 12;
	double element[3][12];
};

void lirefichierbinaire(ListeDesObjetsMessiers& objetsMessier) {

	char chaine[20];

	ifstream fichierBinaire("Liste des objets", ios::binary);

	fichierBinaire.seekg(0, ios::beg);

	for (int i = 0; i < objetsMessier.taille; i++) {

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
		passagesAuMeridien.element[DUSK + i][NOV] = 1.5 + 3 * (i + 0);
		passagesAuMeridien.element[DUSK + i][DEC] = 1.5 + 3 * (i + 0);
		passagesAuMeridien.element[DUSK + i][JAN] = 1.5 + 3 * (i + 1);
		passagesAuMeridien.element[DUSK + i][FEV] = 1.5 + 3 * (i + 2);
		passagesAuMeridien.element[DUSK + i][MAR] = 1.5 + 3 * (i + 2);
		passagesAuMeridien.element[DUSK + i][AVR] = 1.5 + 3 * (i + 3);
		passagesAuMeridien.element[DUSK + i][MAY] = 1.5 + 3 * (i + 4);
		passagesAuMeridien.element[DUSK + i][JUN] = 1.5 + 3 * (i + 4);
		passagesAuMeridien.element[DUSK + i][JUL] = 1.5 + 3 * (i + 5);
		passagesAuMeridien.element[DUSK + i][AUG] = 1.5 + 3 * (i + 6);
		passagesAuMeridien.element[DUSK + i][SEP] = 1.5 + 3 * (i + 6);
		passagesAuMeridien.element[DUSK + i][OCT] = 1.5 + 3 * (i + 7);
	}

}

void initialiserEstAfficher(ListeDesObjetsMessiers& liste) {
	for (int i = 0; i < liste.taille; ++i)
		liste.element[i].estAffiche = true;
}

void afficherMenu() {
	cout << "Veuiller faire un choix parmis les suivants : " << endl;
	cout << "1 - Afficher Tout les objets Messiers actuellement visible" << endl;
	cout << "2 - Afficher Tout les objets Messiers de niveau facile actuellement visible" << endl;
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
	int month = date_time->tm_mon, hour = date_time->tm_hour;

	int period = -1;
	if (20 <= hour <= 22)
		period = DUSK;
	else if (23 == hour || 0 <= hour <= 1)
		period = NIGHT;
	else if (2 <= hour <= 4)
		period = MORM;

	AcensionDroite acensionsDroiteMin, acensionsDroiteMax;
	acensionsDroiteMin.heure = passagesAuMeridien.element[period][month] - 1.5;
	acensionsDroiteMax.heure = passagesAuMeridien.element[period][month] + 1.5;

	for (int i = 0; i < liste.taille; i++) {
		bool EstDansLaPlageHoraire = (acensionsDroiteMin.heure <= liste.element[i].acensionDroite.heure) && (liste.element[i].acensionDroite.heure <= acensionsDroiteMax.heure);
		if (!EstDansLaPlageHoraire)
			liste.element[i].estAffiche = false;
	}
}

void trouveretoileGuide(ListeDesObjetsMessiers liste, etoiles& etoileGuide) {
	for (int i = 0; i < liste.taille; ++i) {
		if (liste.element[i].estAffiche) {
			if (0 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 3) {
				etoileGuide.nom = "Mirach";
				etoileGuide.constellation = "Andromeda";
				etoileGuide.declinaison = 35;
				etoileGuide.acensionDroite.heure = 1;
				etoileGuide.acensionDroite.minute = 9;
				break;
			}
			else if (3 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 6) {
				etoileGuide.nom = "Aldebaran";
				etoileGuide.constellation = "Taurus";
				etoileGuide.declinaison = 16;
				etoileGuide.acensionDroite.heure = 4;
				etoileGuide.acensionDroite.minute = 35;
				break;
			}
			else if (6 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 9) {
				etoileGuide.nom = "Pollux";
				etoileGuide.constellation = "Gemini";
				etoileGuide.declinaison = 28;
				etoileGuide.acensionDroite.heure = 7;
				etoileGuide.acensionDroite.minute = 45;
				break;
			}
			else if (9 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 12) {
				etoileGuide.nom = "Algieba";
				etoileGuide.constellation = "Leo";
				etoileGuide.declinaison = 19;
				etoileGuide.acensionDroite.heure = 10;
				etoileGuide.acensionDroite.minute = 19;
				break;
			}
			else if (12 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 15) {
				etoileGuide.nom = "Alkaid";
				etoileGuide.constellation = "Ursa Major";
				etoileGuide.declinaison = 49;
				etoileGuide.acensionDroite.heure = 13;
				etoileGuide.acensionDroite.minute = 47;
				break;
			}
			else if (15 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 18) {
				etoileGuide.nom = "Kornephoros";
				etoileGuide.constellation = "Hercules";
				etoileGuide.declinaison = 21;
				etoileGuide.acensionDroite.heure = 16;
				etoileGuide.acensionDroite.minute = 30;
				break;
			}
			else if (18 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 21) {
				etoileGuide.nom = "Albireo";
				etoileGuide.constellation = "Cygnus";
				etoileGuide.declinaison = 27;
				etoileGuide.acensionDroite.heure = 19;
				etoileGuide.acensionDroite.minute = 30;
				break;
			}
			else if (21 <= liste.element[i].acensionDroite.heure && liste.element[i].acensionDroite.heure < 24) {
				etoileGuide.nom = "Matar";
				etoileGuide.constellation = "Pegasus";
				etoileGuide.declinaison = 30;
				etoileGuide.acensionDroite.heure = 22;
				etoileGuide.acensionDroite.minute = 43;
				break;
			}
		}
	}
}

int MAYn() {

	etoiles etoileGuide;

	ListeDesObjetsMessiers objetsMessier;
	lirefichierbinaire(objetsMessier);

	Tableau3Variables passagesAuMeridien;
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
				testVisible(passagesAuMeridien, objetsMessier);
				trouveretoileGuide(objetsMessier, etoileGuide);
				afficherListe("Liste des objets Messiers faciles et visibles", objetsMessier);
				afficheretoileGuide(etoileGuide);
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
}