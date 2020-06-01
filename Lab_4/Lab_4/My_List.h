#pragma once
#include "Iterator.h"
#include "Node.h"


template<typename T>
class List
{
public:
	List  ();
	~List ();
	List  (const List<T>&);
	
	Iterator<T> begin();
	Iterator<T> cbegin() const;
	Iterator<T> end();
	Iterator<T> cend() const;

	void push_back     (T data);
	void pop_back      ();
	void push_front    (T data);
	void pop_front     ();
	Iterator<T> insert (Iterator<T> iter, T value);
	void clear         ();
	void erase         (Iterator<T> iter);
	int size           () { return Size; }

private:
	int      Size;
	Node<T> *first;
	Node<T> *last;
};

//____________________CONSTRUCTORS____________________
template<typename T>
List<T>::List()
{
	Size  = 0;
	first = nullptr;
	last  = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
List<T>::List(const List<T>&a)
{
	first = nullptr;
	last  = nullptr;
	Size  = 0;

	Node<T>*temp = a.first;
	
	while (temp != 0) {
		push_back(temp->data);
		temp = temp->pNext;
	}
}

//_______________BEGIN_AND_END_____________________
template<typename T>
Iterator<T> List<T>::begin()
{
	return (Iterator<T>(this->first));
}

template<typename T>
Iterator<T> List<T>::cbegin() const
{
	return this->begin();;
}

template<typename T>
Iterator<T> List<T>::end()
{
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> List<T>::cend() const
{
	return this->end();
}

//________________LIST_FUNCTIONS_______________________
template<typename T>
void List<T>::push_back(T data)
{
	Node<T> *new_node;
	if (Size == 0) {
		new_node = new Node<T>(data);
		first    = new_node;
		last     = new_node;
	}
	else if (Size == 1){
		new_node     = new Node<T>(data, first);
		last         = new_node;
		first->pNext = last;
		}
	else {
		new_node    = new Node<T>(data, last);
		last->pNext = new_node;
		last        = new_node;
	}
	Size++;
}

template<typename T>
void List<T>::pop_back()
{
	Node<T> *temp = last;
	last = last->pPrev;

	if (Size > 1) {
		last->pNext = nullptr;
	}
	else if (Size == 1) {
		first = last;
	}
	delete temp;
	Size--;
}

template<typename T>
void List<T>::push_front(T data)
{
	auto temp = first;
	first     = new Node<T>(data, nullptr, temp);

	if (Size == 0) {
		last = first;
	}
	else {
		temp->pPrev = first;
	}
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = first;
	first         = first->pNext;
	
	delete temp;

	if (Size > 1) {
		first->pPrev = nullptr;
	}
	else if (Size == 1) {
		last = nullptr;
	}
	Size--;
}

template<typename T>
Iterator<T> List<T>::insert(Iterator<T> iter, T data)
{
	if (iter == begin()) {
		push_front(data);
		return begin();
	}
	auto i = first->pNext;
	for (; i != iter; ++i) {
		i = i->pNext;
	}
	auto new_node = new Node<T>(data, i->pPrev, i);
	i->pPrev->pNext = new_node;
	i->pNext->pPrev = new_node;
	Size++;
	return i;
}

template<typename T>
void List<T>::clear()
{
	while (Size != 0) {
		pop_front();
	}
}

template<typename T>
void List<T>::erase(Iterator<T> iter)
{
	if (iter == begin()) {
		pop_front();
		return;
	}
	auto i = first->pNext;
	for (; i != iter; ++i) {
		i = i->pNext;
	}

	i->pPrev->pNext = i->pNext;
	i->pNext->pPrev = i->pPrev;
	delete i;
	Size;
}

