#pragma once
#include <iostream>
#include "node.h"
class Queue{
	unsigned size;
	Node* head;

public:
	Queue();
	~Queue();
	void push_back(intNode* data);
	intNode* get_head(){
		intNode* temp = head->data;
		pop_front();
		return temp;
	}
	void pop_front();
	int get_size() { return size; };
	void clear();
};

Queue::Queue(){
	size = 0;
	head = nullptr;
}

Queue::~Queue(){
	clear();
}

void Queue::push_back(intNode* data){
	if (head == nullptr)
		head = new Node(data);
	else{
		Node* cur = this->head;

		while (cur->pNext != nullptr)
			cur = cur->pNext;
		cur->pNext = new Node(data);
	}
	size++;
}

void Queue::pop_front(){
	if (this->size){
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

void Queue::clear(){
	while (size)
		pop_front();
}

