#include "list/IList.cpp"
#include "list/Node.h"
#define Null 0

#ifndef LIST_H
#define LIST_H

template <class E>
class List: public IList<E>{
    Node<E> *head;
    Node<E> *tail;
    //private methods
    Node<E>* getNode(int);
public:
    List();
    void addi(E);
    void add(E);
    bool add(E,int);
    bool remove(int);
    void set(int,E);
    E get(int);
    //virtual Iterator getIterator() = 0;
    //virtual setComparator(IComparator) = 0;
    //virtual IComparator getComparator() = 0;
    void print() const;
    //bool isEmpty() const;
    //int getLenght() const;
    virtual ~List();
};

#endif // LIST_H
