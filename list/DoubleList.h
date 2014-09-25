#include "list/DoubleNode.h"
#include "IList.h"
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

template <class E>
class DoubleList : public IList<E>
{
    DoubleNode<E> *head;
    DoubleNode<E> *tail;
    DoubleNode<E>* getNode(int);
public:
    DoubleList();
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
    virtual ~DoubleList();
};

#endif // DOUBLELIST_H
