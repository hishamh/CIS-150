/*
 main.cpp
 Question 2_CIS 150 – Lab 03

 Created by Hisham on 2/7/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: Ask the user for his name and his age, if his age is >=18 he is able to vote else he wont be able to vote if his age < 18
 */


#include <iostream>
#include <string>


using namespace std;

int main() {
    string name; //user’s name
    int age;	//user’s age

    //ask the user for name
    cout << "Enter your name ";
    cin>> name; //accept white space to enter his fist name and last name as one line

    //ask for the age
    cout << "Enter your age ";
    cin>> age;


    //if age greater than 18 it will let him pass to vote and if the vote is less than 18 it wont let him
    if(age >=18){

        cout <<"Congratulations "<< name <<" Your vote registration was successfully processed."<<endl;

    }
    else
    {
        cout <<"You are not eligible to vote "<<name<<endl;
    }


    system("pause");
    return 0;
}
