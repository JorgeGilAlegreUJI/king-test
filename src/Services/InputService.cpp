#include "InputService.h"

std::string InputService::getInput() {
    std::string str;
    std::getline(std::cin, str);
    return str;
}

bool InputService::processLanguageInput(std::string& input) {
    input = getInput();
    return input == "1" || input =="2";
}

bool InputService::processMenuInput(std::string &input) {
    input = getInput();
    return input == "1" || input =="2" || input =="3"|| input =="4";
}

bool InputService::processQuitInput(bool& input) {
    std::string inputStr = getInput();
    if(inputStr == "y" || inputStr =="s")input = true;
    else if(inputStr =="n")input = false;
    else return false;
    return true;
}
