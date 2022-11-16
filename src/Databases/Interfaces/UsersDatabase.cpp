//
// Created by jorge on 15/11/2022.
//

#include "UsersDatabase.h"

bool UsersDatabase::userExists(const std::string& userName) {
    return database.contains(userName);
}

void UsersDatabase::addUser(const std::string& userName) {
    if(userExists(userName))throw RuntimeError(userName + " is already in present in the database");
    std::shared_ptr<User> user = std::make_shared<User>(User{userName});
    database.add(userName,user);
}

int UsersDatabase::getTotalEntries() {
    return database.getSize();
}

std::shared_ptr<User> UsersDatabase::getUser(const std::string &userName) {
    if(!database.contains(userName))throw RuntimeError(userName + "not found in users database");
    return database.get(userName);
}

