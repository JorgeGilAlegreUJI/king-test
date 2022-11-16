//
// Created by jorge on 14/11/2022.
//

#ifndef KING_TEST_INPUTSERVICE_H
#define KING_TEST_INPUTSERVICE_H

#include <iostream>
#include <string>
#include <memory>
#include "LocalizationService.h"

class InputService {
public:
    std::string getInput();
    bool processLanguageInput(std::string& input);
    bool processMenuInput(std::string& input);
    bool processQuitInput(bool& input);
};


#endif //KING_TEST_INPUTSERVICE_H
