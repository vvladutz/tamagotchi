//
// Created by vlad on 1/13/2025.
//

#include "Jucator.h"
#include <iostream>
#include <string>
#include "Catelus.h"
#include "Pisicuta.h"

Jucator::Jucator() = default;

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
            std::cout << "alegeti numele!\n";
            std::string nume;
            std::cin >> nume;
            this->animal = new Catelus(nume);
            break;
        }
        case 2: {
            std::cout << "alegeti numele!\n";
            std::string nume;
            std::cin >> nume;
            this->animal = new Pisicuta(nume);
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

bool Jucator::operator==(const Jucator &j) const {
    return j.username == username && j.parola == parola;
}


const std::string& Jucator::getUsername() const {
    return username;
}

Animalut* Jucator::getAnimal() const {
    return animal;
}

Jucator& Jucator::operator=(const Jucator& other) {
    if (this != &other) {
        animal = other.animal;
    }
    return *this;
}

Jucator::Jucator(const Jucator &other) = default;
