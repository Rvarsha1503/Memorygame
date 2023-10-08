#include <stdio.h>
#include <string.h>
#include <conio.h>

char cards[7][7];
char card[7][7];


void printboard();
char checkfreespaces(char card[7][7]);

int main()
{

    printf("\t\t\t\t\t_____________________________________\n\n");
    printf("\t\t\t\t\t*************************************\n");
    printf("\t\t\t\t\t         Let's start the game!\n          \t\t\t\t\t Enter any key\n");
    printf("\t\t\t\t\t*************************************\n");
    printf("\t\t\t\t\t_____________________________________\n\t\t\t\t\t"); 
    getch();
    printf("\n\n\n");

    printf("  ____________________________________________________________________________________________________________________________\n\n");
    printf("  ****************************************************************************************************************************\n");
    printf("\t  INTRO:\n  \t\tEach '~' has a hidden character under it.\n  \t\tYou can view and access them by entering the particular row and coloum number.\n");
    printf("\t\tThe character will be shown in it's particular box until you access the second card.\n\t\tIt will go back to being hidden, once pressed 'continue'.\n");
    printf("\t\tIf the second chosen character is identical (or) similar to the first chosen one, YOU GET 10 points!.\n");
    printf("\t\tEnter n/N to exit the game when the prompt appears.\n");
    printf("  ***************************************************************************************************************************\n");
    printf("  ____________________________________________________________________________________________________________________________\n\n"); 
    printf("              \t\t\t\t  Enter any key to start the game~~~\n\t\t\t\t\t");
    getch();
    printf("\n");

    int points=0; 
    int attempts=0;
    int correctattempts=0;
    int wrong=0;
    char a,b;
    char check;
    int r1;
    int c1;
    int r2;
    int c2;
    int wt;

    do
    {
        
        cards[1][1] = '?';            card[1][1] = '~'; 
        cards[1][2] = '%';            card[1][2] = '~';
        cards[1][3] = '$';            card[1][3] = '~';
        cards[1][4] = ')';            card[1][4] = '~';
        cards[1][5] = ')';            card[1][5] = '~';    
        cards[1][6] = '|';            card[1][6] = '~'; 
        cards[2][1] = '_';            card[2][1] = '~';
        cards[2][2] = '&';            card[2][2] = '~';    
        cards[2][3] = '^';            card[2][3] = '~';
        cards[2][4] = '%';            card[2][4] = '~';   
        cards[2][5] = '^';            card[2][5] = '~';
        cards[2][6] = '{';            card[2][6] = '~';  
        cards[3][1] = '#';            card[3][1] = '~';
        cards[3][2] = '-';            card[3][2] = '~';
        cards[3][3] = '(';            card[3][3] = '~';
        cards[3][4] = '+';            card[3][4] = '~';
        cards[3][5] = '&';            card[3][5] = '~';
        cards[3][6] = '}';            card[3][6] = '~'; 
        cards[4][1] = '+';            card[4][1] = '~';
        cards[4][2] = '_';            card[4][2] = '~';
        cards[4][3] = '$';            card[4][3] = '~'; 
        cards[4][4] = '!';            card[4][4] = '~';
        cards[4][5] = '?';            card[4][5] = '~';
        cards[4][6] = '{';            card[4][6] = '~'; 
        cards[5][1] = '#';            card[5][1] = '~'; 
        cards[5][2] = '-';            card[5][2] = '~';
        cards[5][3] = '=';            card[5][3] = '~';
        cards[5][4] = '=';            card[5][4] = '~';
        cards[5][5] = '!';            card[5][5] = '~';
        cards[5][6] = '|';            card[5][6] = '~'; 
        cards[6][1] = '(';            card[6][1] = '~'; 
        cards[6][2] = '@';            card[6][2] = '~';
        cards[6][3] = '/';            card[6][3] = '~';
        cards[6][4] = '/';            card[6][4] = '~';
        cards[6][5] = '@';            card[6][5] = '~';
        cards[6][6] = '}';            card[6][6] = '~'; 
         do      
            {
                jump1:  printboard();
                printf("\t\t\t\t\tEnter row for first card(1-6) :");
                scanf("%d", &r1);
                if (r1<1 || r1 >6)
                {
                    printf("\t\t\t\t\tEnter number only between 1-6!\n\t\t\t\t\tPlease try again.\n");
                    goto jump1;//1
                }  

                jump2 :printf("\t\t\t\t\tEnter coloum for first card (1-6) :");
                scanf("%d", &c1);
                if (c1<1 || c1>6)
                {
                    printf("\t\t\t\t\tEnter number only between 1-6!\n\t\t\t\t\tPlease try again.\n :");
                    goto jump2; //2
                }    
                if (cards[r1][c1] == ' ')
                {
                    printf("\n\t\t\t\t\tInvalid selection. Character is already selected / matched\n");
                    goto jump1;
                                            
                }
                else
                {
                    card[r1][c1] = cards[r1][c1];
                        
                    printf("\t\t\t\t\tThe hidden character in here is : '%c'\n\n", cards[r1][c1]);
                }
                
                
                jump3 : printboard();
                 
                printf("\t\t\t\t\tEnter row for second card (1-5) :");
                scanf("%d", &r2);

                if (r2<1 || r2>6)
                {
                    printf("\t\t\t\t\tEnter number only between 1-6!\n\t\t\t\t\tPlease try again.\n");
                    goto jump3;
                }

                jump4 :printf("\t\t\t\t\tEnter coloum for second card (1-5) :");
                scanf("%d", &c2);

                if (c2<1 || c2>6)
                {
                    printf("\t\t\t\t\tEnter number only between 1-6!\n\t\t\t\t\tPlease try again.\n");
                    printboard();
                    goto jump4;
                }

                if (cards[r2][c2] == ' ')
                {
                    printf("\t\t\t\t\tInvalid selection. Character is already selected / matched\n");
                    goto jump3;

                }
                else if (r1==r2 && c1==c2)
                {
                    printf("\n\t\t\t\t\tSelected same row and coloum as the first one.\n\t\t\t\t\tPlease enter a different row or coloum.\n");
                    goto jump3;
                }
               
                card[r2][c2] = cards[r2][c2];
                printboard();
                printf("\t\t\t\t\tThe hidden character in here is : '%c'\n", cards[r2][c2]); 

                if(cards[r1][c1] == cards[r2][c2])
                {
                    card[r1][c1] = ' ';
                    card[r2][c2] = ' ';
                    cards[r1][c1] = ' ';
                    cards[r2][c2] = ' ';
                        
                                

                    printf("\n\n\t\t\t\t\tIT'S A MATCH!\n \t\t\t\t\tGOOD WORK!\n\n");
                    points+=10;
                    correctattempts++;
                            
                            
                    attempts++;

                    printf("\t\t\t\t\tPress N/n to exit the game.\n \t\t\t\t\tEnter 'enter' to continue\n\t\t\t\t\t");
                    scanf("%c", &a);
                    scanf("%c", &b);

                    if (b == 'n' || b == 'N')
                    {
                        goto end;
                    }              
                }                                    
                else 
                {   
                    card[r1][c1] = '~';
                    card[r2][c2] = '~';

                    attempts++;

                    printf("\n\t\t\t\t\tNOT THE RIGHT MATCH!\n\n");
                    printf("\n\t\t\t\t\tPress N/n to exit the game.\n\t\t\t\t\tEnter 'enter' to continue\n");                                  
                    scanf("%c", &a);
                    scanf("%c", &b);
                    wrong++;
                    if (b == 'n' || b == 'N')
                    {
                        goto end;
                    }                     

                
            }                
                
            } while (checkfreespaces(card) != ' ');           

           
            printboard();
            
            
            printf("\t\t\t\t\t_____________________________________\n\n");
            printf("\t\t\t\t\t*************************************\n");
        

             
            printf("\t\t\t\t\tWOHOO!! YOU COMPLETED THE GAME!!! BRAVOO!!\n");
            


            end : printf("\t\t\t\t\t\t  Your score is : %d\n", points);
            printf("\t\t\t\t\t\t  Correct Attempts : %d\n", correctattempts);
            printf("\t\t\t\t\t\t  Failed Attempts : %d\n", wrong);
            printf("\t\t\t\t\t\t  Total attempts : %d\n", attempts);
            printf("\t\t\t\t\t*************************************\n");
            printf("\t\t\t\t\t_____________________________________\n"); 
            printf("\n\n");
            printf("\t\t\t\t\tWould you like to play again? (Y/N) :");
            scanf("%c", &a);
            scanf("%c", &check);
            

    } while (check == 'y' || check == 'Y');
    
    printf("\n\n\t\t\t\t\t_____________________________________\n\n");
    printf("\t\t\t\t\t*************************************\n");  
    printf("\t\t\t\t\t\t  Thank you!\n");
    printf("\t\t\t\t\t*************************************\n");
    printf("\t\t\t\t\t_____________________________________\n\n\n"); 
    
  return 0; 
}


