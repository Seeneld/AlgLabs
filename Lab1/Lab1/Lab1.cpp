#include <iostream>
#include <locale>
#include "Lab1.h"

using namespace std;


int main()
{

	//Testing if everything is working fine
	List* p = new List(10);
	List* r = new List(10);

	r->push_back(90);
	r->push_back(47);
	p->push_front(20);
	p->push_back(47);
	p->push_front(30);
	p->push_back(13);
	p->push_front(40);
	p->push_front(50);
	p->push_front(60);
	p->push_back(10);
	p->push_back(90);
	p->push_back(47);
	p->push_back(2);
	p->remove(1);
	p->insert(90, 5);
	p->set(2, 36);

	cout << "First list:\n" << *p << "\n";
	cout << "Second list:\n" << *r << "\n";
	cout << "\nElement with searched index:" << p->at(3) << "\n";
	if (p->find_last(r) == -1) cout << "First list do not contain second list\n\n";
	else cout << "The last occurrence of the second list in the first list (index): " << p->find_last(r) << "\n\n";
	p->clear();
	p->push_back(100);
	cout << "\nFirst list after editing: " << *p << "\n";
	cout << "\nNumber of elements in the list:" << p->get_size() << "\n";
	if (p->isEmpty()) cout << "List is empty\n"; else cout << "List is not empty\n";
	p->pop_front();
	p->pop_front();
	p->pop_back();
	p->pop_back();
	if (p->isEmpty()) cout << "List is empty\n"; else cout << "List is not empty\n";
}
