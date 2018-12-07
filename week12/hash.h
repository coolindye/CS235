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
    Hash & operator = (const Hash & rhs);
    virtual ~Hash() {  }
    
    int  size()     const { return numElements; }
    int  capacity() const { return numBuckets; }
    bool empty()    const { return numElements == 0; }

    bool find(const T & t) throw (const char *);
    void insert(const T & t) throw (const char *);

    virtual int hash(const T & t) const = 0;

};

template<class T>
inline Hash<T>::Hash(int numBuckets) throw(const char *)
{
    this->numBuckets = numBuckets;
    this->numElements = 0;
    this->table = new T[numBuckets];
}

template<class T>
inline Hash<T>::Hash(const Hash & rhs) throw(const char *)
{
    this->table = rhs.table;
    this->numElements = rhs.numElements;
    this->numBuckets = rhs.numBuckets;
}

template<class T>
Hash<T> & Hash<T>::operator=(const Hash & rhs)
{
    table = rhs.table;
    numElements = rhs.numElements;
    numBuckets = rhs.numBuckets;
    return *this;
}

template<class T>
inline bool Hash<T>::find(const T & t) throw(const char *)
{
    return false;
}

template<class T>
inline void Hash<T>::insert(const T & t) throw(const char *)
{
    numElements++;
    int index = hash(t);

    //if (table[index] == 0) {
    //    table[index] = new std::vector <T> 
    //}

}

#endif // HASH_H
