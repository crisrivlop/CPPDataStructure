#ifndef STACK_H
#define STACK_H
#define Null 0

template <class E>
class Stack {
private:
    Node<E> *_top;
public:
    Stack(){_top = Null;}
    void push(E);
    E pop();
    E peek();
    bool isEmpty();
    virtual ~Stack();
};

#endif // STACK_H
