/*
 main.cpp
 Question 1_CIS 150 – Lab 08

 Created by Hisham on 3/25/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: At text file has an employee name, hours worked, and pay rate. So we have to call the file and calculate the weekly salary then we have to save the information to a file
 */

#include <iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void readAndProcess(ifstream&,ofstream&); //function prototype


int main(int argc, const char * argv[]) {



    ifstream readEmployees("employees.txt");//open and reads whatever inside the file
    ofstream writeToFile("results.txt"); //opens and write into the file


    //function do all the process
    readAndProcess(readEmployees,writeToFile); //function calls


    readEmployees.close(); //file close
    writeToFile.close(); //file close

    system("pause");

       return 0;
}


void readAndProcess(ifstream &readEmployees,ofstream &writeToFile){

    //variables names
    string firstName,lastName;
    double hoursPerWeek,hourlyPayRate,weeklySalary;


    //check if there is any problem with the file if its failed to open
    if(readEmployees.fail()){


        cout<<"Problem with opeining the file";

    }
    else{

        //it is going to loop to the end of the file
        while(!readEmployees.eof()){

            //the pass the data to the variables
            readEmployees>>firstName>>lastName>>hoursPerWeek>>hourlyPayRate;

            //do the math of each one for each name
            weeklySalary = hourlyPayRate * hoursPerWeek;

            //print the data to the user with the fix information and also for test
            cout<< setw(10) << left << firstName << setw(10) << left << lastName << setw(10) << " -----> " << setw(5) << weeklySalary << endl;


            //write the information to  the file
            writeToFile<<setw(10) << left << firstName << setw(10) << left << lastName << setw(10) << " -----> " << setw(5) << weeklySalary << endl;

        }

        cout<<"\n\nAll inforamtion is save to a file called results.txt"<<endl<<endl;


    }

}
