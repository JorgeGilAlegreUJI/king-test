#include "DataModels/User.h"
#include "Databases/Interfaces/UsersDatabase.h"
#include "Controllers/ExecutionController.h"

//
// Created by jorge on 14/11/2022.
//
int main(int, const char* [])
{
    auto executionController = std::make_unique<ExecutionController>();

    while (executionController->isRunning){
        executionController->manageExecution();
    }

    return 0;
}

