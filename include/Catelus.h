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
    void checkUpgrade();
    friend std::ostream& operator<<(std::ostream& os, const Catelus& c);
    friend std::istream& operator>>(std::istream& in, Catelus& c);
};

#endif //CATELUS_H
