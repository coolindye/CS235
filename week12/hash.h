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


template<class T>
class Hash
{
private:
    T * table;
    int numElements; 
    int numBuckets;

public:
    Hash(const int numBuckets) {}
    Hash(const Hash &rhs);
    ~Hash();

    Hash & operator = (const Hash rhs);
    int size();
    int capacity() const;
    bool empty();
    bool find(T t);

    void insert(T t);

    virtual int hash(const T & t) = 0;

};


#endif // HASH_H

