#ifndef OPERATOR_IG
#define OPERATOR_IG

namespace op
{
    //one character
    template <class T, class C> void plus(T , C);
    template <class T, class C> void minus(T , C);
    template <class T, class C> void star(T , C);
    template <class T, class C> void slash(T , C);
    template <class T, class C> void less(T , C);
    //two character
    template <class T, class C> void doubleAmpersand(T , C);
    template <class T, class C> void doubleVertiSlash(T , C);
    template <class T, class C> void exclamation_equal(T , C);
    template <class T, class C> void plus_equal(T , C);
    template <class T, class C> void minus_equal(T , C);
};

#include "../src/operator.cpp"
/*  The template functions must be implemented in the header file,
    but has the different extension here .cpp Has been named and moved in src/ directory
*/
#endif