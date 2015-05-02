#include "doublelistadapter.h"
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

template <class E>
class DoubleList:public DoubleListAdapter<E>
{
protected:
    bool addi(E pData);
    bool addf(E pData);
    bool addFirstData(E pData);
    bool removei();
    bool removef();
public:
    DoubleList();
};

template <class E> DoubleList<E>::DoubleList(){
    this->_lenght = 0;
    this->_head = this->_tail = Null;
}



template <class E> bool DoubleList<E>::addi(E pData){
    DoubleNode<E> *insertionData = new DoubleNode<E>(pData);
    insertionData->setNext(this->_head);
    this->_head->setPrevious(insertionData);
    this->_head = insertionData;
    this->_lenght++;
    return true;
}

template <class E> bool DoubleList<E>::addf(E pData){
    DoubleNode<E> *insertionData = new DoubleNode<E>(pData, this->_tail, Null);
    this->_tail->setNext(insertionData);
    this->_tail = insertionData;
    this->_lenght++;
    return true;
}

template <class E> bool DoubleList<E>::addFirstData(E pData){
    this->_head = this->_tail = new DoubleNode<E>(pData);
    this->_lenght++;
    return true;
}

template <class E> bool DoubleList<E>::removei(){
    DoubleNode<E> *toDelete = this->_head;
    this->_head = toDelete->getNext();
    if (toDelete->getNext())this->_head->setPrevious(Null);
    else this->_head = this->_tail = Null;
    delete toDelete;
    this->_lenght--;
    return true;
}

template <class E> bool DoubleList<E>::removef(){
    DoubleNode<E> *toDelete = this->_tail;
    this->_tail = toDelete->getPrevious();
    this->_tail->setNext(Null);
    this->_lenght--;
    delete toDelete;
    return true;
}


#endif // DOUBLELIST_H
