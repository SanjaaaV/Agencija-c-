#ifndef _Agencija_h_
#define _Agencija_h_


#include "Lista.h"
#include "Aranzman.h"



class Agencija:public Lista<Aranzman*>{
	string nazivAgencije;
public:
	Agencija(string naziv):Lista<Aranzman*>(),nazivAgencije(naziv){}
	Agencija(const Agencija& a) = delete;
	Agencija& operator=(const Agencija& a) = delete;

	friend ostream& operator<<(ostream& os, const Agencija& a) {
		 os << a.nazivAgencije << endl;
		 for (a.naPrvi(); a.imaTek(); a.naSledeci()) {
			 os << *a.dohvPod() << endl;
		 }
		 return os;
	}
};

#endif