#include "IAbrutale.h"

//constructeur
IAbrutale::IAbrutale(Joueur j, Grille grille)
{
    this->joueur=j;
    this->grille=grille;
}

//getteurs et setteurs
Grille IAbrutale::getGrille(){return this->grille;}
Joueur IAbrutale::getJoueur(){return this->joueur;}
void IAbrutale::setGrille(Grille grille){this->grille=grille;}

//autres methodes
void IAbrutale::choixCase(){};
void IAbrutale::choixPion(){};
