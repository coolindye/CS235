/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <cassert>
#include <cctype>
#include "spellCheck.h"
#include "hash.h"
#include "list.h"

using namespace std;

//const string dictionary = "/home/cs235/week12/dictionary.txt";
const string dictionary = "dictionary.txt"; //comment this out after testing

class sHash : public Hash <string>
{
public:
    sHash(int numBuckets)    throw (const char *) : Hash <string>(numBuckets) {}
    sHash(const sHash & rhs) throw (const char *) : Hash <string>(rhs) {}

    // hash function for integers is simply to take the modulous
    int hash(const string & value) const
    {
        int index = 0;
        for (int i = 0; i < value.length(); i++)
        {
            index = index + static_cast<int>(value[i]);
        }
        index = index % 100; //size is 10 for now just to test
        return index;
    }
};


void readDictionary(string dictionary, sHash spell)
{
    ifstream fin(dictionary.c_str());
    if (fin.fail())
    {
        cout << "Error reading file \"" << dictionary << "\"\n";
        return;
    }

    string word;

    while (!fin.eof())
    {
        fin >> word;
        spell.insert(word);
    }
    fin.close();
}


/**********************************************************************
* Standard open file and insert into a hash
***********************************************************************/
void readFile(string filename, sHash spell, list <string> wrong)
{
    ifstream fin(filename.c_str());
    if (fin.fail())
    {
        cout << "Error reading file \"" << filename << "\"\n";
        return;
    }


    string word;
    string temp;
    while (!fin.eof())
    {
        fin >> word;
        int index;
        temp = word;
        basic_string<char>::iterator p;
        for (p = temp.begin(); p != temp.end(); ++p) {

            *p = tolower(*p);
        }
        if (spell.find(temp) == false)
        {
            wrong.push_back(word);
        }
    }

    if (wrong.empty())
    {
        cout << "File contains no spelling errors\n";
    }
    else
    {
        cout << "Misspelled: ";

        for (list<string>::const_iterator it = wrong.begin(); it != wrong.end();)
        {
            cout << *it;
            if (++it != wrong.end())
                cout << ", ";
        }
        cout << endl;
    }

    fin.close();
}

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
    string filename;
    sHash spell(100);
    list <string> wrong;
    cout << "What file do you want to check? ";
    cin >> filename;
    readDictionary(dictionary, spell);
    readFile(filename, spell, wrong);
}






