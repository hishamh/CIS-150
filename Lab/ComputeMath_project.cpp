
/*
 main.cpp
 CIS 150 Winter 2017 Project 01

 Created by Hisham on 03/13/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: It is a mini calculator the use only function to do the calculation then send the answer back to main(). The user will be able to choose an option for the menu and the operation he/she pick will be processed to the selection option. The user will be able to will see which operation was successful or not.
 */


#include <iostream>
#include <algorithm>
using namespace std;

void welcomeScreen(void);   //function prototype
void menu(void);    //function prototype
float computeSum(float,float);  //function prototype
float computeSub (float,float); //function prototype
float computeMul(float,float);  //function prototype
float computeDiv(float,float);  //function prototype
float computeRoot(float,int);   //function prototype
float computePower(float,int); //function prototype
float computePerc(float,float); //function prototype
int   computeLCM(int,int);      //function prototype
int   computeGCD(int,int);      //function prototype
int   computeMod(int, int);      //function prototype
void isWorking(bool,bool,bool,bool,bool,bool,bool,bool,bool,bool);  //function prototype
void userExit(void); //function prototype


int main(int argc, const char * argv[]) {


    //variables that hold the function answer after it calculated
    float sumResult,subResult,mulResult,divResult,rootResult,powerResult,percResult;
    int index,modResult,gcdResult,lcmResult;
    float num1,num2,perc,root;
    char choose;

    //bool is checking weather the user go through the operation if he did the false will change to true
    bool addWorking = false,subWorking = false,mulWorking = false,divWorking = false,rootWorking = false,powerWorking = false,percWorking = false,lcmWorking = false,gcdWorking = false,modWorking = false;


            welcomeScreen();//welcome screen
    do{


            menu(); //function that display the main menu operation you want to make

            //The user must enter one of the following menu
            cout <<"\t\t\tPlease select an operation:  ";
            cin >> choose;


            //switch statement will compare with the cases
        switch (choose) {
            case 'A': case 'a':

                        cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on addional section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";

                //ask the user for number as input
                        cout <<"Enter the first number: ";
                        cin >>num1;

                        cout <<"Enter the second number: ";
                        cin >>num2;

                        //sumResult is holding the number returned by the computeSum(num1,num2)
                        sumResult =computeSum(num1,num2);  //function call

                //display the answer after it calculation by the function
                        cout <<"\nThe total of "<<num1<<" + " <<num2<<" = " << sumResult <<endl;
                //If the user pick A operation, the addWorking will change from false to true to show that the user clicked choose letter A
                        addWorking = true;

                break;
            case 'B': case 'b':

                        cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on subtraction section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";

                    //ask the user for an input
                        cout <<"Enter the first number: ";
                        cin >>num1;

                        cout <<"Enter the second number: ";
                        cin >>num2;

                //subResult is holding the number returned by the computeSub(num1,num2)
                        subResult =computeSub(num1,num2);  //function call
                //show the result that returned by the function
                        cout <<"\nThe The answer of "<<num1<<" - " <<num2<<" = " << subResult <<endl;

                //change to true if the user went through this operation
                        subWorking = true;
                break;
            case 'C': case 'c':

                        cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on multiplication section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++++\n";

                //ask the user for an input
                        cout <<"Enter the first number: ";
                        cin >>num1;

                        cout <<"Enter the second number: ";
                        cin >>num2;

                //mulResult is holding the number returned by the computeSub(num1,num2)
                        mulResult = computeMul(num1,num2);
                //change to true if the user went through this operation
                        mulWorking = true;
                //show the result that calculated by the function
                cout <<"\nThe total of "<<num1<<" * " <<num2<<" = " << mulResult <<endl;
                break;
            case 'D': case 'd':

                //keeps looping as long as the user put 0 for numb2 because you cant divide by zero
                    do{
                        cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on division section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";

                    //ask the user for input
                        cout <<"Enter the first number: ";
                        cin >>num1;

                        cout <<"Enter the second number: ";
                        cin >>num2;

                        //display an error if the suer put 0 for num2
                        if(num2 == 0){

                            cout <<"\nYou can't divide by zero\n\n";
                        }

                    }while(num2 == 0);

                //divResult is holding the number returned by the computeDiv(num1,num2)
                        divResult = computeDiv(num1,num2);

                //show the result that caluclated by the function
                        cout <<"\nThe answer of "<<num1<<" / " <<num2<<" = " << divResult <<endl;

                //change to true if the user went through this operaton
                        divWorking = true;

                break;

            case 'E': case 'e':
               do {
                cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on root section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";

                //keeps repeat  the loop if the user put - number

                    //ask the user for input
                    cout <<"Enter the root: ";
                    cin >>root;
                    cout <<"Enter the index : ";
                    cin >>index;

                    //check it to display the error
                    if(root<0 || index < 0){
                        cout<<"\nYou cant have negative in roots\n";

                    }

                }while(root < 0  || index <0);

                //divResult is holding the number returned by the computeDiv(num1,num2)
                rootResult = computeRoot(root,index);
                //display the answer
                cout<<"\nThe root of "<<root <<" is "<<rootResult<<endl<<endl;

                //change to true if the user went through this operaton
                rootWorking = true;

                break;
            case 'F': case 'f':

                do{
                        cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on power section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";

                        cout <<"Enter the a number: ";
                        cin >>num1;
                        cout <<"To what power of : ";
                        cin >>num2;

                 //check it to display the error
                    if (num1<0){

                        cout <<"\nYou cant have "<<num1<<" becasue it is negative\n\n";
                    //display error if the user enters negative number
                    }else if(num2<0){

                        cout <<"\nYou cant have "<<num2<<" becasue it is negative\n\n";


                    }
                }while(num1<0 || num2<0);

                       //powerResult is holding the number returned by the computePower(num1,num2)
                        powerResult = computePower(num1,num2);  //function call

                        cout <<"\nThe power of "<<num1<<" is "<<powerResult<<endl<<endl;

                        //change to true if the user went through this operation
                        powerWorking = true;

                break;
            case 'G': case 'g':

                cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on percentage section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";

                //ask the user for a input
                        cout <<"Enter a number: ";
                        cin >>num1;
                        cout <<"Enter a percentage: ";
                        cin >>perc;

                //percResult is holding the number returned by the computePerc(num1,perc)
                        percResult = computePerc(num1,perc);  //function call

                 //display the answer
                        cout <<"\nThe percentage of : "<<num1<< " % "<< perc<<" = "<<percResult << endl<<endl;

                //change to true if the user went through this operation
                        percWorking = true;


                break;
            case 'H': case 'h':

                cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on LCM section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";


                //ask the user for input
                    cout <<"Enter the first number LCM: ";
                    cin >>num1;

                    cout <<"Enter the second number LCM: ";
                    cin >>num2;

                //percResult is holding the number returned by the computeLCM(num1,num2)
                    lcmResult = computeLCM(num1,num2); //function call
                //display the answer
                    cout<<"\nThe LCM number is "<<lcmResult<<endl<<endl;
                //change to true if the user went through this operation
                    lcmWorking = true;

                break;
            case 'I': case 'i':

                cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on GCD section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";

                //ask the user for input
                    cout <<"Enter the first number GCD: ";
                    cin >>num1;

                    cout <<"Enter the second number GCD: ";
                    cin >>num2;

                //gcdResult is holding the number returned by the computeGCD(num1,num2)
                    gcdResult = computeGCD(num1,num2); //function call
                //display the answer
                    cout <<"\nThe greates commoun number is "<<gcdResult<<endl<<endl;
                //change to true if the user went through this operation
                    gcdWorking = true;

                break;
            case 'J': case 'j':

                cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++\n";
cout<<"\tYou are on Modules section\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";


                    cout <<"Enter the first number: ";
                    cin >>num1;

                    cout <<"Enter the second number: ";
                    cin >>num2;

                //modResult is holding the number returned by the computeMod(num1,num2)
                    modResult = computeMod(num1,num2);//function call
                //if the number return by the function 0 then there is no reminder
                    if(modResult == 0){
                        cout <<"\nThere is no reminder\n\n";

                         //change to true if the user went through this operation
                        modWorking = true;
                    }
                    else{

                        cout <<"\nThe reminder of "<<num1 <<" % " <<num2<<" = "<<modResult<<endl<<endl;
                         //change to true if the user went through this operation
                        modWorking = true;
                    }

                break;
            case 'K': case 'k':
                isWorking(addWorking,subWorking,mulWorking,divWorking,rootWorking,powerWorking,percWorking,lcmWorking,gcdWorking,modWorking);

                break;
                       case 'Q': case 'q':
                //function message after the user exit the program
                userExit();
                exit(0);
                break;

             default:
                cout <<"Unkow Letter pleae try again"<<endl;
        }

        //if the user choose Q then it will quit from the application
    }while(choose != 'Q' || choose != 'Q');




       return 0;
}
void menu(void){

    //display the menue and let the user choose one
    cout<<"\n\n\t\t--------------------------------------------------"<<endl;
    cout <<"\t\t\tA.) Addition"<<endl;
    cout <<"\t\t\tB.) Subtraction"<<endl;
    cout <<"\t\t\tC.) Multiplication"<<endl;
    cout <<"\t\t\tD.) Division"<<endl;
    cout <<"\t\t\tE.) Roots (only positive number)"<<endl;
    cout <<"\t\t\tF.) Power (only positive number)"<<endl;
    cout <<"\t\t\tG.) Percentage"<<endl;
    cout <<"\t\t\tH.) Least Common Multiplier"<<endl;
    cout <<"\t\t\tI.) Greatest Common Divisor"<<endl;
    cout <<"\t\t\tJ.) Modulus"<<endl;
    cout <<"\t\t\tK.) Display functions execution*"<<endl;
    cout <<"\t\t\tQ.) Quit"<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;

}


