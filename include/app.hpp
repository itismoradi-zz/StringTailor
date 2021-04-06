#ifndef APP_IG
#define APP_IG

#include "command.hpp" 

class App
{
    public:
        App();
        ~App();
        int exec();
        void splashScreen();

        static void switchStatus();
        static bool getStatus();
    private:
        static bool status;
        Command command;
        History history;
};

#endif