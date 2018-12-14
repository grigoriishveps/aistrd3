#pragma once
#include <iostream>
#include <stdexcept>
#include "Stack.h"



using namespace std;

class List
{
public:
	List();
	~List();
	void add_first(int elem);
	int delete_one();

	void push_back(int elem);
	int pop_back();
	size_t get_size();
	void print_to_console();
	void clear();
	void set(size_t index, int elem);
	bool isEmpty();

private:

	class Node {
	public:
		Node(int data, Node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
		int data;
		Node *next;
	};

	Node * head;
	Node * tail;
	size_t size;
};

