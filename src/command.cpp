#include "command.hpp"
#include "app.hpp"
#include "operator.hpp"
#include "operands.hpp"
#include <iostream>
#include <cstring>
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
        cin.getline(userCommand, MAX_COMMAND_LENGTH, '\n');

        try
        {
            separator();    //separate userCommand in three string

            if(cin.eof())
            {
                App::switchStatus();
                break;
            }
            else if(isEmpty())
            {
                throw "your command is empty";
            }
            else if(isComputational())      //inputed command has a string operator
            {
                find_firstOperand_class();
            }
            else    //inputed command is not a string Computational command
            {
                string & command = firstOperand;
                toLowerCaseCommand(command);

                if(command == "exit")
                {
                    App::switchStatus();
                    break;
                }
                else if(command == "help")
                {
                    help();
                }
                else if(command == "history")
                {
                    history->print();
                }
                else
                {
                    throw "undefined command";
                }
            }
        }   
        catch(const out_of_range e)
        {
            cerr << e.what() << endl;
        }
        catch(const char * message)
        {
            cerr << "---------------(!) " << message << endl;
        }

        firstOperand.clear();
        operator_.clear();
        secondOperand.clear();
    }
    while(App::getStatus() == true);
}

void Command::help()
{
    cout << "helppppp" << endl;
}

void Command::separator()
{
    char * pch;
    pch = strtok(userCommand, " ");

    if(pch != NULL)
    {
        firstOperand = pch;
        pch = strtok (NULL, " ");

        if(pch != NULL)
        {
            operator_ = pch;
            pch = strtok (NULL, " ");

            if(pch != NULL)
            {
                secondOperand = pch;
            }
        }
    }
}
bool Command::isEmpty() const
{
    if(firstOperand.empty() && operator_.empty() && secondOperand.empty())
    {
        return true;
    }
    //else...
    return false;
}

bool Command::isComputational() const
{
    if(!firstOperand.empty() && operator_.empty() && secondOperand.empty())
    {
        return false;
    }
    //else...
    return true;
}

void Command::toLowerCaseCommand(string & command)
{
    for(char & ch : command)
    {
        if(ch >= 65 && ch <= 90)
        {
            ch += 32;
        }
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
        return;
    }
    else if(firstOperand.size() == 2)
    {
        Operand2 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }
    else if(firstOperand.size() == 3)
    {
        Operand3 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }
    else if(firstOperand.size() == 4)
    {
        Operand4 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }
    else if(firstOperand.size() == 5)
    {
        Operand5 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }
    else if(firstOperand.size() == 6)
    {
        Operand6 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }
    else if(firstOperand.size() == 7)
    {
        Operand7 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }
    else if(firstOperand.size() == 8)
    {
        Operand8 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }
    else if(firstOperand.size() == 9)
    {
        Operand9 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }
    else if(firstOperand.size() == 10)
    {
        Operand10 firstClass(this->firstOperand); 
        find_secondOperand_class(firstClass);
        return;
    }

    //exception
    throw "Improper behavior due to incorrect insertion of operands";
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
        return;
    }
    else if(secondOperand.size() == 2)
    {
        Operand2 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }
    else if(secondOperand.size() == 3)
    {
        Operand3 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }
    else if(secondOperand.size() == 4)
    {
        Operand4 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }
    else if(secondOperand.size() == 5)
    {
        Operand5 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }
    else if(secondOperand.size() == 6)
    {
        Operand6 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }
    else if(secondOperand.size() == 7)
    {
        Operand7 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }
    else if(secondOperand.size() == 8)
    {
        Operand8 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }
    else if(secondOperand.size() == 9)
    {
        Operand9 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }
    else if(secondOperand.size() == 10)
    {
        Operand10 secondClass(this->secondOperand); 
        findOperator(firstClass, secondClass);
        return;
    }

    //exception
    throw "Improper behavior due to incorrect insertion of operands";
}

template <class X, class Y>
void Command::findOperator(X op1, Y op2)
{
    string result;

    if(operator_ == "+")
    {
        result = op::plus(op1, op2);
    }
    else if(operator_ == "-")
    {
        result = op::minus(op1, op2);
    }
    else if(operator_ == "*")
    {
        result = op::star(op1, op2);
    }
    else if(operator_ == "/")
    {
        result = op::slash(op1, op2);
    }
    else if(operator_ == "<")
    {
        result = op::less(op1, op2);
    }
    else if(operator_ == "&&")
    {
        result = op::doubleAmpersand(op1, op2);
    }
    else if(operator_ == "||")
    {
        result = op::doubleVertiSlash(op1, op2);
    }
    else if(operator_ == "!=")
    {
        result = op::exclamation_equal(op1, op2);
    }
    else if(operator_ == "+=")
    {
        result = op::plus_equal(op1, op2);
    }
    else if(operator_ == "-=")
    {
        result = op::minus_equal(op1, op2);
    }

    cout << result << endl;
    history->insert(result);
}