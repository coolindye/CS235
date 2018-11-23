/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    Garrett
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
	map <string, int> wordFreqMap;
	string filename, word;

	cout << "What is the filename to be counted? ";
	cin >> filename;

	ifstream myfile(filename);
	if (myfile.is_open())
	{
		while (myfile >> word)
		{
			wordFreqMap[word] += 1;
		}
		myfile.close();
	}

	cout << "What word whose frequency is to be found. Type ! when done\n";
	cout << "> ";
	cin >> word;
	while (word != "!")
	{
		cout << "\t"
			<< word
			<< " : "
			<< wordFreqMap[word]
			<< "\n";
		cout << "> ";
		cin >> word;
	}
}
