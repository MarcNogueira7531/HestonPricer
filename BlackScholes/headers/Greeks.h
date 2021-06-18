#ifndef GREEKS_H_INCLUDED
#define GREEKS_H_INCLUDED
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Option.h"
#include "Modele.h"
#include "MarketData.h"

class Greeks { //Classe abstraite de réference pour les grecques
public:
    MarketData *mkt;
    Modele *mod;
    Option *opt;
protected:
    double valeur_greek;
public:
/* Constructors */
    Greeks();
/* Methods */
    void ajouter_market(MarketData* MKT);
    void ajouter_modele(Modele *M);
    void ajouter_option(Option *O);
    virtual double pricing_greeks()=0;
    virtual void affiche_greeks()=0;
    double getGreek(){
        return valeur_greek;
    };
    void setGreek(double g){
        valeur_greek = g;
    };
};
/* Delta */
class Delta : public Greeks{
public:
/* Constructor */
    Delta();
/* Methods */
    double pricing_greeks();    // Calculates the value
    void affiche_greeks();      // Shows the greek

};
/* Gamma */
class Gamma : public Greeks{
public:
/* Constructor */
    Gamma();
/* Methods */
    double pricing_greeks();    // Calculates the value
    void affiche_greeks();      // Shows the greek
};
/* Vega */
class Vega : public Greeks{
public:
/* Constructor */
    Vega();
/* Methods */
    double pricing_greeks();    // Calculates the value
    void affiche_greeks();      // Shows the greek
};

/* Rho */
class Rho : public Greeks{
public:
/* Constructor */
    Rho();
/* Methods */
    double pricing_greeks();    // Calculates the value
    void affiche_greeks();      // Shows the greek
};
/* Theta */
class Theta : public Greeks{
public:
/* Constructor */
    Theta();
/* Methods */
    double pricing_greeks();    // Calculates the value
    void affiche_greeks();      // Shows the greek
};
#endif // GREEKS_H_INCLUDED
