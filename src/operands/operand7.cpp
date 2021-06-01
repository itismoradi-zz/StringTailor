#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand7::Operand7(string text)
{
    setText(text);
}

std::string Operand7::getText() const
{
    return text;
}

size_t Operand7::getSize() const
{
    return text.size();
}

void Operand7::setText(std::string text)
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