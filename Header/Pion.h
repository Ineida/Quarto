/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pion.h
 * Author: cardo
 *
 * Created on 19 février 2019, 13:40
 */

#ifndef PION_H
#define PION_H
class Pion{
private:
    bool claire;
    bool troue;
    bool carree;
    bool grand;
    bool estNull;
    
public:
    Pion(bool claire, bool grand, bool carree, bool troue, bool estNull);
    Pion(bool claire, bool grand, bool carree, bool troue);
    Pion(bool estNull);
    Pion();
    bool estCarree();
    bool estGrand();
    bool estClaire();
    bool estTroue();
    bool sontEgaux(Pion p2);
    bool estNulle();
    void setNull(bool estNull);
    
    
};


#endif /* PION_H */

