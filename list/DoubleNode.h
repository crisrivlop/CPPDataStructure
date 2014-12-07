#include "iostream"
#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <class E>
/**
 * @brief
 *
 */
class DoubleNode
{
    E data; /**< TODO */
    DoubleNode<E> *next; /**< TODO */
    DoubleNode<E> *previous; /**< TODO */
public:
    /**
     * @brief
     *
     * @param E
     */
    DoubleNode(E);
    /**
     * @brief
     *
     * @param E
     * @param
     * @param
     */
    DoubleNode(E, DoubleNode<E>*, DoubleNode<E>*);
    /**
     * @brief
     *
     * @param E
     */
    void setData(E);
    /**
     * @brief
     *
     * @return E
     */
    E getData() const;
    /**
     * @brief
     *
     * @param
     */
    void setNext(DoubleNode<E>*);
    /**
     * @brief
     *
     * @return DoubleNode<E>
     */
    DoubleNode<E>* getNext()const;


    /**
     * @brief
     *
     * @param
     */
    void setPrevious(DoubleNode<E>*);
    /**
     * @brief
     *
     * @return DoubleNode<E>
     */
    DoubleNode<E>* getPrevious()const;


    /**
     * @brief
     *
     */
    void print() const;
    /**
     * @brief
     *
     */
    ~DoubleNode();

};

/**
 * @brief
 *
 * @param data
 */
template <class E> DoubleNode<E>::DoubleNode(E data){
    this->data = data;
    next = 0;
    previous = 0;
}


/**
 * @brief
 *
 * @param data
 * @param previous
 * @param next
 */
template <class E> DoubleNode<E>::DoubleNode(E data, DoubleNode<E> *previous, DoubleNode<E> *next){
    this->data = data;
    this->next = next;
    this->previous = previous;
}

/**
 * @brief
 *
 * @param data
 */
template <class E> void DoubleNode<E>::setData(E data){this->data = data;}

/**
 * @brief
 *
 * @return E DoubleNode<E>
 */
template <class E> E DoubleNode<E>::getData()const{return data;}

/**
 * @brief
 *
 * @param next
 */
template <class E> void DoubleNode<E>::setNext(DoubleNode *next){this->next = next;}

/**
 * @brief
 *
 * @return DoubleNode<E> *DoubleNode<E>
 */
template <class E> DoubleNode<E>* DoubleNode<E>::getNext()const{return next;}

/**
 * @brief
 *
 * @param previous
 */
template <class E> void DoubleNode<E>::setPrevious(DoubleNode *previous){this->previous = previous;}

/**
 * @brief
 *
 * @return DoubleNode<E> *DoubleNode<E>
 */
template <class E> DoubleNode<E>* DoubleNode<E>::getPrevious()const{return previous;}

/**
 * @brief
 *
 */
template <class E> void DoubleNode<E>::print() const {std::cout << data;}

/**
 * @brief
 *
 */
template <class E> DoubleNode<E>::~DoubleNode(){}

#endif // DOUBLENODE_H
