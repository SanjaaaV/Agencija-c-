#include "Datum.h"
#include <cmath>

int operator-(const Datum& d1, const Datum& d2){
	
	return abs(d1.brojdana() - d2.brojdana());
}
