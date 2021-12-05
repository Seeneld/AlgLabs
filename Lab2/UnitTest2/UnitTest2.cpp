#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2/Lab2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(Sorted) {
			const int SIZE = 5;
			int array1[SIZE] = { 10, 20, 30, 40, 50 };
			int array2[SIZE] = { 10, 220, 30, 40, 50 };

			Assert::IsTrue(isSorted(array1, SIZE));  //Expected that array1 is sorted
			Assert::IsFalse(isSorted(array2, SIZE));  //Expected that array2 is not sorted
		}
		TEST_METHOD(BinarySearch)
		{
			const int SIZE = 5;
			int array[SIZE] = { 10, 20, 30, 40, 50 };
			int search = 30;

			Assert::AreEqual(2, Search_Binary(array, 0, SIZE, search));  //Expexted that index of 30 is 2
		}

		TEST_METHOD(Quick_Sort)
		{
			const int SIZE = 5;
			int array[SIZE] = { 5, 4, 20, 40, 1 };

			Assert::IsFalse(isSorted(array, SIZE)); //Expected that array is not sorted

			QuickSort(array, SIZE);

			Assert::IsTrue(isSorted(array, SIZE)); //Expected that array is sorted
		}

		TEST_METHOD(Insertion_Sort)
		{
			const int SIZE = 5;
			int array[SIZE] = { 5, 4, 20, 40, 1 };

			Assert::IsFalse(isSorted(array, SIZE)); //Expected that array is not sorted

			InsertionSort(SIZE, array);

			Assert::IsTrue(isSorted(array, SIZE)); //Expected that array is sorted
		}

		TEST_METHOD(Bogo_Sort)
		{
			const int SIZE = 5;
			int array[SIZE] = { 5, 4, 20, 40, 1 };

			Assert::IsFalse(isSorted(array, SIZE)); //Expected that array is not sorted

			BogoSort(array, SIZE);

			Assert::IsTrue(isSorted(array, SIZE)); //Expected that array is sorted
		}

		TEST_METHOD(Counting_Sort)
		{
			const int SIZE = 5;
			char array[SIZE] = { 97, 99, 106, 98, 104 };

			Assert::IsFalse(isSortedChar(array, SIZE)); //Expected that array is not sorted

			CountingSort(array, SIZE);

			Assert::IsTrue(isSortedChar(array, SIZE)); //Expected that array is sorted
		}
	};
}
