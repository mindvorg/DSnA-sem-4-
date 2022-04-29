#pragma once
#ifndef PAIR_H
template< typename Key, typename Value>
class Pair
{
public:
	Key first;
	Value second;
	Pair(Key& first, Value& second)
	{
		this->first = first;
		this->second = second;
	}
	Pair(Pair& pair) {
		this->first = pair->first;
		this->second = pair->second;
	}
	~Pair() {}

private:

};
template< typename Key, typename Value>
Pair<Key,Value> makepair(Key first, Value second)
{
	return Pair<Key, Value>(first, second);
}
#endif // !PAIR_H
