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

}

template <class T, class C>
string op::slash(T  op1, C  op2)
{

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