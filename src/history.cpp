#include "history.hpp"
#include <iostream>
#include <iomanip>
#include <exception>
using namespace std;

void History::insert(string result)
{
    if(result.empty())
    {
        throw "machine result is empty";
    }
    //else...
    data.push_back(result);
}

void History::print() const
{
    cout << "---------------(!) Machine results:" << endl;

    for(string item : data)
    {
        cout << "    " << setw(30) << item << endl;
    }
}