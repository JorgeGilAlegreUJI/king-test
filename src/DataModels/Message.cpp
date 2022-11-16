#include "Message.h"

namespace DataModels{
    Message::Message(std::shared_ptr<User> sender, std::shared_ptr<User> receiver,std::string  content) :
            sender(std::move(sender)), receiver(std::move(receiver)), content(std::move(content)){}
}

