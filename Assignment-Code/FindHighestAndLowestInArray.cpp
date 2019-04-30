/*
 main.cpp
 Question 1_CIS 150 – Lab 09

 Created by Hisham on 3/30/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: calculate the sum and finding the highest, lowest numbers in the array using a functions and using loops

 */



#include <iostream>
#include<iomanip>
#include<fstream>

using namespace std;

//functions prototype
int arraySum(int []);
int lowest(int []);
int highest(int []);

int main()
{
    const int SIZE = 20;
    int values[SIZE] = {0, 23, 34, -7, 110, 42, -350, 424, 25, 99, 10, 05, 50, -5, 1, 200, -350, 437, 25, 147};

    //functions call
    arraySum(values);
    lowest(values);
    highest(values);

    //display the result
    cout<<"The sum is "<<arraySum(values)<<" , the highes number is "<<highest(values)<<" , the lowest number is  "<<lowest(values)<<endl;

	system("pause");
    return 0;

}



int arraySum(int values[]){

    //variable name
    int total=0;

    for(int i = 0; i<20;i++){

        total +=values[i];//keep adding the total when its looping


    }

    return total; //return the total
}

int lowest(int values[]){

    //assign total to the first number of the array
    int low=values[0];


    for(int i = 0; i<20;i++){
        //finding the lowest number in the array
        if(low>values[i]){
            low=values[i]; //assign the lowest number to low

        }


    }

    return low; //return the lowest number
}

int highest(int values[]){

    //assign total to the first number of the array
    int high=values[0];

    for(int i = 0; i<20;i++){
        //finding the highest number in the array
        if(values[i]>high){
            high=values[i];  //assign the highest number to low

        }

    }

    return high; //return highest
}
