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
#include "iostream"


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
    reserve=Pion();
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
  Pion Grille::getXY(int x, int y){return grille[x][y];};

  Pion** Grille::getListePionDispo(){return this->listePionDispo;}

  /**
 * @brief Grille::getReserve
 * @return le pion reserve (choisit pour joueur)
 */
Pion Grille::getReserve(){return this->reserve;}

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
                reserve= Pion();
            }
       }
     }
   void Grille::setXY(int x, int y, Pion valeur){
            if(estVide(x,y)){
                grille[x][y]=valeur;
                reserve= Pion();
            }

     }
   /**
    * @brief Grille::GrandEnLigne
    * @param i
    * @return vrai si 4 pions grandes dans la ligne i
    */
   bool Grille:: grandEnLigne(int i){
       bool vrai=false;
       if(!grille[i][0].estNulle() && !grille[i][1].estNulle()
               && !grille[i][2].estNulle() && !grille[i][3].estNulle())
       {
           if(grille[i][0].estGrand()==grille[i][1].estGrand()&&
                  grille[i][1].estGrand()==grille[i][2].estGrand()&&
                   grille[i][2].estGrand()==grille[i][3].estGrand()){ vrai=true;}
       }
       return vrai;
   }
   /**
    * @brief Grille::carreeEnLigne
    * @param i
    * @return vrai si 4 pions carres dans la ligne i
    */
   bool Grille:: carreeEnLigne(int i){
       bool vrai=false;
        if(!grille[i][0].estNulle() && !grille[i][1].estNulle()
               && !grille[i][2].estNulle() && !grille[i][3].estNulle())
       {
           if(grille[i][0].estCarree()==grille[i][1].estCarree()&&
               grille[i][1].estCarree()==grille[i][2].estCarree()&&
               grille[i][2].estCarree()==grille[i][3].estCarree())
           { vrai=true;}
       }
       return vrai;
   }
   /**
    * @brief Grille::claireEnLigne
    * @param i
    * @return vrai si 4 pions claires dans la ligne i
    */
   bool Grille:: claireEnLigne(int i){
       bool vrai=false;
       if(!grille[i][0].estNulle() && !grille[i][1].estNulle()
               && !grille[i][2].estNulle() && !grille[i][3].estNulle())
       {
           if(grille[i][0].estClaire()==grille[i][1].estClaire()&&
                   grille[i][1].estClaire()==grille[i][2].estClaire() &&
                   grille[i][2].estClaire()==grille[i][3].estClaire() )
           { vrai=true;}
       }
       return vrai;
   }
   /**
    * @brief Grille::troueEnLigne
    * @param i
    * @return vrai si 4 pions troues dans la ligne i
    */
   bool Grille:: troueEnLigne(int i){
       bool vrai=false;
       if(!grille[i][0].estNulle() && !grille[i][1].estNulle()
               && !grille[i][2].estNulle() && !grille[i][3].estNulle())
       {
           if(grille[i][0].estTroue()==grille[i][1].estTroue()&&
                   grille[i][1].estTroue()==grille[i][2].estTroue()&&
                   grille[i][2].estTroue()==grille[i][3].estTroue())
           { vrai=true;}
       }
       return vrai;
   }
   /**
    * @brief Grille::GrandEnColonne
    * @param i
    * @return vrai si 4 pions grandes dans la colonne i
    */
   bool Grille:: grandEnColonne(int i){
       bool vrai=false;
       if(!grille[0][i].estNulle() && !grille[1][i].estNulle()
               && !grille[2][i].estNulle() && !grille[3][i].estNulle())
       {
           if(grille[0][i].estGrand()==grille[1][i].estGrand() &&
               grille[1][i].estGrand()==grille[2][i].estGrand()&&
               grille[2][i].estGrand()==grille[3][i].estGrand()){ vrai=true;}
       }
       return vrai;
   }
   /**
    * @brief Grille::carreeEnColonne
    * @param i
    * @return vrai si 4 pions carres dans la colonne i
    */
   bool Grille:: carreeEnColonne(int i){
       bool vrai=false;
       if(!grille[0][i].estNulle() && !grille[1][i].estNulle()
               && !grille[2][i].estNulle() && !grille[3][i].estNulle())
       {
           if(grille[0][i].estCarree()==grille[1][i].estCarree()&&
                   grille[1][i].estCarree()==grille[2][i].estCarree() &&
                   grille[2][i].estCarree()==grille[3][i].estCarree())
           { vrai=true;}
       }
       return vrai;
   }
   /**
    * @brief Grille::claireEnColonne
    * @param i
    * @return vrai si 4 pions claires dans la colonne i
    */
   bool Grille:: claireEnColonne(int i){
       bool vrai=false;
       if(!grille[0][i].estNulle() && !grille[1][i].estNulle()
               && !grille[2][i].estNulle() && !grille[3][i].estNulle())
       {
           if(grille[0][i].estClaire()==grille[1][i].estClaire() &&
                grille[1][i].estClaire()==grille[2][i].estClaire() &&
                grille[2][i].estClaire()==grille[3][i].estClaire())
           { vrai=true;}
       }
       return vrai;
   }
   /**
    * @brief Grille::troueEnColonne
    * @param i
    * @return vrai si 4 pions troues dans la colonne i
    */
   bool Grille:: troueEnColonne(int i){
       bool vrai=false;
       if(grille[0][i].estNulle()==false && grille[1][i].estNulle()==false
               && grille[2][i].estNulle()==false && grille[3][i].estNulle()==false)
       {
           if( grille[0][i].estTroue()==grille[1][i].estTroue() &&
                   grille[1][i].estTroue()==grille[2][i].estTroue() &&
                   grille[2][i].estTroue()==grille[3][i].estTroue() )
           { vrai=true;}
       }
       return vrai;
   }

   /**
    * @brief Grille::gagnerLigne
    * @param i
    * @return vrai si la ligne i contient 4 pions avec une caracteristique pareille
    */
   bool Grille::gagnerLigne(int i){
       bool gagner=false;
       if(i<=3 && i>=0){
            if(grandEnLigne(i)//caractéristique grande
          ||carreeEnLigne(i)//caractéristique carrée
          ||troueEnLigne(i)//caractéristique Troue
          ||claireEnLigne(i))//caractéristique claire)
            { gagner=true;}
       }
       return gagner;
   }
   /**
    * @brief Grille::gagnerColonne
    * @param i
    * @return vrai si la colonne i contient 4 pions avec une caracteristique pareille
    */
   bool Grille::gagnerColonne(int i){
       bool gagner=false;
       if(i<=3 && i>=0){
           if(grandEnColonne(i)//caractéristique grande
          ||carreeEnColonne(i)//caractéristique carrée
          ||troueEnColonne(i)//caractéristique Troue
          ||claireEnColonne(i)//caractéristique claire
           )
            { gagner=true;}
       }
       return gagner;
   }
   /**
    * @brief Grille::gagnerDiagonal
    * @return vrai si une des diagonales contient 4 pions avec une caracteristique pareille
    */
   bool Grille::gagnerDiagonal(){

       bool gagner=false;
       //DIAGONAL descendante
       if(!grille[0][0].estNulle()){
           if((grille[0][0].estGrand()==grille[1][1].estGrand()&& !grille[1][1].estNulle() &&
               grille[1][1].estGrand()==grille[2][2].estGrand()&& !grille[2][2].estNulle() &&
               grille[2][2].estGrand()==grille[3][3].estGrand() && !grille[3][3].estNulle())
                   //caractéristique grande
          ||(grille[0][0].estCarree()==grille[1][1].estCarree() && !grille[1][1].estNulle() &&
             grille[1][1].estCarree()==grille[2][2].estCarree()&& !grille[2][2].estNulle() &&
             grille[2][2].estCarree()==grille[3][3].estCarree() && !grille[3][3].estNulle())
                   //caractéristique carrée
          ||(grille[0][0].estTroue()==grille[1][1].estTroue() && !grille[1][1].estNulle() &&
             grille[1][1].estTroue()==grille[2][2].estTroue()&& !grille[2][2].estNulle()&&
             grille[2][2].estTroue()==grille[3][3].estTroue() && !grille[3][3].estNulle())
                   //caractéristique Troue
          ||(grille[0][0].estClaire()==grille[1][1].estClaire() && !grille[1][1].estNulle() &&
             grille[1][1].estClaire()==grille[2][2].estClaire()&&  !grille[2][2].estNulle()&&
             grille[2][2].estClaire()==grille[3][3].estClaire() && !grille[3][3].estNulle())
                   //caractéristique claire
                   )
            { gagner=true;}}

        //DIAGONAL montante
           if(!grille[3][0].estNulle()){
                if((grille[3][0].estGrand()==grille[2][1].estGrand()&&!grille[2][1].estNulle()&&
                    grille[2][1].estGrand()==grille[1][2].estGrand()&& !grille[1][2].estNulle()&&
                    grille[1][2].estGrand()==grille[0][3].estGrand() && !grille[0][3].estNulle())
                        //caractéristique grande
                 ||(grille[3][0].estCarree()==grille[2][1].estCarree()&& !grille[2][1].estNulle()&&
                    grille[2][1].estCarree()==grille[1][2].estCarree() && !grille[1][2].estNulle()&&
                    grille[1][2].estCarree()==grille[0][3].estCarree() && !grille[0][3].estNulle())
                        //caractéristique carrée
                 ||(grille[3][0].estTroue()==grille[2][1].estTroue()&& !grille[2][1].estNulle()&&
                    grille[2][1].estTroue()==grille[1][2].estTroue() && !grille[1][2].estNulle()&&
                    grille[1][2].estTroue()==grille[0][3].estTroue() && !grille[0][3].estNulle())
                        //caractéristique Troue
                 ||(grille[3][0].estClaire()==grille[2][1].estClaire()&& !grille[2][1].estNulle()&&
                    grille[2][1].estClaire()==grille[1][2].estClaire() && !grille[1][2].estNulle()&&
                    grille[1][2].estClaire()==grille[0][3].estClaire() && !grille[0][3].estNulle())
                        //caractéristique claire
                        )
                {gagner=true;}}


       return gagner;
   }

   /**
    * @brief Grille::gagner
    * @return  vrai on a 4 pions avec la même caractéristique alignes.
    */
   //marche pas
   bool Grille::gagner(){
       //verification horizontal
       bool gagner=false;
       for(int i=0;i<4;i++){
           if(gagnerLigne(i)||gagnerColonne(i)){gagner=true;}
       }
       if(gagnerDiagonal()){gagner=true;}
       return gagner;
   }
   
   
   
   
   
   int main(int argc,char* argv[]){
       Grille g= Grille();
       g.setXY(1,1,Pion(true,true,true,true));
       // std::cout << "Pion :"<< g.getXY(1,1).estCarree()<<"     "<<  g.getXY(1,1).estGrand()<<"     "<< g.getXY(1,1).estClaire()<<"     "<<g.getXY(1,1).estTroue()<<"     "<< g.getXY(1,1).estNulle() <<"     ";
       g.setXY(2,1,Pion(true,false,true,true));

       g.setXY(3,1,Pion(true,true,false,true));

       g.setXY(0,1,Pion(true,true,true,false));


       std::cout << "gagner :"<< g.gagnerLigne(1) <<endl;
   }
