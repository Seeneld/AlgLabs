#pragma once
#include <iostream>

using namespace std;
class Stack{
public:
	Stack();
	~Stack();
	void push(int data);
	int get_head();
	void pop_front();
	int get_size() { return size; };
	void clear();

	friend std::ostream& operator<<(std::ostream& s, Stack& list){
		unsigned count = 1;
		Node* cur = list.head;

		while (count <= list.size) {
			s << cur->data << '\t';
			cur = cur->pNext;
			count++;
		}

		return s;
	}

private:
	struct Node{
		Node* pNext;
		int data;

		Node(int data = int(), Node* pNext = nullptr){
			this->data = data;
			this->pNext = pNext;
		}
	};
	unsigned size;
	Node* head;
};

Stack::Stack(){
	size = 0;
	head = nullptr;
}

Stack::~Stack(){
	clear();
}

void Stack::push(int data){
	head = new Node(data, head);
	size++;
}

int Stack::get_head(){
	int temp = head->data;
	pop_front();
	return temp;
}

void Stack::pop_front(){
	if (this->size){
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

void Stack::clear(){
	while (size)
		pop_front();
}