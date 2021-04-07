#ifndef COMMAND_IG
#define COMMAND_IG

#include <string>
#include <array>
#include <history.hpp>
#define MAX_COMMAND_LENGTH 1000

class Command
{
    public:
        Command();
        Command(History *);
        void getCommand();
    private:
        std::array <char, MAX_COMMAND_LENGTH> inputedText;  
        std::string operand1;
        std::string operator_;
        std::string operand2;
        History * history;

        void help();
        void separator(char *);
        size_t findNoneSpaceHomeIndex(size_t) const;
        bool isComputational() const;
        void findClass();
        template <class T, class C>
        void findOperator(T, C);
};

#endif