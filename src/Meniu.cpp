//
// Created by vlad on 1/13/2025.
//

#include "Meniu.h"
#include <iostream>
#include <limits>

#include "Catelus.h"
#include "Pisicuta.h"
#include "WrongInput.h"

Meniu::Meniu() = default;
Meniu::~Meniu() {jucatori.clear();};

Meniu& Meniu::getInstance() {
    static Meniu instance;
    return instance;
}

void Meniu::checkForDuplicates() {
    for (int i = 0; i < static_cast<int>(jucatori.size()); i++) {
        for (int j = i+1; j < static_cast<int>(jucatori.size()); j++ ) {
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
        std::cout << "4. copiaza animalutul altui jucator\n";
        std::cout << "9. exit\n";

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
                            std::cout << "4. folositi o metoda specifica animalutului dvs!\n";
                            std::cout << "9. inapoi la meniul principal\n";
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
                                    Animalut* animal = jucatori[jucatorId].getAnimal();
                                    if (auto* catelus = dynamic_cast<Catelus*>(animal)) {
                                        catelus->prinde();
                                    } else if (auto* pisicuta = dynamic_cast<Pisicuta*>(animal)) {
                                        pisicuta->scarpina();
                                    } else {
                                        std::cout << "nu inteleg!\n";
                                    }
                                    break;
                                }
                                case 9: {
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
                    std::cout << "ce jucator esti?\n";
                    for (int i = 0; i < static_cast<int>(jucatori.size()); i++) {
                        std::cout << i+1 << ". " << jucatori[i].getUsername() << std::endl;
                    }
                    int jucatorId2;
                    std::cin >> jucatorId2;
                    --jucatorId2;
                    if (!(jucatorId2 >= 0 && jucatorId2 < static_cast<int>(jucatori.size()))) {
                        std::cout << "jucator invalid!\n";
                        break;
                    }
                    if (jucatori[jucatorId2].getAnimal() != nullptr) {
                        std::cout << "ATENTIE! AI DEJA UN ANIMAL! esti sigur ca vrei sa copiezi altul? \n";
                        std::cout << "sansa ta sa te retragi! apasa 9 ca sa iesi, orice alta cifra ca sa continui!\n";
                        std::cin >> raspuns;
                        if (raspuns == 9) break;
                    }
                    std::cout << "animalutul cui jucator il doresti?\n";
                    for (int i = 0; i < static_cast<int>(jucatori.size()); i++) {
                        std::cout << i+1 << ". " << jucatori[i].getUsername() << std::endl;
                    }
                    int jucatorId;
                    std::cin >> jucatorId;
                    --jucatorId;
                    if (jucatorId == jucatorId2) {
                        std::cout << "nu iti poti copia propriul animalut!\n";
                        break;
                    }
                    if (!(jucatorId >= 0 && jucatorId < static_cast<int>(jucatori.size()))) {
                        std::cout << "jucator invalid!\n";
                        break;
                    }
                    std::cout << "introduceti parola!\n";
                    std::string parola;
                    std::cin >> parola;
                    if (jucatori[jucatorId].checkParola(parola)) {
                        if (jucatori[jucatorId].getAnimal() == nullptr) {
                            std::cout << "jucatorul " << jucatori[jucatorId].getUsername() << " nu are un animalut!\n";
                        }
                        else jucatori[jucatorId2] = jucatori[jucatorId];
                    }
                    break;
                }
                case 9: {
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

