//
// Created by jorge on 14/11/2022.
//

#ifndef KING_TEST_EXECUTIONCONTROLLER_H
#define KING_TEST_EXECUTIONCONTROLLER_H


#include "../Databases/Interfaces/UsersDatabase.h"
#include "../Services/LocalizationService.h"
#include "../Services/OutputService.h"
#include "../Services/InputService.h"
#include "../Databases/Interfaces/MessagesDatabase.h"

class ExecutionController {
private:
    std::shared_ptr<User> activeUser;
    enum States {Welcome,Menu,UserRegistry,OutboxFrom,OutboxTo,y,Quit};
    States currentState;
    std::shared_ptr<LocalizationService> localizationService;
    std::shared_ptr<OutputService> outputService;
    std::unique_ptr<InputService> inputService;
    std::unique_ptr<UsersDatabase> usersDatabase;
    std::unique_ptr<MessagesDatabase> messagesDatabase;
    void manageOutput();
    void manageInput();
    void manageLanguageSelection();
    void manageMenuSelection();
    void manageUserRegistry();
    void manageOutboxFrom();
    void manageOutboxTo();
    void manageQuit();
public:
    ExecutionController();
    void manageExecution();
    bool isRunning;
};


#endif //KING_TEST_EXECUTIONCONTROLLER_H
