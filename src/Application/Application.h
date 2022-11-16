#ifndef KING_TEST_APPLICATION_H
#define KING_TEST_APPLICATION_H


#include "../Databases/Interfaces/UsersDatabase.h"
#include "../Services/LocalizationService.h"
#include "../Services/OutputService.h"
#include "../Services/InputService.h"
#include "../Databases/Interfaces/MessagesDatabase.h"

//Main class to simulate the use of these created services
class Application {
private:
    enum States {Welcome,Menu,UserRegistry,Outbox,Inbox,Quit};
    States currentState;
    std::shared_ptr<LocalizationService> localizationService;
    std::shared_ptr<OutputService> outputService;
    std::unique_ptr<InputService> inputService;
    std::unique_ptr<UsersDatabase> usersDatabase;
    std::unique_ptr<MessagesDatabase> messagesDatabase;
    void manageLanguageSelection();
    void manageMenuSelection();
    void manageUserRegistry();
    void manageOutbox();
    std::shared_ptr<DataModels::User> manageOutboxFrom();
    std::shared_ptr<DataModels::User> manageOutboxTo();
    void manageInbox();
    void manageQuit();
    void createInputInterruption();
public:
    Application();
    void manageExecution();
    bool isRunning;
};


#endif //KING_TEST_APPLICATION_H
