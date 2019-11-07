#include "stdafx.h"
#include "arrayStack.h"


template<class T>
arrayStack<T>::arrayStack(int initialCapacity /*= 10*/)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameTerValue(s.str());
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}


template<class T>
void arrayStack<T>::push(const T& theElement)
{
	if (stackTop == arrayLength - 1)
	{
		changeLength1D(stack, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	stack[++stackTop] = theElement;
}

template<class T>
void arrayStack<T>::changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
	{
		throw illegalParameterValue("new length must be >=0");
	}
	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}
