#include "CallOptionAsiatique.h"
#include <cmath>
#include <string>

using namespace std;

CallOptionAsiatique::CallOptionAsiatique() : Option(){}
CallOptionAsiatique::CallOptionAsiatique(double maturity, double strike, double spot, string type, double dividende, double date_dividende) : Option(maturity, strike, spot, type, dividende, date_dividende){}

double CallOptionAsiatique::Payoff(double spot_T){
    return max(spot_T-strike,0.0);
}

