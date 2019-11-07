#include "stdafx.h"
#include "arrayList.h"

template<class T>
arrayList<T>::arrayList(int initialCapacity /*= 10*/)
{
	if (initialCapacity<1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}
template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
	if (theIndex<0||theIndex>=listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
}

template<class T>
T& arrayList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = (int)(find(element, elemnt + listSize, theElement) - element);
	if (theIndex == listSize)
		return -1;
	else return theIndex;
}
template<class T>
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	copy(element + theIndex + 1, element + lsitSize, element + theIndex);
	element[--listSize].~T();
}
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0||theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
}

template<class T>
void arrayList<T>::changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength<0)
	{
		throw illegalParameterValue("new length must be >=0");
	}
	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{

}
