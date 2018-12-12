#include "Heap.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

Tree::Tree(int key)
{
	root = new Node(key);
}

Tree::Node::Node(int k)
{
	data = k;
	lft = rgt = nullptr;

}

Tree::Node::~Node()
{
	free(this);
}

Tree::~Tree()
{
	if (size != 0)
	{
		root->Delete();
		if (root->lft != nullptr)
			root->lft = nullptr;
		if (root->rgt != nullptr)
			root->rgt = nullptr;
		root = nullptr;
	}
}

void Tree::Node::Delete()
{
	if (this == nullptr) return;
	this->lft->Delete();
	this->rgt->Delete();
	free(this);
}

void Tree::insert(int newelem)
{
	Node *elem = new Node;
	elem->data = newelem;
	if (root == nullptr) //Если список пуст
	{
		root = elem;
		last = root;
	}
	else
	{
		Node *current = last;
		while (current->parent != nullptr && current == current->parent->rgt) //Движемся к корню
			current = current->parent;

		if (current->parent != nullptr) 
		{
			if (current->parent->rgt != nullptr)//у родителя есть правый узел
			{
				current = current->parent->rgt;//переходим на него
				while (current->lft != nullptr)//если у того есть левый
					current = current->lft;
			}

			else current = current->parent;//нет правого узла,вставим в правый
		}
		else //Попали в корень
		{  
			while (current->lft != nullptr)
				current = current->lft;
		}

		if (current->lft != nullptr) //вставка вправо
		{
			current->rgt = elem;
			last = current->rgt;
		}

		else
		{
			current->lft = elem;
			last = current->lft;
		}

		elem->parent = current; //Задаем связи
		elem->lft = nullptr;
		elem->rgt = nullptr;
	}

	size++;

	Sort(last); //Сортируем под вид кучи
}

//Убрать в прайват и написать доп функцию
bool Tree::remove(Node *node, int value) //Возвращает значение true, если элемент был найден, false - если элемент не найден
{
	int help = 0;
	if (size == 0)
	{
		cout << "Дерево пусто\n";
		return false;
	}
	else
	{

		if (size == 1)
		{
			if (root->data == value)
			{
				free(root);
				cout << "Дерево пусто\n";
				size--;
				return true;
			}
		}
		else
		{
			if (node)
			{
				if (node->data != value) //Значение текущего элемента не равно введенному ключу
				{
					if (remove(node->lft, value) == true) //Рекурсивно идем влево
						return true;
					if (remove(node->rgt, value) == true) //Рекурсивно идем направо
						return true;
				}
				else //Нашли нужное значение
				{
					while ((node->lft != nullptr) || (node->rgt != nullptr)) //Пока не дошли до нижнего элемента
					{
						if ((node->rgt == nullptr) || (node->lft->data >= node->rgt->data))
						{
							node->data = node->lft->data; //Меняем значение родителя на значение максимального потомка и передвигаемся в него
							node = node->lft;
							help = 1; 
						}
						else
						{
							node->data = node->rgt->data;
							node = node->rgt;
							help = 2;
						}
					}
					if ((node->lft == nullptr) && (node->rgt == nullptr)) //Дошли до нижнегоэлемента в цепочке замен и удаляем его
					{
						node = node->parent;
						if (help == 1)
						{
							node->lft = nullptr;
						}
						else
						{
							node->rgt = nullptr;
						}
						size--;
						return true;
					}
				}

			}
			else
				return false;
		}
	}
}


void Tree::print_Tree(Node * node, int level) //Дерево выводится повернутым на 90 градусов и читается справа налево
{
	if (node)
	{
		print_Tree(node->rgt, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << node->data << endl;
		print_Tree(node->lft, level + 1);
	}
}

void Tree::Sort(Node* elem)
{
	while (elem->parent != nullptr && elem->data > elem->parent->data) //Пока не дошли до корня и значение потомка больше значения родителя 
	{
		int temp = elem->data;

		if (elem->data > elem->parent->data) //Меняем местами значение потомка и родителя
		{
			elem->data = elem->parent->data;
			elem->parent->data = temp;
		}

		elem = elem->parent; //Движемся вверх
	}
}



//________________________________________________________________________________________________

Iterator*Tree::create_bft_iterator() const //в ширину
{
	if (this == nullptr && this->root == nullptr) throw std::exception("ERROR");
	return new bft_Iterator(this->root);
}

int Tree::bft_Iterator::next()
{
	if (lst.get_size() == 0) //Используем список из 2 лабораторной в качестве очереди
		lst.push_back(current);
	current = lst.at(0);
	lst.pop_front();
	const int key = current->data;
	if (current->lft) 
	{
		lst.push_back(current->lft);
	}
	if (current->rgt) {
		lst.push_back(current->rgt);
	}
	return key;
}

bool Tree::bft_Iterator::has_next()
{
	return (lst.get_size() || current->lft != nullptr && current->rgt != nullptr);
}


Iterator * Tree::create_dft_iterator()const //в глубину
{
	if (this == nullptr && this->root == nullptr) throw std::exception("ERROR");
	return new dft_Iterator(this->root);
}

int Tree::dft_Iterator::next() //Используем список из 2 лабораторной в качестве стека
{
	if (current != nullptr)
	{
		const int key = current->data;
		if (current->rgt != nullptr)
			lst.push_front(current);
		current = current->lft;
		return key;
	}
	if (current == nullptr) {
		current = lst.at(0);
		lst.pop_front();
		current = current->rgt;
		next();
	}
}

bool Tree::dft_Iterator::has_next()
{
	return (lst.get_size() || current != nullptr);
}




//______________________________________________________________________________________________________________________


bool Tree::contains(Node *root, int findelem)
{
	if (size == 0)
		return false;

	Node *elem = new Node;
	elem->data = findelem;

	if (root)
	{
		if (root->data != elem->data)
		{
			if (contains(root->lft, findelem) == true)
				return true;
			if (contains(root->rgt, findelem) == true)
				return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}


bool Tree::isEmpty(Node *root)
{
	if (size == 0)
		return true;
	else
		return false;
}
