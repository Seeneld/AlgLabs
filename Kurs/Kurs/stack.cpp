#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

template <class T>

class Stack
{
	struct Node
	{
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr){
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node* head;
public:

	Stack();
	~Stack();
	void push(T data);
	T get_head();
	void pop_front();
	int get_size() { return size; };
	void clear();

	friend std::ostream& operator<<(std::ostream& s, Stack& list)
	{
		unsigned count = 1;
		Node* cur = list.head;

		while (count <= list.size) {
			s << cur->data << '\t';
			cur = cur->pNext;
			count++;
		}
		return s;
	}
};


template <class T>
Stack<T>::Stack(){
	size = 0;
	head = nullptr;
}

template<class T>
Stack<T>::~Stack(){
	clear();
}

template <class T>
void Stack<T>::push(T data){
	head = new Node(data, head);
	size++;
}

template<class T>
T Stack<T>::get_head(){
	T temp = head->data;
	return temp;
}

template<class T>
void Stack<T>::pop_front(){
	if (this->size){
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

template<class T>
void Stack<T>::clear(){
	while (size)
		pop_front();
}

