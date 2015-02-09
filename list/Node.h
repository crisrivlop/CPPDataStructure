#include "iostream"

#ifndef NODE_H
#define NODE_H
/**
 * @brief
 * Es la parte elemental de una lista simple.
 *
 */
template <class E> class Node
{
    E data; /**< TODO */
    Node<E> *next; /**< TODO */
public:
    /**
     * @brief Constructor del Nodo, el next se setea como un puntero
     * nulo para evitar punteros colgados.
     *
     * @param data el dato que contrendra el nodo
     */
    Node(E);
    /**
     * @brief Constructor del Nodo
     *
     * @param data el dato que contendra el dato
     * @param next el puntero al nodo siguiente
     */
    Node(E data,Node<E> *next);
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
    void setNext(Node<E>*);
    /**
     * @brief Obtiene el nodo siguiente
     *
     * @return DoubleNode<E> el nodo siguiente
     */
    Node<E>* getNext()const;

    /**
     * @brief
     * Liberador de memoria.
     */
    virtual ~Node();
};


template <class E> Node<E>::Node(E data){
    this->data = data;
    this->next = 0;
}

template <class E> Node<E>::Node(E data,Node<E> *next){
    this->data = data;
    this->next = next;
}

template <class E> void Node<E>::setData(E data){this->data = data;}

template <class E> E Node<E>::getData()const {return data;}
template <class E> E& Node<E>::getReferenceData(){return data;}

template <class E> void Node<E>::setNext(Node<E> *next){this->next = next;}

template <class E> Node<E>* Node<E>::getNext()const {return this->next;}

template <class E> Node<E>::~Node(){}

#endif // NODE_H
