//
// Created by vlad on 1/13/2025.
//

#include "Jucator.h"
#include <iostream>

#include "Catelus.h"
#include "Pisicuta.h"

Jucator::Jucator() {}

Jucator::~Jucator() {
    delete animal;
}

void Jucator::setAnimalut() {
    std::cout << "ce animalut doriti?\n";
    std::cout << "1. catelus\n";
    std::cout << "2. pisicuta\n";
    int raspuns;
    std::cin >> raspuns;
    switch (raspuns) {
        case 1: {
            this->animal = new Catelus();
            break;
        }
        case 2: {
            this->animal = new Pisicuta();
            break;
        }
        default: {
            std::cout << "nu am inteles!\n";
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Jucator& j) {
    os << "username: " << j.username << std::endl;
    os << "animalut: " << j.animal->getNume() << std::endl;
    return os;
}

std::istream& operator>>(std::istream& in, Jucator& j) {
    std::cout << "username: \n";
    in >> j.username;
    std::cout << "parola: \n";
    in >> j.parola;
    return in;
}

int Jucator::checkParola(const std::string& check) const {
    return check == parola;
}

void Jucator::citire() {
    std::cin >> *this;
}

std::string Jucator::getUsername() {
    return username;
}

Animalut* Jucator::getAnimal() const {
    return animal;
}
