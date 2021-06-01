#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand5::Operand5(string text)
{
    setText(text);
}

std::string Operand5::getText() const
{
    return text;
}

size_t Operand5::getSize() const
{
    return text.size();
}
void Operand5::setText(std::string text)
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