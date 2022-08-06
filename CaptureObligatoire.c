#include "CaptureObligatoire.h"
#include <stdlib.h>
#include <stdio.h>


// retourne si il y a des prises ou non
int PossibilitePrisePions(char tableau[5][9],char pBN){
int i=0;
    int j=0;

    if(pBN=='N'){

for(i=0;i<5;i++){
    for(j=0;j<9;j++){

        if(tableau[i][j]=='N'){

              //down
                if((i+1<=4 && tableau[i+1][j]==' ')  && ((i+2<=4 && tableau[i+2][j]=='B') || ( i-1>=0 && tableau[i-1][j]=='B'))){return 1;break;}
            //up
               else if((i-1>=0 && tableau[i-1][j]==' ')  && ((i-2>=0 && tableau[i-2][j]=='B')  || (i+1<=4 && tableau[i+1][j]=='B') )){return 1;break;}
               //right
                else if(( j+1<=8 && tableau[i][j+1]==' ')  && (( j+2<=8 && tableau[i][j+2]=='B') || ( j-1>=0 && tableau[i][j-1]=='B' ) )){return 1;break;}
               //left
                else if(( j-1>=0 && tableau[i][j-1]==' ') &&  (( j-2>=0 && tableau[i][j-2]=='B')  || ( j+1<=8 && tableau[i][j+1]=='B') )){return 1;break;}


                   //down right
                    else if( (i+j)%2==0 && (i+1<=4 && j+1<=8 && tableau[i+1][j+1]==' ') && ((i+2<=4 && j+2<=8 && tableau[i+2][j+2]=='B')  || ( i-1>=0 && j-1>=0 && tableau[i-1][j-1]=='B')) ){return 1;break;}
                   //up left
                   else if( (i+j)%2==0 && (i-1>=0 && j-1>=0 && tableau[i-1][j-1]==' ') && (( i-2>=0 && j-2>=0 && tableau[i-2][j-2]=='B' )|| (i+1<=4 && j+1<=8 && tableau[i+1][j+1]=='B')) ){return 1;break;}
                   //down left
                    else if( (i+j)%2==0 && ( i+1<=4 && j-1>=0 && tableau[i+1][j-1]==' ') && (( i+2<=4 && j-2>=0 && tableau[i+2][j-2]=='B') || ( i-1>=0 && j+1<=8 && tableau[i-1][j+1]=='B') )){return 1;break;}
                   //up right
                    else if( (i+j)%2==0 && (i-1>=0 && j+1<=8 && tableau[i-1][j+1]==' ') && ((i-2>=0 && j+2<=8 && tableau[i-2][j+2]=='B') || (i+1<=4 && j-1>=0 && tableau[i+1][j-1]=='B'))){return 1;break;}
                  }

    }  }
}
i=0;
j=0;

if(pBN=='B'){

for(i=0;i<5;i++){
    for(j=0;j<9;j++){

        if(tableau[i][j]=='B'){
              //down
                if((i+1<=4 && tableau[i+1][j]==' ')  && ((i+2<=4 && tableau[i+2][j]=='N') || ( i-1>=0 && tableau[i-1][j]=='N'))){return 1;break;}
            //up
                else if((i-1>=0 && tableau[i-1][j]==' ')  && ((i-2>=0 && tableau[i-2][j]=='N')  || (i+1<=4 && tableau[i+1][j]=='N'))){return 1;break;}
               //right
                else if(( j+1<=8 && tableau[i][j+1]==' ')  && (( j+2<=8 && tableau[i][j+2]=='N') || ( j-1>=0 && tableau[i][j-1]=='N' ))){return 1;break;}
               //left
                else if(( j-1>=0 && tableau[i][j-1]==' ') &&  (( j-2>=0 && tableau[i][j-2]=='N')  || ( j+1<=8 && tableau[i][j+1]=='N') )){return 1;break;}

                   //down right
                    else if( (i+j)%2==0 && (i+1<=4 && j+1<=8 && tableau[i+1][j+1]==' ') && ((i+2<=4 && j+2<=8 && tableau[i+2][j+2]=='N')  || ( i-1>=0 && j-1>=0 && tableau[i-1][j-1]=='N')) ){return 1;break;}
                   //up left
                   else if( (i+j)%2==0 && (i-1>=0 && j-1>=0 && tableau[i-1][j-1]==' ') && (( i-2>=0 && j-2>=0 && tableau[i-2][j-2]=='N' )|| (i+1<=4 && j+1<=8 && tableau[i+1][j+1]=='N')) ){return 1;break;}
                   //down left
                    else if( (i+j)%2==0 && ( i+1<=4 && j-1>=0 && tableau[i+1][j-1]==' ') && (( i+2<=4 && j-2>=0 && tableau[i+2][j-2]=='N') || ( i-1>=0 && j+1<=8 && tableau[i-1][j+1]=='N') ) ){return 1;break;}
                   //up right
                    else if( (i+j)%2==0 && (i-1>=0 && j+1<=8 && tableau[i-1][j+1]==' ') && ((i-2>=0 && j+2<=8 && tableau[i-2][j+2]=='N') || (i+1<=4 && j-1>=0 && tableau[i+1][j-1]=='N')) ){return 1;break;}
                  }

    }  }






}
return 0;
}
