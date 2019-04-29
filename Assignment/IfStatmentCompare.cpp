/*
  main.cpp
  Question 1_CIS 150 – Lab 03

  Created by Hisham on 2/7/17.
  Copyright © 2017 Hisham Hussein. All rights reserved.
  Purpose: Use the if statement to see what will the value 10 output or what the value 5 is going to output. It is all depends on the if statement and the value we put in it
*/


#include <iostream>
#include <iostream>

using namespace std;

int main() {
    int x, y;

    cout << "Please enter an integer value: ";
    cin >> x;

    if (x >= 9)
    {
        x = x + 1;
        y = x * x;
    }
    else
    {
        x = x * 2;
        y = x + x;
    }

    cout << "x = " << x << " y = " << y << endl;

    system("pause");
    return 0;
}
