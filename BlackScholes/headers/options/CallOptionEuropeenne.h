#ifndef CALLOPTIONEUROPEENNE_H_INCLUDED
#define CALLOPTIONEUROPEENNE_H_INCLUDED
#include "Option.h"

using namespace std;

class CallOptionEuropeenne : public Option
{
public:
/* Constructors */
    CallOptionEuropeenne();
    CallOptionEuropeenne(double maturity, double strike, double spot, string type, double dividende, double date_dividende);
/* Method */
    double Payoff(double spot_T);
};


#endif // CALLOPTIONEUROPEENNE_H_INCLUDED
