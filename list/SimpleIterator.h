#include "list/IIterator.h"
#include "list/Node.h"
#include <list>
#ifndef SIMPLEITERATOR_H
#define SIMPLEITERATOR_H


template <class E>
/**
 * @brief
 *
 */
class SimpleIterator : public IIterator<E>{
    /**
     * @brief
     *
     * @param
     * @param
     */
    SimpleIterator(Node<E>*,Node<E>*);
    template <class T>
    friend class List;
protected:
    Node<E> *head, *tail, *current; /**< TODO */
public:
    /**
     * @brief
     *
     * @return E
     */
    E getNext();
    /**
     * @brief
     *
     * @return E
     */
    E getCurrent();
    /**
     * @brief
     *
     * @return bool
     */
    bool hasNext();
    /**
     * @brief
     *
     */
    virtual ~SimpleIterator();
};
/**
 * @brief
 *
 * @param phead
 * @param ptail
 */
template <class E> SimpleIterator<E>::SimpleIterator(Node<E> *phead, Node<E> *ptail){
    this->head = phead;
    this->tail = ptail;
    this->current = this->head;
}
/**
 * @brief
 *
 * @return E SimpleIterator<E>
 */
template <class E> E SimpleIterator<E>::getNext(){
    if (!this->current){
        throw this->current;
        cerr << "End of List!"<< endl;
    }
    E data = this->current->getData();
    this->current = this->current->getNext();
    return data;
}

/**
 * @brief
 *
 * @return E SimpleIterator<E>
 */
template <class E> E SimpleIterator<E>::getCurrent(){
    if (!this->current){
        throw this->current;
        cerr << "End of List!"<< endl;
    }
    return this->current->getData();
}

/**
 * @brief
 *
 * @return bool SimpleIterator<E>
 */
template <class E> bool SimpleIterator<E>::hasNext(){
    if (!this->current){
        return false;
    }
    return this->current->getNext();
}

/**
 * @brief
 *
 */
template <class E> SimpleIterator<E>::~SimpleIterator(){}

#endif // SIMPLEITERATOR_H
