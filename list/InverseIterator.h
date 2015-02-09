#include "IIterator.h"
#include "DoubleNode.h"
#include <ostream>
#ifndef INVERSEITERATOR_H
#define INVERSEITERATOR_H
template <class E>
/**
 * @brief Esta clase es un iterador de las listas doblemente enlazadas, ademas la actualizacion
 * de la lista NO actualiza el iterador, por lo que el iterador es momentaneo. Es similar a una
 * fotografia de una lista que no ha sido alterada si la lista se altera usando un iterador
 * puede que el iterador falle. Por lo que es recomendable que la lista no se actualice mientras
 * se usa un iterador. Ademas de que este iterador recorre la lista desde el dato final hasta
 * el dato inicial.
 */
class InverseIterator:public IIterator<E>{

    template <class T> friend class DoubleList;

    DoubleNode<E> *head,*tail,*current; /**< TODO */
public:
    /**
     * @brief Metodo constructor
     * @param head es la cabeza el ultimo elemento de la iteracion
     * @param tail es la cola por donde se iniciara la iteracion
     */
    InverseIterator(DoubleNode<E>*,DoubleNode<E>*);

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
    bool hasNext() const;
    /**
     * @brief Verifica si tiene siguiente
     *
     * @return true si tiene siguiente, false si no lo tiene
     * @throw donthavenext si el dato actual es nulo
     */
    E getCurrent() const;
    /**
     * @brief liberador de memoria
     *
     */
    virtual ~InverseIterator(){}
};


template <class E> InverseIterator<E>::InverseIterator(DoubleNode<E> *head,DoubleNode<E>*tail){
    this->head = head;
    this->tail = tail;
    current = tail;
}


template <class E> E InverseIterator<E>::getNext(){
    if (!current){
        throw current;
        std::cerr << "dont have next!" << std::endl;
    }
    E data = current->getData();
    current = current->getPrevious();
    return data;
}


template <class E> E InverseIterator<E>::getCurrent() const{
    if (!current){
        throw current;
        std::cerr <<"dont have next!"<< std::endl;
    }
    return current->getData();
}


template <class E> bool InverseIterator<E>::hasNext() const{
    if (!current){
        throw current;
        std::cerr << "dont have next!"<< std::endl;
    }
    return current->getPrevious();
}


#endif // INVERSEITERATOR_H
