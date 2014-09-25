#include "list/Node.h"
#include "list/Stack.h"
#define Null 0

using namespace std;

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

template <class E> E Stack<E>::peek(){
    if (_top != Null){
        return _top->getData();
    }
    cerr<< "Empty Stack!"<< endl;
    throw _top;
}

template <class E> bool Stack<E>::isEmpty(){
    return !_top;
}
