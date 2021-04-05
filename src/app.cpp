#include "app.hpp"
#include <iostream>
using namespace std;

bool App::status = true;

App::App()
{
    splashScreen();
}

App::~App()
{
    cout << "=!= " << "program finished!" << endl;
}

int App::exec()
{
    command.getCommand();
    return 0;
}

void App::splashScreen()
{
    cout << "   _&_          _{|}_   0" << endl;
    cout << "   |$$\\________/^^^^^\\_|0|" << endl;
    cout << "   |-------------(*)-/ |0|" << endl;
    cout << "    \\v/\"\"\"\"\"\"\"\"\\^^^^/   0" << endl;
    cout << "     !          |^^^|" << endl;
    cout << "#==============/=====\\======#" << endl;
    cout << "|****** String Tailor ******|" << endl;
    cout << "|<! string sewing machine !>|" << endl;
    cout << "|:: machine guide command ::|" << endl;
    cout << "|^^^^^^^^^ <help> ^^^^^^^^^^|" << endl;
    cout << "#===========================#" << endl;
}

void App::switchStatus()
{
    //switches app status to false/true
    if(status == true)
    {
        status = false;
    }
    else
    {
        status = true;
    }
}

bool App::getStatus()
{
    return status;
}