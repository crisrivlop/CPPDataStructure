#include "IIterator.h"
#include "DoubleNode.h"
#include <ostream>
#ifndef INVERSEITERATOR_H
#define INVERSEITERATOR_H
template <class E>
class InverseIterator:public IIterator<E>{

    template <class T> friend class DoubleList;

    DoubleNode<E> *head,*tail,*current;
protected:
    InverseIterator(DoubleNode<E>*,DoubleNode<E>*);
public:
    E getNext();
    bool hasNext() const;
    E getCurrent() const;
};

template <class E> InverseIterator<E>::InverseIterator(DoubleNode<E> *head,DoubleNode<E>*tail){
    this->head = head;
    this->tail = tail;
    current = tail;
}

template <class E> E InverseIterator<E>::getNext(){
    if (!current){
        throw current;
        std::cerr << "dont have next!" << std::endl;
    }
    E data = current->getData();
    current = current->getPrevious();
    return data;
}

template <class E> E InverseIterator<E>::getCurrent() const{
    if (!current){
        throw current;
        std::cerr <<"dont have next!"<< std::endl;
    }
    return current->getData();
}

template <class E> bool InverseIterator<E>::hasNext() const{
    if (!current){
        throw current;
        std::cerr << "dont have next!"<< std::endl;
    }
    return current->getPrevious();
}


#endif // INVERSEITERATOR_H
