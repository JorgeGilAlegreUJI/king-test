//
// Created by jorge on 15/11/2022.
//

#ifndef KING_TEST_USER_H
#define KING_TEST_USER_H

#include <string>

struct User {
    //Given that we're using the name of the user as its identifier, it makes sense to make it const.
    const std::string name;
};
#endif //KING_TEST_USER_H
