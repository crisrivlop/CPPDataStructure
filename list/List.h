#include <iostream>
#include <list>
#define Null 0

#ifndef LIST_HPP
#define LIST_HPP

template <class E>
/**
 * @brief
 *
 */
class List : public IList<E>{
    /**
     * @brief
     *
     * @param int
     * @return Node<E>
     */
    Node<E>* getNode(int);
    Node<E> *head; /**< TODO */
    Node<E> *tail; /**< TODO */

public:
    /**
     * @brief
     *
     */
    List();
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
    /**
     * @brief
     *
     * @return SimpleIterator<E>
     */
    SimpleIterator<E>* getIterator();
    //virtual setComparator(IComparator) = 0;
    //virtual IComparator getComparator() = 0;
    /**
     * @brief
     *
     */
    void print() const;
    /**
     * @brief
     *
     */
    virtual ~List();
};
/**
 * @brief
 *
 */
template <class E> List<E>::List() {
    tail = Null;
    head = Null;
    this->lenght = 0;
}

/**
 * @brief
 *
 * @param index
 * @return Node<E> *List<E>
 */
template <class E> Node<E>* List<E>::getNode(int index){
    Node<E> *actualNode = head;
    for (int from = 0; from <index; from++){
        actualNode = actualNode->getNext();
    }
    return actualNode;
}

/**
 * @brief
 *
 * @param data
 */
template <class E> void List<E>::addi(E data){
    if(head == Null){
        head = new Node<E>(data);
        tail = head;
    }
    else{
        Node<E> *newNode = new Node<E>(data);
        newNode->setNext(head);
        head = newNode;
    }
    this->lenght++;
}

/**
 * @brief
 *
 * @param data
 */
template <class E> void List<E>::add(E data){
    if (head == Null){
        head = new Node<E>(data);
        tail = head;
    }
    else{
        Node<E> *newNode = new Node<E>(data);
        tail->setNext(newNode);
        tail = newNode;
    }
    this->lenght++;

}

/**
 * @brief
 *
 * @param data
 * @param index
 * @return bool List<E>
 */
template <class E> bool List<E>::add(E data,int index){
    if (0 <= index && index <= this->lenght){
        if (index == 0){
            addi(data);
        }
        else if (this->lenght == index){
            add(data);
        }
        else{
            Node<E> *previousNode = getNode(index-1);
            Node<E> *insertionNode = new Node<E>(data,previousNode->getNext());
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
 * @return bool List<E>
 */
template <class E> bool List<E>::remove(int index){
    if (0 <= index && index < this->lenght){
        if(this->lenght == 1){
            delete head;
            head = 0;
            tail = 0;
        }
        else if (index == 0){
            Node<E> *deleteNode = head;
            head = head->getNext();
            delete deleteNode;
        }
        else if (this->lenght-1 == index){
            Node<E> *deleteNode = tail;
            tail = getNode(index-1);
            tail->setNext(Null);
            delete deleteNode;
        }
        else{
            Node<E> *previousNode = getNode(index-1);
            Node<E> *deleteNode = previousNode->getNext();
            previousNode->setNext(deleteNode->getNext());
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
template <class E> void List<E>::set(int index,E data){
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
 * @return E List<E>
 */
template <class E> E List<E>:: get(int index){
    if (0 <= index && index < this->lenght){
        return getNode(index)->getData();
    }
    else{
        std::cerr << "index out bounds";
        throw index;
    }
}
/**
 * @brief
 *
 * @return SimpleIterator<E> *List<E>
 */
template <class E> SimpleIterator<E>* List<E>:: getIterator(){
    SimpleIterator<E> *iterador = new SimpleIterator<E>(head, tail);
    return iterador;
}

/**
 * @brief
 *
 */
template <class E> void List<E>::print() const{
    if (this->lenght > 0){
        Node<E> *actualNode = head;
        std::cout << "[";
        for(int actualIndex = 0; actualIndex < this->lenght-1; actualIndex++){
            actualNode->print();
            std::cout << ",";
            actualNode = actualNode->getNext();
        }
        actualNode->print();
        std::cout << "]" << std::endl;
    }
    else{
        std::cout << "[]" << std::endl;
    }
}

/**
 * @brief
 *
 */
template <class E> List<E>::~List(){
    Node<E> *actualNode = head;
    std::cout << "Deleting List...\n";
    while(this->lenght !=0){
        actualNode = head;
        head = head->getNext();
        delete actualNode;
        this->lenght--;
    }
    std::cout << "List deleted!\n";
}

#endif // LIST_HPP
