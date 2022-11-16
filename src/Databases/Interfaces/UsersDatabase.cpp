#include "UsersDatabase.h"

bool UsersDatabase::userExists(const std::string& userName) {
    return database.contains(userName);
}

void UsersDatabase::addUser(const std::string& userName) {
    if(userExists(userName))throw RuntimeError(userName + " is already in present in the database");
    std::shared_ptr<DataModels::User> user = std::make_shared<DataModels::User>(DataModels::User{userName});
    database.add(userName,user);
}

unsigned long long UsersDatabase::getTotalEntries() {
    return database.getSize();
}

std::shared_ptr<DataModels::User> UsersDatabase::getUser(const std::string &userName) {
    if(!database.contains(userName))throw RuntimeError(userName + "not found in users database");
    return database.get(userName);
}

