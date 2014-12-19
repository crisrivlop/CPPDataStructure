#include "Node.h"
#ifndef IITERATOR_H
#define IITERATOR_H
template <class E>

/**
 * @brief Es una interfaz para los iteradores hijos de este.
 *
 */
class IIterator{
public:

    /**
     * @brief Obtiene el dato actual y actualiza al nodo siguiente.
     * @return E el dato actual
     * @throw donthavenext si el dato actual es nulo
     */
    virtual E getNext()=0;

    /**
     * @brief Obtiene el dato actual
     * @return E el dato actual
     * @throw donthavenext si el dato actual es nulo
     */
    virtual E getCurrent() const =0;

    /**
     * @brief Verifica si tiene siguiente
     *
     * @return true si tiene siguiente, false si no lo tiene
     * @throw donthavenext si el dato actual es nulo
     */
    virtual bool hasNext() const =0;
    /**
     * @brief Liberador de memoria
     */
    virtual ~IIterator(){}

};
#endif // IITERATOR_H
