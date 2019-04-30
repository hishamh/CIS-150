/*
 main.cpp
 Question 3_CIS 150 – Lab 06

 Created by Hisham on 3/11/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: Ask the use for two numbers and determine the highest and lowest number by creating different function and return them to main
 */


//function prototype
int highest(int,int);
int lowest(int,int);

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {

    int num1,num2;

    //ask the use the enter two different numbers
    cout<<"Please provide the first number: ";
    cin>>num1;

    cout<<"Please provide the second number:  ";
    cin>>num2;

    //send the values to the function
    highest(num1, num2);//function call
    lowest(num1, num2);//function call


    //compare if they are equal to each other if not continues to else
    if(num1 == num2){

        //show the result
        cout <<"\nThe are equal"<<endl;

    }else{

        //show the result
        cout<<"The highest number is "<<highest(num1, num2)<<endl;
         cout<<"The lowest number is "<<lowest(num1, num2)<<endl;


    }

    system("pause");
    return 0;
}
int highest(int num1,int num2){

    //compare numbers that was send by the user. Passing by value
    if(num1>num2){

            return  num1;  //return the smallest number
    }
    else{

            return num2; //return the smallest number

    }

}

int lowest(int num1,int num2){

    //compare numbers that was send by the user. Passing by value
   if(num2>num1){

         return num1; //return the smallest number
   }else{

     return num2; //return the smallest number

   }

}


}
