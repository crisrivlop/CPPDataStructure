#include "list/IList.h"
#include "DoubleNode.h"
#include "iostream"
#define Null 0

#ifndef DoubleCircularList_H
#define DoubleCircularList_H

template <class E>
class DoubleCircularList : public IList<E>
{
    DoubleNode<E> *head;
    DoubleNode<E> *tail;
    DoubleNode<E>* getNode(int);
public:
    DoubleCircularList();
    void addi(E);
    void add(E);
    bool add(E,int);
    bool remove(int);
    void set(int,E);
    E get(int);
    //virtual Iterator getIterator() = 0;
    //virtual setComparator(IComparator) = 0;
    //virtual IComparator getComparator() = 0;
    void print() const;
    //bool isEmpty() const;
    //int getLenght() const;
    virtual ~DoubleCircularList();
};

template <class E> DoubleNode<E>* DoubleCircularList<E>::getNode(int index){
        DoubleNode<E> *actualNode = head;
        int from = this->lenght/2 -index;
        if (from <=0){
            int to = this->lenght -1 -index;
            actualNode = tail;
            for (from = 0; from < to ; from++){
                actualNode = actualNode->getPrevious();
            }
        }
        else{
            for (from = 0; from <index; from++){
                actualNode = actualNode->getNext();
            }
        }
        return actualNode;
}

template <class E> DoubleCircularList<E>::DoubleCircularList(){
    tail = Null;
    head = Null;
    this->lenght = 0;
}

template <class E> void DoubleCircularList<E>::addi(E data){
    if(head == Null){
        head = new DoubleNode<E>(data);
        tail = head;
    }
    else{
        DoubleNode<E> *newNode = new DoubleNode<E>(data);
        newNode->setNext(head);
        head->setPrevious(newNode);
        head = newNode;
        head->setPrevious(tail);
        tail->setNext(head);
    }
    this->lenght++;
}

template <class E> void DoubleCircularList<E>::add(E data){
    if (tail == Null){
        head = new DoubleNode<E>(data);
        tail = head;
    }
    else{
        DoubleNode<E> *newNode = new DoubleNode<E>(data);
        tail->setNext(newNode);
        newNode->setPrevious(tail);
        tail = newNode;
        head->setPrevious(tail);
        tail->setNext(head);
    }
    this->lenght++;

}

template <class E> bool DoubleCircularList<E>::add(E data,int index){
    if (0 <= index && index <= this->lenght){
        if (index == 0){
            addi(data);
        }
        else if (this->lenght == index){
            add(data);
        }
        else{
            DoubleNode<E> *previousNode = getNode(index-1);
            DoubleNode<E> *insertionNode = new DoubleNode<E>(data,previousNode,previousNode->getNext());
            previousNode->getNext()->setPrevious(insertionNode);
            previousNode->setNext(insertionNode);
            this->lenght++;
        }
        return true;
    }
    else{
        std::cerr << "index out bounds";
        throw index;
        return false;
    }

}
template <class E> bool DoubleCircularList<E>::remove(int index){
    if (0 <= index && index < this->lenght){
        if(this->lenght == 1){
            delete head;
            head = 0;
            tail = 0;
        }
        else if (index == 0){
            DoubleNode<E> *deleteNode = head;
            head = head->getNext();
            head->setPrevious(tail);
            tail->setNext(head);
            delete deleteNode;
        }
        else if (this->lenght-1 == index){
            DoubleNode<E> *deleteNode = tail;
            tail = tail->getPrevious();
            tail->setNext(head);
            head->setPrevious(tail);
            deleteNode->setPrevious(Null);
            delete deleteNode;
        }
        else{
            DoubleNode<E> *previousNode = getNode(index-1);
            DoubleNode<E> *deleteNode = previousNode->getNext();
            previousNode->setNext(deleteNode->getNext());
            deleteNode->getNext()->setPrevious(previousNode);
            deleteNode->setNext(Null);
            deleteNode->setPrevious(Null);
            delete deleteNode;
        }
        this->lenght--;
        return true;
    }
    else{
        std::cerr << "index out bounds";
        throw index;
        return false;
    }
}
template <class E> void DoubleCircularList<E>::set(int index,E data){
    if (0 <= index && index < this->lenght){
        getNode(index)->setData(data);
    }
    else{
        std::cerr << "index out bounds";
        throw index;
    }
}

template <class E> E DoubleCircularList<E>::get(int index){
    if (0 <= index && index < this->lenght){
        return getNode(index)->getData();
    }
    else{
        std::cerr << "index out bounds\n";
        throw index;

    }
}

template <class E> void DoubleCircularList<E>::print() const{
    if (head){
        DoubleNode<E> *actualNode = head;
        std::cout << "[ ";

        for(int actualIndex = 0; actualIndex < this->lenght-1; actualIndex++){
            actualNode->print();
            std::cout << ", ";
            actualNode = actualNode->getNext();
        }
        actualNode->print();
        std::cout << "]" << std::endl;
    }
    else{
        std::cout << "[ ]"<< std::endl;
    }

}
template <class E> DoubleCircularList<E>::~DoubleCircularList(){
    DoubleNode<E> *actualNode = head;
    std::cout << "Deleting DoubleCircularList...\n";
    while(this->lenght != 0){
        actualNode = head;
        head = head->getNext();
        delete actualNode;
        this->lenght--;
    }
    std::cout << "DoubleCircularList deleted!\n";
}


#endif // DoubleCircularList_H
