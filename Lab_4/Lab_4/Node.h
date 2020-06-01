#pragma once

template<typename T>
class Node {
public:
	Node *pNext;
	Node *pPrev;
	T data;
	Node(T data = T(), Node *pPrev = nullptr, Node *pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
		this->pPrev = pPrev;
	}
};
