#StringTailor
cmake_minimum_required(VERSION 3.0)
project("StringTailor")
include_directories(include)
add_executable(app 
    src/main.cpp
    src/app.cpp
    src/command.cpp
    src/history.cpp
    src/operands/operand1.cpp
    src/operands/operand2.cpp
    src/operands/operand3.cpp
    src/operands/operand4.cpp
    src/operands/operand5.cpp
    src/operands/operand6.cpp
    src/operands/operand7.cpp
    src/operands/operand8.cpp
    src/operands/operand9.cpp
    src/operands/operand10.cpp
)
message(STATUS ">>> app is building!!")