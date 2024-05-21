#include "Medicament.h"
#include <iostream>
#include <string>

using namespace std;

//Medicament::Medicament(long long price, string name) {
//	this->price = price;
//	this->nameMedicament = name;
//}

void Medicament::printMed() const 
{
	cout << "(Название: " << nameMedicament << ", Цена: " << price << ")";
}

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