#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include "Stack.h"
#include "Deque.h"
//Сосиска
using namespace std;

class Iterator {

public:

	virtual bool has_next() = 0;
	virtual Node* next() = 0;
};


class Heap
{
	friend class Node;
public:

	Heap();
	~Heap();

	void add_first(int elem);
	bool is_correct();
	bool contains(int elem);
	void add(int elem);
	Iterator* bfs();
	Iterator* dfs();

	void remove(int elem);
	int remove();
	void print();
	
private:

	class HeapIterator :public Iterator {

	public:
		HeapIterator(Deque* Deque = nullptr);
	
		Node * next() override;
		bool has_next() override;

		Node *cont;
		Deque *deque;
	};


	Node * head;
	size_t max_lvl;
	Deque *tail;
	size_t tail_index;
	
};