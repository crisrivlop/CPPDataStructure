#include "list/Node.h"

#ifndef STACK_H
#define STACK_H
#define Null 0


using namespace std;


template <class E>
/**
 * @brief
 *
 */
class Stack {
private:
    Node<E> *_top; /**< TODO */
public:
    /**
     * @brief
     *
     */
    Stack();
    /**
     * @brief
     *
     * @param E
     */
    void push(E);
    /**
     * @brief
     *
     * @return E
     */
    E pop();
    /**
     * @brief
     *
     * @return E
     */
    E peek()const;
    /**
     * @brief
     *
     * @return bool
     */
    bool isEmpty();
    /**
     * @brief
     *
     */
    virtual ~Stack();
};

/**
 * @brief
 *
 */
template <class E> Stack<E>::Stack(){_top = Null;}

/**
 * @brief
 *
 * @param data
 */
template <class E> void Stack<E>::push(E data){
        Node<E> *tmp = new Node<E>(data,_top);
        _top = tmp;
}

/**
 * @brief
 *
 * @return E Stack<E>
 */
template <class E> E Stack<E>::pop(){
    if (!_top){
        cerr<< "Empty Stack!"<< endl;
        throw _top;
    }
    Node<E> *tmp = _top;
    _top = _top->getNext();
    E data = tmp->getData();
    delete tmp;
    return data;
}

/**
 * @brief
 *
 * @return E Stack<E>
 */
template <class E> E Stack<E>::peek()const{
    if (_top != Null){
        return _top->getData();
    }
    cerr<< "Empty Stack!"<< endl;
    throw _top;
}

/**
 * @brief
 *
 * @return bool Stack<E>
 */
template <class E> bool Stack<E>::isEmpty(){
    return !_top;
}

/**
 * @brief
 *
 */
template <class E> Stack<E>::~Stack() {
    // TODO Auto-generated destructor stub
    Node<E> *actual = _top;
    Node<E> *tmp;
    while(actual){
        tmp = actual->getNext();
        delete actual;
        actual = tmp;
    }
}

#endif // STACK_H
