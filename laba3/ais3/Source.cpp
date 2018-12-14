#include "Header.h"

List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

List::~List()
{
	this->clear();
}

void List::add_first(int elem) {
	tail = head = new Node(elem);
	size = 1;
}

int List::delete_one() {
	int value = tail->data;
	delete tail;
	tail = head = nullptr;
	size = 0;
	return value;
}

void List::push_back(int elem)
{
	if (head == nullptr)
		add_first(elem);
	else {
		tail = tail->next = new Node(elem);
		//tail = tail->next;
		size++;
	}

}

int List::pop_back() {
	Node *ñont = head;
	if (!head)
		throw out_of_range("Error list is Empty");
	else if (tail == head) {
		return delete_one();
	}
	else {
		int value;
		while (ñont->next != tail)
			ñont = ñont->next;
		value = tail->data;
		delete tail;
		tail = ñont;
		tail->next = nullptr;
		size--;
		return value;
	}

}



size_t List::get_size() {
	return size;
}

void List::print_to_console() {
	Node* ñont = head;
	if (isEmpty())
		cout << "List is empty" << endl;
	else {
		cout << "List: ";
		while (ñont != nullptr) {
			cout << ñont->data << " ";
			ñont = ñont->next;
		}
		cout << endl;
	}
}

void List::clear() {
	Node* ñont = head;
	while (ñont != nullptr) {
		ñont = ñont->next;
		delete head;
		head = ñont;
	}
	size = 0;
	head = nullptr;
	tail = nullptr;
}


void List::set(size_t index, int elem) {
	if (index >= get_size())
		throw out_of_range("List out of range");
	else {
		Node *ñont1 = head;

		if (index == 0) {
			head->data = elem;
		}
		else {
			size_t count = 0;
			Node* ñont1 = head;
			while (count != index) {
				ñont1 = ñont1->next;
				count++;
			}
			ñont1->data = elem;
		}
	}
}


bool List::isEmpty()
{
	return (head == nullptr);
}



