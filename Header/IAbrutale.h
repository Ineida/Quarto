#ifndef IA_H
#define IA_H
#include "Joueur.h"

class IAbrutale
{

    private:
        Joueur joueur;
        Grille grille;
    public:
        //constructeur
        IAbrutale(Joueur j, Grille grille);
        //getteurs et setteurs
        Joueur getJoueur();
        Grille getGrille();
        void setGrille(Grille grille);
        // autres methodes
        void choixPion();
        void choixCase();
};

#endif // IA_H
