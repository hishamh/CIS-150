/*
    main.cpp
    Question 2_CIS 150 – Lab 04

    Created by Hisham on 2/14/17.
    Copyright © 2017 Hisham Hussein. All rights reserved.
    Purpose: Ask the user for a grade letter and compare them with switch statement
 */

#include <iostream>
using namespace std;

int main() {

    char gradeLetter;

    //ask the user for an input for his grade
    cout <<"Enter your letter grade: ";
    cin >>gradeLetter;

    //comparing the entered values by the user
    switch (gradeLetter) {
        case 'A': case 'a':
            cout <<"Excellent"<<endl;
            break;
        case 'B':case'b':
            cout <<"Good"<<endl;
            break;
        case 'C':case 'c':
            cout <<"Average"<<endl;
            break;
        case 'D': case 'E':case 'd':case 'e':
            cout <<"Below Average"<<endl;
            break;
        case 'F': case 'f':
            cout <<"Fail"<<endl;
            break;
        default:
            cout<<"Invalid Grade\n\n";
            break;
    }
    system("pause");
    return 0;
}
