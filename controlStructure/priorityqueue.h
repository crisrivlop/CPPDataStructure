#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


template <class E>
class PriorityQueue
{
public:
    PriorityQueue();
    void enqueue(E pdata,int prioridad);
    E dequeue();
    E last();
    E first();
};

template <class E>
void PriorityQueue<E>::enqueue(E pdata, int prioridad)
{

}
template <class E>
E PriorityQueue<E>::dequeue()
{

}
template <class E>
E PriorityQueue<E>::last()
{

}
template <class E>
E PriorityQueue<E>::first()
{

}
#endif // PRIORITYQUEUE_H
