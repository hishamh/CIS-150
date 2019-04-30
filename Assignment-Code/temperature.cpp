/*
    main.cpp
    Question 1_CIS 150 – Lab 04

    Created by Hisham on 2/14/17.
    Copyright © 2017 Hisham Hussein. All rights reserved.
    Purpose: Asking the user of the temperature and determine what to do by if else statement
*/

#include <iostream>
using namespace std;

int main() {

    int temp;

	//ask the user for an input for temperature
    cout <<"\n\nWhat is current temperature in Fahrenheit: ";
    cin >>temp;

    //check the heat of the temperature and show the correct result
    if(temp>90){
        cout <<"Visit a neighbor"<<endl;

    }
    else if (temp <=90 && temp >80){
       cout <<"Turn on air conditioning."<<endl;

    }
    else if (temp <= 80 && temp >70){
       cout <<"Do nothing."<<endl;

    }
     else if (temp <= 70 && temp >55){
      cout <<"Turn on heat"<<endl;

    }
    else if (temp <= 55 && temp >30){
        cout <<"Wear a heavy coat."<<endl;

    }
    else if (temp <=30 && temp >0){
        cout <<"Wear gloves."<<endl;

    }
    else{
        cout <<"Stay home"<<endl;

    }

system("pause");

    return 0;
}
