#pragma once
#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class List
{
public:
	List();
	~List();
	void add_first(int elem);
	int delete_one();

	void push_back(int elem);
	void push_front(int elem);
	int pop_back();
	void pop_front();
	void insert(int elem, size_t index);

	int at(size_t index);
	void delete_elem(size_t index);
	size_t get_size();
	void print_to_console();
	void clear();

	void set(size_t index, int elem);
	bool isEmpty();

	size_t find_first(List *list);


	bool equal_h(int value);
	bool equal_t(int value);
	bool equal_i(size_t index, int value);

	bool equal(List list1, List list2);


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

