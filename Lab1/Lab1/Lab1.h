#pragma once
#include <iostream>
using namespace std;

class List {
private:
	struct Node {
		int data;
		Node* next;

		Node(int input) {
			data = input;
			next = nullptr;
		}

		int getData() {
			return data;
		}

		Node* getNext() {
			return next;
		}

		void setNext(Node* newnext) {
			next = newnext;
		}
	};

	Node* head;

	void push_front(Node* temp) {
		temp->next = head;
		head = temp;
	}

	void push_back(Node* temp) {
		Node* p = head;
		for (size_t i = 0; i < get_size() - 1; i++) {
			p = p->next;
		}
		p->next = temp;
	}

	void push(Node* temp, Node* prev, Node* prev_plus_one) {
		temp->next = prev_plus_one;
		prev->next = temp;
		temp = prev;

	}

	void pop_front_() {
		Node* p = head;
		head = head->next;
		delete p;
	}

	void pop_back_() {
		Node* p = head;
		head = head->next;
		if (head == nullptr)
			delete p;
	}

	size_t get_size_() {
		Node* p = head;
		size_t count = 0;
		while (p != nullptr) {
			count++;
			p = p->next;
		}
		return count;
	}

	void remove_(size_t number) {
		Node* p = head;
		Node* cur = head;
		Node* prev = NULL;
		bool found = false;
		for (size_t i = 0; i < get_size() - 1; i++) {
			if (i == number - 1) {
				prev = cur;
				cur = cur->getNext();
			}
			else {
				if (i < number)
					cur = cur->getNext();
			}
		}
		if (prev == NULL) {
			head = cur->getNext();
		}
		else {
			prev->setNext(cur->getNext());
		}
	}

	int at_(size_t number) {
		Node* p = head;
		for (size_t i = 0; i < get_size(); i++) {
			if (i == number) {
				return p->getData();
			}
			else {
				p = p->next;
			}
		}
		return false;
	}

	void insert_(int data, size_t number) {
		Node* cur = head;
		Node* prev = NULL;
		bool found = false;
		for (size_t i = 0; i < get_size() - 1; i++) {
			if (i == number - 1) {
				prev = cur;
				cur = cur->getNext();
			}
			else {
				if (i < number)
					cur = cur->getNext();
			}
		}
		push(new Node(data), prev, cur);
	}

	int find_last_(List* second_list) {
		Node* p1 = head;
		Node* p2 = second_list->head;
		size_t size1 = get_size();
		size_t size2 = second_list->get_size();
		int index = -1;
		for (size_t i = 0; i < size1; i++) {
			int n1 = this->at(i);
			int n2 = second_list->at(0);
			if (n1 == n2) {
				if (!(i + (size2 - 1) < size1)) break;
				bool is_sublist = true;
				for (size_t j = 0; j < size2 && i + j < size1; j++) {
					n1 = this->at(i + j);
					n2 = second_list->at(j);
					if (n1 != n2) is_sublist = false;
				}
				if (is_sublist) index = i;
			}
		}
		return index;
	}
public:

	List() {
		head = nullptr;
	}

	List(int data) {
		head = new Node(data);
	}

	~List() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push_front(int data) { //pushes the element in the front
		if (head == nullptr) {
			head = new Node(data);
		}
		else
			push_front(new Node(data));
	}

	void push_back(int data) { //pushes the element in the back
		if (head == nullptr) {
			head = new Node(data);
		}
		else
			push_back(new Node(data));
	}

	void pop_back() {          //deletes the last element
		if (head == nullptr) return;
		else pop_back_();
	}

	void pop_front() {         //deletes the first element
		if (head == nullptr) return;
		else pop_front_();
	}

	void insert(int data, size_t number) { //inserts an element (data) on index (number)
		if (head == nullptr) return;
		else insert_(data, number);
	}

	int at(size_t number) {          //Finds an element with index (number)
		if (head == nullptr) return 0;
		else return at_(number);
	}

	void remove(size_t number) {     //Removes an element with index (number)
		if ((head == nullptr) || (number > get_size()) || (number < 0)) return;
		else remove_(number);
	}

	size_t get_size() {              //Gets the size of the list
		if (head == nullptr) return 0;
		else return get_size_();
	}


	void clear() {              //Removes all the elements in the list
		if (head == nullptr) return;
		else while (head != nullptr) pop_front();
	}

	void set(size_t number, int data) {      //Removes an element with index (number) and puts another element (data) on index
		if (head == nullptr) return;
		else {
			remove(number);
			insert(data, number);
		}
	}

	bool isEmpty() {          //Finds out if the list is empty
		if (head == nullptr)  return true;
		else return false;
	}

	int find_last(List* second_list) {       //Searches for the last occurrence of another list (second_list) in the list
		if (head == nullptr) return -1;
		else {
			return find_last_(second_list);
		}
	}

	friend ostream& operator<< (ostream& out, List& l);

};

ostream& operator<< (ostream& out, List& l) {

	List::Node* p = l.head;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}

	return out;
}
