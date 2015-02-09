#include "list/IIterator.h"
#define Null 0
#ifndef IORDINATELIST_H
#define IORDINATELIST_H

template <class E>
class IOrdinateList
{
protected:
    int _lenght;
public:
    virtual bool add(E pData) = 0;
    virtual bool remove(int pIndex) = 0;
    virtual int search(E pData) = 0;
    virtual E get(int pIndex) = 0;
    virtual E& getReference(int pIndex) = 0;
    int getLenght();
    virtual IIterator<E>* getIterator() = 0;
    virtual ~IOrdinateList(){}
};

template <class E> int IOrdinateList<E>::getLenght(){
    return _lenght;
}

#endif // IORDINATELIST_H
