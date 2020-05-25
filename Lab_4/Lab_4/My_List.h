#pragma once

template<typename T>
class Node {
public:
	Node *pNext;
	Node *pPrev;
	T data;
	Node(T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
		this->pPrev = pPrev;
	}
};

//template<typename T>
//class My_Iterator {
//public:
//	using different_type = std::ptrdiff_t;
//	using value_type = T;
//	using pointer = T;
//	using reference = T&;
//	using iterator_category = std::random_access_iterator_tag;
//
//	
//private:
//	Node<T>* iter;
//};


template<typename T>
class My_List
{
public:
	My_List();
	~My_List();

	int size() { return Size; }
	
	void push_back  (T data);
	void pop_back   ();
	void push_front (T data);
	void pop_front  ();
	void insert     (T value, int index);
	void clear      ();
	void removeAt   (int index);



private:
	/*template<typename T>
	class Node {
	public:
		Node *pNext;
		Node *pPrev;
		T data;
		Node(T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};*/
	int Size;
	Node<T> *first;
	Node<T> *last;
};

template<typename T>
My_List<T>::My_List()
{
	Size = 0;
	first = nullptr;
	last = nullptr;
}

template<typename T>
My_List<T>::~My_List()
{
	clear();
}



template<typename T>
void My_List<T>::push_back(T data)
{
	Node<T> *new_node;
	if (first == nullptr && last ==nullptr) {
		new_node = new Node<T>(data);
		first = new_node;
		last = new_node;
	}
	else if (first == last){
		new_node = new Node<T>(data, first);
		last = new_node;
		first->pNext = last;
		}
	else {
		new_node = new Node<T>(data, last);
		last->pNext = new_node;
		last = new_node;
	}
	Size++;
}

template<typename T>
inline void My_List<T>::push_front(T data)
{
	first = new Node<T>(data, first);
	//last = last->pNext;
	Size++;
}

template<typename T>
inline void My_List<T>::pop_front()
{
	Node<T> *temp = first;
	first = first->pNext;
	//last = last->pPrev;
	delete temp;
	Size--;
}

template<typename T>
inline void My_List<T>::pop_back()
{
	//Node<T> *temp = last;
	//last = last->pPrev;
	//delete temp;
	//Size--;
	removeAt(Size - 1);
}

template<typename T>
inline void My_List<T>::insert(T data, int index)
{
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T> *prev = this->first;

		for (int i = 0; i < index - 1; i++) {
			prev = prev->pNext;
		}

		Node<T> *new_node = new Node<T>(data, prev->pNext);
		prev->pNext = new_node;
		//last = last->pNext;
		Size++;
	}
}

template<typename T>
inline void My_List<T>::clear()
{
	while (Size != 0) {
		pop_front();
	}
}

template<typename T>
inline void My_List<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T> *prev = this->first;
		for (int i = 0; i < index - 1; i++) {
			prev = prev->pNext;
		}

		Node<T> *toDelete = prev->pNext;

		prev->pNext = toDelete->pNext;
		//last = last->pPrev;
		delete toDelete;
		Size--;
	}
}

