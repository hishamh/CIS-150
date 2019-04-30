/*
 main.cpp
 CIS 150 Winter 2017 Project 02

 Created by Hisham on 04/19/17.
 Last time modification by Hisham on 04/23/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: This is an airplane seat reservation where the user can reserve seat when he/she enter the row number and the column letter. any seat that is reserved will be market with the letter X. The user also can remove the reservation seats by just entering the row number and the letter he wants to cancel. Moreover, the user can view the statistics of how many airplane seats windows left and aisle seats, and what is the percentage of the reserved seats. Also the user can save the reservation of the seats to a file with all the information.
 */



#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>

#define ROW 26
#define COLUM  26

using namespace std;

//function protype
void mune(void);
int determinRow();
void displaySeat(ifstream&,string[][COLUM],int,int,int&);
void reserveSeat(string[][COLUM],int,int);
void cancelReserveSeat(string [ROW][COLUM],int,int);
void saveToFile(string [][COLUM],int,int);
void help(void);
void statistics(string [][COLUM],int,int,int&);
void goodBye(void);

int main(int argc, const char * argv[]) {

    //variables

    string seatChart[ROW][COLUM]={};
    int cColum,rRow,countArray,holdRowDetermin,option;
    ifstream openAirPlaneSetsFile;

    //giving the user to choose option between the fixed array or unlimited array
    holdRowDetermin = determinRow();// function call

    //check what option does the user choose
    if(holdRowDetermin==1){
        openAirPlaneSetsFile.open("chartin.txt");//open the file called chartin.txt
        cColum = 23;
        rRow = 25;
    }else{
        openAirPlaneSetsFile.open("chartin2.txt");//open the file called chartin2.txt
        cColum = 4;
        rRow = 10;

    }

    do{

        mune(); //display mune

        //asking the user to choos one of the option from the mune
        cout<<"Choose one of the operation: ";
        cin>> option;


        switch (option) {
            case 1:
                //function call to load the fill data to the array
                displaySeat(openAirPlaneSetsFile, seatChart,rRow,cColum,countArray);
                openAirPlaneSetsFile.close();
                break;
            case 2:
                //function call the asks the user for seats number and row
                reserveSeat(seatChart,rRow,cColum);
                break;
            case 3:
                //function call that ask the use for row number and seat letter to cancel the reservation
                cancelReserveSeat(seatChart,rRow,cColum);
                break;
            case 4:
                //function call that save the airplane seats after the user choose the eats
                saveToFile(seatChart,rRow,cColum);
                break;
            case 5:
                //function call shows information like how many seats left on the windows and the total percentage of seat reserved
                statistics(seatChart,rRow,cColum,countArray);
                break;
            case 6:
                //function call that show the user how to user the program in detailed way
                help();
                break;
            case 7:
                //exit program
                goodBye();
                exit(0);
                break;
            default:
                cout<<"\n\nYou choose the wrong operation\n\n";
                break;
        }

    }while(option != '7');

    return 0;
}

void mune(void){
    /*
     Purpose: This only display the menu to the user
     Author: Hisham Hussein
     Creation Date: 04/12/17
     Last time function modification by Hisham on 04/12/17.
     */


    //display a menu
    cout<<"------------------------ Menu ---------------------------";
    cout<<"\n1. Display Seat Chart";
    cout<<"\n2. Reserve Seat";
    cout<<"\n3. Cancel Reservation";
    cout<<"\n4. Save Seat Chart to File";
    cout<<"\n5. Statistics";
    cout<<"\n6. Help";
    cout<<"\n7. Quit";
    cout<<"\n---------------------------------------------------------"<<endl;

}

