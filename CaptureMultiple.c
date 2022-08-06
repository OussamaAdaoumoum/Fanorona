#include "CaptureMultiple.h"
#include <stdlib.h>
#include <stdio.h>


int PriseMultiplePossible(int i,int j,int Ligne1,int Colonne1,char tableau[5][9],char pBN){

if(pBN=='N'){

        //down
        if(tableau[i+1][j]==' '  && (tableau[i+2][j]=='B' || tableau[i-1][j]=='B') && (abs(i-Ligne1)!=1 || j!=Colonne1) ){return 1;}

        //up
        else if(tableau[i-1][j]==' '  && (tableau[i-2][j]=='B'  || tableau[i+1][j]=='B' ) && (abs(i-Ligne1)!=1 || j!=Colonne1) ){return 1;}

        //right
        else if(tableau[i][j+1]==' '  && (tableau[i][j+2]=='B' || tableau[i][j-1]=='B'  ) && (abs(j-Colonne1)!=1 || i!=Ligne1)){return 1;}

        //left
        else if(tableau[i][j-1]==' ' &&  (tableau[i][j-2]=='B'  || tableau[i][j+1]=='B' ) && (abs(j-Colonne1)!=1 || i!=Ligne1)){return 1;}

        //down right
        else if( (i+j)%2==0 && tableau[i+1][j+1]==' ' && (tableau[i+2][j+2]=='B'  || tableau[i-1][j-1]=='B') && (i-Ligne1!=1 || j-Colonne1!=1) ){return 1;}

        //up left
        else if( (i+j)%2==0 && tableau[i-1][j-1]==' ' && (tableau[i-2][j-2]=='B' || tableau[i+1][j+1]=='B') && (i-Ligne1!=-1 || j-Colonne1!=-1) ){return 1;}

        //down left
        else if( (i+j)%2==0 && tableau[i+1][j-1]==' ' && (tableau[i+2][j-2]=='B' || tableau[i-1][j+1]=='B' ) && (i-Ligne1!=1 || j-Colonne1!=-1)){return 1;}

        //up right
        else if( (i+j)%2==0 && tableau[i-1][j+1]==' ' && (tableau[i-2][j+2]=='B' || tableau[i+1][j-1]=='B' ) && (i-Ligne1!=-1 || j-Colonne1!=1)){return 1;}
}



if (pBN=='B'){

        //down
        if(tableau[i+1][j]==' '  && (tableau[i+2][j]=='N' || tableau[i-1][j]=='N') && (abs(i-Ligne1)!=1 || j!=Colonne1) ){return 1;}

        //up
        else if(tableau[i-1][j]==' '  && (tableau[i-2][j]=='N'  || tableau[i+1][j]=='N' ) && (abs(i-Ligne1)!=1 || j!=Colonne1) ){return 1;}

        //right
        else if(tableau[i][j+1]==' '  && (tableau[i][j+2]=='N' || tableau[i][j-1]=='N'  ) && (abs(j-Colonne1)!=1 || i!=Ligne1)){return 1;}

        //left
        else if(tableau[i][j-1]==' ' &&  (tableau[i][j-2]=='N'  || tableau[i][j+1]=='N' ) && (abs(j-Colonne1)!=1 || i!=Ligne1)){return 1;}

        //down right
        else if( (i+j)%2==0 && tableau[i+1][j+1]==' ' && (tableau[i+2][j+2]=='N'  || tableau[i-1][j-1]=='N') && (i-Ligne1!=1 || j-Colonne1!=1) ){return 1;}

        //up left
        else if( (i+j)%2==0 && tableau[i-1][j-1]==' ' && (tableau[i-2][j-2]=='N' || tableau[i+1][j+1]=='N') && (i-Ligne1!=-1 || j-Colonne1!=-1) ){return 1;}

        //down left
        else if( (i+j)%2==0 && tableau[i+1][j-1]==' ' && (tableau[i+2][j-2]=='N' || tableau[i-1][j+1]=='N' ) && (i-Ligne1!=1 || j-Colonne1!=-1)){return 1;}

        //up right
        else if( (i+j)%2==0 && tableau[i-1][j+1]==' ' && (tableau[i-2][j+2]=='N' || tableau[i+1][j-1]=='N' ) && (i-Ligne1!=-1 || j-Colonne1!=1)){return 1;}
}

return 0;
}

