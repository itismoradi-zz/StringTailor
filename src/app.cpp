#include "app.hpp"
#include <iostream>
using namespace std;

App::App()
{
    status = true;
}

App::~App()
{
    cout << "program finished!" << endl;
}

int App::exec()
{
    splashScreen();
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