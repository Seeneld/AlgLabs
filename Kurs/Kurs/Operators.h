#pragma once
double OperatorPlus(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(temp1 + temp2);
		return temp1 + temp2;
	}
	else if (kStack.GetSize()) return kStack.GetTop();
	else throw exception("Invalid infix expression");
}

double OperatorMinus(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(temp2 - temp1);
		return temp2 - temp1;
	}
	else if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(-temp1);
		return kStack.GetTop();
	}
	else throw exception("Invalid infix expression");
}

double OperatorMultiplication(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(temp2 * temp1);
		return temp2 * temp1;
	}
	else throw exception("Invalid infix expression");
}

double OperatorDivision(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		if (temp1 == 0) throw exception("You can't divide by zero!");
		else {
			kStack.Push(temp2 / temp1);
			return temp2 / temp1;
		}
	}
	else throw exception("Invalid infix expression");
}

double OperatorExponentiation(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		kStack.Push(pow(temp2, temp1));
		return pow(temp2, temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorLog(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		if (temp1 < 0 || temp2 < 0)
			throw exception("Logarithm's argument and base must be positive!");
		if (temp2 == 1)
			throw exception("Logarithm's base can't be equal to one!");
		kStack.Push(log(temp1) / log(temp2));
		return log(temp1) / log(temp2);
	}
	else throw exception("Invalid infix expression");
}

double OperatorMax(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		if (temp1 >= temp2) {
			kStack.Push(temp1);
			return temp1;
		}
		else {
			kStack.Push(temp2);
			return temp2;
		}
	}
	else throw exception("Invalid infix expression");
}

double OperatorMin(Stack<double>& kStack)
{
	if (kStack.GetSize() > 1)
	{
		double temp1 = kStack.GetTop();
		kStack.PopFront();
		double temp2 = kStack.GetTop();
		kStack.PopFront();
		if (temp1 <= temp2) {
			kStack.Push(temp1);
			return temp1;
		}
		else {
			kStack.Push(temp2);
			return temp2;
		}
	}
	else throw exception("Invalid infix expression");
}

