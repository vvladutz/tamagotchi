//
// Created by vlad on 1/13/2025.
//

#include "Meniu.h"
#include <iostream>
#include <limits>

#include "WrongInput.h"

Meniu::Meniu() = default;
Meniu::~Meniu() {jucatori.clear();};

Meniu& Meniu::getInstance() {
    static Meniu instance;
    return instance;
}

bool Meniu::run() {
    while (true) {
        int raspuns;
        std::cout << "alegeti: \n";
        std::cout << "1. creeaza un jucator\n";
        std::cout << "2. alege un jucator\n";
        std::cout << "3. exit\n";

        try {
            std::cin >> raspuns;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw WrongInput();
            }

            switch (raspuns) {
                case 1: {
                    creeaza();
                    break;
                }
                case 2: {
                    std::cout << "ce jucator doresti?\n";
                    for (int i = 0; i < static_cast<int>(jucatori.size()); i++) {
                        std::cout << i+1 << ". " << jucatori[i].getUsername() << std::endl;
                    }
                    int jucatorId;
                    std::cin >> jucatorId;
                    --jucatorId;
                    if (!(jucatorId >= 0 && jucatorId < jucatori.size())) {
                        std::cout << "jucator invalid!\n";
                        break;
                    }
                    std::cout << "introduceti parola!\n";
                    std::string parola;
                    std::cin >> parola;
                    if (jucatori[jucatorId].checkParola(parola)) {
                        if (jucatori[jucatorId].getAnimal() == nullptr) {
                            jucatori[jucatorId].setAnimalut();
                        }
                        else {
                            bool ok = true;
                            while (ok) {
                                std::cout << "ce doriti sa faceti?\n";
                                std::cout << "1. joaca!\n";
                                std::cout << "2. hranire.\n";
                                std::cout << "3. vedeti informatii despre animalutul dvs\n";
                                std::cout << "4. inapoi la meniul principal\n";
                                std::cin >> raspuns;
                                switch (raspuns) {
                                    case 1: {
                                        jucatori[jucatorId].getAnimal()->joaca();
                                        break;
                                    }
                                    case 2: {
                                        jucatori[jucatorId].getAnimal()->hraneste();
                                        break;
                                    }
                                    case 3: {
                                        jucatori[jucatorId].getAnimal()->display();
                                        break;
                                    }
                                    case 4: {
                                        ok = false;
                                        break;
                                    }
                                    default: {
                                        std::cout << "nu inteleg!\n";
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else std::cout << "parola gresita!\n";
                    break;
                }
                case 3: {
                    return false;
                }
                default: {
                    std::cout << "nu inteleg.\n";
                    break;
                }
            }
        }
        catch (WrongInput& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void Meniu::creeaza() {
    jucatori.emplace_back();
    jucatori.back().citire();
}

