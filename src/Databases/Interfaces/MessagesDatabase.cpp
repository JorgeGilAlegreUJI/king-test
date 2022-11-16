#include "MessagesDatabase.h"

unsigned long long MessagesDatabase::getTotalEntries() {
    return database.getSize();
}

void MessagesDatabase::addMessage(const std::string &userNameReceiver, const std::shared_ptr<DataModels::Message>& message) {
    if(database.contains(userNameReceiver)){
        database.get(userNameReceiver).push_back(message);
    }
    else{
        std::vector<std::shared_ptr<DataModels::Message>> msgs;
        msgs.push_back(message);
        database.add(userNameReceiver,msgs);
    }
}

std::vector<std::shared_ptr<DataModels::Message>> MessagesDatabase::extractUserMessages(const std::string &userNameReceiver) {
    if(database.contains(userNameReceiver)){
        auto data = database.get(userNameReceiver);
        removeEntry(userNameReceiver);
        return data;
    }
    else throw RuntimeError(userNameReceiver + " not found in messages database");
}

void MessagesDatabase::removeEntry(const std::string &key) {
    if(database.contains(key)){
        database.Remove(key);
    }
}

unsigned long long MessagesDatabase::getUserMessagesCount(const std::string &key) {
    if(database.contains(key)){
        return database.get(key).size();
    }
    return 0;
}
