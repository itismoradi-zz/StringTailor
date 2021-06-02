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

    if(op1Size == op2Size)
    {
        return "null";
    }
    else if(op1Size > op2Size)
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
            break;
        }
        else if(ch + 32 == op2.getText().at(index))
        {
            ch = op2.getText().at(index);
            index++;
        }
    }

    return result;
}

template <class T, class C>
string op::less(T  op1, C  op2)
{
    string result;
    string op1Text = op1.getText();
    string op2Text = op2.getText();
    size_t op1Size = op1.getSize();
    size_t op2Size = op2.getSize();

    if(op2Size > 1)
    {
        throw "operand 2 must be one character";
    }
    if(op1Text == op2Text)
    {
        return "null";
    }

    for(char & ch : op1Text)
    {
        if(ch < op2Text[0])
        {
            result.push_back(ch);
        }
    }

    if(result.empty())
    {
        return "null";
    }

    return result;
}

//two character

template <class T, class C>
string op::doubleAmpersand(T  op1, C  op2)
{
    for(char & ch : op1.getText())  //check operand 1
    {
        //to lowercase
        if(ch >= 65 && ch <= 90)
        {
            ch += 32;
        }

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            for(char & ch : op2.getText())  //check operand 2
            {
                //to lowercase
                if(ch >= 65 && ch <= 90)
                {
                    ch += 32;
                }

                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                {
                    return "True";
                }
            }

            return "False";     //Avoid rotating the outer loop
        }
    }
    
    return "False";
}

template <class T, class C>
string op::doubleVertiSlash(T  op1, C  op2)
{
    string result = op1.getText() + op2.getText();

    for(char & ch : result)
    {
        //to lowercase
        if(ch >= 65 && ch <= 90)
        {
            ch += 32;
        }

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return "True";
        }
    }
    
    return "False";
}

template <class T, class C>
string op::exclamation_equal(T  op1, C  op2)
{
    string result;
    bool foundCharacter;
    string op1Text = op1.getText();
    string op2Text = op2.getText();
    size_t op1Size = op1.getSize();
    size_t op2Size = op2.getSize();
    size_t index = 0; //index of character

    if(op2Size > 1)
    {
        throw "operand 2 must be one character";
    }

    //find index of character in operand 1
    for(index = 0; index < op1Size; index++)
    {
        if(op1Text.at(index) == op2Text[0])
        {
            foundCharacter = true;
            break;
        }
    }
    if(!foundCharacter)
    {
        throw "operand 2 character not found in operand 1";
    }

    if((op1Size % 2) == 1 && (index == (op1Size / 2)))   //Axis is center of operand 1 string
    {
        size_t numberOfSwapElements = op1Size / 2;
        
        //swap after and before Elements
        for(size_t i = 1; i <= numberOfSwapElements; i++)
        {
            char temp = op1Text.at(index + i);
            op1Text.at(index + i) = op1Text.at(index - i);
            op1Text.at(index - i) = temp;
        }

        return op1Text;
    }
    else if(index > (op1Size / 2))     //Axis is right of operand 1 string
    {
        size_t numberOfLeftElements = op1Size - index - 1;
        size_t indexRight = index - numberOfLeftElements - 1;

        //swap left Elements
        for(size_t i = 1; i <= numberOfLeftElements; i++)
        {
            char temp = op1Text.at(index + i);
            op1Text.at(index + i) = op1Text.at(index - i);
            op1Text.at(index - i) = temp;
        }

        for (size_t i = indexRight + 1; i < op1Size; i++)
        {
            result.push_back(op1Text.at(i));
        }
        
        //swap other elements
        for (int i = indexRight; i >= 0; i--)
        {
            result.push_back(op1Text.at(i));
        }

        return result;
    }
    else if(index <= (op1Size / 2))     //Axis is left of operand 1 string
    {
        size_t numberOfRightElements = index;
        size_t indexLeft = index + numberOfRightElements + 1;

        //swap right Elements
        for (size_t i = 1; i <= index; i++)
        {
            char temp = op1Text.at(index + i);
            op1Text.at(index + i) = op1Text.at(index - i);
            op1Text.at(index - i) = temp;
        }

        for (size_t i = 0; i < indexLeft; i++)
        {
            result.push_back(op1Text.at(i));
        }

        //swap other elements
        string str;

        for (int i = op1Size - 1; i >= indexLeft; i--)
        {
            
            str.push_back(op1Text.at(i));
        }

        return (str + result);
    }
}

template <class T, class C>
string op::plus_equal(T  op1, C  op2)
{
    string result;
    string op2Text = op2.getText();
    size_t op1Size = op1.getSize();
    size_t op2Size = op2.getSize();

    if(op2Size > 1)
    {
        throw "operand 2 must be one character";
    }

    for(const char & ch : op1.getText())
    {
       result += ch;
       result += op2Text;
    }
    
    return result;
}

template <class T, class C>
string op::minus_equal(T  op1, C  op2)
{
    string result;
    string op1Text = op1.getText();
    string op2Text = op2.getText();
    size_t op1Size = op1.getSize();
    size_t op2Size = op2.getSize();

    if(op1.getText() == op2.getText())
    {
        return "null";
    }
    else if(op1Size < op2Size)
    {
        throw "operand2 must be less than or equal to operand1";
    }

    for(size_t i = 0; i < op1Size; i++)
    {
        char ch = op1Text.at(i);
        if(ch == op2Text.at(0) && i < (op1Size - op2Size + 1))     //check first same characters
        {
            size_t j = 1; //index of traversal in operand 2

            for(size_t k = 1; k < op2Size; k++)
            {
                if(op1Text.at(i+j) == op2Text.at(j))
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            
            if(j == op2Size)
            {
                i += j - 1;
                continue;
            }
        }
        result.push_back(ch);
    }

    return result;
}