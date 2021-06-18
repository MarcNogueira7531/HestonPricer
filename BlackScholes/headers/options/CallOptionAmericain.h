#ifndef CALLOPTIONAMERICAIN_H_INCLUDED
#define CALLOPTIONAMERICAIN_H_INCLUDED
#include "Option.h"

using namespace std;

class CallOptionAmericain : public Option
{
public:
/* Constructors */
    CallOptionAmericain();
    CallOptionAmericain(double maturity, double strike, double spot, string type, double dividende, double date_dividende);
/* Method */
    double Payoff(double spot_T);
};



#endif // CALLOPTIONAMERICAIN_H_INCLUDED
