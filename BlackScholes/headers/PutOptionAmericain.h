#ifndef PUTOPTIONAMERICAIN_H_INCLUDED
#define PUTOPTIONAMERICAIN_H_INCLUDED
#include "Option.h"

using namespace std;

class PutOptionAmericain : public Option
{
public:
/* Constructors */
    PutOptionAmericain();
    PutOptionAmericain(double maturity, double strike, double spot, string type, double dividende, double date_dividende);
/* Method */
    double Payoff(double spot_T);
};



#endif // PUTOPTIONAMERICAIN_H_INCLUDED