void welcomeScreen(void){

    /*
     Last time function modification  by Hisham on 03/10/17.

     */

    //This is the mune where the user choose the operation
    cout<<"\n\n-----------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\tWELCOME TO THE CALCULATOR PROJECT"<<endl;
    cout<<"-----------------------------------------------------------------------------\n"<<endl;


}



float computeSum(float num1,  float num2)
{
    /*
     Last time function modification  by Hisham on 03/05/17.

     */

    float sum;

    //calculate the passing value by the user
    sum = num1 + num2;
    //return the answer
    return sum;
}

float computeSub (float num1,  float num2){

    /*
     Last time function modification  by Hisham on 03/05/17.

     */

    float sum;

    //calculate the passing value by the user
    sum = num1 - num2;
    //return the answer
    return sum;
}

float computeMul(float num1,  float num2){

    /*
     Last time function modification  by Hisham on 03/05/17.

     */

    float total;

    //calculate the passing value by the user
       total = num1 * num2;
    //return the answer
    return total;

}

float computeDiv(float num1,  float num2){

    /*
     Last time function modification  by Hisham on 03/05/17.

     */

    float total;
    //calculate the passing value by the user
    total = num1 / num2;
    //return the answer
    return total;

}
float computeRoot(float root, int index)
{

    /*
     Last time function modification  by Hisham on 03/13/17.

     */

    float tp, mid;
    float low = 0;
    float high = root;

    //loops keep repeating if the condition is wrong
    do
    {
        //assign mid to high that we get from the user and add them then divide it
        mid = (low + high) / 2;

        //then we going to use our pervious function to compute power to fin the power of the number and if the root is less then  computePower answer then it will go to the else statement
        if (computePower(mid, index) > root)
        {
            high = mid;  //assign high to mid
        }
        else
        {
            low = mid;  ; //assign low to mid
        }

        //assign mid to high that we get from the user and add them then divide it
            mid = (low + high) / 2;
            tp = (computePower(mid, index) - root);

        if (tp < 0)
        {//grab absolute value
            tp = tp * (-1.0);
        }
    } while (tp > .000005);//accuracy of our root

    return mid;
}




