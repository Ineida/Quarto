 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pion.cpp
 * Author: cardo
 *
 * Created on 19 février 2019, 13:59
 */

#include "Header/Pion.h"
using namespace std;


/*
 * Construteur, qui prend en parametres les 4 booleans: carrée, grand, claire, troué
 */
Pion::Pion(bool carree, bool grand,bool claire, bool troue, bool estNull){
    this->carree=carree;
    this->grand=grand;
    this->claire=claire;
    this->troue=troue;
    this->estNull=estNull;
}
Pion::Pion(bool carree, bool grand,bool claire, bool troue){
    this->carree=carree;
    this->grand=grand;
    this->claire=claire;
    this->troue=troue;
    this->estNull=false;
}

/*
 * Initialise un Pion a null.
 */
Pion::Pion(){
    this->estNull=true;
    this->carree=false;
    this->grand=false;
    this->claire=false;
    this->troue=false;
}

/*
 * renvoie vrai si un pion est troué et false sinon
 */
bool Pion::estTroue(){
    return troue;
}


/*
 * renvoie vrai si un pion est carrée et false sinon
 */
bool Pion::estCarree(){
    return carree;
}

/*
 * renvoie vrai si un pion est claire et false sinon
 */
bool Pion::estClaire(){
    return claire;
}

/*
 * renvoie vrai si un pion est Grand et false sinon
 */
bool Pion::estGrand(){
    return grand;
}

/*
 *Verifie si un pion est null ou pas 
 */
bool Pion::estNulle(){
    return estNull;
}

/*
 * dit si un pion est null ou pas.
 */

 /*
* Comparer si deux pion sont egaux
 */
bool Pion::sontEgaux(Pion p2){
    bool egaux=false;
    if(this->estCarree()==p2.estCarree() && this->estClaire()==p2.estClaire()
            && this->estGrand()==p2.estGrand() && this->estTroue()==p2.estTroue())
        egaux=true;
    return egaux;
 }

 



/*
 * 
 */


