#include "iostream"
#include "list/Node.h"



template <class E> E Node<E>::getData(){return data;}

template <class E> void Node<E>::setData(E data){
    this->data = data;
}

template <class E> Node<E>* Node<E>::getNext(){
    return this->next;
}

template <class E> void Node<E>::setNext(Node *next){
    this->next = next;
}

template <class E> void Node<E>::print(){
    std::cout << data;
}

template <class E> Node<E>::~Node(){
    std::cout << "node deleted \n";
}
