#ifndef FORMULEFERMEE_H_INCLUDED
#define FORMULEFERMEE_H_INCLUDED
#include "Modele.h"
#include "BasicFunction.h"
#include "Option.h"
#include "MarketData.h"


using namespace std;

class FormuleFermee : public Modele
{
public:
/* Constructors */
    FormuleFermee();
    FormuleFermee(string type_modele, int nombre_simulation, double pas_discretisation, double prix);
/*Method*/
    double pricing_model();
    void affiche_pricing();
};



#endif // FORMULEFERMEE_H_INCLUDED
