#include "Elem.h" 

Node::Node(int data) {
	this->data = data;
	this->nextL = nullptr;
	this->nextR = nullptr;
	this->prev = nullptr;
}

int Node::get_data() {
	return data;
}


Piece::Piece(Node * value, Piece * next, Piece * prev) {
	this->value = value;
	this->next = next;
	this->prev = prev;
}


ListUniversal::ListUniversal() {
	start = end = cont = nullptr;
	size = 0;
}


bool ListUniversal::is_empty() {
	if (!start || !end)
		return true;
	return false;
}


Node * ListUniversal::pop() {
	if (size) {
		Piece* p = start;
		start = start->next;
		size--;
		return p->value;
	}
	return nullptr;
}