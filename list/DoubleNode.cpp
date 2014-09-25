#include "iostream"
#include "list/DoubleNode.h"


template <class E> E DoubleNode<E>::getData(){
    return data;
}

template <class E> void DoubleNode<E>::setData(E data){
    this->data = data;
}

template <class E> DoubleNode<E>* DoubleNode<E>::getNext(){
    return next;
}

template <class E> void DoubleNode<E>::setNext(DoubleNode *next){
    this->next = next;
}

template <class E> DoubleNode<E>* DoubleNode<E>::getPrevious(){
    return previous;
}

template <class E> void DoubleNode<E>::setPrevious(DoubleNode *previous){
    this->previous = previous;
}

template <class E> void DoubleNode<E>::print(){
    std::cout << data;
}

template <class E> DoubleNode<E>::~DoubleNode(){
    std::cout << "double node deleted \n";
}
