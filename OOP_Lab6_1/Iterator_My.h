#pragma once
template <class node, class T>
class Iterator_My
{
private:
    node* node_ptr;

public:
    Iterator_My(node* n) 
    {
        node_ptr = n; 
    }
    T* next() { 
        return node_ptr->get(); 
    }
    void  operator ++ () 
    {
        node_ptr = node_ptr->next(); 
    }
    Iterator_My operator ++ (int) 
    {
        Iterator_My iter(*this);        ++(*this);
        return iter;
    }
    bool operator == (Iterator_My const& i) 
    {
        return node_ptr == i.node_ptr;
    }
    bool operator != (Iterator_My const& i) 
    {
        return !(*this == i); 
    }
};