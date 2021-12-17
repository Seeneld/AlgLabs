#include "stack.cpp"
using namespace std;

double _plus(Stack<double>& Stack){
	if (Stack.get_size() > 1){
		double temp1 = Stack.get_head();
		Stack.pop_front();

		double temp2 = Stack.get_head();
		Stack.pop_front();
		Stack.push(temp1 + temp2);

		return temp1 + temp2;
	}
	else if (Stack.get_size()) return Stack.get_head();
	else throw exception("Invalid expression!");
}

double _minus(Stack<double>& Stack){
	if (Stack.get_size() > 1){
		double temp1 = Stack.get_head();
		Stack.pop_front();

		double temp2 = Stack.get_head();
		Stack.pop_front();
		Stack.push(temp2 - temp1);

		return temp2 - temp1;
	}
	else if (Stack.get_size()){
		double temp1 = Stack.get_head();

		Stack.pop_front();
		Stack.push(-temp1);

		return Stack.get_head();
	}
	else throw exception("Invalid expression!");
}

double _multiplication(Stack<double>& Stack){
	if (Stack.get_size() > 1){
		double temp1 = Stack.get_head();
		Stack.pop_front();

		double temp2 = Stack.get_head();
		Stack.pop_front();
		Stack.push(temp2 * temp1);

		return temp2 * temp1;
	}
	else throw exception("Invalid expression!");
}

double _division(Stack<double>& Stack){
	if (Stack.get_size() > 1){
		double temp1 = Stack.get_head();
		Stack.pop_front();

		double temp2 = Stack.get_head();
		Stack.pop_front();

		if (temp1 == 0) throw exception("Divide by zero is always a bad idea (error, obviosly)");
		else {
			Stack.push(temp2 / temp1);
			return temp2 / temp1;
		}
	}
	else throw exception("Invalid expression!");
}

double _sqrt(Stack<double>& Stack) {
	if (Stack.get_size()) {
		double temp1 = Stack.get_head();

		if (temp1 < 0)
			throw exception("Negative numbers don't have square roots!");

		Stack.pop_front();
		Stack.push(sqrt(temp1));

		return sqrt(temp1);
	}
	else throw exception("Invalid expression!");
}

double _exponentiation(Stack<double>& Stack){
	if (Stack.get_size() > 1){
		double temp1 = Stack.get_head();
		Stack.pop_front();

		double temp2 = Stack.get_head();
		Stack.pop_front();
		Stack.push(pow(temp2, temp1));

		return pow(temp2, temp1);
	}
	else throw exception("Invalid expression!");
}

double _log(Stack<double>& Stack){
	if (Stack.get_size() > 1){
		double temp1 = Stack.get_head();
		Stack.pop_front();

		double temp2 = Stack.get_head();
		Stack.pop_front();

		if (temp1 < 0 || temp2 < 0)
			throw exception("Logarithm's argument and base must be positive!");
		if (temp2 == 1)
			throw exception("Logarithm's base must not be equal to one!");
		
		Stack.push(log(temp1) / log(temp2));

		return log(temp1) / log(temp2);
	}
	else throw exception("Invalid expression!");
}

double _sin(Stack<double>& Stack){
	if (Stack.get_size()){
		double temp1 = Stack.get_head();

		if (temp1 == 3.14159 || temp1 == 3.14159 * 2){
			Stack.pop_front();
			Stack.push(0);
			return 0;
		}

		Stack.pop_front();
		Stack.push(sin(temp1));

		return sin(temp1);
	}
	else throw exception("Invalid expression!");
}

double _cos(Stack<double>& Stack){
	if (Stack.get_size()){
		double temp1 = Stack.get_head();

		if (temp1 == 3.14159 / 2 || temp1 == 3.14159 / 2 + 3.14159){
			Stack.pop_front();
			Stack.push(0);
			return 0;
		}

		Stack.pop_front();
		Stack.push(cos(temp1));

		return cos(temp1);
	}
	else throw exception("Invalid expression!");
}

double _tg(Stack<double>& Stack){
	if (Stack.get_size()){
		double temp1 = Stack.get_head();

		if (temp1 == 2 * 3.14159){
			Stack.pop_front();
			Stack.push(0);
			return 0;
		}

		if (temp1 == 3.14159 / 2)
			throw exception("tg(pi/2) does not exist!");

		Stack.pop_front();
		Stack.push(tan(temp1));
		return tan(temp1);
	}
	else throw exception("Invalid expression!");
}

double _ctg(Stack<double>& Stack){
	if (Stack.get_size()){
		double temp1 = Stack.get_head();

		if (temp1 == 0)
			throw exception("Divide by zero is always a bad idea (error, obviosly)");

		Stack.pop_front();
		Stack.push(1 / tan(temp1));

		return 1 / tan(temp1);
	}
	else throw exception("Invalid expression!");
}

double _ln(Stack<double>& Stack){
	if (Stack.get_size()){
		double temp1 = Stack.get_head();

		if (temp1 < 0)
			throw exception("Logarithm's argument must be positive!");

		Stack.pop_front();
		Stack.push(log(temp1));

		return log(temp1);
	}
	else throw exception("Invalid expression!");
}

double _max(Stack<double>& Stack) {
	if (Stack.get_size() > 1) {
		double temp1 = Stack.get_head();
		Stack.pop_front();

		double temp2 = Stack.get_head();
		Stack.pop_front();

		if (temp1 >= temp2) {
			Stack.push(temp1);
			return temp1;
		}
		else {
			Stack.push(temp2);
			return temp2;
		}
	}
	else throw exception("Invalid expression!");
}

