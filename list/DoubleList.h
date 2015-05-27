#include "IList.h"
#include "DoubleNode.h"
#include "DoubleIterator.h"
#include "InverseIterator.h"
#include "iostream"
#ifndef UDOUBLELIST_H
#define UDOUBLELIST_H

template <class E>
/**
 * @brief
 * Esta clase es una estructura de datos especificamente
 * una lista doblemente enlazada que puede contener cualquier tipo de dato
 * solamente definiciendolo mediante el template de esta clase. se puede agregar y borrar
 * el dato.
 *
 */
class UDoubleList : public IList<E>
{

    DoubleNode<E> *head; /**< TODO */
    DoubleNode<E> *tail; /**< TODO */
    bool inverseIterate;
    /**
     * @brief
     * Es un metodo interno de esta clase que permite obtener un nodo mediante su indice.
     * @param index el indice indicado que permite buscar el nodo, tiene que ser un numero
     * entero mayor o igual que cero y menor al largo de la lista.
     * @return Node<E> un puntero del nodo buscado, en caso de que el indice exista.
     */
    DoubleNode<E>* getNode(int);

public:
    /**
     * @brief
     * Es el constructor de la lista doble.
     */
    UDoubleList();
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
     * @param data el elemento a agregar
     * @param index el indice que indica el lugar donde se agragegara
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
     * @param index el indice en el que se encuetra el dato
     * @param data el dato por el que se cambiara
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
     * @return data el dato buscado por el indice indicado
     * @throw indexoutbounds fuera de rango si index es menor que cero o index es mayor
     * o igual que el largo de la lista
     */
    E get(int);

    /**
     * @brief
     * Obtiene una instancia de un nuevo iterador de esta lista, y pueden obtenerse
     * cuantas sean necesarias. pero es responsabilidad del programador eliminar mediante
     * la palabra reservada delete. Ademas este puede ser un iterador inverso o normal, eso
     * quiere decir que el iterador puede recorrer la lista al reves o al derecho
     * respectivamente a los iteradores anteriormente citados. El tipo de iterador
     * puede ser señalado con la funcion @link DoubleCircularList::inverseIteration(bool)
     * @return IIterator<E> un puntero del iterador indicado
     */
    IIterator<E>* getIterator();

    /**
     * @brief
     * Decide si el iterador es inverso o normal.
     * @param si es true el iterador sera inverso, false es un iterador normal
     */
    void inverseIteration(bool);

    /**
     * @brief
     * Es el destructor de la lista.
     */
    virtual ~UDoubleList();
};

template <class E> DoubleNode<E>* UDoubleList<E>::getNode(int index){
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


template <class E> UDoubleList<E>::UDoubleList(){
    tail = null;
    head = null;
    this->lenght = 0;
    inverseIterate = false;
}


template <class E> void UDoubleList<E>::addi(E data){
    if(head == null){
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


template <class E> void UDoubleList<E>::add(E data){
    if (tail == null){
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


template <class E> bool UDoubleList<E>::add(E data,int index){
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

template <class E> bool UDoubleList<E>::remove(int index){
    if (0 <= index && index < this->lenght){
        if(this->lenght == 1){
            delete head;
            head = 0;
            tail = 0;
        }
        else if (index == 0){
            DoubleNode<E> *deleteNode = head;
            head = head->getNext();
            head->setPrevious(null);
            delete deleteNode;
        }
        else if (this->lenght-1 == index){
            DoubleNode<E> *deleteNode = tail;
            tail = tail->getPrevious();
            tail->setNext(null);
            deleteNode->setPrevious(null);
            delete deleteNode;
        }
        else{
            DoubleNode<E> *previousNode = getNode(index-1);
            DoubleNode<E> *deleteNode = previousNode->getNext();
            previousNode->setNext(deleteNode->getNext());
            deleteNode->getNext()->setPrevious(previousNode);
            deleteNode->setNext(null);
            deleteNode->setPrevious(null);
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



template <class E> void UDoubleList<E>::set(int index,E data){
    if (0 <= index && index < this->lenght){
        getNode(index)->setData(data);
    }
    else{
        std::cerr << "index out bounds";
        throw index;
    }
}


template <class E> E UDoubleList<E>::get(int index){
    if (0 <= index && index < this->lenght){
        return getNode(index)->getData();
    }
    else{
        std::cerr << "index out bounds\n";
        throw index;
    }
}

template <class E> IIterator<E>* UDoubleList<E>::getIterator()
{
    IIterator<E> *iterator;
    if(inverseIterate)iterator = new InverseIterator<E>(head, tail);
    else iterator = new DoubleIterator<E>(head,tail);
    return iterator;
}
template <class E> void UDoubleList<E>::inverseIteration(bool inverse){
    inverseIterate = inverse;
}


template <class E> UDoubleList<E>::~UDoubleList(){
    DoubleNode<E> *actualNode = head;
    std::cout << "Deleting DoubleList...\n";
    while(head){
        actualNode = head;
        head = head->getNext();
        delete actualNode;
        this->lenght--;
    }
    std::cout << "DoubleList deleted!\n";
}
#endif // UDOUBLELIST_H
