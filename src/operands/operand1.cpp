#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand1::Operand1(string text)
{
    setText(text);
}

std::string Operand1::getText() const
{
    return text;
}

size_t Operand1::getSize() const
{
    return text.size();
}

void Operand1::setText(std::string text)
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