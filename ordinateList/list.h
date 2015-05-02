#include "simplelistadapter.h"
#ifndef LIST_H
#define LIST_H

template <class E>
class List:public SimpleListAdapter<E>
{
protected:
    bool addi(E pData);
    bool addf(E pData);
    bool addFirstData(E pData);
    bool removei();
    bool removef();
public:
    List();
};

template <class E> List<E>::List(){
    this->_lenght = 0;
    this->_head = this->_tail = Null;
}



template <class E> bool List<E>::addi(E pData){
    Node<E> *insertionData = new Node<E>(pData, this->_head);
    this->_head = insertionData;
    this->_lenght++;
    return true;
}

template <class E> bool List<E>::addf(E pData){
    Node<E> *insertionData = new Node<E>(pData);
    this->_tail->setNext(insertionData);
    this->_tail = insertionData;
    this->_lenght++;
    return true;
}

template <class E> bool List<E>::addFirstData(E pData){
    this->_head = this->_tail = new Node<E>(pData);
    this->_lenght++;
    return true;
}

template <class E> bool List<E>::removei(){
    Node<E> *toDelete = this->_head;
    this->_head = this->_head->getNext();
    delete toDelete;
    this->_lenght--;
    return true;
}

template <class E> bool List<E>::removef(){
    Node<E> *currentNode = this->_head;
    for (int x = 0;x < this->_lenght-1;x++)currentNode = currentNode->getNext();
    Node<E> *toDelete = currentNode->getNext();
    currentNode->setNext(Null);
    this->_tail = currentNode;
    this->_lenght--;
    delete toDelete;
    return true;
}



#endif // LIST_H
