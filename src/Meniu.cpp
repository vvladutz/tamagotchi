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

void Meniu::checkForDuplicates() {
    for (int i = 0; i < jucatori.size(); i++) {
        for (int j = i+1; j < jucatori.size(); j++ ) {
            if (jucatori[i] == jucatori[j]) {
                std::cout << "nu poti crea jucatorul " << jucatori[i].getUsername() << " deoarece exista deja!\n";
                jucatori.erase(jucatori.begin()+i);
            }
        }
    }
}





bool Meniu::run() {
    while (true) {
        Meniu::getInstance().checkForDuplicates();
        std::cout << "alegeti: \n";
        std::cout << "1. creeaza un jucator\n";
        std::cout << "2. alege un jucator\n";
        std::cout << "3. vezi informatii despre toate animalutele existente\n";
        std::cout << "4. exit\n";

        try {
            int raspuns;
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
                    if (!(jucatorId >= 0 && jucatorId < static_cast<int>(jucatori.size()))) {
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

                    else std::cout << "parola gresita!\n";
                    break;
                }
                case 3: {
                    int ok =0;
                    for (const auto& i : jucatori) {
                        if (i.getAnimal() != nullptr) {
                            i.getAnimal()->display();
                            ok=1; //verificare
                        }
                    }
                    if (!ok) std::cout << "nu exista animalute!\n";
                    break;
                }
                case 4: {
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

