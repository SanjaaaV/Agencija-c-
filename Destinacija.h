#ifndef _Destinacija_h_
#define _Destinacija_h_
#include <string>
#include <iostream>
using namespace std;

class Destinacija{
	string nazivDestinacije;
	string opisDestinacija;
	unsigned int ocena=0;
	int broj=0;
public:
	Destinacija(string naziv, string opis) :nazivDestinacije(naziv), opisDestinacija(opis) {}
	
	string dohvNazivDestinacije() { return nazivDestinacije; }
	string dohvOpisDestinacije() { return opisDestinacija; }
	unsigned int  dohvProsecnuOcenuDestinacije() { return ocena; }

	void  oceni(unsigned int k) {
		if (k >= 0 && k <=5 ){
			ocena = (ocena * broj + k) / (broj + 1);
			broj++;
		}
	}

	friend bool operator>(const Destinacija& d1, const Destinacija& d2) {
		if (d1.ocena > d2.ocena) return true;
		return false;
	}


	friend ostream& operator<<(ostream& os, const Destinacija& d) {
		return os << "[" << d.ocena<< "]" << d.nazivDestinacije << "(" << d.opisDestinacija << ")";
	}
};

#endif