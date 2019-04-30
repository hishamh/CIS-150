/*
 main.cpp
 Question 2_CIS 150 – Lab 08

 Created by Hisham on 3/25/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: Load a file to the program and calculate the average of the students using a function. */


#include <iostream>
#include<fstream>
#include<iomanip>


using namespace std;

double readAndProcess(ifstream&,double); //function prototype


int main(int argc, const char * argv[]) {


    //variables names
    double avg;
    string fileName;

    //ask for the file name
    cout<<"Enter the name of the file: ";
    cin>>fileName;

    ifstream readStudentFile;//open and reads whatever inside the file
    readStudentFile.open(fileName.c_str());


    //hold the calculated avg from the function
    avg = readAndProcess(readStudentFile,avg); //function calls

    //if the file faild to open the this error will display
    if(avg == 1){

        cout<<"\nError trying open the file\n";

    }else{
        //show the average
        cout<<"\nThe average is "<<avg<<endl;
    }

    readStudentFile.close(); //close file
    system("pause");
    return 0;
}


double readAndProcess(ifstream &readStudentFile,double avg){


    //variables
    string firstName,string,lastName;
    int items=0,score=0;
    double sum=0;

    //check if there is any problem with the file if its failed to open
    if(readStudentFile.fail()){

        return 1;
    }
    else{

        //it is going to loop to the end of the file
        while(!readStudentFile.eof()){


            //it will send all the information to each variables name
            readStudentFile>>firstName>>lastName>>score;
            //display the out put
            cout<<setw(10) << left << firstName << setw(15) << left << lastName<< setw(10) << score << endl;

            //calculated the score of student’s grade
                sum += score;
                items++; //how many items in the file

        }//end of while loop

        //calculated the avg
        avg = sum / items;

    }//end of else
    return avg;
}
