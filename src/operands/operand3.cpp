#include "operands.hpp"
#include <iostream>
#include <exception>
using namespace std;

Operand3::Operand3(string text)
{
    setText(text);
}

std::string Operand3::getText() const
{
    return text;
}

void Operand3::setText(std::string text)
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