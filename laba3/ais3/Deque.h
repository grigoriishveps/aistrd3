#pragma once
#include "Elem.h"

class Deque :public ListUniversal {
public:
	using ListUniversal::ListUniversal;
	void push(Node* elem);
	Node* pope();
};