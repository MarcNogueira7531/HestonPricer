#ifndef MONTECARLO_H_INCLUDED
#define MONTECARLO_H_INCLUDED
#include <vector>
#include <string>
#include "FormuleFermee.h"
#include "BasicFunction.h"
#include "Option.h"
#include "MarketData.h"

using namespace std;

class MonteCarlo : public Modele{
public:
/* Constructors */
    MonteCarlo();
    MonteCarlo(string type_modele, int nombre_simulation, double pas_discretisation, double prix);
/* Method */
    double pricing_model();
    void affiche_pricing();
};

#endif // MONTECARLO_H_INCLUDED
