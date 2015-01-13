#define Null 0
#ifndef BINARYNODE_H
#define BINARYNODE_H


template <class E>
/**
 * @brief Esta clase es el elemento sustancial para los arboles binarios, contiene datos
 * y punteros a la derecha e izquierda para generar esa estructura de los arboles binarios
 *
 */
class BinaryNode{
    E data; /**< TODO */
    BinaryNode<E> *left,*right; /**< TODO */
public:
    /**
     * @brief Constructor, setea el dato que contiene el nodo y los punteros son punteros
     * nulos para evitar punteros colgados.
     *
     * @param data el dato que contendra el nodo
     */
    BinaryNode(E data);
    /**
     * @brief onstructor, setea el dato que contiene el nodo y los punteros son punteros
     * a la derecha e izquierda, se puede omiter el de la derecha y este se seteara como
     * nulo.
     *
     * @param data el dato que contendra el nodo
     * @param left el nodo de la izquierda
     * @param right el nodo de la derecha
     */
    BinaryNode(E data,BinaryNode<E> *left,BinaryNode<E> *right);

    /**
     * @brief Setea el dato que contiene el nodo.
     *
     * @param data el nuevo dato que contendra el nodo
     */
    void setData(E data);
    /**
     * @brief Setea el nodo de la izquierda.
     *
     * @param left el nuevo nodo de la izquierda
     */
    void setLeft(BinaryNode<E> *left);
    /**
     * @brief Setea el nodo de la derecha.
     *
     * @param right el nuevo nodo de la derecha.
     */
    void setRight(BinaryNode<E> *right);
    /**
     * @brief Obtiene el dato que contiene el nodo.
     *
     * @return E el dato contenido en el nodo.
     */
    E getData();
    /**
     * @brief Obtiene el nodo de la izquierda.
     *
     * @return BinaryNode<E> el nodo de la izquierda
     */
    BinaryNode<E> *getLeft();
    /**
     * @brief Obtiene el nodo de la derecha.
     *
     * @return BinaryNode<E> el nodo de la derecha
     */
    BinaryNode<E> *getRight();
    /**
     * @brief Liberador de memoria, libera la memoria que ocupa y la memoria que ocupan sus hijos.
     * si se desea borrar solo este nodo se debe setear los punteros de los hijos a Null o sea que
     * apunten a 0 en memoria.
     *
     */
    virtual ~BinaryNode();
};

template <class E>
BinaryNode<E>::BinaryNode(E data){
    this->data = data;
    this->left = Null;
    this->right = Null;
}

template <class E>
BinaryNode<E>::BinaryNode(E data, BinaryNode<E> *left, BinaryNode<E> *right){
    this->data = data;
    this->left = left;
    this->right = right;
}


template <class E>
void BinaryNode<E>::setData(E data){
    this->data = data;
}

template <class E>
void BinaryNode<E>::setLeft(BinaryNode<E> *left){
    this->left = left;
}

template <class E>
void BinaryNode<E>::setRight(BinaryNode<E> *right){
    this->right = right;
}

template <class E>
E BinaryNode<E>::getData(){
    return data;
}

template <class E>
BinaryNode<E> *BinaryNode<E>::getLeft(){
    return left;
}

template <class E>
BinaryNode<E> *BinaryNode<E>::getRight(){
    return right;
}
template <class E>
BinaryNode<E>::~BinaryNode(){
    delete left;
    delete right;
    left = Null;
    right=Null;
}


#endif // BINARYNODE_H
