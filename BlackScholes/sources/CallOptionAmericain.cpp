#include "CallOptionAmericain.h"
#include <cmath>
#include <string>

using namespace std;

CallOptionAmericain::CallOptionAmericain() : Option(){}
CallOptionAmericain::CallOptionAmericain(double maturity, double strike, double spot, string type, double dividende, double date_dividende) : Option(maturity, strike, spot, type, dividende, date_dividende){}

double CallOptionAmericain::Payoff(double spot_T){
    return max(spot_T-strike,0.0);
}

