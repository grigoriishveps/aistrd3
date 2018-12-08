#include "Heap.h"
#include "Header.h"


Heap::Heap()
{
	head = nullptr;
	max_lvl = 0;
	tail = new Deque();
}

Heap::~Heap()
{
	Node *cont = head;
	Deque *deque = new Deque();
	deque->push(head);

	while (tail->start && tail->end) {
		tail->pop();
	}

	while (deque->start && deque->end) {
		cont = deque->pop();
		if (cont) {
			deque->push(cont->nextL);
			deque->push(cont->nextR);
			delete cont;
		}
	}
	delete deque;
	head = nullptr;
	delete tail;
	tail = nullptr;
}

void Heap::add_first(int elem) {
	head = new Node(elem);
	tail->push(head);
	tail->push(head);
	head->prev = nullptr;
	tail_index = 0;
	max_lvl= 0;
}
bool Heap::is_correct()
{
	Deque *deque = new Deque();
	Node *cont;
	int len = 0, count = 0;
	deque->push(head);
	while (deque->start && deque->end) {
		cont = deque->pop();
		if (cont) {
			if (cont->nextL)
				if (cont->data < cont->nextL->data)
					return false;
			if (cont->nextR)
				if (cont->data < cont->nextR->data)
					return false;

			if (cont->lvl != len)
				return false;
			count++;
			if (count == 1 << len) {
				count = 0;
				len++;
			}

			deque->push(cont->nextL);
			deque->push(cont->nextR);
		}
	}

	return true;
}

void Heap::add(int elem) {
	Node*new_elem = new Node(elem), *cont_elem, *data_new_elem = new_elem;
	if (!head) 
		add_first(elem);
	else 
	{
		cont_elem = tail->pop();
		new_elem->prev = cont_elem;
		tail->push(new_elem);
		tail->push(new_elem);
	
		if (tail->size%2)
			cont_elem->nextL = new_elem;
		else
			cont_elem->nextR = new_elem;
		while (new_elem->prev != nullptr && new_elem->prev->data < new_elem->data) {
			cont_elem = new_elem->prev;
			swap(cont_elem->data, new_elem->data);
			new_elem = cont_elem;
		}

		tail_index++;
		if (tail_index == 1)
			max_lvl++;
		else if (tail_index == (1 << max_lvl))
			tail_index = 0;
		else if (tail_index == 0 && max_lvl == 0) {
			delete tail;
			head = nullptr;
			tail = new Deque();
		}
		data_new_elem->lvl = max_lvl;
	}
}

Iterator * Heap::bfs(){
	if (head) {
		Deque *iterator = new Deque();
		Deque *deque = new Deque();
		Node* cont = head;
		iterator->push(head);
		
		while(cont) {
			
			iterator->push(cont->nextL);
			iterator->push(cont->nextR);
			deque->push(cont->nextL);
			deque->push(cont->nextR);
			cont = deque->pop();
			
		}
		
		return  new HeapIterator(iterator);
	}
	return nullptr;
}

Iterator * Heap::dfs() {
	if (head) {
		Deque *iterator = new Deque();
		Stack *stack = new Stack();
		Node *cont = nullptr;
		List *list = new List();
		int selector = 0, deep= 1;
		iterator->push(head);
		stack->push(head);
		list->push_back(0);
		while (stack->start) {

			if (selector == 0) {
				if (stack->start->value->nextL) {
					iterator->push(stack->start->value->nextL);
					stack->push(stack->start->value->nextL);
					list->push_back(deep);
					deep= 1;
				}
				else {
					while (deep--) {
						stack->pop();

					}
					deep= list->pop_back();
					selector = 2;
				}
			}
			else {

				if (stack->start->value->nextR)
				{
					iterator->push(stack->start->value->nextR);
					stack->push(stack->start->value->nextR);
					deep++;
				}
				else {
					while (deep--) {
						stack->pop();
					}

				}

				selector = 0;
			}
		}
		return new HeapIterator(iterator);
	}
	return nullptr;
}





