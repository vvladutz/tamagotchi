//
// Created by vlad on 1/13/2025.
//

#ifndef CATELUS_H
#define CATELUS_H

#include <string>

#include "Animalut.h"

class Catelus : public Animalut {
private:
    std::string nume;
public:
    Catelus();
    ~Catelus() override;

    void joaca() override;
    void hraneste() override;
};

#endif //CATELUS_H
