#pragma once
#ifndef RBTree_H
#include "Stack.h"
//#include"Iterator.h"
#include"List.h"
#include"Pair.h"
using namespace std;
template<class Key, class Value>
class RBTree
{
private:
	enum class Color { RED = 0, BLACK = 1 };
	class Elem
	{
	private:
		Elem* parent;
		Elem* left;
		Elem* right;
		Key* key;
		Value data;
		Color color;
	public:
		friend class RBTree;
		friend class TreeIterator;
		Elem(Key key, Value data) :Elem() {
			this->key = new Key[1];
			*this->key = key;
			this->data = data;
		}
		Elem() { left = NULL; right = NULL; parent = NULL; key = NULL; data = 0; color = Color::RED; }
		~Elem() { if (key != NULL) delete key; }
	};

public:
	Elem* root; Elem* nill;
	class TreeIterator
	{public:
		friend class RBtree;
		Stack<Elem*>* stack;
		Elem* cur;
		Elem* nill;
		TreeIterator(Elem* root, Elem* nill) { this->nill = nill; cur = root; stack = new Stack<Elem*>(); }
		~TreeIterator() { delete stack; }
		bool has_next() { return cur != nill; }
		Elem* next()
		{
			if (!has_next()) { throw out_of_range("no more elements"); }
			Elem* tmp = cur;
			if (cur-> right != nill) { stack->push(cur->right); }
			if (cur->left != nill) { cur = cur->left; }
			else {
				try { cur = stack->top(); stack->pop(); }
				catch (out_of_range) { cur = nill; }
			}
			return tmp;
		}
	};
	RBTree()
	{
		nill = new Elem();
		nill->color = Color::BLACK;
		root = nill;
	}
	~RBTree()
	{
			TreeIterator* newiterator;
			newiterator = createIterator();
			while (newiterator->has_next())
			{
				Elem* next = newiterator->next();
					delete next;
			}
			delete newiterator;
	}
	/*/~RBTree()
	{
		auto iterator = createIterator();
		while (iterator->has_next())
		{
			Elem* tmp = iterator->cur;
			iterator->next();
			delete tmp;
			delete nill;
		}
	}*/
	/*class RBTreeIterator : public Iterator<Pair<Key, Value>>
	{public:
		friend class RBTree;
		Stack<Elem*>* stack;
		Elem* cur;
		RBTreeIterator(Elem* root) { cur = root; stack = new Stack<Elem*>(); }
		~RBTreeIterator() { delete stack; }
		bool has_next() { return cur != NULL; }
		Pair<Key, Value> next()
		{
			Elem* tmp = cur;
			Pair<Key, Value> pair = makepair(*tmp->key, tmp->data);
			if (cur->right->key != NULL) { stack->push(cur->right); }
			if (cur->left->key != nullptr)
			{
				cur = cur->left;
			}
			else
			{
				if (!stack->empty())
				{
					cur = stack->top();
					stack->pop();
				}
				else
				{
					cur = NULL;
				}
			}

			return pair;
		}
	};*///закомичено до пиздеца (19:51)

	/*
	List<Value>* getValues()
	{
		List < Value>* values = new List<Key>();
		TreeIterator* iterator = createIterator();
		while (iterator->has_next())
		{
			Elem* next = iterator->next();
			Value value = next->data;
			values->pushBack(value);
		}
		delete iterator;
		return values;
	}
	*/

	void printtree() {
		TreeIterator* iterator = createIterator();
		while (iterator->has_next()) {
			Elem* next = iterator->next();
			cout << "Key is=" << *next->key << " and data is=" << next->data << endl;
		}
		delete iterator;
	}
	TreeIterator* createIterator()
	{
		return new TreeIterator(root, nill);
	}
	/*RBTreeIterator* createIterator()
	{
		return new RBTreeIterator(root);
	}*/
	void leftSwitch(Elem* x)
	{
		Elem* y = x->right;
		Elem* b = y->left;
		x->right = b;
		if (b != nill)
		{
			b->parent = x;
		}
		Elem* p = x->parent;
		y->parent = p;
		if (p == NULL) { root = y; }
		else if (x == p->left) { p->left = y; }
		else { p->right = y; }
		y->parent = x;
		x->parent = y;
	}
	void rightSwitch(Elem* x)
	{
		Elem* y = x->left;
		Elem* b = y->right;
		x->left = b;
		if (b != nill) { b->parent = x; }
		Elem* p = x->parent;
		y->parent = p;
		if (p == NULL) { root = y; }
		else if (x == p->right) { p->right = y; }
		else { p->left = y; }
		y->right = x;
		x->parent = y;
	}
	Elem* parentToInsert(Key key)
	{
		Elem* cur = root;
		if (key == *cur->key) return nill;
		while (1)
		{
			if (key > *cur->key) {
				if (cur->right != nill) {
					if (*cur->right->key == key) return nill;
					cur = cur->right;
				}
				else return cur;
			}
			else
			{
				if (cur->left != nill)
				{
					if (*cur->left->key == key) return nill;
					cur = cur->left;
				}
				else return cur;
			}
		}
	}

