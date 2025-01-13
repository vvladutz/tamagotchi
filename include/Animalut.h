//
// Created by vlad on 1/13/2025.
//

#ifndef ANIMALUT_H
#define ANIMALUT_H

#include <string>

class Animalut {
protected:
    int varsta;
    int fericire;
    int nivel;
public:
    Animalut(int varsta, int fericire, int nivel);
    virtual ~Animalut();

    Animalut(const Animalut& other);

    Animalut& operator=(const Animalut& other);
    virtual void joaca() = 0;
    virtual void hraneste() = 0;
    virtual void display() = 0;
    virtual void citire() = 0;
    virtual std::string getNume() = 0;
};

#endif //ANIMALUT_H
