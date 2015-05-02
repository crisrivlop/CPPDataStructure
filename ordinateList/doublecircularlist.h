#include "doublelistadapter.h"
#ifndef DOUBLECIRCULARLIST_H
#define DOUBLECIRCULARLIST_H

template<class E>
class DoubleCircularList:public DoubleListAdapter<E>
{
protected:
    bool addi(E pData);
    bool addf(E pData);
    bool addFirstData(E pData);
    bool removei();
    bool removef();
public:
    DoubleCircularList();
};

template <class E> DoubleCircularList<E>::DoubleCircularList(){
    this->_lenght = 0;
    this->_head = this->_tail = Null;
}



template <class E> bool DoubleCircularList<E>::addi(E pData){
    DoubleNode<E> *insertionData = new DoubleNode<E>(pData,this->_tail, this->_head);
    this->_head->setPrevious(insertionData);
    this->_head = insertionData;
    this->_tail->setNext(this->_head);
    this->_lenght++;
    return true;
}

template <class E> bool DoubleCircularList<E>::addf(E pData){
    DoubleNode<E> *insertionData = new DoubleNode<E>(pData, this->_tail, this->_head);
    this->_tail->setNext(insertionData);
    this->_tail = insertionData;
    this->_head->setPrevious(this->_tail);
    this->_lenght++;
    return true;
}

template <class E> bool DoubleCircularList<E>::addFirstData(E pData){
    this->_head = this->_tail = new DoubleNode<E>(pData);
    this->_head->setNext(this->_head);
    this->_head->setPrevious(this->_head);
    this->_lenght++;
    return true;
}

template <class E> bool DoubleCircularList<E>::removei(){
    DoubleNode<E> *toDelete = this->_head;
    this->_head = toDelete->getNext();
    if (this->_head){
        this->_head->setPrevious(this->_tail);
        this->_tail->setNext(this->_head);
    }
    else{
        this->_head = this->_tail = Null;
    }
    delete toDelete;
    this->_lenght--;
    return true;
}

template <class E> bool DoubleCircularList<E>::removef(){
    DoubleNode<E> *toDelete = this->_tail;
    this->_tail = toDelete->getPrevious();
    this->_tail->setNext(this->_head);
    this->_head->setPrevious(this->_tail);
    this->_lenght--;
    delete toDelete;
    return true;
}
#endif // DOUBLECIRCULARLIST_H
