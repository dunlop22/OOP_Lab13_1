#pragma once
#include "Element_My.h"
#include "Iterator_My.h"

template <class T>
class Agregat_My
{
public:
    typedef Element_My<T> node;
    typedef Iterator_My <node, T> myIter;
private:
    node* root;
public:
    Agregat_My() 
    { 
        root = 0; 
    }
    ~Agregat_My() 
    {
        if (root)
        {
            delete root;
        }
    }
    myIter begin() 
    {
        return myIter(root); 
    }
    myIter end() 
    {
        return  myIter(0); 
    }
    void push(T const& t) {
        if (root)
        {
            root->push(t);
        }
        else 
        {
            root = new node(t); 
        }
    }
};
