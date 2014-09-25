#include "iostream"

#ifndef NODE_H
#define NODE_H
template <class E> class Node
{
    E data;
    Node<E> *next;
public:
    Node(E data){
        this->data = data;
        this->next = 0;
    }
    Node(E data,Node<E> *next){
        this->data = data;
        this->next = next;
    }
    void setData(E);
    E getData();
    void setNext(Node<E>*);
    Node<E>* getNext();
    void print();
    virtual ~Node();
};

#endif // NODE_H
