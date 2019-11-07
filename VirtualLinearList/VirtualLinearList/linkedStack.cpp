#include "stdafx.h"
#include "linkedStack.h"

template<class T>
linkedStack<T>::~linkedStack()
{
	while (stackTop != NULL)
	{
		chainNode<T>* nextNode = stackTop->next;
		delete stackTop;
		stackTop = nextNode;
	}
}

template<class T>
void linkedStack<T>::pop()
{
	if (stackSize == 0)
		throw stakEmpty();
	chainNode<T>* nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize--;
}