double OperatorSin(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 == 3.14159 || temp1 == 3.14159 * 2)
		{
			kStack.PopFront();
			kStack.Push(0);
			return 0;
		}
		kStack.PopFront();
		kStack.Push(sin(temp1));
		return sin(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorCos(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 == 3.14159 / 2 || temp1 == 3.14159 / 2 + 3.14159)
		{
			kStack.PopFront();
			kStack.Push(0);
			return 0;
		}
		kStack.PopFront();
		kStack.Push(cos(temp1));
		return cos(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorTg(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 == 2 * 3.14159)
		{
			kStack.PopFront();
			kStack.Push(0);
			return 0;
		}
		if (temp1 == 3.14159 / 2)
			throw exception("tg(pi/2) doesn't exist!");
		kStack.PopFront();
		kStack.Push(tan(temp1));
		return tan(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorCtg(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 == 0)
			throw exception("You can't divide by zero!");
		kStack.PopFront();
		kStack.Push(1 / tan(temp1));
		return 1 / tan(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorLn(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 < 0)
			throw exception("Logarithm's argument must be positive!");
		kStack.PopFront();
		kStack.Push(log(temp1));
		return log(temp1);
	}
	else throw exception("Invalid infix expression");
}

double OperatorSqrt(Stack<double>& kStack)
{
	if (kStack.GetSize())
	{
		double temp1 = kStack.GetTop();
		if (temp1 < 0)
			throw exception("You cannot extract the square root of a negative number!");
		kStack.PopFront();
		kStack.Push(sqrt(temp1));
		return sqrt(temp1);
	}
	else throw exception("Invalid infix expression");
}

bool IsOperator(string inp)
{
	string variations[] = { "-","+","*","/","^","sin","cos","tg","ln","ctg","sqrt","log","max","min" };
	for (int i = 0; i < 14; i++)
		if (inp == variations[i])
			return true;
	return false;
}

bool IsNumber(char letter)
{
	if ((letter >= '0' && letter <= '9') || letter == '.')
		return true;
	else return false;
}

bool IsNumber(string letter)
{
	if ((letter >= "0" && letter <= "9") || letter == "." || letter == "pi" || letter == "e")
		return true;
	else return false;
}

int Precedence(string letter)
{
	if (letter == "^" || letter == "sin" || letter == "cos" || letter == "tg" || letter == "ln" || letter == "ctg"
		|| letter == "sqrt" || letter == "log" || letter == "max" || letter == "min")
		return 3;
	else if (letter == "*" || letter == "/")
		return 2;
	else if (letter == "+" || letter == "-")
		return 1;
	else return -1;
}

string InfToPost(string infix)
{
	Stack<string> kStack;
	string postfix, temp;
	unsigned u = 0;
	bool flag = 0;

	for (unsigned i = 0; i < infix.length(); i++)
	{
		if (infix[i] == ' ')
			continue;
		u = 0;
		temp = "";
		flag = 0;
		while (u < 2)
		{
			temp += infix[i + u];
			if (IsNumber(temp))
			{
				flag = 1;
				break;
			}
			u++;
		}

		if (flag)
		{
			if (temp != "pi" && temp != "e") {
				do
				{
					postfix += infix[i];
					i++;
				} while ((IsNumber(infix[i])) && i < infix.length());
				postfix += ' ';
				i--;
			}
			else {
				postfix += temp;
				postfix += ' ';
				i += u;
			}
		}

		else if (infix[i] == '(')
			kStack.Push(string(1, infix[i]));

		else if (infix[i] == ')')
		{
			while (kStack.GetTop() != "(" && (kStack.GetSize()))
			{
				postfix += kStack.GetTop();
				postfix += ' ';
				kStack.PopFront();
			}
			kStack.PopFront();
		}

		else
		{
			u = 0;
			temp = "";
			flag = 0;
			while (u < 4) {
				temp += infix[i + u];
				if (IsOperator(temp))
				{
					flag = 1;
					break;
				}
				u++;
			}
			if (flag)
			{
				if (!kStack.GetSize())
					kStack.Push(temp);
				else
				{
					if (Precedence(temp) > Precedence(kStack.GetTop()))
						kStack.Push(temp);
					else if ((Precedence(temp) == Precedence(kStack.GetTop())) && (temp == "^" || temp == "sin" ||
						temp == "cos" || temp == "tg" || temp == "ln" || temp == "ctg" || temp == "sqrt" || temp == "log" ||
						temp == "max" || temp == "min"))
						kStack.Push(temp);
					else
					{
						while ((kStack.GetSize()) && (Precedence(temp)) <= Precedence(kStack.GetTop()))
						{
							postfix += kStack.GetTop();
							postfix += ' ';
							kStack.PopFront();
						}
						kStack.Push(temp);
					}
				}
				flag = 0;
				i += u;
			}
			else throw exception("Invalid infix expression", i);
		}
	}
	while (kStack.GetSize())
	{
		postfix += kStack.GetTop();
		postfix += ' ';
		kStack.PopFront();
	}
	return postfix;
}

double CalculatePostfix(string postfix)
{
	bool flag = 0;
	Stack<double> kStack;
	string temp = "";
	for (unsigned i = 0; i < postfix.length(); i++)
	{
		temp = "";
		flag = 0;
		while (postfix[i] != ' ')
		{
			temp += postfix[i];
			if (IsNumber(temp))
				flag = 1;
			i++;
		}

		if (flag)
		{
			if (temp != "pi" && temp != "e")
				kStack.Push(atof(temp.c_str()));
			else if (temp == "pi")
				kStack.Push(3.14159);
			else if (temp == "e")
				kStack.Push(2.71828);
			flag = 0;
			temp = "";
		}

		else if (IsOperator(temp))
		{
			if (temp == "+")
				OperatorPlus(kStack);
			else if (temp == "-")
				OperatorMinus(kStack);
			else if (temp == "*")
				OperatorMultiplication(kStack);
			else if (temp == "/")
				OperatorDivision(kStack);
			else if (temp == "^")
				OperatorExponentiation(kStack);
			else if (temp == "log")
				OperatorLog(kStack);
			else if (temp == "max")
				OperatorMax(kStack);
			else if (temp == "min")
				OperatorMin(kStack);
			else if (temp == "sin")
				OperatorSin(kStack);
			else if (temp == "cos")
				OperatorCos(kStack);
			else if (temp == "tg")
				OperatorTg(kStack);
			else if (temp == "ctg")
				OperatorCtg(kStack);
			else if (temp == "ln")
				OperatorLn(kStack);
			else if (temp == "sqrt")
				OperatorSqrt(kStack);
		}
	}
	double solution = kStack.GetTop();
	kStack.PopFront();
	return solution;
}