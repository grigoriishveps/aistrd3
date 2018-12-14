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
	Node *�ont = head;
	if (!head)
		throw out_of_range("Error list is Empty");
	else if (tail == head) {
		return delete_one();
	}
	else {
		int value;
		while (�ont->next != tail)
			�ont = �ont->next;
		value = tail->data;
		delete tail;
		tail = �ont;
		tail->next = nullptr;
		size--;
		return value;
	}

}



size_t List::get_size() {
	return size;
}

void List::print_to_console() {
	Node* �ont = head;
	if (isEmpty())
		cout << "List is empty" << endl;
	else {
		cout << "List: ";
		while (�ont != nullptr) {
			cout << �ont->data << " ";
			�ont = �ont->next;
		}
		cout << endl;
	}
}

void List::clear() {
	Node* �ont = head;
	while (�ont != nullptr) {
		�ont = �ont->next;
		delete head;
		head = �ont;
	}
	size = 0;
	head = nullptr;
	tail = nullptr;
}


void List::set(size_t index, int elem) {
	if (index >= get_size())
		throw out_of_range("List out of range");
	else {
		Node *�ont1 = head;

		if (index == 0) {
			head->data = elem;
		}
		else {
			size_t count = 0;
			Node* �ont1 = head;
			while (count != index) {
				�ont1 = �ont1->next;
				count++;
			}
			�ont1->data = elem;
		}
	}
}


bool List::isEmpty()
{
	return (head == nullptr);
}



