#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand2::Operand2(string text)
{
    setText(text);
}

std::string Operand2::getText() const
{
    return text;
}

void Operand2::setText(std::string text)
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