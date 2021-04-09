#include "command.hpp"
#include "app.hpp"
#include "operator.hpp"
#include "operands.hpp"
#include <iostream>
using namespace std;

Command::Command()
{
    //defualt construcor
}

Command::Command(History * history)
{
    this->history = history;
}

void Command::getCommand()
{
    do
    {
        cout << "Machine Command" << ":=) ";
        char tempInputedText[MAX_COMMAND_LENGTH];
        cin.getline(tempInputedText, MAX_COMMAND_LENGTH);

        try
        {
            separator(tempInputedText);
        }
        catch(const out_of_range e)
        {
            cerr << e.what() << endl;
        }
        catch(const char * message)
        {
            cerr << message << endl;
        }
        
        if(!isComputational())   //inputed command is not a string Computational command
        {
            if(firstOperand == "exit" || cin.eof())
            {
                App::switchStatus();
                break;
            }
            else if(firstOperand == "help")
            {
                help();
            }
            else if(firstOperand == "history")
            {

            }
        }
        else                     //inputed command has a string operator
        {
            try
            {
                find_firstOperand_class();
            }
            catch(const char * message)
            {
                cerr << "(!) " << message << endl;
            }
        }
    }
    while(App::getStatus() == true);
}

void Command::help()
{

}

void Command::separator(char * text)
{
    size_t index = 0;   //Home index scrolled in inputedText array
    size_t textSize;

    //copy user inputed command to inputedText array data member
    while(text[index] != '\0')
    {
        inputedText.at(index) = text[index];
        index++;
    }
    
    //ignore white spaces in array front
    textSize = --index;
    index = findNoneSpaceHomeIndex(0);

    //separate firstOperand
    while(inputedText.at(index) != ' ')
    {
        char item = inputedText.at(index);
        firstOperand.push_back(item);
        index++;
    }

    //ignore white spaces between firstOperand and operator
    index = findNoneSpaceHomeIndex(index);

    //separate operator
    if(char item1 = inputedText.at(index) != ' ')
    {
        operator_.push_back(item1);
        index++;

        if(char item2 = inputedText.at(index) != ' ')
        {
            operator_.push_back(item2);
            index++;
        }
    }

    //ignore white spaces between operator and secondOperand
    index = findNoneSpaceHomeIndex(index);

    //separate operand2
    while(inputedText.at(index) != ' ')
    {
        char item = inputedText.at(index);
        secondOperand.push_back(item);
        index++;
    }

    if(firstOperand.size() > 10 || secondOperand.size() > 10)
    {
        throw "=!= operand must be maximum 10 character";
    }

    cout << "! " << firstOperand << " ! " << operator_ << " ! " << secondOperand << endl;
}

size_t Command::findNoneSpaceHomeIndex(size_t pos) const
{
    while(inputedText.at(pos) == ' ')
    {
        pos++;
    }

    return pos;
}

bool Command::isComputational() const
{
    if(operator_.empty() && secondOperand.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Command::find_firstOperand_class()
{
    /* 
        operand 1
        According to the size of the firstOperand string,
        creates a suitable object for the user input 
        operand to finally pass to the op namespace functions 
    */

    if(firstOperand.size() == 1)
    {
        Operand1 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 2)
    {
        Operand2 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 3)
    {
        Operand3 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 4)
    {
        Operand4 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 5)
    {
        Operand5 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 6)
    {
        Operand6 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 7)
    {
        Operand7 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 8)
    {
        Operand8 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 9)
    {
        Operand9 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
    else if(firstOperand.size() == 10)
    {
        Operand10 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
    }
}

template <class T>
void Command::find_secondOperand_class(T firstClass)
{
    /* 
        operand 2
        According to the size of the secondOperand string,
        creates a suitable object for the user input 
        operand to finally pass to the op namespace functions 
    */

    if(secondOperand.size() == 1)
    {
        Operand1 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 2)
    {
        Operand2 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 3)
    {
        Operand3 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 4)
    {
        Operand4 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 5)
    {
        Operand5 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 6)
    {
        Operand6 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 7)
    {
        Operand7 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 8)
    {
        Operand8 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 9)
    {
        Operand9 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
    else if(secondOperand.size() == 10)
    {
        Operand10 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
    }
}

template <class X, class Y>
void Command::findOperator(X op1, Y op2)
{
    if(operator_ == "+")
    {
        op::plus(op1, op2);
    }
    else if(operator_ == "-")
    {
        op::minus(op1, op2);
    }
    else if(operator_ == "*")
    {
        op::star(op1, op2);
    }
    else if(operator_ == "/")
    {
        op::slash(op1, op2);
    }
    else if(operator_ == "<")
    {
        op::less(op1, op2);
    }
    else if(operator_ == "&&")
    {
        op::doubleAmpersand(op1, op2);
    }
    else if(operator_ == "||")
    {
        op::doubleVertiSlash(op1, op2);
    }
    else if(operator_ == "!=")
    {
        op::exclamation_equal(op1, op2);
    }
    else if(operator_ == "+=")
    {
        op::plus_equal(op1, op2);
    }
    else if(operator_ == "-=")
    {
        op::minus_equal(op1, op2);
    }
}