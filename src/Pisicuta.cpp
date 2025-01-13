//
// Created by vlad on 1/13/2025.
//

#include "Pisicuta.h"
#include <iostream>
#include <string>

Pisicuta::Pisicuta() : Animalut(0, 10, 1) {}
Pisicuta::~Pisicuta() = default;

void Pisicuta::checkUpgrade() {
    if (fericire > 100) {
        nivel++;
        fericire -= 100;
    }
}


void Pisicuta::hraneste() {
    fericire += 7 * 1/nivel;
    std::cout << "catelusul " << nume << " a fost hranit! (+10 fericire)\n";
    checkUpgrade();
}

void Pisicuta::joaca() {
    fericire += 10 * 1/nivel;
    std::cout << "catelusul " << nume << " se joaca! (+15 fericire)\n";
    checkUpgrade();
}

std::ostream& operator<<(std::ostream& os, const Pisicuta& p) {
    os << "catelusul " << p.nume << std::endl;
    os << "varsta: " << p.varsta << std::endl;
    os << "fericire: " << p.fericire << std::endl;
    os << "nivel: " << p.nivel << std::endl;
    return os;
}

std::istream& operator>>(std::istream& in, Pisicuta& p) {
    std::getline(in, p.nume);
    return in;
}

void Pisicuta::citire() {
    std::cin >> *this;
}

std::string Pisicuta::getNume() {
    return nume;
}

void Pisicuta::display() {
    std::cout << *this;
}
