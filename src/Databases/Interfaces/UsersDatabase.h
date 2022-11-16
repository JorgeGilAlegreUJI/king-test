#ifndef KING_TEST_USERSDATABASE_H
#define KING_TEST_USERSDATABASE_H

#include <memory>
#include "BaseDatabase.h"
#include "../../DataModels/User.h"
#include "../Implementations/UMapDatabase.h"

#define usersDatabaseImplementation UMapDatabase<std::string,std::shared_ptr<DataModels::User>>

//Layer of abstraction between the application and the implementation, SOLI(D) Principle
class UsersDatabase : public BaseDatabase{
private:
    usersDatabaseImplementation database;
public:
    unsigned long long getTotalEntries()override;
    bool userExists(const std::string& userName);
    void addUser(const std::string& userName);
    std::shared_ptr<DataModels::User> getUser(const std::string& userName);
};


#endif //KING_TEST_USERSDATABASE_H
