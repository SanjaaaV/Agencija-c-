#ifndef _Lista_h_
#define _Lista_h_
#include <exception>
using namespace std;

class GNemaTek :public exception {
public:
	const char* what()const override {
		return "Ne postoji tekuci element!";
	}
};

template<typename T>
class Lista{
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& t, Elem* s = nullptr) {
			pod = t;
			sled = s;
		}
	};

	Elem* prvi, *posl;
	mutable Elem* tek;
	int broj;

	void brisi();
	void kopiraj(const Lista& t);
	void premesti( Lista& t) {
		prvi = t.prvi;
		posl = t.posl;
		tek = t.tek;

		t.prvi =t.posl= nullptr;
	}

public:
	Lista() {
		prvi = posl = tek = nullptr;
		broj = 0;
	}

	Lista(const Lista& l) {
		kopiraj(l);
	}
	Lista(Lista&& l) {
		premesti(l);
	}
	~Lista() { brisi(); }

	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj();
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}


	Lista& dodaj(const T& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		broj++;
		return *this;
	}

	int dohvBroj()const { return broj; }

	T& dohvPod()const {
		if (!tek) throw GNemaTek();
		return tek->pod;
	}

	void naPrvi()const { tek = prvi; }
	void naSledeci()const {
		if (tek) tek = tek->sled;
	}
	bool imaTek()const { return tek != nullptr; }

};

template <typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = nullptr;
}
template <typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = posl = tek = nullptr;
	for (Elem* temp = l.prvi; temp; temp = temp->sled) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(temp->pod);
	}
}





#endif