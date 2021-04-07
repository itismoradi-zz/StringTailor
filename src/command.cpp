#include "command.hpp"
#include "app.hpp"
#include "operator.hpp"
#include <iostream>
using namespace std;

Command::Command()
{

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
            if(operand1 == "exit" || cin.eof())
            {
                App::switchStatus();
                break;
            }
            else if(operand1 == "help")
            {
                help();
            }
            else if(operand1 == "history")
            {

            }
        }
        else                     //inputed command has a string operator
        {
            findClass();
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

    //separate operand1
    while(inputedText.at(index) != ' ')
    {
        char item = inputedText.at(index);
        operand1.push_back(item);
        index++;
    }

    //ignore white spaces between operand1 and operator
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

    //ignore white spaces between operator and operand2
    index = findNoneSpaceHomeIndex(index);

    //separate operand2
    while(inputedText.at(index) != ' ')
    {
        char item = inputedText.at(index);
        operand2.push_back(item);
        index++;
    }

    if(operand1.size() > 10 || operand2.size() > 10)
    {
        throw "=!= operand must be maximum 10 character";
    }

    cout << "! " << operand1 << " ! " << operator_ << " ! " << operand2 << endl;
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
    if(operator_.empty() && operand2.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Command::findClass()
{
    if(operand1.size() == 1)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 2)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 3)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 4)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 5)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 6)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 7)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 8)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 9)
    {
        findOperator<, >(class1, class2);    
    }
    else if(operand1.size() == 10)
    {
        findOperator<, >(class1, class2);    
    }
}

template <class T, class C>
void Command::findOperator(T op1, C op2)
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