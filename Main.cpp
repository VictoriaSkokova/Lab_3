#include "Heap.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Tree Heap;
	Heap.insert(3);
	Heap.insert(5);
	Heap.insert(2);
	Heap.insert(1);
	Heap.insert(7);
	Heap.insert(6);
	Heap.insert(16);
	Heap.insert(17);
	Heap.insert(10);
	Heap.insert(24);
	Heap.insert(13);
	Heap.insert(5);
	cout << "Добрый день. Лабораторная работа 3. Выполнила Скокова Виктория \n";
	cout << "Дерево имеет вид: \n";

	Heap.print();

	cout << "\nРазмер дерева - " << Heap.size << "\n";
	cout << "\nПроверим на наличие элемента с ключом 10:\n";
	if (Heap.contains_begin(10) == true)
		cout << "Элемент найден \n";
	else cout << "Элемент не найден \n";
	cout << endl;
	cout << "Обход дерева в глубину при помощи итератора\n";
	cout << endl;
	Iterator* dft_iterator = Heap.create_dft_iterator();
	while (dft_iterator->has_next())
	{
		cout << " " << dft_iterator->next();
	}
	cout << endl;
	cout << endl;

	cout << "Обход дерева в ширину при помощи итератора\n";
	cout << endl;
	Iterator* bft_iterator = Heap.create_bft_iterator();
	while (bft_iterator->has_next())
	{
		cout << " " << bft_iterator->next();
	}
	cout << endl;
	cout << endl;
	cout << "Удалим элемент дерева с ключом 10:\n";
	cout << endl;
	if (Heap.remove_begin(10) == false)
		cout << "В дереве не был найден элемент с данным ключом";
	else {
		cout << "Размер дерева стал - " << Heap.size << "\n";

		if (Heap.size > 0)
		{
			cout << "Дерево приняло вид: \n";
			Heap.print();
		}
		else
		{
			cout << "В дереве не осталось элементов";
		}
		cout << endl;
	}

	system("pause");
	return 0;

}
