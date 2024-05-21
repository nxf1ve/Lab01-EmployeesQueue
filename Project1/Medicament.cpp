#include "Medicament.h"
#include <iostream>
#include <string>

using namespace std;

string Medicament::getNameMedicament() const{
	return nameMedicament;
}

long long Medicament::getPrice() const {
	return price;
}

ostream& operator << (std::ostream& os, const Medicament& med)
{
	return os << med.getNameMedicament() << " " << med.getPrice();
}