#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand10::Operand10(string text)
{
    setText(text);
}

std::string Operand10::getText() const
{
    return text;
}

size_t Operand10::getSize() const
{
    return text.size();
}

void Operand10::setText(std::string text)
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