/*
 main.cpp
 Question 2_CIS 150 – Lab 09

 Created by Hisham on 3/30/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: open a file with a numbers and load all they number to a array then look how many negative numbers found in the array and ask the user for a search value to look if there is is match one in the array. All this done by a separated function
 */

#include <iostream>
#include<iomanip>
#include<fstream>


using namespace std;

//function prototypes
void readNumbers (ifstream& , int [], int& );
int countNegativeInArray (int [], int );
bool searchValueInArray (int , int [], int);



int main()
{
    //variables names
    const int SIZE =200;  //never change
    int numbers [SIZE];
    int numbersCount,value;
    int holdNegative=0;
    bool isValueFound;

    ifstream myFileNumbers("numbers.txt");//open the file only

    //function call that load the file information to he array and count the numbers inside the array.
    readNumbers (myFileNumbers,numbers,numbersCount);
    holdNegative = countNegativeInArray(numbers,numbersCount); // function call to find the negative numbers

    //ask the user for the value they want to search insie the array
    cout<<"What value do you want to serach in the array: ";
    cin>>value;

    //this function check if the search value is found or not
    isValueFound = searchValueInArray(value, numbers, numbersCount);

    //if the search value found then it will display how many values found
    if (isValueFound == 1){

        cout<<"There are "<<holdNegative<<" negative "<<"and the searched value "<<value <<" founed"<<endl;


    }else{
            //display the result if the value not found in the array
         cout<<"There are "<<holdNegative<<" negative "<<"and the searched value "<<value <<" not founed"<<endl;

    }





    myFileNumbers.close();//close the file

    return 0;
}


void readNumbers (ifstream &myFileNumbers, int numbers[], int& numbersCount)
{
    //variables for the array
    int i=0;

    //check if the file is opened
    if(myFileNumbers.fail()){

        cout<<"File can't be opened"<<endl;

    }else{
            //run to the end of the file
            while(!myFileNumbers.eof()){

                //load the information from the file to the array by increment[i] to the array to place it to the each elements
                myFileNumbers>>numbers[i];
                i++; //keep increment for the next data



            }//end of while

            numbersCount = i;//count how many lines in the array or in he files
    }//end of else

}

int countNegativeInArray (int numbers[], int numbersCount)
{
    //varaibles
    int countNegative = 0, found=0;

    //keeps loop then the it is stops
    for(int i = 0; i < numbersCount; i++){

        //check if number is found
        if(found > numbers[i]){

            countNegative++; //increment 1 each time when a number is found on the array

        }

    }

    return countNegative; //return how many numbers found
}


bool searchValueInArray (int value, int numbers[], int numbersCount)
{
    //keep loop till it stops
    for(int i = 0; i < numbersCount; i++){

        //check if the value the user want to search found then return true else return false
        if(value == numbers[i]){

            return true; //if found return true
        }


    }

    return false; //not found then return false

}
