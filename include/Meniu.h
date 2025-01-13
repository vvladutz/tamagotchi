//
// Created by vlad on 1/13/2025.
//

#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include "Jucator.h"

class Meniu {
private:
    std::vector<Jucator> jucatori;
    Meniu();
    ~Meniu();
public:
    static Meniu& getInstance();

    bool run();

    void creeaza();

    void checkForDuplicates();
};

#endif //MENIU_H
