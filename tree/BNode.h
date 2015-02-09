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
    BArray<VALUE> *_keys;
    BArray< BNode<VALUE>* > *_childs;
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

    BNode();

    BNode(const BNode&);

    /**
     * @brief Obtiene el puntero hacia los valores contenidos sin realizar cambios en el nodo.
     *
     * @return VALUE el arreglo de valores del nodo.
     */
    BArray<VALUE>* getValues() const;

    VALUE getValue(int pIndex) const;


    /**
     * @brief obtiene el puntero del arreglo de los nodos hijos de este nodo. si retorna un puntero nulo
     * entonce significa que nodo es hoja
     *
     * @return BNode<VALUE> el puntero al array de nodos siguientes.
     */
    BArray< BNode<VALUE>* >* getChilds() const;

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


    bool addChild(BNode<VALUE>* pChild);

    /**
     * @brief Retorna si el nodo tiene un estado de explosion.
     * retorna si la cantidad de datos es igual al limite impuesto en el constructor.
     *
     * @return true si el nodo esta explotando, false si no.
     */
    bool oneToExploding() const;

    bool isFull() const;


    /**
     * @brief explode, genera los hijos del nodos y los agrega a la lista de hijos
     * @return
     */
    void explode();

    void adoptExploitedNode(BNode<VALUE>*,int);


    /**
     * @brief isLeaf
     * @return
     */
    bool isLeaf() const;

    void print();
    /**
     * @brief ~BNode
     * Liberador de memoria
     */
    virtual ~BNode();
};

template <typename VALUE> BNode<VALUE>::BNode(int pSize,VALUE pInitialValue)
{
    if (pSize <= 3)throw this;
    _keys= new BArray<VALUE>(pSize);
    _keys->add(pInitialValue);
    _childs = Null;
}

template <typename VALUE> BNode<VALUE>::BNode(int pSize)
{
    if (pSize <= 3)throw pSize;
    _keys= new BArray<VALUE>(pSize);
    _childs = Null;
}

template <typename VALUE> BNode<VALUE>::BNode()
{
    _keys= new BArray<VALUE>(0);
    _childs = Null;
}

template <typename VALUE> BNode<VALUE>::BNode(const BNode &copy){
    _keys= new BArray<VALUE>(copy._keys);
    _childs = new BArray< BNode<VALUE>* >(copy._childs);
    cout << "copy called" << endl;
}

template <typename VALUE> BArray<VALUE>* BNode<VALUE>::getValues() const{
    return _keys;
}

template <typename VALUE> VALUE BNode<VALUE>::getValue(int pIndex) const{
    VALUE toReturn = _keys->getValue(pIndex);
    return toReturn;
}

template <typename VALUE> BArray< BNode<VALUE>* >* BNode<VALUE>::getChilds() const{
    return _childs;
}

template <typename VALUE> BNode<VALUE>* BNode<VALUE>::getChild(int pIndex) const{

    if (!_childs || 0 > pIndex || pIndex >= _childs->getCurrentLenght()) throw this;

    return _childs->getValue(pIndex);
}

template <typename VALUE> bool BNode<VALUE>::addValue(VALUE pValue)
{
    return _keys->add(pValue);
}

template <typename VALUE> bool BNode<VALUE>::addChild(BNode<VALUE> *pChild)
{
    return _childs->add(pChild);
}


template <typename VALUE> bool BNode<VALUE>::oneToExploding() const
{
    return _keys->getMaximunLenght() - _keys->getCurrentLenght() <= 1;
}

template <typename VALUE> bool BNode<VALUE>::isFull() const
{
    return _keys->isFull();
}

template <typename VALUE> void BNode<VALUE>::explode()
{
    //crear el hijo izquierdo
    //crear el hijo derecho
    //el nodo actual es el nodo padre de los nodos
    BNode<VALUE> *left= new BNode<VALUE>(_keys->getMaximunLenght());
    BNode<VALUE> *right= new BNode<VALUE>(_keys->getMaximunLenght());
    int x = 0;
    for(; x < (_keys->getCurrentLenght())/2;x++)left->addValue(_keys->getValue(x));
    VALUE nodeKey = _keys->getValue(x++);
    for(; x < _keys->getCurrentLenght();x++)right->addValue(_keys->getValue(x));
    _keys->reset();
    _keys->add(nodeKey);
    if (_childs){
        left->_childs = new BArray< BNode<VALUE>* >(_keys->getMaximunLenght()+2);
        right->_childs = new BArray< BNode<VALUE>* >(_keys->getMaximunLenght()+2);
        cout << "la cantidad de hijos que tiene son: " << _childs->getCurrentLenght() << endl;
        cout << "los imprimire"<< endl;
        cout << "[" << endl;
        for (int m = 0 ; m < _childs->getCurrentLenght(); m++){
            _childs->getValue(m)->print();
        }
        cout << "]" << endl;
        x=0;
        for(; x < left->getValues()->getCurrentLenght()+1;x++){
            left->_childs->add(x,_childs->getValue(x));
            //left->_childs->getValue(x)->print();
        }

        cout << "la cantidad de hijos que tiene left son: " << left->_childs->getCurrentLenght() << endl;
        cout << "los imprimire"<< endl;
        cout << "[" << endl;
        for (int m = 0 ; m < left->_childs->getCurrentLenght(); m++){
            left->_childs->getValue(m)->print();
        }
        cout << "]" << endl;

        int y = 0;
        for(; x < _childs->getCurrentLenght();x++){
            right->_childs->add(y++,_childs->getValue(x));
        }

        delete _childs;
    }
    _childs = new BArray< BNode<VALUE>* >(_keys->getMaximunLenght()+2);
    _childs->add(left);
    _childs->add(right);
}

template <typename VALUE> void BNode<VALUE>::adoptExploitedNode(BNode<VALUE> *pExploitedNode,int pIndexOfExploited)
{
    _keys->add(pExploitedNode->getValue(0));
    int x;
    for (x = 0; x < _keys->getCurrentLenght(); x++)if (_keys->getValue(x) == pExploitedNode->getValue(0))break;
    _childs->remove(pIndexOfExploited);
    _childs->add(x,pExploitedNode->getChild(1));
    _childs->add(x, pExploitedNode->getChild(0));
}

template <typename VALUE> bool BNode<VALUE>::isLeaf() const
{
    return !_childs;
}


template <typename VALUE> void BNode<VALUE>::print(){
    _keys->print();
}

template <typename VALUE> BNode<VALUE>::~BNode()
{
    delete _childs;
    delete _keys;
}
#endif // BNODE_H


