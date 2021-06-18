#ifndef CALLOPTIONASIATIQUE_H_INCLUDED
#define CALLOPTIONASIATIQUE_H_INCLUDED
#include "Option.h"

using namespace std;

class CallOptionAsiatique : public Option
{
public:
/* Constructors */
    CallOptionAsiatique();
    CallOptionAsiatique(double maturity, double strike, double spot, string type, double dividende, double date_dividende);
/* Method */
    double Payoff(double spot_T);
};


#endif // CALLOPTIONASIATIQUE_H_INCLUDED
