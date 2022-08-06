#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "affichage.h"
#include "regles.h"
#include "Joueurs.h"
#include "CaptureMultiple.h"
#include "CaptureObligatoire.h"
#include "IA.h"

int main(){

    SetConsoleTitle("Fanorona");                   // changer le titre du console
    system("color 0b");                            // changer la couleur du console
    system("mode 180,100");                        // changer la hauteur et largeur du console

    char choix='0';
    char choix2='0';
    char choix3='0';
    char re;

    char tableau[5][9]={{'B','B','B','B','B','B','B','B','B'},
                        {'B','B','B','B','B','B','B','B','B'},
                        {'B','N','B','N',' ','B','N','B','N'},
                        {'N','N','N','N','N','N','N','N','N'},
                        {'N','N','N','N','N','N','N','N','N'}};

    // variables partie Joueur vs Joueur
    char joueur_1[20],joueur_2[20];
    int cjoueur1=0;
    int cjoueur2=0;

    // variables partie Joueur vs Ordinateur N1
    char joueur[10];
    int cjoueur=0;
    int cOrdinateur=0;

    // variables partie Joueur vs Ordinateur N2
    char joueurN2 [10];
    int cjoueurN2 = 0;
    int cOrdinateurN2 = 0;

    int c=0; //compteurPionsCapturé

    srand(time(NULL));
    int x = 1 + rand() % (2);// x est un entier qui nous permet de choisir le joueur qui va commencer à jouer d'une manière aléatoire




do{
    acceuil :
    system("cls");
    afficher("fanorona.txt");
    scanf("%c",&choix);
    switch(choix){

        case '1':{         // option de jouer
            do{
                    rejouer:
                    system("cls");
                    afficher("jouerFonction.txt");
                    scanf("%c",&choix2);

                    switch(choix2){
                        case '1':{
                            //joueurVSjoueur
                            system("cls");
                            afficher("fanoronatxt.txt");
                            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    Joueur1 (pions noirs)   :");
                            scanf("%s",&joueur_1);
                            printf("\n\t\t\t\t\t\t\t\t    Joueur2 (pions blancs)  :");
                            scanf("%s",&joueur_2);


                            //commencer aléatoirement

                            if(x==1)
                                printf("\n\n\t\t\t\t\t\t\t\tle joueur qui va commencer est: %s",joueur_1);
                            else if(x==2)
                                printf("\n\n\t\t\t\t\t\t\t\tle joueur qui va commencer est: %s",joueur_2);

                            char tableau[5][9]={{'B','B','B','B','B','B','B','B','B'},
                                                {'B','B','B','B','B','B','B','B','B'},
                                                {'B','N','B','N',' ','B','N','B','N'},
                                                {'N','N','N','N','N','N','N','N','N'},
                                                {'N','N','N','N','N','N','N','N','N'}};
                            getch();
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n");
                            AfficherTableau(tableau);

                            int jeux=x+1;
                            do{
                                char joueur[20];
                                char pBN='N';


                                if(jeux%2==0){
                                    strcpy( joueur, joueur_1);
                                    pBN='N';
                                    }
                                else if(jeux%2==1){
                                    strcpy( joueur, joueur_2);
                                    pBN='B';
                                    }

                                    printf("\n");
                                    joueur_humain(joueur,pBN,&c,tableau,&cjoueur1,&cjoueur2);//cette fonction a pour but d'afficher le tableau et donner la main au joueur de choisir un pion et son emplacement

                                    if(jeux%2==0){
                                        cjoueur1=cjoueur1+c;
                                   }
                                    else{
                                            cjoueur2=cjoueur2+c;
                                    }

                                    c=0;
                                    jeux++;

                            }while(cjoueur1!=22 && cjoueur2!=22 );

                                system("cls");
                                printf("\n\n");
                                afficher("congratulation.txt");
                                if(cjoueur1==22){ printf("\n\t\t\t\t\t\t\t\t\t%s , you won !",joueurN2);}
                                else if(cjoueur2==22) { printf("\n Computer, you won !");}


                                printf("\n\n\t\t\t\t\t\t\t\t  voulez-vous rejouer? ");

                                scanf("%s",&re);
                                if(re=='o'){
                                    goto rejouer;
                                }
                                else { exit(EXIT_SUCCESS); }
                                }

                                break;




                    case '2':{
                            do{
                            system("cls");
                            afficher("joueurVSordinateur.txt");
                            scanf("%c",&choix3);


                            switch(choix3){
                                case '1':{

                                system("cls");
                                afficher("fanoronatxt.txt");
                                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    entrer le nom du joueur : ");
                                    scanf("%s",&joueur);printf("\n");
                                    srand(time(NULL));
                                    if(x==1)
                                    {printf("\n\t\t\t\t\t\t\t\tle joueur qui va commencer est: %s\n",joueur);}
                                    else if(x==2)
                                    {printf("\n\t\t\t\t\t\t\t\tl'ordinateur qui va commencer a jouer \n");}

                                    printf("\n\n\t\t\t\t\t\t\t\t --cliquer sur entrer pour commencer--");
                                    getch();
                                    char tableau2[5][9]={{'B','B','B','B','B','B','B','B','B'},
                                                        {'B','B','B','B','B','B','B','B','B'},
                                                        {'B','N','B','N',' ','B','N','B','N'},
                                                        {'N','N','N','N','N','N','N','N','N'},
                                                        {'N','N','N','N','N','N','N','N','N'}};

                                    system("cls");
                                    AfficherTableau(tableau2);
                                    if(x==2){goto ordinateur;}

                                    do{

                                     printf("\n");

                                    joueur_humain(joueur,'N',&c,tableau2,&cjoueur,&cOrdinateur);//fonction dédiée au joueur
                                    cjoueur=cjoueur+c;
                                    c=0;
                                    printf("cliquer sur entrer... ");
                                    getch();
                                    system("cls");
                                    ordinateur:
                                    joueur_ordinateur(tableau2,&c);//fonction dédiée à l'ordinateur
                                    cOrdinateur=cOrdinateur+c;
                                    c=0;

        // verifier ca
                                  //  printf("\n%s : %d        ordinateur : %d",joueur, cjoueur,cOrdinateur);
                                   }while(cjoueur!=22 && cOrdinateur!=22 );
                                    system("cls");
                                    printf("\n\n");
                                    afficher("congratulation.txt");
                                    if(cjoueur==22){ printf("\n\t\t\t\t\t\t\t\t\t%s , you won !",joueur);}
                                    else if(cOrdinateur==22) { printf("\n\t\t\t\t\t\t\t\t\t Computer, you won !");}
          //                      break;

                                    printf("\n\n\t\t\t\t\t\t\t\t   voulez-vous rejouer? ");
                                    scanf("%s",&re);

                                    if(re=='o'){
                                        goto rejouer;
                                    }
                                    else { exit(EXIT_SUCCESS); }
                                    }

                                    break;

                                case '2':{

                                system("cls");
                                afficher("fanoronatxt.txt");
                               printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    entrer le nom du joueur : ");
                                scanf("%s",&joueurN2);printf("\n");
                                srand(time(NULL));
                                if(x==1)
                                {printf("\n\t\t\t\t\t\t\t\t   le joueur %s qui va commencer\n",joueurN2);}
                                else if(x==2)
                                {printf("\n\t\t\t\t\t\t\t\tl'ordinateur qui va commencer a jouer \n");}

                                printf("\n\n\t\t\t\t\t\t\t\t --cliquer sur entrer pour commencer-- ");
                                getch();
                                char tableau3[5][9]={{'B','B','B','B','B','B','B','B','B'},{'B','B','B','B','B','B','B','B','B'},{'B','N','B','N',' ','B','N','B','N'},{'N','N','N','N','N','N','N','N','N'},{'N','N','N','N','N','N','N','N','N'}};

                                system("cls");
                                AfficherTableau(tableau3);
                                if(x==2){goto ordinateur2;}

                               do{

                                 printf("\n");

                                joueur_humain(joueurN2,'N',&c,tableau3,&cjoueurN2,&cOrdinateurN2);//fonction dédiée au joueur
                                cjoueurN2=cjoueurN2+c;
                                c=0;
                                printf("cliquer sur entrer... ");
                                getch();
                                system("cls");
                                ordinateur2:
                                Joueur_ordinateur_Niveau2(tableau3, &c , cOrdinateurN2,cjoueurN2);//fonction dédiée à l'ordinateur
                                cOrdinateurN2=cOrdinateurN2+c;
                                c=0;

                               }while(cjoueurN2!=22 && cOrdinateurN2!=22 );
                                system("cls");
                                printf("\n\n");
                                afficher("congratulation.txt");
                                if(cjoueurN2==22){ printf("\n\t\t\t\t\t\t\t\t\t%s , you won !",joueurN2);}
                                else if(cOrdinateurN2==22) { printf("\n Computer, you won !");}


                                printf("\n\n\t\t\t\t\t\t\t\t   est-ce que vous voulez rejouer? ");

                                scanf("%s",&re);
                                if(re=='o'){
                                    goto rejouer;
                                }
                                else { exit(EXIT_SUCCESS); }
                                }

                                break;
                                case '3':{
                                 goto acceuil;
                                } break;


                                }
                                }while(choix3!='1' && choix3!='2' && choix3!='3');


                                }
                                break;



                        case '3':{
                        goto acceuil;
                        } break;


                    }

        }while(choix2!='1' && choix2!='2' && choix2!='3' );
         printf("\n\n\n\n\n\n\n\n");
        }  break;

        case '2':{
            regles();
        char r;
        regle:
        scanf("%s", &r);
        if(r=='o'){goto acceuil;}
        else if(r=='n' || r=='non' || r =='Non' ){
                exit(EXIT_SUCCESS);
        }
        else{
            printf("\t\t\t\t\t\t\t\t\t\t  Erreur!");
            goto regle;
        }
    }  break;

    case '3':
        system("cls");
        break;
    }
}while(choix!='1' && choix!='2' && choix!='3' );







return 0;

}

