/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "bnode.h"         // for BINARY_NODE class definition
#include "vector.h"        // for VECTOR container
#include "pair.h"          // for PAIR container
#include "huffman.h"       // for HUFFMAN() prototype


using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;
using namespace std;
using namespace custom;

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const string & fileName)
{
	//BNode *root = NULL;
	string word;
	float freq;
    vector <custom::pair <float, string>> pairs;
    ifstream myfile(fileName);

    if (myfile.fail())
    {
        cout << "Error reading file \"" << fileName << "\"\n";
        return;
    }

	if (myfile.is_open())
	{
		while (myfile >> word)
		{
			myfile >> freq;
			pairs.push_back(custom::pair<float, string>(freq, word));
		}
		myfile.close();
	}

    //for (vector<BNode*>::iterator it = pairs.begin(); it != pairs.end(); it++) {
    	
    //}


   return;
}
