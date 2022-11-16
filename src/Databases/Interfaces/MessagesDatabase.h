#ifndef KING_TEST_MESSAGESDATABASE_H
#define KING_TEST_MESSAGESDATABASE_H


#include <string>
#include <memory>
#include <vector>
#include "BaseDatabase.h"
#include "../../DataModels/Message.h"
#include "../Implementations/UMapDatabase.h"

#define messagesDatabaseImplementation UMapDatabase<std::string,std::vector<std::shared_ptr<DataModels::Message>>>

//Layer of abstraction between the application and the implementation, SOLI(D) Principle
class MessagesDatabase : public BaseDatabase{
private:
    messagesDatabaseImplementation database;
    void removeEntry(const std::string& key);
public:
    void addMessage(const std::string& userNameReceiver,const std::shared_ptr<DataModels::Message>& message);
    unsigned long long getUserMessagesCount(const std::string& key);
    std::vector<std::shared_ptr<DataModels::Message>> extractUserMessages(const std::string& userNameReceiver);
    unsigned long long getTotalEntries()override;
};


#endif //KING_TEST_MESSAGESDATABASE_H
