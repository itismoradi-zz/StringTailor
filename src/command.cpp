#include "command.hpp"
#include "app.hpp"
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

        separator();

        if(operator_.empty() && operand2.empty())   //inputed command is not a string Computational command
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
        }

        if(operator_ == "+")
        {
            
        }
    }
    while(App::getStatus() == true);
}

void Command::help()
{

}

void Command::separator()
{
    size_t index = 0;   //Home index scrolled in inputedText array

    for(char item : inputedText)
    {
        index++;

        if(item != ' ')
        {
            operand1.push_back(item);
        }
        else    //Reached the empty space
        {
            break;
        }
    }

    index++;    //next word

    if(inputedText.at(index) != ' ' || inputedText.at(index) != '\n')
    {
        operator_.push_back(inputedText.at(index));
        index++;
        operator_.push_back(inputedText.at(index));
    }


}
