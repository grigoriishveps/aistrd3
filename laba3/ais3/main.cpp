#include "Heap.h"

int main() {
	Heap h;
	int i;
	h.print();
	/*
	h.add(8);
	h.print();
	cout << "|8|" << endl;
	cout << (1 << (-1)) << endl;*/
	
	///*
	
	for (i = 23; i > 8; i--) {
		h.add(i);
		h.print();
	}
	
	//cout << h.contains(4);
	//h.remove(11);
	
	//h.print();
	
	
	
	//cout << h.contains(9) << endl;
	//cout << h.is_correct() << endl;
	/*
	cout << "bfs:";
	Iterator* itr= h.bfs();
	while (itr->has_next()) 
		cout << (itr->next())->get_data() << " " ;
	cout << endl;
	*/
	//*/
	/*
	for (i = 113; i > 100; i--) {
		h.add(i);
		h.print();
	}*/
	/*
	for (i = 107; i > 100; i--) {
		h.remove(i);
		h.print();
	}*/
	//h.remove(7);
	//h.remove(5);

	//h.remove(4);
	//h.remove(3);
	//h.remove(2);
	//h.remove(1);

	h.print();

	system("pause");
	return 0;
}