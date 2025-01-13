//
// Created by vlad on 1/13/2025.
//

#include "Catelus.h"
#include <iostream>
#include <string>

Catelus::Catelus(std::string nume) : Animalut(0, 20, 1), nume{std::move(nume)} {}
Catelus::~Catelus() = default;

void Catelus::checkUpgrade() {
    if (fericire > 100) {
        nivel++;
        fericire -= 100;
    }
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

void Catelus::citire() {
    std::cin >> *this;
}

std::string Catelus::getNume() {
    return nume;
}

void Catelus::display() {
    std::cout << *this;
}

Catelus& Catelus::operator=(const Catelus &other) {
    if (this != &other) {
        Animalut::operator=(other);
        nume = other.nume;
    }
    return *this;
}

Catelus::Catelus(const Catelus &other) = default;
