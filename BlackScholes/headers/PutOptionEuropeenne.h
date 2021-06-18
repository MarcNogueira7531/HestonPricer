#ifndef PUTOPTIONEUROPEENNE_H_INCLUDED
#define PUTOPTIONEUROPEENNE_H_INCLUDED
#include "Option.h"

using namespace std;

class PutOptionEuropeenne : public Option
{
public:
/* Constructors */
    PutOptionEuropeenne();
    PutOptionEuropeenne(double maturity, double strike, double spot, string type, double dividende, double date_dividende);
/* Method */
    double Payoff(double spot_T);
};

#endif // PUTOPTIONEUROPEENNE_H_INCLUDED
