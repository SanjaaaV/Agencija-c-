#ifndef _Smestaj_h_
#define _Smestaj_h_
#include"Destinacija.h"

enum Tip{HOTEL, APARTMAN};

class Smestaj{
	Destinacija  destinacija;
	string nazivSmestaja;
	int brojZvezdica;
	double cenaPoDanu;
	Tip tip;
	static string tipSmestaja[];

public:
	Smestaj( Destinacija& d, Tip tip, string naziv,int brojZ, double cena):destinacija(d){
		nazivSmestaja = naziv;
		brojZvezdica = brojZ;
		cenaPoDanu = cena;
		this->tip = tip;
	}

	Destinacija dohvDestinaciju()const { return destinacija; }
	string dohvNazivSmestaja()const { return nazivSmestaja; }
	int dohvBrojZvezdica()const { return brojZvezdica; }
	double dohvCenuPoDanu()const { return cenaPoDanu; }
	Tip dohvTipSmestaja()const { return tip; }

	friend ostream& operator<<(ostream& os, const Smestaj& s) {
		 os << s.tipSmestaja[s.tip] << " " << s.dohvNazivSmestaja();
		 for (int i = 0; i < s.dohvBrojZvezdica(); i++) {
			 os << "*";
		 }
		 return os;
	}


};

#endif