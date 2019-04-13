#include "Header/Joueur.h"
#include "iostream"
Joueur::Joueur(Grille grille){
    this->grilleJeu=grille; //par defaut IA.
}
Grille Joueur::getGrille(){return grilleJeu;}
std::list<int>Joueur::choixCase(){
    int ligne;
    int colonne;
    int valeur=-1;
    while(valeur<0||valeur>15){
        std::cout<< "Rentrez la case voulu (les cases sont numerotes de 0 à 15)"<< std::endl;
        std::cin>> valeur;

    }
    colonne=valeur%4;
    if(valeur<4){ligne=valeur;}
    else if(valeur>3 && valeur<8){ligne=(valeur-4)%4;}
    else {ligne=(valeur-8)%4;}
    return std::list<int>{ligne,colonne};
}

Pion Joueur::choixPoin(std::list<int>ListePionDispo){
    int ligne;
    int colonne;
    int valeur=-1;
    int valeurmax=ListePionDispo.size()-1;
    Pion pion;
    while(valeur<0||valeur>valeurmax){
        std::cout<< "Rentrez le Pion voulu (les cases sont numerotes de 0 à "<< ListePionDispo.size()<<")"<< std::endl;
        std::cin>> valeur;

    }
    colonne=valeur%4;
    if(valeur<8){ligne=1;}
    else {ligne=2;}
    //pion=this->getGrille().getListePionDispo().getXY(ligne,colonne); cette partie est encore à revoir en fonction de comment on gere les pions dispo
    return pion;
}
