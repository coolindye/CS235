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

vector<int> blacklist;
vector<int> order;

bool notBlacklisted(int index) {
	for (int i = 0; i < blacklist.size(); i++) {
		if (index == blacklist[i])
			return false;
	}
	return true;
}

int getLowest(vector<custom::pair<float, string>> pairs) {
    int index = 0;
    int i;
    for (i = 0; i < pairs.size(); i++) {
        if ((pairs[i].getFirst() < pairs[index].getFirst()) && notBlacklisted(i))
        {
            index = i;
        }
        if (blacklist.size()+1 == pairs.size()) 
        {
        	index = i;
        }

    }

    if (notBlacklisted(index))
    	blacklist.push_back(index);
    return index;
}

double sumOfNode(BNode<custom::pair<float, string>> *node) 
{
	double sum = 0;
	if (node->pLeft != NULL) 
	{
		cout << "left";
		sum += sumOfNode(node->pLeft);
	}
	if (node->pRight != NULL) 
	{
		cout << "right";
		sum += sumOfNode(node->pRight);
	}
	//cout << node->data.getFirst();
	return node->data.getFirst();
}

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const string & fileName)
{
	//BNode<custom::pair<float, string>> *root = NULL;
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

	for (int i = 0; i < pairs.size(); i++) {
		int nextLowest = getLowest(pairs);
		order.push_back(nextLowest);
	}

	for (int i = 0; i < order.size(); i++) {
		//cout << order[i] << " " << pairs[order[i]].getFirst() << " " << pairs[order[i]].getSecond() << endl;
	}

	BNode<custom::pair<float, string>> *tempOne = new BNode<custom::pair<float, string>>(pairs[order[0]]);
	BNode<custom::pair<float, string>> *tempTwo = new BNode<custom::pair<float, string>>(pairs[order[0]]);
	BNode<custom::pair<float, string>> *tempParent;
	addRight(tempParent, tempOne);
	//tempParent->pRight = tempTwo;

	cout << sumOfNode(tempOne) << " sum of node " << endl;




   return;
}
