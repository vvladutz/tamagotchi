//
// Created by vlad on 1/13/2025.
//

#include "Animalut.h"

Animalut::Animalut(int varsta, int fericire, int nivel) : varsta{varsta}, fericire{fericire}, nivel{nivel} {}

Animalut::~Animalut() = default;

Animalut::Animalut(const Animalut& other) = default;

Animalut& Animalut::operator=(const Animalut& other) {
    if (this != &other) {
        varsta = other.varsta;
        fericire = other.fericire;
        nivel = other.nivel;
    }
    return *this;
}