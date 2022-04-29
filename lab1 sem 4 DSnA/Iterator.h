#pragma once
#ifndef iterators_H
template<class T>
class Iterator
{
public:
	virtual T next() = 0;
	virtual bool has_next() = 0;
	virtual ~Iterator() {};
};
#endif // !iterators_H