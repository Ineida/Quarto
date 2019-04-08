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
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            grille[i][j]=Pion();//pion null
        }
     }
    for(int i=0; i<2; i++)
    {
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
      Pion** tampon = nullptr;
      for (int i=0;i<2;i++)
      {
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
   

   

   
   
   
   