int determinRow(){
    /*
     Purpose: This only determine if the user choose limited
     or unlimited seat plane
     Author: Hisham Hussein
     Creation Date: 04/16/17
     Last time function modification by Hisham on 04/16/17.
     */

    //giving the user the option to choose weather he/she wants the limited or unlimited airplane seats
    int fixAirePlaneSeats;
    do {
        cout<<"---------------------- Choose Plan ----------------------";
        cout<<"\nPlease choose the unlimited seat plane or the fixed seat \n";
        cout<<"1. Any row and column\n";
        cout<<"2. Fixed row and column\n";
        cout<<"Please choose one: ";
        cin>>fixAirePlaneSeats;
        cout<<endl;
        //check if the user enter values greater or less then the option we gave
        if(fixAirePlaneSeats > 2 || fixAirePlaneSeats < 1){
            cout<<"There is no option of "<<fixAirePlaneSeats<<endl<<endl;
        }
    }while(fixAirePlaneSeats > 2 || fixAirePlaneSeats < 1);

    return fixAirePlaneSeats; //send the choose to the function main
}
void displaySeat(ifstream &openAirPlaneSetsFile, string seatChart[ROW][COLUM],int rRow,int cColum,int &countArray){

    /*
     Purpose: This function load the data from the file to
     the array and then print the airplane seats
     Author: Hisham Hussein
     Creation Date: 04/12/17
     Last time function modification by Hisham on 04/15/17.
     */

    //read all the information on the file to the array
    while(!openAirPlaneSetsFile.eof()){

        //put the file information into the array
        for(int r = 0; r<rRow;r++){

            for(int c = 0; c<cColum;c++){

                //information saved in the array now
                openAirPlaneSetsFile>> seatChart[r][c];
                countArray++;

            }//end of inner for loop

        }//end of outer for loop

    }//end of while lop

    //check weather the column the user choose limited or unlimited
    if(cColum==23){

        cout<<"ROW  "<<"A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W\n";
        cout<<"---  "<<"-------------------------------------------------------------------\n";

        //print out the seat chart
        for(int r = 0; r<rRow;r++){

            cout<<r<<"\t ";

            for(int c = 0; c<cColum;c++){

                cout<< seatChart[r][c]<<"  ";

            }//end of inner for loop
            cout<<endl;
        }//end of outer for loop
    }else{
        //display the second limited airplane seats
        cout<<"ROW  "<<"A  B  C  D\n";
        cout<<"---  "<<"----------\n";

        //print out the seat chart

        for(int r = 0; r<rRow;r++){

            cout<<r<<"\t ";

            for(int c = 0; c<cColum;c++){

                cout<< seatChart[r][c]<<"  ";

            }//end of inner for loop
            cout<<endl;
        }//end of outer for loop

    }
}

void reserveSeat(string seatChart[][COLUM],int rRow,int cColum){

    /*
     Purpose: This function is only reserve seats for the user when
     enter the seat information
     Author: Hisham Hussein
     Creation Date: 04/16/17
     Last time function modification by Hisham on 04/18/17.
     */

    int row,c;
    char colum;

    //check weather the column the user choose limited or unlimited
    if(cColum != 23){

        do{
            //ask the user for the row number and the column letter to reserve the seats
            cout<<"Enter the row number with column letter ex(0 A): ";
            cin>>row>>colum;

            //convert the letter the user enter to upper letter
            colum = toupper(colum);
            c= int(colum - 'A');// subtract A because will convert it to an array like A-A=0,B-A=1,C-A=2
            //convert the char to string to compare letters of ABC
            string convertColumToString(1, colum);

            //check if the seats is taken or not
            if (seatChart[row][c] == "X"){
                cout<<"seat is already taken\n\n";

            }
            //validate the user if he entered value greater then D
            if(convertColumToString>"D"){

                cout<<"\nThere is no letter "<<colum<<" in the airplane seats!\n\n";
            }

            //keep loop if he keeps enter any value Greater then D or value is equal X
        }while(seatChart[row][c] == "X" || colum>'D');

        //if the information all correct then reserve the seats
        seatChart[row][c] = "X";
        cout<<"your successfully reserve your seat\n\n";

    }else{
        string convertLetter;

        do{
            //ask the user for the row number and the column letter to reserve the seats
            cout<<"Enter the row number with column letter ex(0 A): ";
            cin>>row>>colum;

            //convert the letter the user enter to upper letter
            colum = toupper(colum);
            c= int(colum - 'A');// substract  A because will convert it to an array like A-A=0,B-A=1,C-A=2

            //validate the user if he entered value greater then D
            if (seatChart[row][c] == "X"){
                cout<<"seat is already taken\n\n";
            }//end of first end statement

            //convert char to string so i can compare them
            convertLetter =to_string(colum);

            //check if the user enter letter greater or equal Z
            if(convertLetter<="Z"){

                cout<<"\nThere is no letter "<<colum<<" in the airplane seats!\n\n";

            }//end of second if statement

        }while(seatChart[row][c] == "X" || colum>'W');

        //if the information all correct then reserve the seats
        seatChart[row][c] = "X";
        cout<<"your successfully reserve your seat\n\n";

    }

}

