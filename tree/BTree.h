#include <iostream>
#ifndef BTREE_H
#define BTREE_H
#include "BNode.h"

using namespace std;

template <typename K>
class BTree{
	BNode<K> * _root;
	int _lenghtKeys;
	bool _explotion;
	BNode<K>* searchNode(K pData) const;
	BNode<K>* insert(K pData, BNode<K>* pRoot);
	BNode<K>* explode(K pData, BNode<K>* pRoot, BNode<K>* pChild);
    void print(BNode<K>* pRoot, string taber);
public:
	BTree(int pLenghtKeys);
    void insert(K pData);
	bool remove(K pData);
	K search(K pData) const;
    void print();
    virtual ~BTree();
};


template <typename K> BTree<K>::BTree(int pLenghtKeys):_lenghtKeys(pLenghtKeys)
{
    _root = Null;
}

template <typename K> void BTree<K>::insert(K pData){
    _explotion = false;
    if (_root){
        _root = insert(pData,_root);
    }
    else{
        _root = new BNode<K>(_lenghtKeys,pData);
    }
}


template <typename K> BNode<K> *BTree<K>::insert(K pData, BNode<K> *pRoot){
    //BTree<K> *returnedData = Null;
    if (pRoot->isLeaf()){
        if(pRoot->oneToExploding()){
            pRoot->addValue(pData);
            _explotion = true;
            pRoot->explode();
            return pRoot;
        }
        pRoot->addValue(pData);
    }
    else{
        int x = 0;
        if (pData < pRoot->getValue(x)){
            BNode<K> *tmp = insert(pData, pRoot->getChild(x));
            if (_explotion){
                pRoot->adoptExploitedNode(tmp,0);
                delete tmp;
            }
        }

        for (x=0; x < pRoot->getValues()->getCurrentLenght() && pData > pRoot->getValue(x); x++);
        BNode<K> *tmp = insert(pData, pRoot->getChild(x));
        if (_explotion){
            cout << "llave de insercion: " << pData << endl;
            pRoot->adoptExploitedNode(tmp,x);
            cout << "aun no hay problemas"<< endl;
            delete tmp;
        }
        if (pRoot->isFull())pRoot->explode();
        else _explotion = false;
    }
    return pRoot;

    /**
    if (pRoot->isExploding()){
        //explota pRoot, existen dos casos que pRoot sea un nodo hoja o que no lo sea
    }
    **/
}

template <typename K> void BTree<K>::print(BNode<K> *pRoot, string taber)
{
    if (pRoot){
        taber = "-" + taber;
        pRoot->print();
        if (!pRoot->isLeaf()){
            BArray< BNode<K>* > *array = pRoot->getChilds();
            for (int x=0; x < array->getCurrentLenght(); x++){
                cout << taber  << x << ":";
                if (array->getValue(x))print(array->getValue(x), taber + "-");
                else cout << "*" << endl;
            }
        }
    }
    else cout << taber << "null" << endl;

}



template <typename K> void BTree<K>::print(){
/*
    cout << "root: ";
    _root->print();
    if (!_root->isLeaf()){
        BArray< BNode<K>* > *array = _root->getChilds();
        cout << "cantidad de hijos: " << array->getCurrentLenght() << endl;
        cout << "cantidad maxima de hijos: " << array->getMaximunLenght() << endl;
        for (int x=0; x < array->getCurrentLenght(); x++){
            cout << "child number " << x << ": ";
            array->getValue(x)->print();


        }
    }

    */
    print(_root,"-");
}

template <typename K> BTree<K>::~BTree(){
    delete _root;
}


#endif // BTREE_H
