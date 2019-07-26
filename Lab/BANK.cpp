#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
float withdraw(float);
float withdraw(float);
void balance(float);
float deposit(float);
void menu( );

int main()
{
float amt=0;
char ba;
        menu();
      do
     {

         printf("\n Enter any choice:");
          scanf("\n%c",&ba);
          switch(ba)
          {
             case 'D': case 'd' :
                          amt = deposit(amt);
                          menu();
                          break;
             case 'W': case 'w' :
                          amt =withdraw(amt);
                          menu();
                            break;
             case 'B': case 'b' :
                          balance(amt);
                          menu();
                          break;
             case 'Q': case 'q' :
                              printf("Thank You");
                                break;
         }
     }while(ba!='Q' && ba!='q' );



return 0;
}



float  deposit(float amt)
{
int d;
system("cls");
   do
   {



      printf("\nEnter amount of debosit :");
      scanf("%d",&d);

      if(d>amt)
      {
      amt=amt+d;
      printf("Your amount of debosit is:%f\n",amt);
      }
      else if (d=='-') {

            printf("you cant put depsoit of 0 value\nOR the number you enter is negative value\n\n please try again\n\n");
      }

   } while (d>amt);
return amt;
}
float withdraw(float amt)
{
int w;
 system("cls");
      do
      {
      printf("Enter amount of withdraw you want\n");
      scanf("%d",&w);
      if(amt>w)
      {
        amt=amt-w;
        printf("Your balance is:%f\n",amt);

      }
      else
      printf("You cant withdraw becase you have below 0 or your balance is %f\n", amt);
        }while (w>amt);
      return amt;
}

void balance(float amt)
{
 system("cls");
        printf("The balance amount is :%f\n",amt);
}

void menu()
{

     printf("                                           \n\n\n");
     printf("\t\t Welcome to HFCC Federal Credit Union! \n\n\n\n\n");
     printf("******************************************");
     printf( "\n Plese select from the following menu: \n");
     printf("******************************************");

     printf("\nD:        Make a deposit\n");
     printf("\nW:        Make a withdrawal\n");
     printf("\nB:        Make a check your account balance\n");
     printf("\nQ:        To quit\n");

}

