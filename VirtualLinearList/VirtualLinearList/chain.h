#pragma once
#include "linearList.h"
template<class T>
struct chainNode
{
	//数据成员
	T * element;
	chainNode<T> *next;
	//方法
	chainNode() {};
	chainNode(const T& element)
	{
		this->element = element;
	}
	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};
template<class T>
class chain :
	public linearList<T>
{
public:
	chain(int initialCapacity =  10);
	chain(const chain<T>&);
	~chain();
	
	bool empty()const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;
protected:
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode;
	int listSize;
};






