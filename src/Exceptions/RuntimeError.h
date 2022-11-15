//
// Created by jorge on 15/11/2022.
//

#ifndef KING_TEST_RUNTIMEERROR_H
#define KING_TEST_RUNTIMEERROR_H

#include <stdexcept>

class RuntimeError: public std:: runtime_error {
public:
    explicit RuntimeError(const std::string& msg):runtime_error(msg.c_str()){}
};
#endif //KING_TEST_RUNTIMEERROR_H