void cancelReserveSeat(string seatChart[ROW][COLUM],int rRow,int cColum){

    /*
     Purpose: This function is only canceling seats for the user when
     enter the seat information
     Author: Hisham Hussein
     Creation Date: 04/12/17
     Last time function modification by Hisham on 04/15/17.
     */


    int row;
    char colum,askAgain;

    //check weather the column the user choose limited or unlimited
    if(colum != 23){
        do{
            //ask the user for the row number and the column letter to cancel the seats
            cout<<"Enter the row number with column letter to cancel ex(0 A): ";
            cin>>row>>colum;
            colum = toupper(colum);
            int c= int(colum - 'A');
            string convertColumToString(1, colum);
            //check if the letter is less then D
            if(convertColumToString <="D"){

                //check if the seat is taken if not then assign seatChar to the letter of the user entered
                if(seatChart[row][c] == "X"){
                    seatChart[row][c] = colum;//assign the column to the correct position
                    cout<<"\nYour seat has been canceled\n";
                }
                else{
                    //display error if the seats is not taken
                    cout<<"\nSeat is not taken to cancel\n";
                }

            }
            else
            {
                //display error if the user enter out of range letter for the column
                cout<<"\nThere is no letter "<<colum<<" in the airplane seats to cancel!\n\n";
            }


            //ask the user if there is another seats to cancel
            cout<<"\n\nIs There another seat to cancel y/n: ";
            cin >>askAgain;
            askAgain = tolower(askAgain);

        }while(askAgain != 'n');
    }//end of first if statement column != 23
    else{

        do{
            //ask the user for the row number and the column letter to cancel the seats
            cout<<"Enter the row number with column letter to cancel ex(0 A): ";
            cin>>row>>colum;
            colum = toupper(colum); //convert letter to upper case
            int c= int(colum - 'A');    //an array of abcd
            string convertColumToString(1, colum); //converting char to string

            //check if the user enter greater then W to display error
            if(convertColumToString >"W"){

                //check if the seat is taken if not then assign seatChar to the letter of the user entered
                if(seatChart[row][c] == "X"){

                    seatChart[row][c] = colum;
                    cout<<"\nYour seat has been canceled\n";

                }else{
                    //display error if the seats is not taken
                    cout<<"\nSeat is not taken to cancel\n";
                }

            }else{
                //display error if the user enter out of range column letter
                cout<<"\nThere is no letter "<<colum<<" in the airplane seats to cancel!\n\n";

            }

            //ask the user if there is another seats to cancel
            cout<<"\n\nIs There another seat to cancel y/n: ";
            cin >>askAgain;

        }while(askAgain != 'n');

    }//end of else statement for the first if statement if column != 23

}

void saveToFile(string seatChart[][COLUM],int rRow,int cColum){

    /*
     Purpose: This only save the seat information array to
     a file
     Author: Hisham Hussein
     Creation Date: 04/16/17
     Last time function modification by Hisham on 04/16/17.
     */

    string fileName;
    //ask the user for a file name
    cout<<"Enter the name of the file with .txt at the end: ";
    cin>>fileName;

    //opens the file name
    ofstream writSeatchartReservation(fileName.c_str());

    if(cColum == 23){
        //organize the file into more readable
        writSeatchartReservation<<"ROW\t"<<" A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W\n";
        writSeatchartReservation<<"---\t"<<" -------------------------------------------------------------------\n";
        //loop through the array
        for(int r = 0; r<rRow;r++){

            writSeatchartReservation<< r<<"\t "; //write down to file

            for(int c = 0; c<cColum;c++){

                writSeatchartReservation<< seatChart[r][c]<<"  "; //write down the seats to the file

            }//end of inner for loop
            writSeatchartReservation<<endl;

        }//end of outer for loop

        writSeatchartReservation.close();// close the file after the information is saved
        cout<<"\nYour airplane seats file is saved\n\n";
    }else{

        //organize the file into more readable
        writSeatchartReservation<<"ROW\t"<<" A  B  C  D\n";
        writSeatchartReservation<<"---\t"<<" ----------\n";
        //loop through the array
        for(int r = 0; r<rRow;r++){

            writSeatchartReservation<< r<<"\t "; //write down to file

            for(int c = 0; c<cColum;c++){

                writSeatchartReservation<< seatChart[r][c]<<"  "; //write down the seats to the file

            }//end of inner for loop
            writSeatchartReservation<<endl;

        }//end of outer for loop

        writSeatchartReservation.close();// close the file after the information is saved
        cout<<"\nYour airplane seats file is saved\n\n";
    }
}

