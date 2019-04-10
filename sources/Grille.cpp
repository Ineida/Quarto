/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Header/Grille.h"
#include "Header/Pion.h"
#include "stdlib.h"

//#define NULL ((void*)0)
//#define null 0
using namespace std;



/**
   * @brief Grille::Grille
   *  Construteur de la grille
   * renvoie la liste des pions disponibles
   * et la grille
   */
  Grille::Grille(){
    bool claire=true;
    bool grand=true;
    bool troue=true;
    bool carree=true;
    grille=new Pion*[4];
    for(int i=0; i<4; i++)
    {
        grille[i]=new Pion[4];
        for(int j=0; j<4; j++)
        {
            grille[i][j]=Pion();//pion null
        }
     }
     listePionDispo=new Pion*[2];
    for(int i=0; i<2; i++)
    {
        listePionDispo[i]=new Pion[8];
        claire=!claire;
        for(int j=0; j<8; j++)
        {
            grand=!grand;
            if(j%2==0){
                troue=!true;
                if(j%4==0)
                {
                    carree=!carree;
                }
            }
        listePionDispo[i][j]=Pion(claire,grand,carree,troue);
        }
    }
   }


  /**
   * @brief Grille::reserver
   * @param claire
   * @param grand
   * @param carree
   * @param troue
   * @return un pion avec les cateristiques places en paramêtre
   */
  Pion Grille::reserver(Pion p){
      Pion resultat=Pion();
      Pion** tampon = new Pion*[2];
      for (int i=0;i<2;i++)
      {
          tampon[i]=new Pion[8];
          for(int j=0;j<8;j++){
              if(this->listePionDispo[i][j].sontEgaux(p)){
                resultat=listePionDispo[i][j];
                this->reserve=listePionDispo[i][j];
              }
              else{
                  tampon[i][j]=listePionDispo[i][j];
              }
          }
      }
      return resultat;
  }


  /**
  * @brief Grille::estVide
  * @param x
  * @param y
  * @return true si la case à la position (x,y) de la grille est vide
  */
 bool Grille::estVide(int x, int y){
    bool vide = false;
       if(grille[x][y].estNulle()){
           vide = true;
       }
    return vide;
   }
   

 /**
   * @brief Grille::laGrille
   * @return l'état de la grille
   */
  Pion** Grille::laGrille()const{
       return Grille::grille;
   }


  /**
    * @brief Grille::setXY
    * @param x
    * @param y
    * @param valeur
    * permet de mettre le pion reservé dans une case de la grille, à la X-ieme ligne et à la Y-iéme colonne
    */
   void Grille::setXY(int x, int y){
       if(!reserve.estNulle()){
            if(estVide(x,y)){
                grille[x][y]=reserve;
            }
       }
     }
   

   bool Grille::gagnerLigne(int i){
       bool gagner=false;
       if(i<=3 && i>=0){
        if((grille[i][0].estGrand()==grille[i][1].estGrand()==grille[i][2].estGrand()==grille[i][3].estGrand()) //caractéristique grande
          ||(grille[i][0].estCarree()==grille[i][1].estCarree()==grille[i][2].estCarree()==grille[i][3].estCarree())//caractéristique carrée
          ||(grille[i][0].estTroue()==grille[i][1].estTroue()==grille[i][2].estTroue()==grille[i][3].estTroue())
          ||(grille[i][0].estClaire()==grille[i][1].estClaire()==grille[i][2].estClaire()==grille[i][3].estClaire()))
            { gagner=true;}
       }
       return gagner;
   }
   
   bool Grille::gagnerColonne(int i){
       bool gagner=false;
       if(i<=3 && i>=0){
        if((grille[0][i].estGrand()==grille[1][i].estGrand()==grille[2][i].estGrand()==grille[3][i].estGrand()) //caractéristique grande
          ||(grille[0][i].estCarree()==grille[1][i].estCarree()==grille[2][i].estCarree()==grille[3][i].estCarree())//caractéristique carrée
          ||(grille[0][i].estTroue()==grille[1][i].estTroue()==grille[2][i].estTroue()==grille[3][i].estTroue())
          ||(grille[0][i].estClaire()==grille[1][i].estClaire()==grille[2][i].estClaire()==grille[3][i].estClaire()))
            { gagner=true;}
       }
       return gagner;
   }
   bool Grille::gagnerDiagonal(){

       bool gagner=false;
       //DIAGONAL descendante
        if((grille[0][0].estGrand()==grille[1][1].estGrand()==grille[2][2].estGrand()==grille[3][3].estGrand()) //caractéristique grande
          ||(grille[0][0].estCarree()==grille[1][1].estCarree()==grille[2][2].estCarree()==grille[3][3].estCarree())//caractéristique carrée
          ||(grille[0][0].estTroue()==grille[1][1].estTroue()==grille[2][2].estTroue()==grille[3][3].estTroue())
          ||(grille[0][0].estClaire()==grille[1][1].estClaire()==grille[2][2].estClaire()==grille[3][3].estClaire()))
            { gagner=true;}
        //DIAGONAL montante
        if ((grille[3][0].estGrand()==grille[2][1].estGrand()==grille[1][2].estGrand()==grille[0][3].estGrand()) //caractéristique grande
                 ||(grille[3][0].estCarree()==grille[2][1].estCarree()==grille[1][2].estCarree()==grille[0][3].estCarree())//caractéristique carrée
                 ||(grille[3][0].estTroue()==grille[2][1].estTroue()==grille[1][2].estTroue()==grille[3][0].estTroue())
                 ||(grille[3][0].estClaire()==grille[2][1].estClaire()==grille[1][2].estClaire()==grille[0][3].estClaire())) {
            gagner=true;
        }

       return gagner;
   }


   bool Grille::gagner(){
       //verification horizontal
       bool gagner=false;
       for(int i=0;i<4;i++){
           if(gagnerLigne(i)||gagnerColonne(i)){gagner=true;}
       }
           if(gagnerDiagonal()){gagner=true;}
           return gagner;
   }
   
   
   