float computePower(float num1, int num2)
{
    /*
     Last time function modification  by Hisham on 03/05/17.

     */

    float numProduct = 1;
    int i;

    //keeps loop on the number the user passed to the function
        for (i = 0; i < num2; i++)
        {
            //multiply the numProduct by num1 to gave the the power root
        numProduct = numProduct * num1;
        }
    //return the answer
    return numProduct;
}

float computePerc(float num1,  float perc){

    /*
     Last time function modification  by Hisham on 03/05/17.

     */


    //multiply the num1 by  converted to percentage to the number he/she enter for the perc and divide it by 100 to get the percentage of the number we mulitply
    perc = (num1 * perc) /100;


    //return the answer to the function
    return perc;
}


int computeGCD(int num1, int num2)
{

    /*
     Last time function modification  by Hisham on 03/05/17.

     */


   //it will keep loop if num1 == num2
    while (num1 != num2)
    {
        //if num1 > num2 then ti will do the calculation
        if (num1 > num2)
        {
            num1 = num1 - num2;
        }
        else
        {
            //if num2 > num1 then it will do the calculation
            num2 = num2 - num1;
        }
    }

    //return the answer to the function
    return num1;
    }


int computeLCM(int num1, int num2)
{
    /*
     Last time function modification  by Hisham on 03/05/17.

     */


    int tmp_lcm;


    /*
        first do the Multiplication of the numberd entered by the user then, use the pervious function called computeGCD to pass the num1 and num2 and do the calculation because without GCD we cant find the LCM and divide the number you multiply by the number returned by the computeGCD
     */
    tmp_lcm = ((num1 * num2) / computeGCD(num1, num2));

    //return the answer to the function
    return tmp_lcm;
}

