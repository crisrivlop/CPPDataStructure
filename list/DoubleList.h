#include "list/IList.h"
#include "list/DoubleNode.h"
#include "iostream"
#define Null 0
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

template <class E>
/**
 * @brief
 *
 */
class DoubleList : public IList<E>
{
    DoubleNode<E> *head; /**< TODO */
    DoubleNode<E> *tail; /**< TODO */
    /**
     * @brief
     *
     * @param int
     * @return DoubleNode<E>
     */
    DoubleNode<E>* getNode(int);

public:
    /**
     * @brief
     *
     */
    DoubleList();
    /**
     * @brief
     *
     * @param E
     */
    void addi(E);
    /**
     * @brief
     *
     * @param E
     */
    void add(E);
    /**
     * @brief
     *
     * @param E
     * @param int
     * @return bool
     */
    bool add(E,int);
    /**
     * @brief
     *
     * @param int
     * @return bool
     */
    bool remove(int);
    /**
     * @brief
     *
     * @param int
     * @param E
     */
    void set(int,E);
    /**
     * @brief
     *
     * @param int
     * @return E
     */
    E get(int);
    //virtual Iterator getIterator() = 0;
    //virtual setComparator(IComparator) = 0;
    //virtual IComparator getComparator() = 0;
    /**
     * @brief
     *
     */
    void print() const;
    //bool isEmpty() const;
    //int getLenght() const;
    /**
     * @brief
     *
     */
    virtual ~DoubleList();
};

/**
 * @brief
 *
 * @param index
 * @return DoubleNode<E> *DoubleList<E>
 */
template <class E> DoubleNode<E>* DoubleList<E>::getNode(int index){
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

/**
 * @brief
 *
 */
template <class E> DoubleList<E>::DoubleList(){
    tail = Null;
    head = Null;
    this->lenght = 0;
}

/**
 * @brief
 *
 * @param data
 */
template <class E> void DoubleList<E>::addi(E data){
    if(head == Null){
        head = new DoubleNode<E>(data);
        tail = head;
    }
    else{
        DoubleNode<E> *newNode = new DoubleNode<E>(data);
        newNode->setNext(head);
        head->setPrevious(newNode);
        head = newNode;
    }
    this->lenght++;
}
/**
 * @brief
 *
 * @param data
 */
template <class E> void DoubleList<E>::add(E data){
    if (tail == Null){
        head = new DoubleNode<E>(data);
        tail = head;
    }
    else{
        DoubleNode<E> *newNode = new DoubleNode<E>(data);
        tail->setNext(newNode);
        newNode->setPrevious(tail);
        tail = newNode;
    }
    this->lenght++;

}

/**
 * @brief
 *
 * @param data
 * @param index
 * @return bool DoubleList<E>
 */
template <class E> bool DoubleList<E>::add(E data,int index){
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
/**
 * @brief
 *
 * @param index
 * @return bool DoubleList<E>
 */
template <class E> bool DoubleList<E>::remove(int index){
    if (0 <= index && index < this->lenght){
        if(this->lenght == 1){
            delete head;
            head = 0;
            tail = 0;
        }
        else if (index == 0){
            DoubleNode<E> *deleteNode = head;
            head = head->getNext();
            head->setPrevious(Null);
            delete deleteNode;
        }
        else if (this->lenght-1 == index){
            DoubleNode<E> *deleteNode = tail;
            tail = tail->getPrevious();
            tail->setNext(Null);
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


/**
 * @brief
 *
 * @param index
 * @param data
 */
template <class E> void DoubleList<E>::set(int index,E data){
    if (0 <= index && index < this->lenght){
        getNode(index)->setData(data);
    }
    else{
        std::cerr << "index out bounds";
        throw index;
    }
}

/**
 * @brief
 *
 * @param index
 * @return E DoubleList<E>
 */
template <class E> E DoubleList<E>::get(int index){
    if (0 <= index && index < this->lenght){
        return getNode(index)->getData();
    }
    else{
        std::cerr << "index out bounds\n";
        throw index;

    }
}
/**
 * @brief
 *
 */
template <class E> void DoubleList<E>::print() const{
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
/**
 * @brief
 *
 */
template <class E> DoubleList<E>::~DoubleList(){
    DoubleNode<E> *actualNode = head;
    std::cout << "Deleting DoubleList...\n";
    while(this->lenght != 0){
        actualNode = head;
        head = head->getNext();
        delete actualNode;
        this->lenght--;
    }
    std::cout << "DoubleList deleted!\n";
}
#endif // DOUBLELIST_H
