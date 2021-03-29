#ifndef APP_HPP
#define APP_HPP

class App
{
    public:
        App();
        ~App();
        int exec();
        void splashScreen();
    private:
        bool status;
};

#endif