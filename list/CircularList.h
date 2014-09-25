#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#define Null 0

template <class E>
class CircularList : IList<E>{
    Node<E> *head,*tail;
    Node<E>* getNode(int);
public:
    CircularList();
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
    virtual ~CircularList();
};

#endif // CIRCULARLIST_H
