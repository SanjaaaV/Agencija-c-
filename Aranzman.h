#ifndef _Aranzman_h_
#define _Aranzman_h_
#include "Destinacija.h"
#include "Datum.h"
#include "Smestaj.h"
#include "Prevoz.h"

class GNemaPrevozaSmestaja :public exception {
public:
	const char* what()const override {
		return "Nije dodat smestaj ili prevoz!";
	}
};


class Aranzman{
	Destinacija destinacija;
	Datum datumP;
	Datum datumK;
	Smestaj* smestaj;
	Prevoz* prevoz;
public:
	Aranzman(const Destinacija& d, const Datum& p, const Datum& k):destinacija(d), datumP(p),datumK(k){
		smestaj = nullptr;
		prevoz = nullptr;
	}

	Aranzman& dodajSmestaj( Smestaj* s) {
		smestaj = s;
		return *this;
	}
	Aranzman& dodajPrevoz( Prevoz* p) {
		prevoz = p;
		return *this;
	}



	Destinacija dohvDestinac()const { return destinacija; }
	Datum dohvDPocetak()const { return datumP; }
	Datum dohvDKraj()const { return datumK; }

	int trejanjeAranzmana(const Datum& pocetak, const Datum& kraj)const {
		return kraj - pocetak;
	}
	double cenaAranzmana()const {
		if (this->prevoz == nullptr || this->smestaj == nullptr) throw GNemaPrevozaSmestaja();
		return { prevoz->dohvCenuPrevoza() + smestaj->dohvCenuPoDanu() * trejanjeAranzmana(dohvDPocetak(), dohvDKraj()) };
	}


	friend ostream& operator<<(ostream& os, const Aranzman& a) {
		os << a.dohvDestinac() << endl;
		os << *(a.smestaj) << endl;
		os << a.cenaAranzmana();
		return os;
	}

};

#endif