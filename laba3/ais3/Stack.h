#pragma once
#include "Elem.h"


class Stack : public ListUniversal {
public:
	using ListUniversal::ListUniversal;

	void push(Node* elem);
};
