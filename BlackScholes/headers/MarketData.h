#ifndef MARKETDATA_H_INCLUDED
#define MARKETDATA_H_INCLUDED

using namespace std;

class MarketData{
protected:
/* Variables */
    double rate;
    double volatility;
public:
/* Constructors */
    MarketData();
    MarketData(double r, double vol);
/* Methods */
    double getRate(){
        return rate;
	}
    double getVol(){
        return volatility;
	}
};

#endif // MARKETDATA_H_INCLUDED
