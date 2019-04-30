//
//  main.cpp
//  Question 1_CIS 150 – Lab 01
//  Purpose: Asking the user to enter two Integer numbers to add them and display the value
//  Created by Hisham on 1/24/17.
//  Copyright © 2017 Hisham Hussein. All rights reserved.
//


#include <iostream>

using namespace std;

int main()
{

    // declare three variables x, y, and z of type int
    int numOne,numTwo,sum=0;


    //display a message using cout asking the user to enter a first integer
    cout <<"Ente your first integer"<<endl;
    cin >>numOne;

    // display a message using cout asking the user to enter a second integer
    cout <<"Ente your second integer"<<endl;
    cin >>numTwo;

    //statement that calculate the two numbers entered by the user
    sum = numOne + numTwo;


    //display a message using cout displaying the message
    cout <<"The sum of the two integers is : "<< sum <<endl;


    system("pause");
    return 0;
}
