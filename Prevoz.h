#ifndef _Prevoz_h_
#define _Prevoz_h_
#include "Destinacija.h"


class Prevoz{
	Destinacija destinac;
	double cenaKartePovratna;
	double cenaPrevoza;
public:
	Prevoz(Destinacija d, double cenaK) :destinac(d) {
		cenaKartePovratna = cenaK;
		cenaPrevoza = cenaKartePovratna;
	}

	Destinacija dohvDestinac()const { return destinac; }

	double dohvCenuPrevoza()const { return cenaPrevoza; }



	

};

#endif