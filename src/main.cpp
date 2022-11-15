#include <iostream>
#include "DataModels/User.h"
#include "Databases/Interfaces/UsersDatabase.h"
#include "Databases/Implementations/IuMapDatabase.h"
//
// Created by jorge on 14/11/2022.
//
int main(int, const char* [])
{
    auto db = new IuMapDatabase<std::string,User>();
    db->Get("lel");
    //std::cout << < std::endl;

//    MessageStore store;
//
//    while (store.ProcessInput() == false){
//
//    }
//
//    store.terminate();

    return 0;
}