	void insert(Key key, Value val)
	{
		if (root == nill)
		{
			Elem* newElem = new Elem(key, val);
			root = newElem;
			root->color = Color::BLACK;
			newElem->left = nill;
			newElem->right = nill;
		}
		else
		{
			Elem* parentElem = parentToInsert(key);
			if (parentElem != nill)
			{
				Elem* newElem = new Elem(key, val);
				if (key < *parentElem->key)
					parentElem->left = newElem;
				else
					parentElem->right = newElem;
				newElem->parent = parentElem;
				newElem->left = nill;
				newElem->right = nill;
				newElem->color = Color::RED;
				recoveryInsert(newElem);

			}
			else
			{
				throw invalid_argument("key is already here ");
			}

		}
	}
	void recoveryInsert(Elem* newElem)
	{
		while (newElem->parent->color == Color::RED)
		{
			Elem* p = newElem->parent;
			Elem* grandp = p->parent;
			if (p == grandp->left)
			{
				if (grandp->right->color == Color::RED)
				{
					grandp->left->color = Color::BLACK;
					grandp->right->color = Color::BLACK;
					grandp->color = Color::RED;
				}
				else
				{
					if (newElem == p->right)
					{
						newElem = p;
						leftSwitch(newElem);
						p = newElem->parent;
						grandp = p->parent;
					}
					else
					{
						p->color = Color::BLACK;
						grandp->color = Color::RED;
						rightSwitch(grandp);
					}
				}
			}
			else
			{
				if (grandp->left->color == Color::RED)
				{
					grandp->left->color = Color::BLACK;
					grandp->right->color = Color::BLACK;
					grandp->color = Color::RED;
					newElem = grandp;
				}
				else
				{
					if (newElem == p->left)
					{
						newElem = p;
						rightSwitch(newElem);
						p = newElem->parent;
						grandp = p->parent;
					}

					else {
						p->color = Color::BLACK;
						grandp->color = Color::RED;
						leftSwitch(grandp);
					}
				}

			}
			if (newElem == root) break;
		}
		root->color = Color::BLACK;
	}
	void deleteElement(Key key)
	{
		Elem* deleteElem = findElem(key);
		if (deleteElem != nill)
		{
			Color tmpColor = deleteElem->color;
			Elem* x = NULL;
			if (deleteElem->left == nill)
			{
				x = deleteElem->right;
				swapElems(deleteElem, x);
			}
			else if (deleteElem->right == nill)
			{
				x = deleteElem->left;
				swapElems(deleteElem, x);
			}
			else
			{
				Elem* y = min(deleteElem->right);
				tmpColor = y->color;
				x = y->right;
				if (y->parent == deleteElem)
				{
					x->parent = y;
				}
				else
				{
					swapElems(y, y->right);
					y->right = deleteElem->right;
					y->right->parent = y;
				}
				swapElems(deleteElem, y);
				y->color = tmpColor;
				y->left = deleteElem->left;
				y->left->parent = y;
				y->color = deleteElem->color;
			}
			delete deleteElem;
			if (tmpColor == Color::BLACK) { recoveryDelete(x); }
		}
	}
	void recoveryDelete(Elem* x)
	{
		Elem* w;
		while (x != root && x->color == Color::BLACK)
		{
			if (x == x->parent->left)
			{
				w = x->parent->right;
				if (w->color == Color::RED)
				{
					w->color = Color::BLACK;
					x->parent->color = Color::RED;
					leftSwitch(x->parent);
					w = x->parent->right;
				}
				if (w->left->color == Color::BLACK && w->right->color == Color::BLACK)
				{
					w->color = Color::RED;
					x = x->parent;
				}
				else
				{
					if (w->right->color == Color::BLACK)
					{
						w->left->color = Color::BLACK;
						w->color = Color::RED;
						rightSwitch(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = Color::BLACK;
					w->right->color = Color::BLACK;
					leftSwitch(x->parent);
					x = root;
				}
			}
			else
			{
				w = x->parent->left;
				if (w->color == Color::RED)
				{
					w->color = Color::BLACK;
					x->parent->color = Color::RED;
					rightSwitch(x->parent);
					w = x->parent->left;
				}
				else if (w->left->color == Color::BLACK)
				{
					w->right->color = Color::BLACK;
					w->color = Color::RED;
					leftSwitch(w);
					w = x->parent->left;
				}
				else {
					w->color = x->parent->color;
					x->parent->color = Color::BLACK;
					w->left->color = Color::BLACK;
					rightSwitch(x->parent);
					x = root;
				}
			}
		}
		x->color = Color::BLACK;
	}
	Elem* findElem(Key key)
	{
		Elem* cur = root;
		while (cur != nill)
		{
			if (*cur->key == key) return cur;
			if (*cur->key < key) { cur = cur->right; }
			else if (*cur->key > key) { cur = cur->left; }
		}
		return nill;
	}
	void swapElems(Elem* x, Elem* y)
	{
		if (x->parent == NULL)
		{
			root = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else { x->parent->right = y; }
		y->parent = x->parent;
	}
	Elem* min(Elem* elem)
	{
		while (elem->left != nill)
		{
			elem = elem->left;
		}
		return elem;
	}
	Value getData(Key key)
	{
		Elem* elem = findElem(key);
		return elem->data;
	}
	List<Key>* getKeys()
	{
		List <Key>* keys = new List<Key>();
		//Iterator<Elem*>* iterator;
		//RBTreeIterator <Pair<Key,Value>>* iterator = createIterator(); 
		TreeIterator* iterator = createIterator();
		//while(iterator->has_next())
		//while (iterator->has_next())
		while(iterator->has_next())
		{
			Elem*  next = iterator->next();
			Key* key = next->key;
			keys->pushBack(*key);
		}
		delete iterator;
		return keys;
	}
	List<Value>* getValues()
	{
		List < Value>* values = new List<Key>();
		TreeIterator* iterator = createIterator();
		while (iterator->has_next())
		{
			Elem* next = iterator->next();
			Value value = next->data;
			values->pushBack(value);
		}
		delete iterator;
		return values;
	}
};

#endif // !RBTree_H
