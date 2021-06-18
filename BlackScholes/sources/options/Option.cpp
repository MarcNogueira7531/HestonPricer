#include "Option.h"
#include <cmath>

Option::Option(){
    maturity = 0;
    strike = 0;
    spot = 0;
    type = "None";
    dividende = 0;
    date_dividende = 0;
}
Option::Option(double mat, double s, double sp, string t, double d, double dt_div){
	maturity = mat;
	strike = s;
	spot = sp;
	type = t;
	dividende = d;
	date_dividende = dt_div;
}

void Option::affiche_option(){
    cout << "La maturite de l'option est : " << maturity <<endl;
    cout << "Le cours du sous-jacent est : " << spot <<endl;
    cout << "Le strike de l'option est : " << strike <<endl;
    cout << "L'option est de type " << type <<endl;
    cout << "Le dividende de l'option est de : " << dividende << " (pourcentage du cours)" <<endl;
    cout << "La periode de temps ou est prevue le dividende est de " << date_dividende <<endl;
}
