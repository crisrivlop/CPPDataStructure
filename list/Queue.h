#ifndef QUEUE_H
#define QUEUE_H
#define Null 0

template <class E>
class Queue {
private:
    Node<E> *tail,*head;
public:
    Queue(){head = Null; tail = Null;}
    void enqueue(E);
    E dequeue();
    bool isEmpty();
    virtual ~Queue();
};

#endif // QUEUE_H
