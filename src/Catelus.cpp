//
// Created by vlad on 1/13/2025.
//

#include "Catelus.h"
#include <iostream>
#include <string>

Catelus::Catelus() : Animalut(0, 0, 1) {}
Catelus::~Catelus() = default;

void Catelus::checkUpgrade() {
    if (fericire > 100)
        nivel++;
}


void Catelus::hraneste() {
    fericire += 10 * 1/nivel;
    std::cout << "catelusul " << nume << " a fost hranit! (+10 fericire)\n";
    checkUpgrade();
}

void Catelus::joaca() {
    fericire += 15 * 1/nivel;
    std::cout << "catelusul " << nume << " se joaca! (+15 fericire)\n";
    checkUpgrade();
}

std::ostream& operator<<(std::ostream& os, const Catelus& c) {
    os << "catelusul " << c.nume << std::endl;
    os << "varsta: " << c.varsta << std::endl;
    os << "fericire: " << c.fericire << std::endl;
    os << "nivel: " << c.nivel << std::endl;
    return os;
}

std::istream& operator>>(std::istream& in, Catelus& c) {
    std::getline(in, c.nume);
    return in;
}

