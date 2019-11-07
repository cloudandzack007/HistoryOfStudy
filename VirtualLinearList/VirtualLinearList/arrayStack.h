#pragma once
#include "stack.h"
template<class T>
class arrayStack :
	public stack<T>
{
public:
	arrayStack(int initialCapacity = 10);
	~arrayStack() { delete[] stack; };
	bool empty() const { return stackTop == -1; }
	int size() const
	{
		return stackTop + 1;
	}
	T& top()
	{
		if (stackTop == -1)
			throw stackEmpty();
		return stack[stackTop];
	}
	void pop()
	{
		if (stackTop == -1)
			throw stackEmpty();
		stack[stackTop--].~T();
	}
	void push(const T& theElement);
private:
	void changeLength1D(T*& a, int oldLength, int newLength);
	int stackTop;
	int arrayLength;
	T *stack;
};




