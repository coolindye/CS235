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

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const string & fileName)
{
    vector <BNode <custom::pair <std::string, float> > *> pair;
    ifstream fin(fileName);

    if (fin.fail())
    {
        cout << "Error reading file \"" << fileName << "\"\n";
        return;
    }

    string letter;
    float number;

    while (fin >> letter >> number)
    {
        custom::pair <std::string, float> current(letter, number);
        BNode <custom::pair <std::string, float> > * tempNode;
        tempNode = new BNode <custom::pair<std::string, float> > (current);
        pair.push_back(tempNode);
    }


   return;
}
