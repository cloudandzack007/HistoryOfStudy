#pragma once
#include "stack.h"
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
class linkedStack :
	public stack<T>
{
public:
	linkedStack(int initialCapacity = 10)
	{
		stackTop = NULL;
		stackSize = 0;
	}
	~linkedStack();
	bool empty() const
	{
		return stackSize == 0;
	}
	int size() const
	{
		return stackSize;
	}
	T& top()
	{
		if (stackSize == 0)
			throw stackeEmpty();
		return stackTop->element;
	}
	void pop();
	void push(const T& theElement)
	{
		stackTop = new chainNode<T>(theElement, stackTop);
		stackSize++;
	}
private:
	chainNode<T>* stackTop;
	int stackSize;
};




