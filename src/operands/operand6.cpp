#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand6::Operand6(string text)
{
    setText(text);
}

std::string Operand6::getText() const
{
    return text;
}

void Operand6::setText(std::string text)
{
    for(char & item : text)
    {
        if(!(item >= 'A' && item <= 'Z'))
        {
            if(!(item >= 'a' && item <= 'z'))
            {
                if(!(item >= '0' && item <= '9'))
                {
                    throw "Operands can only be uppercase or lowercase English letters or numbers";
                }
            }
        }
    }

    this->text = text;
}