#pragma once
#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <string>

using namespace std;
class Medicament {
private:
    long long price;
    std::string nameMedicament;
public:
    Medicament() : price(0), nameMedicament("") {}
    Medicament(long long pri, const std::string& name) : nameMedicament(name), price(pri) {}
    void printMed() const;
    string getNameMedicament() const;
    long long getPrice() const;


};

std::ostream& operator << (std::ostream& os, const Medicament& med);

#endif

 