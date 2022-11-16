//
// Created by jorge on 14/11/2022.
//

#include "ExecutionController.h"

ExecutionController::ExecutionController() {
    isRunning = true;
    currentState = Welcome;
    localizationService = std::make_shared<LocalizationService>();
    outputService = std::make_unique<OutputService>(localizationService);
    inputService = std::make_unique<InputService>();
    usersDatabase = std::make_unique<UsersDatabase>();
    messagesDatabase = std::make_unique<MessagesDatabase>();
}

void ExecutionController::manageExecution() {
    manageOutput();
    manageInput();
}


void ExecutionController::manageOutput() {
    switch (currentState) {
        case Welcome:
            outputService->displayMessage(localizationService->getMessage("_Welcome"),1);
            break;
        case Menu:
            outputService->displayMessage(localizationService->getMessage("_Menu"),2);
            break;
        case UserRegistry:
            outputService->displayMessage(localizationService->getMessage("_AskUserName"),0);
            break;
        case OutboxFrom:
            outputService->displayMessage(localizationService->getMessage("_OutboxFrom"),0);
            break;
        case OutboxTo:
            outputService->displayMessage(localizationService->getMessage("_OutboxTo"),0);
            break;
        case Quit:
            outputService->displayMessage(localizationService->getMessage("_Quit"),1);
            break;
    }
}


void ExecutionController::manageInput() {
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
        case OutboxFrom:
            manageOutboxFrom();
            break;
        case OutboxTo:
            manageOutboxTo();
            break;
        case Quit:
            manageQuit();
            break;
    }

}

void ExecutionController::manageLanguageSelection() {
    std::string input;
    bool welcomeInputOK = inputService->processLanguageInput(input);
    if(welcomeInputOK){
        localizationService->changeLanguage(std::stoi(input));
        outputService->displayMessage(localizationService->getMessage("_LanguageSelected"),2);
        currentState = Menu;
    }
    else{
        outputService->displayInputError();
    }
}

void ExecutionController::manageMenuSelection() {
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
                currentState = OutboxFrom;
                break;
            }
            case 3:{
                //currentState = UserRegistry;
                break;
            }
            case 4:{
                currentState = Quit;
                break;
            }
        }
    }
    else{
        outputService->displayInputError();
    }

}

void ExecutionController::manageUserRegistry() {
    std::string  input = inputService->getInput();
    if(usersDatabase->userExists(input)){
        outputService->displayMessage(localizationService->getMessage("_UserExists"),2);
    } else{
        usersDatabase->addUser(input);
        outputService->displayMessage(localizationService->getMessage("_UserAdded"),0);
        outputService->displayMessage(input,2);
    }
    currentState = Menu;
}

void ExecutionController::manageQuit() {
    bool input;
    bool quitInputOK = inputService->processQuitInput(input);
    if(quitInputOK){
        if(input){
            outputService->displayMessage(localizationService->getMessage("_Bye"),1);
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

void ExecutionController::manageOutboxFrom() {
    std::string senderName = inputService->getInput();
    if(usersDatabase->userExists(senderName)){
        activeUser = usersDatabase->getUser(senderName);
        currentState = OutboxTo;
    }
    else{
        outputService->displayMessage(localizationService->getMessage("_NoUser"),2);
        currentState = Menu;
    }
}

void ExecutionController::manageOutboxTo() {
    std::string endUserName = inputService->getInput();
    if(usersDatabase->userExists(endUserName)){
        //create message and add it to the messagesdb
        auto endUser = usersDatabase->getUser(endUserName);
        auto message = std::make_shared<Message>(activeUser,endUser,"msg");
    }
    else{
        outputService->displayMessage(localizationService->getMessage("_NoUser"),2);
        currentState = Menu;
    }

}


