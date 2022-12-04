#ifndef POLYNOMIAL2_H
#define POLYNOMIAL2_H
#include "../DS_HW4_circularList/circularList.h"
#include "../DS_HW4_circularList/circularList.cpp"
using namespace std;

struct Term
{ // All member of Tern are public by default.

    int coef; // coefficient
    int exp;  // exponent
    Term(int c = 0, int e = -1) : coef(c), exp(e) {}
};

class Polynomial
{
public:
    Polynomial();
    ~Polynomial();
    int evaluate(int x);
    Polynomial operator+(const Polynomial &b) const;

private:
    cirChain<Term> *poly;
};

#endif