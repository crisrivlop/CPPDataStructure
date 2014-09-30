#include "list/Node.h"

#ifndef STACK_H
#define STACK_H
#define Null 0


using namespace std;


template <class E>
class Stack {
private:
    Node<E> *_top;
public:
    Stack();
    void push(E);
    E pop();
    E peek()const;
    bool isEmpty();
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