void help(void){
    /*
     Purpose: This function is only show help if
     the user get stuck
     enter the seat information
     Author: Hisham Hussein
     Creation Date: 04/12/17
     Last time function modification by Hisham on 04/12/17.
     */

    //expale in detial what each function do and how to use them
    cout<<"\n------------------------ HELP ---------------------------";
    cout<<"\n      Welcome to University of Michigan airline help";
    cout<<"\n---------------------------------------------------------\n";

    cout<<"\n-Option 1 is the first thing to do befor anything,\n";
    cout<<"      option 1 which display the seats of the airplane\n";
    cout<<"      the airplane seats ";
    cout<<"\n\n-option 2 lets you reserve a seats in the airplane;\n";
    cout<<"      the way to reserve a seats is by entering the row\n";
    cout<<"      number that between 0-9 with space and a letter\n";
    cout<<"      from A-D EXAMPLE(5  D), this will reserve row\n";
    cout<<"      number 5 seat D   ";
    cout<<"\n\n-option 3 lets you cancel reserve a seats, the way\n";
    cout<<"      to cancel a reserve seats is by entering the row\n";
    cout<<"      number that between 0-9 with space and a letter \n";
    cout<<"      from A-D EXAMPLE(5  D), this will cancel the\n";
    cout<<"      resrvation seat row number 5 seat D";
    cout<<"\n\n-option 4 lets you save reservetion of seats, to a\n";
    cout<<"      file that you have to enter the name of the file\n";
    cout<<"      number that between 0-9 with space and a letter\n";
    cout<<"      then the program will save it to your computer\n";
    cout<<"      you do this after you sure that you want the seat\n";
    cout<<"\n\n-option 5 shows the Statistics of airplane seats\n";
    cout<<"      ,it shows you how many seats avilbel,how many \n";
    cout<<"      seats left on the window,and aisle of the airplan\n";
    cout<<"      and lastly it will show you the percentage of \n";
    cout<<"      a total airplane seats resrvation\n";
    cout<<"\n\n-option 6 is where you at now, which is seeking \n";
    cout<<"      help and helps you what each function do\n";
    cout<<"\n\n-option 7 is where to exit. After you finish \n";
    cout<<"      and you want to exit, just press option 7 \n\n";

}
void statistics(string seatChart[][COLUM],int rRow,int cColum,int &countArray){
    /*
     Purpose: This function show the statistics information like how
     many seats left on the windows side, percentage of
     seat reserved, and aisle seats
     enter the seat information
     Author: Hisham Hussein
     Creation Date: 04/16/17
     Last time function modification by Hisham on 04/19/17.
     */

    int windowsSeats=0,aisleSeats=0, availableSeats=0;
    float percReserved= 0.0;
    //run thourgh the two dimensional array
    for(int r = 0; r<rRow; r++){
        for(int c = 0; c< cColum; c++){
            //check if the user choose the unlimited or not
            if(cColum!=23){

                //check how many seats available for windows position
                if(seatChart[r][c] == "A" || seatChart[r][c] == "D"){
                    windowsSeats++;
                }

                //check how many seats available for aisle
                if(seatChart[r][c] == "B" || seatChart[r][c] == "C"){

                    aisleSeats++; //count how many aisle seats

                }

                //check the reserved seats
                if(seatChart[r][c] != "X"){

                    availableSeats++; //count total of available seats
                }

            }else{

                if(seatChart[r][c] == "A" || seatChart[r][c] == "W"){
                    windowsSeats++; //calculate windows seats
                }


                //check how many seats available for aisle
                if(seatChart[r][c] >= "B" && seatChart[r][c] <="V") {

                    aisleSeats++; //calculate the aisle seats

                }

                //check the reserved seats
                if(seatChart[r][c] != "X"){

                    availableSeats++;
                }

            }//end of else statement

        }//end for inner  loop

    }//end for outer loo[

    //calculate the percentage of seat reserve
    percReserved =((countArray-float(availableSeats))/countArray) *100;

    //display the result
    cout<<"\nPercentage of reserved seats is: "<<fixed<<showpoint<<setprecision(2)<<percReserved<<"%";
    cout<<"\nSeats available: "<<availableSeats;
    cout<<"\nWindows seats available: "<<windowsSeats;
    cout<<"\nAisle seats available: "<<aisleSeats<<endl;

}

void goodBye(){
    /*
     Purpose: This only display thank you message after the
     user exit the program
     Author: Hisham Hussein
     Creation Date: 04/12/17
     Last time function modification by Hisham on 04/12/17.
     */

    //display message when the user exit
    cout<<"\n------------------------ Thank You ----------------------";
    cout<<"\n      For Using University of Michigan airline";
    cout<<"\n               We hope so you again";
    cout<<"\n---------------------------------------------------------\n";

}
