#ifndef IAOPTIMISEE_H
#define IAOPTIMISEE_H
#include "Joueur.h"
class IAoptimisee{
private:

    Joueur joueur;
    Grille grille;
public:
    //constructeur
    IAoptimisee(Joueur j, Grille grille);
    //getteurs et setteurs
    Joueur getJoueur();
    Grille getGrille();
    void setGrille(Grille grille);
    // autres methodes
    void choixPion();
    void choixCase();
};
#endif // IAOPTIMISEE_H
