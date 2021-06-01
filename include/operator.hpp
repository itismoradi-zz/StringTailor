#ifndef OPERATOR_IG
#define OPERATOR_IG

#include <string>

namespace op
{
    //one character
    template <class T, class C> std::string plus(T , C);
    template <class T, class C> std::string minus(T , C);
    template <class T, class C> std::string star(T , C);
    template <class T, class C> std::string slash(T , C);
    template <class T, class C> std::string less(T , C);
    //two character
    template <class T, class C> std::string doubleAmpersand(T , C);
    template <class T, class C> std::string doubleVertiSlash(T , C);
    template <class T, class C> std::string exclamation_equal(T , C);
    template <class T, class C> std::string plus_equal(T , C);
    template <class T, class C> std::string minus_equal(T , C);
};

#include "../src/operator.cpp"
/*  The template functions must be implemented in the header file,
    but has the different extension here .cpp Has been named and moved in src/ directory
*/
#endif