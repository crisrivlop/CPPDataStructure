#include "list/Node.h"
#include "ostream"
#include "list/Queue.h"
#define Null 0


#ifndef QUEUE_H
#define QUEUE_H

template <class E>
class Queue {
private:
    Node<E> *tail,*head;
public:
    Queue();
    void enqueue(E data);
    E dequeue();
    bool isEmpty();
    virtual ~Queue();
};

template <class E> Queue<E>::Queue(){head = Null; tail = Null;}
template <class E> void Queue<E>::enqueue(E data){
    Node<E> *insertionNode = new Node<E> (data);
    if (head != Null){
        tail->setNext(insertionNode);
        tail = insertionNode;
        return;
    }
    head = insertionNode;
    tail = head;
}
template <class E> E Queue<E>::dequeue(){
    if(head != Null){
        std::cerr << "Empty Queue!\n";
    }
    Node<E> *outNode = head;
    head = head->getNext();
    E out = outNode->getData();
    delete outNode;
    return out;
}
template <class E> Queue<E>::isEmpty(){
    return !head;
}

template <class E> Queue<E>::~Queue(){
    Node<E> *actual = head;
    Node<E> *tmp;
    while(actual){
        tmp = actual->getNext();
        delete actual;
        actual = tmp;
    }
}

#endif // QUEUE_H
