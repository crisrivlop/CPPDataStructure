#include "IIterator.h"
#include "Node.h"
#include <list>
#include <ostream>
#ifndef SIMPLEITERATOR_H
#define SIMPLEITERATOR_H


template <class E>
/**
 * @brief Esta clase es un iterador de las listas simples, ademas la actualizacion
 * de la lista NO actualiza el iterador, por lo que el iterador es momentaneo. Es similar a una
 * fotografia de una lista que no ha sido alterada si la lista se altera usando un iterador
 * puede que el iterador falle. Por lo que es recomendable que la lista no se actualice mientras
 * se usa un iterador.
 */
class SimpleIterator : public IIterator<E>{
    template <class T>
    friend class List;
    template <class M>
    friend class CircularList;
protected:
    Node<E> *head, *tail, *current; /**< TODO */
public:

    /**
     * @brief Metodo constructor
     * @param head es la cabeza por donde se iniciara la iteracion
     * @param tail es la cola el ultimo elemento de la iteracion
     */
    SimpleIterator(Node<E>*,Node<E>*);


    /**
     * @brief Obtiene el dato actual y actualiza al nodo siguiente.
     * @return E el dato actual
     * @throw donthavenext si el dato actual es nulo
     */
    E getNext();
    /**
     * @brief Obtiene el dato actual
     * @return E el dato actual
     * @throw donthavenext si el dato actual es nulo
     */
    E getCurrent() const;
    /**
     * @brief Verifica si tiene siguiente
     *
     * @return true si tiene siguiente, false si no lo tiene
     * @throw donthavenext si el dato actual es nulo
     */
    bool hasNext() const;
    /**
     * @brief Liberador de memoria
     *
     */
    virtual ~SimpleIterator();
};


template <class E> SimpleIterator<E>::SimpleIterator(Node<E> *phead, Node<E> *ptail){
    this->head = phead;
    this->tail = ptail;
    this->current = this->head;
}



template <class E> E SimpleIterator<E>::getNext(){
    if (!this->current){
        throw this->current;
        std::cerr << "End of List!"<< std::endl;
    }
    E data = this->current->getData();
    this->current = this->current->getNext();
    return data;
}



template <class E> E SimpleIterator<E>::getCurrent() const{
    if (!this->current){
        throw this->current;
        std::cerr << "End of List!"<< std::endl;
    }
    return this->current->getData();
}


template <class E> bool SimpleIterator<E>::hasNext()const{
    if (!this->current){
        return false;
    }
    return this->current->getNext();
}



template <class E> SimpleIterator<E>::~SimpleIterator(){}

#endif // SIMPLEITERATOR_H
