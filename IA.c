#include <stdio.h>
#include <stdlib.h>
#include "joueurs.h"
#include <limits.h>
#include "IA.h"
#include "affichage.h"
#include <string.h>
#include "CapturePions.h"
#include "CaptureObligatoire.h"




// fonction calcule le poids d'un etat de jeu en se basant sur les compteurs
int calcul_poids (int cOrdinateur, int cJoueur)
{
    if (cOrdinateur >= cJoueur){return 10;}
    else if (cOrdinateur <= cJoueur){return -10;}
    else {return 0;}

}

// fonction verifie si le pion peut etre jouable , et retourne l'emplacement

int pionPossible(char tableau[5][9], int i, int j, int *Ligne2 , int*Colonne2 , char pBN)
{
    int x=0;
    if (pBN=='B')
    {

    //chercher l'emplacement en respectant la regle de capture obligatoire
            //down

    if(tableau[i+1][j]==' '  && i+1<=4  )
       {if (PossibilitePrisePions(tableau,'B')!=0  && (( i+2<=4 && tableau[i+2][j]=='N' )||(i-1>=0 && tableau[i-1][j]=='N'))){*Ligne2=i+1;*Colonne2=j;x=1;}
        else if(PossibilitePrisePions(tableau,'B')== 0){*Ligne2=i+1;*Colonne2=j;x=1;}}


            //up

    if(tableau[i-1][j]==' '  && i-1>=0  )
   {if (PossibilitePrisePions(tableau,'B')!=0 && ((i-2>=0 && tableau[i-2][j]=='N') || (i+1<=4 && tableau[i+1][j]=='N'))){*Ligne2=i-1;*Colonne2=j;x=1;}
    else if(PossibilitePrisePions(tableau,'B')==0){*Ligne2=i-1;*Colonne2=j;x=1;}}


               //right
    if(tableau[i][j+1]==' '  && j+1<=8  )
   {if (PossibilitePrisePions(tableau,'B')!=0 && ((j+2<=8 && tableau[i][j+2]=='N') || (j-1>=0 && tableau[i][j-1]=='N'))){*Ligne2=i;*Colonne2=j+1;x=1;}
    else if(PossibilitePrisePions(tableau,'B')==0){*Ligne2=i;*Colonne2=j+1;x=1;} }



               //left
     if(tableau[i][j-1]==' '  && j-1>=0)
   {if (PossibilitePrisePions(tableau,'B')!=0 && ((j-2>=0 && tableau[i][j-2]=='N') || (j+1<=8 && tableau[i][j+1]=='N'))){*Ligne2=i;*Colonne2=j-1;x=1;}
    else if(PossibilitePrisePions(tableau,'B')==0){*Ligne2=i;*Colonne2=j-1;x=1;} }




                   //down right
    if((i+j)%2==0 && tableau[i+1][j+1]==' ' && i+1<=4 && j+1<=8 )
   {if (PossibilitePrisePions(tableau,'B')!=0 && ((i+2<=4 && j+2<=8 && tableau[i+2][j+2]=='N') || (i-1>=0 && j-1>=0 && tableau[i-1][j-1]=='N'))){*Ligne2=i+1;*Colonne2=j+1;x=1;}
    else if(PossibilitePrisePions(tableau,'B')==0){*Ligne2=i+1;*Colonne2=j+1;x=1;}}



                   //up left
    if((i+j)%2==0 && tableau[i-1][j-1]==' ' && i-1>=0 && j-1>=0 )
   {if (PossibilitePrisePions(tableau,'B')!=0 && ((i-2>=0 && j-2>=0 && tableau[i-2][j-2]=='N') ||(i+1<=4 && j+1<=8 && tableau[i+1][j+1]=='N'))){*Ligne2=i-1;*Colonne2=j-1;x=1;}
    else if(PossibilitePrisePions(tableau,'B')==0){*Ligne2=i-1;*Colonne2=j-1;x=1;}}



                   //down left

    if((i+j)%2==0 && tableau[i+1][j-1]==' ' && i+1<=4 && j-1>=0 )
   {if (PossibilitePrisePions(tableau,'B')!=0 && ((i+2<=4 && j-2>=0 && tableau[i+2][j-2]=='N') || (i-1>=0 && j+1<=8 && tableau[i-1][j+1]=='N'))){*Ligne2=i+1;*Colonne2=j-1;x=1;}
    else if(PossibilitePrisePions(tableau,'B')==0){*Ligne2=i+1;*Colonne2=j-1;x=1;}}



                   //up right

    if((i+j)%2==0 && tableau[i-1][j+1]==' ' && i-1>=0 && j+1<=8 )
   {if (PossibilitePrisePions(tableau,'B')!=0 && ((i-2>=0 && j+2<=8 && tableau[i-2][j+2]=='N') ||(i+1<=4 && j-1>=0 && tableau[i+1][j-1]=='N'))){*Ligne2=i-1;*Colonne2=j+1;x=1;}
    else if(PossibilitePrisePions(tableau,'B')==0){*Ligne2=i-1;*Colonne2=j+1;x=1;}}




    }

    else if (pBN=='N')
    {
        // down
    if(tableau[i+1][j]==' '  && i+1<=4 )
    {if (PossibilitePrisePions(tableau,'N')!=0 && (( i+2<=4 && tableau[i+2][j]=='B' )||(i-1>=0 && tableau[i-1][j]=='B'))){*Ligne2=i+1;*Colonne2=j;x=1;}
    else if(PossibilitePrisePions(tableau,'N')==0){*Ligne2=i+1;*Colonne2=j;x=1;}}


            //up
     if(tableau[i-1][j]==' '  && i-1>=0 )
    {if (PossibilitePrisePions(tableau,'N')!=0 && ((i-2>=0 && tableau[i-2][j]=='B') || (i+1<=4 && tableau[i+1][j]=='B'))){*Ligne2=i-1;*Colonne2=j;x=1;}
    else if(PossibilitePrisePions(tableau,'N')==0){*Ligne2=i-1;*Colonne2=j;x=1;}}

               //right
      if(tableau[i][j+1]==' '  && j+1<=8 )
    {if (PossibilitePrisePions(tableau,'N')!=0 && ((j+2<=8 && tableau[i][j+2]=='B') || (j-1>=0 && tableau[i][j-1]=='B'))){*Ligne2=i;*Colonne2=j+1;x=1;}
    else if(PossibilitePrisePions(tableau,'N')==0){*Ligne2=i;*Colonne2=j+1;x=1;}}



               //left
      if(tableau[i][j-1]==' '  && j-1>=0  )
   {if (PossibilitePrisePions(tableau,'N')!=0 && ((j-2>=0 && tableau[i][j-2]=='B') || (j+1<=8 && tableau[i][j+1]=='B'))){*Ligne2=i;*Colonne2=j-1;x=1;}
    else if(PossibilitePrisePions(tableau,'N')==0){*Ligne2=i;*Colonne2=j-1;x=1;}}


                   //down right

      if((i+j)%2==0 && tableau[i+1][j+1]==' ' && i+1<=4 && j+1<=8  )
   {if (PossibilitePrisePions(tableau,'N')!=0 && ((i+2<=4 && j+2<=8 && tableau[i+2][j+2]=='B') || (i-1>=0 && j-1>=0 && tableau[i-1][j-1]=='B'))){*Ligne2=i+1;*Colonne2=j+1;x=1;}
    else if(PossibilitePrisePions(tableau,'N')==0){*Ligne2=i+1;*Colonne2=j+1;x=1;}}


                   //up left
    if((i+j)%2==0 && tableau[i-1][j-1]==' '&& i-1>=0 && j-1>=0 )
   {if (PossibilitePrisePions(tableau,'N')!=0 && ((i-2>=0 && j-2>=0 && tableau[i-2][j-2]=='B') ||(i+1<=4 && j+1<=8 && tableau[i+1][j+1]=='B'))){*Ligne2=i-1;*Colonne2=j-1;x=1;}
    else if(PossibilitePrisePions(tableau,'N')==0){*Ligne2=i-1;*Colonne2=j-1;x=1;}}



                   //down left
     if((i+j)%2==0 && tableau[i+1][j-1]==' ' && i+1<=4 && j-1>=0 )
   {if (PossibilitePrisePions(tableau,'N')!=0 && ((i+2<=4 && j-2>=0 && tableau[i+2][j-2]=='B') || (i-1>=0 && j+1<=8 && tableau[i-1][j+1]=='B'))){*Ligne2=i+1;*Colonne2=j-1;x=1;}
    else if(PossibilitePrisePions(tableau,'N')==0){*Ligne2=i+1;*Colonne2=j-1;x=1;}}



                   //up right
      if((i+j)%2==0 && tableau[i-1][j+1]==' ' && i-1>=0 && j+1<=8 )
   {if (PossibilitePrisePions(tableau,'N')!=0 && ((i-2>=0 && j+2<=8 && tableau[i-2][j+2]=='B') ||(i+1<=4 && j-1>=0 && tableau[i+1][j-1]=='B'))){*Ligne2=i-1;*Colonne2=j+1;x=1;}
    else if(PossibilitePrisePions(tableau,'N')==0){*Ligne2=i-1;*Colonne2=j+1;x=1;}}



    }
    return x;
}

