/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille.h
 * Author: cardo
 *
 * Created on 19 février 2019, 15:36
 */

#ifndef GRILLE_H
#define GRILLE_H
#include "Pion.h"  

class Grille{
private:
    Pion** grille;
    Pion** listePionDispo;
    Pion reserve;
    
public:
    //constructeur
    Grille();
    //getteurs et setteurs
    Pion** laGrille() const;
    void setXY(int x, int y);
    //autres methodes
    bool estVide(int x, int y);
    Pion reserver(Pion);
    bool gagner();
    bool gagnerLigne(int i);
    bool gagnerColonne(int i);
    bool gagnerDiagonal();
};


#endif /* GRILLE_H */