int   computeMod(int num1,  int num2){

    /*
     Last time function modification  by Hisham on 03/05/17.

     */


    float result;

    //it computeMod of two numbers  if mode number is dividable and wont return any reminder it will return 0 to the function else it will return the result
    if(num1 % num2 == 0){

        return 0;
    }
    else{
        result = num1 % num2;
    }



    return result;
}
void isWorking(bool addWorking,bool subWorking,bool multWorking,bool divWorking,bool rootWorking,bool powerWorking,bool percWorking,bool lcmWorking,bool gcdWorking, bool modeWorking){

    /*
     Last time function modification  by Hisham on 03/06/17.

     */


    //This function handles whether the the program execute the operation or not because if it does it will write execution success if not it will say execution failure

    cout<<"\n\n-----------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\tDISPLAYING FUNCTION EXECUTION";
    cout<<"\n-----------------------------------------------------------------------------\n"<<endl;
        cout<<"\n\n\t\tOperation Name            Execuation\n";
		cout<<"\t\t--------------		 -------------------\n";

    //compare the function that was sent when the user went through the operation because the value will change from false to true if the operation is successfully if not then it wont change. This will have happened to all of them and also if statement will be individual for each operation for example addition will have its if and else if statement and when we go to the subtracting, it will have its own if else statement.

    if (addWorking == true){

        cout<<"\t\tAddition             - Execution Success\n";

    }else{

        cout<<"\t\tAddition             - Execution Failure\n";

    }



    if (subWorking == true){

        cout<<"\t\tSubtraction          - Execution Success\n";

    }else{

        cout<<"\t\tSubtraction          - Execution Failure\n";

    }

    if (multWorking == true){

        cout<<"\t\tMultiplication       - Execution Success\n";

    }else{

        cout<<"\t\tMultiplication       - Execution Failure\n";

    }

    if (divWorking == true){

        cout<<"\t\tDivision             - Execution Success\n";

    }else{

        cout<<"\t\tDivision             - Execution Failure\n";

    }

    if (rootWorking == true){

        cout<<"\t\tRoots                - Execution Success\n";

    }else{

        cout<<"\t\tRoots                - Execution Failure\n";

    }

    if (powerWorking == true){

        cout<<"\t\tPower                - Execution Success\n";

    }else{

        cout<<"\t\tPower                - Execution Failure\n";

    }

    if (percWorking == true){

        cout<<"\t\tPercentage           - Execution Success\n";

    }else{

        cout<<"\t\tPercentage           - Execution Failure\n";

    }

    if (lcmWorking == true){

        cout<<"\t\tLCM                  - Execution Success\n";

    }else{

        cout<<"\t\tLCM                  - Execution Failure\n";

    }

    if (gcdWorking == true){

        cout<<"\t\tGCD                  - Execution Success\n";

    }else{

        cout<<"\t\tGCD                  - Execution Failure\n";

    }
    if (modeWorking == true){

        cout<<"\t\tGCD                  - Execution Success\n";

    }else{

        cout<<"\t\tModulus              - Execution Failure\n";

    }

}
void userExit(void){

    /*
     Last time function modification  by Hisham on 03/10/17.

     */


    //This is the mune where the user choose the operation
    cout<<"\n\n-----------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t    THANK YOU FOR USING CALCULATOR PROJECT                        "<<endl;
    cout<<"-----------------------------------------------------------------------------\n"<<endl;

}
