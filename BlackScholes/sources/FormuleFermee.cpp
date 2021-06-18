#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "FormuleFermee.h"
#include "Option.h"



FormuleFermee::FormuleFermee() : Modele(){}
FormuleFermee::FormuleFermee(string type_modele, int nombre_simulation, double pas_discretisation, double prix) : Modele(type_modele, nombre_simulation, pas_discretisation, prix){
}
double FormuleFermee::pricing_model()
{
    double vol = mkt->getVol();
    double r = mkt->getRate();
    double mat = opt->getMaturity();
    double sp = opt->getSpot();
    double str = opt->getStrike();
    double norm = 1 / (vol * sqrt(mat));
    double d1 = norm * (log(sp/str) + (r + vol*vol/2) * mat);
    double d2 = d1 - vol * sqrt(mat);
    double Nd1, Nd2;
    Nd1 = NormalCDF(d1);
    Nd2 = NormalCDF(d2);


    if(opt->getType() == "Call Europeen")
    {
        prix = Nd1 * sp - Nd2 * str * exp(-r*mat);
    }
    else if (opt->getType() == "Put Europeen")
    {
        double N_d1 = NormalCDF(-d1);
        double N_d2 = NormalCDF(-d2);

        prix = N_d2 * str * exp(-r*mat) - N_d1 * sp;
    }
    else
    {
        cout << "Seulement les prix des options europeennes peuvent etre determines par formule fermee" <<endl;
        prix = 0;
    }

};
void FormuleFermee::affiche_pricing(){
    cout << "Le prix de l'option est de : " << prix << endl;
};
