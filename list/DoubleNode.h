#include "iostream"
#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <class E>
class DoubleNode
{
    E data;
    DoubleNode<E> *next;
    DoubleNode<E> *previous;
public:
    DoubleNode(E data)
    {
        this->data = data;
        next = 0;
        previous = 0;
    }

    DoubleNode(E data, DoubleNode<E> *previous, DoubleNode<E> *next){
        this->data = data;
        this->next = next;
        this->previous = previous;
    }

    void setData(E data){this->data = data;}

    E getData(){return data;}

    void setNext(DoubleNode *next){this->next = next;}

    DoubleNode* getNext(){return next;}
    void setPrevious(DoubleNode *previous){this->previous = previous;}
    DoubleNode* getPrevious(){return previous;}
    void print(){std::cout << data;}
    ~DoubleNode(){std::cout << "double node deleted \n";}

};

#endif // DOUBLENODE_H
