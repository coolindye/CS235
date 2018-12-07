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
    ~Hash() { delete[] table; }

    Hash & operator = (const Hash & rhs);
    int size();
    int capacity() const;
    bool empty();
    bool find(T t);

    void insert(const T & t) throw (const char *);

    virtual int hash(const T & t) = 0;

};


#endif // HASH_H

template<class T>
Hash<T>::Hash(int numBuckets) throw(const char *)
{
    this->numBuckets = numBuckets;
}

template<class T>
Hash<T>::Hash(const Hash & rhs) throw(const char *)
{
}

template<class T>
Hash<T> & Hash<T>::operator=(const Hash & rhs)
{
    // TODO: insert return statement here
}
