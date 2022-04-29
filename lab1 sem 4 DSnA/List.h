#pragma once
#ifndef LinkedList_H
#include<iostream>
template <class T>
class List
{
	class ElemList
	{
	public:
		ElemList(T value, ElemList* next, ElemList* prev) { this->data = value; this->next = next; this->prev = prev; };
		//ElemList(T value):
		~ElemList() {};
		ElemList* prev;
		ElemList* next;
		T data;
	};


public:
	ElemList* head;
	ElemList* tail;
	ElemList* gethead() { return head; }
	ElemList* gettail() { return tail; }
	ElemList* getnext(ElemList* elem) { return elem->next; }
	List() {
		head = NULL;
		tail = NULL;
	};
	~List() {
		ElemList* cur = head;
		while (cur != NULL) { cur = cur->next; delete head; head = cur; }
	};
	void pushBack(T elem)
	{
		ElemList* newElem=new ElemList(elem,NULL,tail);
			if (head == NULL) { head = newElem; }
			else { tail->next = newElem; }
		tail = newElem;
	}
	void pushFront(T elem)
	{
		ElemList* newElem = new ElemList(elem, head, NULL);
			if (head == NULL) { tail = newElem; }
			else { head->next = newElem; }
		head = newElem;
	}
	void popBack()
	{
		if(head!=NULL)
		{
			ElemList* cur = tail->prev;
			delete tail;
			tail = cur;
			
			cur->next = NULL;
		}
		else
		{
			//throw _out_of_range("no elements");
		}
	}
	void popFront()
	{
		if(head!=NULL)
		{
			ElemList* cur = head->next;
			delete head;
			head = cur;
			cur->prev = NULL;
		}
		else
		{
		//	throw out_of_range("no elements");
		}
	}
	void clear()
	{
		~List();
	}

};

#endif // !LinkedList_H
