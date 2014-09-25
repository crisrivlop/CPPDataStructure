#ifndef DOUBLENODE_H
#define DOUBLENODE_H
template <class E>
class DoubleNode
{
    E data;
    DoubleNode<E> *next;
    DoubleNode<E> *previous;
public:
    DoubleNode(E data)
    {
        this->data = data;
        next = 0;
        previous = 0;
    }
    DoubleNode(E data, DoubleNode<E> *previous, DoubleNode<E> *next){
        this->data = data;
        this->next = next;
        this->previous = previous;
    }
    void setData(E);
    E getData();
    void setNext(DoubleNode*);
    DoubleNode* getNext();
    void setPrevious(DoubleNode*);
    DoubleNode* getPrevious();
    void print();
    virtual ~DoubleNode();
};

#endif // DOUBLENODE_H
