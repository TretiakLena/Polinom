#pragma once
#include "My_List.h"
#include "Node.h"

template<typename T>
class Iterator {
public:

	using different_type    = std::ptrdiff_t; //тип данных разности
	using value_type        = T; //тип данных (параметр шаблона)
	using pointer           = T; //указатель параметра шаблона
	using reference         = T & ; //ссылка параметра шаблона
	using iterator_category = std::random_access_iterator_tag;

	Iterator(Node<T>* p = nullptr);
	Iterator(const Iterator& copy) :Iterator(copy.iter) {};
	
	Iterator operator++        ();
	Iterator operator--        ();
	Iterator operator++        (int);
	Iterator operator--        (int);
	Iterator& operator=        (const Iterator& copy);
	friend bool operator==     (const Iterator& t1, const Iterator& t2) { return t1.iter == t2.iter; }
	friend bool operator!=     (const Iterator& t1, const Iterator& t2) { return !operator==(t1, t2); }
	T* operator->              () { return iter->data; };
	T& operator*               ();
	explicit operator Node<T>* () { return iter; }
private:
	Node<T>* iter;
};

//____________________CONSTRUCTOR______________________
template<typename T>
Iterator<T>::Iterator(Node<T>* p)
{
	this->iter = p;
};

//__________________INCREMENT_AND_DECREMENT_______________
template<typename T>
Iterator<T> Iterator<T>::operator++()
{
	iter = iter->pNext;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--()
{
	iter = iter->pPrev;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator<T> tmp = *this;
	iter = iter->pNext;
	return tmp;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int)
{
	Iterator<T> tmp = *this;
	iter = iter->pPrev;
	return tmp;
}

//_______________________OTHER_OPERATORS_________________
template<typename T>
Iterator<T> & Iterator<T>::operator=(const Iterator & copy)
{
	if (this->iter != copy.iter) {
		this->iter = copy.iter;
	}
	return *this;
}

template<typename T>
T& Iterator<T>::operator*()
{
	return iter->data;
}
