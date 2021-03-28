#StringTailor
cmake_minimum_required(VERSION 3.0)
project("StringTailor")
include_directories(include)
add_executable(app 
    src/main.cpp
    src/app.cpp
)
message(STATUS ">>> app is building!!")