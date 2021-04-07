#StringTailor
cmake_minimum_required(VERSION 3.0)
project("StringTailor")
include_directories(include)
add_executable(app 
    src/main.cpp
    src/app.cpp
    src/command.cpp
    src/operator.cpp
    src/history.cpp
)
message(STATUS ">>> app is building!!")