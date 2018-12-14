#pragma once

class Node {
	friend class Heap;
	friend class Piece;
	friend class ListUniversal;
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

class Piece {
	//friend ListUniversal;
public:
	Piece(Node* value, Piece*next = nullptr, Piece*prev = nullptr);
	Node* value;

	Piece* next;
	Piece* prev;
};


class ListUniversal {
public:

	ListUniversal();
	Node* pop();
	bool is_empty();

	size_t size;
	Piece* start;
	Piece* cont;
	Piece* end;
};