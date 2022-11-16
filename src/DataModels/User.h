#ifndef KING_TEST_USER_H
#define KING_TEST_USER_H

#include <string>
#include <iostream>

namespace DataModels{
    struct User {
        //Given that we're using the name of the user as its identifier, it makes sense to make it const.
        const std::string name;
    };
}
#endif //KING_TEST_USER_H
