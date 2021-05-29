#ifndef HISTORY_IG
#define HISTORY_IG

#include <vector>
#include <string>

class History
{
    public:
        void insert(std::string);
        void print() const;
    private:
        std::vector <std::string> data;
};

#endif