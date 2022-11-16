cmake_minimum_required(VERSION 3.23)
project(king_test)

set(CMAKE_CXX_STANDARD 14)
add_executable(king_test src/main.cpp src/Controllers/ExecutionController.cpp src/Controllers/ExecutionController.h src/Services/InputService.cpp src/Services/InputService.h src/Services/OutputService.cpp src/Services/OutputService.h src/Databases/Interfaces/UsersDatabase.cpp src/Databases/Interfaces/UsersDatabase.h src/Databases/Interfaces/MessagesDatabase.cpp src/Databases/Interfaces/MessagesDatabase.h src/DataModels/User.h src/DataModels/Message.h src/Databases/Implementations/UMapDatabase.h src/Databases/Implementations/UMapDatabase.tpp src/Exceptions/RuntimeError.h src/Databases/Interfaces/BaseDatabase.h src/Services/LocalizationService.cpp src/Services/LocalizationService.h src/DataModels/Message.cpp)
