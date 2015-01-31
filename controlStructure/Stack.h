#include "../list/Node.h"

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
     * Metodo constructor
     */
    Stack();
    /**
     * @brief
     * Agrega el dato a la cima de la pila.
     * @param E el dato a agregar.
     */
    void push(E);
    /**
     * @brief
     * Elimina de la pila y retorna el dato de la cima de la pila. En caso de que la pila
     * este vacia se produce un error.
     * @return E el dato en la cima.
     */
    E pop();
    /**
     * @brief
     * Revisa el dato en la cima de la pila. En caso de que la pila
     * este vacia se produce un error.
     * @return E el dato de la cima
     */
    E peek()const;
    /**
     * @brief
     * Retorna verdadero si la pila esta vacia de lo contrario retorna falso.
     * @return bool el valor de verdad de la frase ¿esta vacia la pila?
     */
    bool isEmpty();
    /**
     * @brief
     * Metodo destructor, borra todos los elementos de la pila.
     */
    virtual ~Stack();
};


template <class E> Stack<E>::Stack(){_top = Null;}



template <class E> void Stack<E>::push(E data){
        Node<E> *tmp = new Node<E>(data,_top);
        _top = tmp;
}



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



template <class E> E Stack<E>::peek()const{
    if (_top != Null){
        return _top->getData();
    }
    cerr<< "Empty Stack!"<< endl;
    throw _top;
}




template <class E> bool Stack<E>::isEmpty(){
    return !_top;
}




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
