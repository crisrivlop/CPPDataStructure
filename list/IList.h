#include "IIterator.h"

#define null 0

#ifndef ILIST_H
#define ILIST_H

template <class E>
/**
 * @brief Es la interfaz de las listas.
 *
 */
class IList
{
protected:
    int lenght; /**< TODO */ /**< TODO */
public:

    /**
     * @brief
     * Agrega un elemento al principio de la lista.
     *
     * @param data el elemento a agregar
     */
    virtual void addi(E) = 0;

    /**
     * @brief
     * Agregar un elemento al final de la lista.
     * @param data el elemento a agregar
     */
    virtual void add(E) = 0;

    /**
     * @brief
     * Agrega el elemento en el indice indicado. Si el indice es incorrecto no se agrega el
     * elemento.
     *
     * @param data el elemento a agregar
     * @param index el indice que indica el lugar donde se agragegara
     * @return si el elemento se agrega retorna true, en caso contrario retorna false
     */
    virtual bool add(E,int) = 0;

    /**
     * @brief
     * Remueve el dato en la posicion indicada por el parametro, en caso que el indice
     * indicado sea incorrecto, osea que sea menor que cero o mayor o igual que
     * el largo de la lista no alterara la lista.
     *
     * @param index la posicion indicada del objeto a borrar
     * @return true si borra algo, false si el indice indicado es incorrecto
     */
    virtual bool remove(int) = 0;

    /**
     * @brief
     * Setea el valor del dato que se encuentre en el indice citado con un nuevo valor.
     * @param index el indice en el que se encuetra el dato
     * @param data el dato por el que se cambiara
     */
    virtual void set(int,E) = 0;

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
    virtual E get(int) = 0;

    /**
     * @brief Obtiene el largo de la lista
     * @return lenght el largo de la lista
     */
    int getLenght() const;
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
    virtual IIterator<E>* getIterator() = 0;

    /**
     * @brief Verifica si la lista esta vacia
     *
     * @return true si la lista esta vacia
     */
    bool isEmpty() const;

    /**
     * @brief Liberador de memoria
     */
    virtual ~IList(){}
};


template <class E> int IList<E>:: getLenght() const{return lenght;}

template <class E> bool IList<E>:: isEmpty() const {return lenght == 0;}
#endif // ILIST_H
