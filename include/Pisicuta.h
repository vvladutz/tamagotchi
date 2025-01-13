//
// Created by vlad on 1/13/2025.
//

#ifndef PISICUTA_H
#define PISICUTA_H

#include "Animalut.h"

class Pisicuta : public Animalut {
private:
    std::string nume;
public:
    explicit Pisicuta(std::string nume);
    ~Pisicuta() override;

    Pisicuta(const Pisicuta& other);
    Pisicuta& operator=(const Pisicuta& other);

    void joaca() override;
    void scarpina();
    void hraneste() override;
    void display() override;
    void checkUpgrade();
    void citire() override;
    std::string getNume() override;
    friend std::ostream& operator<<(std::ostream& os, const Pisicuta& p);
    friend std::istream& operator>>(std::istream& in, Pisicuta& p);
};

#endif