#ifndef COMMAND_IG
#define COMMAND_IG

#include <string>
#include <array>
#include <history.hpp>
#define MAX_COMMAND_LENGTH 24       //operand1 maximum 10 character 
                                    //space and binary operator maximum 4 character
                                    //operand2 maximum 10 character

class Command
{
    public:
        Command();
        Command(History *);
        void getCommand();
        void help();
        void separator();
    private:
        std::array <char, MAX_COMMAND_LENGTH> inputedText;  
        std::string operand1;
        std::string operator_;
        std::string operand2;
        History * history;
};

#endif