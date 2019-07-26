#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void displayBoard(char [][3]);
int RandomNumber();
int selectLocation(char [][3],int);
int selectLocationC(char [][3],int);
void setTurn(char [][3],int,int,int);
int checkForWin(char [][3] ,char s);
int checkForWinP(char [][3] );

int main() {
int pick;
	 char playAgain;
	 char symbol[2]={'X','O'};
	 char sym ;

	 printf("choose wone plese\n");
	 printf("1.) computer vs human\n");
	 printf("2.) player vs player\n");
	 scanf("\n%d",&pick);
	 do {
		  int turn, pos, winner,count;
		  char board [3][3] = {
								{'.','.','.'},
								{'.','.','.'},
								{'.','.','.'}
								};
								turn=0;

		  playAgain=0;
		  winner=0;
		  count = 0;


			if (pick==1)
			{
				printf("Now you playing with computer vs human\n\n");
				do
				{

					count++;
					playAgain=0;

					displayBoard(board); //function to show up the board

					printf("Player %d turn (%c)\n",turn+1,symbol[turn]);  //showing who player is going to play first
					turn=0;
					pos = selectLocation(board,turn); //function

					setTurn(board,turn,pos/3,pos%3);//function


					if (checkForWin(board,'X') == 1 )
						winner=1;

					turn=1;
					pos = selectLocationC(board,turn); //function

					setTurn(board,turn,pos/3,pos%3);//function

					if (checkForWin(board,'O')==1)
						winner=2;

				} while((winner==0) && (count<9));

				displayBoard(board);//function

			if (winner!=0)
			{

				printf("***********congratulation************\n");

				printf(" The winner is Player %d!!!\n", winner);

			} else
				printf("A draw!!!\n");

			 printf("Do you want to play again? (Y/N)");
			 scanf("%c\n",&playAgain);

			 printf("\n\nGAME OVER! Thank you for playing :-)\n\n");
		}

		else
		printf("Now you playing with human vs human\n\n");



        do {
		  int turn=0, pos, winner,count;
		  char board [3][3] = {
								{'.','.','.'},
								{'.','.','.'},
								{'.','.','.'}
								};
		  playAgain=0;
		  winner=-1;
		  count = 0;
		  do{
				count++;

				playAgain=0;

				displayBoard(board); //showing the board in fucntion

				printf("Player %d turn (%c)\n",turn+1,symbol[turn]);

				pos = selectLocation(board,turn);    //function

				setTurn(board,turn,pos/3,pos%3);//function

				if (checkForWinP(board)) winner=turn;

            turn = (turn+1)%2;
		  } while((winner==-1) && (count<9));

		  displayBoard(board);//function

		  if (winner!=-1){

				printf("Winner is Player %d!!!\n", winner+1);

        } else
				printf("A draw!!!\n");

		  printf("Do you want to play again? (Y/N)");

		  scanf("\n%c",&playAgain);

	 } while(playAgain=='Y' || playAgain=='y');

      } while(playAgain=='Y' || playAgain=='y');






	 return 0;
}

int RandomNumber()
{
 srand (time(0));
 return (rand() % (10));
}

void displayBoard(char board[3][3])
{

	 //system("cls");
	 printf("\t\t\twelcome to tic tac toe game!");
	 printf("\n\t\t\t____________________________\n\n\n");
	 printf("\n");
									printf("     0   1   2\n\n");
	 printf("0   ");        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
				printf("    ---+---+---\n");
	 printf("1   ");        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
				printf("    ---+---+---\n");
	 printf("2   ");        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
				printf("\n");
}

int selectLocation(char board[3][3],int turn)
{
	 char symbol[2]={'X','O'};
	 int x,y;
	 do{
		  printf("Please type 2 numbers as the location to put a %c (0 <= row, col <= 2): ",symbol[turn]);
		  scanf("%d %d",&x,&y);
		  if ((x>2) || (y>2) || (x<0) || (y<0) ||(board[x][y]!='.'))
				printf("Invalid position\n\n");
	 } while ((x>2) || (y>2) || (x<0) || (y<0) || (board[x][y]!='.'));
	 return x*3+y;
}

int selectLocationC(char board[3][3],int turn)
{
	 char symbol[2]={'X','O'};
	 int x,y;
	 do{

	 x = rand() % 3;
	 y    = rand() % 3;
		  if ((x>2) || (y>2) || (x<0) || (y<0) ||(board[x][y]!='.'))
				printf("Invalid position\n\n");
	 } while ((x>2) || (y>2) || (x<0) || (y<0) || (board[x][y]!='.'));
	 return x*3+y;
}
void setTurn(char board[3][3], int turn, int row,int col)
{
	 char symbol[2]={'X','O'};
	 board[row][col] = symbol[turn];

}

int checkForWin(char board[3][3], char s){


	 if ( board [0][0] == s &&    board [0][1]==s   &&    board [0][2]==s  )
			return 1  ;

	 if ( board [1][0] == s &&    board [1][1]==s   &&    board [1][2]==s  )
			return 1  ;

	 if ( board [2][0] == s &&    board [2][1]==s   &&    board [2][2]==s  )
			return 1  ;

	 if ( board [0][0] == s &&    board [1][0]==s   &&    board [0][2]==s  )
			return 1  ;

	 if ( board [1][0] == s &&    board [1][1]==s   &&    board [1][2]==s  )
			return 1  ;

	  if ( board [0][0] == s &&    board [1][1]==s   &&    board [2][2]==s  )
			return 1  ;

	  if ( board [0][2] == s &&    board [1][2]==s   &&    board [2][1]==s  )
			return 1  ;


	  if ( board [0][1] == s &&    board [1][1]==s   &&    board [2][1]==s  )
			return 1  ;

	  if ( board [2][2] == s &&    board [1][2]==s   &&    board [0][2]==s  )
			return 1  ;

	  if ( board [0][2] == s &&    board [1][2]==s   &&    board [2][2]==s  )
			return 1  ;

	  if ( board [0][0] == s &&    board [1][0]==s   &&    board [0][2]==s  )
			return 1  ;
	 return 0;
}

int checkForWinP(char board[3][3]){
    int i,j,count;
    for(i=0;i<3;i++){
        /////////////////////// check row/////////////////////////
        count=0;
        for(j=1;j<3;j++){
            if ((board[i][j]==board[i][0]) && (board[i][0]!='.')) count++;
        }
        if (count==2) return 1;

        /////////////////////// check column/////////////////////////
        count=0;
        for(j=1;j<3;j++){
            if ((board[j][i]==board[0][i]) && (board[0][i]!='.')) count++;
        }
        if (count==2) return 1;
    }
    count=0;
    for(i=1;i<3;i++){
        if ((board[i][i]==board[0][0]) && (board[0][0]!='.')) count++;
    }
    if (count==2) return 1;

    count=0;
    for(i=1;i<3;i++){
        if ((board[i][2-i]==board[0][2]) && (board[0][2]!='.'))  count++;
    }
    if (count==2) return 1;
    return 0;
}

