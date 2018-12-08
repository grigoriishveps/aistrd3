#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ais3/Heap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Heap *heap;
		size_t index;
		TEST_METHOD_INITIALIZE(setup) {
			heap = new Heap();
		}

		TEST_METHOD_CLEANUP(cleanup) {
			delete heap;
		}

		TEST_METHOD(add_ordered)
		{
			for ( index = 7; index > 0; index--) 
				heap->add(index);
			Assert::IsTrue(heap->is_correct());
		}

		TEST_METHOD(add_not_ordered)
		{
			heap->add(0);
			for ( index = 7; index > 0; index--)
				heap->add(index);
			heap->add(11);
			Assert::IsTrue(heap->is_correct());
		}
		
		TEST_METHOD(add_one_element)
		{
			heap->add(0);
			Assert::IsTrue(heap->is_correct());
		}
		
		TEST_METHOD(contains_body)
		{
			for ( index = 10; index > 0; index--)
				heap->add(index);
			Assert::IsTrue(heap->contains(5));
		}
		
		TEST_METHOD(contains_not)
		{
			for ( index = 10; index > 0; index--)
				heap->add(index);
			Assert::IsFalse(heap->contains(11));
		}
		
		TEST_METHOD(contains_tail)
		{
			for ( index = 10; index > 0; index--)
				heap->add(index);
			Assert::IsTrue(heap->contains(1));
		}

		TEST_METHOD(contains_head)
		{
			for ( index = 10; index > 0; index--)
				heap->add(index);
			Assert::IsTrue(heap->contains(10));
		}

		TEST_METHOD(contains_one_elem)
		{
			heap->add(3);
			Assert::IsTrue(heap->contains(3));
		}
		
		
		TEST_METHOD(remove_one_elem)
		{
			
			heap->add(8);
			heap->remove(8);
			Assert::IsTrue(!heap->contains(8));
		}
		
		TEST_METHOD(remove_body)
		{
			for ( index = 10; index > 0; index--)
				heap->add(index);
			heap->remove(6);
			Assert::IsTrue(!heap->contains(6) && heap->is_correct());
		}

		TEST_METHOD(remove_tail)
		{
			for ( index = 10; index > 0; index--)
				heap->add(index);
			heap->remove(1);
			Assert::IsTrue(!heap->contains(1) && heap->is_correct());
		}

		TEST_METHOD(remove_head)
		{
			for ( index = 10; index > 0; index--)
				heap->add(index);
			heap->remove(10);
			Assert::IsTrue(!heap->contains(10) && heap->is_correct());
		}
		
		TEST_METHOD(remove_one_elem_in_level)
		{
			for ( index = 8; index > 0; index--)
				heap->add(index);
			heap->remove(8);
			Assert::IsTrue(!heap->contains(8) && heap->is_correct());
		}
		

		TEST_METHOD(dfs_with_sorted_add)
		{
			for ( index = 15; index > 0; index--)
				heap->add(index);
			Iterator* iterator = heap->dfs();
			int array[15];
			int example[] = {15, 14, 12, 8, 7, 11, 6, 5, 13, 10, 4, 3, 9, 2, 1 };
			index = 0;
			while (iterator->has_next())
				array[index++] = iterator->next()->get_data();
			for(index = 0; index < 15; index++)
				Assert::AreEqual(array[index], example[index]);
		}

		TEST_METHOD(dfs_with_not_sorted_add)
		{
			for ( index = 14; index > 0; index--)
				heap->add(index);
			heap->add(15);
			Iterator* iterator = heap->dfs();
			int array[15];
			int example[] = {15, 13, 11, 7, 6,10, 5, 4, 14, 9, 3, 2, 12, 1, 8 };
			index = 0;
			while (iterator->has_next())
				array[index++] = iterator->next()->get_data();
			for(index = 0; index < 15; index++)
				Assert::AreEqual(array[index], example[index]);
		}

		TEST_METHOD(dfs_not_full_level)
		{
			for (index = 14; index > 0; index--)
				heap->add(index);
			Iterator* iterator = heap->dfs();
			int array[14];
			int example[] = { 14, 13, 11, 7, 6, 10, 5, 4, 12, 9, 3, 2, 8, 1 };
			index = 0;
			while (iterator->has_next())
				array[index++] = iterator->next()->get_data();
			for (index = 0; index < 14; index++)
				Assert::AreEqual(array[index], example[index]);
		}



		TEST_METHOD(bfs_with_sorted_add)
		{
			for ( index = 15; index > 0; index--)
				heap->add(index);
			Iterator* iterator = heap->bfs();
			int array[15];
			int example[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			index = 0;
			while (iterator->has_next())
				array[index++] = iterator->next()->get_data();
			for(index = 0; index < 15; index++)
				Assert::AreEqual(array[index], example[index]);
		}
		
		TEST_METHOD(bfs_with_not_sorted_add)
		{
			for ( index = 14; index > 0; index--)
				heap->add(index);
			heap->add(15);
			Iterator* iterator = heap->bfs();
			int array[15];
			int example[] = {15, 13, 14, 11, 10, 9, 12, 7, 6, 5, 4, 3, 2, 1, 8 };
			index = 0;
			while (iterator->has_next())
				array[index++] = iterator->next()->get_data();
			for(index = 0; index < 15; index++)
				Assert::AreEqual(array[index], example[index]);
		}

	};
}