#include "iostream"
#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <class E>
/**
 * @brief
 * Es la parte elemental de una lista que sea doublemente enlazada.
 *
 */
class DoubleNode
{
    E data; /**< TODO */
    DoubleNode<E> *next; /**< TODO */
    DoubleNode<E> *previous; /**< TODO */
public:
    /**
     * @brief Constructor del Nodo Doble, el dato previous y next se setean como punteros
     * nulos para evitar punteros colgados.
     *
     * @param data el dato que contrendra el nodo
     */
    DoubleNode(E);
    /**
     * @brief Constructor del Nodo Doble
     *
     * @param data el dato que contendra el dato
     * @param previous el puntero al nodo anterior
     * @param next el puntero al nodo siguiente
     */
    DoubleNode(E, DoubleNode<E>*, DoubleNode<E>*);
    /**
     * @brief
     * Setea el dato contenido en el nodo
     * @param data el dato nuevo
     */
    void setData(E);
    /**
     * @brief Obtiene el dato contenido en el nodo
     *
     * @return E el dato contenido
     */
    E getData() const;

    E& getReferenceData();

    /**
     * @brief Setea el puntero del nodo siguiente
     *
     * @param next el nuevo nodo que representa el nodo siguiente
     */
    void setNext(DoubleNode<E>*);
    /**
     * @brief Obtiene el nodo siguiente
     *
     * @return DoubleNode<E> el nodo siguiente
     */
    DoubleNode<E>* getNext()const;


    /**
     * @brief Setea el puntero del nodo anterior
     *
     * @param previous el nuevo nodo que reprenta el nodo anterior
     */
    void setPrevious(DoubleNode<E>*);
    /**
     * @brief Obtiene el nodo anterior
     *
     * @return DoubleNode<E> el nodo anterior
     */
    DoubleNode<E>* getPrevious()const;

    /**
     * @brief el destructor de este nodo
     *
     */
    virtual ~DoubleNode();

};




template <class E> DoubleNode<E>::DoubleNode(E data){
    this->data = data;
    next = 0;
    previous = 0;
}



template <class E> DoubleNode<E>::DoubleNode(E data, DoubleNode<E> *previous, DoubleNode<E> *next){
    this->data = data;
    this->next = next;
    this->previous = previous;
}


template <class E> void DoubleNode<E>::setData(E data){this->data = data;}


template <class E> E DoubleNode<E>::getData()const{return data;}

template <class E> E& DoubleNode<E>::getReferenceData(){return data;}


template <class E> void DoubleNode<E>::setNext(DoubleNode *next){this->next = next;}


template <class E> DoubleNode<E>* DoubleNode<E>::getNext()const{return next;}


template <class E> void DoubleNode<E>::setPrevious(DoubleNode *previous){this->previous = previous;}


template <class E> DoubleNode<E>* DoubleNode<E>::getPrevious()const{return previous;}



template <class E> DoubleNode<E>::~DoubleNode(){}

#endif // DOUBLENODE_H
