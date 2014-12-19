#include "iostream"
#include "BinaryNode.h"
using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class E>
/**
 * @brief
 *
 */
class BinaryTree{
    BinaryNode<E> *root;
    bool addedNode;
    /**
     * @brief add
     * @param data
     * @param pRoot
     * @return
     */
    BinaryNode<E> *add(E data, BinaryNode<E> *pRoot);
    /**
     * @brief getGreatest
     * @param pRoot
     * @return
     */
    BinaryNode<E> *getGreatest(BinaryNode<E> *pRoot);
    /**
     * @brief getLowest
     * @param pRoot
     * @return
     */
    BinaryNode<E> *getLowest(BinaryNode<E> *pRoot);
public:
    /**
     * @brief
     *
     */
    BinaryTree();
    /**
     * @brief
     *
     * @param data
     * @return bool
     */
    bool add(E data);
    /**
     * @brief
     *
     * @param data
     */
    E search(E data);
    /**
     * @brief
     *
     * @param data
     * @return bool
     */
    bool remove(E data);
    /**
     * @brief print
     */
    void print()const;

    /**
     * @brief
     *
     */
    virtual ~BinaryTree();
};

template <class E>
BinaryNode<E> *BinaryTree<E>::add(E data, BinaryNode<E> *pRoot){
    if (!pRoot){
        pRoot = new BinaryNode<E>(data);
        addedNode = true;
        return pRoot;
    }
    else if (pRoot->getData() < data){
        pRoot->setRight(add(data,pRoot->getRight()));
        return pRoot;
    }
    else if (data < pRoot->getData()){
        pRoot->setLeft(add(data,pRoot->getLeft()));
        return pRoot;
    }
    else{
        return Null;
    }

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
void BinaryTree<E>::print() const{
    cout << "hello world" << endl;
    if (root){
        cout << root->getData() << endl;
        cout << root->getLeft()->getData() << ";" ;
        cout << root->getRight()->getData() << endl ;
    }
    else {
        cout << "root no existe" << endl;
    }

}

template <class E>
BinaryTree<E>::~BinaryTree(){

}


#endif // BINARYTREE_H



