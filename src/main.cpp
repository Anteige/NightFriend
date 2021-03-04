#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

enum Months { JAN, FEV, MAR, AVR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
enum NightTime { DUSK, NIGHT, MORM };

struct RightAscension {
	int hour, minute;
};

struct Coordinate {
	int declination = 0;
	RightAscension rightAscension = {0, 0};
};

struct Object : Coordinate {
	bool isVisible = true;
	double magnitude = 0.0;
	unsigned name = 0;
	string type = "";

};

struct Star : Coordinate {
	string name = "", constellation = "";
};

struct Tableau3Variables {
	int taille1 = 3, taille2 = 12;
	double element[3][12];
};

void readObjects(Object* object) {
	ifstream file("./data/objects", ios::binary);
	file.seekg(0, ios::beg);
	for (int i = 0; i < 110; ++i) {
		file.read((char*)&object[i].name, sizeof(int));
		char chaine[20];
		file.read((char*)&chaine, sizeof(chaine));
		object[i].type = chaine;
		file.read((char*)&object[i].magnitude, sizeof(double));
		file.read((char*)&object[i].declination, sizeof(int));
		file.read((char*)&object[i].rightAscension.hour, sizeof(int));
		file.read((char*)&object[i].rightAscension.minute, sizeof(int));
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

void afficherListe(Object* liste) {
	unsigned counter = 0;

	cout << "~ "<< "Liste des objets Messiers faciles et visibles" << " ~" << endl;
	cout << "________________________________________________________________________"  << endl;

	for (int i = 0; i < 110; i++) {
		if (liste[i].isVisible) {
			cout << ' ' << 'M' << liste[i].name << '\t'
				<< "Type: " << left << setw(17) << setfill(' ') << liste[i].type << '\t'
				<< "Magnitude: " << liste[i].magnitude << '\t'
				<< "AD: " << right << setw(2) << setfill('0') << liste[i].rightAscension.hour << ':' << right << setw(2) << setfill('0') << liste[i].rightAscension.minute << '\t'
				<< "Dec: " << setw(3) << setfill(' ') << liste[i].declination << endl;
			++counter;
		}
	}

		if (counter != 0)
			cout << endl << "total: " << counter << endl;
		else
			cout << endl << "Aucun objet Messier n'est visible :(" << endl;
		cout << "________________________________________________________________________" << endl;
}

void afficheretoileGuide(Star etoile) {
	if (etoile.name != "") {
		cout << endl << "L'etoile de reperage est " << etoile.name << " situee dans la constellation " << etoile.constellation << "." << endl
		 	 << "Les coordonees pour cette etoile sont :" << endl
			 << "AD: " << right << setw(2) << setfill('0') << etoile.rightAscension.hour << ':' << right << setw(2) << setfill('0') << etoile.rightAscension.minute << endl
			 << "Dec: " << etoile.declination << endl;
	}
}

void testVisible(const Tableau3Variables& passagesAuMeridien, Object* liste) {
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

	RightAscension acensionsDroiteMin, acensionsDroiteMax;
	acensionsDroiteMin.hour = passagesAuMeridien.element[period][month] - 1.5;
	acensionsDroiteMax.hour = passagesAuMeridien.element[period][month] + 1.5;

	for (int i = 0; i < 110; ++i) {
		bool EstDansLaPlageHoraire = (acensionsDroiteMin.hour <= liste[i].rightAscension.hour) && (liste[i].rightAscension.hour <= acensionsDroiteMax.hour);
		if (!EstDansLaPlageHoraire || liste[i].magnitude >= 8)
			liste[i].isVisible = false;
	}
}

void trouveretoileGuide(Object* liste, Star& etoileGuide) {
	for (int i = 0; i < 110; ++i) {
		if (liste[i].isVisible) {
			if (0 <= liste[i].rightAscension.hour && liste[i].rightAscension.hour < 3) {
				etoileGuide.name = "Mirach";
				etoileGuide.constellation = "Andromeda";
				etoileGuide.declination = 35;
				etoileGuide.rightAscension.hour = 1;
				etoileGuide.rightAscension.minute = 9;
				break;
			}
			else if (3 <= liste[i].rightAscension.hour && liste[i].rightAscension.hour < 6) {
				etoileGuide.name = "Aldebaran";
				etoileGuide.constellation = "Taurus";
				etoileGuide.declination = 16;
				etoileGuide.rightAscension.hour = 4;
				etoileGuide.rightAscension.minute = 35;
				break;
			}
			else if (6 <= liste[i].rightAscension.hour && liste[i].rightAscension.hour < 9) {
				etoileGuide.name = "Pollux";
				etoileGuide.constellation = "Gemini";
				etoileGuide.declination = 28;
				etoileGuide.rightAscension.hour = 7;
				etoileGuide.rightAscension.minute = 45;
				break;
			}
			else if (9 <= liste[i].rightAscension.hour && liste[i].rightAscension.hour < 12) {
				etoileGuide.name = "Algieba";
				etoileGuide.constellation = "Leo";
				etoileGuide.declination = 19;
				etoileGuide.rightAscension.hour = 10;
				etoileGuide.rightAscension.minute = 19;
				break;
			}
			else if (12 <= liste[i].rightAscension.hour && liste[i].rightAscension.hour < 15) {
				etoileGuide.name = "Alkaid";
				etoileGuide.constellation = "Ursa Major";
				etoileGuide.declination = 49;
				etoileGuide.rightAscension.hour = 13;
				etoileGuide.rightAscension.minute = 47;
				break;
			}
			else if (15 <= liste[i].rightAscension.hour && liste[i].rightAscension.hour < 18) {
				etoileGuide.name = "Kornephoros";
				etoileGuide.constellation = "Hercules";
				etoileGuide.declination = 21;
				etoileGuide.rightAscension.hour = 16;
				etoileGuide.rightAscension.minute = 30;
				break;
			}
			else if (18 <= liste[i].rightAscension.hour && liste[i].rightAscension.hour < 21) {
				etoileGuide.name = "Albireo";
				etoileGuide.constellation = "Cygnus";
				etoileGuide.declination = 27;
				etoileGuide.rightAscension.hour = 19;
				etoileGuide.rightAscension.minute = 30;
				break;
			}
			else if (21 <= liste[i].rightAscension.hour && liste[i].rightAscension.hour < 24) {
				etoileGuide.name = "Matar";
				etoileGuide.constellation = "Pegasus";
				etoileGuide.declination = 30;
				etoileGuide.rightAscension.hour = 22;
				etoileGuide.rightAscension.minute = 43;
				break;
			}
		}
	}
}

int main() {
	Object objects[110];
	readObjects(objects);
	Tableau3Variables passagesAuMeridien;
	initialiserTableau3Variables(passagesAuMeridien);
	testVisible(passagesAuMeridien, objects);
	Star etoileGuide;
	trouveretoileGuide(objects, etoileGuide);
	afficherListe(objects);
	afficheretoileGuide(etoileGuide);
}