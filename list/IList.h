#ifndef ILIST_H
#define ILIST_H

template <class E>
class IList
{
protected:
    int lenght;
public:
    virtual void addi(E) = 0;
    virtual void add(E) = 0;
    virtual bool add(E,int) = 0;
    virtual bool remove(int) = 0;
    virtual void set(int,E) = 0;
    virtual E get(int) = 0;
    int getLenght() const{return lenght;}
    //virtual Iterator getIterator() = 0;
    //virtual setComparator(IComparator) = 0;
    //virtual IComparator getComparator() = 0;
    bool isEmpty() const{return lenght == 0;}
    virtual void print() const = 0;
};

#endif // ILIST_H
