//
// Created by vlad on 1/13/2025.
//

#ifndef ANIMALUT_H
#define ANIMALUT_H

class Animalut {
protected:
    int varsta;
    int fericire;
    int nivel;
public:
    Animalut(int varsta, int fericire, int nivel);
    virtual ~Animalut();

    virtual void joaca() = 0;
    virtual void hraneste() = 0;
};

#endif //ANIMALUT_H
