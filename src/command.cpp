#include "command.hpp"
#include "app.hpp"
#include <iostream>
using namespace std;

Command::Command()
{

}

void Command::getCommand()
{
    do
    {
        cout << "Machine Command" << ":=) ";
        getline(cin, commandText);
        
        if(commandText == "exit" || cin.eof())
        {
            App::switchStatus;
            break;
        }
        else if(commandText == "help")
        {
            
        }
    }
    while(App::getStatus() == true);
}
