#include "Application/Application.h"
int main(int, const char* [])
{
    auto application = std::make_unique<Application>();
    while (application->isRunning){
        application->manageExecution();
    }
    return 0;
}

