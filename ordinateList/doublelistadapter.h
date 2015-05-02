#include "iordinatelist.h"
#include "list/DoubleNode.h"
#include "list/DoubleIterator.h"
#include "list/InverseIterator.h"
#include "iostream"
#ifndef DOUBLELISTADAPTER_H
#define DOUBLELISTADAPTER_H

template <class E>
class DoubleListAdapter:public IOrdinateList<E>
{
    bool _inverseIteration;
protected:
    DoubleNode<E> *_head,*_tail;
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
    void setInversedIteration(bool pIteration);
    virtual ~DoubleListAdapter();
    void print();
};

template <class E> bool DoubleListAdapter<E>::add(E pData){
    if (_head == Null)return addFirstData(pData);
    else if (pData < _head->getData())return addi(pData);
    else if (pData > _tail->getData())return addf(pData);
    else{
        DoubleNode<E> *currentNode = _head;
        while (pData > currentNode->getNext()->getData())currentNode = currentNode->getNext();
        if (pData != currentNode->getNext()->getData()){
            DoubleNode<E> *nextNode = currentNode->getNext();
            DoubleNode<E> *insertionNode = new DoubleNode<E>(pData,currentNode,nextNode);
            currentNode->setNext(insertionNode);
            nextNode->setPrevious(insertionNode);
            this->_lenght++;
            return true;
        }
        return false;
    }
}
template <class E> bool DoubleListAdapter<E>::remove(int pIndex){
    if (pIndex < 0 || pIndex >= this->_lenght)return false;
    else if (pIndex == 0)return removei();
    else if (pIndex == this->_lenght-1)return removef();
    else{
        DoubleNode<E> *currentNode = _head;
        for (int x = 0;x < pIndex-1;x++)currentNode = currentNode->getNext();
        DoubleNode<E> *toDelete = currentNode->getNext();
        currentNode->setNext(toDelete->getNext());
        toDelete->getNext()->setPrevious(currentNode);
        this->_lenght--;
        delete toDelete;
        return true;
    }

}

template <class E> E DoubleListAdapter<E>::get(int pIndex){
    if (pIndex < 0 || pIndex >= this->_lenght)throw this;
    else{
        DoubleNode<E> *currentNode = _head;
        for (int x = 0;x < pIndex;x++)currentNode = currentNode->getNext();
        return currentNode->getData();
    }
}


template <class E> E& DoubleListAdapter<E>::getReference(int pIndex){
    if (pIndex < 0 || pIndex >= this->_lenght)throw this;
    else{
        DoubleNode<E> *currentNode = _head;
        for (int x = 0;x < pIndex;x++)currentNode = currentNode->getNext();
        return currentNode->getReferenceData();
    }
}

template <class E> IIterator<E>* DoubleListAdapter<E>::getIterator()
{
    IIterator<E> *iterator;
    if(_inverseIteration)iterator = new InverseIterator<E>(_head, _tail);
    else iterator = new DoubleIterator<E>(_head,_tail);
    return iterator;

}

template <class E> void DoubleListAdapter<E>::setInversedIteration(bool pIteration)
{
    _inverseIteration = pIteration;
}

template <class E> DoubleListAdapter<E>::~DoubleListAdapter()
{
    DoubleNode<E> *actualNode = _head;
    while(_head){
        actualNode = _head;
        _head = _head->getNext();
        delete actualNode;
        this->_lenght--;
    }
}


template <class E> void DoubleListAdapter<E>::print(){
    std::cout << "[";
    DoubleNode<E> *current = this->_head;
    for(int x = 0; x < this->_lenght -1; x++){
        std::cout << current->getData() <<",";
        current = current->getNext();
    }
    std::cout << current->getData() <<"]" << std::endl;
}

#endif // DOUBLELISTADAPTER_H
