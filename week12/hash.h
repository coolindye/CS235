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
    virtual ~Hash() { delete[] table; }

    Hash & operator = (const Hash & rhs);
    int size() const { return numElements; }
    int capacity() const { return numBuckets; }
    bool empty() const { return this->numElements == 0;  }
    bool find(const T & t) throw (const char *);

    void insert(const T & t) throw (const char *);

    virtual int hash(const T & t) const = 0;

};


#endif // HASH_H

template<class T>
inline Hash<T>::Hash(int numBuckets) throw(const char *)
{
    this->numBuckets = numBuckets;
}

template<class T>
inline Hash<T>::Hash(const Hash & rhs) throw(const char *)
{
}

template<class T>
Hash<T> & Hash<T>::operator=(const Hash & rhs)
{
    // TODO: insert return statement here
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
}
