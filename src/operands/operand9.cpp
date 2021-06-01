#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand9::Operand9(string text)
{
    setText(text);
}

std::string Operand9::getText() const
{
    return text;
}

size_t Operand9::getSize() const
{
    return text.size();
}

void Operand9::setText(std::string text)
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