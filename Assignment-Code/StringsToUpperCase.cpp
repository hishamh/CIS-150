/*
 main.cpp
 Question 3_CIS 150 – Lab 08

 Created by Hisham on 3/25/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: Load a text file to the program and change all string inside the file to Upper cases and find the longest sentences and how many lines on the file and how many characters. after the save all the information to different file for example after you change it to upper cease then save it to different file and that goes for the others
 */


#include <iostream>
#include <fstream>
#include <istream>
#include <string>


using namespace std;
string convToUpper(string); //function prototype

int main(){

    //variables
    string linesInsideFile,allUp,largest="";
    int countLines=0,countCharWithWhiteSpace=0,countNoWhitSpace=0;

    ifstream readMyFile("sam.txt");//reads
    ofstream writeToMyFile("SameToUpper.txt"); //write
    ofstream writeToMyFile2("samDetials.txt");  //write

    //check if the file is working correctly
    if(readMyFile.fail()){

        cout<<"Error: the file you enter can't be open";
    }
    else{
        //read to the end of the file
        while(!readMyFile.eof()){
            //getline is getting the whole sentences in the file
            getline(readMyFile,linesInsideFile);


            //for loop check the larges sentences inside the file
            for(int i = 0; i<linesInsideFile.length();i++){

                //finding the largest sentences
                if(linesInsideFile.length()>largest.length()){

                    largest = linesInsideFile;//assign the largest sentences to largest

                }
                //check if there is no white space and if there aren’t it will keep to increase the count
                if (!isspace(linesInsideFile[i])){
                    countNoWhitSpace++; //count the lines without spaces
                }

            }//end of for loop

            //calculating the length in whole file with spaces
            countCharWithWhiteSpace +=linesInsideFile.length();
            countLines++;//count how many lines in the file


            convToUpper(linesInsideFile); //function call to convert to upper cases
            writeToMyFile<<convToUpper(linesInsideFile)<<endl; //write to the file to upper cases

            writeToMyFile2<<countLines<<": "<<linesInsideFile<<endl; //display the lines after each sentences


        }//end of while loop

        //write the information to a file we created
        writeToMyFile2<<"\n\nThe largest sentence is: "<<largest<<endl;
        writeToMyFile2<<"There are total of "<<countLines<<" of lines in file"<<endl;
        writeToMyFile2<<"There are total of "<<countCharWithWhiteSpace<<" With white space"<<endl;
        writeToMyFile2<<"There are total of "<<countNoWhitSpace<<" Without white space"<<endl;


    }//end of if statement

    writeToMyFile.close(); //file close
    readMyFile.close(); //file close

    return 0;
}


string convToUpper(string linesInsideFile){

    //loops till it convert all letter to upper cases
    for(int i = 0; i<linesInsideFile.length();i++){

        //convert every single letter to upper case
        linesInsideFile[i] = toupper(linesInsideFile[i]);


    }
    return linesInsideFile; //return it
}

