#include "iordinatelist.h"
#include "list/Node.h"
#include "list/SimpleIterator.h"
#include <iostream>
#ifndef SIMPLELISTADAPTER_H
#define SIMPLELISTADAPTER_H

template <class E>
class SimpleListAdapter:public IOrdinateList<E>
{
protected:
    Node<E> *_head,*_tail;
    virtual bool addi(E pData) = 0;
    virtual bool addf(E pData) = 0;
    virtual bool addFirstData(E pData) = 0;
    virtual bool removei() = 0;
    virtual bool removef() = 0;
public:
    bool add(E pData);
    bool remove(int pIndex);
    E get(int pIndex);
    E& getReference(int pIndex);
    IIterator<E>* getIterator();
    void print();
    virtual ~SimpleListAdapter();
};

template <class E> bool SimpleListAdapter<E>::add(E pData){
    if (_head == Null)return addFirstData(pData);
    else if (pData < _head->getData())return addi(pData);
    else if (pData > _tail->getData())return addf(pData);
    else{
        Node<E> *currentNode = _head;
        while (pData > currentNode->getNext()->getData())currentNode = currentNode->getNext();
        if (pData != currentNode->getNext()->getData()){
            Node<E> *nextNode = currentNode->getNext();
            Node<E> *insertionNode = new Node<E>(pData,nextNode);
            currentNode->setNext(insertionNode);
            this->_lenght++;
            return true;
        }
        return false;
    }
}
template <class E> bool SimpleListAdapter<E>::remove(int pIndex){
    if (pIndex < 0 || pIndex >= this->_lenght)return false;
    else if (pIndex == 0)return removei();
    else if (pIndex == this->_lenght-1)return removef();
    else{
        Node<E> *currentNode = _head;
        for (int x = 0;x < pIndex-1;x++)currentNode = currentNode->getNext();
        Node<E> *toDelete = currentNode->getNext();
        currentNode->setNext(toDelete->getNext());
        this->_lenght--;
        delete toDelete;
        return true;
    }

}


template <class E> E SimpleListAdapter<E>::get(int pIndex){
    if (pIndex < 0 || pIndex >= this->_lenght)throw this;
    else{
        Node<E> *currentNode = _head;
        for (int x = 0;x < pIndex;x++)currentNode = currentNode->getNext();
        return currentNode->getData();
    }
}


template <class E> E& SimpleListAdapter<E>::getReference(int pIndex){
    if (pIndex < 0 || pIndex >= this->_lenght)throw this;
    else{
        Node<E> *currentNode = _head;
        for (int x = 0;x < pIndex;x++)currentNode = currentNode->getNext();
        return currentNode->getReferenceData();
    }
}

template <class E> IIterator<E>* SimpleListAdapter<E>::getIterator()
{
    IIterator<E> *iterator = new SimpleIterator<E>(_head,_tail);
    return iterator;
}

template <class E> SimpleListAdapter<E>::~SimpleListAdapter()
{
    Node<E> *actualNode = _head;
    while(_head){
        actualNode = _head;
        _head = _head->getNext();
        delete actualNode;
        this->_lenght--;
    }
}


template <class E> void SimpleListAdapter<E>::print(){
    std::cout << "[";
    Node<E> *current = this->_head;
    for(int x = 0; x < this->_lenght -1; x++){
        std::cout << current->getData() <<",";
        current = current->getNext();
    }
    std::cout << current->getData() <<"]" << std::endl;
}

#endif // SIMPLELISTADAPTER_H
