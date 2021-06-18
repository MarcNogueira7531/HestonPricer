#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED
#include <iostream>
#include <string>


using namespace std;

class Option{ /*classe abstraite des options */
protected:
/* Variables */
    double maturity;
    double strike;
    double spot;
    string type;
    double dividende;
    double date_dividende;
public:
/* Constructors */
    Option();
    Option(double mat, double s, double sp, string t, double d, double dt_div);
    virtual double Payoff(double spot_T)=0;
    void affiche_option();
/* Methods */
	void setMaturity(double M){
        maturity = M;
	};
	double getMaturity(){
        return maturity;
	};
	void setStrike(double S){
        strike = S;
	};
	double getStrike(){
        return strike;
	};
	void setSpot(double Sp){
        spot = Sp;
	};
	double getSpot(){
        return spot;
	};
	void setType(string T){
        type = T;
	};
	string getType(){
        return type;
	};
	void setDiv(double D){
        dividende = D;
	};
	double getDiv(){
        return dividende;
	};
	void setDtDiv(double Dtd){
        date_dividende = Dtd;
	};
	double getDtDiv(){
        return date_dividende;
	};
};

#endif // OPTION_H_INCLUDED
