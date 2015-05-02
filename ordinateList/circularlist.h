#include "simplelistadapter.h"
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

template <class E>
class CircularList:public SimpleListAdapter<E>
{
protected:
    bool addi(E pData);
    bool addf(E pData);
    bool addFirstData(E pData);
    bool removei();
    bool removef();
public:
    CircularList();
};


template <class E> CircularList<E>::CircularList(){
    this->_lenght = 0;
    this->_head = this->_tail = Null;
}


template <class E> bool CircularList<E>::addi(E pData){
    Node<E> *insertionData = new Node<E>(pData, this->_head);
    this->_head = insertionData;
    this->_tail->setNext(this->_head);
    this->_lenght++;
    return true;
}

template <class E> bool CircularList<E>::addf(E pData){
    Node<E> *insertionData = new Node<E>(pData,this->_head);
    this->_tail->setNext(insertionData);
    this->_tail = insertionData;
    this->_lenght++;
    return true;
}

template <class E> bool CircularList<E>::addFirstData(E pData){
    this->_head = this->_tail = new Node<E>(pData);
    this->_head->setNext(this->_head);
    this->_lenght++;
    return true;
}

template <class E> bool CircularList<E>::removei(){
    Node<E> *toDelete = this->_head;
    if (this->_lenght == 1){
        this->_tail = this->_head = Null;
    }
    else{
        this->_head = this->_head->getNext();
        this->_tail->setNext(this->_head);
    }
    delete toDelete;
    this->_lenght--;
    return true;
}

template <class E> bool CircularList<E>::removef(){
    Node<E> *currentNode = this->_head;
    for (int x = 0;x < this->_lenght-1;x++)currentNode = currentNode->getNext();
    Node<E> *toDelete = currentNode->getNext();
    currentNode->setNext(this->_head);
    this->_tail = currentNode;
    this->_lenght--;
    delete toDelete;
    return true;
}


#endif // CIRCULARLIST_H
