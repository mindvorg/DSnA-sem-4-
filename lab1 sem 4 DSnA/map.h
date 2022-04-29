#pragma once
#ifndef Map_H
#include <iostream>
#include"RBTree.h"
#include"List.h"
template<class Key,class Value>
class Map {
private:
	RBTree<Key, Value>* tree;
public:
		Map()
	{	
		tree = new RBTree<Key, Value>();
	};
	void insert(Key key, Value val){tree->insert(key, val);	}
	void remove(Key key) { tree->deleteElement(key); }
	void clear() { delete tree; tree = new RBTree<Key, Value>(); }
	void print() {
		if (tree->root == tree->nill) { cout << "map is empty"; }
		else { tree->printtree(); }
	}
	Value find(Key key) {
			return tree->getData(key);
		}
	List<Key>* getkeys()
	{
		List<Key>* list = tree->getKeys();
		return list;
	}
	List<Value>* getValues()
	{
		List<Value>* list = tree->getValues();
		return list;
	}
};
#endif // !Map_H
