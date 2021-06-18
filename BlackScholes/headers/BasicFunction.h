#ifndef BASICFUNCTION_H_INCLUDED
#define BASICFUNCTION_H_INCLUDED
#include <vector>
#include <numeric>

using namespace std;
/* Normal Distribution Functions */
double NormalPDF(double x);
double NormalCDF(double x);
/* Meant to simulate variable normally distributed */
double gaussian_box_muller();
/* Simulates a trajectory and stores it into vector */
vector<double> trajectoire(double discret, double s, double r, double sigma, double t);
/* Calculate mean of a vector's values, usefull for asian options */
double Mean_vector(vector<double> x);
#endif // BASICFUNCTION_H_INCLUDED
