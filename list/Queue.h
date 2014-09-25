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
    Queue(){head = Null; tail = Null;}
    void enqueue(E data){
        Node<E> *insertionNode = new Node<E> (data);
        if (head != Null){
            tail->setNext(insertionNode);
            tail = insertionNode;
            return;
        }
        head = insertionNode;
        tail = head;
    }
    E dequeue(){
        if(head != Null){
            std::cerr << "Empty Queue!\n";
        }
        Node<E> *outNode = head;
        head = head->getNext();
        E out = outNode->getData();
        delete outNode;
        return out;
    }
    bool isEmpty(){
        return !head;
    }
    virtual ~Queue(){
        Node<E> *actual = head;
        Node<E> *tmp;
        while(actual){
            tmp = actual->getNext();
            delete actual;
            actual = tmp;
        }
    }
};

#endif // QUEUE_H
