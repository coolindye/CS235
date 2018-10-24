/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    <your names here>
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  1.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
//#include <set>
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish() {

	cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";

	custom::set <Card> cards;
	int matches = 0;
	Card guess;

	char word[32];
	ifstream myfile("/home/cs235/week05/hand.txt");
	if (myfile.is_open())
	{
		while (myfile >> word)
		{
			guess = word;
			cards.insert(guess);
		}
		myfile.close();
	}

	for (int i = 1; i <= 5; i++) {
		cout << "round " << i << ": ";
		cin >> guess;
		//can change to findIndex with a little work I think
		if(cards.find(guess) != cards.end()) {
			matches++;
			cout << "\tYou got a match!" << endl;
			cards.erase(cards.find(guess));
		}
		else
			cout << "\tGo Fish!" << endl;
	}

	cout << "You have " << matches << " matches!" << endl
		 << "The remaining cards: "; 
	custom::set <Card> ::iterator it = cards.begin();
	 for (int i = 0; i < cards.size() ; ++i)
	 {
		 if (it == cards.begin())
		 {
			 cout << *it;
			 ++it;
			 continue;
		 }
		cout << ", " << *it;
		++it;
     }
	 cout << endl;
		
}
