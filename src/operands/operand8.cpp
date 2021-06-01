#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand8::Operand8(string text)
{
    setText(text);
}

std::string Operand8::getText() const
{
    return text;
}

size_t Operand8::getSize() const
{
    return text.size();
}

void Operand8::setText(std::string text)
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