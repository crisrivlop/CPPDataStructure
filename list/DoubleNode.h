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
    DoubleNode(E);
    DoubleNode(E, DoubleNode<E>*, DoubleNode<E>*);
    void setData(E);
    E getData() const;
    void setNext(DoubleNode<E>*);
    DoubleNode<E>* getNext()const;
    void setPrevious(DoubleNode<E>*);
    DoubleNode<E>* getPrevious()const;
    void print() const;
    ~DoubleNode();

};

template <class E> DoubleNode<E>::DoubleNode(E data){
    this->data = data;
    next = 0;
    previous = 0;
}


template <class E> DoubleNode<E>::DoubleNode(E data, DoubleNode<E> *previous, DoubleNode<E> *next){
    this->data = data;
    this->next = next;
    this->previous = previous;
}

template <class E> void DoubleNode<E>::setData(E data){this->data = data;}

template <class E> E DoubleNode<E>::getData()const{return data;}

template <class E> void DoubleNode<E>::setNext(DoubleNode *next){this->next = next;}

template <class E> DoubleNode<E>* DoubleNode<E>::getNext()const{return next;}

template <class E> void DoubleNode<E>::setPrevious(DoubleNode *previous){this->previous = previous;}

template <class E> DoubleNode<E>* DoubleNode<E>::getPrevious()const{return previous;}

template <class E> void DoubleNode<E>::print() const {std::cout << data;}

template <class E> DoubleNode<E>::~DoubleNode(){}

#endif // DOUBLENODE_H
