#ifndef BTREE_H
#define BTREE_H
#include "BNode.h"
#include <iostream>

using namespace std;

template <typename K>
class BTree{
	friend class ostream;
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
	void print();
	K search(K pData) const;
    virtual ~BTree();
};


template <typename K> BTree<K>::BTree(int pLeghtKeys):_lenghtKeys(pLeghtKeys), _explotion(false){
	_root = new BNode<K>(pLeghtKeys);
}

template <typename K> void BTree<K>::insert(K pData){
	_explotion = false;
	_root = insert(pData,_root);
	if(_explotion){
		BNode<K> *tmpRoot = new BNode<K>(_lenghtKeys);
		_root = explode(pData,tmpRoot,_root);
	}
}
template <typename K> BNode<K>* BTree<K>::insert(K pData,BNode<K> *pRoot){
	if (pRoot->isLeaf()){
		if (pRoot->isExploding())_explotion = true;
		pRoot->addValue(pData);
		return pRoot;
	}
	else{
		BNode<K> *element;
		if (pData < pRoot->getValues()[0]){
			element = insert(pData,&pRoot->getChilds()[0]);
		}
		else{
			K *value = pRoot->getValues();
			int index;
			for(index = 0; (index < pRoot->getCurrentLenghtData()) && value[index] < pData;index++){}
			element = insert(pData,&pRoot->getChilds()[index+1]);
		}
		if (_explotion){
			cout << "explosion time" << endl;
			pRoot = explode(pData,pRoot,element);
		}

		return pRoot;
	}
}

template <typename K> BNode<K>* BTree<K>::explode(K pData,BNode<K> *pRoot, BNode<K> *pChild){
	K *currentValues,initialNodeValue;
	BNode<K> *left,*right;
	currentValues = pChild->getValues();
	int x=0;
	left = new BNode<K>(_lenghtKeys);
	for (; x < pChild->getCurrentLenghtData()/2;x++)left->addValue(currentValues[x]);
	initialNodeValue = currentValues[x++];
	right = new BNode<K>(_lenghtKeys);
	for(;x < pChild->getCurrentLenghtData();x++)right->addValue(currentValues[x]);
	cout << "left: ";
	left->print();
	cout << endl << "right: ";
	right->print();
	cout << endl;
	pRoot->addValue(initialNodeValue);
	pRoot->setLeftChild(left,initialNodeValue);
	pRoot->setRightChild(right,initialNodeValue);
	if (!pRoot->isExploding())_explotion = false;
	if (!pChild->isLeaf()){
		// agregar hijos
	}
	return pRoot;
}

template <typename K> void BTree<K>::print(){
	cout << "=========================="<< endl;
	print(_root, true);
	cout << endl <<"=========================="<< endl;
}
template <typename K> void BTree<K>::print(BNode<K>* pRoot,bool nextLevel){
	if (pRoot){
		pRoot->print();
		if (nextLevel){cout << endl;}
		for(int x = 0; x < pRoot->getLenghtOfChilds();x++){
			print(&pRoot->getChilds()[x], false);
			cout << " ";
		}
	}
	else{
        cout << "--" << endl;
	}
}

template <typename K> ostream& operator<<(ostream &o,BTree<K> &pTree){
	//o << pTree._root;
	return o;
}

template <typename K> BTree<K>::~BTree(){
    delete _root;
    cout << "im deleting"<<endl;
}


#endif // BTREE_H