// pionsFils : fonction cherche les pions possibles de jouer avec

void pionsFils(char tableau[5][9] , char pBN , pion tab_fils[] ,int *L)
{

    int i,j,n=0;
    int Ligne2=0, Colonne2=0;

    for(i=0;i<5;i++){
    for(j=0;j<9;j++){
    if (tableau[i][j]==pBN && pionPossible(tableau,i,j , &Ligne2, &Colonne2,pBN) == 1)
        {
            (tab_fils[n]).X=i;
            (tab_fils[n]).Y=j;
            (tab_fils[n+1]).X= Ligne2;
            (tab_fils[n+1]).Y= Colonne2;
            n=n+2;
        }
    }}

    *L=n;
}


int minimax (char tableau[5][9],int prof_arbre,int alpha, int beta, Bool max_Joueur,int compteurOr, int compteurJ )
{
    // variables de travail
    int C_Ordi=compteurOr, C_Joueur = compteurJ;
    int n;
    pion tab_fils[20];
    int longueur=0;
    int Poids=0;

    char copieTableau[5][9];

    // condition d'arret
    if (prof_arbre == 0 || compteurOr==22 || compteurJ==22)
        {return calcul_poids(C_Ordi,C_Joueur);}


    if (max_Joueur == true)
    {
        int max_poids= -INT_MAX;
        longueur=0;
        Poids= 0;
        // trouver les etats fils
        pionsFils(tableau, 'B', tab_fils ,&longueur);

            for(n=0;n<longueur;n=n+2)
        {

            memcpy(copieTableau,tableau,5*9*sizeof(char));

            // jouer le mouvement

            copieTableau[(tab_fils[n]).X][(tab_fils[n]).Y]=' ';
            copieTableau[(tab_fils[n+1]).X][(tab_fils[n+1]).Y]='B';
            Capture_Pions((tab_fils[n]).Y+1,(tab_fils[n+1]).Y+1,(tab_fils[n]).X+1,(tab_fils[n+1]).X+1,&C_Ordi,copieTableau,'B');

            // evaluer l'etat
            Poids = minimax(copieTableau,prof_arbre -1 ,alpha, beta, false, C_Ordi, C_Joueur);
            // annuler le mouvement
            memcpy(copieTableau,tableau,5*9*sizeof(char));
            C_Ordi=compteurOr;
            C_Joueur = compteurJ;
            if (Poids >= max_poids)
            {
                max_poids = Poids;
            }
            if (Poids >= alpha)
            {
                alpha=Poids;
            }
            if (beta <=alpha)
                break;

        }
        return max_poids;
    }
     else
     {
        Poids= 0;
        int min_poids= INT_MAX;
        longueur=0;
         pionsFils(tableau, 'N', tab_fils, &longueur);

         for(n=0;n<longueur;n=n+2)
        {
             memcpy(copieTableau,tableau,5*9*sizeof(char));


            // jouer le mouvement

            copieTableau[(tab_fils[n]).X][(tab_fils[n]).Y]=' ';
            copieTableau[(tab_fils[n+1]).X][(tab_fils[n+1]).Y]='N';
            Capture_Pions((tab_fils[n]).Y+1,(tab_fils[n+1]).Y+1,(tab_fils[n]).X+1,(tab_fils[n+1]).X+1,&C_Joueur,copieTableau,'N');

            // evaluer l'etat
            Poids = minimax(copieTableau,prof_arbre -1,alpha, beta, true, C_Ordi,C_Joueur );

            // annuler le mouvement
            memcpy(copieTableau,tableau,5*9*sizeof(char));
            C_Ordi=compteurOr;
            C_Joueur = compteurJ;

            if (Poids <= min_poids)
            {
                min_poids = Poids;
            }
            if (min_poids <= beta)
            {
                beta = min_poids;
            }
            if (beta <=alpha)
                break;

        }
    return min_poids;

}

}


