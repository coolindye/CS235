/***********************************************************************
 * Component:
 *    Assignment 12, Hash Function
 *    Brother Kirby, CS 235
 * Author:
 *    Garrett/Aiden/Ian
 * Summary:
 *    
 ************************************************************************/

#ifndef HASH_H
#define HASH_H

#include <iostream>

template<class T>
class Hash
{
private:
    T * table;
    int numElements; 
    int numBuckets;

public:
    Hash(int numBuckets) throw (const char *);
    Hash(const Hash &rhs) throw (const char *);
    ~Hash();

    Hash & operator = (const Hash rhs);
    int size();
    int capacity() const;
    bool empty();
    bool find(T t);

    void insert(T t);

    int virtual hash(const T & t) = 0;

};


#endif // HASH_H

