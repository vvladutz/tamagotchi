//
// Created by vlad on 1/13/2025.
//

#ifndef WRONGINPUT_H
#define WRONGINPUT_H
#include <exception>

class WrongInput : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //WRONGINPUT_H
