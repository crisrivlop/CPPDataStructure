#include "list/IList.h"
#include "list/Node.h"
#include "SimpleIterator.h"

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#define Null 0
//===========================================================================
//==================== Declaration of Circular List =========================
//===========================================================================
template <class E>

/**
 * @brief
 *
 */
class CircularList :public IList<E>{
    Node<E> *head,*tail; /**< TODO */
    /**
     * @brief
     *
     * @param int
     * @return Node<E>
     */
    Node<E>* getNode(int);

public:
    /**
     * @brief
     *
     */
    CircularList();
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
    IIterator<E>* getIterator();
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
    virtual ~CircularList();
};
//===========================================================================
//========================= END OF DECLARATION ==============================
//===========================================================================



//###########################################################################
//##########################  DATASTRUCTURE   ###############################
//###################           CRISFERLOP           ########################
//########################## GNU/GPL LICENCE  ###############################
//###########################################################################



//===========================================================================
//================== Implementation of Circular List ========================
//===========================================================================


/*
 * @brief CircularList::getNode()
 * @param index
 */
/**
 * @brief
 *
 * @param index
 * @return Node<E> *CircularList<E>
 */
/**
 * @brief
 *
 * @param index
 * @return Node<E> *CircularList<E>
 */
template <class E> Node<E>* CircularList<E>::getNode(int index){
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
/**
 * @brief
 *
 * @param data
 */
template <class E> void CircularList<E>::addi(E data){
        if(head == Null){
            head = new Node<E>(data);
            tail = head;
        }
        else{
            Node<E> *newNode = new Node<E>(data);
            newNode->setNext(head);
            head = newNode;
            tail->setNext(head);
        }
        this->lenght++;
}

/**
 * @brief
 *
 * @param data
 */
/**
 * @brief
 *
 * @param data
 */
template <class E> void CircularList<E>::add(E data){
        if (head == Null){
            head = new Node<E>(data);
            tail = head;
        }
        else{
            Node<E> *newNode = new Node<E>(data);
            tail->setNext(newNode);
            tail = newNode;
            tail->setNext(head);
        }
        this->lenght++;
}

/**
 * @brief
 *
 * @param data
 * @param index
 * @return bool CircularList<E>
 */
/**
 * @brief
 *
 * @param data
 * @param index
 * @return bool CircularList<E>
 */
template <class E> bool CircularList<E>::add(E data,int index){
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
 * @return bool CircularList<E>
 */
/**
 * @brief
 *
 * @param index
 * @return bool CircularList<E>
 */
template <class E> bool CircularList<E>::remove(int index){
        if (0 <= index && index < this->lenght){
            if(this->lenght == 1){
                delete head;
                head = 0;
                tail = 0;
            }
            else if (index == 0){
                Node<E> *deleteNode = head;
                head = head->getNext();
                tail->setNext(head);
                delete deleteNode;
            }
            else if (this->lenght-1 == index){
                Node<E> *deleteNode = tail;
                tail = getNode(index-1);
                tail->setNext(head);
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
/**
 * @brief
 *
 * @param index
 * @param data
 */
template <class E> void CircularList<E>::set(int index,E data){
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
 * @return E CircularList<E>
 */
/**
 * @brief
 *
 * @param index
 * @return E CircularList<E>
 */
template <class E> E CircularList<E>::get(int index){
        if (0 <= index && index < this->lenght){
            return getNode(index)->getData();
        }
        else{
            std::cerr << "index out bounds";
            throw index;
        }
}

template <class E> IIterator<E>* CircularList<E>::getIterator(){
    IIterator<E> *it = 0;
    SimpleIterator<E> *iterador = new SimpleIterator<E>(this->head, this->tail);
    it = iterador;
    return it;
}

/**
 * @brief
 *
 */
/**
 * @brief
 *
 */
template <class E> void CircularList<E>::print() const{
    if (this->lenght > 0){
        Node<E> *actualNode = head;
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
        std::cout << "[]" << std::endl;
    }
}
/**
 * @brief
 *
 */
/**
 * @brief
 *
 */
template <class E> CircularList<E>::~CircularList(){
    Node<E> *actualNode = head;
    std::cout << "Deleting CircularList...\n";
    while(this->lenght != 0){
        actualNode = head;
        head = head->getNext();
        delete actualNode;
        this->lenght--;
    }
    std::cout << "CircularList deleted!\n";
}
/**
 * @brief
 *
 */
/**
 * @brief
 *
 */
template <class E> CircularList<E>::CircularList() {
    tail = Null;
    head = Null;
    this->lenght = 0;
}

#endif // CIRCULARLIST_H
