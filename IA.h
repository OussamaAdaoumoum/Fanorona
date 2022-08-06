#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

typedef enum Bool
{
    false,
    true
}Bool ;
typedef struct pion
    {
        int X;
        int Y;
    }pion;

int calcul_poids (int cOrdinateur, int cJoueur);
int pionPossible(char tableau[5][9], int i, int j, int *Ligne2 , int*Colonne2 , char pBN);
void pionsFils(char tableau[5][9] , char pBN , pion tab_fils[],int *L);
int minimax (char tableau[5][9],int prof_arbre,int alpha, int beta, Bool max_Joueur,int compteurOr, int compteurJ );
void pionChoisi(char tableau[5][9] , pion tab_fils[], int cOrdinateur, int cJoueur,int L, pion *meilleurPion, pion *meilleurEmp);






#endif

