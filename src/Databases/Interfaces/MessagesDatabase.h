//
// Created by jorge on 15/11/2022.
//

#ifndef KING_TEST_MESSAGESDATABASE_H
#define KING_TEST_MESSAGESDATABASE_H


#include <string>
#include <memory>
#include <vector>
#include "BaseDatabase.h"
#include "../../DataModels/Message.h"
#include "../Implementations/UMapDatabase.h"

#define messagesDatabaseImplementation UMapDatabase<std::string,std::vector<std::shared_ptr<Message>>>
class MessagesDatabase : public BaseDatabase{
private:
    messagesDatabaseImplementation database;
public:
    void addMessage(const std::string& userNameReceiver,const std::shared_ptr<Message>& message);
    std::vector<std::shared_ptr<Message>> getUserMessages(const std::string& userNameReceiver);
    int getTotalEntries()override;
};


#endif //KING_TEST_MESSAGESDATABASE_H
