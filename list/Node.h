#include "iostream"

#ifndef NODE_H
#define NODE_H
/**
 * @brief
 *
 */
template <class E> class Node
{
    E data; /**< TODO */
    Node<E> *next; /**< TODO */
public:
    /**
     * @brief
     *
     * @param E
     */
    Node(E);
    /**
     * @brief
     *
     * @param data
     * @param next
     */
    Node(E data,Node<E> *next);
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
    void setNext(Node<E>*);
    /**
     * @brief
     *
     * @return Node<E>
     */
    Node<E>* getNext()const;
    /**
     * @brief
     *
     */
    void print() const;
    /**
     * @brief
     *
     */
    virtual ~Node();
};

/**
 * @brief
 *
 * @param data
 */
template <class E> Node<E>::Node(E data){
    this->data = data;
    this->next = 0;
}
/**
 * @brief
 *
 * @param data
 * @param next
 */
template <class E> Node<E>::Node(E data,Node<E> *next){
    this->data = data;
    this->next = next;
}
/**
 * @brief
 *
 * @param data
 */
template <class E> void Node<E>::setData(E data){this->data = data;}
/**
 * @brief
 *
 * @return E Node<E>
 */
template <class E> E Node<E>::getData()const {return data;}
/**
 * @brief
 *
 * @param next
 */
template <class E> void Node<E>::setNext(Node<E> *next){this->next = next;}
/**
 * @brief
 *
 * @return Node<E> *Node<E>
 */
template <class E> Node<E>* Node<E>::getNext()const {return this->next;}
/**
 * @brief
 *
 */
template <class E> void Node<E>::print() const{std::cout << data;}
/**
 * @brief
 *
 */
template <class E> Node<E>::~Node(){}

#endif // NODE_H
