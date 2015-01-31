#ifndef BTREE_H
#define BTREE_H
#include "BNode.h"

template <typename K>
class BTree{
	BNode<K> * _root;
	int _lenghtKeys;
	bool _explotion;
	BNode<K>* searchNode(K pData) const;
	BNode<K>* insert(K pData, BNode<K>* pRoot);
	BNode<K>* explode(K pData, BNode<K>* pRoot, BNode<K>* pChild);
	void print(BNode<K>* pRoot, bool nextLevel);
public:
	BTree(int pLenghtKeys);
    void insert(K pData);
	bool remove(K pData);
	K search(K pData) const;
    virtual ~BTree();
};


template <typename K> void BTree<K>::insert(K pData){
    if (_root){
        _root = insert(pData,_root);
    }
    else{
        _root = new BNode<K>(_lenghtKeys,pData);
    }
}




#endif // BTREE_H
