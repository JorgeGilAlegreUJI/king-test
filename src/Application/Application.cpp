#include "Application.h"

Application::Application() {
    isRunning = true;
    currentState = Welcome;
    localizationService = std::make_shared<LocalizationService>();
    outputService = std::make_unique<OutputService>(localizationService);
    inputService = std::make_unique<InputService>();
    usersDatabase = std::make_unique<UsersDatabase>();
    messagesDatabase = std::make_unique<MessagesDatabase>();
}

void Application::manageExecution() {
    switch (currentState) {
        case Welcome:
            manageLanguageSelection();
            break;
        case Menu:
            manageMenuSelection();
            break;
        case UserRegistry:
            manageUserRegistry();
            break;
        case Outbox:
            manageOutbox();
            break;
        case Inbox:
            manageInbox();
            break;
        case Quit:
            manageQuit();
            break;
    }
}

void Application::manageLanguageSelection() {
    outputService->displayLocalizedMessage("_Welcome",1);
    std::string input;
    bool welcomeInputOK = inputService->processLanguageInput(input);
    if(welcomeInputOK){
        localizationService->changeLanguage(std::stoi(input));
        outputService->displayLocalizedMessage("_LanguageSelected",2);
        currentState = Menu;
    }
    else{
        outputService->displayInputError();
        createInputInterruption();
    }

}

void Application::manageMenuSelection() {
    outputService->displayLocalizedMessage("_Menu",2);
    std::string input;
    bool menuInputOk = inputService->processMenuInput(input);
    if(menuInputOk){
        int numericInput = std::stoi(input);
        switch (numericInput) {
            case 1:{
                currentState = UserRegistry;
                break;
            }
            case 2:{
                currentState = Outbox;
                break;
            }
            case 3:{
                currentState = Inbox;
                break;
            }
            case 4:{
                currentState = Quit;
                break;
            }
            default:{
                throw RuntimeError(" Application menu input validation failed");
            }
        }
    }
    else{
        outputService->displayInputError();
        createInputInterruption();
    }

}

void Application::manageUserRegistry() {
    outputService->displayLocalizedMessage("_AskUserName",0);
    std::string  input = inputService->getInput();
    if(usersDatabase->userExists(input)){
        outputService->displayLocalizedMessage("_UserExists",2);
        createInputInterruption();
    } else{
        usersDatabase->addUser(input);
        outputService->displayLocalizedMessage("_UserAdded",0);
        outputService->displayMessage(input,2);
    }
    currentState = Menu;
}

#pragma region Outbox

void Application::manageOutbox() {
    std::shared_ptr<DataModels::User> from = manageOutboxFrom();
    if(from == nullptr){
        createInputInterruption();
        currentState = Menu;
        return;
    }
    std::shared_ptr<DataModels::User> to = manageOutboxTo();
    if(to == nullptr){
        createInputInterruption();
        currentState = Menu;
        return;
    }

    //Message Creation
    outputService->displayLocalizedMessage("_MessageInput",0);
    std::string messageContent = inputService->getInput();
    auto message = std::make_shared<DataModels::Message>(from,to,messageContent);
    messagesDatabase->addMessage(to->name,message);
    outputService->displayLocalizedMessage("_MessageOK",2);
    currentState = Menu;
}

std::shared_ptr<DataModels::User> Application::manageOutboxFrom() {
    outputService->displayLocalizedMessage("_OutboxFrom",0);
    std::string senderName = inputService->getInput();
    if(usersDatabase->userExists(senderName)){
        std::shared_ptr<DataModels::User> activeUser = usersDatabase->getUser(senderName);
        return activeUser;
    }
    else{
        outputService->displayLocalizedMessage("_NoUser",2);
        return nullptr;
    }
}

std::shared_ptr<DataModels::User> Application::manageOutboxTo() {
    outputService->displayLocalizedMessage("_OutboxTo",0);
    std::string endUserName = inputService->getInput();
    if(usersDatabase->userExists(endUserName)){
        auto endUser = usersDatabase->getUser(endUserName);
        return endUser;
    }
    else{
        outputService->displayLocalizedMessage("_NoUser",2);
        return nullptr;
    }

}

#pragma endregion

void Application::manageQuit() {
    outputService->displayLocalizedMessage("_Quit",1);
    bool input;
    bool quitInputOK = inputService->processQuitInput(input);
    if(quitInputOK){
        if(input){
            outputService->displayLocalizedMessage("_Bye",1);
            isRunning = false;
        }
        else{
            currentState = Menu;
        }
    }
    else{
        outputService->displayInputError();
    }

}

void Application::manageInbox() {
    outputService->displayLocalizedMessage("_InboxOf",0);
    std::string userName = inputService->getInput();
    if(messagesDatabase->getUserMessagesCount(userName)>0){
        outputService->displayLocalizedMessage("_MessagesHeader",1);
        auto msgs = messagesDatabase->extractUserMessages(userName);
        for (int i = 0;i<msgs.size();i++) {
            outputService->displayLocalizedMessage("_Message",0);
            outputService->displayMessage(std::to_string(i),1);
            outputService->displayLocalizedMessage("_OutboxFrom",0);
            outputService->displayMessage(msgs[i]->sender->name,1);
            outputService->displayLocalizedMessage("_Message",0);
            outputService->displayMessage(msgs[i]->content,1);
            if(i != msgs.size()-1)outputService->displayMessage("--------------",1);
        }
        outputService->displayLocalizedMessage("_MessagesFooter",2);
        createInputInterruption();
    }
    else{
        outputService->displayLocalizedMessage("_NoMessages",2);
        createInputInterruption();
    }
    currentState = Menu;
}

void Application::createInputInterruption() {
    outputService->displayOutputInterruption();
    inputService->getInput();
}




