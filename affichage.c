#include "affichage.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void afficher(char *textBox){
    char c;
    FILE *f=NULL;
   f=fopen(textBox,"r");
   if(f!=NULL)
   {
       do
       {
           c=fgetc(f);
           printf("%c",c);
       }while(c!=EOF);
   }
   fclose(f);
}



void SetColor(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }



void AfficherTableau(char tableau[5][9]){
    system("cls");

    int i,j;
    printf("\n\n\n\n");
    printf("\t\t\t\t                                1    2    3    4    5    6    7    8    9    \n");
    printf("\t\t\t\t                    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);


    for(i=0;i<5;i++)
    {
        printf("\t\t\t\t");
        printf("\n\t\t\t\t              %d>    |     \t",i+1);

        if(tableau[i][0] == 'B')
        {
            SetColor(15);
            printf("%c",tableau[i][0]);
            SetColor(11);
        }
        else
        {
            SetColor(3);
            printf("%c",tableau[i][0]);
            SetColor(11);
        }
        for(j=1;j<9;j++)
        {
            printf(" -- ");
            if(tableau[i][j] == 'B')
            {
                SetColor(15);
                printf("%c",tableau[i][j]);
                SetColor(11);
            }
            else
            {
                SetColor(3);
                printf("%c",tableau[i][j]);
                SetColor(11);
            }
        }
        if(i%2==0 && i!=4)
        {
            printf("\t    |    <%d",i+1);
        printf("\n\t\t\t\t                    |     \t| \\  |  / | \\  |  / | \\  |  / | \\  |  / |\t    |");
        printf("\n\t\t\t\t                    |     \t|  \\ | /  |  \\ | /  |  \\ | /  |  \\ | /  |\t    |");
        printf("\n\t\t\t\t                    |     \t|   \\|/   |   \\|/   |   \\|/   |   \\|/   |\t    |");
        }
        if(i%2!=0)
        {
            printf("\t    |    <%d",i+1);
            printf("\n\t\t\t\t                    |     \t|   /|\\   |   /|\\   |   /|\\   |   /|\\   |\t    |");
            printf("\n\t\t\t\t                    |     \t|  / | \\  |  / | \\  |  / | \\  |  / | \\  |\t    |");
            printf("\n\t\t\t\t                    |     \t| /  |  \\ | /  |  \\ | /  |  \\ | /  |  \\ |\t    |");
            }
    }
            printf("           |    <5");

            printf("\n\t\t\t\t                    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
            printf("\n\t\t\t\t                                1    2    3    4    5    6    7    8    9    \n");


}





































