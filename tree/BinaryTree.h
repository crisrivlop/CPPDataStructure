#include "iostream"
#include "BinaryNode.h"
using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class E>
/**
 * @brief
 * Clase Arbol Binario.
 * Esta clase representa a la estructura de datos arbol binario, valga la rendondancia.
 * Esta estructura de datos puede insertar, eliminar y buscar los datos relacionados con esta
 * la misma. Usa platillas para almacenar diversos datos. Usa los operadores de comparacion
 * como <, >, ==, >=, <= y !=.
 *
 */
class BinaryTree{
    BinaryNode<E> *root;
    bool addedNode;
    bool deletedNode;
    /**
     * @brief Agrega datos utilizando el mismo metodo recursivamente,
     * de esta manera explora el arbol sin verificar muchas veces pues la recursividad es muy
     * explotable en esta estructura de datos.
     * @param data el dato a insertar.
     * @param pRoot el nodo en que se explora la opcion de insertar el dato.
     * @return se retorna pRoot.
     */
    BinaryNode<E> *add(E data, BinaryNode<E> *pRoot);
    /**
     * @brief Extrae el dato Mayor de los menores, eso quiere decir que el mayor de los menores
     * se desprende de el arbol y su unico hijo es heredado a su padre.
     * @param pRoot El nodo del que se quiere consegir el mayor de los menores.
     * @return El nodo desprendido de la jerarquia de nodos.
     */
    BinaryNode<E> *extractGreatestOfLowest(BinaryNode<E> *pRoot);
    /**
     * @brief Extrae el dato menor de los mayores, eso quiere decir que el menor de los mayores
     * se desprende de el arbol y su unico hijo es heredado a su padre.
     * @param pRoot El nodo del que se quiere consegir el mayor de los menores.
     * @return El nodo desprendido de la jerarquia de nodos.
     */
    BinaryNode<E> *extractLowestOfGreatest(BinaryNode<E> *pRoot);

    /**
     * @brief Imprime el arbol utilizando la recursividad. Mientras el nivel del nodo se inferior
     * la tabulacion en su impresion es mayor.
     * @param pNode el nodo con el que se esta tratando.
     * @param tab es una tabulacion que ayuda a identificar la gerarquia de nodos.
     */
    void print(BinaryNode<E> *pNode,string tab) const;
    /**
     * @brief Remueve un dato, utilizando la recursividad como fuerte.
     * @param data el dato a remover
     * @param pRoot el nodo a explorar.
     * @return retorna pRoot.
     */
    BinaryNode<E> *remove(E data, BinaryNode<E> *pRoot);

public:
    /**
     * @brief Inicializa un arbol binario.
     *
     */
    BinaryTree();
    /**
     * @brief Agrega un dato al arbol binario, si el dato ya existe no lo inserta.
     *
     * @param data el dato a insertar.
     * @return true, si el dato ha sido insertado, false en caso constrario.
     */
    bool add(E data);
    /**
     * @brief
     * Busca un dato en el arbol. Si el dato no se encuentra en el arbol arroja un error, en este
     * caso el mismo arbol.
     * @param data el dato a buscar.
     * @return el dato buscado.
     * @throw const BinaryTree<E>*
     */
    E search(E data)const;
    /**
     * @brief Remueve un dato en el arbol, en caso de no existir no pasa nada.
     *
     * @param data el dato a borrar.
     * @return true si el dato se borro(si existia), false si no existia.
     */
    bool remove(E data);
    /**
     * @brief imprime el arbol.
     */
    void print()const;

    /**
     * @brief
     * Libera la memoria ocupada por el arbol borrando la raiz del arbol. La raiz libera la memoria
     * de los nodos hijos y estos sus nodos hijos, y asi consecutivamente, de esta manera se usa
     * la recursividad para liberar memoria.
     */
    virtual ~BinaryTree();
};

