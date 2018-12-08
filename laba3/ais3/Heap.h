#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>


using namespace std;



class Node {

	friend class Heap;
public:
	Node(int data);
	int get_data();
private:
	int data;
	Node *nextL;
	Node *nextR;
	Node *prev;
	size_t lvl;
};

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
	class Piece {
	public:
		Piece(Node* value, Piece*next = nullptr, Piece*prev = nullptr);
		Node* value;

		Piece* next;
		Piece* prev;
	};


	class ListUniversal {
	public:
		
		ListUniversal();
		Node* pop();;
		bool is_empty();

		size_t size;
		Piece* start;
		Piece* cont;
		Piece* end;
	};


	class Deque :public ListUniversal {
	public:
		using ListUniversal::ListUniversal;
		void push(Node* elem);


		Node* pope();;
	};

	class Stack : public ListUniversal {
	public:
		using ListUniversal::ListUniversal;

		void push(Node* elem);
		//List *cont;
	};


	class HeapIterator :public Iterator {

	public:
		HeapIterator(Deque* Deque = nullptr);
	
		Node * next() override;
		bool has_next() override;;

		Node *cont;
		Deque *deque;
	};


	Node * head;
	size_t max_lvl;
	Deque *tail;
	size_t tail_index;
	
};