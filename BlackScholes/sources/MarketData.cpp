#include "MarketData.h"
#include <iostream>

using namespace std;

/* Default Constructor */
MarketData::MarketData(){
    rate = 0;
    volatility=0;
}
/* Specific constructor expecting inputs */
MarketData::MarketData(double r, double vol){
    rate = r;
    volatility = vol;
}

