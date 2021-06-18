#include "CallOptionEuropeenne.h"
#include <cmath>
#include <string>

using namespace std;

CallOptionEuropeenne::CallOptionEuropeenne() : Option(){}
CallOptionEuropeenne::CallOptionEuropeenne(double maturity, double strike, double spot, string type, double dividende, double date_dividende) : Option(maturity, strike, spot, type, dividende, date_dividende){}

double CallOptionEuropeenne::Payoff(double spot_T){
    return max(spot_T-strike,0.0);
}
