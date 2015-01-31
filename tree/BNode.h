#include <iostream>
#include "BArray.h"
#ifndef BNODE_H
#define BNODE_H

using namespace std;

template <typename VALUE>
/**
 * Clase BNode. representa un nodo del arbol B, es una de las hojas o ramas del mismo
 * contiene una lista de datos ordenados.
 */
class BNode{
    BArray<VALUE> _keys;
    BArray< BNode<VALUE> > *_childs;
public:
    /**
     * El construtor de BNode es elegante, pues agrega el valor inicial al arreglo de datos,
     * la misma inicializa la cantidad de datos que contendra.
     * @param pSize el largo del arreglo que contendra los datos,
     * en otras palabras el limite de datos que contiene el nodo, si el dato es menor o igual a tres.
     * se colocara un tres por defecto
     * @param pInitialValue el valor inicial que se contendrá en el arreglo.
     */
    BNode(int pSize,VALUE pInitialValue);

    /**
     * @brief El construtor de BNode, inicializa la cantidad de datos que contendra.
     * @param pSize el largo del arreglo que contendra los datos,
     * en otras palabras el limite de datos que contiene el nodo, si el dato es menor o igual a tres.
     * se colocara un tres por defecto
     */
    BNode(int pSize);

    /**
     * @brief Obtiene el puntero hacia los valores contenidos sin realizar cambios en el nodo.
     *
     * @return VALUE el arreglo de valores del nodo.
     */
    BArray<VALUE>& getValues() const;

    /**
     * @brief obtiene el puntero del arreglo de los nodos hijos de este nodo. si retorna un puntero nulo
     * entonce significa que nodo es hoja
     *
     * @return BNode<VALUE> el puntero al array de nodos siguientes.
     */
    BArray< BNode<VALUE> >* getChilds() const;

    /**
     * @brief getChild
     * @param pIndex
     * @return
     */
    BNode<VALUE>* getChild(int pIndex) const;

    /**
     * @brief agrega en orden el valor en el array, en caso que la lista este llena no insertara el valor
     *
     * @param pValue
     * @return true, si el valor se inserto correctamente y la lista no este llena
     */
    bool addValue(VALUE pValue);

    /**
     * @brief Retorna si el nodo tiene un estado de explosion.
     * retorna si la cantidad de datos es igual al limite impuesto en el constructor.
     *
     * @return true si el nodo esta explotando, false si no.
     */
    bool isExploding() const;


    /**
     * @brief explode, genera los hijos del nodos los inserta y ademas retorna la raiz del sub arbol
     * generado con sus dos hijos
     * @return
     */
    BNode<VALUE>& explode();

    /**
     * @brief isLeaf
     * @return
     */
    bool isLeaf() const;

    /**
     * @brief ~BNode
     * Liberador de memoria
     */
    virtual ~BNode();
};

template <typename VALUE> BNode<VALUE>::BNode(int pSize,VALUE pInitialValue):
    _keys(pSize),_childs(pSize+1)
{
    if (pSize < 3)throw this;
    _keys.add(pInitialValue);
}

template <typename VALUE> BNode<VALUE>::BNode(int pSize): _keys(pSize),_childs(pSize+1)
{
    if (pSize < 3)throw pSize;
}

template <typename VALUE> BArray<VALUE>& BNode<VALUE>::getValues() const{
    return _keys;
}

template <typename VALUE> BArray< BNode<VALUE> >* BNode<VALUE>::getChilds() const{
    return _childs;
}

template <typename VALUE> BNode<VALUE>* BNode<VALUE>::getChild(int pIndex) const{
    if (0 <= pIndex && pIndex < _childs.getCurrentLenght()) throw this;
    return &_childs.getValue(pIndex);
}


template <typename VALUE> bool BNode<VALUE>::isExploding() const
{
    return _keys.isFull();
}

template <typename VALUE> BNode<VALUE>& BNode<VALUE>::explode()
{
    //crear el hijo izquierdo
    //crear el hijo derecho
    //crear el nodo central y retornar la referencia
}

template <typename VALUE> bool BNode<VALUE>::isLeaf() const
{
    return _childs.getCurrentLenght() == 0;
}
#endif // BNODE_H


