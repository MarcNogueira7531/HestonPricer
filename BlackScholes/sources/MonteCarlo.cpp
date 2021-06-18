#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include<ctime>
#include "MonteCarlo.h"

MonteCarlo::MonteCarlo() : Modele(){}
MonteCarlo::MonteCarlo(string type_modele, int nombre_simulation, double pas_discretisation, double prix) : Modele(type_modele, nombre_simulation, pas_discretisation, prix){}

double MonteCarlo::pricing_model(){
    srand(time(NULL));
    double vol = mkt->getVol(); //récupération des données de marché, et de l'option
    double r = mkt->getRate();
    double mat = opt->getMaturity();
    double sp = opt->getSpot();
    double str = opt->getStrike();
    double d = opt->getDiv();
    double dt_div = opt->getDtDiv();
    double exercice = (dt_div*getPasDiscret()/mat);

    if((opt->getType()=="Call Europeen")|(opt->getType()=="Put Europeen")) //Cas pricing non path dépendent (européenne)
    {
        double s_adj = sp * exp((r - vol*vol/2) * mat);
        double payoff_cumul = 0.0;
        double st;

        for(int i = 0; i < getNbSim(); i++)
        {
            double gauss = gaussian_box_muller(); // Appel de la fonction permettant de simuler une loi normale
            st = s_adj * exp(vol * sqrt(mat) * gauss); // Application du mouvement brownien
            double payoff = opt->Payoff(st); // Appel à la fonction payoff de option spécifique à chaque option
            payoff_cumul += payoff;
        }

        setPrix((payoff_cumul / getNbSim()) * exp(-r*mat));
    }
    else if ((opt->getType()=="Call Americain")|(opt->getType()=="Put Americain")) // Cas des options americaines
    {
        double payoff_cumul = 0.0;

        for(int i = 0; i < getNbSim(); i++)    /* For each simulation */
        {
            /* Simulate a path */
            if(d == 0)
            {
                double gauss = gaussian_box_muller();
                double st = sp * exp((r - vol*vol/2) * mat) * exp(vol * sqrt(mat) * gauss);
                double payoff = opt->Payoff(st);
                payoff_cumul += payoff * exp(-r*mat);
            }
            else
            {
                vector<double> path;
                path = trajectoire(getPasDiscret(), sp, r, vol, mat); // Permet de construire un vecteur de trajectoire
                double payoff_disc = 0.0;   /* Discounted pay-off to agregate in payoff_cumul */

                for(double j = exercice-1; j <= getPasDiscret(); j++)    /* Le cas optimal pour une Américaine est d'exercer avant le dividende si le payoff est positif sinon au terme */
                {
                    double payoff = opt->Payoff(path[j]); // On applique le payoff à toute la trajectoire

                    if(d*path[j] > path[j]-str && j == exercice-1 && opt->getType() == "Call Americain") // Verfication si le payoff avec dividende est positif
                    {
                        double temp_t = mat / getPasDiscret();
                        payoff_disc = (payoff + d*path[j]) * exp(-r*(temp_t*j));
                        payoff_cumul += payoff_disc;

                        break; // permet de sortir de la boucle car on à exercer un pas de temps avant le dividende
                    }
                    else if(d*path[j] > str-path[j] && j == exercice-1 && opt->getType()=="Put Americain")
                    {
                        double temp_t = mat / getPasDiscret(); // pour le put le test est different
                        payoff_disc = (payoff + d*path[j]) * exp(-r*(temp_t*j));
                        payoff_cumul += payoff_disc;

                        break;
                    }
                    else if (j == getPasDiscret()) // cas ou on n'exerce pas au temps du détachement du dividende alors le temps optimal est au terme de la maturité
                    {
                        payoff_disc = payoff * exp(-r*(mat));

                        payoff_cumul += payoff_disc;
                    }
                }
            }

        }
        setPrix(payoff_cumul / getNbSim());
    }
    else // Option asiatique path dependant pour la moyenne mais calculer sur la valeur terminal contrairement à l'americaine
    {
        double payoff_cumul = 0.0;
        vector<double> path;
        for(int i = 0; i < getNbSim(); i++)    /* For each simulation */
        {
            /* Simulate a path */
            path = trajectoire(getPasDiscret(), sp, r, vol, mat);
            double payoff_disc = 0.0;   /* Discounted pay-off to agregate in payoff_cumul */
            double payoff = opt->Payoff(Mean_vector(path));

            payoff_disc = payoff * exp(-r*(mat));
            payoff_cumul += payoff_disc;
        }
        setPrix(payoff_cumul / getNbSim());
    }
};
void MonteCarlo::affiche_pricing(){ // Shows price
    cout << "Le prix du " << opt->getType() <<" est de : " << getPrix() << endl;
};
