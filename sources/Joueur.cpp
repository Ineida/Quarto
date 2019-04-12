#include "Header/Joueur.h"

Joueur::Joueur(){
    this->adversaire=0; //par defaut IA.
}

Joueur::Joueur(int adversaire){
    this->adversaire=adversaire%2; //paire IA impoaire Joueur.
}
