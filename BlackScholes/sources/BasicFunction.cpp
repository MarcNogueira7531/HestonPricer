#include <cmath>
#include <iostream>
#include <cstdlib>
#include "BasicFunction.h"
#include <ctime>

using namespace std;

double NormalPDF(double x){
    double density = (1 / sqrt(2 * M_PI)) * exp(-x*x/2.0);
    return density;
};

double NormalCDF(double x){
    double cumul = (0.5) * (1 + erf(x/sqrt(2)));
    return cumul;
};

double gaussian_box_muller(){
  double x = 0.0;
  double y = 0.0;
  double euclid_sq = 0.0;

  // Genere deux variables aleatoire uniforme  two uniform random variables
  // jusqu'a ce que la racine de leur distance euclidienne est inferieure a l'unite
  // on en deduit une variable aleatoire suivant une loi normale
  do {
    x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
    y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
    euclid_sq = x*x + y*y;
  } while (euclid_sq >= 1.0);

  return x*sqrt(-2*log(euclid_sq)/euclid_sq);
};

vector<double> trajectoire(double pas_discretisation, double s, double r, double sigma, double t){
    vector<double> path;
    path.push_back(s);  /* insert underlying value at t = 0 */

    double s_adj, s_ti;
    for(int i = 1; i <= pas_discretisation; i++)
    {
    /* Defines time step */
        double temp_t = t / pas_discretisation;

        s_adj = path[i - 1] * exp((r - sigma*sigma/2) * (temp_t));
    /* Simulates variable normally distributed */
        double gauss = gaussian_box_muller();
    /* Generate a path for the underlying */
        s_ti = s_adj * exp(sigma * sqrt(temp_t) * gauss);
    /* Stores each simulation at each step into a vector */
        path.push_back(s_ti);
    }

    return path;
};
double Mean_vector(vector<double> x){ // Fonction permettant de creer la moyenne d'un vecteur (pour asiatique)
    return accumulate(x.begin(), x.end(), 0.0)/ x.size();
};
