#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3\binarySearchTree.h"
#include "..\Lab3\node.h"
#include "..\Lab3\queue.h"
#include "..\Lab3\stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestContains)
		{
			BinarySearchTree Tree;
			for (unsigned i = 50; i > 0; i--)
				Tree.insert(i);

			for (unsigned i = 50; i > 0; i--)
				Assert::IsTrue(Tree.contains(i));

			for (unsigned i = 100; i > 50; i--)
				Assert::IsTrue(!Tree.contains(i));
		}

		TEST_METHOD(TestInsert)
		{
			BinarySearchTree Tree;
			Tree.insert(77);
			Tree.insert(31);
			Tree.insert(123);

			Assert::IsTrue(Tree.contains(77));
			Assert::IsTrue(Tree.contains(31));
			Assert::IsTrue(Tree.contains(123));

			Assert::IsTrue(!Tree.contains(1000));
		}

		TEST_METHOD(TestRemove)
		{
			BinarySearchTree Tree;
			Tree.insert(77);
			Tree.insert(31);
			Tree.insert(123);
			Tree.insert(23);
			Tree.insert(56);

			Tree.remove(56);
			Tree.remove(31);
			Tree.remove(77);
			Tree.remove(123);

			Assert::IsTrue(!Tree.contains(77));
			Assert::IsTrue(!Tree.contains(31));
			Assert::IsTrue(!Tree.contains(123));
			Assert::IsTrue(!Tree.contains(56));

			Assert::IsTrue(Tree.contains(23));
		}

		TEST_METHOD(TestDftIterator)
		{
			BinarySearchTree Tree;
			Tree.insert(77);
			Tree.insert(31);
			Tree.insert(123);
			Tree.insert(23);
			Tree.insert(56);
			Tree.insert(123);
			Tree.insert(934);

			BinarySearchTree::Iterator* D = Tree.create_dft_iterator();

			Assert::IsTrue(D->getCurData() == 77);
			Assert::IsTrue(D->next() == 31);
			Assert::IsTrue(D->next() == 23);
			Assert::IsTrue(D->next() == 56);
			Assert::IsTrue(D->next() == 123);
			Assert::IsTrue(D->next() == 123);
			Assert::IsTrue(D->next() == 934);
		}

		TEST_METHOD(TestBftIterator)
		{
			BinarySearchTree Tree;
			Tree.insert(77);
			Tree.insert(31);
			Tree.insert(123);
			Tree.insert(23);
			Tree.insert(56);
			Tree.insert(123);
			Tree.insert(934);

			BinarySearchTree::Iterator* B = Tree.create_bft_iterator();

			Assert::IsTrue(B->Next2() == 77);
			Assert::IsTrue(B->Next2() == 31);
			Assert::IsTrue(B->Next2() == 123);
			Assert::IsTrue(B->Next2() == 23);
			Assert::IsTrue(B->Next2() == 56);
			Assert::IsTrue(B->Next2() == 123);
			Assert::IsTrue(B->Next2() == 934);
		}
	};
}
