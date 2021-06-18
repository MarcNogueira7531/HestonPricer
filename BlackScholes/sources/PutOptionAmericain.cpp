#include "PutOptionAmericain.h"
#include <cmath>
#include <string>

using namespace std;

PutOptionAmericain::PutOptionAmericain() : Option(){}
PutOptionAmericain::PutOptionAmericain(double maturity, double strike, double spot, string type, double dividende, double date_dividende) : Option(maturity, strike, spot, type, dividende, date_dividende){}

double PutOptionAmericain::Payoff(double spot_T){
    return max(strike-spot_T,0.0);
}
