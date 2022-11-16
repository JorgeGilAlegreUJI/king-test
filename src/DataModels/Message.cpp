//
// Created by jorge on 16/11/2022.
//
#include "Message.h"

#include <utility>

Message::Message(std::shared_ptr<User> sender, std::shared_ptr<User> receiver,std::string  content) :
sender(std::move(sender)), receiver(std::move(receiver)), content(std::move(content)){}

