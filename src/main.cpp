#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const int N_OBJECTS = 110, N_NIGHT_STATES = 3, N_MONTHS = 12;

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

void readFromDisk(Object* objects) {
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

void printStar(Star etoile) {
	if (etoile.name != "")
		cout << endl << "Pour le calibrage, utilisez " << etoile.name <<
		" dans la constellation " << etoile.constellation << "." << endl
		<< "AD: " << right << setw(2) << setfill('0') <<
		etoile.rightAscension.hour << ':' << right << setw(2) << setfill('0')
		<< etoile.rightAscension.minute << endl << "Dec: " << 
		etoile.declination << endl << endl;
}

void findStar(Object* objects) {
	Star star;
	for (int i = 0; i < N_OBJECTS; ++i) {
		if (objects[i].isVisible) {
			if (0 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 3) {
				star.name = "Mirach";
				star.constellation = "Andromeda";
				star.declination = 35;
				star.rightAscension.hour = 1;
				star.rightAscension.minute = 9;
				break;
			}
			else if (3 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 6) {
				star.name = "Aldebaran";
				star.constellation = "Taurus";
				star.declination = 16;
				star.rightAscension.hour = 4;
				star.rightAscension.minute = 35;
				break;
			}
			else if (6 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 9) {
				star.name = "Pollux";
				star.constellation = "Gemini";
				star.declination = 28;
				star.rightAscension.hour = 7;
				star.rightAscension.minute = 45;
				break;
			}
			else if (9 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 12) {
				star.name = "Algieba";
				star.constellation = "Leo";
				star.declination = 19;
				star.rightAscension.hour = 10;
				star.rightAscension.minute = 19;
				break;
			}
			else if (12 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 15) {
				star.name = "Alkaid";
				star.constellation = "Ursa Major";
				star.declination = 49;
				star.rightAscension.hour = 13;
				star.rightAscension.minute = 47;
				break;
			}
			else if (15 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 18) {
				star.name = "Kornephoros";
				star.constellation = "Hercules";
				star.declination = 21;
				star.rightAscension.hour = 16;
				star.rightAscension.minute = 30;
				break;
			}
			else if (18 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 21) {
				star.name = "Albireo";
				star.constellation = "Cygnus";
				star.declination = 27;
				star.rightAscension.hour = 19;
				star.rightAscension.minute = 30;
				break;
			}
			else if (21 <= objects[i].rightAscension.hour && objects[i].rightAscension.hour < 24) {
				star.name = "Matar";
				star.constellation = "Pegasus";
				star.declination = 30;
				star.rightAscension.hour = 22;
				star.rightAscension.minute = 43;
				break;
			}
		}
	}
	printStar(star);
}

void constructMatrix(double meridian[N_NIGHT_STATES][N_MONTHS]) {
	for (int i = 0; i < N_NIGHT_STATES; ++i) {
		meridian[DUSK + i][NOV] = 1.5 + 3 * (i + 0);
		meridian[DUSK + i][DEC] = 1.5 + 3 * (i + 0);
		meridian[DUSK + i][JAN] = 1.5 + 3 * (i + 1);
		meridian[DUSK + i][FEV] = 1.5 + 3 * (i + 2);
		meridian[DUSK + i][MAR] = 1.5 + 3 * (i + 2);
		meridian[DUSK + i][AVR] = 1.5 + 3 * (i + 3);
		meridian[DUSK + i][MAY] = 1.5 + 3 * (i + 4);
		meridian[DUSK + i][JUN] = 1.5 + 3 * (i + 4);
		meridian[DUSK + i][JUL] = 1.5 + 3 * (i + 5);
		meridian[DUSK + i][AUG] = 1.5 + 3 * (i + 6);
		meridian[DUSK + i][SEP] = 1.5 + 3 * (i + 6);
		meridian[DUSK + i][OCT] = 1.5 + 3 * (i + 7);
	}
}

void printResults(Object* objects) {
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

void checkVisibility(const double meridian[N_NIGHT_STATES][N_MONTHS], Object* objects) {
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
	raMin.hour = meridian[period][month] - 1.5;
	raMax.hour = meridian[period][month] + 1.5;

	for (int i = 0; i < N_OBJECTS; ++i) {
		bool isVisible = (raMin.hour <= objects[i].rightAscension.hour) && (objects[i].rightAscension.hour <= raMax.hour);
		if (!isVisible || objects[i].magnitude >= 8)
			objects[i].isVisible = false;
	}
	printResults(objects);
}

int main() {
	Object objects[N_OBJECTS];
	readFromDisk(objects);
	findStar(objects);
	double meridians[N_NIGHT_STATES][N_MONTHS];
	constructMatrix(meridians);
	checkVisibility(meridians, objects);
}