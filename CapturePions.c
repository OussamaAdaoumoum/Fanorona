#include "CapturePions.h"
#include <stdlib.h>
#include <stdio.h>


void Capture_Pions(int Colonne1,int Colonne2,int Ligne1,int Ligne2,int *pc,char tableau[5][9],char pBN){

    // go up
    if(Colonne1==Colonne2 && Ligne1>Ligne2){

            int cTop=0;
            int cButtoom=0;
            int i=Ligne2-1;

            while(tableau[i-1][Colonne2-1]!=pBN && tableau[i-1][Colonne2-1]!=' ' && i>0){
                    cTop++;
                    i--;
                    }

            i=Ligne1-1;
            while(tableau[i+1][Colonne2-1]!=pBN && tableau[i+1][Colonne2-1]!=' ' && i<4){
                    cButtoom++;
                    i++;
                    }

            if(cTop>=cButtoom){
                    for(i=Ligne2-1;i>0;i--){
                        if (tableau[i-1][Colonne2-1]!=pBN && tableau[i-1][Colonne2-1]!=' '){
                            tableau[i-1][Colonne2-1]=' ';
                            *pc=*pc+1;
                            }

                        else{
                                break;
                        }
                    }
                }

            else{
                    for(i=Ligne1-1;i<4 ;i++){
                        if (tableau[i+1][Colonne2-1]!=pBN && tableau[i+1][Colonne2-1]!=' '){

                            tableau[i+1][Colonne2-1]=' ';
                            *pc=*pc+1;
                            }

                        else{
                                break;
                        }
                    }
                }
            }




    // go Buttoom
    if(Colonne1==Colonne2 && Ligne1<Ligne2){

            int cTop=0;     //compteur des pions possible à capturer en haut
            int cButtoom=0; //compteur des pions possible à capturer en bas
            int i=Ligne1-1;

            while(tableau[i-1][Colonne2-1]!=pBN && tableau[i-1][Colonne2-1]!=' ' && i>0){
                    cTop++;
                    i--;
                    }

            i=Ligne2-1;
            while(tableau[i+1][Colonne2-1]!=pBN && tableau[i+1][Colonne2-1]!=' ' && i<4){
                    cButtoom++;
                    i++;
                }

            if(cTop>=cButtoom){
                    for(i=Ligne1-1;i>0;i--){
                        if (tableau[i-1][Colonne2-1]!=pBN && tableau[i-1][Colonne2-1]!=' '){
                                tableau[i-1][Colonne2-1]=' ';
                                *pc=*pc+1;
                                }
                        else{
                                break;
                }
            }
        }

            else{
                    for(i=Ligne2-1;i<4;i++){
                        if (tableau[i+1][Colonne2-1]!=pBN && tableau[i+1][Colonne2-1]!=' '){
                            tableau[i+1][Colonne2-1]=' ';
                            *pc=*pc+1;
                    }

                        else{
                                break;
                        }
                    }
                }
            }





    // go right
    if(Ligne1==Ligne2 && Colonne1+1==Colonne2){

            int cRight=0; //compteur des pions possible à capturer à droite
            int cLeft=0;  //compteur des pions possible à capturer à gauche
            int j=Colonne2-1;

            while(tableau[Ligne1-1][j+1]!=pBN && tableau[Ligne1-1][j+1]!=' ' && j<8){
                    cRight++;
                    j++;
                }

            j=Colonne1-1;
            while(tableau[Ligne1-1][j-1]!=pBN && tableau[Ligne1-1][j-1]!=' ' && j>0){
                    cLeft++;
                    j--;
                }

            if(cRight>=cLeft){
                for(j=Colonne2-1;j<8;j++){
                    if (tableau[Ligne1-1][j+1]!=pBN && tableau[Ligne1-1][j+1]!=' '){
                        tableau[Ligne1-1][j+1]=' ';
                        *pc=*pc+1;
            }

                    else{
                        break;
                    }
                }
            }

            else{
                    for(j=Colonne1-1;j>0;j--){
                        if (tableau[Ligne1-1][j-1]!=pBN && tableau[Ligne1-1][j-1]!=' '){
                            tableau[Ligne1-1][j-1]=' ';
                            *pc=*pc+1;
                        }

                        else{
                                break;
                    }
                }
            }
        }



    // go left
    if(Ligne1==Ligne2 && Colonne1-1==Colonne2){

        int cRight=0;//compteur des pions possible à capturer à droite
        int cLeft=0;//compteur des pions possible à capturer à gauche
        int j=Colonne1-1;

            while(tableau[Ligne1-1][j+1]!=pBN && tableau[Ligne1-1][j+1]!=' ' && j<8){
                cRight++;
                j++;
            }

            j=Colonne2-1;
            while(tableau[Ligne1-1][j-1]!=pBN && tableau[Ligne1-1][j-1]!=' ' && j>0){
                cLeft++;
                j--;
            }

            if(cRight>=cLeft){
                    for(j=Colonne1-1;j<8;j++){
                        if (tableau[Ligne1-1][j+1]!=pBN && tableau[Ligne1-1][j+1]!=' '){

                        tableau[Ligne1-1][j+1]=' ';
                        *pc=*pc+1;
                    }

                        else{
                                break;
                    }
                }
            }

                        else{
                                for(j=Colonne2-1;j>0;j--){
                                    if (tableau[Ligne1-1][j-1]!=pBN && tableau[Ligne1-1][j-1]!=' '){
                                        tableau[Ligne1-1][j-1]=' ';
                                        *pc=*pc+1;
                                        }

                                    else{
                                        break;
                                }
                            }
                        }
                    }






    // go up right
    if(Ligne1-1==Ligne2 && Colonne1+1==Colonne2 ){

            int cTopRight=0;//compteur des pions possible à capturer en haut à droite
            int cButtoomLeft=0;//compteur des pions possible à capturer en bas à gauche
            int j=Colonne2-1,i=Ligne2-1;

            while(tableau[i-1][j+1]!=pBN && tableau[i-1][j+1]!=' ' && j<8 && i>0){
                    cTopRight++;
                    j++;
                    i--;
                }

            j=Colonne1-1;
            i=Ligne1-1;

            while(tableau[i+1][j-1]!=pBN && tableau[i+1][j-1]!=' ' && j>0 && i<4){
                    cButtoomLeft++;
                    j--;
                    i++;
                }
            if(cTopRight>=cButtoomLeft){
                for(i=Ligne2-1,j=Colonne2-1;j<8 && i>0;j++,i--){
                    if (tableau[i-1][j+1]!=pBN && tableau[i-1][j+1]!=' '){
                        tableau[i-1][j+1]=' ';
                        *pc=*pc+1;
                    }

                    else{
                        break;
                    }
                }
            }
                    else{

                        for(i=Ligne1-1,j=Colonne1-1;j>0 && i<4;j--,i++){
                            if (tableau[i+1][j-1]!=pBN && tableau[i+1][j-1]!=' '){
                                tableau[i+1][j-1]=' ';
                                *pc=*pc+1;
                                }

                            else{
                                break;
                        }
                    }
                }
            }





    // go up left

    if(Ligne1-1==Ligne2 && Colonne1-1==Colonne2 ){

            int cTopLeft=0;//compteur des pions possible à capturer en haut à gauche
            int cButtoomRight=0;//compteur des pions possible à capturer en bas à droite
            int j=Colonne2-1,i=Ligne2-1;

            while(tableau[i-1][j-1]!=pBN && tableau[i-1][j-1]!=' ' && j>0 && i>0){
                    cTopLeft++;
                    j--;
                    i--;
                }

            j=Colonne1-1;
            i=Ligne1-1;
            while(tableau[i+1][j+1]!=pBN && tableau[i+1][j+1]!=' ' && j<8 && i<4){
                cButtoomRight++;
                j++;
                i++;
            }

            if(cTopLeft>=cButtoomRight){
                for(i=Ligne2-1,j=Colonne2-1;j>0 && i>0;j--,i--){
                    if (tableau[i-1][j-1]!=pBN && tableau[i-1][j-1]!=' '){
                        tableau[i-1][j-1]=' ';
                        *pc=*pc+1;
                    }

                    else{
                        break;
                    }
                }
            }
                    else{
                        for(i=Ligne1-1,j=Colonne1-1;j<8 && i<4 ;j++,i++){
                            if (tableau[i+1][j+1]!=pBN && tableau[i+1][j+1]!=' '){
                                tableau[i+1][j+1]=' ';
                                *pc=*pc+1;
                        }

                            else{
                                break;
                            }
                        }
                    }
                }





    // go down right
    if(Ligne1+1==Ligne2 && Colonne1+1==Colonne2 && (Ligne1+Colonne1)%2==0 && (Ligne2+Colonne2)%2==0){

            int cButtoomRight=0;//compteur des pions possible à capturer en bas à droite
            int cTopLeft=0;//compteur des pions possible à capturer en haut à gauche
            int j=Colonne1-1,i=Ligne1-1;

            while(tableau[i-1][j-1]!=pBN && tableau[i-1][j-1]!=' ' && j>0 && i>0){
                    cTopLeft++;
                    j--;
                    i--;
            }


            j=Colonne2-1;
            i=Ligne2-1;
            while(tableau[i+1][j+1]!=pBN && tableau[i+1][j+1]!=' ' && j<8 && i<4){
                cButtoomRight++;
                j++;
                i++;
            }

            if(cTopLeft>=cButtoomRight){
                    for(i=Ligne1-1,j=Colonne1-1;j>0 && i>0;j--,i--){
                        if (tableau[i-1][j-1]!=pBN && tableau[i-1][j-1]!=' '){

                            tableau[i-1][j-1]=' ';
                            *pc=*pc+1;
            }
                        else{
                            break;
                        }
                    }
                }

                        else{
                                for(i=Ligne2-1,j=Colonne2-1;j<8 && i<4 ;j++,i++){
                                    if (tableau[i+1][j+1]!=pBN && tableau[i+1][j+1]!=' '){
                                        tableau[i+1][j+1]=' ';
                                        *pc=*pc+1;
                                        }

                                    else{
                                            break;
                                    }
                                }
                            }
                        }




    // go down left

   if(Ligne1+1==Ligne2 && Colonne1-1==Colonne2 && (Ligne1+Colonne1)%2==0 && (Ligne2+Colonne2)%2==0 ){

            int cTopRight=0;//compteur des pions possible à capturer en haut à droite
            int cButtoomLeft=0;//compteur des pions possible à capturer en bas à gauche
            int j=Colonne1-1,i=Ligne1-1;

            while(tableau[i-1][j+1]!=pBN && tableau[i-1][j+1]!=' ' && j<8 && i>0){
                    cTopRight++;
                    j++;
                    i--;
            }

            j=Colonne2-1;
            i=Ligne2-1;
            while(tableau[i+1][j-1]!=pBN && tableau[i+1][j-1]!=' ' && j>0 && i<4){
                    cButtoomLeft++;
                    j--;
                    i++;
            }

            if(cTopRight>=cButtoomLeft){
                for(i=Ligne1-1,j=Colonne1-1;j<8 && i>0;j++,i--){
                    if (tableau[i-1][j+1]!=pBN && tableau[i-1][j+1]!=' '){
                        tableau[i-1][j+1]=' ';
                        *pc=*pc+1;
                    }
                    else{
                        break;
                    }
                }
            }

                else{
                    for(i=Ligne2-1,j=Colonne2-1;j>0 && i<4;j--,i++){
                        if (tableau[i+1][j-1]!=pBN && tableau[i+1][j-1]!=' '){
                            tableau[i+1][j-1]=' ';
                            *pc=*pc+1;
                            }

                        else{
                            break;
                        }
                    }
                }
            }

}
