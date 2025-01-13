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

    friend std::ostream& operator<<(std::ostream& os, const Jucator& j);
    friend std::istream& operator>>(std::istream& in, Jucator& j);

    Jucator(const Jucator& other);
    Jucator& operator=(const Jucator& other);

    bool operator==(const Jucator& j) const;
    void citire();
    void setAnimalut();
    [[nodiscard]] const std::string& getUsername() const;
    [[nodiscard]] Animalut* getAnimal() const;
    [[nodiscard]] int checkParola(const std::string& check) const;
};

#endif //JUCATOR_H
