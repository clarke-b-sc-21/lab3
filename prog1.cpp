#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



/*
Author: Logan Clarke
Lab Assignment 3
Purpose: The purpose of this porgram is to simulate craps. 
	 It simply asks the user to enter 'r' to roll the 
	 dice then generates random numbers to simulate the
	 dice being rolled. The rules of the program mirror
	 the rules for craps
*/



//returns a random number between 1&6

int die (void){
return rand() % 6+1;
}



//Plays craps

int playGame (void) {

	char a;
	int x1, x2,sum,point;
	bool start = false;
	bool playing = true;
	cout <<endl<< "Craps Simulator " <<endl;



								//receives first input from user, 
								//handles unexpected input

	while ( start == false){

		cout << "Press 'r' then 'enter' to roll the dice ..  ";
		cin >> a;

		if ( a == 'R' || a=='r' ){
		start = true;
		}

		else {
		cout << "The value entered is not valid";
		}


	}




									//once out of the while loop
									// we start to play

	x1 = die();
	x2 = die();
	sum = x1+x2;


	cout << "You Rolled: " << x1 << " + " << x2<< " = " <<sum <<endl;

	if( sum == 7 || sum == 11 ){                                    //player either wins
	cout << "Player wins";
	}

	else if ( sum == 2 || sum  == 3 || sum  == 12 ){
	cout << "Player Loses ";                                       //or loses
	}

	else {
		cout << "The point is now: " << (x1+x2)<<endl<<endl;  //or we get the point to 
		point = (x1+x2);			              //continue the game



							// we are still in the last else statement,
							// the following while loop gets the 
         						//initial input and handles unexpected input
		while (playing == true){



			start = false;
			while ( start == false){

				cout << "Press 'r' then 'enter' to roll the dice! ..   ";
				cin >> a;

				if ( a == 'R' || a == 'r' ){
				start = true;
				}

				else {
				cout<< "The value entered is not valid" <<endl;
				}

				}

									//once out of the while loop
									// we start to play
			x1 = die();
			x2 = die();
			sum = (x1 + x2);
			cout <<endl << "You Rolled: " << x1 << " + " << x2 << " = " << sum<<endl ;

			if( sum == point) {
				cout << "Player wins " ;       		// player wins, we get out
									// of the while loop
				playing = false;
				}
			else if ( sum == 7 ){
				cout << "Player loses " ;       	//player loses, we finish
				playing = false;
				}

		} 					//or we keep playing and go back to the
							//top of the while loop

	}


}                                  
                                     




int main( ) {
  char ans;
  bool done = false;
  srand (time(NULL));
  while ( ! done ) {
         playGame();   // YOU MUST WRITE THIS FUNCTION
         cout << " Play again (y/n) ? ";
         cin >> ans;
         if ( ans == 'n' || ans == 'N') done = true;
             else done = false;
  }
  return 0;
}









