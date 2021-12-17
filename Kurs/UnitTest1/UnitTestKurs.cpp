#include "pch.h"
#include "CppUnitTest.h"
#include "..\Kurs\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestKurs
{
	TEST_CLASS(UnitTestKurs)
	{
	public:

		TEST_METHOD(TestIsOperator)
		{
			string str = "+";
			Assert::IsTrue(IsOperator(str));

			str = "-";
			Assert::IsTrue(IsOperator(str));

			str = "*";
			Assert::IsTrue(IsOperator(str));

			str = "/";
			Assert::IsTrue(IsOperator(str));

			str = "^";
			Assert::IsTrue(IsOperator(str));

			str = "sin";
			Assert::IsTrue(IsOperator(str));

			str = "cos";
			Assert::IsTrue(IsOperator(str));

			str = "tg";
			Assert::IsTrue(IsOperator(str));

			str = "ctg";
			Assert::IsTrue(IsOperator(str));

			str = "log";
			Assert::IsTrue(IsOperator(str));

			str = "ln";
			Assert::IsTrue(IsOperator(str));

			str = "min";
			Assert::IsTrue(IsOperator(str));

			str = "max";
			Assert::IsTrue(IsOperator(str));

			str = "sqrt";
			Assert::IsTrue(IsOperator(str));

			str = "ss";
			Assert::IsTrue(!IsOperator(str));

			str = "";
			Assert::IsTrue(!IsOperator(str));
		}

		TEST_METHOD(TestIsNumber)
		{
			string str = "1";
			Assert::IsTrue(IsNumber(str));

			str = "1.23";
			Assert::IsTrue(IsNumber(str));

			str = "0.12";
			Assert::IsTrue(IsNumber(str));

			str = "pi";
			Assert::IsTrue(IsNumber(str));

			str = "e";
			Assert::IsTrue(IsNumber(str));

			str = "sin";
			Assert::IsTrue(!IsNumber(str));

			str = "cos";
			Assert::IsTrue(!IsNumber(str));
		}

		TEST_METHOD(TestPlusMinus)
		{
			Stack<double> Stack;

			Stack.push(2);
			Assert::IsTrue(_plus(Stack) == 2);

			Stack.push(3);
			Assert::IsTrue(_plus(Stack) == 5);

			Stack.push(5);
			Assert::IsTrue(_minus(Stack) == 0);

			Stack.push(10);
			Assert::IsTrue(_minus(Stack) == -10);
		}

		TEST_METHOD(TestMultiplicationDivision)
		{
			Stack<double> Stack;

			Stack.push(5);
			Stack.push(4);
			Assert::IsTrue(_multiplication(Stack) == 20);

			try {
				_multiplication(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }


			Stack.push(10);
			Assert::IsTrue(_division(Stack) == 2);


			try {
				_division(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			Stack.push(0);
			try {
				_division(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
		}

		TEST_METHOD(TestSqrt)
		{
			Stack<double> Stack;

			Stack.push(64);
			Assert::IsTrue(_sqrt(Stack) == 8);

			Stack.pop_front();
			try {
				_sqrt(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			try {
				Stack.push(-1);
				_sqrt(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
		}

		TEST_METHOD(TestExponenta)
		{
			Stack<double> Stack;

			Stack.push(2);
			try {
				_exponentiation(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			Stack.push(2);
			Assert::IsTrue(_exponentiation(Stack) == 4);
		}

		TEST_METHOD(TestLogarithm)
		{
			Stack<double> Stack;

			Stack.push(2);
			try {
				_log(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			Stack.push(16);
			Assert::IsTrue(_log(Stack) == 4);
		}

		TEST_METHOD(TestSin)
		{
			Stack<double> Stack;

			try {
				_sin(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			Stack.push(0);
			Assert::IsTrue(_sin(Stack) == 0);
		}

		TEST_METHOD(TestCos)
		{
			Stack<double> Stack;

			try {
				_cos(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			Stack.push(0);
			Assert::IsTrue(_cos(Stack) == 1);
		}

		TEST_METHOD(TestTg)
		{
			Stack<double> Stack;

			try {
				_tg(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			Stack.push(0);
			Assert::IsTrue(_tg(Stack) == 0);
		}

		TEST_METHOD(TestCtg)
		{
			Stack<double> Stack;

			try {
				_ctg(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			try {
				Stack.push(0);
				_ctg(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }
		}

		TEST_METHOD(TestLn)
		{
			Stack<double> Stack;

			try {
				_ln(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			Stack.push(1);
			Assert::IsTrue(_ln(Stack) == 0);
		}

		TEST_METHOD(TestMax)
		{
			Stack<double> Stack;

			Stack.push(2);
			try {
				_max(Stack);
			}
			catch (exception ex) { Assert::IsTrue(ex.what()); }

			Stack.push(4);
			Assert::IsTrue(_max(Stack) == 4);
		}

		TEST_METHOD(TestPrecedence)
		{
			string str = "+";
			Assert::IsTrue(Precedence(str) == 1);

			str = "-";
			Assert::IsTrue(Precedence(str) == 1);

			str = "*";
			Assert::IsTrue(Precedence(str) == 2);

			str = "/";
			Assert::IsTrue(Precedence(str) == 2);

			str = "sin";
			Assert::IsTrue(Precedence(str) == 3);

			str = "cos";
			Assert::IsTrue(Precedence(str) == 3);

			str = "tg";
			Assert::IsTrue(Precedence(str) == 3);

			str = "ctg";
			Assert::IsTrue(Precedence(str) == 3);

			str = "^";
			Assert::IsTrue(Precedence(str) == 3);

			str = "log";
			Assert::IsTrue(Precedence(str) == 3);

			str = "sqrt";
			Assert::IsTrue(Precedence(str) == 3);

			str = "ln";
			Assert::IsTrue(Precedence(str) == 3);

			str = "min";
			Assert::IsTrue(Precedence(str) == 3);

			str = "max";
			Assert::IsTrue(Precedence(str) == 3);
		}

		TEST_METHOD(TestInfToPost)
		{
			string str = "2+2";
			Assert::IsTrue(InfToPost(str) == "2 2 + ");

			str = "(6*e-pi)/((pi^e-53)*3)";
			Assert::IsTrue(InfToPost(str) == "6 e * pi - pi e ^ 53 - 3 * / ");
		}

		TEST_METHOD(TestCalculatePostfix)
		{
			string str = "2 2 + ";
			Assert::IsTrue(CalculatePostfix(str) == 4);

			str = "55 100 - 50 / ";
			Assert::IsTrue(CalculatePostfix(str) == -0.9);

			str = "16 sqrt 0 cos + 2 * ";
			Assert::IsTrue(CalculatePostfix(str) == 10);
		}
	};
}