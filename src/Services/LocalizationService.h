#ifndef KING_TEST_LOCALIZATIONSERVICE_H
#define KING_TEST_LOCALIZATIONSERVICE_H

#include <string>
#include <vector>
#include "../Databases/Implementations/UMapDatabase.h"

#define localizationDatabaseImplementation UMapDatabase<std::string,std::vector<std::string>>

class LocalizationService {
private:
    const std::string nullMsg = "[Missing entry on localization service]";
    localizationDatabaseImplementation database;
    void buildDatabase();
public:
    enum Languages { Null,English, Spanish};
    Languages currentLanguage;
    LocalizationService();
    void changeLanguage(int newLanguageID);
    std::string getMessage(const std::string& key);
};


#endif //KING_TEST_LOCALIZATIONSERVICE_H
