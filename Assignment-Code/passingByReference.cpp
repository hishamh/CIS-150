/*
main.cpp
Question 1_CIS 150 – Lab 07

Created by Hisham on 3/18/17.
Copyright © 2017 Hisham Hussein. All rights reserved.
Purpose: Ask the user to enter two numbers and send them to function by passing by value or reference and see what is the different
*/


#include <iostream>
using namespace std;

//function prototype
void doIt(int& , int );
void doIt2(int , int& );
void doIt3(int& , int& );

int main(int argc, const char * argv[]) {

    //declare two number to hold user's value
    int num1,num2;

    //ask the user for first number
    cout<<"Enter first number: ";
    cin>>num1;

    //ask the user for second number
    cout<<"Enter second number: ";
    cin>>num2;


        //send the value that entered by the user to the function
        doIt(num1 , num2 );

            //display the change for the first function
            cout<<"\nNew numbers: "<<num1<<"   "<<num2<<endl;

            //ask the user again for first number and second number
            cout<<"Enter first number: ";
            cin>>num1;

            cout<<"Enter second number: ";
            cin>>num2;

        //send the value that entered by the user to the function for the second time
        doIt2(num1 , num2 );

            //display the change for the second function
            cout<<"\nNew numbers: "<<num1<<"   "<<num2<<endl;

            //ask the user again for first number and second number
            cout<<"Enter first number: ";
            cin>>num1;

            cout<<"Enter second number: ";
            cin>>num2;

        doIt3(num1 , num2 );
            //display the change for the third function
            cout<<"\nNew numbers: "<<num1<<"   "<<num2<<endl;

    system("pause");
    return 0;
}


void doIt(int& a, int b)//when you pass by reference
{
    /*
        the variable (a) is pointed to the main function value, will change the original value because it passes by reference, but the value b will only have copy of the value and it will not be able to change the original value
     */
    a = a + 5;
    b = b + 5;
}

void doIt2(int a, int& b)
{
    /*
     the value is variable b is pointed to the main function value, will change the original value because it passes by reference, but the value a will only have copy of the value and it will not be able to change the original value
     */

    a = a + 5;
    b = b + 5;
}

void doIt3(int& a, int& b)
{
    /*
     the variable a and b is pointed to the main function value, will change the original value because it passes by reference
     */
    a = a + 5;
    b = b + 5;
}


/*
 when the data sent by value means it only take copy of the original value and put it in a new variable so, it wont effect the original value if the copied value change. In a simple way the the function does not have the access to the original variable. In other hand when the user pass by reference it mean the the variable the the full access to the original value and change it. In simply way it changes the original value of the variable.
 */
