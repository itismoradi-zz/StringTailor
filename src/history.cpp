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
    int numberOfStrings = (int) data.size() - 1;

    cout << "Machine results:" << endl;
    
    for(int i = numberOfStrings ; i>=0; i--)
    {
        cout << "    " << setw(30) << left << data.at(i) << endl;
    }
}