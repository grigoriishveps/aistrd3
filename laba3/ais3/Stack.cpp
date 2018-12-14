#include "Stack.h"
//Привет
void Stack::push(Node * elem)
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