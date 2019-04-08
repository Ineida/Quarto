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
    Grille();
    Pion** laGrille() const;
    void setXY(int x, int y);
    bool estVide(int x, int y);
    Pion reserver(Pion);
    
};


#endif /* GRILLE_H */

