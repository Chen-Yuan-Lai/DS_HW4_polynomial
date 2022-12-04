#include <iostream>
#include <math.h>
#include "Polynomial2.h"
#include "../DS_HW4_circularList/circularList.h"

using namespace std;

Polynomial::Polynomial()
{
    Term a;
    poly = new cirChain<Term>(a);
}
Polynomial::~Polynomial()
{
    poly->~cirChain<Term>();
}

Polynomial Polynomial::operator+(const Polynomial &b) const
{ // Polynomial *this(a) and b are added and the sum returned
    cirChain<Term>::cirChainIterator ai = poly->begin(), bi = poly->begin();
    Polynomial c; // assume contructor sets head->exp = -1

    while (1)
    {
        if (ai->exp == bi->exp)
        {
            if (ai->exp == -1)
                return c;
            int sum = ai->coef + bi->coef;
            if (sum)
            {
                Term temp(sum, ai->exp);
                c.poly->InsertBack(temp);
            }
            ai++;
            bi++;
        }
        else if (ai->exp < bi->exp)
        {
            Term temp(bi->coef, bi->exp);
            c.poly->InsertBack(temp);
            bi++; // next term of b
        }
        else
        {
            Term temp(ai->coef, ai->exp);
            c.poly->InsertBack(temp);
            ai++;
        }
    }
}

int Polynomial::evaluate(int x)
{
    int sum = 0;
    for (typename cirChain<Term>::cirChainIterator i = poly->begin(); i != poly->end(); i++)
    {
        sum = sum + (i->coef) * (i->exp);
    }
    return sum;
}