#include "IIterator.h"
#include "DoubleNode.h"
#include <list>
#include <ostream>
#ifndef DOUBLELISTITERATOR_H
#define DOUBLELISTITERATOR_H

template <class E>
/**
 * @brief Esta clase es un iterador de las listas doblemente enlazadas, ademas la actualizacion
 * de la lista NO actualiza el iterador, por lo que el iterador es momentaneo. Es similar a una
 * fotografia de una lista que no ha sido alterada si la lista se altera usando un iterador
 * puede que el iterador falle. Por lo que es recomendable que la lista no se actualice mientras
 * se usa un iterador.
 */
class DoubleIterator:public IIterator<E>{
    template <class T> friend class DoubleList;

    DoubleNode<E> *head,*tail,*current;
public:
    /**
     * @brief Metodo constructor
     * @param head es la cabeza por donde se iniciara la iteracion
     * @param tail es la cola el ultimo elemento de la iteracion
     */
    DoubleIterator(DoubleNode<E>*,DoubleNode<E>*);

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

    virtual ~DoubleIterator(){}
};



template <class E>
DoubleIterator<E>::DoubleIterator(DoubleNode<E> *head, DoubleNode<E> *tail){
    this->head = head;
    this->tail = tail;
    this->current = head;
}
template <class E>
bool DoubleIterator<E>::hasNext()const{
    if (!current){
        throw current;
        std::cerr << "dont have next!" << std::endl;
    }
    return current->getNext();
}


template <class E>
E DoubleIterator<E>::getCurrent()const{
    if (!current){
        throw current;
        std::cerr << "dont have next!" << std::endl;
    }
    return current->getData();
}


template <class E>
E DoubleIterator<E>::getNext(){
    if (!current){
        throw current;
        std::cerr << "dont have next!" << std::endl;
    }
    E data = current->getData();
    current = current->getNext();
    return data;
}

#endif // DOUBLELISTITERATOR_H
