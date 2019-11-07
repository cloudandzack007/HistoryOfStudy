#include "stdafx.h"
#include "chain.h"


template<class T>
chain<T>::chain(int initialCapacity /*= 10*/)
{
	if (initialCapacity < 1)
	{
		//
	}
	firstNode = NULL;
	listSize = 0;
}


template<class T>
chain<T>::chain(const chain<T>& theList)
{
	listsize = theList.listSize;

	if (listSize == 0)
	{
		firstNode = NULL;
		return;
	}

	chainNode<T>* sorceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
}

template<class T>
chain<T>::~chain()
{

}

template<class T>
void chain<T>::checkIndex(int theIndex) const
{

}

template<class T>
void chain<T>::output(ostream& out) const
{

}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{

}

template<class T>
void chain<T>::erase(int theIndex)
{

}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{

}

template<class T>
T& chain<T>::get(int theIndex) const
{

}
