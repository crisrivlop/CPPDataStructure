#include "IIterator.h"
#include "DoubleNode.h"
#include <list>
#include <ostream>
#ifndef DOUBLELISTITERATOR_H
#define DOUBLELISTITERATOR_H

template <class E>
class DoubleIterator:public IIterator<E>{
    template <class T> friend class DoubleList;

    DoubleNode<E> *head,*tail,*current;
protected:
    DoubleIterator(DoubleNode<E>*,DoubleNode<E>*);
public:
    /**
     * @brief
     *
     * @return E
     */
    E getNext();

    /**
     * @brief
     *
     * @return E
     */
    E getCurrent() const;

    /**
     * @brief
     *
     * @return bool
     */
    bool hasNext() const;
};
template <class E>
DoubleIterator<E>::DoubleIterator(DoubleNode<E> *head, DoubleNode<E> *tail){
    this->head = head;
    this->tail = tail;
    this->current = head;
}
template <class E>
bool DoubleIterator<E>::hasNext()const{
    if (!current){
        throw current;
        std::cerr << "dont have next!" << std::endl;
    }
    return current->getNext();
}
template <class E>
E DoubleIterator<E>::getCurrent()const{
    if (!current){
        throw current;
        std::cerr << "dont have next!" << std::endl;
    }
    return current->getData();
}
template <class E>
E DoubleIterator<E>::getNext(){
    if (!current){
        throw current;
        std::cerr << "dont have next!" << std::endl;
    }
    E data = current->getData();
    current = current->getNext();
    return data;
}

#endif // DOUBLELISTITERATOR_H
