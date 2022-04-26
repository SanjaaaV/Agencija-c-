#include "Aranzman.h"
#include "Agencija.h"


int main() {
	try {
		Datum d1(5,4, 2021);
		Datum d2(28, 12, 2020);
		cout << d1 - d2 << endl << endl;

		Destinacija dest1("Zlatibor", "zimovanje");

		Prevoz p1(dest1, 3500);

		Smestaj smes1(dest1, HOTEL, "Bor", 4, 1500);

		dest1.oceni(2);
		dest1.oceni(5);
		cout << dest1.dohvProsecnuOcenuDestinacije() << endl << endl;

		Aranzman   a1(dest1, d1, d2);
		a1.dodajSmestaj(&smes1);
		a1.dodajPrevoz(&p1);
		cout << a1<< endl<<endl;

		Agencija a("Travel");
		a.dodaj(&a1);
		cout << a << endl;



	}
	catch (exception e) {
		cout << e.what();
	}
	
	


}