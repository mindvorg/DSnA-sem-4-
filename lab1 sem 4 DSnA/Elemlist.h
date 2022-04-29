/*
#pragma once
#ifndef Elemlist_H

#include<iostream>
using namespace std;
template<class T_link>
class ElemList
{
public:
	ElemList(T_link data = NULL, ElemList* next = NULL, ElemList* prev = NUll) :data(data), next(next), prev(prev) {};
	~ElemList() = default;
	setNext(ElemList* newnext) { this->next = newnext; }
	setPrev(ElemList* newprev) { this->prev = newprev; }
	ElemList* getnext() { return this->next; }
	ElemList* getprev() { return this->prev; }
	ElemList* makeNull() { return this->next = NULL; }
	T_link getNextdata() { if (this->next == NULL)return 0; else return this->next->data; }
	T_link getPrevdata() { if (this->prev == NULL)return 0; else return this->prev->data; }
	T_link getElemdata() { return this->data; }
	setNewData(T_link newData) { this->data = newData; }
	ElemList* next, * prev;
	T_link data;
};
#endif
*/