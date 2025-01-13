//
// Created by vlad on 1/13/2025.
//

#ifndef JUCATOR_H
#define JUCATOR_H

#include <Animalut.h>
#include <string>

class Jucator {
private:
    std::string username;
    Animalut* animal = nullptr;
    std::string parola;
public:
    Jucator();
    ~Jucator();

    friend std::ostream& operator<<(std::ostream& os, const Jucator& jucator);
    friend std::istream& operator>>(std::istream& is, Jucator& jucator);

    void citire();
    void setAnimalut();
    std::string getUsername();
    [[nodiscard]] Animalut* getAnimal() const;
    int checkParola(const std::string& check) const;
};

#endif //JUCATOR_H
