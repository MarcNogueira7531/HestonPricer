#include <cmath>
#include <iostream>
#include <string>
#include "FormuleFermee.h"
#include "BasicFunction.h"
#include "Modele.h"
#include "Greeks.h"
#include "Option.h"
#include "BasicFunction.h"

using namespace std;

/* Points to classes Option, Greeks and MarketData to retrieve the information */
Greeks::Greeks(){
    valeur_greek = 0;
};
void Greeks::ajouter_option(Option* O){
    opt = O;
};
void Greeks::ajouter_modele(Modele* M){
    mod = M;
};
void Greeks::ajouter_market(MarketData* MKT){
    mkt = MKT;
};

/* Constructor */
Delta::Delta() : Greeks(){};
/* Calculates delta */
double Delta::pricing_greeks(){
    double vol = mkt->getVol();
    double r = mkt->getRate();
    double mat = opt->getMaturity();
    double sp = opt->getSpot();
    double str = opt->getStrike();
    double norm = 1 / (vol * sqrt(mat));
    double d1 = norm * (log(sp/str) + (r + vol*vol/2) * mat);
    double Nd1;
    Nd1 = NormalCDF(d1);

    if(opt->getType()=="Call Europeen")
    {
        setGreek(Nd1);
    }
    else if(opt->getType()=="Put Europeen")
    {
        setGreek(1 - Nd1);
    }
    else
    {
        setGreek(-100);
    }
};
/* shows the value */
void Delta::affiche_greeks(){
    if(getGreek()==-100){
        cout << "Le delta pour ce type d'option n'est pas implemente" <<endl;}
    else {cout << "La valeur du Delta est de : " << getGreek() << endl;}
};

/* Same for Gamma */
Gamma::Gamma() : Greeks(){};
double Gamma::pricing_greeks(){
    double vol = mkt->getVol();
    double r = mkt->getRate();
    double mat = opt->getMaturity();
    double sp = opt->getSpot();
    double str = opt->getStrike();
    double norm = 1 / (vol * sqrt(mat));
    double d1 = norm * (log(sp/str) + (r + vol*vol/2) * mat);
    double Nd1_;
    Nd1_ = NormalPDF(d1);

    if((opt->getType() == "Call Europeen") | (opt->getType() == "Put Europeen"))
    {
        setGreek(Nd1_ / (sp * vol * sqrt(mat)));
    }
    else
    {
        setGreek(-100);
    }
};
void Gamma::affiche_greeks(){
    if(getGreek() == -100){cout << "Le Gamma pour ce type d'option n'est pas implemente" <<endl;}
    else {cout << "La valeur du Gamma est de : " << getGreek() << endl;}
};

/* Same for Vega */
Vega::Vega() : Greeks(){};
double Vega::pricing_greeks(){
    double vol = mkt->getVol();
    double r = mkt->getRate();
    double mat = opt->getMaturity();
    double sp = opt->getSpot();
    double str = opt->getStrike();
    double norm = 1 / (vol * sqrt(mat));
    double d1 = norm * (log(sp/str) + (r + vol*vol/2) * mat);
    double N_d1;    /* N_(d1) i.e. densite de proba */
    N_d1 = NormalPDF(d1);

    if((opt->getType() == "Call Europeen") | (opt->getType() == "Put Europeen"))
    {
        setGreek(sp * N_d1 * sqrt(mat)/100);
    }
    else
    {
        setGreek(-100);
    }
};
void Vega::affiche_greeks(){
    if(getGreek() == -100){cout << "Le Vega pour ce type d'option n'est pas implemente" <<endl;}
    else {cout << "La valeur du Vega est de : " << getGreek() << endl;}
};


/* Same for Theta */
Theta::Theta() : Greeks(){};
double Theta::pricing_greeks(){
    double vol = mkt->getVol();
    double r = mkt->getRate();
    double mat = opt->getMaturity();
    double sp = opt->getSpot();
    double str = opt->getStrike();
    double norm = 1 / (vol * sqrt(mat));
    double d1 = norm * (log(sp/str) + (r + vol*vol/2) * mat);
    double d2 = d1 - vol * sqrt(mat);
    double d2_ = -d2;
    double N_d1, Nd2, Nd2_;    /* N'(d1) i.e. densité de proba */
    N_d1 = NormalPDF(d1);
    Nd2 = NormalCDF(d2);
    Nd2_ = NormalCDF(-d2);
    double c1 = r * str * exp(-r*mat);
    double c2 = -(sp * N_d1 * vol) / (2 * sqrt(mat));

    if(opt->getType() == "Call Europeen")
    {
        setGreek(c2/100 - c1 * Nd2/100);
    }
    else if(opt->getType() == "Put Europeen")
    {
        setGreek(c2/100 + c1 * Nd2_/100);
    }
    else
    {
        setGreek(-100);
    }
};
void Theta::affiche_greeks(){
    if(getGreek() == -100){cout << "Le Theta pour ce type d'option n'est pas implemente" <<endl;}
    else {cout << "La valeur du Theta est de : " << getGreek() << endl;}
};

/* Same for Rho */
Rho::Rho() : Greeks(){};
double Rho::pricing_greeks(){
    double vol = mkt->getVol();
    double r = mkt->getRate();
    double mat = opt->getMaturity();
    double sp = opt->getSpot();
    double str = opt->getStrike();
    double norm = 1 / (vol * sqrt(mat));
    double d1 = norm * (log(sp/str) + (r + vol*vol/2) * mat);
    double d2 = d1 - vol * sqrt(mat);
    double d2_ = -d2;
    double Nd2, Nd2_;
    Nd2 = NormalCDF(d2);
    Nd2_ = NormalCDF(d2_);
    double c = str * mat * exp(-r*mat);

    if(opt->getType() == "Call Europeen")
    {
        setGreek(c * Nd2/100);
    }
    else if(opt->getType() == "Put Europeen")
    {
        setGreek(-(c * Nd2_)/100);
    }
    else
    {
        setGreek(-100);
    }
};
void Rho::affiche_greeks(){
    if(getGreek() == -100){cout << "Le Rho pour ce type d'option n'est pas implemente" <<endl;}
    else {cout << "La valeur du Rho est de : " << getGreek() << endl;}
};
