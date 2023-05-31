#pragma once
template <class T>
class Element_My
{
private:
    T object;
    Element_My* next_node;
public:
    Element_My(T const& t)
    {
        object = t; 
        next_node = 0; 
    }
    ~Element_My() 
    { 
        if (next_node)
        {
            delete next_node;
        }
    }
    Element_My* next()
    { 
        return next_node; 
    }
    T* get() 
    { 
        return &object; 
    }
    void push(T const& t)
    {
        cout << "Element_My push: " << t << endl;
        if (next_node)
        {
            next_node->push(t);
        }
        else
        {
            next_node = new Element_My(t);
        }
    }
};
