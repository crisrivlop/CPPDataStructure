#include "iostream"

#ifndef NODE_H
#define NODE_H
template <class E> class Node
{
    E data;
    Node<E> *next;
public:
    Node(E);
    Node(E data,Node<E> *next);
    void setData(E);
    E getData() const;
    void setNext(Node<E>*);
    Node<E>* getNext()const;
    void print() const;
    virtual ~Node();
};

template <class E> Node<E>::Node(E data){
    this->data = data;
    this->next = 0;
}
template <class E> Node<E>::Node(E data,Node<E> *next){
    this->data = data;
    this->next = next;
}
template <class E> void Node<E>::setData(E data){this->data = data;}
template <class E> E Node<E>::getData()const {return data;}
template <class E> void Node<E>::setNext(Node<E> *next){this->next = next;}
template <class E> Node<E>* Node<E>::getNext()const {return this->next;}
template <class E> void Node<E>::print() const{std::cout << data;}
template <class E> Node<E>::~Node(){}

#endif // NODE_H
