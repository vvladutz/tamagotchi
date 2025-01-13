//
// Created by vlad on 1/13/2025.
//

#include "Pisicuta.h"
#include <iostream>
#include <string>
#include <utility>

Pisicuta::Pisicuta(std::string nume) : Animalut(0, 10, 1), nume{std::move(nume)} {}
Pisicuta::~Pisicuta() = default;

void Pisicuta::checkUpgrade() {
    if (fericire > 100) {
        nivel++;
        fericire -= 100;
    }
}


void Pisicuta::hraneste() {
    fericire += 7 * 1/nivel;
    std::cout << "pisicuta " << nume << " a fost hranit! (+10 fericire)\n";
    checkUpgrade();
}

void Pisicuta::joaca() {
    fericire += 10 * 1/nivel;
    std::cout << "pisicuta  " << nume << " se joaca! (+15 fericire)\n";
    checkUpgrade();
}

std::ostream& operator<<(std::ostream& os, const Pisicuta& p) {
    os << "pisicuta " << p.nume << std::endl;
    os << "varsta: " << p.varsta << std::endl;
    os << "fericire: " << p.fericire << std::endl;
    os << "nivel: " << p.nivel << std::endl;
    return os;
}

std::istream& operator>>(std::istream& in, Pisicuta& p) {
    std::cout << "introduceti numele pisicutei: \n";
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

Pisicuta& Pisicuta::operator=(const Pisicuta &other) {
    if (this != &other) {
        Animalut::operator=(other);
        nume = other.nume;
    }
    return *this;
}

Pisicuta::Pisicuta(const Pisicuta &other) = default;