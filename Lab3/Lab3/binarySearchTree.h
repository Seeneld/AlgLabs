#pragma once
#include "stack.h"
#include "queue.h"
#include "conio.h"

using namespace std;

class BinarySearchTree{
public:
	BinarySearchTree(){
		root = nullptr;
	}
	~BinarySearchTree(){
		while (root != nullptr)
			remove(root->data);
	}
	bool contains(int data);
	void insert(int data);
	void remove(int data);

	intNode* root;

	class Iterator{
	public:
		Iterator(intNode* start){
			cur = start;
			if (start != nullptr)
				Queue.push_back(start);
		}

		bool hasNext();
		bool hasNext2();
		int next();
		int Next2();
		int getCurData() { return cur->data; };
	private:
		intNode* cur;
		Stack Stack;
		Queue Queue;
	};

	Iterator* create_dft_iterator(){
		cout << root->data << " ";
		return new Iterator(root);
	}
	Iterator* create_bft_iterator(){
		return new Iterator(root);
	}
};

bool BinarySearchTree::contains(int data)
{
	intNode* cur = root;

	while (cur != nullptr){
		if (data > cur->data){
			cur = cur->pRight;
			continue;
		}
		if (data < cur->data){
			cur = cur->pLeft;
			continue;
		}
		if (data == cur->data)
			return true;
	}
	return false;
}

void BinarySearchTree::insert(int data){
	intNode* cur = root;

	if (cur == nullptr)
		root = new intNode(nullptr, data);
	else{
		while ((cur->pLeft != nullptr) || (cur->pRight != nullptr)){
			if ((data > cur->data) && (cur->pRight != nullptr))
				cur = cur->pRight;
			else if ((data > cur->data) && (cur->pRight == nullptr)) break;

			if ((data <= cur->data) && (cur->pLeft != nullptr))
				cur = cur->pLeft;
			else if ((data <= cur->data) && (cur->pLeft == nullptr)) break;
		}

		if (data > cur->data)
			cur->pRight = new intNode(cur, data);
		else
			cur->pLeft = new intNode(cur, data);
	}
}

void BinarySearchTree::remove(int data){
	if (!contains(data))
		throw exception("You cannot remove a non-existent element!");
	intNode* cur = root;

	while (data != cur->data){
		if (data < cur->data)
			cur = cur->pLeft;
		else
			cur = cur->pRight;
	}
	if (cur != nullptr){
		if ((cur->pLeft == nullptr) && (cur->pRight == nullptr)){
			intNode* temp = cur;
			if (cur == root)
				root = nullptr;
			else{
				if (cur->data > cur->pPrev->data)
					cur->pPrev->pRight = nullptr;
				else cur->pPrev->pLeft = nullptr;
			}
			delete temp;
		}

		else if ((cur->pLeft != nullptr) ^ (cur->pRight != nullptr)){
			intNode* temp = cur;

			if (cur == root)
				if (cur->pLeft != nullptr)
					root = root->pLeft;
				else root = root->pRight;

			else{
				if (cur->data > cur->pPrev->data)
					if (cur->pLeft != nullptr)
						cur->pPrev->pRight = cur->pLeft;
					else cur->pPrev->pRight = cur->pRight;

				else
					if (cur->pLeft != nullptr)
						cur->pPrev->pLeft = cur->pLeft;
					else cur->pPrev->pLeft = cur->pRight;
			}
			delete temp;
		}

		else if ((cur->pLeft != nullptr) && (cur->pRight != nullptr)){
			intNode* temp = cur;
			cur = cur->pRight;

			while (cur->pLeft != nullptr)
				cur = cur->pLeft;

			if (temp == root)
				root->data = cur->data;

			temp->data = cur->data;
			intNode* temp1 = temp;
			temp = cur;

			if (cur->pPrev == temp1)
				cur->pPrev->pRight = nullptr;
			else cur->pPrev->pLeft = nullptr;
			delete temp;
		}
	}
}

bool BinarySearchTree::Iterator::hasNext(){
	if ((Stack.get_size() != 0) || (cur->pLeft != nullptr) || (cur->pRight != nullptr))
		return true;
	else return false;
}

bool BinarySearchTree::Iterator::hasNext2(){
	if (Queue.get_size())
		return true;
	else return false;
}

int BinarySearchTree::Iterator::next(){
	if (cur->pRight != nullptr){
		Stack.push(cur->pRight->data);
	}

	if (cur->pLeft != nullptr)
		cur = cur->pLeft;
	else{
		if (Stack.get_size()){
			int temp = Stack.get_head();
			do
				cur = cur->pPrev;
			while ((cur->pRight == nullptr) || (cur->pRight->data != temp));
			cur = cur->pRight;
		}
	}
	return cur->data;
}

int BinarySearchTree::Iterator::Next2()
{
	intNode* tempNode = Queue.get_head();

	if (tempNode->pLeft != nullptr)
		Queue.push_back(tempNode->pLeft);

	if (tempNode->pRight != nullptr)
		Queue.push_back(tempNode->pRight);

	return tempNode->data;
}