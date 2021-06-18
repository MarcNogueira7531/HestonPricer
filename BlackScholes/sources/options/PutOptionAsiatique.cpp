#include "PutOptionAsiatique.h"
#include <cmath>
#include <string>

using namespace std;

PutOptionAsiatique::PutOptionAsiatique() : Option(){}
PutOptionAsiatique::PutOptionAsiatique(double maturity, double strike, double spot, string type, double dividende, double date_dividende) : Option(maturity, strike, spot, type, dividende, date_dividende){}

double PutOptionAsiatique::Payoff(double spot_T){
    return max(strike-spot_T,0.0);
}
