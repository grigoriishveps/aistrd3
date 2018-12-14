#include "Stack.h"

void Stack::push(Node * elem)//добавление элемента в стек
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