template <class E>
BinaryNode<E> *BinaryTree<E>::add(E data, BinaryNode<E> *pRoot){
    if (!pRoot){
        pRoot = new BinaryNode<E>(data);
        addedNode = true;
    }
    else if (pRoot->getData() < data){
        pRoot->setRight(add(data,pRoot->getRight()));
    }
    else if (data < pRoot->getData()){
        pRoot->setLeft(add(data,pRoot->getLeft()));
    }
    return pRoot;
}


template <class E>
BinaryNode<E> *BinaryTree<E>::extractGreatestOfLowest(BinaryNode<E> *pRoot)
{
    BinaryNode<E> *current = pRoot->getLeft();
    if (current->getRight()){
        do{pRoot = current;current = current->getRight();}
        while (current->getRight());
        pRoot->setRight(current->getLeft());
    }
    else {
        pRoot->setLeft(current->getLeft());
    }
    pRoot = current;
    return pRoot;
}


template <class E>
BinaryNode<E> *BinaryTree<E>::extractLowestOfGreatest(BinaryNode<E> *pRoot)
{
    BinaryNode<E> *current = pRoot->getRight();
    if (current->getLeft()){
        do{pRoot = current;current = current->getLeft();}
        while (current->getLeft());
        pRoot->setLeft(current->getRight());
    }
    else {
        pRoot->setRight(current->getRight());
    }
    pRoot = current;
    pRoot->setLeft(Null);
    pRoot->setRight(Null);
    return pRoot;
}

template <class E>
BinaryTree<E>::BinaryTree()
{
    root = Null;
    addedNode = false;
}

template <class E>
bool BinaryTree<E>::add(E data)
{
    addedNode = false;
    root = add(data,root);
    return addedNode;
}

template <class E>
E BinaryTree<E>::search(E data)const{
    BinaryNode<E> *current = root;
    while (current){
        if (data < current->getData())current = current->getLeft();
        else if(data > current->getData())current = current->getRight();
        else{
            return current->getData();
        }
    }
    throw this;
}

template <class E>
bool BinaryTree<E>::remove(E data)
{
    deletedNode = false;
    root = remove(data,root);
    return deletedNode;
}

template <class E>
void BinaryTree<E>::print() const{
    if (root){
        cout << "root-data:{"<<root->getData()<< "}"<< endl;
        cout << " right-";
        print(this->root->getRight(),"  ");
        cout << " left-";
        print(this->root->getLeft(),"  ");
        cout << endl;
    }
    else{
        cout << "the tree is empty!"<< endl;
    }
}


template <class E>
void BinaryTree<E>::print(BinaryNode<E> *pNode,string tab) const{
    if (pNode){
        E print = pNode->getData();
        cout <<"data:{" << print << "}" << endl;
        cout << tab <<"  right-";
        this->print(pNode->getRight(),tab + "  ");
        cout << tab <<"  left-";
        this->print(pNode->getLeft(), tab + "  ");
    }
    else cout << "data: null" << endl;

}

template <class E>
BinaryNode<E> *BinaryTree<E>::remove(E data, BinaryNode<E> *pRoot)
{
    if (!pRoot)return pRoot;
    else if (data > pRoot->getData()){
        pRoot->setRight(this->remove(data,pRoot->getRight()));
        return pRoot;
    }
    else if (data < pRoot->getData()){
        pRoot->setLeft(this->remove(data,pRoot->getLeft()));
        return pRoot;
    }
    deletedNode = true;
    BinaryNode<E> *current = Null;
    if (pRoot->getLeft())current = this->extractGreatestOfLowest(pRoot);
    else if (pRoot->getRight())current = this->extractLowestOfGreatest(pRoot);
    if (current){
        current->setLeft(pRoot->getLeft());
        current->setRight(pRoot->getRight());
    }
    pRoot->setLeft(Null);
    pRoot->setRight(Null);
    delete pRoot;
    return current;
}

template <class E>
BinaryTree<E>::~BinaryTree(){
    delete root;
    root = Null;
}

#endif // BINARYTREE_H



