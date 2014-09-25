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
    void setData(E data){this->data = data;}
    E getData(){return data;}
    void setNext(Node *next){this->next = next;}
    Node<E>* getNext(){return this->next;}
    void print(){std::cout << data;}
    virtual ~Node(){std::cout << "node deleted \n";}
};

#endif // NODE_H
