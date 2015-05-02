#include "list/IIterator.h"
#include "iostream"
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
    int search(E pData);
    virtual E get(int pIndex) = 0;
    virtual E& getReference(int pIndex) = 0;
    int getLenght();
    virtual IIterator<E>* getIterator() = 0;
    virtual ~IOrdinateList(){}
};

template <class E> int IOrdinateList<E>::getLenght(){
    return _lenght;
}


template <class E> int IOrdinateList<E>::search(E pData){
    int left,center,right;
    left = 0;
    right = _lenght-1;
    while(left <= right){
        center = int((left+right)/2);
        if (pData < get(center)){
            right = center-1;
        }
        else if (pData > get(center)){
            left = center+1;
        }
        else{
            return center;
        }
    }
    return -1;
}


#endif // IORDINATELIST_H
