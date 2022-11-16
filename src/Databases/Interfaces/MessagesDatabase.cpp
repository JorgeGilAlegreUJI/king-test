//
// Created by jorge on 15/11/2022.
//

#include "MessagesDatabase.h"

int MessagesDatabase::getTotalEntries() {
    return database.getSize();
}

void MessagesDatabase::addMessage(const std::string &userNameReceiver, const std::shared_ptr<Message>& message) {
    if(database.contains(userNameReceiver)){
        database.get(userNameReceiver).push_back(message);
    }
    else{
        std::vector<std::shared_ptr<Message>> msgs;
        msgs.push_back(message);
        database.add(userNameReceiver,msgs);
    }
}

std::vector<std::shared_ptr<Message>> MessagesDatabase::getUserMessages(const std::string &userNameReceiver) {
    if(database.contains(userNameReceiver)){
        return database.get(userNameReceiver);
    }
    else throw RuntimeError(userNameReceiver + " not found in messages database");
}
