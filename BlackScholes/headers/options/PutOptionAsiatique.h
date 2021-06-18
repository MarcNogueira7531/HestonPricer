#ifndef PUTOPTIONASIATIQUE_H_INCLUDED
#define PUTOPTIONASIATIQUE_H_INCLUDED
#include "Option.h"

using namespace std;

class PutOptionAsiatique : public Option
{
public:
/* Constructors */
    PutOptionAsiatique();
    PutOptionAsiatique(double maturity, double strike, double spot, string type, double dividende, double date_dividende);
/* Method */
    double Payoff(double spot_T);
};



#endif // PUTOPTIONASIATIQUE_H_INCLUDED
