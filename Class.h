#pragma once
#include <stdexcept>

template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	size_t get_size() const;
	void push_back(T newElem);
	void push_front(T newElem);
	void pop_back();
	void pop_front();
	T at(size_t index) const;
	void clear();
	bool isEmpty();



private:
	void add_first(T newElem);
	void reset_list();

	class Node
	{
	public:
		Node(T data, Node * next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		~Node() {};

		T data;
		Node * next;
	};
	Node * head;
	Node * tail;

	size_t size;

};
