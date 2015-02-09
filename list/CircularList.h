#include "list/IList.h"
#include "list/Node.h"
#include "SimpleIterator.h"

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

//===========================================================================
//==================== Declaration of Circular List =========================
//===========================================================================

template <class E>

/**
 * @brief
 * Esta clase es una estructura de datos especificamente
 * una lista enlazada circular simple que puede contener cualquier tipo de dato
 * solamente definiciendolo mediante el template de esta clase. se puede agregar y borrar
 * el dato.
 *
 */
class CircularList :public IList<E>{
    Node<E> *head,*tail; /**< TODO */
    /**
     * @brief
     * Es un metodo interno de esta clase que permite obtener un nodo mediante su indice.
     * @param index el indice indicado que permite buscar el nodo, tiene que ser un numero
     * entero mayor o igual que cero y menor al largo de la lista.
     * @return Node<E> un puntero del nodo buscado, en caso de que el indice exista.
     */
    Node<E>* getNode(int);

public:
    /**
     * @brief
     * Es el constructor de la lista circular simple.
     */
    CircularList();
    /**
     * @brief
     * Agrega un elemento al principio de la lista.
     *
     * @param data el elemento a agregar
     */
    void addi(E);
    /**
     * @brief
     * Agregar un elemento al final de la lista.
     * @param data el elemento a agregar
     */
    void add(E);
    /**
     * @brief
     * Agrega el elemento en el indice indicado. Si el indice es incorrecto no se agrega el
     * elemento.
     *
     * @param dato el elemento a agregar
     * @param index el indice que indica el lugar donde se agregara
     * @return si el elemento se agrega retorna true, en caso contrario retorna false
     */
    bool add(E,int);
    /**
     * @brief
     * Remueve el dato en la posicion indicada por el parametro, en caso que el indice
     * indicado sea incorrecto, osea que sea menor que cero o mayor o igual que
     * el largo de la lista no alterara la lista.
     *
     * @param index la posicion indicada del objeto a borrar
     * @return true si borra algo, false si el indice indicado es incorrecto
     */
    bool remove(int);
    /**
     * @brief
     * Setea el valor del dato que se encuentre en el indice citado con un nuevo valor.
     * @param int el indice en el que se encuetra el dato
     * @param E el dato por el que se cambiara
     */
    void set(int,E);
    /**
     * @brief
     * Obtiene un dato el la posicion indicada.
     * En caso que el indice indicado sea incorrecto, osea que sea menor que cero o
     * mayor o igual que el largo de la lista arrojara un error pues el dato esta fuera
     * de los limites de la lista.
     *
     * @param index el indice indicado
     * @return E el dato buscado por el indice indicado
     * @throw indexoutbounds fuera de rango
     */
    E get(int);
    /**
     * @brief
     * Obtiene una instancia de un nuevo iterador de esta lista, y pueden obtenerse
     * cuantas sean necesarias. pero es responsabilidad del programador eliminar mediante
     * la palabra reservada delete.
     * @return IIterator<E> un puntero de0l iterador indicado
     */
    IIterator<E>* getIterator();
    //virtual setComparator(IComparator) = 0;
    //virtual IComparator getComparator() = 0;

    /**
     * @brief
     * Es el destructor de la lista.
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



template <class E> Node<E>* CircularList<E>::getNode(int index){
    Node<E> *actualNode = head;
    for (int from = 0; from <index; from++){
        actualNode = actualNode->getNext();
    }
    return actualNode;
}

template <class E> void CircularList<E>::addi(E data){
        if(head == null){
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

template <class E> void CircularList<E>::add(E data){
        if (head == null){
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

template <class E> void CircularList<E>::set(int index,E data){
        if (0 <= index && index < this->lenght){
            getNode(index)->setData(data);
        }
        else{
            std::cerr << "index out bounds";
            throw index;

        }
}

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


template <class E> CircularList<E>::~CircularList(){
    Node<E> *actualNode = head;
    std::cout << "Deleting CircularList...\n";
    while(head){
        actualNode = head;
        head = head->getNext();
        delete actualNode;
        this->lenght--;
    }
    std::cout << "CircularList deleted!\n";
}

template <class E> CircularList<E>::CircularList() {
    tail = null;
    head = null;
    this->lenght = 0;
}

//===========================================================================
//========================= END OF IMPLEMENTATION ===========================
//===========================================================================

#endif // CIRCULARLIST_H
