#include "Joueurs.h"
#include <stdlib.h>
#include <stdio.h>
#include "CapturePions.h"
#include "affichage.h"
#include "IA.h"
#include "CaptureObligatoire.h"
#include "CaptureMultiple.h"


// fonction dediee au joueur
void joueur_humain(char joueur[20], char pBN,int* pc,char tableau[5][9],int *pc1, int *pc2){
    int Ligne1=0,Colonne1=0,Ligne2=0,Colonne2=0;

Aff:
    SetColor(12);
    printf("\n\t\t\t\t\t\t\t                          Fanorona                            ");
    printf("\n\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf("\n\t\t\t\t\t\t\t                           Score:                      ");
    printf("\n\t\t\t\t\t\t\t      Joueur 1                           Joueur 2      ");
    printf("\n\t\t\t\t\t\t\t         %d                                  %d          ",*pc1,*pc2);
    printf("\n\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    SetColor(11);
pion:
    printf("%s : jouer ! \n",joueur);

    if (pBN =='N'){printf("pions Noirs N \n");}
    else{printf("pions Blancs B \n");}

    printf("les coordonnees de pion  \n");
    printf("l'abscisse Y  :");
    scanf("%d",&Ligne1);
    printf("l'abscisse X  :");
    scanf("%d",&Colonne1);

    if(tableau[Ligne1-1][Colonne1-1]!=pBN  ){printf("erreur ! :\n"); goto pion;}
    if (Ligne1>5  || Ligne1<=0 || Colonne1>9 || Colonne1<=0 ){printf("erreur ! :\n"); goto pion;}
    if (tableau[Ligne1-2][Colonne1-1]!=' ' && tableau[Ligne1][Colonne1-1]!=' '&& tableau[Ligne1-1][Colonne1-2]!=' ' && tableau[Ligne1-1][Colonne1]!=' '){
    if ((Ligne1+Colonne1)%2==0 && tableau[Ligne1-2][Colonne1-2]!=' ' && tableau[Ligne1-2][Colonne1]!=' ' && tableau[Ligne1][Colonne1-2]!=' ' && tableau[Ligne1][Colonne1]!=' ' ){
                printf("erreur ! : \n"); goto pion;}}


emp:
    printf("les coordonnees d'emplacement :  \n");
    printf("l'abscisse Y  :");scanf("%d",&Ligne2);
    printf("l'abscisse X  :");scanf("%d",&Colonne2);

    if(tableau[Ligne2-1][Colonne2-1]!=' ' ){ printf("erreur ! :\n");goto emp;}
    if( (abs(Colonne2-Colonne1)!=1 || abs(Ligne2-Ligne1)!=0) && (abs(Colonne2-Colonne1)!=0 || abs(Ligne2-Ligne1)!=1)&& (abs(Colonne2-Colonne1)!=1 || abs(Ligne2-Ligne1)!=1)){ printf("erreur ! :\n");goto emp;}
    if(tableau[Ligne2-1][Colonne2-1]!=' ' ){ printf("erreur ! :\n");goto emp;}
    if((Ligne1+Colonne1)%2==1 && abs(Colonne2-Colonne1)==1 && abs(Ligne2-Ligne1)==1){printf("erreur ! :\n");goto emp;}
    if (Ligne2>5  || Ligne2<=0 || Colonne2>9 || Colonne2<=0 ){printf("erreur ! :\n"); goto emp;}


    tableau[Ligne1-1][Colonne1-1]=' ';
    tableau[Ligne2-1][Colonne2-1]=pBN;


    Capture_Pions(Colonne1,Colonne2,Ligne1,Ligne2,pc,tableau,pBN);
    AfficherTableau(tableau);
    if(*pc==0){
        tableau[Ligne1-1][Colonne1-1]=pBN;
        tableau[Ligne2-1][Colonne2-1]=' ';
        if(PossibilitePrisePions(tableau,pBN)!=0){
                AfficherTableau(tableau);
                printf("Vous avez la possbilite d'une capture , vous devez choisir le bon pion\n");
                goto Aff;}
         else{
                tableau[Ligne1-1][Colonne1-1]=' ';
                tableau[Ligne2-1][Colonne2-1]=pBN;}




                }

        AfficherTableau(tableau);

}




// fonction dediee a l'ordinateur avec intelligence simple
void joueur_ordinateur(char tableau[5][9],int *pc){
    srand(time(NULL));
    int i=0,j=0,Ligne2=0,Colonne2=0;
    int x=0;
    debut:

    i=rand()%5;
    j=rand()%9;

    if(tableau[i][j]!='B'){
            goto debut;
            x=0;

                           }
        //down
    if(tableau[i+1][j]==' '  && i+1<=4 && (tableau[i+2][j]=='N' || tableau[i-1][j]=='N')){Ligne2=i+1;Colonne2=j;x=1;}
            //up
    else if(tableau[i-1][j]==' '  && i-1>=0 && (tableau[i-2][j]=='N'  || tableau[i+1][j]=='N' )){Ligne2=i-1;Colonne2=j;x=1;}
               //right
    else if(tableau[i][j+1]==' '  && j+1<=8 && (tableau[i][j+2]=='N' || tableau[i][j-1]=='N'  )){Ligne2=i;Colonne2=j+1;x=1;}
               //left
    else if(tableau[i][j-1]==' ' && j-1>=0 && (tableau[i][j-2]=='N'  || tableau[i][j+1]=='N' )){Ligne2=i;Colonne2=j-1;x=1;}

                   //down right
    else if( (i+j)%2==0 && tableau[i+1][j+1]==' ' && i+1<=4 && j+1<=8 && (tableau[i+2][j+2]=='N'  || tableau[i-1][j-1]=='N') ){Ligne2=i+1;Colonne2=j+1;x=1;}
                   //up left
    else if( (i+j)%2==0 && tableau[i-1][j-1]==' ' && i-1>=0 && j-1>=0 && (tableau[i-2][j-2]=='N' || tableau[i+1][j+1]=='N') ){Ligne2=i-1;Colonne2=j-1;x=1;}
                   //down left
    else if( (i+j)%2==0 && tableau[i+1][j-1]==' ' && i+1<=4 && j-1>=0 && (tableau[i+2][j-2]=='N' || tableau[i-1][j+1]=='N' ) ){Ligne2=i+1;Colonne2=j-1;x=1;}
                   //up right
    else if( (i+j)%2==0 && tableau[i-1][j+1]==' ' && i-1>=0 && j+1<=8 && (tableau[i-2][j+2]=='N' || tableau[i+1][j-1]=='N' ) ){Ligne2=i-1;Colonne2=j+1;x=1;}


                if(x==0 && PossibilitePrisePions(tableau,'B')!=0){goto debut;}
                if (PossibilitePrisePions(tableau,'B')==0){


                        end:
                        Ligne2=i+1-rand()%3;
                        Colonne2=j+1-rand()%3;


                        if(tableau[Ligne2][Colonne2]!=' ' ){ goto end;}
                        if(Ligne2<0 || Ligne2>4 || Colonne2<0 || Colonne2>8 ){goto end;}

                        if((i+j)%2==1 && abs(Colonne2-j)==1 && abs(Ligne2-i)==1){goto end;}


                            }



        tableau[i][j]=' ';
        tableau[Ligne2][Colonne2]='B';

        Capture_Pions(j+1,Colonne2+1,i+1,Ligne2+1,pc,tableau,'B');
        AfficherTableau(tableau);
     printf("l'ordinateur a fait le deplacement suivant : (Y=%d,X=%d) ---> (Y=%d,X=%d)   nombre de pions captures : %d\n", i+1,j+1,Ligne2+1,Colonne2+1,*pc);

}


// fonction dediee a l'ordinateur avec intelligence evoluee
void Joueur_ordinateur_Niveau2(char tableau[5][9], int *pc , int cOrdinateur,int cJoueur)
{

    // trouver les pions possibles : etats fils
    pion pionsPossibles[20];
    pion meilleurPion={-1,-1};
    pion meilleurEmp={-1,-1};

    int L=0;




    pionsFils(tableau,'B',pionsPossibles, &L);

    // trouver le meilleur pion : meilleur etat parmi les etats fils
    pionChoisi(tableau,pionsPossibles,cOrdinateur,cJoueur,L,&meilleurPion, &meilleurEmp);
    // jouer le mouvement

    tableau[meilleurPion.X][meilleurPion.Y]=' ';
    tableau[meilleurEmp.X][meilleurEmp.Y]='B';

    Capture_Pions(meilleurPion.Y+1,meilleurEmp.Y+1,meilleurPion.X+1,meilleurEmp.X+1,pc,tableau,'B');
    AfficherTableau(tableau);
    printf("l'ordinateur a fait le deplacement suivant : (Y=%d,X=%d) ---> (Y=%d,X=%d)   nombre de pions captures : %d\n", meilleurPion.X+1,meilleurPion.Y+1,meilleurEmp.X+1,meilleurEmp.Y+1,*pc);

}