bool Heap::contains(int elem) {

	if (head) {
		Iterator* itr = bfs();
		Node* value;
		
		while (itr->has_next()) {
			value = itr->next();
			if (elem > value->data)
				return false;
			else if (elem == value->data)
				return true;
		}
		return false;
	}
	return false;
		//throw out_of_range("Heap is empty");
}

void Heap::remove(int elem) {
	Stack* stack = new Stack();
	Node* cont,* last_elem;
	stack->push(head);
	while (!stack->is_empty()) {
		cont = stack->pop();
		if (cont->data == elem) {
			tail->pope();
			last_elem = tail->pope();
			tail->push(last_elem->prev);
			cont->data = last_elem->data;
		
			if (last_elem->prev)
				if (tail->size % 2)
					last_elem->prev->nextR = nullptr;
				else
					last_elem->prev->nextL = nullptr;
			
			if (tail_index == 1)
				max_lvl--;
			else if (tail_index == 0)
				tail_index = (1 << max_lvl);
			tail_index--;

			if (last_elem == head) {
				head = nullptr;
				delete cont;
				cont = last_elem = nullptr;
				return;
			}
	
			while (cont) {
				if (cont->nextL && cont->nextR) {
					if (cont->nextL->data > cont->data && cont->nextR->data > cont->data) {
						if (cont->nextL->data > cont->nextR->data) {
							swap(cont->nextL->data, cont->data);
							cont = cont->nextL;
						}
						else if(cont->nextL->data < cont->nextR->data){
							swap(cont->nextR->data, cont->data);
							cont = cont->nextR;
						}
						else return;
					}
					else if (cont->nextL->data > cont->data)
					{
						swap(cont->nextL->data, cont->data);
						cont = cont->nextL;
					}
					else if (cont->nextR->data > cont->data)
					{
						swap(cont->nextR->data, cont->data);
						cont = cont->nextR;
					}
					else
						return;	
				}
				else if (cont->nextL && cont->nextL->data > cont->data) {
					swap(cont->nextL->data, cont->data);
					cont = cont->nextL;
				}
				else if (cont->nextR && cont->nextR->data > cont->data)
				{
					swap(cont->nextR->data, cont->data);
					cont = cont->nextR;
				}
				else return;
			}//
		}
		stack->push(cont->nextL);
		stack->push(cont->nextR);
	}
	
};

int Heap::remove() {
	Stack* stack = new Stack();
	Node* cont = head, *last_elem;
	int result;
	stack->push(head);
	if (head) {
		result = cont->data;
		tail->pope();
		last_elem = tail->pope();
		tail->push(last_elem->prev);
		cont->data = last_elem->data;

		if (last_elem->prev)
			if (tail->size % 2)
				last_elem->prev->nextR = nullptr;
			else
				last_elem->prev->nextL = nullptr;

		if (tail_index == 1)
			max_lvl--;
		else if (tail_index == 0)
			tail_index = (1 << max_lvl);
		tail_index--;

		if (last_elem == head) {
			head = nullptr;
			delete cont;
			cont = last_elem = nullptr;
			return result;
		}
		///*
		while (cont) {
			if (cont->nextL && cont->nextR) {
				if (cont->nextL->data > cont->data && cont->nextR->data > cont->data) {
					if (cont->nextL->data > cont->nextR->data) {
						swap(cont->nextL->data, cont->data);
						cont = cont->nextL;
					}
					else if (cont->nextL->data < cont->nextR->data) {
						swap(cont->nextR->data, cont->data);
						cont = cont->nextR;
					}
					else return result;
				}
				else if (cont->nextL->data > cont->data)
				{
					swap(cont->nextL->data, cont->data);
					cont = cont->nextL;
				}
				else if (cont->nextR->data > cont->data)
				{
					swap(cont->nextR->data, cont->data);
					cont = cont->nextR;
				}
				else
					return result;
			}
			else if (cont->nextL && cont->nextL->data > cont->data) {
				swap(cont->nextL->data, cont->data);
				cont = cont->nextL;
			}
			else if (cont->nextR && cont->nextR->data > cont->data)
			{
				swap(cont->nextR->data, cont->data);
				cont = cont->nextR;
			}
			else return result;
		}
	}
	return result;
};