// trouver le meilleur pion parmi les pions de tab_fils
void pionChoisi(char tableau[5][9] , pion tab_fils[], int cOrdinateur, int cJoueur,int L, pion *meilleurPion, pion *meilleurEmp)
{
    // variables de travail

    int n,poids=0;
    int compteurOr = cOrdinateur , compteurJ = cJoueur;
    char copieTableau[5][9];


    int meilleurPoids = -INT_MAX;


    for (n=0 ;n<L ; n=n+2) // pour chaque etat
    {

        memcpy(copieTableau,tableau,5*9*sizeof(char));

        // jouer le mouvement

        copieTableau[(tab_fils[n]).X][(tab_fils[n]).Y]=' ';
        copieTableau[(tab_fils[n+1]).X][(tab_fils[n+1]).Y]='B';
        Capture_Pions((tab_fils[n]).Y+1,(tab_fils[n+1]).Y+1,(tab_fils[n]).X+1,(tab_fils[n+1]).X+1,&compteurOr,copieTableau,'B');

        // evaluer le mouvement
        poids= minimax(copieTableau,4,-INT_MAX, INT_MAX, false,compteurOr,compteurJ);
        // annuler le mouvement
        memcpy(copieTableau,tableau,5*9*sizeof(char));
        compteurJ=cJoueur;
        compteurOr=cOrdinateur;
        if (poids>=meilleurPoids)
        {
            meilleurPoids=poids;
            meilleurPion->X=tab_fils[n].X;
            meilleurPion->Y=tab_fils[n].Y;
            meilleurEmp->X=tab_fils[n+1].X;
            meilleurEmp->Y=tab_fils[n+1].Y;
        }

    }

}

