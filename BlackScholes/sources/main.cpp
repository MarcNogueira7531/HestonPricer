#include <iostream>
#include <cmath>
#include <string>
#include "Option.h"
#include "CallOptionEuropeenne.h"
#include "CallOptionAsiatique.h"
#include "CallOptionAmericain.h"
#include "PutOptionEuropeenne.h"
#include "PutOptionAmericain.h"
#include "PutOptionAsiatique.h"
#include "Modele.h"
#include "FormuleFermee.h"
#include "BasicFunction.h"
#include "Greeks.h"
#include "MonteCarlo.h"


using namespace std;

int main()
{
cout << "Bienvenue sur le pricer d'option" <<endl;
string type_opt;
int choix = 0;
double spot;
double strike;
double maturity;
double dividende;
double date_dividende;
double a = 0;
double volatility;
double rate;
Option *opt;
MarketData *mkt;
Modele *mod;


while(choix == 0)
{

        cout << "Veuillez saisir le numero correspondant au type d'option à pricer :" << endl;
        cout << "1- Call Europeen" << endl;
        cout << "2- Put Europeen" << endl;
        cout << "3- Call Americain" << endl;
        cout << "4- Put Americain" << endl;
        cout << "5- Call Asiatique" << endl;
        cout << "6- Put Asiatique" << endl;

        cin >> a;
        if(a<7 && a >0)
        {
            if(a==1){type_opt = "Call Europeen";}
            if(a==2){type_opt = "Put Europeen";}
            if(a==3){type_opt = "Call Americain";}
            if(a==4){type_opt = "Put Americain";}
            if(a==5){type_opt = "Call Asiatique";}
            if(a==6){type_opt = "Put Asiatique";}

        }
        else
        {
            cout << "Erreur de saisie !" << endl;
            break;
        }
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "Veuillez saisir le prix du sous-jacent (spot) :" << endl;
        cin >> a;
        if(a > 0)
        {
            spot = a;
        }
        else
        {
            cout << "Erreur de saisie !" << endl;
            break;cout << "---------------------------------------------------------------------------------------" << endl;
        }
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "Veuillez saisir le strike de l'option :" << endl;
        cin >> a;
        if(a > 0)
        {
            strike = a;
        }
        else
        {
            cout << "Erreur de saisie !" << endl;
            break;
        }
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "Veuillez saisir la maturite de l'option (1 an = 1, 6 mois = 0,5 ...) :" << endl;
        cin >> a;
        if(a > 0)
        {
            maturity = a;
        }
        else
        {
            cout << "Erreur de saisie !" << endl;
            break;
        }
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "Veuillez saisir le rendement du dividende (en pourcentage du spot) :" << endl;
        cin >> a;
        if(a >= 0)
        {
            dividende = a/100;
        }
        else
        {
            cout << "Erreur de saisie !" << endl;
            break;
        }
        if(dividende!=0)
        {
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "Veuillez saisir la periode de survenance du dividende (1 an = 1, 6 mois = 0,5 ...) :" << endl;
            cin >> a;
            if(a > 0)
            {
                date_dividende = a;
            }
            else
            {
                cout << "Erreur de saisie !" << endl;
                break;
            }
        }

        if(type_opt == "Call Europeen")
        {
            opt = new CallOptionEuropeenne(maturity, strike, spot, type_opt, 0, 0);

        }
        else if(type_opt == "Put Europeen")
        {
            opt = new PutOptionEuropeenne(maturity, strike, spot, type_opt, 0, 0);

        }
        else if(type_opt == "Call Americain")
        {
            opt = new CallOptionAmericain(maturity, strike, spot, type_opt, dividende, date_dividende);
        }
        else if(type_opt == "Put Americain")
        {
            opt = new PutOptionAmericain(maturity, strike, spot, type_opt, dividende, date_dividende);
        }
        else if(type_opt == "Call Asiatique")
        {
            opt = new CallOptionAsiatique(maturity, strike, spot, type_opt, 0, 0);
        }
        else
        {
            opt = new PutOptionAsiatique(maturity, strike, spot, type_opt, 0, 0);
        }

cout << "---------------------------------------------------------------------------------------" << endl;

a=0;
double b = 0;
while(b == 0)
{
    cout << "Veuillez saisir la volatilite pour l'actif concerne (en pourcentage) :" << endl;
    cin >> a;
    if (a>0)
        {
            volatility = a/100.0;
        }
    else
        {
            cout << "Erreur de saisie\n" <<endl;;
        }

    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "Veuillez saisir le taux sans risque (en pourcentage):" << endl;
    cin >> a;
    if (a>0)
        {
            rate = a/100.0;

        }
    else
        {
          cout << "Erreur de saisie\n" <<endl;;
          break;
        }


    b = 1;
}
cout << "---------------------------------------------------------------------------------------" << endl;
mkt =new MarketData(rate, volatility);
choix = 0;
while(choix == 0)
{
    cout << "Veuillez saisir le numero du modele de pricing desire :" << endl;
    cout << "1- Modele de pricing Black and Scholes formule fermee (disponible que pour les options europeenne)" << endl;
    cout << "2- Modele de pricing de MonteCarlo (disponible pour tous les types d'actifs)" << endl;
    cin >> a;
    if(a == 1)
        {
            cout << "---------------------------------------------------------------------------------------" << endl;
            string type_modele="BSFF";
            int nombre_simulation = 0;
            double pas_discretisation = 0;
            double prix = 0;
            mod = new FormuleFermee(type_modele, nombre_simulation, pas_discretisation, prix);
            mod->ajouter_option(opt);
            mod->ajouter_market(mkt);
            mod->pricing_model();
            mod->affiche_pricing();
            cout << "---------------------------------------------------------------------------------------" << endl;
            Greeks *D = new Delta();
            D->ajouter_market(mkt);
            D->ajouter_modele(mod);
            D->ajouter_option(opt);
            D->pricing_greeks();
            D->affiche_greeks();
            Greeks *G = new Gamma();
            G->ajouter_market(mkt);
            G->ajouter_modele(mod);
            G->ajouter_option(opt);
            G->pricing_greeks();
            G->affiche_greeks();
            Greeks *V = new Vega();
            V->ajouter_market(mkt);
            V->ajouter_modele(mod);
            V->ajouter_option(opt);
            V->pricing_greeks();
            V->affiche_greeks();
            Greeks *R = new Rho();
            R->ajouter_market(mkt);
            R->ajouter_modele(mod);
            R->ajouter_option(opt);
            R->pricing_greeks();
            R->affiche_greeks();
            Greeks *T = new Theta();
            T->ajouter_market(mkt);
            T->ajouter_modele(mod);
            T->ajouter_option(opt);
            T->pricing_greeks();
            T->affiche_greeks();
            cout << "---------------------------------------------------------------------------------------" << endl;


        }
    else if (a == 2)
        {
            string type_modele="MC";
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "Veuillez indiquer le nombre de simulations que vous souhaitez realiser par MonteCarlo : " <<endl;
            int nombre_simulation;
            cin >> nombre_simulation;
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "Veuillez indiquer le pas de temps de la discretisation : ";
            double pas_discretisation;
            cin >> pas_discretisation;
            double prix = 0;
            Modele *mod = new MonteCarlo(type_modele, nombre_simulation, pas_discretisation, prix);
            mod->ajouter_option(opt);
            mod->ajouter_market(mkt);
            mod->pricing_model();
            cout << "---------------------------------------------------------------------------------------" << endl;
            mod->affiche_pricing();
            cout << "---------------------------------------------------------------------------------------" << endl;
        }
    else
        {   cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "Erreur de saisie du modele" << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            break;
        }

}


}

cout << "---------------------------------------------------------------------------------------" << endl;
}

