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
    Stack(){_top = Null;}
    void push(E data){
        Node<E> *tmp = new Node<E>(data,_top);
        _top = tmp;
    }
    E pop(){
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
    E peek(){
        if (_top != Null){
            return _top->getData();
        }
        cerr<< "Empty Stack!"<< endl;
        throw _top;
    }
    bool isEmpty(){
        return !_top;
    }

    virtual ~Stack() {
        // TODO Auto-generated destructor stub
        Node<E> *actual = _top;
        Node<E> *tmp;
        while(actual){
            tmp = actual->getNext();
            delete actual;
            actual = tmp;
        }
    }
};

#endif // STACK_H
