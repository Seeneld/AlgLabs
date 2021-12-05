#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1/Lab1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:

		TEST_METHOD(AddingElements)
		{
			List* p = new List(6);         //List: 6
			Assert::AreEqual(6, p->at(0));

			p->push_back(11);              //List: 6  11
			Assert::AreEqual(11, p->at(1));

			p->push_front(17);             //List: 6  11  17
			Assert::AreEqual(17, p->at(0));

			p->insert(13, 2);              //List: 6  11  13  17
			Assert::AreEqual(13, p->at(2));
		}

		TEST_METHOD(DeletingElements) {
			List* p = new List(6);         //List: 6

			p->pop_back();                 //List: nothing
			Assert::IsTrue(p->isEmpty());

			p->push_back(1);
			p->push_back(2);
			p->push_back(3);               //List: 1  2  3

			Assert::IsFalse(p->isEmpty());
			p->pop_front();                //List: 2  3
			p->pop_back();                 //List: 2
			p->push_back(3);               //List: 2  3

			p->push_back(4);
			p->push_back(5);               //List: 2  3  4  5
			p->remove(1);                  //List: 2  4  5
			Assert::AreEqual(4, p->at(1));

			p->clear();                    //List: nothing
			Assert::IsTrue(p->isEmpty());
		}

		TEST_METHOD(SetElement) {
			List* p = new List(6);          //List: 6

			p->push_back(1);
			p->push_back(2);                //List: 6  1  2

			p->set(1, 4);                   //List: 6  4  2
			Assert::AreEqual(4, p->at(1));

		}

		TEST_METHOD(GetSize) {
			List* p = new List(6);          //List: 6

			for (size_t i = 0; i < 9; i++)
				p->push_back(1);            //List: 6  1  1  1  1  1  1  1  1  1     (10 numbers)

			Assert::AreEqual((size_t)10, p->get_size());
		}

		TEST_METHOD(FindLastElement) {
			List* p = new List();
			p->push_back(1);
			p->push_back(2);
			p->push_back(3);                 //List: 1  2  3

			for (int i = 0; i < 5; i++) p->push_back(i + 10); //List: 1  2  3  10  11  12  13  14 
			p->push_back(1);
			p->push_back(2);
			p->push_back(3);

			for (int i = 0; i < 5; i++) p->push_back(i + 7);  //List: 1  2  3  10  11  12  13  14  1  2  3  7  8  9  10  11
			p->push_back(1);
			p->push_back(2);
			p->push_back(3);

			for (int i = 0; i < 5; i++) p->push_back(i + 8);  //List: 1  2  3  10  11  12  13  14  1  2  3  7  8  9  10  11  1 <--(16th element by index)  2  3  8  9  10  11  12

			List* sub_p = new List();
			sub_p->push_back(1);
			sub_p->push_back(2);
			sub_p->push_back(3);                             //List2: 1  2  3

			Assert::AreEqual(16, p->find_last(sub_p));
		}
	};
}
