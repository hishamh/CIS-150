/*
 main.cpp
 Question 5_CIS 150 – Lab 04

 Created by Hisham on 2/7/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: ask the user for a character and the height and printed within nested loops
 */


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    char  Keyboardchar;
    int number;

    //ask the user of the character type by the user
    cout <<"Enter a character : ";
    cin >>Keyboardchar;

    //entering the height by the usr
    cout <<"Enter a height : ";
    cin >>number;

    /*
        doing nisted loops fist if the i < number it will go to the next loop
        and in the second loop will keep contire til its true and will go back to the first loop

     */
    for(int i = 0; i<number;i++){
        for(int j=0; j<=i;j++){

            cout<<Keyboardchar;
        }
          cout<<endl;
    }

    system("pause");
    return 0;
}
