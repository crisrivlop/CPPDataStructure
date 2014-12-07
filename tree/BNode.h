#include <iostream>
#ifndef BNODE_H
#define BNODE_H

using namespace std;

template <typename VALUE>
/**
 * Clase BNode. representa un nodo del arbol B, es una de las hojas o ramas del mismo
 * contiene una lista de datos ordenados.
 */
class BNode{
    VALUE *_keys;
    BNode<VALUE> *_childs;
    int _lenghtToExplode;
    int _lenghtData;
    int _lenghtChild;
    BNode();
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
    VALUE* getValues() const;

    /**
     * @brief obtiene el puntero del arreglo de los nodos hijos de este nodo. si retorna un puntero nulo
     * entonce significa que nodo es hoja
     *
     * @return BNode<VALUE> el puntero al array de nodos siguientes.
     */
    BNode<VALUE>* getChilds() const;

    /**
     * @brief agrega en orden el valor en el array, en caso que la lista este llena no insertara el valor
     *
     * @param pValue
     * @return true, si el valor se inserto correctamente
     */
    bool addValue(VALUE pValue);

    /**
     * @brief agregar un nodo hijo a la izquierda de la clave indicada por parametro pIndex
     * @param pChild el nodo a agregar como nodo hijo
     * @param pIndex el indice del valor al cual se le quiere dar un hijo izquierdo
     * @return true, si el nodo hijo ha sido insertado, false en el otro caso.
     */
    bool setLeftChild(BNode<VALUE> *pChild, VALUE pIndex);

    /**
     * @brief agregar un nodo hijo a la derecha de la clave indicada por parametro pIndex
     * @param pChild el nodo a agregar como nodo hijo
     * @param pIndex el indice del valor al cual se le quiere dar un hijo izquierdo
     * @return true, si el nodo hijo ha sido insertado, false en el otro caso.
     */
    bool setRightChild(BNode<VALUE> *pChild, VALUE pIndex);

    /**
     * @brief Retorna si el nodo tiene un estado de explosion.
     * retorna si la cantidad de datos es igual al limite impuesto en el constructor.
     *
     * @return true si el nodo esta explotando, false si no.
     */
    bool isExploding() const;

    bool isLeaf() const;
    /**
     * @brief Imprime el dato sin realizar cambios en el nodo.
     *
     */
    void print()const;

    int getLenghtToExplode()const;
    int getLenghtOfChilds()const;
    int getCurrentLenghtData()const;

    /**
     * @brief obtiene el valor maximo de las claves que contiene el nodo
     * @return el valor maximo que contiene el nodo
     */
    VALUE* getMaximumValue() const;

    /**
     * @brief obtiene el valor minimo de las claves que contiene el nodo
     * @return el valor minimo que contiene el nodo
     */
    VALUE* getMinimumValue() const;
    /**
     * @brief destructor
     *
     */
    virtual ~BNode();
};

template <typename VALUE> BNode<VALUE>::BNode(int pSize,VALUE pInitialValue):
		_lenghtData(1), _lenghtToExplode(pSize), _lenghtChild(0)
{
	if (pSize < 3){
		throw pSize;
		std::cerr << "el largo ingresado no es valido" << endl;
	}
    _keys = new VALUE[_lenghtToExplode];
    _keys[0] = pInitialValue;
    _childs = 0;
}

template <typename VALUE> BNode<VALUE>::BNode(int pSize):
		_lenghtToExplode(pSize)
{
	_lenghtChild= 0;
	_lenghtData = 0;
	if (pSize < 3){
			throw pSize;
			std::cerr << "el largo ingresado no es valido" << endl;
	}
	_keys = new VALUE[_lenghtToExplode];
	_childs = 0;
}

template <typename VALUE> BNode<VALUE>::BNode(): _lenghtToExplode(0){
	_lenghtChild= 0;
	_lenghtData = 0;
	_keys = 0;
	_childs = 0;
}

template <typename VALUE> VALUE* BNode<VALUE>::getValues() const{
    return _keys;
}

template <typename VALUE> BNode<VALUE>* BNode<VALUE>::getChilds() const{
    return _childs;
}

template <typename VALUE>  bool BNode<VALUE>::addValue(VALUE pValue){
	if (_lenghtData < _lenghtToExplode){
		int x;
		for (x = 0; x < _lenghtData && pValue >= _keys[x]; x++){}
		if (_keys[x] == pValue)return false;
		VALUE data;
		VALUE tmp = pValue;
		_lenghtData++;
		for(;x <_lenghtData; x++){
			data = _keys[x];
			_keys[x] = tmp;
			tmp = data;
		}
		return true;
	}
	return false;
}

template <typename VALUE> bool BNode<VALUE>::setLeftChild(BNode<VALUE>* pChild,VALUE pIndex){
	if (_lenghtChild == 0){
		_childs = new BNode<VALUE>[_lenghtToExplode+1];
		_childs->_lenghtToExplode = _lenghtToExplode;
		for (int x = 0; x < _lenghtToExplode+1; x++){
			(_childs[x])._keys = new VALUE[_lenghtToExplode];
		}
	}
	int x = 0;
	for (;x < _lenghtData; x++){
		if(pIndex == _keys[x]){
			_lenghtChild++;
			_childs[x] = *pChild;
			return true;
		}
	}
	return false;
}

template <typename VALUE> bool BNode<VALUE>::setRightChild(BNode<VALUE>* pChild,VALUE pIndex){
	if (_lenghtChild == 0){
		_childs = new BNode<VALUE>[_lenghtToExplode+1];
		_childs->_lenghtToExplode = _lenghtToExplode;
		for (int x = 0; x < _lenghtToExplode+1; x++){
			(_childs[x])._keys = new VALUE[_lenghtToExplode];
		}
	}
	int x = 0;
	for (;x < _lenghtData; x++){
		if(pIndex == _keys[x]){
			_lenghtChild++;
			_childs[x+1] = *pChild;
			return true;
		}
	}
	return false;
}

template <typename VALUE> bool BNode<VALUE>::isExploding() const{
    return _lenghtData >= _lenghtToExplode-1;
}

template <typename VALUE> bool BNode<VALUE>::isLeaf() const{
    return _lenghtChild == 0;
}

template <typename VALUE> void BNode<VALUE>::print() const {
	cout << "[";
    for (int x = 0; x < _lenghtData-1; x++){
        cout << _keys[x] << ",";
    }
    cout << _keys[_lenghtData-1] << "]";
}

template <typename VALUE> VALUE* BNode<VALUE>::getMaximumValue() const {
	if(_lenghtData > 0)return _keys[_lenghtData-1];
	return 0;
}

template <typename VALUE> VALUE* BNode<VALUE>::getMinimumValue() const{
	if(_lenghtData > 0)return _keys[0];
	return 0;
}

template <typename VALUE> int BNode<VALUE>::getCurrentLenghtData() const{
	return _lenghtData;
}

template <typename VALUE> int BNode<VALUE>::getLenghtToExplode() const{
	return _lenghtToExplode;
}

template <typename VALUE> int BNode<VALUE>::getLenghtOfChilds() const{
	return _lenghtChild;
}

template <typename VALUE> BNode<VALUE>::~BNode(){
    delete  [] _keys;
    if (_childs)delete  [] _childs;
    cout << "borrando un nodo x" << endl;
}

#endif // BNODE_H


