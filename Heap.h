#pragma once
#include "Iterator.h"
#include <iomanip>
#include <iostream>
#include "Class.h"
#include "Class.cpp"


class Tree
{
public:

	class Node//Элемент дерева
	{
	public:
		~Node();
		Node() {};

		int data;//Значение элемента
		Node *next = next; //Следующий 
		Node *rgt = nullptr;//правый узел
		Node *lft = nullptr;//левый узел
		Node *parent = nullptr;//Родитель
		Node(int k);
		void Delete();
	};
	~Tree();
	Tree() {  };
	Node *root = nullptr;//Корень дерева
	Node *last = nullptr;//Последний добавленный элемент
	size_t size = 0;
	void insert(int newelem); //Вставка элемента
	bool contains(Node *root, int findelem); //Проверка на содержание элемента по ключу
	void print_Tree(Node * node, int level); //Вывод дерева
	void Sort(Node* elem); //Сортировка
	Iterator * create_dft_iterator()const; //Обход в глубину при помощи итератора
	Iterator * create_bft_iterator()const; //Обход в ширину с помощью итератора
	bool remove(Node *node, int value); //Удаление элемента по ключу
	bool isEmpty(Node *root); //Проверка на пустоту списка
	Tree(int key);

	/*______________________________________________________________________________________________*/

	class dft_Iterator : public Iterator //Класс наследник 
	{
	public:
		dft_Iterator(Node * root)
		{
			current = root;
		};
		int next() override;
		bool has_next() override;

	private:
		LinkedList<Node*> lst;
		Node * current;
	};

	//___________________________________________________________________________________________________

	class bft_Iterator : public Iterator
	{
	public:
		bft_Iterator(Node * root)
		{
			current = root;
		};
		int next() override;
		bool has_next() override;

	private:
		LinkedList<Node*> lst;
		Node * current;
	};
};
