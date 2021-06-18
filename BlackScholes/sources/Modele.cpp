#include <iostream>
#include "Modele.h"
#include "Option.h"
#include "MarketData.h"

Modele::Modele(){
    type_modele = "None";
    nombre_simulation = 0;
    pas_discretisation = 0;
    prix = 0;
};
Modele::Modele(string tm, int nb_s, double pas, double p){
    type_modele = tm;
    nombre_simulation = nb_s;
    pas_discretisation = pas;
    prix = p;
};
void Modele::ajouter_option(Option* O){
    opt = O;
};
void Modele::ajouter_market(MarketData* MKT){
    mkt = MKT;
};
