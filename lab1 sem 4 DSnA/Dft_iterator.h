#pragma once
#ifndef Dft_Iterator_H

#include "Stack.h"
#include "Iterator.h"
#include "Elem.h"
using namespace std;
template<class T_key,class T_value>
class dft_iterator :public Iterator<T_key> 
{
public:
	dft_iterator(Elem<T_key, T_value>* root)
	{
		cur = root;
		Stack = new Stack<Elem<T_key, T_value>*>();
	};
	~dft_iterator() { delete Stack; };
	has_next() { return cur != NULL; }
	next() {
		if (!has_next()) { throw out_of_range("no more elements"); } 
		T_key tmp = *(cur->data); 
		if (cur->next_right->data != NULL) { cur = cur->next_left; }
		else { try { cur = stack->peek(); stack->pop(); } catch (out_of_range) { cur = NULL; } }
	}
	return tmp;
private:

};
#endif // !Dft_Iterator_H