bool IsOperator(string inp){
	string variations[] = { "-","+","*","/","^","sin","cos","tg","ln","ctg","sqrt","log","max","min" };
	
	for (int i = 0; i < 14; i++)
		if (inp == variations[i])
			return true;

	return false;
}

bool IsNumber(char letter){
	if ((letter >= '0' && letter <= '9') || letter == '.')
		return true;

	else return false;
}

bool IsNumber(string letter){
	if ((letter >= "0" && letter <= "9") || letter == "." || letter == "pi" || letter == "e")
		return true;

	else return false;
}

int Precedence(string letter){
	if (letter == "^" || letter == "sin" || letter == "cos" || letter == "tg" || letter == "ln" || letter == "ctg"
		|| letter == "sqrt" || letter == "log" || letter == "max" || letter == "min")
		return 3;

	else if (letter == "*" || letter == "/")
		return 2;

	else if (letter == "+" || letter == "-")
		return 1;

	else return -1;
}

string InfToPost(string infix){
	Stack<string> Stack;
	string postfix, temp;
	unsigned u = 0;
	bool flag = 0;

	for (unsigned i = 0; i < infix.length(); i++){
		if (infix[i] == ' ')
			continue;

		u = 0;
		temp = "";
		flag = 0;

		while (u < 2){
			temp += infix[i + u];
			if (IsNumber(temp)){
				flag = 1;
				break;
			}

			u++;
		}

		if (flag){
			if (temp != "pi" && temp != "e"){
				do{
					postfix += infix[i];
					i++;
				} 
				while ((IsNumber(infix[i])) && i < infix.length());
				postfix += ' ';
				i--;
			}
			else{
				postfix += temp;
				postfix += ' ';
				i += u;
			}
		}

		else if (infix[i] == '(')
			Stack.push(string(1, infix[i]));

		else if (infix[i] == ')'){
			while (Stack.get_head() != "(" && (Stack.get_size())){
				postfix += Stack.get_head();
				postfix += ' ';
				Stack.pop_front();
			}
			Stack.pop_front();
		}

		else
		{
			u = 0;
			temp = "";
			flag = 0;

			while (u < 4){
				temp += infix[i + u];
				if (IsOperator(temp))
				{
					flag = 1;
					break;
				}
				u++;
			}
			if (flag){
				if (!Stack.get_size())
					Stack.push(temp);
				else{
					if (Precedence(temp) > Precedence(Stack.get_head()))
						Stack.push(temp);
					else if ((Precedence(temp) == Precedence(Stack.get_head())) && (temp == "^" || temp == "sin" ||
						temp == "cos" || temp == "tg" || temp == "ln" || temp == "ctg" || temp == "sqrt" || temp == "log" ||
						temp == "max" || temp == "min"))
						Stack.push(temp);
					else{
						while ((Stack.get_size()) && (Precedence(temp)) <= Precedence(Stack.get_head())){
							postfix += Stack.get_head();
							postfix += ' ';
							Stack.pop_front();
						}
						Stack.push(temp);
					}
				}
				flag = 0;
				i += u;
			}
			else throw exception("Invalid expression!", i);
		}
	}
	while (Stack.get_size()){
		postfix += Stack.get_head();
		postfix += ' ';
		Stack.pop_front();
	}
	return postfix;
}

double CalculatePostfix(string postfix){
	bool flag = 0;
	Stack<double> Stack;
	string temp = "";

	for (unsigned i = 0; i < postfix.length(); i++){
		temp = "";
		flag = 0;
		while (postfix[i] != ' '){
			temp += postfix[i];
			if (IsNumber(temp))
				flag = 1;
			i++;
		}

		if (flag){
			if (temp != "pi" && temp != "e")
				Stack.push(atof(temp.c_str()));

			else if (temp == "pi")
				Stack.push(3.14159);

			else if (temp == "e")
				Stack.push(2.71828);

			flag = 0;
			temp = "";
		}

		else if (IsOperator(temp))
		{
			if (temp == "+")
				_plus(Stack);

			else if (temp == "-")
				_minus(Stack);

			else if (temp == "*")
				_multiplication(Stack);

			else if (temp == "/")
				_division(Stack);

			else if (temp == "^")
				_exponentiation(Stack);

			else if (temp == "log")
				_log(Stack);

			else if (temp == "max")
				_max(Stack);

			else if (temp == "sin")
				_sin(Stack);

			else if (temp == "cos")
				_cos(Stack);

			else if (temp == "tg")
				_tg(Stack);

			else if (temp == "ctg")
				_ctg(Stack);

			else if (temp == "ln")
				_ln(Stack);

			else if (temp == "sqrt")
				_sqrt(Stack);
		}
	}
	double solution = Stack.get_head();
	Stack.pop_front();
	return solution;
}

int main()
{
	try {
		string infix, postfix;

		cout << "Enter an expression you want to solve:" << "\n\n";
		getline(cin, infix);

		int check = 0;
		for (unsigned i = 0; i < infix.length(); i++)
		{
			if (infix[i] == '(')
				check++;
			if (infix[i] == ')')
				check--;
			if (check < 0)
				throw exception("Invalid expression!");
		}

		if (check)
			throw exception("Invalid expression!");

		postfix = InfToPost(infix);
		cout << "\n" << "Postfix expression: " << "\n\n" << postfix;

		double solution = CalculatePostfix(postfix);
		cout << "\n\n" << "Answer :\n\n" << solution << "\n";
	}
	catch (exception ex) { cout << "\n\n" << ex.what() << "\n"; }

	_getch();
}