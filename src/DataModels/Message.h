#ifndef KING_TEST_MESSAGE_H
#define KING_TEST_MESSAGE_H

#include <string>
#include <memory>
#include "User.h"
#include <utility>

namespace  DataModels{
    struct Message {
        std::shared_ptr<User> sender;
        std::shared_ptr<User> receiver;
        const std::string content;
        Message(std::shared_ptr<User> sender,std::shared_ptr<User> receiver,std::string content);
    };
}
#endif //KING_TEST_MESSAGE_H
