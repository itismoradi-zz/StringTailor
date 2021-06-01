#ifndef OPERNADS_IG
#define OPERANDS_IG

#include <string>

/* Because the use of inheritance was not allowed
   10 classes with similar and repetitive definitions have been used
   and Their implementation is done in 10 cpp files in src/operands/ 
   directory */

class Operand1
{
    public:
        Operand1(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand2
{
    public:
        Operand2(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand3
{
    public:
        Operand3(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand4
{
    public:
        Operand4(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand5
{
    public:
        Operand5(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand6
{
    public:
        Operand6(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand7
{
    public:
        Operand7(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand8
{
    public:
        Operand8(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand9
{
    public:
        Operand9(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

class Operand10
{
    public:
        Operand10(std::string);
        std::string getText() const;
        size_t getSize() const;
    private:
        std::string text;    //user inputed operand
        void setText(std::string);
};

#endif