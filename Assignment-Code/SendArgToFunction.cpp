
/*
 main.cpp
 Question 2_CIS 150 – Lab 06

 Created by Hisham on 3/11/17.
 Copyright © 2017 Hisham Hussein. All rights reserved.
 Purpose: Ask the user for two players name with their score and send it to function to determine who is the winner and how is the loser and if the games is a tie
 */


#include <iostream>
using namespace std;

//function prototype
void winner(int, int,string,string);



int main(int argc, const char * argv[]) {

    //variables to hold values
    string playerName1,playerName2;
    int scorePlayer1,scorePlayer2;

    //ask  player one  for the number name and score they get
    cout <<"\nPlayer one name :";
    cin>>playerName1;
    cout <<"Enter your score: ";
    cin>>scorePlayer1;

    //ask  player two  for the number name and score they get
    cout <<"\n\nPlayer two name :";
    cin>>playerName2;
    cout <<"Enter your score: ";
    cin>>scorePlayer2;

    //send the values to the function
    winner(scorePlayer1,scorePlayer2,playerName1,playerName2);

    system("pause");
    return  0;
}

void winner(int playerScore1,int playerScore2,string namePlayer1,string namePlayer2){

    //compare the score between user one and user two if player1 greater score then player two then player one is the winner
    if (playerScore1 > playerScore2){

        //display the result
        cout<<endl<<namePlayer1<<" is the winner of score "<<playerScore1<<endl;
    }
    //if player to has greate socre then player one the player two is the winner
    else if (playerScore2 > playerScore1){

        //display the result
        cout<<endl<<namePlayer2<<" is the winner of score "<<playerScore2<<endl;
        //if player one socre == to player two then they are tie
    }else{
        //show the result
        cout<<"\nThe score is tie"<<endl;

    }

}

