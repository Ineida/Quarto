#ifndef JEU_H
#define JEU_H
#include "Joueur.h"
#include "IAbrutale.h"
#include "IAoptimisee.h"
class Jeu{
private:
    Joueur joueur1;
    Joueur joueur2;
    IAbrutale ia;
    IAoptimisee IA;


};

#endif // JEU_H
