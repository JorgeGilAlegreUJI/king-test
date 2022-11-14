cmake_minimum_required(VERSION 3.23)
project(king_test)

set(CMAKE_CXX_STANDARD 14)

include_directories(MessageStore)

add_executable(king_test
        MessageStore/main.cpp
        MessageStore/MessageStore.cpp
        MessageStore/MessageStore.h)
