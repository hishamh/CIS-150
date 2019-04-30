/*
 main.cpp
 Question 1_CIS 150 – Lab 06

 Created by Hisham on 3/11/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: Ask the user to choose an operation to find max or min and then ask him for the numbers after that we send the numbers to the function which he use the operation with. After all the function return the answer
 */

#include <iostream>
using namespace std;


//function prototype
int maximum(int,int);
int minimum(int,int);
void welcome(void);
void displayMenu(void);
void bye(void);

int main(int argc, const char * argv[]) {

    //variables
    char pick;
    int num1,num2,maxHolder,minHolder;


    //display welcome message once only
    welcome();
    do {
         //function to display the Menu
        displayMenu();

        //ask the user to choose operation
        cout<<"Please select an operation: ";
        cin>>pick;


        //use switch statement to go to the correct operation
        switch (pick) {
            case 'A': case 'a':
                //ask the user for 1st and 2nd number
                cout<<"Please provide the first number: ";
                cin>>num1;

                cout<<"Please provide the second number:  ";
                cin>>num2;

                //holder the the returned number of function maximum
                maxHolder = maximum(num1, num2);

                 //show the result
                cout<<"The maximum of "<<num1<<" and "<<num2<<" is " <<maxHolder<<endl;


                break;
            case 'B': case 'b':
                //ask the user for 1st and 2nd number
                cout<<"Please provide the first number: ";
                cin>>num1;

                cout<<"Please provide the second number:  ";
                cin>>num2;

                //holder the the returned number of function minimum
                minHolder = minimum(num1, num2);

                //show the result
                cout<<"The minimum of "<<num1<<" and "<<num2<<" is " <<minHolder<<endl;
                break;
            case 'C': case 'c':

                bye();//function call to display message after the user exit
                exit(0);    //exit function
                break;
            default:
                cout<<"\nYou choose the wrong operation\n";
                break;
        }

    //keeps repated until the user click c or C
    }while(pick !='c' || pick !='C');

		system("pause")
    return 0;
}

int maximum(int num1,int num2){

//compare numbers that was send by the user..passing by value
    if(num1>num2){

        return num1;    //return the greater number
    }
    else

    return num2; //return the smallest number
}



int minimum(int num1,int num2){

    //compare numbers that was send by the user..passing by value

    if(num1<num2){


        return num1; //return the smallest number
    }
    else

    return num2; //return the greater number
}

void welcome(){

    //dsiplay welcome message to the user

    cout<<"--------------------------------------------------------"<<endl;
    cout<<"                        WELCOME                         "<<endl;
    cout<<"--------------------------------------------------------"<<endl;

}
void displayMenu(){  Menu
    //display the wecome message to the user

     cout<<"----------------------------------------"<<endl;
    cout<< "A.) Maximum of two integers"<<endl;
    cout<< "B.) Minimum of two integers"<<endl;
    cout<< "C.) Quit"<<endl;
    cout<<"----------------------------------------"<<endl;




}
void bye(){
    //display the exit message to the user
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"        Thank you for using our programing              "<<endl;
    cout<<"--------------------------------------------------------"<<endl;



}
