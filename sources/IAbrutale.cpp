#include "Header/IAbrutale.h"

//constructeur
IAbrutale::IAbrutale(Grille grille)
{
    this->grille=grille;
}

//getteurs et setteurs
Grille IAbrutale::getGrille(){return this->grille;}
void IAbrutale::setGrille(Grille grille){this->grille=grille;}

//autres methodes
void IAbrutale::choixCase(){};
void IAbrutale::choixPion(){};
