#ifndef MODELE_H_INCLUDED
#define MODELE_H_INCLUDED
#include "Option.h"
#include "MarketData.h"

using namespace std;

class Modele{ /* classe abstraite des modeles */
protected:
    string type_modele;
    int nombre_simulation;
    double pas_discretisation;
    double prix;
public:
    Option *opt;
    MarketData *mkt;
public:
/* Constructors */
    Modele();
    Modele(string tm, int nb_s, double pas, double p);
/* Methods */
    void ajouter_market(MarketData* MKT);
    void ajouter_option(Option *O);
    virtual double pricing_model()=0;
    virtual void affiche_pricing()=0;
    double getPasDiscret(){
        return pas_discretisation;
	};
    double getPrix(){
        return prix;
	};
	void setPrix(double p){
        prix = p;
	};
    int getNbSim(){
        return nombre_simulation;
	};
    string getTpMod(){
        return type_modele;
	};
};

#endif // MODELE_H_INCLUDED
