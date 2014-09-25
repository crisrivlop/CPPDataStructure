#ifndef DoubleCircularList_H
#define DoubleCircularList_H

template <class E>
class DoubleCircularList : public IList<E>
{
    DoubleNode<E> *head;
    DoubleNode<E> *tail;
    DoubleNode<E>* getNode(int);
public:
    DoubleCircularList();
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
    virtual ~DoubleCircularList();
};

#endif // DoubleCircularList_H
