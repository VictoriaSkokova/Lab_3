#include "stdafx.h"
#include <stdexcept>
#include "CppUnitTest.h"
#include "..\Lab_Alg_3\Heap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(insert_empty)
		{
			Tree Heap;
			Heap.insert(2);
			Assert::IsTrue(Heap.root->data == 2);

		}

		TEST_METHOD(insert_not_empty)
		{
			Tree Heap;
			Heap.insert(2);
			Heap.insert(3);
			Assert::IsTrue(Heap.root->data == 3);
		}

		TEST_METHOD(insert_several_checks)
		{
			bool check = true;
			Tree Heap;
			Heap.insert(4);
			Heap.insert(6);
			Heap.insert(3);
			Heap.insert(2);
			Heap.insert(5);
			
			int i = 0;

			int array[5];
			array[0] = 6;
			array[1] = 5;
			array[2] = 3;
			array[3] = 2;
			array[4] = 4;

			Iterator* bft_iterator = Heap.create_bft_iterator();
			while (bft_iterator->has_next())

			{
				if (bft_iterator->next() != array[i])
					check = false;
				i++;
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(contains_true)
		{
			Tree Heap;
			Heap.insert(2);
			Heap.insert(3);
			Assert::IsTrue(Heap.contains_begin(3) == true);
		}

		TEST_METHOD(contains_false)
		{
			Tree Heap;
			Heap.insert(2);
			Heap.insert(3);
			Assert::IsTrue(Heap.contains_begin(4) == false);
		}

		TEST_METHOD(contains_empty)
		{
			Tree Heap;
			Assert::IsTrue(Heap.contains_begin(4) == false);
		}

		TEST_METHOD(isntEmpty)
		{
			Tree Heap;
			Heap.insert(3);
			Assert::IsFalse(Heap.isEmpty());
		}

		TEST_METHOD(isEmpty)
		{
			Tree Heap;
			Assert::IsTrue(Heap.isEmpty());
		}

		TEST_METHOD(remove_empty)
		{
			Tree Heap;
			Assert::IsTrue(Heap.remove_begin(4) == false);
		} 

		TEST_METHOD(remove_one)
		{
			Tree Heap;
			Heap.insert(4);
			Heap.remove_begin(4);
			Assert::IsTrue(Heap.isEmpty());
		}

		TEST_METHOD(remove_root)
		{
			Tree Heap;
			Heap.insert(4);
			Heap.insert(6);
			Heap.insert(5);
			Heap.remove_begin(6);
			Assert::IsTrue(Heap.root->data != 6);
		}

		TEST_METHOD(remove_middle_if_one)
		{
			Tree Heap;
			Heap.insert(4);
			Heap.insert(6);
			Heap.insert(5);
			Heap.insert(3);
			Heap.insert(2);
			Heap.remove_begin(5);
			Assert::IsTrue(Heap.contains_begin(5) == false);
		}

		TEST_METHOD(remove_middle_if_more)
		{
			Tree Heap;
			Heap.insert(4);
			Heap.insert(6);
			Heap.insert(5);
			Heap.insert(3);
			Heap.insert(2);
			Heap.insert(5);
			Heap.remove_begin(5);

			bool check = true;
			int i = 0;

			int array[5];
			array[0] = 6;
			array[1] = 4;
			array[2] = 5;
			array[3] = 3;
			array[4] = 2;

			Iterator* bft_iterator = Heap.create_bft_iterator();
			while (bft_iterator->has_next())

			{
				if (bft_iterator->next() != array[i])
					check = false;
				i++;
			}
			Assert::IsTrue(check);
		}


		TEST_METHOD(remove_end)
		{
			Tree Heap;
			Heap.insert(4);
			Heap.insert(6);
			Heap.insert(5);
			Heap.insert(3);
			Heap.insert(2);
			Heap.remove_begin(2);
			Assert::IsTrue(Heap.contains_begin(2) == false);
		}

		TEST_METHOD(size_remove)
		{
			Tree Heap;
			Heap.insert(4);
			Heap.insert(6);
			Heap.insert(5);
			Heap.remove_begin(6);
			Assert::IsTrue(Heap.size == 2);
		}

		//Итераторы

		TEST_METHOD(dft_has_next)
		{
			Tree Heap;
			Heap.insert(4);
			Heap.insert(6);
			Iterator* dft_iterator = Heap.create_dft_iterator();
			dft_iterator->next();
			Assert::IsTrue(dft_iterator->has_next());
		}

		TEST_METHOD(bft_has_next)
		{
			Tree Heap;
			Heap.insert(4);
			Heap.insert(6);
			Iterator* bft_iterator = Heap.create_bft_iterator();
			bft_iterator->next();
			Assert::IsTrue(bft_iterator->has_next());
		}

		TEST_METHOD(dft_iterator)
		{
			bool check = true;
			int i = 0;
			int array[4];
			array[0] = 6;
			array[1] = 5;
			array[2] = 3;
			array[3] = 4;
			Tree Heap;
			Heap.insert(5);
			Heap.insert(6);
			Heap.insert(4);
			Heap.insert(3);
			Iterator* dft_iterator = Heap.create_dft_iterator();
			while (dft_iterator->has_next())

			{
				if (dft_iterator->next() != array[i])
					check = false;
				i++;
			}
			Assert::IsTrue(check);
		}


		TEST_METHOD(bft_iterator)
		{
			bool check = true;
			int i = 0;
			int array[4];
			array[0] = 6;
			array[1] = 5;
			array[2] = 4;
			array[3] = 3;
			Tree Heap;
			Heap.insert(5);
			Heap.insert(6);
			Heap.insert(4);
			Heap.insert(3);
			Iterator* bft_iterator = Heap.create_bft_iterator();
			while (bft_iterator->has_next())

			{
				if (bft_iterator->next() != array[i])
					check = false;
				i++;
			}
			Assert::IsTrue(check);
		}


		TEST_METHOD(dft_iterator_false)
		{
			bool check = true;
			int i = 0;
			int array[4];
			array[0] = 6;
			array[1] = 5;
			array[2] = 4;
			array[3] = 3;
			Tree Heap;
			Heap.insert(5);
			Heap.insert(6);
			Heap.insert(4);
			Heap.insert(3);
			Iterator* dft_iterator = Heap.create_dft_iterator();
			while (dft_iterator->has_next())

			{
				if (dft_iterator->next() != array[i])
					check = false;
				i++;
			}
			Assert::IsFalse(check);
		}


		TEST_METHOD(bft_iterator_false)
		{
			bool check = true;
			int i = 0;
			int array[4];
			array[0] = 6;
			array[1] = 5;
			array[2] = 3;
			array[3] = 4;
			Tree Heap;
			Heap.insert(5);
			Heap.insert(6);
			Heap.insert(4);
			Heap.insert(3);
			Iterator* bft_iterator = Heap.create_bft_iterator();
			while (bft_iterator->has_next())

			{
				if (bft_iterator->next() != array[i])
					check = false;
				i++;
			}
			Assert::IsFalse(check);
		}
	};
}
