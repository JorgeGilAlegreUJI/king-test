#include <iostream>
#include "OutputService.h"

OutputService::OutputService(const std::shared_ptr<LocalizationService>& _localizationService) {
    localizationService = _localizationService;
}

void OutputService::displayMessage(const std::string &msg,int nEndOfLines = 1) {
    std::cout << msg;
    for (int i = 0; i < nEndOfLines; ++i) {
        std::cout << std::endl;
    }
}

void OutputService::displayInputError() {
    displayMessage(localizationService->getMessage("_InputError"),2);
}

void OutputService::displayOutputInterruption() {
    displayMessage(localizationService->getMessage("_Interruption"),2);
}

void OutputService::displayLocalizedMessage(const std::string &key, int nEndOfLines) {
    displayMessage(localizationService->getMessage(key),nEndOfLines);
}



