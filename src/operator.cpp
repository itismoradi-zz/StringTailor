#include "operator.hpp"
#include <iostream>
#include <exception>
#include <cmath>
#include <algorithm>
using namespace std;
//one character

template <class T, class C>
string op::plus(T  op1, C  op2)
{
    string result = op1.getText() + op2.getText();

    //sorting characters
    sort(result.begin(), result.end());
    
    return result;
}

template <class T, class C>
string op::minus(T  op1, C  op2)
{
    string result;
    size_t op1Size = op1.getSize();
    size_t op2Size = op2.getSize();
    int resultSize = abs((int) op1Size - (int) op2Size);

    if(op1Size > op2Size)
    {
        size_t i = 0;

        for(char ch : op1.getText())
        {
            if(i == resultSize)
            {
                break;
            }

            result.push_back(ch);
            i++;
        }
    }
    else if(op1Size < op2Size)
    {
        size_t i = 0;

        for(char ch : op2.getText())
        {
            if(i == resultSize)
            {
                break;
            }

            result.push_back(ch);
            i++;
        }
    }
    else
    {
        throw "The lengths of the two operands should not be equal";
    }

    return result;
}

template <class T, class C>
string op::star(T  op1, C  op2)
{
    string result;
    size_t op1Size = op1.getSize();
    size_t op2Size = op2.getSize();

    if(op1Size > op2Size)
    {
        for(size_t i = 0; i < op1Size; i++)
        {
            result += op2.getText();
        }
    }
    else if(op1Size < op2Size)
    {
        for(size_t i = 0; i < op2Size; i++)
        {
            result += op1.getText();
        }
    }
    else
    {
        throw "The lengths of the two operands should not be equal";
    }

    return result;
}

template <class T, class C>
string op::slash(T  op1, C  op2)
{
    string result = op1.getText();
    size_t op1Size = op1.getSize();
    size_t op2Size = op2.getSize();
    size_t index = 0;   //index of traversal in operand2 string

    //validation for operand 1
    for(const char & ch : result)
    {
        if(ch < 65 || ch > 90)
        {
            throw "all operand 1 characters must be uppercase";
        }
    }

    //operating
    for(char & ch : result)
    {
        if(index == op2Size)
        {
            return result;
        }
        else if(ch + 32 == op2.getText().at(index))
        {
            ch = op2.getText().at(index);
            index++;
        }
    }
}

template <class T, class C>
string op::less(T  op1, C  op2)
{

}

//two character

template <class T, class C>
string op::doubleAmpersand(T  op1, C  op2)
{

}

template <class T, class C>
string op::doubleVertiSlash(T  op1, C  op2)
{

}

template <class T, class C>
string op::exclamation_equal(T  op1, C  op2)
{

}

template <class T, class C>
string op::plus_equal(T  op1, C  op2)
{

}

template <class T, class C>
string op::minus_equal(T  op1, C  op2)
{

}