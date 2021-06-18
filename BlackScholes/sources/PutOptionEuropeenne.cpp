#include "PutOptionEuropeenne.h"
#include <cmath>
#include <string>

using namespace std;

PutOptionEuropeenne::PutOptionEuropeenne() : Option(){}
PutOptionEuropeenne::PutOptionEuropeenne(double maturity, double strike, double spot, string type, double dividende, double date_dividende) : Option(maturity, strike, spot, type, dividende, date_dividende){
}

double PutOptionEuropeenne::Payoff(double spot_T){
    return max(strike-spot_T,0.0);
}
