#include "stdafx.h"
#include "TemList.h"
#include <iosfwd>

template<class T>
TemList<T>::TemList(int initialCapacity /*= 10*/)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		//throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}

template<class T>
TemList<T>::TemList(const chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize = 0)
	{
		firstNode == 0;
		return;
	}
	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNodeM<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
	while (sourceNode!=NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}

template<class T>
TemList<T>::~TemList()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class T>
T& TemList<T>::get(int theIndex) const
{
	checkIndex(theIndex);

	chainNode<T>* currentNode = firstNode;
	for (int i =0;i<theIndex;i++)
	{
		currentNode = currentNode->next;
		return currentNode->element;
	}
}

template<class T>
void TemList<T>::checkIndex(int theIndex) const
{
	if (theIndex>listSize)
	{
		ostringstream s;
		s << "Initial Index = " << theIndex << " Must be < listSize";
		//throw illegalParameterValue(s.str());
	}
}

template<class T>
int TemList<T>::indexOf(const T& theElement) const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != NULL && 
		   currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}

	if (currentNode == NULL)
	{
		return -1;
	}
	else
	{
		return index;
	}
}

template<class T>
void TemList<T>::erase(int theIndex)
{
	checkIndex(theIndex);

	chainNode<T>* deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0;i < theIndex - 1; i++)
		{
			p = p->next;
		}
		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
}

template<class T>
void TemList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (theIndex == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (iint i=0;i<theIndex - 1;i++)
		{
			p = p->next;
		}
		p->next = new chainNode<T>(theElement, p->next);
	}
	listSize++;
}