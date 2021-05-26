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
        std::string firstOperand;
        std::string operator_;
        std::string secondOperand;
        History * history;

        void help();
        void separator(char *);
        size_t findNoneSpaceHomeIndex(size_t) const;
        bool isComputational(const char *) const;

        void find_firstOperand_class();
        template <class T> void find_secondOperand_class(T);
        template <class X, class Y> void findOperator(X, Y);
};

#endif