void printboard()
{   
    printf("_________________________________________________________\n");

    printf("|       |       |       |       |       |       |       |\n");

    printf("|       |   1   |   2   |   3   |   4   |   5   |   6   |\n");

    printf("|_______|_______|_______|_______|_______|_______|_______|\n");

    printf("|       |       |       |       |       |       |       |\n");
   
    printf("|   1   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", card[1][1], card[1][2], card[1][3], card[1][4], card[1][5], card[1][6]);

    printf("|_______|_______|_______|_______|_______|_______|_______|\n");

    printf("|       |       |       |       |       |       |       |\n");

    printf("|   2   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", card[2][1], card[2][2], card[2][3], card[2][4], card[2][5], card[2][6]);

    printf("|_______|_______|_______|_______|_______|_______|_______|\n");

    printf("|       |       |       |       |       |       |       |\n");

    printf("|   3   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", card[3][1], card[3][2], card[3][3], card[3][4], card[3][5], card[3][6]);

    printf("|_______|_______|_______|_______|_______|_______|_______|\n");

    printf("|       |       |       |       |       |       |       |\n");

    printf("|   4   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", card[4][1], card[4][2],card[4][3], card[4][4], card[4][5], card[4][6]);

    printf("|_______|_______|_______|_______|_______|_______|_______|\n");

    printf("|       |       |       |       |       |       |       |\n");

    printf("|   5   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", card[5][1], card[5][2],card[5][3], card[5][4], card[5][5], card[5][6]);

    printf("|_______|_______|_______|_______|_______|_______|_______|\n");

    printf("|       |       |       |       |       |       |       |\n");

    printf("|   6   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", card[6][1], card[6][2],card[6][3], card[6][4], card[6][5], card[6][6]);

    printf("|_______|_______|_______|_______|_______|_______|_______|\n\n\n");

}

char checkfreespaces(char card[7][7])
{   
    int smtng=0;
    for (int i=1; i<=7; i++)
    {
        for (int j=1; j<=7; j++)
        {
            if(card[i][j] == ' ')
            {
               smtng++;
            }

        }
    }
    
    if (smtng == 34)
    {
        return ' ';
    }
        
}