Node * Heap::ListUniversal::pop() {
	if (size) {
		Piece* p = start;
		start = start->next;
		size--;
		return p->value;
	}
	return nullptr;
}

void Heap::Deque::push(Node * elem)
{
	if (elem){
		if (!size) {
			start = end = cont = new Piece(elem);
		}
		else {
			end->next = new Piece(elem, nullptr, end);
			end = end->next;
		}
		size++;
	}
}

inline Node * Heap::Deque::pope() {
	if (start) {
		Piece* p;
		size--;
		p = end;
		end = end->prev;
		if (end)
			end->next = nullptr;
		return p->value;

	}
	return nullptr;
}


void Heap::Stack::push(Node * elem)
{
	if (elem) {
		if (!size) {
			start = end = cont = new Piece(elem);
		}
		else {
			start = new Piece(elem, start);
		}
		size++;
	}
}

void Heap::print()//2
{

	if (!head) {
		cout << "Heap is Empty" << endl;
		return;
	}
	cout << "hello" << endl;;
	Deque *deque = new Deque();
	Node* elem;
	

	cout <<  tail_index << " " << max_lvl << endl<<'\n';
	deque->push(head);
	int count_underscore;
	for (int count_lvl = max_lvl; count_lvl >= 0; count_lvl--) {
		for (int index = 0; index < 1 << (max_lvl - count_lvl); index++) {
			elem = deque->pop();
			cout << setw((1 << count_lvl) - 1 ) << "";
			if (elem) {
				deque->push(elem->nextL);
				deque->push(elem->nextR);
				if (elem->nextL) {

					for (count_underscore = 0; count_underscore < ((1 << count_lvl) - 1); count_underscore++)
						cout << "_";
				}
				else {
					cout << setw((1 << count_lvl) - 1) << "";
				}

				
				if(index % 2)
					cout << left << setw(2) << elem->data;
				else
					cout << right << setw(2) << elem->data;
				

				if (elem->nextR) {
					for (count_underscore = 0; count_underscore < (1 << count_lvl) - 1; count_underscore++)
						cout << "_";
				}
				else {
					cout << setw(1 << count_lvl - 1) << "";
				}
				cout << setw((1 << count_lvl) - 1) << "";
			}
			else {
				deque->push(nullptr);
				deque->push(nullptr);
			}
			cout << setw(2) << "";


		}
		cout << '\n';
	}
	cout << '\n';
	cout << '\n';
	
}

inline Heap::ListUniversal::ListUniversal() {
	start = end = cont = nullptr;
	size = 0;
}


inline bool Heap::ListUniversal::is_empty() {
	if (!start || !end)
		return true;
	return false;
}

inline Heap::HeapIterator::HeapIterator(Deque * deque) {
	this->deque = deque;
	cont = deque->pop();
}

inline Node * Heap::HeapIterator::next() {
	if (has_next()) {
		Node* temp = cont;
		cont = deque->pop();
		return temp;
	}
	return nullptr;
}

inline bool Heap::HeapIterator::has_next() {
	return (cont != nullptr);
}

inline Heap::Piece::Piece(Node * value, Piece * next, Piece * prev) {
	this->value = value;
	this->next = next;
	this->prev = prev;
}


inline Node::Node(int data) {
	this->data = data;
	this->nextL = nullptr;
	this->nextR = nullptr;
	this->prev = nullptr;
}

int Node::get_data() {
	return data;
}
