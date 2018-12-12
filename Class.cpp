#include <stdexcept>
#include <iostream>
#include "Class.h"

using namespace std;
template <class T>
void LinkedList<T>::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

template <class T>
LinkedList<T>::LinkedList()
{
	reset_list();
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <class T>
void LinkedList<T>::add_first(T newElem)
{
	head = new Node(newElem);
	tail = head;
}

template <class T>
size_t LinkedList<T>::get_size() const
{
	return size;
}

template <class T>
void LinkedList<T>::push_back(T newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		tail->next = new Node(newElem);
		tail = tail->next;
	}
	size++;
}

template <class T>
void LinkedList<T>::push_front(T newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		head = new Node(newElem, head);
	}
	size++;

}


template <class T>
void LinkedList<T>::pop_back()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node * current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}

template <class T>
void LinkedList<T>::pop_front()
{
	if (size == 0) return;

	if (size == 1)
	{
		delete head;
		reset_list();
	}
	else
	{
		Node * current = head;
		head = head->next;

		delete current;
	}
	size--;
}

template <class T>
T LinkedList<T>::at(size_t index) const
{
	if ((index >= size) || (index < 0)) {
		throw out_of_range("Wrong index");
	}
	else {
		size_t counter = 0;
		Node * current = head;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}


template <class T>
void LinkedList<T>::clear()
{

	for (size_t i = 0; i < get_size() + 6
		; i++) {

		pop_front();

	}
}


template <class T>
bool LinkedList<T>::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}
