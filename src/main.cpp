#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const int N_OBJECTS = 110;

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
	double element[3][12];
};

void readObjects(Object* objects) {
	ifstream file("./data/objects", ios::binary);
	file.seekg(0, ios::beg);
	for (int i = 0; i < N_OBJECTS; ++i) {
		file.read((char*)&objects[i].name, sizeof(int));
		char chaine[20];
		file.read((char*)&chaine, sizeof(chaine));
		objects[i].type = chaine;
		file.read((char*)&objects[i].magnitude, sizeof(double));
		file.read((char*)&objects[i].declination, sizeof(int));
		file.read((char*)&objects[i].rightAscension.hour, sizeof(int));
		file.read((char*)&objects[i].rightAscension.minute, sizeof(int));
	}
}

void initialiserTableau3Variables(Tableau3Variables& passagesAuMeridien) {
	for (int i = 0; i < 3; ++i) {
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

void checkVisibility(const Tableau3Variables& passagesAuMeridien, Object* objects) {
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

	RightAscension raMin, raMax;
	raMin.hour = passagesAuMeridien.element[period][month] - 1.5;
	raMax.hour = passagesAuMeridien.element[period][month] + 1.5;

	for (int i = 0; i < N_OBJECTS; ++i) {
		bool isVisible = (raMin.hour <= objects[i].rightAscension.hour) && (objects[i].rightAscension.hour <= raMax.hour);
		if (!isVisible || objects[i].magnitude >= 8)
			objects[i].isVisible = false;
	}
}

void trouveretoileGuide(Object* objects, Star& etoileGuide) {
	for (int i = 0; i < N_OBJECTS; ++i) {
		if (objects[i].isVisible) {
			if (0 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 3) {
				etoileGuide.name = "Mirach";
				etoileGuide.constellation = "Andromeda";
				etoileGuide.declination = 35;
				etoileGuide.rightAscension.hour = 1;
				etoileGuide.rightAscension.minute = 9;
				break;
			}
			else if (3 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 6) {
				etoileGuide.name = "Aldebaran";
				etoileGuide.constellation = "Taurus";
				etoileGuide.declination = 16;
				etoileGuide.rightAscension.hour = 4;
				etoileGuide.rightAscension.minute = 35;
				break;
			}
			else if (6 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 9) {
				etoileGuide.name = "Pollux";
				etoileGuide.constellation = "Gemini";
				etoileGuide.declination = 28;
				etoileGuide.rightAscension.hour = 7;
				etoileGuide.rightAscension.minute = 45;
				break;
			}
			else if (9 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 12) {
				etoileGuide.name = "Algieba";
				etoileGuide.constellation = "Leo";
				etoileGuide.declination = 19;
				etoileGuide.rightAscension.hour = 10;
				etoileGuide.rightAscension.minute = 19;
				break;
			}
			else if (12 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 15) {
				etoileGuide.name = "Alkaid";
				etoileGuide.constellation = "Ursa Major";
				etoileGuide.declination = 49;
				etoileGuide.rightAscension.hour = 13;
				etoileGuide.rightAscension.minute = 47;
				break;
			}
			else if (15 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 18) {
				etoileGuide.name = "Kornephoros";
				etoileGuide.constellation = "Hercules";
				etoileGuide.declination = 21;
				etoileGuide.rightAscension.hour = 16;
				etoileGuide.rightAscension.minute = 30;
				break;
			}
			else if (18 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 21) {
				etoileGuide.name = "Albireo";
				etoileGuide.constellation = "Cygnus";
				etoileGuide.declination = 27;
				etoileGuide.rightAscension.hour = 19;
				etoileGuide.rightAscension.minute = 30;
				break;
			}
			else if (21 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 24) {
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

void showResults(Object* objects) {
	unsigned counter = 0;
	for (int i = 0; i < N_OBJECTS; ++i) {
		if (objects[i].isVisible) {
			cout << 'M' << objects[i].name << '\t' << left << setw(8) <<
			setfill(' ') << objects[i].type << '\t' << "Magnitude: " <<
			objects[i].magnitude << '\t' << "AD: " << right << setw(2) <<
			setfill('0') << objects[i].rightAscension.hour << ':' << right <<
			setw(2) << setfill('0') << objects[i].rightAscension.minute << '\t'
			<< "Dec: " << setw(3) << setfill(' ') << objects[i].declination <<
			endl;
			++counter;
		}
	}
	if (counter)
		cout << endl << "total: " << counter << endl;
	else
		cout << endl << "Aucun objet Messier n'est visible :(" << endl;
}

void showStar(Star etoile) {
	if (etoile.name != "")
		cout << endl << "Pour le calibrage, utilisez " << etoile.name <<
		" dans la constellation " << etoile.constellation << "." << endl
		<< "AD: " << right << setw(2) << setfill('0') <<
		etoile.rightAscension.hour << ':' << right << setw(2) << setfill('0')
		<< etoile.rightAscension.minute << endl << "Dec: " << 
		etoile.declination << endl;
}

int main() {
	Object objects[N_OBJECTS];
	readObjects(objects);
	Tableau3Variables passagesAuMeridien;
	initialiserTableau3Variables(passagesAuMeridien);
	checkVisibility(passagesAuMeridien, objects);
	Star star;
	trouveretoileGuide(objects, star);
	showResults(objects);
	showStar(star);
}