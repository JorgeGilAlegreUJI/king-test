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
    void displayLocalizedMessage(const std::string& key,int nEndOfLines);
    void displayInputError();
    void displayOutputInterruption();
};


#endif //KING_TEST_OUTPUTSERVICE_H
