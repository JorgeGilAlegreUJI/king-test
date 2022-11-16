//
// Created by jorge on 14/11/2022.
//

#ifndef KING_TEST_OUTPUTSERVICE_H
#define KING_TEST_OUTPUTSERVICE_H


#include <memory>
#include "LocalizationService.h"

class OutputService {
private:
    std::shared_ptr<LocalizationService> localizationService;
public:
    explicit OutputService(const std::shared_ptr<LocalizationService>& _localizationService);
    void displayMessage(const std::string& msg,int nEndOfLines);
    void displayInputError();

};


#endif //KING_TEST_OUTPUTSERVICE_H
