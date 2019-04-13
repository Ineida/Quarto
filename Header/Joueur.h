#ifndef JUEUR_H
#define JUEUR_H
#include "Grille.h"
#include "iostream"
#include "list"
 class Joueur{
 private:
     Grille grilleJeu;
     int niveau;
 public:
     // contructeurs
     Joueur(Grille grille);
     Joueur(int niveau, int adversaire,Grille grille);// si on arrive à avoir 2 IA
     //getteurs et setteurs
      void setGrille(Grille grille);
      Grille getGrille();
      //autres methodes
      std::list<int> choixCase();
      Pion choixPoin(std::list<int>ListePionDispo);
      Pion choixPoin(std::list<std::list<Pion>> ListePionDispo);
      //void choisirNiveau();
};

#endif // JUEUR_H
