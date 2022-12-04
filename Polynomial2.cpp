#include <iostream>
#include "Polynomial2.h"
#include "../DS_HW4_circularList/circularList.h"

using namespace std;

Polynomial::Polynomial(Term a) : poly(a)
{
    Term a(0, -1);
}

Polynomial::~Polynomial()
{
    poly.~cirChain<Term>();
}

// Polynomial Polynomial::operator+(const Polynomial &b) const
// { // Polynomial *this(a) and b are added and the sum returned
//     cirChain<Term>::cirChainIterator ai = poly.begin(), bi = poly.begin();
//     Term head;
//     Polynomial c(head);
// }
