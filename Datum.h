#ifndef _Datum_h_
#define _Datum_h_
#include <iostream>

using namespace std;

class Gneispravandatum :public exception
{
public:
	Gneispravandatum() :exception("Datum nije validan!") {}
};



class Datum {
	int dan, mesec, godina;


	bool dobarDatum(int d, int m, int g) {

		if (d > 0) {
			switch (m) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if (d <= 31) return true;
				else break;

			case 4: case 6:  case 9: case 11:
				if (d <= 30) return true;
				else break;

			case 2:
				if (!(g % 4) && ((g % 100) || !(g % 400))) {
					if (d <= 29) return true;
				}
				else if (d <= 28) return true;

				break;
			}
		}

		return false;

	}


	int brojdana() const {
		return ((godina - 1) * 365 + daniuTekucojG(mesec, dan) + BrPrestupnihGodina(godina));
	}
	
	 static int daniuTekucojG(int m, int dan) {
		int d = 0;
		switch (m) {
		case 12:d += 30;
		case 11:d += 31;
		case 10:d += 30;
		case 9:d += 31;
		case 8:d += 31;
		case 7:d +=30;
		case 6:d += 31;
		case 5:d += 30;
		case 4:d +=31;
		case 3:d += 28;
		case 2:d +=31;
		case 1:d += dan; break;
		}
		return d;
	}
	static int BrPrestupnihGodina(int g) {
		return g / 4 - g / 100 + g / 400;
	}

public:
	Datum(int d = 1, int mes = 1, int god = 2021) {
		if (dobarDatum(d, mes, god)) {
			dan = d;
			mesec = mes;
			godina = god;
		}
		else throw Gneispravandatum();
	}

	int dohvDan()const { return dan; }
	int dohvMesec()const { return mesec; }
	int dohvGodinu()const { return godina; }

	friend int operator-(const Datum& d1, const Datum& d2);

	friend ostream& operator<<(ostream& os, const Datum& d) {
		return os << d.dan << "." << d.mesec << "." << d.godina;
	}

	

};
#endif