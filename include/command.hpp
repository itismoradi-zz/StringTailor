#ifndef COMMAND_IG
#define COMMAND_IG

#include <string>

class Command
{
    public:
        Command();
        void getCommand();
    private:
        std::string commandText;
};

#endif